#include<iostream>
using namespace std;
#define n 30
int p[n];
int front = -1;
int rear = -1;
void Display();

void Enqueue() {
    int x;
    cout << "\nEnter the element:\n";
    cin >> x;
    if ((rear + 1) % n == front) {
        cout << "\nQueue Overflow\n";
        return;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        p[rear] = x;
    }
    else {
        rear = (rear + 1) % n;
        p[rear] = x;
    }
    cout << "\n";
    Display();
}

void Dequeue() {
    if (front == -1 && rear == -1) {
        cout << "\nQueue Underflow\n";
        return;
    }
    else if (front == rear) {
        cout << "\nThe element that has been deleted is: " << p[front] << "\n";
        front = rear = -1;
    }
    else {
        cout << "\nThe element that has been deleted is: " << p[front] << "\n";
        front = (front + 1) % n;
    }
    cout << "\n";
    Display();
}

void Display() {
    int t = front;
    if (front == -1 && rear == -1)
        cout << "\nQueue Underflow";
    else {
        while (t != rear) {
            cout << p[t] << "\t";
            t = (t + 1) % n;
        }
        cout << p[t] << "\n";
    }
}

int main() {
    int ch = 0;
    while (1) {
        cout << "\nA) Enter 1 to insert element.\n";
        cout << "B) Enter 2 to delete element.\n";
        cout << "D) Enter 3 to exit.\n";
        cin >> ch;
        switch (ch) {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid input!/n";
        }
    }
}

