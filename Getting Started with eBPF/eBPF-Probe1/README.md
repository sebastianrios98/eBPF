# 🧬 eBPF Probe: Process Creation via `sys_clone`

## 📌 Description

This project implements a minimal eBPF probe that monitors the creation of new processes in a Linux system by hooking into the `sys_clone` system call. The eBPF program is written in **C**, compiled, and loaded into the kernel using **BCC (BPF Compiler Collection)** from a **Python runner** script.

The `sys_clone` function is invoked by the kernel whenever a new process is spawned. By attaching a `kprobe` to `sys_clone`, this probe lets us observe process creation events in real time, making it a powerful debugging or observability tool—even in this minimal form.

The eBPF program prints a simple message to the kernel trace buffer when a new process is created. The Python script uses BCC to compile, load, and manage the eBPF code, and displays trace buffer output live in the console.

> While this version is basic and primarily educational, it lays the foundation for more advanced tracing with structured data, perf buffers, and complex filters.

## 🎯 Objectives

- Understand how to use eBPF and BCC to trace kernel functions.
- Hook into the `sys_clone` syscall using a `kprobe`.
- Print a message to the kernel trace buffer when a process is created.
- Use Python and the BCC library to load and run eBPF programs from user space.
- Run and observe the behavior of eBPF programs in real time.

## 🧩 Requirements

- Linux system with kernel **≥ 4.x** (with eBPF support)
- Root privileges (to load eBPF code into the kernel)
- **GCC** (to compile C code, usually included by default)
- **Python ≥ 3.8**

## 📦 Dependencies

### 🛠 System Packages

Install the BCC tools and Python bindings:

**On Arch Linux:**
```bash
sudo pacman -S bcc bcc-tools python-bcc

