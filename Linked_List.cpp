/*
Create a single directional linked list.
Must use two point,one point for previous point and another point for latter point.
For example:
		p2 = p1;
		p1 = p1->next;
*/
#include <iostream>
using namespace std;
class node {
public:
	node() {};
	node(int v, node * n = NULL) { value = v; next = n; };
	int value;
	node * next;
	~node() {};
};

int main() {
	node * create(),*insert(node *,int),*remove(node*,int),*head;
	void print(node *);
	head=create();
	//print(insert(head, 3));
	head=remove(head, 3);
	print(remove(head, 9));
}

node * create() {
	int input = 0, count = 0;// record the number of node
	node *head=NULL,*p2=NULL;
	while (true) {
		cout << "Enter the node value:" << endl;
		cin >> input;
		if (input==0) break;
		else {
			node *p1 = new node;
			p1->value = input;
			if (count == 0) { 
				head = p1;
				p2 = p1;
			}
			else {
				p2->next = p1;// Previous node point to next node
				p2 = p1; // Node move forward
			}
		}
		count++;
	}
	p2->next = NULL;// Don't forget set the lasted point as NULL
	return head;
}

node * insert(node *head, int value) {
	int count = 0;
	node *newNode = new node(value); // 全部用指针来进行操作就没那么容易出错
	node *p1 = head, *p2 = NULL;
	while (p1 != NULL) {
		// Ascending
		if (value <= p1->value) {
			if (count == 0) { // Insert it in head
				newNode->next = head;
				head = newNode;
		    }
			else {	// Insert it in middle
				p2->next = newNode;
				newNode->next = p1;
			}
			break;
		}
		else if (p1->next == NULL) { // Move to tail, the inserting value is highest
			p1->next = newNode;
			break;
		}  
		p2 = p1; // Save the previous node

		p1 = p1->next; // Move the point forward
		count++;
	}
	return head;
}

node * remove(node *head, int value) {
	if (value == head->value) {
		cout << "Node " << head->value << " was removed" << endl;
		head = head->next;
		return head;
	}
	node *p1 = head, *p2 = NULL;
	while (p1 != NULL) {
		if (value == p1->value) { 
			cout << "Node " << p1->value << " was removed" << endl;
			p2->next = p1->next; 
			delete p1;
			return head;
		}
		else if (p1->next==NULL) { // Value not found
			cout << "Node " << value << " not found" << endl;
			return head; 
		} 
		p2 = p1;
		p1 = p1->next;
	}
}

void print(node *head) {
	node *p = head;
	while (p!=NULL) {
		cout << "Node " << p->value << endl;
		p = p->next;
	};
}
