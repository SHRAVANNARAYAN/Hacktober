#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* front;
node* rear;

void Push() {
    int x;
    cout << "How many nodes do you want to enter?\n";
    cin >> x;
    node* temp;
    cout << "Enter the elements:\n";
    for (int i = 0; i < x; i++) {
        temp = new node();
        temp->next = front;
        cout << (i + 1) << ". ";
        cin >> temp->data;
        if (front == NULL && rear == NULL) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
    }
}

void Pop() {
    if (front == NULL) {
        cout << "Queue Underflow";
        return;
    }
    if (front == rear) {
        free(front);
        front = rear = NULL;
        return;
    }
    node* temp = front;
    while (temp->next != rear) {
        temp = temp->next;
    }
    temp->next = front;
    free(rear);
    rear = temp;
}

void Display() {
    if (front == NULL) {
        cout << "Queue Underflow";
        return;
    }
    node* temp = front;
    while (temp->next != front) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << temp->data << "\t";
}

int main()
{
    int a;
    front = NULL;
    rear = NULL;
    Push();
    while (1) {
        cout << "\nEnter 1 to delete element\n";
        cout << "Enter 2 to display circular queue\n";
        cout << "Enter 3 to exit\n";
        cin >> a;
        switch (a)
        {
        case 1:
            Pop();
            break;
        case 2:
            Display();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid input!/n";
        }
    }
}

