#include <stdio.h>
#include<malloc.h>
//结点的结构体可定义如下：
typedef struct qnode
{
    int data;
    struct qnode* next;
} LQNode;
//队头指针front和队尾指针rear的结构体类型：
typedef struct
{
    LQNode* front;
    LQNode* rear;
} LQueue;
//初始化QueueInitiate(Q)
void QueueInitiate(LQueue* Q)
{
    Q->rear = NULL;
    Q->front = NULL;
}
//非空否QueueNotEmpty(Q)
int QueueNotEmpty(LQueue Q)
{
    if (Q.front == NULL) return 0;
    else return 1;
}
//入队列QueueAppend(Q, x)
int QueueAppend(LQueue* Q, int x)
{
    LQNode* p;
    p = (LQNode*)malloc(sizeof(LQNode));
    p->data = x;
    p->next = NULL;
    if (Q->rear != NULL) Q->rear->next = p;
    Q->rear = p;
    if (Q->front == NULL) Q->front = p;
    return 1;
}
//出队列QueueDelete(Q, d)
int QueueDelete(LQueue* Q, int* d)
{
    LQNode* p;
    if (Q->front == NULL)
    {
        printf("队列已空无数据元素出队列! \n");
        return 0;
    }
    else
    {
        *d = Q->front->data;
        p = Q->front;
        Q->front = Q->front->next;
        if (Q->front == NULL) Q->rear = NULL;
        free(p);
        return 1;
    }
}
//取队头数据元素QueueGet(Q, d)
int QueueGet(LQueue Q, int* d)
{
    if (Q.front == NULL)
    {
        printf("队列已空无数据元素出队列! \n");
        return 0;
    }
    else
    {
        *d = Q.front->data;
        return 1;
    }
}
