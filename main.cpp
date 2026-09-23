#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    vector<int> nd;     // nd rez
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

studentas ivestistudenta(bool generuoti, mt19937& gen) {
    studentas s;
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

void skaitytifaila(const string& failas, vector<studentas>& studentai) {
    ifstream in(failas);
    if (!in) {
        cout << "Nepavyko atidaryti failo " << failas << "\n";
        return;
    }
    string eil;
    getline(in, eil);  // praleidzia antraste
    while (getline(in, eil)) {
        istringstream ss(eil);
        studentas s;
        ss >> s.vardas >> s.pavarde;
        int x;
        while (ss >> x) s.nd.push_back(x);
        if (s.nd.empty()) continue;   // tuscia arba bloga eilute
        s.egzaminas = s.nd.back();    // paskutinis skaicius - egzaminas
        s.nd.pop_back();
        skaiciuoti(s);
        studentai.push_back(s);
    }
    cout << "Is viso studentu: " << studentai.size() << "\n";
}

void spausdinti(vector<studentas>& studentai, ostream& out) {
        sort(studentai.begin(), studentai.end(), [](const studentas& a, const studentas& b) {
        if (a.pavarde != b.pavarde) return a.pavarde < b.pavarde;
        return a.vardas < b.vardas;
    });
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
        cout << "\n1 - Ivesti studenta ranka\n2 - Generuoti pazymius atsitiktinai\n" << "3 - Rodyti rezultatus\n4 - Skaityti is failo\n0 - Baigti\nPasirinkimas: ";
        int pas;
        if (!(cin >> pas)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu\n";
            continue;
        }
        if (pas == 0) break;
        if (pas == 1 || pas == 2) studentai.push_back(ivestistudenta(pas == 2, gen));
                else if (pas == 3) {
            if (studentai.size() <= 50) spausdinti(studentai, cout);
            else {
                ofstream f("rezultatai.txt");
                spausdinti(studentai, f);
                cout << "Studentu daug, rezultatai irasyti i rezultatai.txt\n";
            }
        }
        else if (pas == 4) {
            string failas;
            cout << "Failo pavadinimas: ";
            cin >> failas;
            skaitytifaila(failas, studentai);
        }
        else cout << "Tokio pasirinkimo nera\n";
    }
    return 0;
}

