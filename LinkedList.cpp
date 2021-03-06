// LinkedList.cpp : Defines the entry point for the console application.
//

#include <iostream>
template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};
template <class T>
class LinkedList
{
private:
	Node<T>* head;
	void reverseRecursiveP(Node<T>* curr)
	{
	    if(curr == nullptr)
	    {
	        return;
	    }
	    else if(curr->next == nullptr)
	    {
	        head = curr;
	    }
	    else
	    {
	        reverseRecursiveP(curr->next);
	        curr->next->next=curr;
	        curr->next = nullptr;
	    }
	}
public:
	LinkedList() :head(nullptr) {}
	void add(T data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node<T>* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;

		}
	}
	void print()
	{
		Node<T> *temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	bool deleteNode(T data)
	{
		bool ret = true;
		Node<T>* prev = nullptr;
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == data)
			{
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			std::cout << "Node with data " << data << " is not present in linked list" << std::endl;
			ret = false;
			return ret;
		}
		else
		{
			if (prev != nullptr)
			{
				prev->next = temp->next;
			}
			else if (temp == head)
			{
				head = temp->next;
			}
			delete temp;
		}
		return ret;
	}
	void reverse()
	{
		Node<T>* previous = nullptr;
		Node<T>* current = head;
		Node<T>* next = nullptr;
		while (current != nullptr)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		head = previous;
	}
	void reverseRecursive()
	{
	    reverseRecursiveP(head);
	}
	LinkedList<T> deepCopy()
	{
		LinkedList<T> newlist;
		Node<T>* temp = head;
		Node<T>* previous = nullptr;
		while (temp != nullptr)
		{
			Node<T>* newNode = new Node<T>();
			newNode->data = temp->data;
			newNode->next = nullptr;
			if (previous != nullptr)
			{
				previous->next = newNode;
			}
			else
			{
				newlist.head = newNode;
			}
			previous = newNode;
			temp = temp->next;
		}
		return newlist;
	}
};
int main() {
	std::cout << "Hello World!\n";
	LinkedList<int> mylist;
	mylist.add(4);
	mylist.add(6);
	mylist.add(8);
	mylist.add(1);
	mylist.add(3);
	mylist.add(5);
	mylist.print();
	mylist.deleteNode(8);
	mylist.print();
  //  mylist.reverse();
    mylist.reverseRecursive();
	mylist.print();
//	LinkedList<int> newlist = mylist.deepCopy();
//	std::cout << "printing new list" << std::endl;
//	newlist.print();
	return 0;
}