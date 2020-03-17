/****************************
Name: Safwan Hossain
ID: 0918742
email: safwan@uoguelph.ca
*********************************/

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "funcPointers.h"
#include "balancedTreeAPI.h"

Tree *createBalancedBinTree(int (*compareFP) (void *data1, void *data2), void (*destroyFP) (void *toBeDeleted),void *(*copyFP)(void *toBeCopy))
{
	Tree* avlTree;
	avlTree= (Tree*)malloc(sizeof(Tree));

	avlTree->root=NULL;/*(TreeNode*)malloc(sizeof(TreeNode*));*/



	avlTree->compareFP=compareFP;
	avlTree->destroyFP=destroyFP;
	avlTree->copyFP=copyFP;

	if (avlTree->compareFP == NULL || avlTree->destroyFP == NULL || avlTree->copyFP == NULL)
	{

		return NULL;
	}

	return avlTree;



}

TreeNode *createBalancedBinNode(void *data)
{

	TreeNode* new =(TreeNode*)malloc(sizeof(TreeNode*)*10);

	new->data=data;
	new->left=NULL;
	new->right=NULL;
	new->height = 0;

	return new;
}

//wrapper of insertHelper
void treeInsertNode(Tree *theTree, void *toBeInserted)
{	
	if (theTree == NULL || toBeInserted == NULL)
	{
		printf("Inputted Null Tree or Null data\n");
		return;
	}


	if (theTree->root == NULL)
	{
		theTree->root=insertHelper(theTree->root, theTree, toBeInserted);
	}
	else
	{
		/*TreeNode* insertedNode = */insertHelper(theTree->root, theTree, toBeInserted);





	}

}

//helper of treeInsertNode
TreeNode * insertHelper(TreeNode* root , Tree * tree, void* data)
{
	// printf("HIMMY\n");
	if (tree == NULL)
	{


		return NULL;

	}

	if (root == NULL)
	{
		//printf("Tim\n");
		TreeNode* new = createBalancedBinNode(data);//create new node
		 printf("Inserted value: %d\n",*(int*)new->data );

	 	//root=new;
		return new;

	}
	else
	{

		//printf("eneasdsat\n\n\n");


		if(tree->compareFP(data,root->data)<=0)
		{
		   // printf("left\n");

			root->left =  insertHelper(root->left, tree, data);

		 	// printf("inside left insert: %d\n\n",*(int*)root->left->data);

			//rebalancing
		 	//left left
			if (heightOfNodes(root->left)-heightOfNodes(root->right) > 1)// >= 1 because the heightOfNodes checks the height of root not root->left
			{
				if (tree->compareFP(data,root->left->data) <=0)
				{
					// printf("Root is: %d\n",*(int*)root->data );

					root = rotateRightWithLeftChild(root,tree);


					// printf("Root after rotation: %d\n",*(int*)root->right->data );
				}
				else//left right
				{
					root=doubleRotateWithLeftChild(root,tree);
				}
			}

		}
		else if (tree->compareFP(data,root->data)>0)
		{
			// printf("right\n");
			root->right =  insertHelper(root->right, tree, data);



			//rebalancing
			if (heightOfNodes(root->right)-heightOfNodes(root->left) > 1)//right right
			{
				if (tree->compareFP(data,root->right->data)> 0)
				{

					root=rotateLeftWithRightChild(root,tree);
				}
				else//right left
				{
					root=doubleRotateWithRightChild(root,tree);
				}
			}

		}

	}

	return root;

}

int heightOfNodes(TreeNode *node)
{
	if (node == NULL)
	{
		return -1;

	}

	return max(heightOfNodes(node->left), heightOfNodes(node->right))+1;

}

int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{

		return b;
	}

}

TreeNode * rotateRightWithLeftChild(TreeNode* oldRoot, Tree* tree)//left left
{
	TreeNode*temp=oldRoot->left;
	oldRoot->left=temp->right;
	temp->right=oldRoot;
	temp->height=heightOfNodes(temp);
	oldRoot->height=heightOfNodes(oldRoot);

	// printf("Temp is: %d\n",*(int*)temp->data );

	if(tree->root == oldRoot)
	{
		tree->root=temp;
	}


	return temp;


}
TreeNode *rotateLeftWithRightChild(TreeNode* oldRoot, Tree* tree)//right //right
{
	TreeNode*temp=oldRoot->right;
	oldRoot->right=temp->left;
	temp->left=oldRoot;
	temp->height=heightOfNodes(temp);
	oldRoot->height=heightOfNodes(oldRoot);

	// printf("Temp is: %d\n",*(int*)temp->data );

	if(tree->root == oldRoot)
	{
		tree->root=temp;
	}
	
	return temp;
}

TreeNode * doubleRotateWithLeftChild(TreeNode*oldRoot,Tree* tree)//left right
{
	oldRoot->left=rotateWithRightChild(oldRoot->left,tree);
	oldRoot=rotateRightWithLeftChild(oldRoot,tree);
	return oldRoot;


}

TreeNode * rotateWithRightChild(TreeNode * oldRootLeft,Tree* tree)
{
	TreeNode* temp=oldRootLeft->right; //right of root->left
	oldRootLeft->right=temp->left;
	temp->left=oldRootLeft;

	return temp;

}


TreeNode * doubleRotateWithRightChild(TreeNode*oldRoot,Tree* tree)//right left
{
	oldRoot->right=rotateWithLeftChild(oldRoot->right,tree);
	oldRoot=rotateLeftWithRightChild(oldRoot,tree);
	return oldRoot;


}

TreeNode * rotateWithLeftChild(TreeNode * oldRootRight,Tree* tree)
{
	TreeNode* temp=oldRootRight->left; //right of root->left
	oldRootRight->left=temp->right;
	temp->right=oldRootRight;

	return temp;

}

