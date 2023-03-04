#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>
using namespace std;


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	//BestCase = WorstCase = AverageCase = THETA(1)
	this->curent_element = c.colectie.prim;
	this->curent_cantitate = 0;
}

TElem IteratorColectie::element() const {
	//BestCase = WorstCase = AverageCase = THETA(1)

	if (!this->valid())
		throw exception();
	return this->col.colectie.noduri[this->curent_element].elem;
}


bool IteratorColectie::valid() const {
	//BestCase = WorstCase = AverageCase = THETA(1)

	return this->curent_element != -1;
}

void IteratorColectie::urmator() {
	//BestCase = WorstCase = AverageCase = THETA(1)

	if (!this->valid())
		throw exception();
	if (this->curent_cantitate < this->col.colectie.noduri[this->curent_element].frecventa - 1)
		this->curent_cantitate++;
	else
	{
		this->curent_cantitate = 0;
		this->curent_element = this->col.colectie.noduri[this->curent_element].next;
	}
}

void IteratorColectie::prim() {
	//BestCase = WorstCase = AverageCase = THETA(1)

	this->curent_element = this->col.colectie.prim;
	this->curent_cantitate = 0;
}
