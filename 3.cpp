#include <iostream>
using namespace std;
#define n 30
int pq[n];
int f = -1;
int r = -1;

void Push() {
    int count = 0;
    count++;
    int x;
    cout << "\nEnter the element\n";
    cin >> x;
    if (r == n - 1)
        cout << "Stack Overflow\n";
    else if (f == -1 && r == -1) {
        f = r = 0;
        pq[r] = x;
    }
    else {
        for (int i = r; i >= f; i--)
            pq[i + 1] = pq[i];
        pq[f] = x;
        r++;
    }
}

void Pop() {
    int count = 0;
    count--;
    int x;
    if (f == -1 && r == -1)
        cout << "\nStack Underflow\n";
    else if (f == r) {
        cout << "\nThe element that has been deleted is: " << pq[r] << "\n";
        f = r = -1;
    }
    else {
        cout << "\nThe element that has been deleted is: " << pq[f] << "\n";
        f++;
    }
}

void Display() {
    int t = f;
    while (t != r) {
        cout << pq[t] << "\t";
        t++;
    }
    cout << pq[t];
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
            Push();
            break;
        case 2:
            Pop();
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
