#include "Header.h"			//siame faile yra visos funkcijos pilnai aprasytos

void DuomenuNuskaitymas(vector <Studentas>& Stud) {

	std::ifstream FD("kursiokai.txt");
	string a;		//tik nuskaityti pirma eil
	int NdKiekis = 0;			//kiek faile yra aprasytu ND
	int l;			//laikinas
	Studentas Duomenys;

	if (!FD) {
		cout << "Duomenu failas nerastas, programa nebus vykdoma" << endl;
		exit(0);
	}
	
	FD >> a >> a >> a;		//skaito  pirmos eiles teksta
	while (a[0] == 'N') {			//atpazista kiek ND yra
		NdKiekis++;
		FD >> a;		//ciklo pabaigoje a tampa egzaminu
	}

	while (!FD.eof()) {
		FD >> Duomenys.v >> Duomenys.pav;	//stud v ir pav
		for (int i = 0; i < NdKiekis; i++) {			//visi nd (dabar - 15)
			FD >> l;
			if ((l < 0) || (l > 10)) {
				l = 0;
				cout << "Ivedant pazymius buvo rasta klaidu, vietoj jo buvo irasytas 0" << endl;
			}
			Duomenys.nd.push_back(l);
		}
		FD >> Duomenys.egz;				//egz rez

		Stud.push_back(Duomenys);				//viskas perkeliama i pagr strukturos viena nari
		Duomenys.nd.clear();
	}

	FD.close();

}

int Tikrinimas(int n, int t) {

	for (int i = 0; i < 1; i++){

		if (t == 0) {							//tikrinamas ivestas pazymiu kiekis
			if (cin.fail() || (n < -1)) {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Klaida - veskite dar karta" << endl;
					cin >> n;
					i--;
			}
			else { return n; }
			
		}
		 if (t == 1) {										//tikrinamas egz pazymys ar nd pazymys
			if (cin.fail() || (n < 0) || (n > 10)) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Klaida - veskite dar karta" << endl;
				cin >> n;
				i--;
			}
			else { return n; }

		 }

		 if (t == 2) {
			 if (cin.fail() || (n < 0)) {
				 cin.clear();
				 cin.ignore(256, '\n');
				 cout << "Klaida - veskite dar karta" << endl;
				 cin >> n;
				 i--;
			 }
			 else { return n; }
		 }
	}

}

void DuomenuIvedimas(vector <Studentas>& Stud) {

	int ss, n, l, t;									//studentu skaicius, nd skc, laikinas ir patikrinimo kintamieji
	string pat;

	cout << "Kiek mokiniu bus?" << endl;
	cin >> ss;
	t = 2;
	ss = Tikrinimas(ss, t);
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

			int t = 1;										//tikrinimo fun. tikrins egz
			Duomenys.egz = Tikrinimas(Duomenys.egz, t);		//perraso jei kazkas negerai

			cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite -1)" << endl;
			cin >> n;
			t = 0;											// tikrinimo fun. tikrins paz kieki
			n = Tikrinimas(n, t);
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
			Duomenys.egz = (1 + rand() % 10);		//egz pazymys generuojamas nuo 1 iki 10
			cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite -1):" << endl;
			cin >> n;
			t = 0;
			n = Tikrinimas(n, t);

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
