#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorderIterative(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }}
void postorderIterative(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left != NULL)
            stack1[++top1] = node->left;
        if (node->right != NULL)
            stack1[++top1] = node->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

void preorderIterative(struct Node* root) {
    if (root==NULL)
        return;
    printf("%d",root->data);
    preorderIterative(root->left);
    preorderIterative(root->right);


    }

int findParent(struct Node* root, int key) {
    if (root == NULL)
        return -1;

    if ((root->left != NULL && root->left->data == key) || (root->right != NULL && root->right->data == key))
        return root->data;

    int leftParent = findParent(root->left, key);
    if (leftParent != -1)
        return leftParent;

    return findParent(root->right, key);
}
int depth(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}
bool ancestors(struct Node* root, int target) {
    if (root == NULL)
        return false;

    if (root->data == target)
        return true;

    if (ancestors(root->left, target) || ancestors(root->right, target)) {
        printf("%d ", root->data);
        return true;
    }

    return false;
}
int leafnodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return leafnodes(root->left) + leafnodes(root->right);
}
void createBST(struct Node** root,int val)
{
   struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    struct Node* t = *root;
    if(*root==NULL)
    {
        *root = temp;
        return;
    }
    if(val<t->data)
        createBST(&(t->left),val);
    else
        createBST(&(t->right),val);

}


int main() {
    int x,y;
    struct Node* root;
    while(y!=0){
            printf("enter value to be added to the tree");
    scanf("%d",&x);
    createBST(&root,x);
    printf("enter any key to continue and zero to end");
    scanf("%d",&y);

    }


    printf("Inorder Traversal: ");
    inorderIterative(root);
    printf("\nPostorder Traversal: ");
    postorderIterative(root);
    printf("\nPreorder Traversal: ");
    preorderIterative(root);
    printf("\nParent of 5: %d\n", findParent(root, 5));
    printf("Depth of the tree: %d\n", depth(root));
    printf("Ancestors of 5: ");
    ancestors(root, 5);
    printf("\nNumber of leaf nodes: %d\n", leafnodes(root));

    return 0;
}
