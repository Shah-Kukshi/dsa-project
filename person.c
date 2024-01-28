#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define MAX_QUEUE_SIZE 100

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
    Person queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isQueueFull(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

void enqueue(Queue *q, Person p) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot add person.\n");
        return;
    }


    for (int i = q->front; i <= q->rear; i++) {
        if (strcasecmp(q->queue[i].name, p.name) == 0) {
            printf("Error: Person with the name '%s' already exists in the queue. Cannot add duplicate.\n", p.name);
            return;
        }
    }

    if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }

    strcpy(q->queue[q->rear].name, p.name);
    q->queue[q->rear].age = p.age;

    printf("Person added to the queue successfully.\n");
}

void dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot delete person.\n");
        return;
    }

    printf("Deleted person: %s\n", q->queue[q->front].name);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

void search(Queue *q, char *name) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot search for person.\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        if (strcmp(q->queue[i].name, name) == 0) {
            printf("Person found: %s, Age: %d\n", q->queue[i].name, q->queue[i].age);
            return;
        }
    }

    printf("Person not found in the queue.\n");
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue of Persons:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("Name: %s, Age: %d\n", q->queue[i].name, q->queue[i].age);
    }
}


int main() {
    Queue q;
    initializeQueue(&q);

    int choice;
    Person p;
    char name[50];

    do {
        printf("\nQueue of Persons\n");
        printf("1. Add Person\n");
        printf("2. Delete Person\n");
        printf("3. Search Person\n");
        printf("4. Display Person\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Check if the input is an integer
        if (scanf("%d", &choice) != 1) {
            // Handle the error
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue; // Skip the rest of the loop and restart
        }

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", p.name);
                printf("Enter age: ");
                scanf("%d", &p.age);
                enqueue(&q, p);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                search(&q, name);
                break;
            case 4:
                displayQueue(&q); // Call the display function
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // Clear the input buffer
        while (getchar() != '\n');

    } while (choice != 5);

    return 0;
}