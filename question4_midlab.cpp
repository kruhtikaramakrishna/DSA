#include <stdio.h>
#define SIZE 5   // Size of Circular Queue

int queue[SIZE];
int front = -1, rear = -1;

void addCall(int id) {
    // Check for Overflow
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("Queue is full. Please wait.\n");
        return;
    }
    // First element insertion
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1 && front != 0) { 
        rear = 0; // Circular movement
    } else {
        rear++;
    }
    queue[rear] = id;
    printf("Call added: %d\n", id);
}

void removeCall() {
    // Check Underflow
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Removed customer: %d\n", queue[front]);
    
    // If only one element
    if (front == rear) {
        front = rear = -1;
    } 
    else if (front == SIZE - 1) {
        front = 0;
    } 
    else {
        front++;
    }
}

void displayQueue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Customers in queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    // Adding fixed calls (as shown in question output)
    addCall(101);
    addCall(102);
    addCall(103);
    addCall(104);
    addCall(105);
    
    displayQueue();
    
    // Try adding one more to show queue full
    addCall(106);
    
    // Remove two calls
    removeCall();
    removeCall();
    
    displayQueue();
    
    // Add more calls
    addCall(104);
    addCall(105);
    addCall(106);
    addCall(107);
    
    displayQueue();
    
    return 0;
}

