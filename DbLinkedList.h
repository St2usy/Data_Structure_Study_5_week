#pragma once
#include "Node2.h"
class DbLinkedList {
	Node2<int> org;
public:
	DbLinkedList()
		: org(0) {}
	~DbLinkedList() { while (!isEmpty()) delete remove(0); }
	Node2<int>* getHead() { return org.getNext(); }
	bool isEmpty() { return getHead() == NULL; }

	Node2<int>* getEntry(int pos) {
		Node2<int>* n = &org;
		for (int i = -1; i < pos; i++, n = n->getNext())
			if (n == NULL) break;
		return n;
	}
	void insert(int pos, Node2<int>* n) {
		Node2<int>* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}
	Node2<int>* remove(int pos) {
		Node2<int>* n = getEntry(pos);
		return n->remove();
	}
	Node2<int>* find(int val) {
		for (Node2<int>* p = getHead(); p != NULL; p = p->getNext())
			if (p->hasdata(val)) return p;
		return NULL;
	}
	void replace(int pos, Node2<int>* n) {
		Node2<int>* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
	}
	int size() {
		int count = 0;
		for (Node2<int>* p = getHead(); p != NULL; p = p->getNext())
			count++;
		return count;
	}
	void display() {
		std::cout << "[이중연결리스트 항목 수 = " << size() << "] : ";
		for (Node2<int>* p = getHead(); p != NULL; p = p->getNext())
			p->display();
		std::cout << std::endl;
	}
	void clear() { while (!isEmpty()) delete remove(0); }
};