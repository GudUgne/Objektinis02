#include "Header.h"		//siame faile pagr programa

int main()
{
	std::chrono::steady_clock sc;		//timeris
	string atsakymas;
	int t, p;				//tikrinimui 
	vector <Studentas> Stud, Nuskriausti, Praslyde;
	deque <Studentas> StudDeq, NuskriaustiDeq, PraslydeDeq;
	list <Studentas> StudList, NuskriaustiList, PraslydeList;

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
					for (int i = 0; i < 4; i++) {
						
						DuomenuFailoGeneravimas(a, 5);
						
						//-------------------------------------------------------veiksmai su vektoriais
						auto start = sc.now();
						DuomenuNuskaitymas(Stud, a);
						auto end = sc.now();
						auto time_span = static_cast<std::chrono::duration<double>>(end - start);
						cout << a << " stud. f. vek. nuskaitymas truko " << time_span.count() << " sek." << endl;


						Skaiciavimai(Stud);

						sort(Stud.begin(), Stud.end(), Isrikiavimas);

						start = sc.now();
						Isrusiavimas(Stud, Nuskriausti, Praslyde, t);
						end = sc.now();
						time_span = static_cast<std::chrono::duration<double>>(end - start);
						cout << a << " stud. f. vek. Isrusiavimas truko " << time_span.count() << " sek." << endl;

						
						Spausdinimas(Nuskriausti, t, "NuskriaustiV" + std::to_string(a) + ".txt");
						Spausdinimas(Praslyde, t, "PraslydeV" + std::to_string(a) + ".txt");
						
						Nuskriausti.clear();
						Praslyde.clear();

						//------------------------------------------------------------veiksmai su deque

						start = sc.now();
						DuomenuNuskaitymas(StudDeq, a);
						end = sc.now();
						time_span = static_cast<std::chrono::duration<double>>(end - start);
						cout << a << " stud. f. deq. nuskaitymas truko " << time_span.count() << " sek." << endl;

						Skaiciavimai(StudDeq);
						sort(StudDeq.begin(), StudDeq.end(), Isrikiavimas);

						start = sc.now();
						Isrusiavimas(StudDeq, NuskriaustiDeq, PraslydeDeq, t);
						end = sc.now();
						time_span = static_cast<std::chrono::duration<double>>(end - start);
						cout << a << " stud. f. deq. Isrusiavimas truko " << time_span.count() << " sek." << endl;

						Spausdinimas(NuskriaustiDeq, t, "NuskriaustiDeq" + std::to_string(a) + ".txt");
						Spausdinimas(PraslydeDeq, t, "PraslydeDeq" + std::to_string(a) + ".txt");
						
						NuskriaustiDeq.clear();
						PraslydeDeq.clear();

						//-----------------------------------------------------------------veiksmai su list

						start = sc.now();
						DuomenuNuskaitymas(StudList, a);
						end = sc.now();
						time_span = static_cast<std::chrono::duration<double>>(end - start);
						cout << a << " stud. f. list nuskaitymas truko " << time_span.count() << " sek." << endl;

						Skaiciavimai(StudList);
						StudList.sort(Isrikiavimas);

						start = sc.now();
						IsrusiavimasList(StudList, NuskriaustiList, PraslydeList, t);
						end = sc.now();
						time_span = static_cast<std::chrono::duration<double>>(end - start);
						cout << a << " stud. f. list Isrusiavimas truko " << time_span.count() << " sek." << endl;

						
						Spausdinimas(NuskriaustiList, t, "NuskriaustiList" + std::to_string(a) + ".txt");
						Spausdinimas(PraslydeList, t, "PraslydeList" + std::to_string(a) + ".txt");

						NuskriaustiList.clear();
						PraslydeList.clear();



						a = a * 10;
					}


				}

				else if (atsakymas == "Senas") {		//jau ikeltas failas
					p = 1;
					DuomenuNuskaitymas(Stud, p);
					t = 2;							//spausdins ir gal med ir gal vid
					Skaiciavimai(Stud);
					sort(Stud.begin(), Stud.end(), Isrikiavimas);
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
					sort(Stud.begin(), Stud.end(), Isrikiavimas);
					Spausdinimas(Stud, t, "Rezultatai.txt");
				}

				else if (atsakymas == "Vidurkis") {
					t = 0;
					Skaiciavimai(Stud);
					sort(Stud.begin(), Stud.end(), Isrikiavimas);
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


	return 0;
}