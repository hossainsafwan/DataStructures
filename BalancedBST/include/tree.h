/****************************
Name: Safwan Hossain
ID: 0918742
email: safwan@uoguelph.ca
*********************************/
#ifndef STUDENT_TREE_API_
#define STUDENT_TREE_API_

/*You may add anything to this .h file that you need to add to your tree ADT*/

//YOU MUST LEAVE THESE TYPEDEFS AS IS. 
/**typedef for struct name*/
typedef struct BalancedBinTreeNode TreeNode;

/**typedef for struct name*/
typedef struct BalancedBinTree Tree;




/*complete the struct definitions.  You can change the existing parts if you wish.
*/
struct BalancedBinTree {
  //define your tree here.  You can change these if you need to but your tree must be abstract.
    TreeNode *root; ///< pointer to generic data that is to be stored in the tree
    int (*compareFP) (void *data1, void *data2); ///< function pointer to a comparison function for the purpose of inserting and deleting elements
    void (*destroyFP) (void *data); ///< function pointer to a function to free a single pointer that is deleted from the tree
    void *(*copyFP)(void *toBeCopy); ///< function pointer to a function that copies pointer data

  };



struct BalancedBinTreeNode{
    void *data; ///< pointer to generic data that is to be stored in the heap
    TreeNode *left; ///< pointer to left tree node of current node. Null if empty.
    TreeNode *right; ///< pointer to right tree node of current node. Null if empty.
    //Add additional structure elements here
    int height;
};
#include "balancedTreeAPI.h"

//add function prototypes as necessary

TreeNode * insertHelper(TreeNode* root , Tree * tree, void* data);
int heightOfNodes(TreeNode*);
int max(int a, int b);
TreeNode * rotateRightWithLeftChild(TreeNode*oldRoot,Tree*);
TreeNode *rotateLeftWithRightChild(TreeNode*oldRoot,Tree*);
TreeNode * doubleRotateWithLeftChild(TreeNode*oldRoot,Tree* tree);
TreeNode * rotateWithRightChild(TreeNode * , Tree* tree);
TreeNode * doubleRotateWithRightChild(TreeNode* oldRoot,Tree* tree);
TreeNode * rotateWithLeftChild(TreeNode * , Tree* tree);
void recurseCopy(TreeNode* node,Tree* newTree, void* toBeDeleted, Tree* oldTree);
void recurseInOrder(TreeNode* node, void (*printNodeFP) (void *data));
void recursePostOrder(TreeNode* node, void (*printNodeFP) (void *data));
void recursePreOrder(TreeNode* node, void (*printNodeFP) (void *data));
void destroyTreeHelper(TreeNode* node);
void* recurseSearch(TreeNode* node,void *data, Tree* tree,void**);



#endif