#pragma once
#include<iostream>
template <class T>
class Node
{
public:
	Node(T _data ,Node* _prev=nullptr );
	~Node();
	T data;
	Node* prev;


};
template <class T>
Node<T>::Node(T _data, Node* _prev) :data(_data), prev(_prev)
{

}
template <class T>
Node<T>::~Node()
{
	
}
template <class T>
class List
{
public:
	List();
	virtual ~List();
	virtual void  pushBack(const T& _element) = 0;
	virtual T pop() = 0;
	virtual void print()const = 0;
	int getSize()const { return size; }

	Node<T>* getTail()const { return tail; }
	void setSize(int _size) { size = _size; }
	void setTail(Node<T>* _tail) { tail = _tail; }

private:
	int size;
	Node<T>* tail;
	
	
};
template <class T>
List<T>::List() :size(0), tail(nullptr)
{

}
template <class T>
List<T>::~List()
{
}