#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    };
    // struct node *front = NULL;
    // struct node *rear = NULL;
    void enqueue(int x){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;
        if (newNode == NULL) {
            cout << "Overflow" << endl;
     }
  
}
int main() {
    return 0;
     }