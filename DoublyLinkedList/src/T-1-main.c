/*************************

Lab Project -1
Safwan Hossain 
Date: 29 MAY 2017

***************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"
#include "funcpointers.h"

void menu();

int main()
{	
	char buffer[500];

    List* list=initializeList(printData,deleteData,compare);
    int choice=0;
    menu();
    fgets(buffer,500,stdin);
    choice = atoi(buffer);

    while(choice != 10)
    {

    	if(choice == 1)
    	{
    		printf("Please enter an integer\n");
    		int* a=(int*)malloc(sizeof(int*));
    		scanf("%d", a);
			insertFront(list,a);

    	}
    	else if(choice == 2)
    	{
    		printf("Please enter an integer\n");
    		int* a=(int*)malloc(sizeof(int*));
    		scanf("%d", a);
			insertBack(list,a);

    	}
		else if(choice == 3)
    	{

    		deleteList(list);
    	}
    	else if(choice == 4)
    	{

			printf("Please enter an integer\n");
    		int* a=(int*)malloc(sizeof(int*));
    		scanf("%d", a);
			insertSorted(list,a);
    	}
    	else if(choice == 5)
    	{
    		printf("Please enter an integer\n");
    		int* a=(int*)malloc(sizeof(int*));
			scanf("%d",a);
			deleteDataFromList(list, a);

    	}
    	else if(choice == 6)
    	{
    		if(list->head == NULL)
    		{
    			printf("List is empty\n");

    		}
    		else
    		{
    			void* get = getFromFront(list);
    			printf("From front: %d\n",*(int*)get);
    		}
    	}
    	else if(choice == 7)
    	{
    		if(list->head == NULL)
    		{
    			printf("List is empty\n");

    		}
    		else
    		{
    			void* get = getFromBack(list);
    			printf("From Back: %d\n",*(int*)get);
   			}
    	}
    	else if(choice == 8)
    	{
    		if(list->head == NULL)
    		{
    			printf("List is empty\n");

    		}
    		else
    		{
    			printf("Print Forward:\n");
				printForward(list);
			}
    	}
    	else if(choice == 9)
    	{
    		if(list->head == NULL)
    		{
    			printf("List is empty\n");

    		}
    		else
    		{
    			printf("Print Backward:\n");
    			printBackwards(list);
    		}
    	}
        else if(choice == 11)
        {
            if(list->head == NULL)
            {
                printf("List is empty\n");

            }
            else
            {
               // Node* new = dequeue(list);

                printForward(list);
            }
        }

    	else
    	{

    		printf("Please enter the number of the option you want to select:\n");
    		menu();
    		scanf("%d",&choice);
    	}


    	menu();
    	scanf("%d",&choice);

    }

	return 0;
}

void menu()
{
    	printf("Menu: \n");
    	printf("1. Insert Front\n");
    	printf("2. Insert Back\n");
    	printf("3. Delete List\n");
    	printf("4. insert Sorted\n");
    	printf("5. Delete data from list\n");
    	printf("6. get from front\n");
    	printf("7. get from back\n");
    	printf("8. print forward\n");
    	printf("9. print backward\n");
    	printf("10. quit\n");
        printf("11. dequeue\n");
}


