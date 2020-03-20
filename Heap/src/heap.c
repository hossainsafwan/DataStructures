/*****************************************
Name: Safwan Hossain
*****************************************/
#include <stdio.h>
#include <stdlib.h>

#include "funcPointers.h"
#include "heap.h"

void reheapify(Heap *heap, Node*newNode);
int posParentNode(Heap *heap, Node*newNode);
void heapify(Heap *heap,Node* rootH);
void reheapChange(Heap*heap,Node*newNode);

Heap *createHeap(size_t initialSize,

	HEAP_TYPE htype,
	void (*destroyDataFP)(void *data),
	void (*printNodeFP)(void *toBePrinted),
	int (*compareFP)(const void *first, const void *second))
{


	Heap * heap = (Heap*)malloc(sizeof(Heap));

	heap->sizeofArray = initialSize;

	if(heap->sizeofArray <=0)
	{
		printf("Size of Array cannot be less than or equal to 0\n");
		return NULL;
	}
	Node m;
	heap->hArray=(Node**)malloc(sizeof(m)*((heap->sizeofArray)));//Mallocing space for array of nodes


	heap->lastPosition=NULL;//useful to find out where to insert the next value
	heap->type=htype;
	if(heap->type != MIN_HEAP && heap->type != MAX_HEAP)
	{
		printf("Heap Type has to be either MIN_HEAP or MAX_HEAP\n");
		return NULL;
	}

	heap->destroyData=destroyDataFP;

        if(heap->destroyData == NULL)
        {
                printf("Print Node function cannot be NULL\n");
                return NULL;
        }

	heap->printNode=printNodeFP;

        if(heap->printNode == NULL)
        {
                printf("Print Node function cannot be NULL\n");
                return NULL;
        }

	heap->compare=compareFP;
	if(heap->compare == NULL)
	{
		printf("Compare function cannot be NULL\n");
		return NULL;
	}

	return heap;
}

Node *createHeapNode(void *data)
{
	Node* new=(Node*)malloc(sizeof(Node));
	new->parent=NULL;
	new->data=data;

	return new;
}

void *getMinOrMax(Heap *heap)
{
	if(heap ==NULL ||heap->hArray[0]== NULL)
	{
                printf("Heap is NULL or the first element is null\n");

		return NULL;
	}
	return heap->hArray[0]->data;
}

void insertHeapNode(Heap *heap, void *data)
{
	if(data == NULL)
	{
		printf("Data Cannot be NULL\n");
		return;
	}

	Node*new=createHeapNode(data);

	if (heap == NULL)
	{
		printf("Heap is NULL\n");
		return;

	}


	else if (heap !=NULL && heap->type == MAX_HEAP)
	{
		if(heap->hArray[0] == NULL)/*if root is empty*/
		{
			heap->hArray[0]=new;
			heap->lastPosition=new->left;
			return;

		}
		else
		{
			int i=0;
			while(heap->hArray[i] != NULL)//find location in heap to insert
			{

				i++;
			}
			if (i >= heap->sizeofArray)
			{
				printf("No more space in heap\n");
				return;
			}



			heap->hArray[i]=new;

			reheapify(heap,new);


		}


	}
/********************** MIN HEAP *******************************************/

        else if (heap !=NULL && heap->type == MIN_HEAP)
        {
                if(heap->hArray[0] == NULL)/*if root is empty*/
                {
                        heap->hArray[0]=new;
                        heap->lastPosition=new->left;
                        return;

                }
                else
                {
                        int i=0;
                        while(heap->hArray[i] != NULL)//find location in heap to insert
                        {

                                i++;
                        }


                        heap->hArray[i]=new;
                        reheapify(heap,new);


                }


        }


}



void deleteMinOrMax(Heap *heap)
{
	if (heap != NULL  && heap->hArray[0] != NULL)
	{
		destroyData( heap->hArray[0]->data);
	}
	else
	{
		return;
	}

	int i=0;
	while(heap->hArray[i] != NULL)//find the location of newNode in heap
        {

              i = i+1;
        }
	i=i-1;
	heap->hArray[0] = heap->hArray[i];
	heap->hArray[i]=NULL;
	Node * root=heap->hArray[0];
	heapify(heap,root);


}
void deleteHeap(Heap *heap)
{
	int i=0;

        while(heap->hArray[i] != NULL)//find the location of newNode in heap
        {
              i = i+1;
        }
	int s;
	for(s=0;s<i;s++)
	{
	   
	   free(heap->hArray[s]->data);
	   free(heap->hArray[s]);
	}

	free(heap->hArray);
	free(heap);

}

