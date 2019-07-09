#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void validate (struct node *root, int minv, int maxv)
{
    if (root->data >= minv && root->data <= maxv)
    {
        if(root->left != NULL){
        validate (root->left, minv, root->data);
        validate (root->right, root->data, maxv);
        }
    }else
        cout << "Not BST" << endl;
}
/* newNode() allocates a new node with the given data and NULL left and
right pointers. */
struct node* newNode(int data)
{
// Allocate memory for new node
struct node* node = (struct node*)malloc(sizeof(struct node));

// Assign data to this node
node->data = data;

// Initialize left and right children as NULL
node->left = NULL;
node->right = NULL;
return(node);
}


int main()
{
/*create root*/
struct node *root = newNode(5);
/* following is the tree after above statement

     5
	/ \
	NULL NULL
*/


root->left	 = newNode(4);
root->right	 = newNode(8);
/* 4 and 8 become left and right children of 5
       5
	  / \
	 4	 8
	/ \ / \
	NULL NULL NULL NULL
*/


root->left->left = newNode(3);
root->left->right = newNode(6);
//root->left->right = newNode(4);
/* 3 and 6 becomes left and children of 4
       5
	/	 \
   4	   8
  / \	 / \
3    6 NULL NULL
/ \
NULL NULL
*/
validate (root, -1, 999);
return 0;
}
