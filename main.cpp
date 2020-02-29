#include "Header.h"		//siame faile pagr programa

int main()
{
	string atsakymas;
	int t;				//tikrinimui 
	vector <Studentas> Stud;

	cout << "Studentai ivedami ranka ar skaitomi is failo? Failas/Ranka" << endl;
	cin >> atsakymas;
	
	for (int i = 0; i < 1; i++) {

		if (atsakymas == "Failas") {
			DuomenuNuskaitymas(Stud);
			t = 2;		 //spausdins ir gal med ir gal vid
		}

		else if (atsakymas == "Ranka") {
			DuomenuIvedimas(Stud);
			cout << "Galutini rezultata skaiciuoti naudojant mediana ar namu darbu vidurki? Mediana/Vidurkis" << endl;
			cin >> atsakymas;

			for (int i = 0; i < 1; i++) {

				if (atsakymas == "Mediana") {
					t = 1;
				}

				else if (atsakymas == "Vidurkis") {
					t = 0;
				}

				else {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Klaida - veskite dar karta" << endl;
					cin >> atsakymas;
					i--;
				}

			}
		}

		else {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Klaida - veskite dar karta" << endl;
			cin >> atsakymas;
			i--;

		}
	}

	Skaiciavimai(Stud);
	Spausdinimas(Stud, t);

	return 0;
}