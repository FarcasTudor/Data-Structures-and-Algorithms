#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

//~~~~~~~~~~~~Colectie~~~~~~~~~~~~~~~

bool rel(TElem e1, TElem e2) {
	if (e1 <= e2) 
		return true;
	else 
		return false;
	
}

Colectie::Colectie() {
	/* BestCase = WorstCase = AverageCase = THETA(n) */
	this->colectie.capacitate = 10;
	this->colectie.noduri = new Nod[10];
	this->colectie.prim = -1;
	for (int i = 0; i < this->colectie.capacitate - 1; ++i)
	{
		this->colectie.noduri[i].next = i + 1;
	}
	
	this->colectie.noduri[this->colectie.capacitate - 1].next = -1;
	this->colectie.primLiber = 0;
	this->colectie.dimensiune = 0;
	this->colectie.dimensiune_actuala = 0;

}

int Colectie::cautaPozElement(TElem elem) const
{
	/*
	BestCase = Theta(1) - primul element
	WorstCase = Theta(n) - ultimul element
	OverallCase = O(n)
	*/
	int curent = this->colectie.prim;
	int dim = this->colectie.dimensiune;
	while (curent != -1 && this->colectie.noduri[curent].elem != elem && dim > 0)
	{
		curent = this->colectie.noduri[curent].next;
		dim--;
	}

	return curent;
}

int Colectie::aloca()
{
	//BestCase = WorstCase = AverageCase = THETA(1)
	int newElem = this->colectie.primLiber;
	if (newElem != -1)
	{
		this->colectie.primLiber = this->colectie.noduri[this->colectie.primLiber].next;
		this->colectie.noduri[newElem].next = -1;
	}
	return newElem; 
}

void Colectie::dealoca(int poz)
{
	//BestCase = WorstCase = AverageCase = THETA(1)
	this->colectie.noduri[poz].next = this->colectie.primLiber;
	this->colectie.primLiber = poz;
}

void Colectie::redim()
{
	//BestCase = WorstCase = AverageCase = THETA(n)  -  n = capacitate
	auto newNoduri = new Nod[this->colectie.capacitate * 2];
	for (int i = 0; i < this->colectie.capacitate; i++)
		newNoduri[i] = this->colectie.noduri[i];
	
	//initializam a doua jumatate din next
	for (int i = this->colectie.capacitate; i < 2 * this->colectie.capacitate - 1; i++)
		newNoduri[i].next = i + 1 ;
	newNoduri[2 * this->colectie.capacitate - 1].next = -1;

	this->colectie.primLiber = this->colectie.capacitate;
	this->colectie.capacitate *= 2;
	delete[] this->colectie.noduri;
	this->colectie.noduri = newNoduri;
}

void Colectie::insertPoz(TElem elem, int poz)
{
	/*
	BestCase = Theta(1) - daca am inserat pe prima pozitie
	WorstCase = WorstCAse = Theta(n)
	OverallCase = O(n)
	*/
	int newElem = this->aloca();
	if (newElem == -1) {
		this->redim();
		newElem = this->aloca();
	}
	this->colectie.noduri[newElem].elem = elem;
	if (poz == 0)
	{
		if (this->colectie.prim == -1)
		{
			this->colectie.prim = newElem;
			this->colectie.ultim = newElem;
		}
		else
		{
			this->colectie.noduri[newElem].next = this->colectie.prim;
			this->colectie.prim = newElem;
		}
	}
	else
	{
		int nodCurent = this->colectie.prim;
		int pozCurent = 0;
		while (nodCurent != -1 && pozCurent < poz )
		{
			nodCurent = this->colectie.noduri[nodCurent].next;
			pozCurent = pozCurent + 1;
		}
		int nodNext;
		if (nodCurent != -1)
		{
			nodNext = this->colectie.noduri[nodCurent].next;
			this->colectie.noduri[newElem].next = nodNext;
			this->colectie.noduri[nodCurent].next = newElem;
			if (nodNext == -1)
				this->colectie.ultim = newElem;
			
		}
		else
			throw std::exception();
		
	}
}



