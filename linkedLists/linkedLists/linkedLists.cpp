#include <cstddef>
#include <iostream>
using namespace std;

class node {
public:
	node() :value(0), next(NULL) {};
	node(int Value) :value(Value), next(NULL) {};
	node(int Value, node* Next) :value(Value), next(Next) {};

	void printList();
	void insertFront(int Value);
	void deleteNode(int Value);
	void search(int target);
	void reverse();
private:
	int value;
	node* next;
};
typedef node* nodeptr;
nodeptr head = NULL;

int main() {
	head = new node();
	for (int i = 0; i < 10; i++) {
		head->insertFront(i + 1);
	}
	head->printList();
	head->reverse();
	head->printList();
	head->search(3);
}

void node::printList() {
	if (head == NULL) {
		cout << "The list is empty.\n";
	}
	nodeptr current= head;
	while (current != 0) {
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}
void node::insertFront(int Value) {
	head = new node(Value,head);
}
void node::deleteNode(int Value) {
	nodeptr current = head;
	nodeptr prev = NULL;
	while (current != NULL && current->value != Value) {
		prev = current;
		current = current->next;
	}
	if (current == NULL) {
		cout << "No " << Value << " in the list.\n";
	}
	else if (current == head) {
		head = current->next;
		delete current;
		current = NULL;
	}
	else {
		prev->next = current->next;
		delete current;
		current = NULL;
	}
}
void node::search(int target) {
	nodeptr current = head;
	if (head == NULL) 
		cout << "This list is empty.\n";
	else{
		int count = 0;
		while (current->value != target && current->next != NULL) {
			count++;
			current = current->next;
		}
		if (current->value == target)
			cout << "At " << count+1 << " position.\n";
		else
			cout << "Can't find this node.\n";

		}
}
void node::reverse() {
	if (head == NULL || head->next == NULL)
		return;
	nodeptr prev = NULL;
	nodeptr current = head;
	nodeptr preceding = head->next;
	while (preceding != NULL) {
		current->next = prev;
		prev = current;
		current = preceding;
		preceding = preceding->next;
	}
	current->next = prev;
	head = current;
}