# Studentų rezultatų skaičiuoklė
 
### [Tolimesnės versijos](https://github.com/GudUgne/Objektinis03) <-

## Įdiegimo instrukcija

- Parsisiųskite naujausią programos versiją, dabar - v1.0;

- Parsisiųskite ir įsidiekite C++ IDE, pavyzdžiui, CodeBlocks arba Visual Studio (aš naudoju VS);

- Parsisiuntus programą, atidarykite ją paspaudę .sln failą;

- Arba galima naudoti CMake failą;

## Įdiegimas UNIX kompiuteryje
git clone https://github.com/GudUgne/Objektinis02.git

cd Objektinis02

## Versijų istorija (changelog)


### [v1.0](https://github.com/GudUgne/Objektinis02/releases/tag/v1.0) - (2020-04-05)
***Pridėta***
- Dviejomis strategijomis skaičiuojami studentai naudojant vector, deque ir list STL konteinerius;
- Trečia strategija pritaikyta apskaičiuoti vector konteinerį, naudojant papildomus copy_if ir remove_copy_if algoritmus;
- Išvada patestavus: antroji strategija yra spartesnė skaičiuojant su list, bet ne su kitais konteineriais;
- Trečioji strategija su vektoriais yra sparčiausia;
- Pridėtas CMake failas;


![Apskaičiavimai](https://github.com/GudUgne/Objektinis02/blob/v1.0/Screenshot_1.png)

### [v0.5](https://github.com/GudUgne/Objektinis02/releases/tag/v0.5) - (2020-03-15)

***Pridėta***

- Sugeneruotus naujus failus apskaičiuoja, surikiuoja ir išveda trimis būdais, naudojant tris skirtingus STL konteinerius - Vector, List ir Deque;
- Nuskaitymo ir išskirstymo (į nuskriaustus ir praslydusius) funkcijų vykdymo trukmė yra apskaičiuojama naudojant chrono biblioteką;
- Kompiuterio parametrai: i7 8086k CPU, 16GB RAM, HDD

![funkcijų vykdymo trukmė](https://github.com/GudUgne/Objektinis02/blob/v0.5/89856051_914006059034704_2517563426364981248_n.png)

### [v0.4](https://github.com/GudUgne/Objektinis02/releases/tag/v0.4) - (2020-03-08)

***Pridėta***

- Dabar programa pasirinkus sprendimus "Failas -> Naujas" generuoja 1000, 10000, 100000, 1000000 ir 10000000 el. duomenų failus;
- Pasirinkus "Mediana" arba "Vidurkis" apskaičiuojamas galutinis studento balas;
- Duomenys išskirstomi į dvi grupes - Nuskriaustus, kurių balas < 5 ir Praslydusius, kurių balas >= 5;
- Išskirstyti duomenys surikiuojami pagal pavardes ir išspausdinami į du naujus failus - "Nuskriausti.txt" ir "Praslyde.txt"
- Parašoma, kiek užtruko sukurti, nuskaityti, apskaičiuoti, išskirstyti ir išvesti (į du naujus failus) visus šiuos duomenis, kiekvieno   failo trukmė rodoma atskirai;


### [v0.3](https://github.com/GudUgne/Objektinis02/releases/tag/v0.3) - (2020-02-28)

***Pridėta***

- Pridėtas "Exception handling" - įvedus nesuprantamą/neteisingą pasirinkimą ar atsakymą "bendraujant" su konsole, rodys klaidą;
- Sukurti papildomi .cpp ir.h failai;

### [v0.2](https://github.com/GudUgne/Objektinis02/releases/tag/v0.2) - (2020-02-28)

***Pridėta***

- Pakoreguotas konsolės "bendravimas" su vartotoju;
- Duomenis galima skaityti ir iš failo, studentų ar pažymių kiekiui apribojimų nėra;
- Pridėtas studentų rūšiavimas pagal vardus abecėlės tvarka (jei vardai vienodi - rikiuojama pagal pavardes);
- Duomenys (nesvarbu, iš failo ar įvesti ranka) nuo šiol yra saugomi naujame faile "Rezultatai.txt";

### [v0.1](https://github.com/GudUgne/Objektinis02/releases/tag/v.01) - (2020-02-17)

***Pridėta***

- Duomenų nuskaitymas įvedant duomenis rankiniu būdu;
- Įrašoma kiek studentų norite vesti, tada kiekvieno studento duomenys vedami po vieną;
- Įvedami vardas, pavardė;
- Vartotojui pasirinkus, egzamino ir namų darbų pažymiai yra atsitiktinai generuojami arba įvedami ranka;
- Galima pasirinkti, kiek namų darbų pažymių norite įvesti/sugeneruoti;
- Galutinių vidurkių pagal medianą arba pažymių vidurkius apskaičiavimas, irgi pasirenkama;
- Visų rezultatų išvedimas ekrane;
