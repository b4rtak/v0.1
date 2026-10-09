#include <iostream>
#include <fstream>
#include <limits>
#include "studentas.h"
#include "failai.h"

using namespace std;

int pasirinktiKriteriju()
{
    int k;
    cout << "Rusiuoti pagal: 1 - pavarde, 2 - varda, 3 - galutini bala: ";
    cin >> k;
    return k;
}

int main()
{
    vector<Studentas> studentai;
    mt19937 gen(random_device{}());
    int kiekiai[] = {1000, 10000, 100000, 1000000, 10000000};
    while (true)
    {
        cout << "\n1 - Ivesti studenta ranka\n2 - Generuoti pazymius atsitiktinai\n"
             << "3 - Rodyti rezultatus\n4 - Skaityti is failo\n"
             << "5 - Sugeneruoti 5 failus\n6 - Testuoti greiti\n0 - Baigti\nPasirinkimas: ";
        int pas;
        if (!(cin >> pas))
        {
            if (cin.eof())
                break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite skaiciu!\n";
            continue;
        }
        if (pas == 0)
            break;
        if (pas == 1 || pas == 2)
            studentai.push_back(ivestiStudenta(pas == 2, gen));
        else if (pas == 3)
        {
            rusiuoti(studentai, pasirinktiKriteriju());
            if (studentai.size() <= 50)
                spausdinti(studentai, cout);
            else
            {
                ofstream f("rezultatai.txt");
                spausdinti(studentai, f);
                cout << "Studentu daug, rezultatai irasyti i rezultatai.txt\n";
            }
        }
        else if (pas == 4)
        {
            string failas;
            cout << "Failo pavadinimas: ";
            cin >> failas;
            if (skaitytiFaila(failas, studentai))
                cout << "Is viso studentu: " << studentai.size() << "\n";
        }
        else if (pas == 5)
        {
            for (int kiekis : kiekiai)
                generuotiFaila("gen" + to_string(kiekis) + ".txt", kiekis, gen);
        }
        else if (pas == 6)
        {
            int k = pasirinktiKriteriju();
            for (int kiekis : kiekiai)
                testas("gen" + to_string(kiekis) + ".txt", k);
        }
    else cout << "Tokio pasirinkimo nera!\n";
}
return 0;
}