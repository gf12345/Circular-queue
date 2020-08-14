#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<vld.h>
#include<stdbool.h>
#pragma warning(disable:4996)

//结构的定义
#define Capacity 7
#define QUData int
typedef struct QueueNode{
	QUData *base;
	int capacity;
	QUData front;
	QUData rear;
}QueueNode;
//初始化
void QueueInit(QueueNode *p){
	assert(p != NULL);
	p->capacity = Capacity;
	p->base = (QUData *)malloc(sizeof(QUData)*(p->capacity+1));
	p->front = p->rear = 0;
}
//判空
bool QueueEmpty(QueueNode *p){
	assert(p != NULL);
	return p->front == p->rear;
}
//判满
bool QueueFull(QueueNode *p){
	assert(p != NULL);
	return (p->rear + 1) % (p->capacity+1) == p->front;
}
//入队
void QueueEn(QueueNode *p,QUData x){
	assert(p != NULL);
	if (QueueFull(p)){
		printf("队列已满,无法入队!\n");
		return;
	}
	p->base[p->rear] = x;
	p->rear++;
	p->rear = (p->rear + 1) % (p->capacity + 1);
}
//出队
void QueueOut(QueueNode *p){
	assert(p != NULL);
	if (QueueEmpty(p)){
		printf("队列为空，无法出队!\n");
	}
	p->front= (p->front + 1) % (p->capacity + 1);
}
	
//清除
void QueueClear(QueueNode *p){
	assert(p != NULL);
	p->front = p->rear = 0;
}
//摧毁
void QueueDestroy(QueueNode *p){
	assert(p != NULL);
	free(p->base);
	p->base = NULL;
	p->capacity = p->front = p->rear = 0;
}
//查看队头元素
QUData QueueFrontData(QueueNode *p){
	assert(p != NULL);
	assert(!QueueEmpty(p));
	return p->base[p->front];
}
//查看队尾元素
QUData QueueBackData(QueueNode *p){
	assert(p != NULL);
	assert(!QueueEmpty(p));
	return p->base[(p->rear - 1 + p->capacity + 1) % (p->capacity + 1)];
}

//元素个数
size_t QueueSize(QueueNode *p){
	assert(p != NULL);
	if (p->front > p->rear){
		return p->front + p->capacity + 1 - p->rear;
	}
	else{
		return p->rear - p->front;
	}
}
//遍历
void QueueShow(QueueNode *p){
	assert(p != NULL);
	for (int i = p->front; i != p->rear;){
		printf("%d ", p->base[i]);
		i = (i+1) % (p->capacity + 1);
	}
}
#endif