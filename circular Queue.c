#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = data;
    printf("Inserted %d into queue\n", data);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
