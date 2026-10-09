# Studentų balų skaičiuoklė

Objektinio programavimo užduotis. Programa suskaičiuoja studentų galutinį balą iš namų darbų ir egzamino.

Formulė: galutinis = 0.4 * ND + 0.6 * egzaminas. ND skaičiuojamas dviem būdais, vidurkiu ir mediana.

## Failai

- `studentas.h` / `studentas.cpp` - studento struktūra, balų skaičiavimas, įvedimas, skirstymas į grupes, rūšiavimas
- `failai.h` / `failai.cpp` - failų skaitymas, rašymas, generavimas, greičio testas
- `main.cpp` - meniu

## Meniu

1. įvesti studentą ranka (ND baigiami tuščia eilute)
2. sugeneruoti pažymius atsitiktinai
3. rodyti rezultatus (rūšiuojama pagal pasirinktą parametrą)
4. nuskaityti iš failo
5. sugeneruoti 5 failus: 1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 įrašų
6. greičio testas su sugeneruotais failais

## v0.2 greičio analizė

Studentai skirstomi į dvi grupes pagal galutinį balą (pagal vidurkį): mažiau nei 5 eina į `vargsiukai.txt`, 5 ir daugiau į `kietiakiai.txt`.

Testuojama su anksčiau sugeneruotais failais. Kiekvienas failas testuojamas 3 kartus, lentelėje vidurkis. Rūšiuota pagal pavardę.

Laikai sekundėmis:

| Įrašų | Nuskaitymas | Dalijimas | Rūšiavimas | Išvedimas į 2 failus | Iš viso |
|---|---|---|---|---|---|
| 1 000 | 0.005 | 0.000 | 0.0003 | 0.004 | 0.010 |
| 10 000 | 0.047 | 0.001 | 0.003 | 0.015 | 0.066 |
| 100 000 | 0.469 | 0.007 | 0.035 | 0.167 | 0.678 |
| 1 000 000 | 4.672 | 0.101 | 0.533 | 1.467 | 6.774 |
| 10 000 000 | 47.073 | 0.842 | 6.967 | 14.828 | 69.710 |

Failų kūrimo laikai:

| Įrašų | Laikas (s) |
|---|---|
| 1 000 | 0.008 |
| 10 000 | 0.016 |
| 100 000 | 0.157 |
| 1 000 000 | 1.582 |
| 10 000 000 | 17.924 |

Išvados:
- daugiausiai laiko užima failo nuskaitymas, su 10 mln. įrašų apie 2/3 viso laiko
- padidinus įrašų skaičių 10 kartų, laikas irgi padidėja maždaug 10 kartų
- dalijimas į grupes greitas, nes tai tik vienas perėjimas per vektorių
- failo sukūrimas greitesnis už nuskaitymą, nes rašant nereikia skaidyti eilučių ir skaičiuoti balų

Kompiuteris: AMD Ryzen 5 3600X (6 branduoliai, 3.8 GHz), 16 GB DDR4 RAM, SSD (NVMe)

## Versijos

v.pradinė - pagrindinis funkcionalumas, meniu, skaitymas iš failo

v0.1 - rūšiavimas, išvedimas į failą, įvesties tikrinimas

v0.2 - kodas išskaidytas į .h ir .cpp failus, failų generavimas, skirstymas į dvi grupes, greičio analizė