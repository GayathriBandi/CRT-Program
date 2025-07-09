# 📚 Day 7 - Stack

---

## ✅ What is a Stack?

A **stack** is a linear data structure that follows the **LIFO** (Last In First Out) principle.  
The last element inserted is the first one to be removed.

---

## 📌 Stack Properties

- `push(x)` → adds element `x` on top of the stack  
- `pop()` → removes the top element  
- `top` → returns the current top element  
- `isEmpty()` → returns true if stack is empty  
- `isFull()` → applicable in array implementation (fixed size)

---

## ⚠️ Stack States

| Condition      | Behavior     |
|----------------|--------------|
| Empty Stack    | `top = -1`   |
| Full Stack     | `top = size-1` |
| After Push     | `top++`      |
| After Pop      | `top--`      |

---

## 💻 Stack Implementation Using Array

```c
#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = value;
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        top--;
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}
--------
#### 🧠 **PROBLEM STATEMENT**

Check whether a given string made of `<` and `>` is **balanced** or **valid** using a stack.

---

#### ✅ **EXAMPLES**

| Input    | Result    |
| -------- | --------- |
| `<><>`   | ✅ Valid   |
| `<<>>`   | ✅ Valid   |
| `<><<>>` | ✅ Valid   |
| `<<>`    | ❌ Invalid |
| `><`     | ❌ Invalid |
| `>>>`    | ❌ Invalid |

---

#### 📈 **TIME COMPLEXITY**

**O(n)** — where *n* is the length of the string.

---

#### ✅ **APPROACH**

* Use a **stack** implemented with a **linked list**
* **Push** when `<` is encountered
* **Pop** when `>` is encountered
* If stack is **empty** when trying to pop → ❌ **Invalid**
* At the end, if stack is **empty** → ✅ **Valid**

---

Let me know if you'd like this as part of a collapsible section or want to combine it with the code block in one unified section.

 Problem 1: Check Validity of Arrow Pattern <><<>>
 
 🧠 Problem Statement:
 Check whether a given string made of '<' and '>' 
 is balanced or valid.

 ✅ Examples:
 Valid:   <><>, <<>>, <><<>>
 Invalid: <<>, ><, >>>

 📈 Time Complexity: O(n)

 ✅ Approach:
 Use a stack (implemented using linked list).
 - Push when '<' is found
 - Pop when '>' is found
 - If trying to pop from empty stack → Invalid
 - At end, if stack is empty → Valid
****************************************************/

#include <stdio.h>
#include <stdlib.h>

// Define stack node
struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

// Push character onto stack
void push(char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

// Pop character from stack
void pop() {
    if (top != NULL) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

// Check if stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to check if the arrow string is valid
int isValid(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '<') {
            push('<');
        } else if (str[i] == '>') {
            if (isEmpty())
                return 0; // Unmatched '>'
            pop();
        }
    }
    return isEmpty(); // If empty → all matched
}

// Main function to test the code
int main() {
    char expr[] = "<><<>>";

    if (isValid(expr))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}

🔍 Problem 2: Valid Bracket Checker – ()[]{}
🧠 Problem Statement:
Check whether a string of brackets is valid. A valid expression:

All open brackets are closed in correct order

Types of brackets match

✅ Valid: ([]), {[()]}
❌ Invalid: ([)], ({)}, ((

✅ Solution Using Stack
void push(char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top != NULL) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

char peek() {
    if (top != NULL)
        return top->data;
    return '\0';
}

int isEmpty() {
    return top == NULL;
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int isValid(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty())
                return 0;
            if (!isMatchingPair(peek(), ch))
                return 0;
            pop();
        }
    }
    return isEmpty();
}

int main() {
    char expression[] = "{[()]}";

    if (isValid(expression))
        printf("Brackets are valid.\n");
    else
        printf("Brackets are invalid.\n");

    return 0;
}


