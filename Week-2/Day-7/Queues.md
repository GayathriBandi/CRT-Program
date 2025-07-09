# 📚 Day 7 - Queues and Water Storage Problem

---

## ✅ What is a Queue?

A **Queue** is a linear data structure that follows the **FIFO** (First-In First-Out)** principle.  
Elements are added at the **rear** and removed from the **front**.

---

## 🔁 Standard Queue Operations

| Operation    | Description                               |
|--------------|-------------------------------------------|
| `enqueue()`  | Insert an element at the rear             |
| `dequeue()`  | Remove and return the front element       |
| `isEmpty()`  | Check if the queue is empty               |
| `isFull()`   | Check if the queue is full (array-based)  |
| `display()`  | Show all elements from front to rear      |

### 🧾 Code Snippet for Standard Queue (Array-based)
```c
#define SIZE 100
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue is Full\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is Empty\n");
    else
        printf("Deleted: %d\n", queue[front++]);
}

🔄 Circular Queue
A Circular Queue connects the last position back to the first, avoiding wasted space and making better use of memory.

Key Features:
Efficient memory usage

Wrap-around using modulo arithmetic

Operation	Description
enqueue()	Add an element at the rear with wrap-around
dequeue()	Remove element from front with wrap-around
isEmpty()	Returns true if the queue has no elements
isFull()	Returns true if the queue is full
display()	Show elements from front to rear circularly

🧾 Code Snippet for Circular Queue
c
Copy
Edit
#define SIZE 5
int cqueue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int val) {
    if (isFull()) {
        printf("Circular Queue is Full\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;
    cqueue[rear] = val;
}

void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is Empty\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display() {
    if (isEmpty()) {
        printf("Circular Queue is Empty\n");
        return;
    }
    int i = front;
    printf("Circular Queue: ");
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
💧 Problem: Calculate Height for Storing Water (Trapping Rain Water)
🧠 Problem Statement
Given an array representing heights of bars, find the maximum amount of water that can be trapped between the bars after raining.

📈 Time Complexity: O(n)
✅ Approach
Find the maximum height to the left of each bar.

Find the maximum height to the right of each bar.

Water stored at a position = min(leftMax, rightMax) - height[i]

Sum it over all positions.

🧾 Code (in C)
c
Copy
Edit
#include <stdio.h>

int trap(int height[], int n) {
    int left[n], right[n], water = 0;

    left[0] = height[0];
    for (int i = 1; i < n; i++)
        left[i] = (height[i] > left[i-1]) ? height[i] : left[i-1];

    right[n-1] = height[n-1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = (height[i] > right[i+1]) ? height[i] : right[i+1];

    for (int i = 0; i < n; i++) {
        int level = (left[i] < right[i]) ? left[i] : right[i];
        water += level - height[i];
    }

    return water;
}

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(height) / sizeof(height[0]);
    printf("Water Trapped = %d\n", trap(height, n));
    return 0;
}

🔍 Sample Output
java
Copy
Edit
Water Trapped = 6

📌 Additional Notes
Queue is useful in scheduling, buffering, and level order traversal.

Circular queues prevent wasted memory space when elements are removed.

Trapping Rain Water is a classic array-based problem, often used in interviews.

