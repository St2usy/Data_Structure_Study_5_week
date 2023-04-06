#pragma once
#include<iostream>
#define MAX_LIST_SIZE 100

class ArrayList {
	int data[MAX_LIST_SIZE];
	int length;
public:
	ArrayList() { length = 0; }

	void insert(int pos, int e) {}

	void remove(int pos) {}

	int getEntry(int pos) { return data[pos]; }
	bool isEmpty() { return length == 0; }
	bool isFull() { return length == MAX_LIST_SIZE; }
	bool find(int item) {
		for (int i = 0; i < length; i++) 
			if (data[i] == item) return true;
		return false;
	}
	void replace(int pos, int e) {
		data[pos] = e;
	}
	int size() { return length; }
	void clear() { length = 0; }
};