/********************************
Name: Safwan Hossain
ID: 0918742
email: safwan@uoguelph.ca
***********************************/
#ifndef __Func_Pointers__
#define __Func_Pointers__

#define MIN_HEAP 0
#define MAX_HEAP 1
#define HEAP_TYPE unsigned char
#endif

typedef struct node
{
	void * data;
	struct node *left;
	struct node *right;
	struct node *parent;


}Node;

typedef struct heap
{
	Node **hArray;//heap Array of Nodes
	Node *lastPosition;
	HEAP_TYPE type;
	size_t sizeofArray;
	void (*destroyData) (void * data);
	void (*printNode)(void *toBePrinted);
	int (*compare)(const void *first, const void *second);

}Heap;

#include "heap.h"
void destroyData(void * data);

void printNode(void * toBePrinted);

int compare(const void *first, const void *second);



