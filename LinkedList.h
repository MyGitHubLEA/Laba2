#pragma once
#include <stdexcept>
#include <string>
#include <iostream>

template <typename T>
class LinkedList 
{
public: 
	LinkedList(T* items, int size)
	{
		this->ListSize = size;
		this->FirstNode = new Node<T> (items[0]);
		Node <T>* current = this->FirstNode;
		for (int i = 1; i < size; ++i) //ïóñòü ðàçìåð 3, 
		{
			Node<T>* ptr = new Node <T>(items[i]);
			current->NextElemPtr = ptr;
			current = ptr;
		}
	}

	T GetFirst()
	{
		if (this->GetLength() == 0) throw std::out_of_range("List is empty\n");
		return this->FirstNode->Data;
	}

	LinkedList<T>* GetSubList(int startIndex, int endIndex) 
	{
		if (startIndex < 1 || endIndex > this->GetLength()) 
			throw std::out_of_range("Indexes are out of range\n");
		++endIndex;
		LinkedList* newList = new LinkedList<T>();
		for (int i = startIndex; i < endIndex; ++i) //ïóñòü ðàçìåð 3, 
			newList->Append(this->Get(i));
		return newList;
	}

	void Print()
	{
		Node <T>* current = this->FirstNode;
		for (int i = 0; i < this->ListSize; ++i) //ïóñòü ðàçìåð 3, 
		{
			std::cout << current->Data;
			current = current->NextElemPtr;
		}
		printf("\n");
	}

	T GetLast()
	{
		if (this->GetLength() == 0) throw std::out_of_range("List is empty\n");
		Node <T>* current = this->FirstNode;
		while (current->NextElemPtr != nullptr) 
		{
			current = current->NextElemPtr;
		}
		return current->Data;
	}

	LinkedList() 
	{
		this->ListSize = 0;
		this->FirstNode = nullptr;
	}

	T Get(int index)
	{
		if (index < 0 || index > this->GetLength())
			throw std::out_of_range("Index is out of range\n");
		Node <T>* current = this->FirstNode;
		for (int i = 1; i < index; ++i) 
		{
			current = current->NextElemPtr;
		}
		return current->Data;
	}

	int GetLength()
	{
		return this->ListSize;
	}



	void Append(T item)
	{
		Node <T>* current = this->FirstNode;
		if (current == nullptr)
		{
			this->FirstNode = new Node<T>(item);
		}
		else {
			while (current->NextElemPtr != nullptr)
			{
				current = current->NextElemPtr;
			}
			current->NextElemPtr = new Node<T>(item);
		}
		(this->ListSize)++;
	}

	void Prepend(T item)
	{
		Node<T>* NewFirstElem = new Node<T>(item, this->FirstNode);
		this->FirstNode = NewFirstElem;
		(this->ListSize)++;
	}

	void InsertAt(T item, int index) 
	{
		if (index < 1 || index > this->GetLength()) 
			throw std::out_of_range("Index is out of range\n");
		--index;
		Node <T>* current = this->FirstNode;
		Node<T>* NewElem = new Node<T>(item);
		for (int i = 1; i < index; ++i)
		{
			current = current->NextElemPtr;
		}
		NewElem->NextElemPtr = current->NextElemPtr;
		current->NextElemPtr = NewElem;
		this->ListSize++;
	}

	LinkedList(const LinkedList<T>& other) {
		this->ListSize = other.ListSize;
		this->FirstNode = new Node<T>(other.FirstNode->Data);
		Node<T>* current = this->FirstNode;
		Node<T>* otherCurrent = other.FirstNode->NextElemPtr;
		while (otherCurrent != nullptr) {
			current->NextElemPtr = new Node<T>(otherCurrent->Data);
			current = current->NextElemPtr;
			otherCurrent = otherCurrent->NextElemPtr;
		}
	}
	
	LinkedList<T>* Concat(LinkedList<T>* list)
	{
		LinkedList<T>* newList = new LinkedList<T>(*this);
		Node <T>* current = new Node<T>;
		current = list->FirstNode;
		for (int i = 0; i < list->GetLength(); ++i)
		{
			newList->Append(current->Data);
			current = current->NextElemPtr;
		}
		return newList;
	}

	~LinkedList()
	{
		while (ListSize)
		{
			Node<T>* temp = FirstNode;
			FirstNode = FirstNode->NextElemPtr;
			delete temp;
			ListSize--;
		}
	}

	void Set(const T& item, int index)
	{
		Node<T>* current = this->FirstNode;
		for (int i = 1; i < index; ++i)
			current = current->NextElemPtr;
		current->Data = item;
	}

private:
	template <typename T>
	class Node
	{
	public:
		Node<T>* NextElemPtr;
		T Data;
		Node(T data = T(), Node* Nptr = nullptr)
		{
			this->NextElemPtr = Nptr;
			this->Data = data;
		}
	};
	Node <T>* FirstNode;
	int ListSize;
};
