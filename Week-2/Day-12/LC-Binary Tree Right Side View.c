Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]


Example 2:

Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]
Explanation:



Example 3:
Input: root = [1,null,3]
Output: [1,3]

Example 4:
Input: root = []
Output: []
#include <stdio.h>
#include <stdlib.h>


struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(100 * sizeof(int));
    int levelSize, i, resIndex = 0;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        levelSize = 0;
        struct QueueNode* temp = q->front;
        while (temp) {
            levelSize++;
            temp = temp->next;
        }

        for (i = 0; i < levelSize; i++) {
            struct TreeNode* current = dequeue(q);
            if (i == levelSize - 1) {
                result[resIndex++] = current->val;
            }
            if (current->left) enqueue(q, current->left);
            if (current->right) enqueue(q, current->right);
        }
    }

    *returnSize = resIndex;
    return result;
}
