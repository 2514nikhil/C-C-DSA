#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void traverse(struct Node *p);
struct Node *insert_beginning(struct Node *head);
struct Node *insert_end(struct Node *last, int value);
struct Node *insert_anywhere(struct Node *head, int new_data, int p);

int main()
{
    struct Node *head;

    head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *Second = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = Second;
    Second->data = 10;
    Second->next = NULL;

    head = insert_beginning(head);
    insert_end(Second, 12);
    insert_anywhere(head, 13, 5);
    insert_anywhere(head, 17, 6);
    traverse(head);
}

struct Node *insert_beginning(struct Node *head)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = 3;
    new_node->next = head;
    return new_node;
}
struct Node *insert_anywhere(struct Node *head, int new_data, int p)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *a = head;
    int i = 1;
    while (i != p - 1)
    {
        a = a->next;
        i++;
    }
    ptr->data = new_data;
    ptr->next = a->next;
    a->next = ptr;
    return ptr;
}

struct Node *insert_end(struct Node *last, int value)
{

    struct Node *last_node = (struct Node *)malloc(sizeof(struct Node));
    last->next = last_node;
    last_node->data = value;
    last_node->next = NULL;
    return last_node;
}

void traverse(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
