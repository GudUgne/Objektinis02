#include "Header.h"		//siame faile pagr programa

int main()
{
	string atsakymas;
	int t = 0;				//tikrinimui 
	vector <Studentas> Stud;

	cout << "Studentai ivedami ranka ar skaitomi is failo? Failas/Ranka" << endl;
	cin >> atsakymas;
	if (atsakymas == "Failas") {
		DuomenuNuskaitymas(Stud);
		t = 2;		 //spausdins ir gal med ir gal vid
	}
	else {
		DuomenuIvedimas(Stud);
		cout << "Galutini rezultata skaiciuoti naudojant mediana ar namu darbu vidurki? Mediana/Vidurkis" << endl;
		cin >> atsakymas;
		if ((atsakymas == "Mediana") || (atsakymas == "Vidurkis")) {
			if (atsakymas == "Mediana") {			//jei parasyta kita, nei mediana, automatiskai skaiciuos vidurki
				t = 1;
			}
		}

		else { cout << "Klaida: duomenis veskite dar karta"; }

	}	

	Skaiciavimai(Stud);
	Spausdinimas(Stud, t);

	return 0;
}