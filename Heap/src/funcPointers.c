/****************************
Name: Safwan Hossain
*********************************/
#include <stdio.h>
#include <stdlib.h>


void destroyData(void * data)
{
	free(data);

}

void printNode(void * toBePrinted)
{
             int we = *(int*)toBePrinted;



     printf(" %d ",we);


}
int compare(const void *first, const void *second)
{
	
	if( *(int*)first > *(int*)second ) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
