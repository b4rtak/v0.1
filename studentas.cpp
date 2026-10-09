#include "studentas.h"
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

double vidurkis(const vector<int>& v) {
    if (v.empty()) return 0.0;
    double suma = 0;
    for (int p : v) suma += p;
    return suma / v.size();
}

double mediana(vector<int> v) {
    if (v.empty()) return 0.0;
    sort(v.begin(), v.end());
    size_t n = v.size();
    if (n % 2 == 0) return (v[n / 2 - 1] + v[n / 2]) / 2.0;
    return v[n / 2];
}

void skaiciuoti(Studentas& s) {
    s.galVid = 0.4 * vidurkis(s.nd) + 0.6 * s.egzaminas;
    s.galMed = 0.4 * mediana(s.nd) + 0.6 * s.egzaminas;
}

Studentas ivestiStudenta(bool generuoti, mt19937& gen) {
    Studentas s;
    cout << "Vardas: ";
    cin >> s.vardas;
    cout << "Pavarde: ";
    cin >> s.pavarde;
    if (generuoti) {
        uniform_int_distribution<int> balas(1, 10);
        int n = balas(gen);
        for (int i = 0; i < n; i++) s.nd.push_back(balas(gen));
        s.egzaminas = balas(gen);
    } else {
        cout << "ND rezultatai (po viena eiluteje, baigti - tuscia eilute):\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string eil;
        while (getline(cin, eil) && !eil.empty()) {
            try { s.nd.push_back(stoi(eil)); }
            catch (...) { cout << "Netinkamas skaicius, praleidziama\n"; }
        }
        cout << "Egzamino rezultatas: ";
        while (!(cin >> s.egzaminas)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu: ";
        }
    }
    skaiciuoti(s);
    return s;
} 
void padalinti(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakiai) {
    for (const auto& s : studentai) {
        if (s.galVid < 5.0) vargsiukai.push_back(s);
        else kietiakiai.push_back(s);
    }
    studentai.clear();
    studentai.shrink_to_fit();
}
bool pagalPavarde(const Studentas& a, const Studentas& b) { return a.pavarde < b.pavarde; }
bool pagalVarda(const Studentas& a, const Studentas& b) { return a.vardas < b.vardas; }
bool pagalBala(const Studentas& a, const Studentas& b) { return a.galVid > b.galVid; }

void rusiuoti(vector<Studentas>& studentai, int kriterijus) {
    if (kriterijus == 2) sort(studentai.begin(), studentai.end(), pagalVarda);
    else if (kriterijus == 3) sort(studentai.begin(), studentai.end(), pagalBala);
    else sort(studentai.begin(), studentai.end(), pagalPavarde);
}