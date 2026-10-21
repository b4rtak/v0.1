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
void spausdinti(const vector<Studentas>& studentai, ostream& out);
void testas(const string& failas, int kriterijus);

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