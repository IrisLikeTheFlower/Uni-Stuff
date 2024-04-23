#include <iostream>
#include <assert.h>
#include <stack>

class customNode {
public:
	int data;
	customNode* link;
	customNode(int d) {
		this->data = d;
		this->link = nullptr;
	}
};

class customStack {
private:
	customNode* top;
public:
	customStack() { top = nullptr; }
	
	void push(int data);
	int peek();
	void pop();
	bool isEmpty();
};

void TestsOnCustomStack() {
	customStack Stack;

	assert(Stack.isEmpty() == true);

	Stack.push(120);
	assert(Stack.peek() == 120);
	assert(Stack.isEmpty() == false);

	Stack.push(125);
	Stack.push(25);
	assert(Stack.peek() == 25);

	Stack.push(5);
	assert(Stack.peek() == 5);

	Stack.pop();
	assert(Stack.peek() == 25);

	Stack.pop();
	assert(Stack.peek() == 125);
	assert(Stack.isEmpty() == false);

	Stack.pop();
	Stack.pop();
	assert(Stack.isEmpty() == true);
}

int main() {
	TestsOnCustomStack();

	customStack cs;
	cs.push(10);
	cs.push(20);
	cs.push(30);
	cs.push(40);

	std::cout << "Custom stack elements: ";
	while (!cs.isEmpty()) {
		std::cout << cs.peek();
		cs.pop();
		if (!cs.isEmpty()) {
			std::cout << " --> ";
		}
	}
	std::cout << "\n\n\n";


	std::stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	std::cout << "Stack elements: ";
	while (!s.empty()) {
		std::cout << s.top();
		s.pop();
		if (!s.empty())
			std::cout << " --> ";
	}
	std::cout << '\n';

	return 0;
}

void customStack::push(int data)
{
	customNode* temp = new customNode(data);

	if (!temp) {
		std::cout << "\n\nStack Overflow\n";
		exit(1);
	}
	temp->data = data;
	temp->link = top;
	top = temp;
}

int customStack::peek()
{
	if (!isEmpty()) {
		return top->data;
	}
	else {
		exit(2);
	}
}

void customStack::pop()
{
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

bool customStack::isEmpty()
{
	return top == nullptr;
}
