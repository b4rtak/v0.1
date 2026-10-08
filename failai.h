#pragma once
#include <string>
#include <vector>
#include <ostream>
#include "studentas.h"

using namespace std;

bool skaitytiFaila(const string& failas, vector<Studentas>& studentai);
void spausdinti(vector<Studentas>& studentai, ostream& out);