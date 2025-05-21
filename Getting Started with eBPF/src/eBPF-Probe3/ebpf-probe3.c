#include <uapi/linux/ptrace.h>
#include <linux/sched.h>

struct clone_event_t {
    u32 pid;
    u32 ppid;
    char comm[TASK_COMM_LEN];
};

struct open_event_t {
    u64 timestamp;
    u32 pid;
    char comm[TASK_COMM_LEN];
    char filename[256];
};

BPF_PERF_OUTPUT(clone_events);
BPF_PERF_OUTPUT(open_events);

TRACEPOINT_PROBE(syscalls, sys_enter_clone) {
    struct clone_event_t event = {};
    struct task_struct *task = (struct task_struct *)bpf_get_current_task();

    event.pid = bpf_get_current_pid_tgid() >> 32;

    // Lee el puntero al proceso padre (real_parent->tgid)
    bpf_probe_read_kernel(&event.ppid, sizeof(event.ppid), &task->real_parent->tgid);

    bpf_get_current_comm(&event.comm, sizeof(event.comm));

    clone_events.perf_submit(args, &event, sizeof(event));
    return 0;
}

TRACEPOINT_PROBE(syscalls, sys_enter_openat) {
    struct open_event_t event = {};

    event.timestamp = bpf_ktime_get_ns();
    event.pid = bpf_get_current_pid_tgid() >> 32;
    bpf_get_current_comm(&event.comm, sizeof(event.comm));
    bpf_probe_read_user_str(&event.filename, sizeof(event.filename), (void *)args->filename);

    open_events.perf_submit(args, &event, sizeof(event));
    return 0;
}

