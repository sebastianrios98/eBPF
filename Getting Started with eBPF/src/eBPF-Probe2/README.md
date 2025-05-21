# 🔍 eBPF Probe: Structured Process Creation Tracer

## 📌 Description

This project expands on the basic `sys_clone` eBPF probe by capturing and transmitting **structured process metadata** from the kernel to a user-space Python application.

The eBPF program is loaded into the kernel using **BCC** and runs in a secure, sandboxed environment. It hooks into the `sys_clone` system call to monitor process creation and sends details like **PID**, **PPID**, and **process name** to user space using the **BPF_PERF_OUTPUT** mechanism.

The Python runner script captures this structured event data in real time and displays it in a more meaningful and flexible format—unlike the previous version that simply printed trace logs. This approach opens the door to further processing, analytics, and logging.

## 🎯 Objectives

- Monitor process creation events using `sys_clone`.
- Create a custom C `struct` (`data_t`) to hold PID, PPID, and command name.
- Use `BPF_PERF_OUTPUT` to transmit data to user space.
- Replace `trace_print()` with a **custom Python event handler**.
- Demonstrate communication between the eBPF kernel space and Python user space.
- Poll and decode events in real time from a perf buffer.

## 🧩 Requirements

- Linux system with kernel **≥ 4.x** (eBPF compatible)
- Root privileges to load kernel probes
- **GCC** for compiling C code
- **Python ≥ 3.8**

## 📦 Dependencies

### 🛠 System Packages

Install the BCC framework and Python bindings:

**On Arch Linux:**
```bash
sudo pacman -S bcc bcc-tools python-bcc

