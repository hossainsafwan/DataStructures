
#include <stdio.h>
#include <stdlib.h>


int  compare (const void* first, const void* second)
{
	if( *(int*)first > *(int*)second )
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void printData(void *tobePrinted)
{
	printf("%d\n",*(int*)tobePrinted);
}


void deleteData(void* toBeDeleted)
{
	free(toBeDeleted);

}