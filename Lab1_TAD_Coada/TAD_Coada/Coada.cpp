
#include "Coada.h"
#include <exception>
#include <iostream>
using namespace std;


Coada::Coada() {
	/* Constuctorul */
	capacitate = 30;
	nrElem = 0;
	coada = (TElem*)malloc(capacitate * sizeof(TElem));
	prim = 1;
	ultim = 1;

}

int Coada::Ultimul()
{
	return ultim;
}


void Coada::adauga(TElem e) {
	/* Adauga elementul e in coada 
	   teta(n)
	*/
	if (nrElem < capacitate)
	{
		coada[ultim] = e;
		nrElem++;
		if (ultim < capacitate)
			ultim++;
		 
		if (prim != 1) //aici vom respecta adaugarea circulara, punand pozitia ultim la inceput
				ultim = 1;
	}

	TElem* coadaNoua = (TElem*)malloc(sizeof(TElem) * (capacitate + 2));

	for (int i = prim; i <= capacitate; i++)
	{
		coadaNoua[i] = coada[i];
	}

	free(coada);

	coada = coadaNoua;
	capacitate += 2;

}

//arunca exceptie daca coada e vida
TElem Coada::element() const {
	/* Cauta elementul curent in coada (primul)
	   Returneaza elementul sau -1 daca coada e vida 
	   teta(1)
	   */
	if (vida() == true)
		throw exception();
	else
		return TElem(coada[prim]);
} 
  
// 1 2 3 4

TElem Coada::sterge() {
	/* Sterge elementul curent din coada
	   Returneaza elementul sters sau -1 daca coada e vida 
	   teta(1)
	   */
	if (vida() == true)
		throw exception();
	/*
	else
	{                          //stergere liniara
		TElem e = coada[prim];
		for (int i = prim; i < ultim - 1; i++)
			{
				coada[i] = coada[i + 1];
			}
		ultim--;
		return TElem(e);
	}
	*/
	//~~~~~~~~~~~~~~~~~~~~stergere circulara
	TElem e = coada[prim];

	if (prim < capacitate)
		prim++;
	else
		prim = 1;

	nrElem--;

	return TElem(e);
}

void Coada::tiparire()
{
	/* Tipareste elementele din coada 
	   teta(n)
	*/
	if (prim < ultim)
		for (int i = prim; i < ultim; i++)
			cout << coada[i] << " ";
}


bool Coada::vida() const 
{
	/* Verifica daca coada e vida 
	   Returneaza true daca coada e vida sau false in caz contrar 
	   teta(1)
	   */
	
	if (prim == ultim)
		return true;

	return false;
}


Coada::~Coada() {
	/* Destructor */
	free(coada);
}