void heapify(Heap* heap, Node *rootH)
{
    Node* root = rootH;

    int i = 0;

/********************************MAX HEAP******************************************************/

    if(heap->type == MAX_HEAP)
    {

        while(heap->hArray[(i*2)+1] != NULL || heap->hArray[(i*2)+2] != NULL)
	{


            if(heap->hArray[(i*2) + 2] == NULL)//if right is null
	    {

                if(compare(heap->hArray[(i*2)+1]->data, heap->hArray[i]->data) > 0)
		{
 
                    Node* temp = root;
                    heap->hArray[i] = heap->hArray[(i*2) + 1];
                    heap->hArray[(i*2) + 1] = temp;
                }
                i = 0;
                while (heap->hArray[i] != root)
		{
                    i++;
                }
                if(heap->hArray[(i*2) + 1] != NULL)
		{
                    if (compare(heap->hArray[(i*2)+1]->data, heap->hArray[i]->data) <= 0)
		    {
                        i++;
                    }
                }

            }
		else
		{

                if(compare(heap->hArray[(i*2)+1]->data, heap->hArray[(i*2)+2]->data) > 0)
		{
                    if(compare(heap->hArray[(i*2)+1]->data, heap->hArray[i]->data) >0)
		    {
                        Node* temp = root;
 
                        heap->hArray[i] = heap->hArray[(i*2) + 1];
                        heap->hArray[(i*2) + 1] = temp;

                    }

                    i = 0;
                    while (heap->hArray[i] != root)
		    {
                        i++;
                    }

                }
		else
		{

                    if(heap->hArray[(i*2) + 2] != NULL)
		    {
                        if(compare(heap->hArray[(i*2)+2]->data, heap->hArray[i]->data) >0)
			{
                            Node* temp = root;
                            heap->hArray[i] = heap->hArray[(i*2) + 2];
                            heap->hArray[(i*2) + 2] = temp;

                            i = 0;
                            while (heap->hArray[i] != root)
			    {
                                i++;
                            }
                        }

                    }

                }
            }


        }
    }


/********************************MIN HEAP******************************************************/
    if(heap->type == MIN_HEAP)
    {

        while(heap->hArray[(i*2)+1] != NULL || heap->hArray[(i*2)+2] != NULL)
	{


            if(heap->hArray[(i*2) + 2] == NULL)//if right is null
	    {

                if(compare(heap->hArray[(i*2)+1]->data, heap->hArray[i]->data) <= 0)
		{
 
                    Node* temp = root;
                    heap->hArray[i] = heap->hArray[(i*2) + 1];
                    heap->hArray[(i*2) + 1] = temp;
                }
                i = 0;
                while (heap->hArray[i] != root)
		{
                    i++;
                }
                if(heap->hArray[(i*2) + 1] != NULL)
		{
                    if (compare(heap->hArray[(i*2)+1]->data, heap->hArray[i]->data) >0)
		    {
                        i++;
                    }
                }

            }
		else
		{

                if(compare(heap->hArray[(i*2)+1]->data, heap->hArray[(i*2)+2]->data) <= 0)
		{
                    if(compare(heap->hArray[(i*2)+1]->data, heap->hArray[i]->data) <= 0)
		    {
                        Node* temp = root;
 
                        heap->hArray[i] = heap->hArray[(i*2) + 1];
                        heap->hArray[(i*2) + 1] = temp;

                    }

                    i = 0;
                    while (heap->hArray[i] != root)
		    {
                        i++;
                    }

                }
		else
		{

                    if(heap->hArray[(i*2) + 2] != NULL)
		    {
                        if(compare(heap->hArray[(i*2)+2]->data, heap->hArray[i]->data) <= 0)
			{
                            Node* temp = root;
                            heap->hArray[i] = heap->hArray[(i*2) + 2];
                            heap->hArray[(i*2) + 2] = temp;

                            i = 0;
                            while (heap->hArray[i] != root)
			    {
                                i++;
                            }
                        }

                    }

                }
            }


        }
    }
/*******************************************************************************************************************/
}


