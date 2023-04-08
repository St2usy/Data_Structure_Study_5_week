#pragma once
#include<iostream>
#define MAX_LIST_SIZE 100

template <typename T>
class ArrayList {
	T data[MAX_LIST_SIZE];
	int length;
public:
	ArrayList() { length = 0; }

	void insert(int pos, T e) {
		if (!isFull() && pos >= 0 && pos <= length) {
			for (int i = length; i > pos; i--)
				data[i] = data[i - 1];
			data[pos] = e;
			length++;
		}
		else error("포화상태 오류, 삽입상태 오류");

	}

	void remove(int pos) {
		if (!isEmpty() && pos >= 0 && pos < length) {
			for (int i = pos + 1; i < length; i++)
				data[i - 1] = data[i];
			length--;
		}
		else error("공백상태 오류, 삭제위치 오류");
	}

	T operator[](int pos) { return data[pos]; }
	bool isEmpty() { return length == 0; }
	bool isFull() { return length == MAX_LIST_SIZE; }
	bool find(T item) {
		for (int i = 0; i < length; i++) 
			if (data[i] == item) return true;
		return false;
	}
	void replace(int pos, T e) {
		data[pos] = e;
	}
	int size() { return length; }
	void clear() { length = 0; }
	void swap(int i, int j) {
		T temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
	void display() {
		for (int i = 0; i < size(); i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

template <typename Cont> // 템플릿 버블정렬
void bubble_sort(Cont& cont) {
	for (int i = 0; i < cont.size(); i++) {
		for (int j = i + 1; j < cont.size(); j++) {
			if (cont[i] > cont[j]) {
				cont.swap(i, j);
			}
		}
	}
}

template <typename Cont, typename Comp> // 템플릿 + 함수객체를 활용한 버블정렬 - > 함수객체는 함수는 아니지만 함수 역할을 하는 객체를 의미함
void bubble_sort(Cont& cont, Comp& comp) {
	for (int i = 0; i < cont.size(); i++) {
		for (int j = i + 1; j < cont.size(); j++) {
			if (!comp(cont[i],cont[j])) {
				cont.swap(i, j);
			}
		}
	}
}

struct Comp1 {
	bool operator()(int a, int b) { return a > b; } // 내림차순
};

struct Comp2 {
	bool operator()(int a, int b) { return a < b; } // 오름차순
};