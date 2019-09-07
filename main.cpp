#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct Node {
	int data;
	struct Node* piror, * next;
} Node;

class List
{
public:
	List();
	~List();
	void creatList();
	void printData();
	void insertData();
	void deleteData();
	void listReserve();
	void createCircutList();
	void printCircutList();
	void insertCircutListData();
	void deletdCircutListData();
	void createCircurtSignalList();
	void printCircurtSignalList();
	void insetrCircurtSignalList();
	void deleteCircurtSignalList();
	void reserveCircurtSignalList();
	void display();
	void allFunction(int choice);
private:
	Node* Head;
};

List::List()
{
}

List::~List()
{
}

void List::creatList() {
	Node* head = new Node;
	Node* p = new Node, * q = head;
	int data;
	while (cin >> data && data != -65535) {
		p->data = data;
		q->next = p;
		q = p;
		p = new Node;
	}
	delete p;
	Head = head;
	q->next = NULL;
	cout << "创建成功" << endl;
}

void List::printData() {
	for (auto it = Head->next; it != NULL; it = it->next) {
		cout << it->data << " ";
	}
	putchar(10);
}

void List::insertData() {
	int data, pos;
	cout << "请输入数据和插入位置:";
	cin >> data >> pos;
	if (data != -65535) {
		Node* temp = Head;
		for (int i = 0; i < pos - 1 && temp->next; i++, temp = temp->next);
		Node* p = new Node;
		p->data = data;
		p->next = temp->next;
		temp->next = p;
		cout << "插入成功" << endl;
	}
	else cout << "插入失败" << endl;
}

void List::deleteData() {
	int pos;
	cout << "请输入删除位置:";
	cin >> pos;
	Node* temp = Head;
	for (int i = 0; i < pos - 1 && temp->next; i++, temp = temp->next);
	if (temp->next) {
		Node* p = temp->next;
		temp->next = p->next;
		delete p;
		cout << "删除成功" << endl;
	}
	else cout << "没有该位置" << endl;
}

void List::listReserve() {
	Node* p, * q, * s;
	p = Head->next;
	bool flag = false;
	for (q = p->next, s = q->next; s->next; p = q, q = s, s = s->next) {
		q->next = p;
		if (!flag) {
			p->next = NULL;
			flag = true;
		}
	}
	q->next = p;
	s->next = q;
	Head->next = s;
	cout << "逆置成功" << endl;
}

void List::createCircutList() {
	Node* head = new Node;
	Node* p = new Node, * q = head;
	int data;
	while (cin >> data && data != -65535) {
		p->data = data;
		q->next = p;
		p->piror = q;
		q = p;
		p = new Node;
	}
	delete p;
	head->piror = q;
	q->next = head;
	Head = head;
	cout << "创建成功" << endl;
}

void List::printCircutList() {
	for (auto it = Head->next; it != Head; it = it->next) {
		cout << it->data << " ";
	}
	putchar(10);
	for (auto it = Head->piror; it != Head; it = it->piror) {
		cout << it->data << " ";
	}
	putchar(10);
}

void List::insertCircutListData() {
	int data, pos;
	cout << "请输入数据和插入位置:";
	cin >> data >> pos;
	if (data != -65535) {
		Node* temp = Head;
		for (int i = 0; i < pos - 1 && temp->next; i++, temp = temp->next);
		Node* p = new Node;
		p->data = data;
		p->next = temp->next;
		temp->next->piror = p;
		p->piror = temp;
		temp->next = p;
		cout << "插入成功" << endl;
	}
	else cout << "插入失败" << endl;
}

void List::deletdCircutListData() {
	int pos;
	cout << "请输入删除位置:";
	cin >> pos;
	Node* temp = Head;
	for (int i = 0; i < pos - 1 && temp->next; i++, temp = temp->next);
	if (temp->next) {
		Node* p = temp->next;
		temp->next = p->next;
		p->next->piror = temp;
		delete p;
		cout << "删除成功" << endl;
	}
	else cout << "没有该位置" << endl;
}

void List::createCircurtSignalList() {
	Node* head = new Node;
	Node* p = new Node, * q = head;
	int data;
	while (cin >> data && data != -65535) {
		p->data = data;
		q->next = p;
		q = p;
		p = new Node;
	}
	delete p;
	q->next = head;
	Head = head;
	cout << "创建成功" << endl;
}

void List::printCircurtSignalList() {
	for (auto it = Head->next; it != Head; it = it->next) {
		cout << it->data << " ";
	}
	putchar(10);
}

void List::insetrCircurtSignalList() {
	int data, pos;
	cout << "请输入数据和插入位置:";
	cin >> data >> pos;
	if (data != -65535) {
		Node* temp = Head;
		for (int i = 0; i < pos - 1 && temp->next; i++, temp = temp->next);
		Node* p = new Node;
		p->data = data;
		p->next = temp->next;
		temp->next = p;
		cout << "插入成功" << endl;
	}
	else cout << "插入失败" << endl;
}

void List::deleteCircurtSignalList() {
	int pos;
	cout << "请输入删除位置:";
	cin >> pos;
	Node* temp = Head;
	for (int i = 0; i < pos - 1 && temp->next; i++, temp = temp->next);
	if (temp->next) {
		Node* p = temp->next;
		temp->next = p->next;
		delete p;
		cout << "删除成功" << endl;
	}
	else cout << "没有该位置" << endl;
}

void List::reserveCircurtSignalList() {
	Node* p, * q, * s;
	p = Head->next;
	Head->next = NULL;
	bool flag = false;
	for (q = p->next, s = q->next; s->next != Head; p = q, q = s, s = s->next) {
		if (!flag) {
			p->next = Head;
			flag = true;
		}
		q->next = p;
	}
	q->next = p;
	s->next = q;
	Head->next = s;
	cout << "逆置成功" << endl;
}

void List::display() {
	cout << "请选择功能" << endl
		<< "1.创建链表" << endl
		<< "2.输出链表" << endl
		<< "3.插入数据" << endl
		<< "4.删除数据" << endl
		<< "5.链表逆置,双向链表没有逆置" << endl << endl << endl;
}

void List::allFunction(int choice) {
	int Choice;
	this->display();
	switch (choice) {
	case 1:
		cin >> Choice;
		switch (Choice) {
		case 1:
			this->creatList();
			break;
		case 2:
			this->printData();
			break;
		case 3:
			this->insertData();
			break;
		case 4:
			this->deleteData();
			break;
		case 5:
			this->listReserve();
			break;
		}
		break;
	case 2:
		cin >> Choice;
		switch (Choice) {
		case 1:
			this->createCircutList();
			break;
		case 2:
			this->printCircutList();
			break;
		case 3:
			this->insertCircutListData();
			break;
		case 4:
			this->deletdCircutListData();
			break;
		case 5:
			cout << "双向链表不需要逆置" << endl;
		}

		break;
	case 3:
		cin >> Choice;
		switch (Choice) {
		case 1:
			this->createCircurtSignalList();
			break;
		case 2:
			this->printCircurtSignalList();
			break;
		case 3:
			this->insetrCircurtSignalList();
			break;
		case 4:
			this->deleteCircurtSignalList();
			break;
		case 5:
			this->reserveCircurtSignalList();
			break;
		}
		break;
	}
}

int main() {
	List L;
	int choice;
	cout << "请选择操作" << endl << "1.单链表     2.循环双链表     3.循环单链表" << endl;
	cin >> choice;
	while (true) {
		L.allFunction(choice);
	}
	return 0;
}