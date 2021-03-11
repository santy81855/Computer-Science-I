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

Node *removeNode(Node *root, int value)
{
    if (root == NULL)
        return NULL;
    if (value < root->data)
        root->left = removeNode(root->left, value);
    else if (value > root->data)
        root->right = removeNode(root->right, value);
    // if the target = root->data then we are on the node we want to remove, so we will write our code here
    else if (value == root->data)
    {
        // Check if the node we want to remove has 0 children
        if (root->left == NULL && root->right == NULL)
        {
            // all we have to do is free the node and return null in its place
            free(root);
            return NULL;
        }
        // Check if the nade we want to remove has 1 child, and it is on the left
        if (root->right == NULL)
        {
            // This means we have only a left child
            // In this case, we must replace the node we want to remove with its child
            Node *leftChild = root->left;
            // We can now free the node we want to remove
            free(root);
            // Now we can replace it with its left child by returning the left child
            return leftChild;
        }

        // now we check if the node we want to remove has 1 child, and it is on the right
        if (root->left == NULL)
        {
            // We will do the same as above except we will store the right child instead
            Node *rightChild = root->right;
            free(root);
            return rightChild;
        }

        // If we make it here past the if statements above, it means the node we want to remove has 2 children.
        // This is still not too complicated to remove, but we have to be aware of a couple of concepts:
        // We can't just replace this node with its right or left child, we have to replace it with 1 of the following nodes:
        // 1) The Largest node to the left of it or the smallest node to the right of it. It is your choice.
        // The reason we have to do this is because either of those 2 options will give you a node that can go in the place of the one we want to remove without messing up the order.
        // I will choose the largest on the left.

        // So we go to the left of the node
        Node *replacement = root->left;

        // The following while loop will take us to the largest node on the left of the node we want to remove.
        // It is basically saying, "as long as there is a larger node (a node on the right), we will move into it"
        while (replacement->right != NULL)
            replacement = replacement->right;

        // The node with the value we want to remove is stored in "root" right now. The node with the value we need to replace it with is stored under "replacement".
        // So let's replace that value
        root->data = replacement->data;

        // Now that the node has the appropriate value, we have to remove the node with the duplicate value. aka the node stored in the "replacement" variable
        // The way we can do that is by just taking advantage of the recursion.
        // We know that for the node to be the largest on the left, it cannot have a right child, so it will fall into one of the cases above.
        // The only concept to be aware of here, is that we have to call the removeNode() function to the left of the current node so that we don't remove the node we are on.
        root->left = removeNode(root->left, replacement->data);
    }

    // Don't forget to return the root after we have finished the function
}

void reverseOrderPrint(Node *root)
{
    if (root == NULL)
        return;

    reverseOrderPrint(root->right);
    printf("%d\n", root->data);
    reverseOrderPrint(root->left);
}

int findMin(Node *root)
{
    // This function is super easy. We know that we can just go left until we hit null and we will be on the smallest value
    // First we check for an empty tree, however
    if (root == NULL)
        return -98765431; // just returning a number that is very unlikely to be in a tree
    while (root->left != NULL)
        root = root->left;
    return root->data;
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
    root = addNode(root, -2);

    // Now let's print the tree inOrder
    printf("In order:\n");
    inOrderPrint(root);

    // Now let's print the tree in reverse order
    printf("In reverse order:\n");
    reverseOrderPrint(root);

    // Let's find the smalles value in the tree and print it
    printf("The smalles value in the tree is %d\n", findMin(root));

    // Remove the node with the value 1
    root = removeNode(root, 1);

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