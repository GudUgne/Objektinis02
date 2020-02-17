#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::setprecision;
using std::setw;
using std::left;


struct Studentas {
	string v;
	string pav;     //string pats rezervuos vietu kiek reikes, jei noriu rezervuot pvz 15, rasau char[15]
	double nd[1000];
	int ndskc = 0;
	int egz;
	double vid = 0;
	double med;
	double gal;
};


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
			cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite -1." << endl;
			cin >> n;
			if (n == -1) {
				for (int j = 0; j < 1; j++) {
					cout << "Veskite pazymi. Jei daugiau nera, veskite 0" << endl;
					cin >> l;
					if (l != 0) {
						Duomenys.nd[Duomenys.ndskc] = l;
						Duomenys.ndskc++;
						j--;
					}
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					cout << "Veskite pazymi:" << endl;
					cin >> l;
					Duomenys.nd[Duomenys.ndskc] = l;
					Duomenys.ndskc++;
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
					Duomenys.nd[Duomenys.ndskc] = l;
					Duomenys.ndskc++;
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					l = (1 + rand() % 10);
					Duomenys.nd[Duomenys.ndskc] = l;
					Duomenys.ndskc++;
				}
			}

		}
		Stud.push_back(Duomenys);				//viskas perkeliama i pagr struktura
		cout << "Sio studento duomenu vedimas baigtas" << endl;
	}
}


void Skaiciavimai(vector <Studentas>& Stud, int t) {

	int pozicija;


	for (int i = 0; i < Stud.size(); i++) {
		if (t == 1) {
			sort(Stud.at(i).nd, Stud.at(i).nd+Stud.at(i).ndskc);		//mediana kai lyg skc nariu
			pozicija = Stud.at(i).ndskc;
			if (pozicija % 2 == 0) {
				Stud.at(i).med = ((Stud.at(i).nd[pozicija / 2]) + (Stud.at(i).nd[pozicija / 2 - 1])) / 2;
				cout << Stud.at(i).med << endl;
			}
			else {
				Stud.at(i).med = Stud.at(i).nd[pozicija / 2];
				cout << Stud.at(i).med << endl;						//skaiciuojama mediana kai nelyg skc nariu
			}
			Stud.at(i).gal = (0.4 * Stud.at(i).med) + (0.6 * Stud.at(i).egz);
		}
		else {
			for (int j = 0; j < Stud.at(i).ndskc; j++) {
				Stud.at(i).vid += Stud.at(i).nd[j];			//visu nd pazymiu suma

			}
			Stud.at(i).vid = Stud.at(i).vid / Stud.at(i).ndskc;		//suskaiciuojamas vidurkis

			Stud.at(i).gal = (0.4 * Stud.at(i).vid) + (0.6 * Stud.at(i).egz);

		}
	}
}

void Spausdinimas(vector <Studentas>& Stud, int t) {

	cout << left << setw(15) << "Vardas:" << left << setw(20) << "Pavarde:";
	if (t == 1) { cout << "Gal. med" << endl; }
	else { cout << "Gal. vid" << endl; }

	for (int i = 0; i < Stud.size(); i++) {

		cout << left << setw(15) << Stud.at(i).v << left << setw(20) << Stud.at(i).pav << setprecision(2) << Stud.at(i).gal << endl;;


	}

}

int main()
{
	string atsakymas;
	int t = 0;				//tikrinimui 
	vector <Studentas> Stud;

	DuomenuIvedimas(Stud);

	cout << "Galutini skaiciuoti pagal mediana ar pazymiu vidurki?" << endl;
	cin >> atsakymas;
	if (atsakymas == "mediana") {			//jei parasyta kita, nei mediana, automatiskai skaiciuos vidurki
		t = 1;
	}

	Skaiciavimai(Stud, t);
	Spausdinimas(Stud, t);

	return 0;
}