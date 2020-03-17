/****************************
Name: Safwan Hossain
ID: 0918742
email: safwan@uoguelph.ca
*********************************/
#include <stdio.h>
#include <stdlib.h>

#include "funcPointers.h"


void destroyData(void * data)
{
	int * d=(int*)data;

	free(d);

}

void* copy(void * toBeCopy)
{

	int* i = (int*)malloc(sizeof(int));


	*i= *(int*)toBeCopy;

	return (void*)i;


}
int compare(void *first, void *second)
{
	 int fst= *(int*)first;
	 int scnd= *(int*)second;

	if( fst > scnd) 
	{
		return 1;
	}
	else if (fst < scnd)//fst smaller than or equal to scnd
	{
		return -1;
	}
	else
	{

		return 0;
	}
}

void print(void * data)
{

	printf("--> %d ",*(int*)data);
}

