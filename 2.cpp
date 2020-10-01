#include<iostream>
using namespace std;

struct node {
	int data;
	int priority;
	node* next;
};

node* head;

void Push(int data, int priority) {
	node* temp;
	temp = new node();
	temp->data = data;
	temp->priority = priority;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else if (head->priority > priority) {
		temp->next = head;
		head = temp;
	}
	else {
		node* temp1 = head;
		while (temp1->next != NULL && temp1->next->priority < priority) {
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
	}
}

void Pop() {
	node* temp = head;
	if (head == NULL) {
		cout << "Queue Underflow";
	}
	else {
		head = head->next;
		free(temp);
	}
}

void Peek() {
	if (head == NULL) {
		return;
	}
	cout << "\nThe element with top priority is: " << head->data << "\n\n";
}

void Display() {
	if (head == NULL) {
		cout << "Queue Underflow";
		return;
	}
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
}

int main() {
	head = NULL;
	int n, data, priority;
	cout << "How many nodes do you want to insert?\n";
	cin >> n;
	if (n == 0) {
		Display();
		return 0;
	}
	cout << "\nEnter the elements and their priority:\n";
	for (int i = 0; i < n; i++) {
		cout << "\n" << (i + 1) << ". ";
		cin >> data >> priority;
		Push(data, priority);
	}
	Peek();
	Display();
}