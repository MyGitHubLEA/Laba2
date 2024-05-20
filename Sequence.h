#pragma once
#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"

template <typename T> class Sequence {
public:

	virtual T GetFirst() const = 0;
	virtual T GetLast() const = 0;
	virtual T Get(int index) const = 0;
	virtual int GetLength() const = 0;

	virtual Sequence<T>* GetSubsequence(int start, int end) const = 0; 

	virtual void Set(const T& item, int index) = 0;
	virtual void Append(const T& item) = 0;
	virtual void Prepend(const T& item) = 0;
	virtual void InsertAt(const T& item, int index) = 0;

	virtual Sequence<T>* Concat(const Sequence<T>* seq) const = 0;
	virtual void Print() const = 0;
};


template <typename T> class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* array;
public:

	ArraySequence() {
		this->array = new DynamicArray<T>(0);
	}

	ArraySequence(const ArraySequence<T>& seq) {
		this->array = new DynamicArray<T>(*seq.array);
	}

	ArraySequence(T* items, int size)
	{
		this->array = new DynamicArray<T>(items, size);
	}

	~ArraySequence()
	{
		delete this->array;
	}

	T GetFirst() const override
	{
		if (this->GetLength() == 0) throw std::out_of_range("Sequence is empty\n");
		return this->array->Get(0);
	}

	T GetLast() const override
	{
		if (this->GetLength() == 0) throw std::out_of_range("Sequence is empty\n");
		return this->array->Get(this->GetLength() - 1);
	}

	T Get(int index) const override
	{
		if (index < 0 || index >= this->GetLength()) 
			throw std::out_of_range("IndexOutOfRange\n");
		return this->array->Get(index);
	}

	int GetLength() const override {
		return this->array->GetLength();
	}

	void Set(const T& item, int index) override
	{
		if (index < 1 || index > this->GetLength())
			throw std::out_of_range("IndexOutOfRange\n");
		this->array->Set(item, index - 1);
	}

	ArraySequence<T>* GetSubsequence(int start, int end) const override //1 - 2
	{
		if (start < 1 || start > this->GetLength() || start > end || end > this->GetLength())
			throw std::out_of_range("IndexOutOfRange\n");
		int sizeArray = end - start + 1; //2
		ArraySequence<T>* subSequence = new ArraySequence<T>();
		subSequence->array->Resize(sizeArray);
		for (int i = 0; i < sizeArray; i++) 
			subSequence->Set(this->Get(i + start - 1), i + 1);
		return subSequence;
	}

	void Append(const T& item) override
	{
		this->array->Resize(this->GetLength() + 1);
		this->array->Set(item, this->GetLength() - 1);
	}

	void Prepend(const T& item) override
	{
		T t1;
		int Len = this->GetLength();
		this->array->Resize(this->GetLength() + 1);
		for (int i = 0; i < Len; i++)
		{
			t1 = this->array->Get(Len - (i + 1));
			this->array->Set(t1, Len - i);
		}
		this->array->Set(item, 0);
	}

	void InsertAt(const T& item, int index) override
	{
		if (index < 1 || index > this->GetLength()) throw std::out_of_range("IndexOutOfRange\n");
		--index;
		int Len = this->GetLength(); // = 4, in = 1
		this->array->Resize(this->GetLength() + 1);
		T t1;
		for (int i = Len; i >= index; --i)
		{
			t1 = this->array->Get(i);
			this->array->Set(t1, i + 1);
		}
		this->array->Set(item, index);
	}

	ArraySequence<T>* Concat(const Sequence<T>* seq) const override
	{
		ArraySequence<T>* newArray = new ArraySequence<T>(*this);
		for (int i = 0; i < seq->GetLength(); ++i)
			newArray->Append(seq->Get(i));
		return newArray;
	}

	void Print() const override
	{
		for (int i = 0; i < this->GetLength(); i++)
			std::cout << this->Get(i);
		printf("\n");
	}
};


template <typename T> class ListSequence : public Sequence<T> {
private:
	LinkedList<T>* list;
public:
	ListSequence() {
		this->list = new LinkedList<T>();
	}
	ListSequence(const ListSequence<T>& seq) {
		this->list = new LinkedList<T>(*seq.list);
	}

	ListSequence(T* items, int size) {
		this->list = new LinkedList<T>(items, size);
	}

	virtual ~ListSequence() {
		delete this->list;
	}

	T GetFirst() const override 
	{
		if (this->GetLength() == 0) throw std::out_of_range("Sequence is empty\n");
		return this->list->GetFirst();
	}

	T GetLast() const override 
	{
		if (this->GetLength() == 0) throw std::out_of_range("Sequence is empty\n");
		return this->list->GetLast();
	}

	T Get(int index) const override 
	{
		if (index < 0 || index > this->GetLength())
			throw std::out_of_range("IndexOutOfRange\n");
		return this->list->Get(index);
	}

	int GetLength() const override {
		return this->list->GetLength();
	}

	ListSequence<T>* GetSubsequence(int start, int end) const override 
	{
		if (start < 1 || start > this->GetLength() || start > end || end > this->GetLength()) 
			throw std::out_of_range("IndexOutOfRange\n");
		ListSequence<T>* subList = new ListSequence<T>();
		subList->list = this->list->GetSubList(start, end);
		return subList;
	}

	void Set(const T& item, int index) override
	{
		this->list->Set(item, index);
	}

	void Append(const T& item) override
	{
		this->list->Append(item);
	}

	void Prepend(const T& item) override
	{
		this->list->Prepend(item);
	}

	void InsertAt(const T& item, int index) override
	{
		if (index < 1 || index > this->GetLength())
			throw std::out_of_range("IndexOutOfRange\n");
		this->list->InsertAt(item, index);
	}
	ListSequence<T>* Concat(const Sequence<T>* seq) const override
	{
		ListSequence<T>* newList = new ListSequence<T>(*this);
		for (int i = 0; i < seq->GetLength(); ++i)
			newList->list->Append(seq->Get(i+1));
		return newList;
	}

	void Print() const override
	{
		this->list->Print();
	}
};

