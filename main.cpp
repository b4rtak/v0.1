#include <iostream>
#include <fstream>
#include <limits>
#include "studentas.h"
#include "failai.h"

using namespace std;

int main() {
    vector<Studentas> studentai;
    mt19937 gen(random_device{}());
    while (true) {
        cout << "\n1 - Ivesti studenta ranka\n2 - Generuoti pazymius atsitiktinai\n"
             << "3 - Rodyti rezultatus\n4 - Skaityti is failo\n0 - Baigti\nPasirinkimas: ";
        int pas;
        if (!(cin >> pas)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu!\n";
            continue;
        }
        if (pas == 0) break;
        if (pas == 1 || pas == 2) studentai.push_back(ivestiStudenta(pas == 2, gen));
        else if (pas == 3) {
            if (studentai.size() <= 50) spausdinti(studentai, cout);
            else {
                ofstream f("rezultatai.txt");
                spausdinti(studentai, f);
                cout << "Studentu daug, rezultatai irasyti i rezultatai.txt\n";
            }
        } else if (pas == 4) {
            string failas;
            cout << "Failo pavadinimas: ";
            cin >> failas;
            if (skaitytiFaila(failas, studentai))
                cout << "Is viso studentu: " << studentai.size() << "\n";
        } else cout << "Tokio pasirinkimo nera!\n";
    }
    return 0;
}