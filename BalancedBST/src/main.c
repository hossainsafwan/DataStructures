/****************************
Name: Safwan Hossain
*********************************/
#include <stdio.h>
#include <stdlib.h>

#include "balancedTreeAPI.h"
#include "tree.h"
#include "funcPointers.h"


int main(void)
{
	printf("\n******************* Test Creating trees *************\n\n");

	Tree* a=  createBalancedBinTree(NULL,destroyData,copy);

	if (a == NULL )
	{

		printf("Tree is NULL when NULL compare function sent\n");
	}

	Tree* b=  createBalancedBinTree(compare,NULL,copy);


	if (b == NULL )
	{

		printf("Tree is NULL when NULL destroyData function sent\n");
	}

	Tree* c=  createBalancedBinTree(compare,destroyData,NULL);

	if (c == NULL )
	{

		printf("Tree is NULL when NULL copy function sent\n");
	}


	printf("\nTest Creating and inserting nodes in tree\n\n");

	printf("\n******************* Test Inserting in trees *************\n\n");

	Tree* t = createBalancedBinTree(compare,destroyData,copy);

	printf("Insert NULL Tree\n\n");
	int * inputNull=(int*)malloc(sizeof(int));
	*inputNull=20;

	treeInsertNode(NULL, inputNull);

	printf("\nInsert NULL Data\n\n");

	inputNull=NULL;

	treeInsertNode(t, inputNull);


	printf("\nInsert 68\n");
	int * input=(int*)malloc(sizeof(int));
	*input=68;

	printf("Insert 65\n");

	int * input1=(int*)malloc(sizeof(int));
	*input1=65;

	printf("Insert 75\n");

	int * input2=(int*)malloc(sizeof(int));
	*input2=75;

	printf("Insert 40\n");
	 int * input3=(int*)malloc(sizeof(int));
	 *input3=40;

	printf("Insert 90\n");
	 int * input4=(int*)malloc(sizeof(int));
	 *input4=90;

	printf("Insert 66\n");

 	int * input5=(int*)malloc(sizeof(int));
	 *input5=66;

	printf("Insert 70\n");
	 int * input6=(int*)malloc(sizeof(int));
	 *input6=70;


	treeInsertNode(t, input);
	treeInsertNode(t, input1);
	treeInsertNode(t, input2);
	treeInsertNode(t, input3);
	treeInsertNode(t, input4);
	treeInsertNode(t, input5);
	treeInsertNode(t, input6);

	// treeDeleteNode(t, input5);
	// treeDeleteNode(t, input6);

	printf("\n\n******************Print InOrder**************\n\n");

	treeInOrderPrint(t, print);
	printf("\n\n*************Test empty tree in Inorder Print*************\n");
	printf("Null tree sent\n");
	treeInOrderPrint(NULL, print);
	printf("Null function pointer sent\n");
	treeInOrderPrint(t, NULL);


	
	printf("\n\n******************Print PostOrder**************\n\n");

	treePostOrderPrint(t, print);
	printf("\n\n*************Test empty tree Postorder Print*************\n");
	printf("Null tree sent\n");
	treePostOrderPrint(NULL, print);
	printf("Null function pointer sent\n");
	treePostOrderPrint(t, NULL);



	
	printf("\n\n******************Print PreOrder**************\n\n");
	
	treePreOrderPrint(t, print);
	printf("\n\n*************Test empty tree Preorder Print*************\n");
	printf("Null tree sent\n");
	treePreOrderPrint(NULL, print);
	printf("Null function pointer sent\n");
	treePreOrderPrint(t, NULL);



	printf("\n\n******************Test Print Min**************\n\n");

	printf("Test Min by sending in Null tree\n");
	treeFindMin(NULL);
	printf("\nMin %d\n",*(int*)treeFindMin(t));

	printf("\n\n******************Test Print Max**************\n\n");
	printf("Test Max by sending in Null tree\n");

	treeFindMax(NULL);

	printf("\nMax %d\n",*(int*)treeFindMax(t));

	//destroyBalancedBinTree(t);
	printf("\n\n******************Test Searching**************\n\n");
 	int * input9=(int*)malloc(sizeof(int));
	*input9=40;
 	printf("Test sending empty tree\n\n");
	treeFindNode(NULL, (void*)input9);

 	printf("Test sending empty data\n\n");
	treeFindNode(t, NULL);	

	printf("Try finding 40 in tree\n");


   //treeDeleteNode(t, input3);

	int s= *(int*)(treeFindNode(t, (void*)input9));


	printf("Found This: %d\n\n", s );

	printf("\n\n******************Test Tree is Empty**************\n\n");

	printf("Send empty tree\n");
	treeIsEmpty(NULL);

	printf("Send non- empty tree\n");
	treeIsEmpty(t);

	printf("\n\n******************Test Tree has two children**************\n\n");

	printf("Test with Null tree root\n");

	treeHasTwoChildren(NULL);
	
	printf("Test with non-Null tree root\n");

	treeHasTwoChildren(t->root);

	printf("\n\n******************Test Delete Node**************\n\n");

	printf("Delete Min (Leaf Node): 40\n\n");

	treeDeleteNode(t, input3);

	printf("\nNew Min %d\n",*(int*)treeFindMin(t));

	printf("\nTest deleting root --> 70\n\n");
	printf("Post Order print (Last element should be new root):\n");
	treePostOrderPrint(t, print);
	printf("\n");
	*input9=70;

	treeDeleteNode(t, input9);

	printf("New Post Order print (Last element should be new root):\n");

	treePostOrderPrint(t, print);

	printf("\nRe-input the delete data ---> 70 \n");
	int * input10=(int*)malloc(sizeof(int));
	*input10=70;

	treeInsertNode(t, input10);

	printf("New Post Order output with 70\n");
	treePostOrderPrint(t, print);


	printf("\n\n");
	printf("Test empty data in delete node: \n");

	treeDeleteNode(t, NULL);

	printf("Test empty TREE in delete node: \n");

	treeDeleteNode(NULL, input3);
	
	printf("\n\n******************Test Delete Tree**************\n\n");

	printf("Send Null tree\n");
	destroyBalancedBinTree(NULL);
	printf("Delete Tree\n");
	destroyBalancedBinTree(t);
	printf("Tree deleted\n");

	
	return 0;
}	
