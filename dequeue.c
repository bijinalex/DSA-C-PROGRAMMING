#include <stdio.h>

#define SIZE 10

int Q[SIZE];
int FRONT = -1, REAR = -1;

void insertFront(int ITEM) {
    if (FRONT == 0) {
        printf("Cannot insert at front.\n");
        return;
    }
    if (FRONT == -1) { 
        FRONT = REAR = 0;
    } else {
        FRONT--;
    }
    Q[FRONT] = ITEM;
    printf("Inserted %d at front.\n", ITEM);
}

void insertRear(int ITEM) {
    if (REAR == SIZE - 1) {
        printf("Cannot insert at rear. Deque full.\n");
        return;
    }
    if (REAR == -1) { 
        FRONT = REAR = 0;
    } else {
        REAR++;
    }
    Q[REAR] = ITEM;
    printf("Inserted %d at rear.\n", ITEM);
}

void deleteFront() {
    if (FRONT == -1 || FRONT > REAR) {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }
    printf("Deleted %d from front.\n", Q[FRONT]);
    FRONT++;
    if (FRONT > REAR) {  
        FRONT = REAR = -1;
    }
}

void deleteRear() {
    if (FRONT == -1 || FRONT > REAR) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }
    printf("Deleted %d from rear.\n", Q[REAR]);
    REAR--;
    if (REAR < FRONT) { 
        FRONT = REAR = -1;
    }
}

void display() {
    if (FRONT == -1 || FRONT > REAR) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = FRONT; i <= REAR; i++) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

int main() {
    int choice, ITEM;

    while (1) {
        printf("\nMENU\n");
        printf("1. Insert front\n");
        printf("2. Insert rear\n");
        printf("3. Delete front\n");
        printf("4. Delete rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert at front: ");
                scanf("%d", &ITEM);
                insertFront(ITEM);
                break;
            case 2:
                printf("Enter item to insert at rear: ");
                scanf("%d", &ITEM);
                insertRear(ITEM);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
