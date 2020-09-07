#ifndef Stack_HPP
#define Stack_HPP
#include <iostream>
using namespace std;
class Stack
{
public:
	Stack();
	void stackelemanEkle(char);
	void stackYaz();
	void reserve(int);
	~Stack();
private:
	char *data;
	int top = 0;
	int capacity;
};
#endif