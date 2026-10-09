#pragma once
#include <string>
#include <vector>
#include <ostream>
#include "studentas.h"

using namespace std;

bool skaitytiFaila(const string& failas, vector<Studentas>& studentai);
void spausdinti(const vector<Studentas>& studentai, ostream& out);
void generuotiFaila(const string& failas, int kiekis, mt19937& gen);
void testas(const string& failas, int kriterijus);