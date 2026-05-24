# FinTrack-DSA-Project
Real-Time Personal Finance and  Stock Portfolio Engine using C++ and Custom Data Structures.
#  FinTrack Engine

FinTrack is a lightweight, high-performance personal finance & stock portfolio engine built from scratch in C++. 

To maximize memory efficiency and demonstrate core computer science concepts, this project **does not use any built-in STL containers** (like vectors, lists, stacks, or queues). All memory is managed manually via pointers and dynamic heap allocation.

---

## 🛠️ Data Structures Implementation

* **Singly Linked List (Transaction History):** Keeps a running ledger of daily expenses. New entries are added at the `head` so the latest transaction is always on top.
* **Custom Stack (Undo System):** Operates on the **LIFO** principle to log user actions and cleanly reverse/delete the last operation from memory.
* **Binary Search Tree (Expense Analytics):** Automatically sorts expenses dynamically. Uses recursive **In-order Traversal** to display metrics from lowest to highest.
* **Two-Pointer Queue (Stock Orders):** Processes portfolio buy/sell requests strictly on the **FIFO** (First In, First Out) principle to preserve execution order.

---

## 🚀 How to Run Locally

1. Clone or download `main.cpp`.
2. Open your terminal and compile using GCC:
   ```bash
   g++ main.cpp -o fintrack
