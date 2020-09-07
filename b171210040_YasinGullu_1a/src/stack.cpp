#include "stack.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>

	Stack::Stack()
	{
		data = NULL;
		top=-1;
		capacity = 0;
	}
	void Stack::reserve(int newCapacity)
	{
		char *tmp = new char[newCapacity];
		
		for(int i = 0; i < (top + 1); i++)
		{
			tmp[i] = data[i];
		}
		if(data != NULL) delete [] data;
		data = tmp;
		capacity = newCapacity;
	}
	void Stack::stackelemanEkle(char harf)
	{
		if((top + 1) == capacity)
			reserve(max(1,2*capacity));
		data[++top] = harf;
	}
	void Stack::stackYaz()
	{
		for (int i = top; i >= 0; i--)
		{
			cout<< data[i] ;
		}
	}
	Stack::~Stack()
	{
		delete data;
	}