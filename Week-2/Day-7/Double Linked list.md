# 📚 Day 7 - Doubly Linked List

Today’s class covered **Doubly Linked Lists**, which are data structures where each node contains a reference to both the next and previous nodes.  
This allows **forward and backward traversal** efficiently.

---

## ✅ Topics Covered

- Insertion at Beginning  
- Insertion at End  
- Insertion at Any Position  
- Deletion at Beginning  
- Deletion at End  

---

## 🔗 What is a Doubly Linked List?

A **Doubly Linked List (DLL)** is a linear data structure where each element (node) contains three fields:
1. `data` – to store value  
2. `next` – pointer to the next node  
3. `prev` – pointer to the previous node

This structure allows traversal in **both directions**.

---

## 💻 Complete Code (in C)

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to print the list
void display() {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Insertion at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insertion at end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insertion at any position
void insertAtPosition(int data, int position) {
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Deletion at beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// Deletion at end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

int main() {
    insertAtBeginning(10);
    display();

    insertAtEnd(20);
    display();

    insertAtPosition(15, 2);
    display();

    deleteAtBeginning();
    display();

    deleteAtEnd();
    display();

    return 0;
}

