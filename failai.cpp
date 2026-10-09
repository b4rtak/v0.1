#include "failai.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

bool skaitytiFaila(const string& failas, vector<Studentas>& studentai) {
    ifstream in(failas);
    if (!in) {
        cout << "Nepavyko atidaryti failo " << failas << "\n";
        return false;
    }
    string eil;
    getline(in, eil);  // praleidziama antraste
    while (getline(in, eil)) {
        istringstream ss(eil);
        Studentas s;
        ss >> s.vardas >> s.pavarde;
        int x;
        while (ss >> x) s.nd.push_back(x);
        if (s.nd.empty()) continue;   // tuscia ar bloga eilute
        s.egzaminas = s.nd.back();    // paskutinis skaicius - egzaminas
        s.nd.pop_back();
        skaiciuoti(s);
        s.nd.clear();                 // ND cia nebereikalingi, todel juos galima ismest, kad nenaudot memory
        studentai.push_back(s);
    }
    return true;
}

void spausdinti(const vector<Studentas>& studentai, ostream& out) {
    out << left << setw(20) << "Pavarde" << setw(20) << "Vardas"
        << setw(20) << "Galutinis (Vid.)" << "Galutinis (Med.)\n";
    out << string(76, '-') << "\n" << fixed << setprecision(2);
    for (const auto& s : studentai)
        out << left << setw(20) << s.pavarde << setw(20) << s.vardas
            << setw(20) << s.galVid << s.galMed << "\n";
}
void generuotiFaila(const string& failas, int kiekis, mt19937& gen) {
    clock_t pradzia = clock();
    uniform_int_distribution<int> balas(1, 10);
    ofstream out(failas);
    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int j = 1; j <= 15; j++) out << setw(6) << "ND" + to_string(j);
    out << "Egz.\n";
    for (int i = 1; i <= kiekis; i++) {
        out << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i);
        for (int j = 0; j < 15; j++) out << setw(6) << balas(gen);
        out << balas(gen) << "\n";
    }
    double laikas = double(clock() - pradzia) / CLOCKS_PER_SEC;
    cout << failas << " sukurtas per " << laikas << " s\n";
}

void testas(const string& failas, int kriterijus) {
    double tSk = 0, tDal = 0, tRus = 0, tRas = 0;
    for (int k = 0; k < 3; k++) {
        vector<Studentas> studentai, vargsiukai, kietiakiai;

        clock_t t = clock();
        if (!skaitytiFaila(failas, studentai)) return;
        tSk += double(clock() - t) / CLOCKS_PER_SEC;

        t = clock();
        padalinti(studentai, vargsiukai, kietiakiai);
        tDal += double(clock() - t) / CLOCKS_PER_SEC;

        t = clock();
        rusiuoti(vargsiukai, kriterijus);
        rusiuoti(kietiakiai, kriterijus);
        tRus += double(clock() - t) / CLOCKS_PER_SEC;

        t = clock();
        ofstream f1("vargsiukai.txt"), f2("kietiakiai.txt");
        spausdinti(vargsiukai, f1);
        spausdinti(kietiakiai, f2);
        tRas += double(clock() - t) / CLOCKS_PER_SEC;
    }
    cout << "\n" << failas << " (3 testu vidurkis):\n"
         << "Nuskaitymas:          " << tSk / 3 << " s\n"
         << "Dalijimas i 2 grupes: " << tDal / 3 << " s\n"
         << "Rusiavimas:           " << tRus / 3 << " s\n"
         << "Isvedimas i 2 failus: " << tRas / 3 << " s\n"
         << "Is viso:              " << (tSk + tDal + tRus + tRas) / 3 << " s\n";
}