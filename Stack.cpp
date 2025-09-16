#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;  
};

int isEmpty(struct Node *head){
    if (head == NULL) {
    }
}
struct Node * push(struct Node *head, int new_data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = new_data;
    ptr->next = head;
    return ptr;
}

struct Node * pop(struct Node *head){
    if (isEmpty(head)) {
        return NULL;
    }
    struct Node *temp = head;
    *head = *head->next;
    free(temp);
    return head;
}
int main(){
    struct Node *head = NULL;
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);

    cout << "Deleted number: " << head->data << endl;
    head = pop(head);

}