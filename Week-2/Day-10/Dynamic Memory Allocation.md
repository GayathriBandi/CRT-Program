# Day 10 – Dynamic Memory Allocation in C

## 🧠 Overview

On Day 10 of our CRT program, we learned about **Dynamic Memory Allocation (DMA)** in the C programming language, along with an overview of **memory layout**, and the **differences between local and global variables** in terms of where they are stored in memory.

---

## 🧩 Memory Layout in C

When a C program is executed, the memory is divided into several segments:

+-------------------------+

| Stack | ← Local variables, function calls

+-------------------------+

| Heap | ← Dynamically allocated memory (malloc, calloc, etc.)

+-------------------------+

| BSS Segment | ← Uninitialized global/static variables

+-------------------------+

| Data Segment | ← Initialized global/static variables

+-------------------------+

| Code/Text Segment| ← Actual program instructions

+-------------------------+



---

## 📌 Local vs Global Variables

| Feature            | Local Variables                   | Global Variables                    |
|--------------------|-----------------------------------|-------------------------------------|
| **Scope**          | Within the function/block         | Entire program                      |
| **Storage**        | Stack                             | Data/BSS segment                    |
| **Lifetime**       | Created on function call,         | Exists for entire program           |
|                    | destroyed on return               |                                     |
| **Initialization** | Not auto-initialized              | Zero (BSS) or value assigned (Data) |

---

## 🔗 Dynamic Memory Allocation

Dynamic memory allocation allows allocating memory during **runtime** using heap memory. C provides 4 standard functions:

| Function     | Purpose                                    |
|--------------|--------------------------------------------|
| `malloc()`   | Allocates specified bytes, returns pointer |
| `calloc()`   | Allocates and initializes to zero          |
| `realloc()`  | Resizes previously allocated memory        |
| `free()`     | Frees dynamically allocated memory         |

### 📝 Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n = 5;

    // Allocating memory for 5 integers
    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        ptr[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    // Freeing allocated memory
    free(ptr);

    return 0;
}
 ⚠️ Key Points

- Always check if the memory was successfully allocated.
- Memory allocated using malloc, calloc, or realloc must be freed using free().
- Failure to free memory leads to memory leaks.
- malloc does not initialize memory, calloc does.

✅ Summary
On this day, we understood:

The structure of memory in a C program.

The difference between local and global variables.

How to dynamically allocate, reallocate, and free memory during program execution.

This knowledge is essential for efficient memory management, especially in large-scale or embedded systems programming.

