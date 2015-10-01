//
//  q.h
//  
//
//  Created by Marcelo Sedano on 9/28/15.
//
//

#ifndef q_h
#define q_h

#include <stdio.h>

typedef struct Node {
    int payload;
    struct Node *prev;
    struct Node *next;
};

typedef struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Node* newItem();
void addQueue(struct Queue *head, int item);
void initQueue(struct Queue *head);
int delQueue(struct Queue *head);
void rotateQueue(struct Queue *head);

// Returns a pointer to a new node
struct Node* newItem() {
    return (struct Node*) malloc(sizeof(struct Node));
}

// Creates an empty queue pointed to by the variable head
void initQueue(struct Queue *head) {
    *head = (struct Queue*) malloc(sizeof(struct Queue));
}

// Adds a queue item pointed to by “item” to the queue pointed to by head
void addQueue(struct Queue *head, int item) {
    struct Node *temp = newItem();
    temp->payload = item;
    
    if (head->front == NULL) {
        head->front = temp;
        head->rear = temp;
        return;
    }
    
    temp->prev = head->rear;
    head->rear->next = temp;
    head->rear = temp;
}

// Deletes an item from head and returns a pointer to the deleted item
struct Node* delQueue(struct Queue *head) {
    if (head->front == NULL) {
        printf("Error: cannot delete from an empty queue.");
        return;
    }
    
    struct Node *temp = header->front;
    header->front = header->front->next;
    return temp;
}

// Moves the header pointer to the next element in the queue
void rotateQueue(struct Queue *head) {
    if (head->front == NULL) {
        printf("Error: cannot delete from an empty queue.");
        return;
    }
    
    struct Node *temp = header->front;
    header->front = header->front->next;
    header->rear->next = temp;
    temp->prev = header->rear;
    header->rear = temp;
}


#endif /* q_h */
