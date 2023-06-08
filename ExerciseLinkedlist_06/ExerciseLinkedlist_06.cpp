#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int Bayhaqi;
	string abi;
	Node* next;
	Node* prev;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int roollNo, Node** previous, Node** current);
	bool listEmpty();
	bool delNode(int roollNo);
	void traverse();
	void hapus();
};

void CircularLinkedList::addNode() { //write your answer here
	int name;
	string panggilan;
	cout << "\nEnter the name: ";
	cin >> name;
	cout << "\nEnter the nickname: ";
	cin >> panggilan;
	Node* newNode = new Node();
	newNode->Bayhaqi = name;
	newNode->abi = panggilan;

	if (LAST == NULL || name <= LAST->Bayhaqi) {
		if (LAST != NULL && name == LAST->Bayhaqi) {
			cout << "\nDuplicate name not allowed" << endl;
			return;
		}
		newNode->next = LAST; 
		if (LAST != NULL)
			LAST->prev = newNode;	
		newNode->prev = NULL;	
		LAST = newNode;	
		return;
	}

	Node* current = LAST;	
	Node* previous = NULL;	
	while (current->next != NULL && current->next->Bayhaqi < name)	
	{
		previous = current;	
		current = current->next;
	}

	if (current->next != NULL && name == current->next->Bayhaqi) {
		cout << "\nDuplicate name no allowed" << endl;
		return;
	}

	newNode->next = current->next;	
	newNode->prev = current;	
	if (current->next != NULL)
		current->next->prev = newNode;	
	current->next = newNode;
}

bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST && rollno !=(*current)->Bayhaqi) {
		if (rollno == (*current)->Bayhaqi) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->Bayhaqi) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode(int rollNo) { //write your answer here
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL) 
		current->next->prev = previous;	
	if (previous != NULL) 
		previous->next = current->next;	
	else
		LAST = current->next;

	delete current;
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->Bayhaqi << " " << currentNode->abi << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->Bayhaqi << " " << LAST->abi << endl;
	}
}

void CircularLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (CircularLinkedList::delNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << " deleted " << endl;

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-4): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': 
				obj.addNode();
				break;
			case '2': 
				obj.hapus();
				break;
			case '3': 
				obj.traverse();
				break;
			case '4': 
				return 0;
			default: {
				cout << "Invalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}