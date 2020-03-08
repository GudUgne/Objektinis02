#include "Header.h"		//siame faile pagr programa

int main()
{
	std::chrono::steady_clock sc;		//timeris
	string atsakymas;
	int t, p;				//tikrinimui 
	vector <Studentas> Stud, Nuskriausti, Praslyde;

	cout << "Studentai ivedami ranka ar skaitomi is failo? Failas/Ranka" << endl;
	cin >> atsakymas;
	
	for (int i = 0; i < 1; i++) {

		if (atsakymas == "Failas") {
			cout << "Faila skaityti jau sukurta, ar generuoti nauja? Senas/Naujas" << endl;
			cin >> atsakymas;

			for (int i = 0; i < 1; i++) {

				if (atsakymas == "Naujas") {				//jei naujas failas

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
					//prasideda generavimas, skaiciavimai ir t.t

					 int a = 1000;
					 for (int i = 0; i < 5; i++) {
						 auto start = sc.now();     // start timer
						 DuomenuFailoGeneravimas(a, 5);
						 auto end = sc.now();       // end timer
						 auto time_span = static_cast<std::chrono::duration<double>>(end - start);
						 cout << a << " stud. f. kurimas truko " << time_span.count() << " sek." << endl;

						 start = sc.now();
						 DuomenuNuskaitymas(Stud, a);
						 end = sc.now();
						 time_span = static_cast<std::chrono::duration<double>>(end - start);
						 cout << a << " stud. f. nuskaitymas truko " << time_span.count() << " sek." << endl;
						

						 Skaiciavimai(Stud);

						 start = sc.now();
						 Isrusiavimas(Stud, Nuskriausti, Praslyde, t);
						 end = sc.now();
						 time_span = static_cast<std::chrono::duration<double>>(end - start);
						 cout << a << " stud. f. Isrusiavimas truko " << time_span.count() << " sek." << endl;

						 start = sc.now();
						 Spausdinimas(Nuskriausti, t, "Nuskriausti"+ std::to_string(a) + ".txt");
						 end = sc.now();
						 time_span = static_cast<std::chrono::duration<double>>(end - start);
						 cout << a << " nuskriaustu spausdinimas truko " << time_span.count() << " sek." << endl;

						 start = sc.now();
						 Spausdinimas(Praslyde, t, "Praslyde" + std::to_string(a) + ".txt");
						 end = sc.now();
						 time_span = static_cast<std::chrono::duration<double>>(end - start);
						 cout << a << " praslydusiu spausdinimas truko " << time_span.count() << " sek." << endl;

						 Nuskriausti.clear();
						 Praslyde.clear();

						 a = a * 10;
					 }


				}

				else if (atsakymas == "Senas") {		//jau ikeltas failas
					p = 1;
					DuomenuNuskaitymas(Stud, p);
					t = 2;							//spausdins ir gal med ir gal vid
					Skaiciavimai(Stud);
					Spausdinimas(Stud, t, "Rezultatai.txt");
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

		else if (atsakymas == "Ranka") {
			DuomenuIvedimas(Stud);
			cout << "Galutini rezultata skaiciuoti naudojant mediana ar namu darbu vidurki? Mediana/Vidurkis" << endl;
			cin >> atsakymas;

			for (int i = 0; i < 1; i++) {

				if (atsakymas == "Mediana") {
					t = 1;
					Skaiciavimai(Stud);
					Spausdinimas(Stud, t, "Rezultatai.txt");
				}

				else if (atsakymas == "Vidurkis") {
					t = 0;
					Skaiciavimai(Stud);
					Spausdinimas(Stud, t, "Rezultatai.txt");
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

	//Skaiciavimai(Stud);
	//Spausdinimas(Stud, t, "Rezultatai.txt");

	return 0;
}