#include <stdio.h>
#include<malloc.h>
//���Ľṹ��ɶ������£�
typedef struct qnode
{
    int data;
    struct qnode* next;
} LQNode;
//��ͷָ��front�Ͷ�βָ��rear�Ľṹ�����ͣ�
typedef struct
{
    LQNode* front;
    LQNode* rear;
} LQueue;
//��ʼ��QueueInitiate(Q)
void QueueInitiate(LQueue* Q)
{
    Q->rear = NULL;
    Q->front = NULL;
}
//�ǿշ�QueueNotEmpty(Q)
int QueueNotEmpty(LQueue Q)
{
    if (Q.front == NULL) return 0;
    else return 1;
}
//�����QueueAppend(Q, x)
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
//������QueueDelete(Q, d)
int QueueDelete(LQueue* Q, int* d)
{
    LQNode* p;
    if (Q->front == NULL)
    {
        printf("�����ѿ�������Ԫ�س�����! \n");
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
//ȡ��ͷ����Ԫ��QueueGet(Q, d)
int QueueGet(LQueue Q, int* d)
{
    if (Q.front == NULL)
    {
        printf("�����ѿ�������Ԫ�س�����! \n");
        return 0;
    }
    else
    {
        *d = Q.front->data;
        return 1;
    }
}
