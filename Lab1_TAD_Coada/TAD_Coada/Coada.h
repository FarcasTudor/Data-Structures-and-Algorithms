#pragma once
//Coada.h
#include <stdlib.h>

typedef int TElem;

class Coada {
private:
	/* aici e reprezentarea */
	TElem* coada;
	TElem prim, ultim, capacitate, nrElem;
public:
	//constructorul implicit
	Coada();

	int Ultimul();

	//adauga un element in coada
	void adauga(TElem e);

	//acceseaza elementul cel mai devreme introdus in coada 
	//arunca exceptie daca coada e vida
	TElem element() const;

	void tiparire();

	//sterge elementul cel mai devreme introdus in coada si returneaza elementul sters (principiul FIFO)
	//arunca exceptie daca coada e vida
	TElem sterge();

	//verifica daca coada e vida;
	bool vida() const;


	// destructorul cozii
	~Coada();

};
