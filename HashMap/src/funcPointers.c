/*
Name: Safwan Hossain
Student ID: 0918742
Email: safwan@uoguelph.ca
*/
#include <stdio.h>
#include <stdlib.h>


int hashFunction(size_t tableSize, int key)
{
	int position=key%tableSize;

	return position;

}
void destroyData(void *data)
{
	free(data);

}
void printData(void *toBePrinted)
{
	char *data=(char*)toBePrinted; 

	printf("Data: %s\n",data);

}