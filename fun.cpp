#include "Header.h"			//siame faile yra visos funkcijos pilnai aprasytos

//jeigu kintamasis = NULL, vadinasi jis neegzistuoja



void DuomenuNuskaitymas(vector <Studentas>& Stud) {

	std::ifstream FD("kursiokai.txt");
	string a;		//tik nuskaityti pirma eil
	int NdKiekis = 0;			//kiek faile yra aprasytu ND
	int l;			//laikinas
	Studentas Duomenys;

	FD >> a >> a >> a;		//skaito varda, pavarde (neaktualu) ir tolimesnius ND
	while (a[0] == 'N') {
		NdKiekis++;
		FD >> a;		//ciklo pabaigoje a tampa egzaminu
	}

	while (!FD.eof()) {
		FD >> Duomenys.v >> Duomenys.pav;	//stud v ir pav
		for (int i = 0; i < NdKiekis; i++) {			//visi nd (dabar - 15)
			FD >> l;
			Duomenys.nd.push_back(l);
		}
		FD >> Duomenys.egz;				//egz rez

		Stud.push_back(Duomenys);				//viskas perkeliama i pagr strukturos viena nari
		Duomenys.nd.clear();
	}

	FD.close();

}

void DuomenuIvedimas(vector <Studentas>& Stud) {

	int ss, n, l;									//studentu skaicius, nd skc, laikinas ir patikrinimo kintamieji
	string pat;

	cout << "Kiek mokiniu bus?" << endl;
	cin >> ss;
	Studentas Duomenys;
	for (int i = 0; i < ss; i++) {
		cout << "Iveskite studento varda:" << endl;
		cin >> Duomenys.v;
		cout << "Iveskite studento pavarde:" << endl;
		cin >> Duomenys.pav;
		cout << "Ar norite random sugeneruotu skaiciu? Taip/Ne" << endl;
		cin >> pat;

		//dalis, kai skaiciai ivedami ranka
		if (pat == "Ne") {
			cout << "Iveskite studento egzamino rezultata:" << endl;
			cin >> Duomenys.egz;
			cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite -1)" << endl;
			cin >> n;
			if (n == -1) {
				for (int j = 0; j < 1; j++) {
					cout << "Veskite pazymi. Jei daugiau nera, veskite 0" << endl;
					cin >> l;
					if (l != 0) {
						Duomenys.nd.push_back(l);
						j--;
					}
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					cout << "Veskite pazymi:" << endl;
					cin >> l;
					Duomenys.nd.push_back(l);
				}
			}
		}
		else {						//random pazymiu generavimas
			srand(time(0));
			Duomenys.egz = (1 + rand() % 10);		//pazymiai generuojami nuo 1 iki 10
			cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite -1):" << endl;
			cin >> n;
			if (n == -1) {
				int j = (1 + rand() % 20);			//generuojama nuo 1 iki 20, kad nebutu per daug

				for (int c = 0; c < j; c++) {
					l = (1 + rand() % 10);			//random pazymys nuo 1 iki 10
					Duomenys.nd.push_back(l);

				}
			}
			else {
				for (int j = 0; j < n; j++) {
					l = (1 + rand() % 10);
					Duomenys.nd.push_back(l);
				}
			}

		}
		Stud.push_back(Duomenys);				//viskas perkeliama i pagr struktura
		Duomenys.nd.clear();							//isvaloma naudoti kitam studentui
		cout << "Sio studento duomenu vedimas baigtas" << endl;
	}
}


void Skaiciavimai(vector <Studentas>& Stud) {

	int pozicija;

	for (int i = 0; i < Stud.size(); i++) {

		sort(Stud.at(i).nd.begin(), Stud.at(i).nd.end());		//mediana kai lyg skc nariu
		pozicija = Stud.at(i).nd.size();
		if (pozicija % 2 == 0) {
			Stud.at(i).med = ((Stud.at(i).nd.at(pozicija / 2)) + (Stud.at(i).nd.at(pozicija / 2 - 1))) / 2;
		}
		else {
			Stud.at(i).med = Stud.at(i).nd.at(pozicija / 2);				//skaiciuojama mediana kai nelyg skc nariu
		}
		Stud.at(i).galmed = (0.4 * Stud.at(i).med) + (0.6 * Stud.at(i).egz);



		for (int j = 0; j < Stud.at(i).nd.size(); j++) {
			Stud.at(i).vid += Stud.at(i).nd.at(j);			//visu nd pazymiu suma
		}

		Stud.at(i).vid = Stud.at(i).vid / Stud.at(i).nd.size();		//suskaiciuojamas vidurkis
		Stud.at(i).galvid = (0.4 * Stud.at(i).vid) + (0.6 * Stud.at(i).egz);


	}
}

bool Isrikiavimas(Studentas& s1, Studentas& s2) {
	if (s1.v < s2.v) return s1.v < s2.v;
	else if (s1.v == s2.v) return s1.pav < s2.pav;

}

void Spausdinimas(vector <Studentas>& Stud, int t) {

	std::ofstream FR("Rezultatai.txt");

	FR << left << setw(15) << "Vardas:" << left << setw(20) << "Pavarde:";
	if (t == 1) { FR << "Gal. med" << endl; }
	else if (t == 2) { FR << "Gal. vid" << " Gal. med" << endl; }
	else { FR << "Gal. vid" << endl; }

	sort(Stud.begin(), Stud.end(), Isrikiavimas);

	for (int i = 0; i < Stud.size(); i++) {

		FR << left << setw(15) << Stud.at(i).v << left << setw(20) << Stud.at(i).pav;
		if (t != 1) {
			FR << left << setw(9) << setprecision(3) << Stud.at(i).galvid;
		}

		if (t != 0) {
			FR << left << setw(9) << setprecision(2) << Stud.at(i).galmed;
		}

		FR << endl;
	}
	FR.close();

	cout << "Duomenu isvedimas i faila baigtas";
}
