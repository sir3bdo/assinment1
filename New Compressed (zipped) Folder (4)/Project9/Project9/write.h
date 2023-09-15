#pragma once
#include"struct.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
int height(struct tree* node);
void write(FILE* ptr, struct tree* head);
struct QNode* newNode1(struct tree* node);
struct Queue* createQueue();
void enQueue(struct Queue* q, struct tree* head);
struct tree* createtreenode1();
struct QNode* deQueue(struct Queue* q);

struct QNode {
    struct tree *key;
    struct QNode* next;
};
struct Queue {
    struct QNode* front, * rear;
};
struct QNode* newNode1(struct tree* node)
{
    struct QNode* temp
        = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = node;
    temp->next = NULL;
    return temp;
}
struct Queue* createQueue()
{
    struct Queue* q
        = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue(struct Queue* q, struct tree*head)
{
    struct QNode* temp = newNode1(head);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
 struct QNode* deQueue(struct Queue* q){
     if (q->front == NULL)
         return;
     struct QNode* temp = q->front;
     struct QNode* temp2 = newNode1(temp->key);
     q->front = q->front->next;
     if (q->front == NULL)
         q->rear = NULL;
     free(temp);
     return temp2;
 }
void write(FILE *ptr,struct tree*head) {
    double num = 0;
    double it = 0;
    fopen_s(&ptr, "tree.txt", "w");
    struct Queue* q = createQueue();
    struct QNode* current= (struct QNode*)malloc (sizeof(struct QNode));
    int number_it = height(head);
    int nofcit = 0;
    it = 0;
    enQueue(q, head);
    while (q->front != NULL) {
        current = deQueue(q);
        if (current->key->YES != NULL) {
            enQueue(q, current->key->YES);
            enQueue(q, current->key->NO);
        }
        num++;
        if (current->key->YES == NULL) {
            nofcit = (int)(ceil(log(num+1) / log(2)));
            if(nofcit < number_it){
                current->key->YES =createtreenode1();
                current->key->NO  =createtreenode1();
                enQueue(q, current->key->YES);
                enQueue(q, current->key->NO);
            }
        }
        fprintf_s(ptr, "%s\n", current->key->data);    
    }
    fclose(ptr);
}
struct tree* createtreenode1() {
    struct tree* temp = (struct tree*)malloc(sizeof(struct tree));
    strcpy(temp->data, "-1");
    temp->YES = temp->NO = NULL;
    return temp;
}
int height(struct tree* node)
{
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->YES);
        int rheight = height(node->NO);
        if (lheight > rheight)
            return (lheight +1);
        else
            return (rheight +1);
    }
}


