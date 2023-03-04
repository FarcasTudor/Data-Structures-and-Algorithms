#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorColectie;

class Nod;
typedef Nod* PointerNod; // referim clasa nod, urmand sa referim adresa nodului prin NodAddress

class Nod
{
private:
	TElem elem;
	TElem frecv;
	TElem ind;
	PointerNod urm;
public:
	friend class Colectie;

	//constructor

	Nod(TElem element, TElem frecventa, PointerNod urm);
	//returneaza un element
	TElem element();
	//returneaza frecventa
	TElem frecventa();
	//returneaza indicatorul
	TElem indicator();
	//returneaza urmatorul nod
	PointerNod urmator();
	//daca frecventa e 1, o initializeaza cu 0, altfel daca e >1 ii scade frecventa
	TElem modifica_frecventa();
	//frecventa devine indicatorul
	TElem save_frecventa();
	//indicatorul creste cu o valoare
	TElem mareste_indicator();
	//indicator primeste valoarea 0
	TElem initializeaza_indicator();

};



class Colectie {
	friend class IteratorColectie;
private:
	/* aici e reprezentarea */
	int dimensiune;

	PointerNod prim; //adresa primului Nod din lista
	PointerNod indice;
	PointerNod anterior;

public:
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) ;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem);

	void adaugaAparitiiMultiple(int nr, TElem elem);

	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;
	// destructorul colectiei
	~Colectie();

};