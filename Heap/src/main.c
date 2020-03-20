/**************************

Name: Safwan Hossain

*************************/
#include <stdio.h>
#include <stdlib.h>

#include "funcPointers.h"
#include "heap.h"

void print(Heap *heap);

int main()
{
	printf("My Test Cases:\n");
	printf("Testing ADT\n");
        Heap * heap = createHeap(100,MAX_HEAP,destroyData,printNode,compare);
	printf("1. Test insert for Max heap:\n ");

        int* input=(int*)malloc(sizeof(int));
        *input=5;

        int* second=(int*)malloc(sizeof(int));
        *second=9;

        int* third=(int*)malloc(sizeof(int));
        *third=7;

        int* fourth=(int*)malloc(sizeof(int));
        *fourth=8;

        int* five=(int*)malloc(sizeof(int));;
        *five=12;


        insertHeapNode(heap,input);
        print(heap);
        printf("**************************\n\n");

        insertHeapNode(heap, second);
        print(heap);
        printf("**************************\n\n");

        insertHeapNode(heap,third);
        print(heap);
        printf("**************************\n\n");

        insertHeapNode(heap,fourth);
        print(heap);
        printf("**************************\n\n");

        insertHeapNode(heap, five);
        print(heap);
        printf("<------------ FINAL ARRAY\n\n");



        Heap * heap1 = createHeap(100,MIN_HEAP,destroyData,printNode,compare);
	printf("2. Test  insert for MIN HEAP\n");

        int* f=(int*)malloc(sizeof(int));
        *f=5;

        int* s=(int*)malloc(sizeof(int));
        *s=8;

        int* t=(int*)malloc(sizeof(int));
        *t=0;

        int* four=(int*)malloc(sizeof(int));
        *four=3;

        int* fiv=(int*)malloc(sizeof(int));;
        *fiv=1;


        insertHeapNode(heap1,f);
        print(heap1);
        printf("**************************\n\n");

        insertHeapNode(heap1, s);
        print(heap1);
        printf("**************************\n\n");

        insertHeapNode(heap1,t);
        print(heap1);
        printf("**************************\n\n");

        insertHeapNode(heap1,four);
        print(heap1);
        printf("**************************\n\n");

        insertHeapNode(heap1, fiv);
        print(heap1);
        printf("<------------ FINAL ARRAY\n\n");

	printf("\n3. Test getMinorMax (For MAX_Heap)\n");

	heap->printNode(getMinOrMax(heap));

	printf("\n4. Test getMinorMax (For MIN_Heap)\n");

        heap1->printNode(getMinOrMax(heap1));

        printf("\n5. Test deleteMinOrMax (For MAX_Heap)\n");


        deleteMinOrMax(heap);
        print(heap);
	printf("\n");
        printf("\n6. Test deleteMinOrMax (For MIN_Heap)\n");


        deleteMinOrMax(heap1);
        print(heap1);
	printf("\n");

	printf("\n8. Convert Max heap to Min heap\n");

	changeHeapType(heap);
        print(heap);
        printf("\n");


        printf("\n9. Convert Min heap to Max heap\n");

        changeHeapType(heap1);

        print(heap1);
        printf("\n");

	printf("\n10. Insert Duplicates for Max heap\n");

	 int* w=(int*)malloc(sizeof(int));
        *w=5;
	 insertHeapNode(heap1,w);

        print(heap1);
        printf("\n");


        printf("\n11. Insert Duplicates for Min heap\n");

         int* m=(int*)malloc(sizeof(int));
         *m=5;
         insertHeapNode(heap,w);

        print(heap);
        printf("\n");

        printf("\n12. Insert FULL MAX_Heap\n");


       Heap * heap3 = createHeap(10,MAX_HEAP,destroyData,printNode,compare);
	 int* a=(int*)malloc(sizeof(int));
        *a=15;

        int* b=(int*)malloc(sizeof(int));
        *b=9;

        int* c=(int*)malloc(sizeof(int));
        *c=3;

        int* d=(int*)malloc(sizeof(int));
        *d=8;

        int* e=(int*)malloc(sizeof(int));;
        *e=12;

	 int* g=(int*)malloc(sizeof(int));
        *g=59;

        int* h=(int*)malloc(sizeof(int));
        *h=4;

        int* p=(int*)malloc(sizeof(int));
        *p=0;

        int* v=(int*)malloc(sizeof(int));
        *v=3;

        int* l=(int*)malloc(sizeof(int));;
        *l=7;

	
        int* x=(int*)malloc(sizeof(int));;
        *x=99;


         insertHeapNode(heap3,a);

         print(heap3);
         printf(" *******************\n");

         insertHeapNode(heap3,b);

        print(heap3);
        printf(" ********************\n");
  
       insertHeapNode(heap3,c);


        print(heap3);
        printf(" *********************\n");

         insertHeapNode(heap3,d);

        print(heap3);
        printf(" **********************\n");

         insertHeapNode(heap3,e);


        print(heap3);
        printf(" *********************\n");

         insertHeapNode(heap3,g);


        print(heap3);
        printf(" *******************\n");

         insertHeapNode(heap3,h);

        print(heap3);
        printf(" *******************\n");

         insertHeapNode(heap3,p);


        print(heap3);
        printf(" *******************\n");

         insertHeapNode(heap3,v);


        print(heap3);
        printf("***********************\n");
         insertHeapNode(heap3,l);


        print(heap3);
	printf("<--------------------Final Answer\n");


	printf("\n13: send in extra node\n");

	insertHeapNode(heap3,x);

	printf("\n14: Insert NULL\n");
	insertHeapNode(NULL,x);

	printf("\n15: Enter Null for heap in getMinOrMax\n");
	getMinOrMax(NULL);

	printf("\n16. Enter NULL for data during insert\n");
	insertHeapNode(heap1,NULL);


        printf("\n17. Test createHeap with negative size\n");
        Heap * heap4 = createHeap(-1,MAX_HEAP,destroyData,printNode,compare);
        free(heap4);
        printf("\n18. Test createHeap with 0 size\n");
        Heap * heap5 = createHeap(0,MAX_HEAP,destroyData,printNode,compare);
        free(heap5);


        printf("\n19. Test createHeap with a large positive HEAP_TYPE\n");
        Heap * heap6 = createHeap(11,(HEAP_TYPE)10000,destroyData,printNode,compare);

        printf("\n20. Test createHeap with a large negative HEAP_TYPE\n");
        Heap * heap7 = createHeap(10,(HEAP_TYPE)-10000,destroyData,printNode,compare);


        printf("\n21. Test createHeap with a null function pointer of destroy data\n");
        Heap * heap8 = createHeap(11,MAX_HEAP,NULL,printNode,compare);

        printf("\n22. Test createHeap with a null function pointer of printNode\n");
        Heap * heap9 = createHeap(10,MAX_HEAP,destroyData,NULL,compare);

        printf("\n23. Test createHeap with a null function pointer of COMPARE function\n");
        Heap * heap10 = createHeap(10,MAX_HEAP,destroyData,printNode,NULL);



	printf("\n24. Delete heaps\n");

       printf("Deleted heap3:\n");
       deleteHeap(heap3);


       printf("Deleted heap1:\n");
       deleteHeap(heap1);

       printf("Deleted heap:\n");
       deleteHeap(heap);



       printf("Deleted heap6:\n");
//       deleteHeap(heap6);
	free(heap6);

       printf("Deleted heap7:\n");
       free(heap7);


       printf("Deleted heap8:\n");
       free(heap8);


       printf("Deleted heap9:\n");
       free(heap9);

       printf("Deleted heap10:\n");
       free(heap10);


        return 0;

}


void print(Heap *heap)
{
	if(heap == NULL)
	{
		return;
	}
     int i=0;
        while(heap->hArray[i] != NULL)
        {
             Node *t=heap->hArray[i];
	     heap->printNode(t->data);
             /*int we = *(int*)t->data;

     printf(" %d ",we);*/
             i++;

        }



}



