#include<iostream>
using namespace std;

class SingleLinkedList {

	class Node {
	public:
		Node* next;
		string data;
		Node(const string& data) {
			this->data = data;
			this->next = nullptr;
		}
	};

	Node* head = nullptr;
public:

	void AddBegin(const string data) {
		Node* node = new Node(data);
		node->next = head;
		head = node;
	};

	void AddEnd(const string& data) {
		Node* node = new Node(data);
		if (head == nullptr) {
			head = node;
			return;
		}
		Node* tail = head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = node;
	};

	void DeleteBegin() {
		if (head == nullptr) { 
			cout << "Empty" << endl;
		}
		else {
			if (head->next == nullptr) {
				delete head;
				head = nullptr;
				return;
			}
			if (head != nullptr && head->next != nullptr) {
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}
	};

	void DeleteEnd() {
		if (head == nullptr) {
			cout << "Empty" << endl;
		}
		else {
			if (head->next == nullptr) {
				delete head;
				head = nullptr;
				return;
			}
			Node* tail = head;
			while (tail->next->next != nullptr) {
				tail = tail->next;
			}
			delete tail->next;
			tail->next = nullptr;
		}
	};

	void DeleteByValue(const string& value) {
		if (head == nullptr) {
			cout << "Empty" << endl;
		}
		else {
			if (head->data == value) {
				Node* temp = head;
				head = head->next;
				delete temp;
			}
			Node* temp2 = head;
			while (temp2->next != nullptr) {
				if (temp2->next->data == value) {
					Node* deleted = temp2->next;
					temp2->next = temp2->next->next;
					delete deleted;
				}
				temp2 = temp2->next;
			}
		}
	};

	void Print() {
		Node* copy_head = head;
		while (copy_head != nullptr) {
			cout << copy_head->data << endl;
			copy_head = copy_head->next;
		}
	}

};

void main() {
	SingleLinkedList list;

	//list.AddBegin("Mahmud");
	//list.AddBegin("Elxan");
	//list.AddBegin("Murad");
	//list.Print();

	list.AddEnd("Mahmud");
	list.AddEnd("Elxan");
	list.AddEnd("Murad");
	list.Print();

	//list.DeleteBegin();
	//cout << "----------------" << endl;
	//list.Print();

	//list.DeleteEnd();
	//cout << "----------------" << endl;
	//list.Print();

	/*string value = "Elxan";
	list.DeleteByValue(value);
	cout << "----------------" << endl;
	list.Print();*/



}
