#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<vld.h>
#include<stdbool.h>
#pragma warning(disable:4996)

//�ṹ�Ķ���
#define Capacity 7
#define QUData int
typedef struct QueueNode{
	QUData *base;
	int capacity;
	QUData front;
	QUData rear;
}QueueNode;
//��ʼ��
void QueueInit(QueueNode *p){
	assert(p != NULL);
	p->capacity = Capacity;
	p->base = (QUData *)malloc(sizeof(QUData)*(p->capacity+1));
	p->front = p->rear = 0;
}
//�п�
bool QueueEmpty(QueueNode *p){
	assert(p != NULL);
	return p->front == p->rear;
}
//����
bool QueueFull(QueueNode *p){
	assert(p != NULL);
	return (p->rear + 1) % (p->capacity+1) == p->front;
}
//���
void QueueEn(QueueNode *p,QUData x){
	assert(p != NULL);
	if (QueueFull(p)){
		printf("��������,�޷����!\n");
		return;
	}
	p->base[p->rear] = x;
	p->rear++;
	p->rear = (p->rear + 1) % (p->capacity + 1);
}
//����
void QueueOut(QueueNode *p){
	assert(p != NULL);
	if (QueueEmpty(p)){
		printf("����Ϊ�գ��޷�����!\n");
	}
	p->front= (p->front + 1) % (p->capacity + 1);
}
	
//���
void QueueClear(QueueNode *p){
	assert(p != NULL);
	p->front = p->rear = 0;
}
//�ݻ�
void QueueDestroy(QueueNode *p){
	assert(p != NULL);
	free(p->base);
	p->base = NULL;
	p->capacity = p->front = p->rear = 0;
}
//�鿴��ͷԪ��
QUData QueueFrontData(QueueNode *p){
	assert(p != NULL);
	assert(!QueueEmpty(p));
	return p->base[p->front];
}
//�鿴��βԪ��
QUData QueueBackData(QueueNode *p){
	assert(p != NULL);
	assert(!QueueEmpty(p));
	return p->base[(p->rear - 1 + p->capacity + 1) % (p->capacity + 1)];
}

//Ԫ�ظ���
size_t QueueSize(QueueNode *p){
	assert(p != NULL);
	if (p->front > p->rear){
		return p->front + p->capacity + 1 - p->rear;
	}
	else{
		return p->rear - p->front;
	}
}
//����
void QueueShow(QueueNode *p){
	assert(p != NULL);
	for (int i = p->front; i != p->rear;){
		printf("%d ", p->base[i]);
		i = (i+1) % (p->capacity + 1);
	}
}
#endif