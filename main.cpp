#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    vector<int> nd; //nd rez
    int egzaminas;
    double galVid = 0, galMed = 0;
};

double vidurkis(const vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0;
    double suma = 0;
    for (int p : pazymiai) suma += p;
    return suma / pazymiai.size();
}

double mediana(vector<int> v) {
    if (v.empty()) return 0.0;
    sort(v.begin(), v.end());
    size_t n = v.size();
    if (n % 2 == 0) return (v[n / 2 - 1] + v[n / 2]) / 2.0;
    return v[n / 2];
}

int main() {
    vector<studentas> studentai;
    int kiekis;
    cout << "Kiek studentu?: ";
    cin >> kiekis;

    for (int i = 0; i < kiekis; i++) {
        studentas s;
        cout << "\n" << i + 1 << "-as studentas\n";
        cout << "Vardas: ";
        cin >> s.vardas;
        cout << "Pavarde: ";
        cin >> s.pavarde;

        cout << "ND rezultatai (po viena eiluteje, baigti - tuscia eilute):\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string eil;
        while (getline(cin, eil) && !eil.empty())
            s.nd.push_back(stoi(eil));
        

        cout << "Egzamino rezultatas: ";
        cin >> s.egzaminas;

        s.galVid = 0.4 * vidurkis(s.nd) + 0.6 * s.egzaminas;
        s.galMed = 0.4 * mediana(s.nd) + 0.6 * s.egzaminas;
        studentai.push_back(s);
    }

    cout << "\n" << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (vid.)" << "Galutinis (med.)\n";
    cout << string(76, '-') << "\n" << fixed << setprecision(2);
    for (const auto& s : studentai) {
        cout << left << setw(20) << s.pavarde << setw(20) << s.vardas << setw(20) << s.galVid << s.galMed << "\n";
    }

    return 0;
};

