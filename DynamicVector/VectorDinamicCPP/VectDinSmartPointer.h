#pragma once
#define INITIAL_CAPACITY 10
#include <assert.h>
#include "Pet.h"

typedef Pet T;

template<typename T>
class IteratorVectorTudor;

template<typename T>
class VectorDinamic
{
private:
	T* elemente;
	int capacity;
	int length;

	void redim();

public:
	//constructor
	VectorDinamic();

	//copy constructor
	VectorDinamic(const VectorDinamic& other);

	//assignement operator
	VectorDinamic& operator=(const VectorDinamic& other);

	//destructor
	~VectorDinamic();

	void add(T element);
	T& get(int pozitie);
	void setElementOnPozition(T elemet, int pozitie);
	int size(); // get size of vectorDinamic
	void removeElementByPozition(int pozitie);

	friend class IteratorVectorTudor<T>;

	IteratorVectorTudor<T> begin();
	IteratorVectorTudor<T> end();

};

template<typename T>
void VectorDinamic<T>::redim()
{
	int newCapacity = this->capacity * 2;
	T* newElems = new T[newCapacity];
	for (int i = 0; i < this->length; i++)
		newElems[i] = this->elemente[i];
	delete[] this->elemente;
	this->elemente = newElems;
	this->capacity = newCapacity;
}

template<typename T>
VectorDinamic<T>::VectorDinamic()
{
	this->elemente = new T[INITIAL_CAPACITY];
	this->length = 0;
	this->capacity = INITIAL_CAPACITY;
}

template<typename T>
VectorDinamic<T>::VectorDinamic(const VectorDinamic& other)
{
	this->elemente = new T[other.capacity];

	for (int i = 0; i < other.length; i++)
		this->elemente[i] = other.elemente[i];

	this->length = other.length;
	this->capacity = other.capacity;
}

template<typename T>
VectorDinamic<T>& VectorDinamic<T>::operator=(const VectorDinamic& other)
{
	if (this == &other)
		return *this;
	delete[] this->elemente;

	this->elemente = new T[other.capacity];
	for (int i = 0; i < other.length; i++)
		elemente[i] = other.elemente[i];
	this->length = other.length;
	this->capacity = other.capacity;

	return *this;
}

template<typename T>
VectorDinamic<T>::~VectorDinamic()
{
	delete[] this->elemente;
}

template<typename T>
void VectorDinamic<T>::add(T element)
{
	if (this->length == this->capacity)
		redim();
	this->elemente[this->length] = element;
	this->length++;
}

template<typename T>
T& VectorDinamic<T>::get(int pozitie)
{
	return this->elemente[pozitie];
}

template<typename T>
void VectorDinamic<T>::setElementOnPozition(T element, int pozitie)
{
	this->elemente[pozitie] = element;
}

template<typename T>
int VectorDinamic<T>::size()
{
	return this->length;
}

template<typename T>
void VectorDinamic<T>::removeElementByPozition(int pozitie)
{
	for (int i = pozitie; i < this->length - 1; i++)
		elemente[i] = elemente[i + 1];
	this->length--;
}



template<typename T>
class IteratorVectorTudor {
private:

	const VectorDinamic<T>& vectorD;
	int pozitie = 0;

public:

	IteratorVectorTudor(const VectorDinamic<T>& vector) noexcept;
	IteratorVectorTudor(const VectorDinamic<T>& vector, int pozitie) noexcept;
	bool valid() const;
	T& element() const;
	void next() noexcept;
	T& operator*() noexcept;
	IteratorVectorTudor& operator++();
	bool operator==(const IteratorVectorTudor& other) noexcept;
	bool operator!=(const IteratorVectorTudor& other) noexcept;
};




template<typename T>
IteratorVectorTudor<T> VectorDinamic<T>::begin()
{
	return IteratorVectorTudor<T>(*this);
}

template<typename T>
IteratorVectorTudor<T> VectorDinamic<T>::end()
{
	return IteratorVectorTudor<T>(*this, this->length);
}

template<typename T>
IteratorVectorTudor<T>::IteratorVectorTudor(const VectorDinamic<T>& vector) noexcept : vectorD{ vector } { };
template<typename T>
IteratorVectorTudor<T>::IteratorVectorTudor(const VectorDinamic<T>& vector, int pozitie) noexcept : vectorD{ vector }, pozitie{ pozitie } { };

template<typename T>
bool IteratorVectorTudor<T>::valid() const
{
	return this->pozitie < this->vectorD.length;
}

template<typename T>
T& IteratorVectorTudor<T>::element() const
{
	return this->vectorD.elemente[this->pozitie];
}

template<typename T>
void IteratorVectorTudor<T>::next() noexcept
{
	this->pozitie++;
}

template<typename T>
T& IteratorVectorTudor<T>::operator*() noexcept
{
	return this->element();
}

template<typename T>
IteratorVectorTudor<T>& IteratorVectorTudor<T>::operator++()
{
	this->next();
	return *this;
}

template<typename T>
bool IteratorVectorTudor<T>::operator==(const IteratorVectorTudor& other) noexcept
{
	return this->pozitie == other.pozitie;
}

template<typename T>
bool IteratorVectorTudor<T>::operator!=(const IteratorVectorTudor& other) noexcept
{
	return !(*this == other);
}
