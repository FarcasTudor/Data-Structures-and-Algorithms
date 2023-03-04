#include "IteratorColectie.h"
#include "Colectie.h"
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <exception>

using namespace std;

IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	curent = c.prim;
}

void IteratorColectie::prim() {
	curent = col.prim;
}


void IteratorColectie::urmator() {
	/* 
	functie pe iterator ce pointeaza spre urmatorul element din colectie
	Complexitate: 
	*/
	if (curent->frecventa() > 1)
	{
		curent->modifica_frecventa();
		curent->mareste_indicator();
	}
	else 
		if (curent->frecventa() == 1)
		{
			curent->mareste_indicator();
			curent->save_frecventa();
			if (curent->urmator() != nullptr)
			{
				curent = curent->urmator();
				curent->initializeaza_indicator();
			}
			else
				curent = nullptr;
		}
	
}

bool IteratorColectie::valid() const {
	return curent != nullptr;
}

TElem IteratorColectie::element() const {
	return curent->element();
}

TElem IteratorColectie::frecventa() const
{
	return curent->frecventa();
}
