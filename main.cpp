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

        studentai.push_back(s);
    }

    return 0;
};