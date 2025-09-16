#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (queue->size == queue->capacity)
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int main() {
    struct Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    int item = dequeue(queue);
    if (item != INT_MIN)
        printf("%d dequeued from queue\n", item);

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    item = dequeue(queue);
    if (item != INT_MIN)
        printf("%d dequeued from queue\n", item);

    item = dequeue(queue);
    if (item != INT_MIN)
        printf("%d dequeued from queue\n", item);

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}