void treeDeleteNode(Tree *theTree, void *toBeDeleted)
{
	if (theTree == NULL || theTree->root == NULL || toBeDeleted ==NULL)
	{

		printf("Empty tree or empty data input\n");
		return;
	}
	Tree* newTree = createBalancedBinTree(theTree->compareFP, theTree->destroyFP,theTree->copyFP);
	//printf("Hello\n");
	recurseCopy(theTree->root,newTree, toBeDeleted,theTree);

	*theTree= *newTree;
	
}

void recurseCopy(TreeNode* node,Tree* newTree, void* toBeDeleted, Tree* oldTree)
{
	if(node == NULL)
	{

		return ;

	}

	recurseCopy(node->left,newTree,toBeDeleted,oldTree);

	recurseCopy(node->right,newTree,toBeDeleted,oldTree);

	if(newTree->compareFP(toBeDeleted,node->data) != 0)
	{
		// printf("Data: %d\n",*(int*)node->data);

		void *s = newTree->copyFP(node->data);

		treeInsertNode(newTree, s);

		free(node->data);
		free(node);		


	}

	
}


void treeInOrderPrint(Tree *theTree, void (*printNodeFP) (void *data))
{
	if (theTree == NULL || theTree->root == NULL || printNodeFP == NULL)
	{
		printf("Empty tree or Null function pointer sent\n\n");
		return;
	}
	recurseInOrder(theTree->root,print);

}

void treePreOrderPrint(Tree *theTree, void (*printNodeFP) (void *data))
{
	if (theTree == NULL || theTree->root == NULL || printNodeFP == NULL)
	{
		printf("Empty tree or Null function pointer sent\n\n");
		return;
	}
		recursePreOrder(theTree->root,print);


}

void treePostOrderPrint(Tree *theTree, void (*printNodeFP) (void *data))
{
	if (theTree == NULL || theTree->root == NULL || printNodeFP == NULL)
	{
		printf("Empty tree or Null function pointer sent\n\n");
		return;
	}

	recursePostOrder(theTree->root,print);


}

//HELPER
void recurseInOrder(TreeNode* node, void (*printNodeFP) (void *data))
{
	if (node == NULL)
	{

		return;
	}

	recurseInOrder(node->left, printNodeFP);

	printNodeFP(node->data);

	recurseInOrder(node->right, printNodeFP);

	
}

//HELPER
void recursePostOrder(TreeNode* node, void (*printNodeFP) (void *data))
{
	if (node == NULL)
	{

		return;
	}

	recursePostOrder(node->left, printNodeFP);

	recursePostOrder(node->right, printNodeFP);

	printNodeFP(node->data);


	
}


//HELPER
void recursePreOrder(TreeNode* node, void (*printNodeFP) (void *data))
{
	if (node == NULL)
	{

		return;
	}

	printNodeFP(node->data);

	recursePreOrder(node->left, printNodeFP);

	recursePreOrder(node->right, printNodeFP);



	
}

void *treeFindMin(Tree *theTree)
{
	if (theTree == NULL || theTree->root == NULL)
	{
		printf("Empty Tree or empty root sent\n");
		return NULL;

	}

	TreeNode* node=theTree->root;

	while(node->left !=NULL)
	{

		node=node->left;
	}

	return node->data;
}

void *treeFindMax(Tree *theTree)
{
	if (theTree == NULL || theTree->root == NULL)
	{
		printf("Empty Tree or empty root sent\n");
		return NULL;

	}

	TreeNode* node=theTree->root;

	while(node->right !=NULL)
	{

		node=node->right;
	}

	return node->data;
}

void destroyBalancedBinTree(Tree *toBeDeleted)
{

	if (toBeDeleted == NULL)
	{
		printf("Null tree given\n");

		return;
	}

	destroyTreeHelper(toBeDeleted->root);


	free(toBeDeleted);

}

void destroyTreeHelper(TreeNode* node)
{
	if (node == NULL)
	{

		return;
	}

	destroyTreeHelper(node->left);
	destroyTreeHelper(node->right);

	free(node->data);
	free(node);

}

int treeIsEmpty(Tree *theTree)
{

	if (theTree == NULL || theTree->root == NULL  )
	{
		printf("The Tree is empty\n\n");
		return 1;
	}
	else
	{
		printf("The Tree is not empty\n\n");

		return 0;
	}
}

int treeHasTwoChildren(TreeNode *root)/*CLARIFY!!!!!!!!!!!!!!*/
{

	if (root == NULL)
	{
		printf("Sent empty node\n");
		return 0;

	}
	else if (root->left != NULL && root->right != NULL)
	{
		printf("Tree has two Children\n");

		return 1;
	}
	else 
	{
		printf("Node doesn't have two children\n");
		return 0;
	}
}

void *treeFindNode(Tree *theTree, void *data)
{
	if (theTree == NULL || data == NULL || theTree->root == NULL)
	{
		printf("Sent empty tree or empty data\n\n");
		return NULL;
	}
	void* s= malloc(sizeof(int));
			s=NULL;
	   recurseSearch(theTree->root,data, theTree, &s );

		// printf("s value: %d\n\n",*(int*)s);

	return s;
}

void* recurseSearch(TreeNode* node,void *data, Tree* tree,void ** s)
{
	if (node == NULL)

	{
		return NULL;
	}

		// printf("data: %d\n",*(int*)node->data);
	if (tree->compareFP(data,node->data) == 0)
	{

				*s=node->data;
		return node->data;
	}
	recurseSearch(node->left,data,tree,s);


	recurseSearch(node->right,data,tree,s);




	return NULL;
}
