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
        studentai.push_back(s);
    }
    return true;
}

void spausdinti(vector<Studentas>& studentai, ostream& out) {
    sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        if (a.pavarde != b.pavarde) return a.pavarde < b.pavarde;
        return a.vardas < b.vardas;
    });
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