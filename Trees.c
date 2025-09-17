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
struct Node* search(struct Node* root, int key) {
	if (root == NULL || root->data == key) return root;
	if (key < root->data) 
    return search(root->left, key);
	return search(root->right, key);
}
struct Node* find_min(struct Node* root) {
	while (root && root->left) root = root->left;
	return root;
}
struct Node* find_max(struct Node* root) {
	while (root && root->right) root = root->right;
	return root;
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
    printf("\nMinimun");
    find_min(root);
    printf("\nMaximum");
    find_max(root);
    return 0;
}