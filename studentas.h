#pragma once
#include <string>
#include <vector>
#include <list>
#include <random>

using namespace std;

struct Studentas {
    string vardas, pavarde;
    vector<int> nd;
    int egzaminas = 0;
    double galVid = 0, galMed = 0;
};

double vidurkis(const vector<int>& v);
double mediana(vector<int> v);
void skaiciuoti(Studentas& s);
Studentas ivestiStudenta(bool generuoti, mt19937& gen);
void rusiuoti(vector<Studentas>& studentai, int kriterijus);
void rusiuoti(list<Studentas>& studentai, int kriterijus);

template <typename Konteineris>
void padalinti(Konteineris& studentai, Konteineris& vargsiukai, Konteineris& kietiakiai) {
    for (const auto& s : studentai) {
        if (s.galVid < 5.0) vargsiukai.push_back(s);
        else kietiakiai.push_back(s);
    }
    studentai = Konteineris();
}