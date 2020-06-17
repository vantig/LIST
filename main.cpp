#include"List.h"
#include"Queue.h"
#include"Stack.h"
int main()
{
	List<int>* list = new Queue<int>;
	list->pushBack (7);
	list->pushBack(8);
	list->pushBack(9);
	list->print();
	std::cout << std::endl;
	std::cout<<list->pop();
	std::cout <<std:: endl;
	std::cout<<list->pop();
	std::cout << std::endl;
	list->print();
	list->pop();
	list->pop();
	list->print();
	system("pause");
	return 0;

}