void changeHeapType(Heap *heap)
{

	if(heap == NULL || heap->hArray[0] == NULL || heap->hArray[0]->data == NULL)
	{
		return;
	}

        if(heap->type == MAX_HEAP)
        {
                heap->type=MIN_HEAP;

	 	int i = 0;
        	while(heap->hArray[i] != NULL)
        	{
            		i++;
        	}
		int check=0;
		i=i-1;
		int o=i;
		while (i>0 && check==0)
		{//printf("ssss\n");
                	reheapChange(heap,heap->hArray[i]);
			//i = i-1;
			o=i;
			//check if min_heap reached
			for(o=i;o>0;o--)
			{

				int s = posParentNode(heap, heap->hArray[o]);

        			Node *parentNode=heap->hArray[s];

				if(compare(heap->hArray[o]->data,parentNode->data) > 0 )//
				{
					check=1;
				}
				else
				{
					check=0;
					o=-1;
				}
			}
		}
        }
        else if(heap->type == MIN_HEAP)
        {
                heap->type=MAX_HEAP;


                int i = 0;
                while(heap->hArray[i] != NULL)
                {
                        i++;
                }
         	 int check=0;
		int o=i;

                i=i-1;
                while (i>0 && check==0)
                {
                        reheapChange(heap,heap->hArray[i]);
                        //i = i-1;

            	          //check if min_heap reached
                        for(o=i;o>0;o--)
                        {

                                int s = posParentNode(heap, heap->hArray[o]);

                                Node *parentNode=heap->hArray[s];

                                if(compare(heap->hArray[o]->data,parentNode->data) <= 0 )//
                                {
                                        check=1;
                                }
                                else
                                {
                                        check=0;
                                        o = -1;
                                }
                        }

                }

        }
}

void reheapChange(Heap*heap,Node*newNode)
{
    int s=0;
        int i=0;

        while(heap->hArray[i] != newNode)//find the location of newNode in heap
        {


              i = i+1;
        }


        s = posParentNode(heap, newNode);

        Node *parentNode=heap->hArray[s];

        if(heap->type == MIN_HEAP)
        {
                while(compare(heap->hArray[i]->data,parentNode->data) <= 0 && heap->hArray[i] != heap->hArray[0])//swap if new node data is smaller than parent node data
                {


                        Node*temp=newNode;
                        heap->hArray[i]=parentNode;//set the place of parentNode to newNode
                        heap->hArray[s]=temp;//set to the place newNode to paentNode

                        s=posParentNode(heap, newNode);
                        i=0;
                        while(heap->hArray[i] != newNode)//find the location of newNode in heap
                        {
                                i = i+1;
                        }

                        parentNode=heap->hArray[s];

                }

        }

	else if (heap->type == MAX_HEAP)
	{
		while(compare(heap->hArray[i]->data,parentNode->data) > 0 && heap->hArray[i] != heap->hArray[0])//swap if new node data is smaller than parent node data
                {



                        Node*temp=newNode;
                        heap->hArray[i]=parentNode;//set the place of parentNode to newNode
                        heap->hArray[s]=temp;//set to the place newNode to paentNode

                        s=posParentNode(heap, newNode);
                        i=0;
                        while(heap->hArray[i] != newNode)//find the location of newNode in heap
                        {
                                i = i+1;
                        }

                        parentNode=heap->hArray[s];

                }



	}


}

void reheapify (Heap *heap, Node*newNode)
{	int s=0;
	int i=0;

        while(heap->hArray[i] != newNode)//find the location of newNode in heap
        {


              i = i+1;
        }


	s = posParentNode(heap, newNode);

	Node *parentNode=heap->hArray[s];

	if(heap->type == MAX_HEAP)
	{
		while(compare(heap->hArray[i]->data,parentNode->data) > 0)//swap if new node data is greater than parent node data
		{



			Node*temp=newNode;
			heap->hArray[i]=parentNode;//set the place of parentNode to newNode
			heap->hArray[s]=temp;//set to the place newNode to paentNode

			s=posParentNode(heap, newNode);
			i=0;
        		while(heap->hArray[i] != newNode)//find the location of newNode in heap
        		{
             			i = i+1;
		        }

			parentNode=heap->hArray[s];

		}

	}


 	if(heap->type == MIN_HEAP)
        {
                while(compare(heap->hArray[i]->data,parentNode->data) <= 0 && heap->hArray[i] != heap->hArray[0])//swap if new node data is smaller than parent node data
                {

                        Node*temp=newNode;
                        heap->hArray[i]=parentNode;//set the place of parentNode to newNode
                        heap->hArray[s]=temp;//set to the place newNode to paentNode

                        s=posParentNode(heap, newNode);
                        i=0;
                        while(heap->hArray[i] != newNode)//find the location of newNode in heap
                        {
                                i = i+1;
                        }

                        parentNode=heap->hArray[s];

                }

        }

	return;

}

int posParentNode(Heap *heap, Node*newNode)
{
	int i=0;
	while(heap->hArray[i] != newNode)//find the location of newNode in heap
	{
		i = i+1;
	}
	if (i%2 != 0 )//odd number
	{

		i=(i-1)/2;//index of parentNode if the postion in the array is od

		if(i <= 0)
		{
                    return 0;

		}
		else
		{
		    return i;
		}

	}
	else
	{
		 i=(i-2)/2;//index of parentNode if the postion in the array is odd

		if(i <= 0)
                {
                    return 0;

                }
		else
		{
			return i;
		}

	}

}
