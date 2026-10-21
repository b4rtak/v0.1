#include "failai.h"

using namespace std;

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