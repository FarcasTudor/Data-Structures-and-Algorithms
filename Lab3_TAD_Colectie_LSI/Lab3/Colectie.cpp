#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

Nod::Nod(TElem element, TElem frecventa, PointerNod urm) {
	this->frecv = frecventa;
	this->elem = element;
	this->ind = 0;
	this->urm = urm;
}

TElem Nod::element()
{
	return elem;
}

TElem Nod::frecventa()
{
	return frecv;
}

TElem Nod::indicator() {
	return ind;
}

PointerNod Nod::urmator() {
	return urm;
}

TElem Nod::modifica_frecventa()
{
	if (frecv == 1)
		frecv = 0;
	else
		frecv = frecv - 1;
	return frecv;
}

TElem Nod::save_frecventa(){
	frecv = ind;
	return frecv;
}

TElem Nod::mareste_indicator() {
	ind++;
	return ind;
}

TElem Nod::initializeaza_indicator() {
	ind = 0;
	return ind;
}


//~~~~~~~~Colectie~~~~~~~~

Colectie::Colectie() {
	/* constructor */
	prim = nullptr;
	indice = nullptr;
	anterior = nullptr;
	this->dimensiune = 0;
}


void Colectie::adauga(TElem elem) {
	/* 
	functie pentru adaugarea unui element elem in colectie
	Complexitate: best=theta(1), worst=average=theta(n), overall=O(n)
	*/
	if (cauta(elem) == false)
	{
		PointerNod nou = new Nod(elem, 1, nullptr);
		//nou devine nodul de la final
		nou->urm = prim;
		//prim puncteaza catre noul nod "nou"
		prim = nou;
		indice = prim;
	}
	else
	{
		while (indice->elem != elem && indice != nullptr)
		{
			indice = indice->urm;
		}
		indice->frecv++;
		indice = prim;
		
	}
	dimensiune++;
}


bool Colectie::sterge(TElem elem) {
	/* 
	functie care sterge elementul elem din colectie( sau scadem frecventa)
	returneaza true daca stergerea s-a realizat cu succes, iar false in caz contrar
	Complexitate: best=theta(1), average=worst=theta(n), overall O(n)
	*/
	if (cauta(elem) == false)
		return false;
	else
	{
		indice = prim;
		anterior = nullptr;
		if (indice != nullptr && indice->elem == elem) 
		{	//verificam daca primul element din lista e cel de sters
			if (indice->frecv > 1)
				indice->frecv--;
			else {
				prim = indice->urm;
				delete indice;
			}
		}
		else
		{
			//gasim elementul "elem" care trebuie sters
			while (indice != nullptr && indice->elem != elem)
			{
				anterior = indice;
				indice = indice->urm;
			}
			if (indice->frecv > 1)
				indice->frecv--;
			else
			{
				anterior->urm = indice->urm;
				delete indice;
			}
		}
		indice = prim;
		dimensiune--;
		
		return true; //true - elementul elem s-a sters cu succes
	}
}


bool Colectie::cauta(TElem elem) {
	/*
	functie care cauta alementul elem si returneaza true daca exista, in caz contrar false
	Complexitate: best=theta(1), average=worst=theta(n), overall = O(n)
	*/
	indice = prim;
	while (indice != nullptr)
	{
		if (indice->elem == elem)
		{
			indice = prim;
			return true;
		}
		else
			indice = indice->urm;
	}
	indice = prim;
	return false;


}

int Colectie::nrAparitii(TElem elem){
	
	if (cauta(elem) == false)
		return 0;
	else
	{
		int numarAparitii = 0;
		indice = prim;
		while (indice->elem != elem && indice != nullptr)
			indice = indice->urm;
		if (indice->frecv > 1)
			numarAparitii = indice->frecv;
		else
			numarAparitii = 1;
		indice = prim;

		return numarAparitii;
	}
}

void Colectie::adaugaAparitiiMultiple(int nr, TElem elem)
{
	/*
	functie ce adauga numarul nr de aparitii elementului elem din colectie
	daca numarul de aparitii nr este <0,  arunca exceptie
	Complexitate: best=theta(1), average=worst=theta(n), overall=O(n)
	*/
	if (nr < 0)
		throw exception();
	else
	{
		if (cauta(elem) == true) 
		{
			//exista si doar adaugam la frecventa actuala numarul nr
			indice = prim;
			while (indice->elem != elem && indice != nullptr)
				indice = indice->urm;
			indice->frecv += nr;

			indice = prim;
		}
		else //cazul 2: nu exista si il cream noi
		{
			PointerNod nodNou = new Nod(elem, nr, nullptr); // am creat un noud nou cu elementul elem si frecventa "nr"
			//nou devine nodul de la final
			nodNou->urm = prim;
			//prim puncteaza catre noul nod "nou"
			prim = nodNou;
			indice = prim;
		}
	}
	
}


int Colectie::dim() const {
	/* 
	functie care returneaza dimensiunea colectiei
	Complexitate: best=average=worst case = theta(1)
	*/
	return this->dimensiune;
}


bool Colectie::vida() const {
	/* 
	functie care verifica daca colectia e vida
	Complexitate: best=average=worst case = theta(1)
	*/
	if (prim == nullptr)
		return true;
	else
		return false;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* 
	functie care dealoca memoria nodurilor din lista
	Complexitate: best=average=worst case=theta(n)
	*/
	while (prim != nullptr)
	{
		PointerNod p = prim;
		prim = prim->urm;
		delete p;
	}
}

