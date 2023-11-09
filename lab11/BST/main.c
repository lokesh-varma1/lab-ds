#include<stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

  Node* createNode(int data) {
    Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert (Node*root,int data){
if(!root)
    root = createNode(data);
    else if(data<root->data)
    insert(root->left,data);
    else if(data>root->data)
        insert( root->right,data);
    }

    void deletes(Node*root,int data){
    }
    int search(Node*root,int data)
    {
    if(!root)
        root =createNode(data);
     if(data==root->data)
    return (1);
    else if(data<root->data)
        search(root->left,data);
    else if(data>root->data)
        search(root->right,data);
    }
    void traverse(Node*root)
    {    if (root == NULL)
        return;

    struct Node* stack[100];

        int top = -1;
        Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }}

