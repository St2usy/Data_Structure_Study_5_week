#pragma once
#include "DbLinkedList.h"
class LinkedDeque : public DbLinkedList
{
public:
	void addFront(Node2<int>* n) { insert(0, n); }
	Node2<int>* deleteFront() { return remove(0); }
	Node2<int>* getFront() { return getEntry(0); }
	void addRear(Node2<int>* n) { insert(size(), n); } // size 함수를 돌리면 시간복잡도가 O(n)이 된다. 이 문제점을 해결하라 -> 원형이중연결리스트 구현
	Node2<int>* deleteRear() { return remove(size() - 1); }
	Node2<int>* getRear() { return getEntry(size() - 1); }
};