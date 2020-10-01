#include<iostream>
using namespace std;
#define N 30
int p[N];
int f = -1;
int r = -1;

void Swap(int* a, int* b) {
    int t;
    t = *b;
    *b = *a;
    *a = t;
}

void Sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                Swap(&arr[i], &arr[j]);
            }
        }
    }
}

void Enqueue() {
    int x;
    cout << "\nEnter the element:\n ";
    cin >> x;
    if (r == N - 1)
        cout << "\nQueue Overflow\n";
    else if (f == -1 && r == -1) {
        f = r = 0;
        p[f] = x;
    }
    else {
        r++;
        p[r] = x;
        Sort_array(p, N);
    }
}

void Dequeue() {
    if (f == -1 && r == -1)
        cout << "Queue Underflow";
    else if (f == r) {
        cout << "\nThe element that been removed is: " << p[f] << "\n";
        f = r = -1;
    }
    else {
        cout << "\nThe element that been removed is: " << p[f] << "\n";
        f++;
    }
}

void Display() {
    int t = f;
    cout << "\n";
    while (t != r) {
        cout << p[t] << "\t";
        t++;
    }
    cout << p[t];
    cout << "\n";
}

int main() {
    int ch = 0;
    while (1) {
        cout << "\nA) Enter 1 to insert element.\n";
        cout << "B) Enter 2 to delete element.\n";
        cout << "C) Enter 3 to Display elements.\n";
        cout << "D) Enter 4 to exit.\n";
        cin >> ch;
        switch (ch) {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid input!/n";
        }
    }
    return 0;
}
