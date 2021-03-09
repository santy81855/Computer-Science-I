#include <stdio.h>
#include <stdlib.h>

// struct for a bst node
typedef struct Node
{
    int data;           // the value we store
    struct Node *left;  // the pointer to the left child
    struct Node *right; // the pointer to the right child
} Node;

// This function does not put any duplicate numbers in the tree, but it can be altered to store duplicates by changing the conditional of the last two if statements,
// depending on whether you want the duplicate to be a left or right child. It is your decision.
Node *addNode(Node *root, int value)
{
    // check if the tree is empty OR if we have reached an open spot (base case)
    if (root == NULL)
    {
        // if we fall into this if statement it means either our tree is empty, in which case we just add the node here
        // or it means that we have reached the empty location where we want to add this node.
        // So either way we will add a node here and return it.
        Node *newNode = calloc(1, sizeof(Node));
        newNode->data = value; // give the new node the value we passed into the function
        // make the children of the new node null since it has no children
        newNode->left = NULL;
        newNode->right = NULL;
        // return this newNode to its new home.
        // if the list was empty, then it will be the root of the tree.
        // if the list was not empty, then it will just be the child of some node
        return newNode;
    }
    // Now we check to see if we need to go to the left or to the right of the current node, since a binary search tree stores nodes in numerical order
    // if the value is smaller than the value at the current node (root) then we have to go left
    if (value < root->data)
    {
        root->left = addNode(root->left, value);
    }
    // if the value is greater than the value at hte current node (root) then we have to go right
    if (value > root->data)
    {
        root->right = addNode(root->right, value);
    }
    // We return addNode to root->left and root->right above so that when we create the node in the base case, it will know what it is the child of

    // finally we return the root back to the main function
    return root;
}

void inOrderPrint(Node *root)
{
    // if the tree is empty we just return to main OR we if we reach null we just return to the previous recursive call
    if (root == NULL)
        return;
    // first we go left
    inOrderPrint(root->left);
    // Then we print
    printf("%d\n", root->data);
    // then we go right
    inOrderPrint(root->right);
}

void postOrderFree(Node *root)
{
    if (root == NULL)
        return;

    postOrderFree(root->left);  // go left
    postOrderFree(root->right); // go right
    free(root);                 // free last
}

Node *findNode(Node *root, int target)
{
    // We check if the tree is empty or if we have reached null (base case)
    if (root == NULL)
        return NULL;
    // Now we check if the current node is our target
    if (target == root->data)
    {
        // if it is then we return the node
        return root;
    }
    // if the current node is not the target, then we have to see if we need to go left OR right
    if (target < root->data)
    {
        // if the target is smaller than the current node then we have to go to the left
        return findNode(root->left, target); // we return the function because eventually we will reach teh node we want to return
    }
    if (target > root->data)
    {
        // if the target is greater than the current node, we have to go to the right
        return findNode(root->right, target);
    }
    // We don't need a return at the end because we will already either return the node when we find it or we will return NULL based on our base case
}

int main()
{
    // Let's declare a tree. It is very similar to a linked list, but
    // we call it root instead of head.
    Node *root = NULL;

    // Add some values to the tree
    // This can be done both iteratively or recursively, but recursion makes it a lot easier
    root = addNode(root, 1);
    root = addNode(root, 2);
    root = addNode(root, 3);

    // Now let's print the tree inOrder
    inOrderPrint(root);

    // The function for removing a node is actually quite complicated so we can talk about it in session sometime

    // Let's find a node in the tree and return it into a temp variable so we can print it
    Node *temp = findNode(root, 2);
    // We first check for null in case it wasn't found so we don't dereference it if that's the case
    if (temp == NULL)
        printf("The node was not found\n");
    else
        printf("The node was found. It has the address %p, and the value is %d\n", temp, temp->data);

    // Now let's free the tree
    postOrderFree(root);

    return 0;
}