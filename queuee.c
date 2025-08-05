#include <stdio.h>

int queue[50];
int FRONT = -1, REAR = -1;
int size = 0, value;

void enqueue() {
    if (REAR == size - 1) {
        printf("Queue is Overflow\n");
    } else {
        if (FRONT == -1) {
            FRONT = 0;
        }
        queue[++REAR] = value;
        printf("%d Enqueued\n", value);
    }
}

void dequeue() {
    if (FRONT == -1 || FRONT > REAR) {
        printf("Queue is Underflow\n");
    } else {
        printf("Dequeued %d\n", queue[FRONT++]);
        if (FRONT > REAR) {
            FRONT = REAR = -1;
        }
    }
}

void display() {
    if (FRONT == -1 || FRONT > REAR) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue: ");
        for (int i = FRONT; i <= REAR; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
