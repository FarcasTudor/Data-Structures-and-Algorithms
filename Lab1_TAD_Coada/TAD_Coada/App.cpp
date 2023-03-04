#include <iostream>
#include "Coada.h"
#include "TestExtins.h"
#include "TestScurt.h"

using namespace std;


int main() {
	testAll();
	testAllExtins();
	cout << "~~~~~~~~~~~~~~~~Merge~~~~~~~~~~~~~~~~\n";
	/*
	bool conditie = true;
	char comanda[20] = "";

	Coada c;

	while (conditie)
	{
		printf("[1] Adauga\n");
		printf("[2] Sterge\n");
		printf("[3] Element\n");
		printf("[4] Vida\n");
		printf("[5] Afisare\n");
		printf("[0] Exit\n");

		cout << "\nIntroduceti comanda: ";
		cin >> comanda;
		cout << "\n";

		if (strcmp(comanda , "0") == 0)
		{
			conditie = false;
		}

		else if (strcmp(comanda ,"1") == 0)
		{
			TElem e;

			cout << "Introduceti elementul: ";
			cin >> e;
			cout << "\n";
			c.adauga(e);
		}

		else if (strcmp(comanda, "2") == 0)
		{
			TElem ok;

			try
			{
				ok = c.sterge();
				cout << "Elementul " << ok << " a fost sters cu succes\n";
			}
			catch (exception&)
			{
				cout << "Nu exista elemente de sters\n";
			}

		}

		else if (strcmp(comanda, "3") == 0)
		{
			TElem e;

			try
			{
				e = c.element();
				cout << "Elementul curent este: " << e << "\n";
			}
			catch (exception&)
			{
				cout << "Nu exista elemente in coada!\n";
			}

		}

		else if (strcmp(comanda, "4") == 0)
		{
			bool ok;

			ok = c.vida();

			if (ok == true)
			{
				cout << "Coada este vida\n";
			}

			else
			{
				cout << "Coada nu este vida\n";
			}
		}

		else if (strcmp(comanda, "5") == 0)
		{
			printf("Elementele din coada sunt: ");
			~~~~~~~~~~~~~~~~~~~~~~
			bool ok;

			ok = c.vida();

			while (ok == false)
			{
				TElem e = c.element();

				cout << e << " ";

				c.sterge();

				ok = c.vida();
			}
			~~~~~~~~~~~~~~~~~~~~~~~
			if (c.vida() == true) cout << "Nu exista elemente";
			else
				c.tiparire();

			cout << '\n' << '\n';
		}

		else
		{
			cout << "Comanda invalida!\n\n";
		}
	}

	*/
	return 0;
}
