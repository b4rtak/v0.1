#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    vector<int> nd; //nd rez
    int egzaminas;
    double galutinis;
};

double vidurkis(const vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0;
    double suma = 0;
    for (int p : pazymiai) suma += p;
    return suma / pazymiai.size();
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

        int n;
        cout << "Kiek namu darbu?: ";
        cin >> n;
        for (int j = 0; j < n; j++) {
            int pazymys;
            cout << j + 1 << "-o namu darbo rezultatas: ";
            cin >> pazymys;
            s.nd.push_back(pazymys);
        }

        cout << "Egzamino rezultatas: ";
        cin >> s.egzaminas;

        s.galutinis = 0.4 * vidurkis(s.nd) + 0.6 * s.egzaminas;
        studentai.push_back(s);
    }

    return 0;
};

