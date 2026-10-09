#pragma once
#include <string>
#include <vector>
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
void padalinti(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai);
void rusiuoti(vector<Studentas>& studentai, int kriterijus);