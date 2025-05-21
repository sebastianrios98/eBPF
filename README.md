## 📁 Repository Structure

```bash
Getting-Started-with-eBPF/
└── src/
    ├── eBPF-Probe1/    # Basic kprobe on sys_clone printing simple trace messages
    ├── eBPF-Probe2/    # Enhanced kprobe on sys_clone sending structured process info via perf buffer
    └── eBPF-Probe3/    # Uses tracepoints to monitor process clone and file open syscalls with detailed event data

