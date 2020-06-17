
#pragma once
#include"List.h"

template<class T>
class Stack:public List<T>
{
public:
	Stack();
	~Stack();
	 void  pushBack(const T& _element) ;
	 T pop();
	 void print()const ;


};
template<class T>
Stack<T>::Stack() :List<T>()
{
}
template<class T>
Stack<T>::~Stack()
{
	while (List<T>::getSize())
	{
		pop();
	}
}
template<class T>
void Stack<T>::pushBack(const T& _element)
{
	Node<T>* newNode = new Node<T>(_element, List<T>::getTail());
	List<T>::setTail(newNode);
	List<T>::setSize(List<T>::getSize() + 1);

}
template<class T>
T Stack<T>::pop()
{
	if (List<T>::getSize()!=0)
	{
		Node<T>* temp = List<T>::getTail();
		T key = temp->data;
		List<T>::setTail(temp->prev)  ;
		List<T>::setSize(List<T>::getSize() - 1);
		delete temp;
		return key;
	}
	else
	{
		std::cout << "Steck is empty\n ";
		return T();
	}
}
template<class T>
void Stack<T>::print()const
{
	for (Node<T>* i = List<T>::getTail(); i!=nullptr; i=i->prev)
	{
		std::cout << i->data << " ";
	}
	std::cout << std::endl;
}