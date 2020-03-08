#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <stdlib.h>

//siame faile - visos deklaracijos
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
	vector<double> nd;
	int egz;
	double vid = 0;
	double med;
	double gal;
	double galmed;		//galutinis mediana		- cia kai spausdinu abu iskart
	double galvid;		//galutinis vidurkis
};