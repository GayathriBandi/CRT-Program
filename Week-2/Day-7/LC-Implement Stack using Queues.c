mplement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

Example 1:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]
Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmptyQueue(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

int front(Queue* q) {
    return q->data[q->front];
}


typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&stack->q1);
    initQueue(&stack->q2);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q1, x);
}

int myStackPop(MyStack* obj) {
    while (obj->q1.rear - obj->q1.front > 1) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }
    int top = dequeue(&obj->q1);

    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    return top;
}

int myStackTop(MyStack* obj) {
    while (obj->q1.rear - obj->q1.front > 1) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }
    int top = dequeue(&obj->q1);
    enqueue(&obj->q2, top);

    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    return top;
}

bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}
