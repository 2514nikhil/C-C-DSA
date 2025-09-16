#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct Node *insert(struct Node *root, int data)
{
    if (!root)
    {
        return createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void in_order(struct Node *root)
{
    if (root)
    {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}
void pre_order(struct Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}
void post_order(struct Node *root)
{
    if (root)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 23);
    root = insert(root, 20);
    root = insert(root, 77);
    root = insert(root, 32);
    printf("In_order: ");
    in_order(root);
    printf("Pre_order: ");
    pre_order(root);
    printf("Post_order: ");
    post_order(root);
    return 0;
}