#include"test.h"

int main(){

	QueueNode p;
	QueueInit(&p);
	QUData item;
	printf("Please enter your data(0 is end):>");
	while (scanf("%d", &item), item){
		QueueEn(&p, item);
	}
	//QueueOut(&p);
	//QueueClear(&p);
	item = QueueBackData(&p);
	printf("back=%d\n", item);
	item = QueueFrontData(&p);
	printf("front=%d\n", item);
	size_t i=QueueSize(&p);
	printf("size=%d\n", i);
	QueueShow(&p);
	return 0;
}