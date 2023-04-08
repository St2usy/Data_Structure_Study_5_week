#include "DbLinkedList.h"
void main() {
	DbLinkedList list;
	list.insert(0, new Node2<int>(10));
	list.insert(0, new Node2<int>(20));
	list.insert(1, new Node2<int>(30));
	list.insert(list.size(), new Node2<int>(40));
	list.insert(2, new Node2<int>(50));
	list.display();
	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, new Node2<int>(90));
	list.display();
	list.clear();
	list.display();
}