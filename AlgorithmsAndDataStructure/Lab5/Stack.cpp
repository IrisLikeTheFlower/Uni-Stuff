#pragma once
#include <string>

template <typename T> class Stack
{
public:
	struct customNode
	{
		T data;
		customNode* link;
		customNode(T data) { this->data = data; this->link = nullptr; }
	};
private:
	customNode* top;
public:
	Stack() { top = nullptr; }

	void push(T data) {
		customNode* temp = new customNode(data);

		if (!temp) {
			std::cout << "\n\nStack Overflow\n";
			exit(1);
		}
		temp->data = data;
		temp->link = top;
		top = temp;
	}
	T peek(){
		if (!isEmpty()) {
			return top->data;
		}
		else {
			exit(2);
		}
	}
	void pop() {
		customNode* temp;
		if (top == nullptr) {
			std::cout << "\n\nStack Underflow\n";
			exit(3);
		}
		else {
			temp = top;
			top = temp->link;
			delete[] temp;
		}
	}
	bool isEmpty() {
		return top == nullptr;
	}
};
