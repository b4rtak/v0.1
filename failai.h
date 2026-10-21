#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include "studentas.h"

using namespace std;

void generuotiFaila(const string& failas, int kiekis, mt19937& gen);

template <typename Konteineris>
bool skaitytiFaila(const string& failas, Konteineris& studentai) {
    ifstream in(failas);
    if (!in) {
        cout << "Nepavyko atidaryti failo " << failas << "\n";
        return false;
    }
    string eil;
    getline(in, eil);
    while (getline(in, eil)) {
        istringstream ss(eil);
        Studentas s;
        ss >> s.vardas >> s.pavarde;
        int x;
        while (ss >> x) s.nd.push_back(x);
        if (s.nd.empty()) continue;   
        s.egzaminas = s.nd.back();    
        s.nd.pop_back();
        skaiciuoti(s);
        s.nd.clear();                 
        studentai.push_back(s);
    }
    return true;
}

template <typename Konteineris>
void spausdinti(const Konteineris& studentai, ostream& out) {
    out << left << setw(20) << "Pavarde" << setw(20) << "Vardas"
        << setw(20) << "Galutinis (Vid.)" << "Galutinis (Med.)\n";
    out << string(76, '-') << "\n" << fixed << setprecision(2);
    for (const auto& s : studentai)
        out << left << setw(20) << s.pavarde << setw(20) << s.vardas
            << setw(20) << s.galVid << s.galMed << "\n";
}

template <typename Konteineris>
void testas(const string& failas, int kriterijus) {
    double tSk = 0, tDal = 0, tRus = 0, tRas = 0;
    for (int k = 0; k < 3; k++) {
        Konteineris studentai, vargsiukai, kietiakiai;

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