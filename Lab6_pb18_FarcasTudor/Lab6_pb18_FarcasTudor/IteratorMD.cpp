#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& _md) : md(_md) {
	/* de adaugat */
	this->pozAnterior = 0;
	this->pozCurent = 0;
	deplasare();
}


void IteratorMD::deplasare()
{
	while ((this->pozCurent < md.m) && md.keys[pozCurent] == nullptr)
		pozCurent++;
	if (this->pozCurent < this->md.m)
		this->curent = this->md.keys[this->pozCurent];
}


TElem IteratorMD::element() const {
	/* de adaugat */
	if (!valid())
		throw(exception());
	return this->curent->e;

}

void IteratorMD::anterior()
{
	//
	if (!valid())
		throw(exception());
	if (this->pozCurent == 0)
		this->pozCurent = this->md.m + 1;
	else
	{
		this->pozCurent = this->pozAnterior;
	}
	deplasare();
}

bool IteratorMD::valid() const {
	/* de adaugat */
	if (this->pozCurent < this->md.m)
		return true;
	return false;
}

void IteratorMD::urmator() {
	/* de adaugat */
	if (!valid())
		throw(exception());
	this->curent = this->curent->urm;
	if (this->curent == nullptr)
	{
		this->pozAnterior = this->pozCurent;
		this->pozCurent++;
		deplasare();
	}
}

void IteratorMD::prim() {
	/* de adaugat */
	this->pozCurent= 0;
	this->pozAnterior = this->pozCurent;
	deplasare();
}

