
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* create_node(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node* insertion(struct Node* root, int data) {
	if (root == NULL) return create_node(data);
	if (data < root->data)
		root->left = insertion(root->left, data);
	else if (data > root->data)
		root->right = insertion(root->right, data);
	return root;
}

void inorder(struct Node* root) {
	if (root == NULL) return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void preorder(struct Node* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct Node* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
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

struct Node* delete_node(struct Node* root, int key) {
	if (root == NULL) return root;
	if (key < root->data)
		root->left = delete_node(root->left, key);
	else if (key > root->data)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			struct Node* temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		struct Node* temp = find_min(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}

int main() {
	struct Node* root = NULL;

	root = insertion(root, 50);
	root = insertion(root, 30);
	root = insertion(root, 70);
	root = insertion(root, 20);
	root = insertion(root, 40);
	root = insertion(root, 60);
	root = insertion(root, 80);

	printf("Inorder Traversal: ");
	inorder(root);

	printf("\nPreorder Traversal: ");
	preorder(root);

	printf("\nPostorder Traversal: ");
	postorder(root);

	int key = 40;
	struct Node* found = search(root, key);
	printf("\n\nSearch %d: %s", key, found ? "Found" : "Not Found");

	struct Node* minNode = find_min(root);
	struct Node* maxNode = find_max(root);
	printf("\nMin: %d", minNode ? minNode->data : -1);
	printf("\nMax: %d", maxNode ? maxNode->data : -1);

	root = delete_node(root, 30);
	printf("\nInorder after deleting 30: ");
	inorder(root);

	printf("\n");
	return 0;
}