void Colectie::adauga(TElem e) {
	/*
	BestCase = Theta(1) - daca cautaPozElement are complexitate Theta(1)
	WorstCase = AverageCase = Theta(n) 
	OverallCase = O(n)
	*/
	int poz = this->cautaPozElement(e);
	this->colectie.dimensiune++;
	
	if (poz == -1)
	{
		poz = this->colectie.prim;
		if (poz != -1)
		{
			int index = 0;
			while (poz == -1 && rel(this->colectie.noduri[poz].elem, e))
			{   //
				poz = this->colectie.noduri[poz].next;
				index++;
			}
			if (poz == -1)
			{
				this->insertPoz(e, this->colectie.dimensiune_actuala);
				this->colectie.noduri[this->colectie.dimensiune_actuala].frecventa = 1;
			}
			else
			{
				this->insertPoz(e, index);
				int i = cautaPozElement(e);
				this->colectie.noduri[i].frecventa = 1;
			}
		}
		else
		{ //prima pozitie
			poz = 0;
			this->insertPoz(e, poz);
			this->colectie.noduri[poz].frecventa = 1;
		}
		this->colectie.dimensiune_actuala++;
	}
	else
	{
		this->colectie.noduri[poz].frecventa++;
	}

}


bool Colectie::sterge(TElem e) {
	/*
	BestCase = Theta(1) - daca elementul pe care dorim sa il stergem are frecventa mai mare ca 1
	WorstCase = WorstCAse = Theta(n)
	OverallCase = O(n)
	*/
	int poz = this->cautaPozElement(e);
	if (poz == -1)
		return false;
	if (this->colectie.noduri[poz].frecventa > 1)
	{
		this->colectie.dimensiune--;
		this->colectie.noduri[poz].frecventa--;
	}
	else
	{
		int nod = -1;
		int nodCurent = this->colectie.prim;
		while (nodCurent != -1 && this->colectie.noduri[nodCurent].elem != e)
		{
			nod = nodCurent;
			nodCurent = this->colectie.noduri[nodCurent].next;
		}
		
		this->colectie.dimensiune--;
		this->colectie.dimensiune_actuala--;
		this->colectie.noduri[nodCurent].frecventa--;
		if (nodCurent == this->colectie.prim)
			this->colectie.prim = this->colectie.noduri[this->colectie.prim].next;
		else
			this->colectie.noduri[nod].next = this->colectie.noduri[nodCurent].next;
		this->dealoca(nodCurent);
		
	}
	return true;
}


bool Colectie::cauta(TElem elem) const {
	/*
	BestCase = Theta(1) - elementul cautat este pe prima pozitie
	WorstCase = WorstCAse = Theta(n) - elementul cautat este pe ultima pozitie
	OverallCase = O(n)
	*/
	int curent = this->colectie.prim;
	int dim = this->colectie.dimensiune;
	while (curent != -1 && this->colectie.noduri[curent].elem != elem && dim > 0)
	{
		dim--;
		curent = this->colectie.noduri[curent].next;
	}


	if (curent != -1)
		return true;
	return false;
}


int Colectie::nrAparitii(TElem elem) const {
	/*
	best=theta(1) - daca elementul cautat se afla pe prima pozitie
	average=worst=theta(n),  overall=O(n)
	*/
	int curent = this->colectie.prim;
	int dim = this->colectie.dimensiune;
	while (curent != -1 && this->colectie.noduri[curent].elem != elem && dim > 0)
	{
		dim--;
		curent = this->colectie.noduri[curent].next;

	}
	if (curent == -1)
		return 0;
	return this->colectie.noduri[curent].frecventa;

}

int Colectie::elementeCuFrecventaData(int frecventa) const
{
	int numarDelemente = 0, i=0;
	
	if (frecventa <= 0)
		throw exception();
	for (i = 0; i < this->colectie.dimensiune; i++) {
		if (this->colectie.noduri[i].frecventa == frecventa)
			numarDelemente++;
	}
	return numarDelemente;
}



int Colectie::dim() const {
	//BestCase = WorstCase = AverageCase = THETA(1)
	return this->colectie.dimensiune;
}


bool Colectie::vida() const {
	//BestCase = WorstCase = AverageCase = THETA(1)
	return this->colectie.dimensiune == 0;
}


IteratorColectie Colectie::iterator() const {
	//BestCase = WorstCase = AverageCase = THETA(1)

	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	//BestCase = WorstCase = AverageCase = THETA(1)
	delete[] this->colectie.noduri;
}