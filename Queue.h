#pragma once
#include"List.h"
template <class T>
class Queue :public List<T>
{
public:
	Queue();
	~Queue();
	void  pushBack(const T& _element);
	T pop();
	void print()const;

private:
	void print(Node<T>*prev)const;
	Node<T>* prevHeadSearch();
	Node<T>* head;
};
template <class T>
void  Queue<T>::print(Node<T>* _prev)const
{
	if (_prev->prev!=nullptr)
	{
		print(_prev->prev);
		std::cout << _prev->data<<" ";

	}
	else
	{
		std::cout << _prev->data << " ";
		return;
	}
}
template <class T>

Node<T>* Queue<T>::prevHeadSearch()
{
	Node<T>* temp;
	for (temp = List<T>::getTail(); temp->prev != head; temp = temp->prev);
		return temp;
}
template <class T>
Queue<T>::Queue() :List<T>(),head(nullptr)
{

}
template <class T>
Queue<T>::~Queue()
{
	while (List<T>::getSize())
	{
		pop();
	}
}
template <class T>
void Queue<T>::pushBack(const T& _element)
{
	Node<T>* newNode = new Node<T>(_element, List<T>::getTail());
	if (List<T>::getSize()==0)
	{
		List<T>::setTail(newNode);
		head = List<T>::getTail();

	}
	else
	{
		List<T>::setTail(newNode);
	
	}
	List<T>::setSize(List<T>::getSize() + 1);
	
}
template <class T>
T Queue<T>::pop()
{
	if (List<T>::getSize() >1)
	{
		Node<T>* temp = head;
		T key = temp->data;

		head=prevHeadSearch();
		delete temp;
		head->prev = nullptr;
		List<T>::setSize(List<T>::getSize() - 1);
		
		return key;
	}
	else if (List<T>::getSize() == 1)
	{
		Node<T>* temp = head;
		T key = temp->data;
		
		List<T>::setSize(List<T>::getSize() - 1);
		List<T>::setTail(nullptr);
		 head = List<T>::getTail();
		delete temp;
		return key;
	}
	else
	{
		std::cout << "Queue is empty\n ";
		return T();
	}
}
template <class T>
void Queue<T>::print()const
{
	if (List<T>::getTail())
	{
		print(List<T>::getTail());
	}
	return;
}
