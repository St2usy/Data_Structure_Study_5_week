#pragma once
#include "DbLinkedList.h"
class LinkedDeque : public DbLinkedList
{
public:
	void addFront(Node2<int>* n) { insert(0, n); }
	Node2<int>* deleteFront() { return remove(0); }
	Node2<int>* getFront() { return getEntry(0); }
	void addRear(Node2<int>* n) { insert(size(), n); } // size �Լ��� ������ �ð����⵵�� O(n)�� �ȴ�. �� �������� �ذ��϶� -> �������߿��Ḯ��Ʈ ����
	Node2<int>* deleteRear() { return remove(size() - 1); }
	Node2<int>* getRear() { return getEntry(size() - 1); }
};