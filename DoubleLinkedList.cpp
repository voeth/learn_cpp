#include<iostream>
#include <string>

using namespace std;

struct Node {
	int data=NULL;
	Node *next = NULL;
	Node *previous = NULL;
};

struct LinkedList {
	int length = 0;
	Node *head = NULL;
	Node *tail = NULL;
};

void  create(LinkedList *list) {
	int in;
	Node *node=NULL,*previous=NULL;
	while (true) {
		cout << "Enter the data of node: " << endl;
		cin >> in;
		if (in == 0) { 
			list->tail = node;
			break; }

		list->length++;
		if (!node) {
			node = new Node;
			list->head = node;
		}
		node->data = in;
		node->next = new Node;
		previous = node;
		node = node->next;
		node->previous = previous;
	}
}

void print(Node *node) {
	if (node->next) {
		while (node) {
			cout << node->data << " ";
			node = node->next;
		}
	}
	else {
		while (node) {
			cout << node->data << " ";
			node = node->previous;
		}
	}
}

Node* remove(Node *node,int val) {
	Node *next,*head=node;
	while (node) {
		if (node->data == val) {
			if (node->previous&&node->next) {
				node->next->previous = node->previous;
				node->previous->next = node->next;
			}
			else if (!node->previous) { 
				head = node->next;
				head->previous = NULL; 
				
			}
			else if (!node->next) { 
				node->previous->next = NULL; 
				break;
			};
			
		}
		node = node->next;
		
		
	}
	return head;
}

int main()
{
	LinkedList *list = new LinkedList;
	create(list);
	print(list->tail);
	remove(list->head,0);
	list->head = remove(list->head, 1);
	print(list->head);
}


