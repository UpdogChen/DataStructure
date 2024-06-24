#include<iostream>
using namespace std;

class node {
public:
	node() :value(0), next(NULL), prev(NULL) {}
	node(int Value) :value(Value), next(NULL), prev(NULL) {}
	node* getNext() { return next; }
	node* getPrev() { return prev; }
	int getValue() { return value; }
	friend void insert(int Value, node* afterMe);
	friend void deleteNode(node*& delNode);
	void print();
private:
	int value;
	node* next;
	node* prev;
};
typedef node* nodeptr;
nodeptr head = NULL;

int main() {
	head = new node(3);
	for (int i = 0; i < 10; i++)
		insert(i, head);
	head->print();
	nodeptr here = head;
	here = head->getNext()->getNext();
	deleteNode(here);
	head->print();
}

void insert(int Value, node* afterMe) {
	nodeptr newNode;
	newNode = new node;
	newNode->value = Value;
	newNode->prev = afterMe;
	newNode->next = afterMe->next;
	afterMe->next = newNode;
	if (newNode->next != NULL)
		(newNode->next)->prev = newNode;
}
void deleteNode(node*& delNode) {
	if (head == delNode)
		head = delNode->next;
	if(delNode->next !=NULL)
		delNode->next->prev = delNode->prev;
	if (delNode->prev != NULL)
		delNode->prev->next = delNode->next;
	delete delNode;
	delNode = NULL;
}
void node::print() {
	if (head == NULL) {
		cout << "The list is empty.\n";
	}
	nodeptr current = head;
	while (current != NULL) {
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}