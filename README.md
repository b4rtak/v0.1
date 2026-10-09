# Studentų balų skaičiuoklė v0.2

Programa sugeneruoja penkis studentų failus (1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 įrašų), juos nuskaito, suskirsto studentus į dvi grupes ir išveda į du failus. Studentai, kurių galutinis balas mažesnis nei 5, įrašomi į vargsiukai.txt, o kiti į kietiakiai.txt. Galutinis balas skaičiuojamas taip: 0.4 * ND vidurkis + 0.6 * egzaminas.

Kodas išskaidytas į kelis failus. studentas.h ir studentas.cpp yra studento struktūra, balų skaičiavimas, skirstymas ir rūšiavimas. failai.h ir failai.cpp yra failų generavimas, skaitymas, rašymas ir testavimas. main.cpp yra meniu.

Paleidimas: g++ -O2 main.cpp studentas.cpp failai.cpp -o programa

Meniu 5 sugeneruoja failus, meniu 6 paleidžia greičio testą.

## Testavimas

Kiekvienas failas testuotas 3 kartus, rezultatai yra vidurkis sekundėmis. Studentai rūšiuoti pagal pavardę.

Failų kūrimas:
1 000 įrašų - 0.008 s
10 000 įrašų - 0.016 s
100 000 įrašų - 0.157 s
1 000 000 įrašų - 1.582 s
10 000 000 įrašų - 17.924 s

1 000 įrašų: nuskaitymas 0.005 s, dalijimas 0.000 s, rūšiavimas 0.0003 s, išvedimas 0.004 s, iš viso 0.010 s

10 000 įrašų: nuskaitymas 0.047 s, dalijimas 0.001 s, rūšiavimas 0.003 s, išvedimas 0.015 s, iš viso 0.066 s

100 000 įrašų: nuskaitymas 0.469 s, dalijimas 0.007 s, rūšiavimas 0.035 s, išvedimas 0.167 s, iš viso 0.678 s

1 000 000 įrašų: nuskaitymas 4.672 s, dalijimas 0.101 s, rūšiavimas 0.533 s, išvedimas 1.467 s, iš viso 6.774 s

10 000 000 įrašų: nuskaitymas 47.073 s, dalijimas 0.842 s, rūšiavimas 6.967 s, išvedimas 14.828 s, iš viso 69.710 s

Daugiausiai laiko užima failo nuskaitymas. Padidinus įrašų skaičių 10 kartų, laikas irgi išauga maždaug 10 kartų.

Kompiuteris: AMD Ryzen 5 3600X, 16 GB RAM, SSD