#pragma once

//typedef int TComp;
//typedef TComp TElem;
typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

struct Nod {
	TElem elem;
	int next, frecventa;
};

struct listaNoduri {
	Nod * noduri;
	int prim, ultim, primLiber;
	int capacitate, dimensiune, dimensiune_actuala;
};



class Colectie {

	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	listaNoduri colectie;
	
	int cautaPozElement(TElem elem) const;

	//functie pentru alocarea unui spatiu liber
	//se returneaza pozitia spatiului liber din lista
	int aloca();

	//functie pentru dealocarea spatiului de pe indicele i
	void dealoca(int poz);


	//functie ce redimensioneaza lista inlantuita
	void redim();

	void insertPoz(TElem elem, int poz);


public:
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;

	int elementeCuFrecventaData(int frecventa) const;
	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();


};

