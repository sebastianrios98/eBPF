# 🔧 eBPF Process and File Event Tracer

## 📌 Description

This project demonstrates how to harness the power of **eBPF (Extended Berkeley Packet Filter)** to trace key kernel-level events in Linux systems. It uses **C** to define eBPF programs that attach to system calls like `sys_clone` and `sys_enter_openat`, and a **Python user-space application** to manage, decode, and display the events. By combining these technologies, we gain real-time visibility into process creation and file access activities, all without modifying the kernel source.

## 🎯 Objectives

- Monitor **process creation** using the `sys_clone` syscall.
- Monitor **file access** using the `sys_enter_openat` syscall.
- Use `BCC` to load and attach eBPF programs to kernel tracepoints and kprobes.
- Send structured event data from the kernel to user space using `BPF_PERF_OUTPUT`.
- Parse and display these events in real time using a Python script.
- Lay the foundation for more advanced observability tools based on eBPF.

## 🧩 Requirements

- A Linux system with a kernel version that supports eBPF (≥ 4.x recommended)
- Root or sudo access (to load eBPF programs)
- GCC (to compile C code)
- Python ≥ 3.8

## 📦 Dependencies

### 🛠 System Packages

Install **BCC**, which provides Python bindings and helpers for working with eBPF:

**On Arch Linux:**
```bash
sudo pacman -S bcc bcc-tools python-bcc

