# 🧵 ThreadPool in C++

This project implements a simple **ThreadPool** in C++ that can execute tasks passed as function pointers. It focuses on multithreading, task management, and thread-safe shutdown using standard synchronization primitives.

---

## 📁 Project Structure

- `main.cpp` – Demonstrates how to use the thread pool with simple tasks.
- `implementation.cpp` – Implements the `ThreadPool` class.
- `header.hpp` – Header file containing class definitions and includes.
- `Makefile` – Build instructions.
- `README.md` – Project description (this file).

---

## ⚙️ Features

- Automatically spawns a fixed number of worker threads (default is 5).
- Supports pushing function pointer tasks to a task queue.
- Thread-safe synchronization using `std::mutex`, `std::condition_variable`, and `std::atomic`.
- Graceful shutdown of all threads using `end_wark()`.

---

📝 Notes
	•	This thread pool only supports tasks of type void (*)(). To support more general tasks (e.g. lambdas, functors), consider using std::function<void()>.

## 🧪 Example Output

When you run the program, it prints:

1
2
3
…
9

Order may vary due to concurrent execution.

---

## 🛠️ Build Instructions

Use the provided Makefile:

```bash
make

./main

make clean
