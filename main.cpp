#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    vector<int> nd;     // namu darbu rezultatai
    int egzaminas = 0;
    double galVid = 0, galMed = 0;
};

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

void skaiciuoti(studentas& s) {
    s.galVid = 0.4 * vidurkis(s.nd) + 0.6 * s.egzaminas;
    s.galMed = 0.4 * mediana(s.nd) + 0.6 * s.egzaminas;
}

Studentas ivestistudenta(bool generuoti, mt19937& gen) {
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
        while (getline(cin, eil) && !eil.empty())
            s.nd.push_back(stoi(eil));
        cout << "Egzamino rezultatas: ";
        cin >> s.egzaminas;
    }
    skaiciuoti(s);
    return s;
}

void spausdinti(vector<Studentas>& studentai, ostream& out) {
    out << left << setw(20) << "Pavarde" << setw(20) << "Vardas"
        << setw(20) << "Galutinis (vid.)" << "Galutinis (med.)\n";
    out << string(76, '-') << "\n" << fixed << setprecision(2);
    for (const auto& s : studentai)
        out << left << setw(20) << s.pavarde << setw(20) << s.vardas
            << setw(20) << s.galVid << s.galMed << "\n";
}

int main() {
    vector<studentas> studentai;
    mt19937 gen(random_device{}());
    while (true) {
        cout << "\n1 - Ivesti studenta ranka\n2 - Generuoti pazymius atsitiktinai\n"
             << "3 - Rodyti rezultatus\n0 - Baigti\nPasirinkimas: ";
        int pas;
        cin >> pas;
        if (pas == 0) break;
        if (pas == 1 || pas == 2) studentai.push_back(ivestistudenta(pas == 2, gen));
        else if (pas == 3) spausdinti(studentai, cout);
        else cout << "Tokio pasirinkimo nera\n";
    }
    return 0;
}

