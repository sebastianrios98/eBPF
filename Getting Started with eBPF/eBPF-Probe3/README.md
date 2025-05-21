# 🔬 eBPF Probe: Process and File Access Monitoring

## 📌 Description

This project enhances the capabilities of our eBPF monitoring tools by combining two critical kernel-level observations:

1. **Process creation via `sys_clone`**  
2. **File access via `sys_enter_openat`**

The probe hooks into both events, captures structured metadata from each, and sends the data to user space using **dedicated perf outputs**. The **process creation events** include information like PID, PPID, and command name. The **file open events** include timestamp, PID, command name, and the filename being accessed.

Each type of event is associated with its own C `struct` (`data_t`, `open_event_t`) and corresponding Python event handler. This dual-tracing setup gives us **deeper visibility** into system behavior and opens the door for advanced audit, security, or performance monitoring tools.

## 🎯 Objectives

- Combine process and file activity monitoring in a single eBPF program.
- Use `kprobe` on `sys_clone` and `tracepoint` on `sys_enter_openat`.
- Define separate data structures for each event type.
- Send structured data to user space using `BPF_PERF_OUTPUT`.
- Implement separate Python event handlers to decode and log each event type in real time.
- Demonstrate simultaneous multi-event tracing with live reporting.

## 🧩 Requirements

- Linux kernel **≥ 4.x** with eBPF support.
- Root privileges (required to load eBPF programs).
- **GCC** for compiling the C code.
- **Python ≥ 3.8**

## 📦 Dependencies

### 🛠 System Packages

Install the BCC framework with Python bindings:

**On Arch Linux:**
```bash
sudo pacman -S bcc bcc-tools python-bcc

