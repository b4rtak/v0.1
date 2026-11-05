# Studentų balų skaičiuoklė

Objektinio programavimo užduotis. Programa skaičiuoja studentų galutinį balą (0.4 * ND + 0.6 * egzaminas, ND skaičiuojamas vidurkiu ir mediana), dalina studentus į vargšiukus (balas < 5) ir kietiakus (balas >= 5), generuoja testinius failus ir matuoja greitį su std::vector ir std::list.

## Diegimas

Reikia g++ kompiliatoriaus (Mac'e tinka clang, kuris ateina su Xcode Command Line Tools) ir make.

    git clone https://github.com/b4rtak/v0.1.git
    cd v0.1
    git switch v1.0
    make
    ./programa

make sukompiliuoja programą pagal Makefile. Komanda make clean ištrina sukompiliuotą programą ir rezultatų failus.

Windows'e, jei make neįdiegtas, galima kompiliuoti tiesiogiai:

    g++ -O2 main.cpp studentas.cpp failai.cpp -o programa
    .\programa

## Naudojimas

Paleidus programą reikia pasirinkti konteinerį: 1 - vector, 2 - list. Tada atsiranda meniu:

1 - įvesti studentą ranka (ND vedami po vieną, baigiama tuščia eilute). Įvedus parodomas studento adresas atmintyje.

2 - įvesti vardą ir pavardę, o pažymiai sugeneruojami atsitiktinai.

3 - parodyti rezultatus. Galima rinktis rūšiavimą pagal pavardę, vardą arba balą. Jei studentų daugiau nei 50, rezultatai įrašomi į rezultatai.txt.

4 - nuskaityti studentus iš failo (pvz. kursiokai.txt). Failo pirma eilutė yra antraštė, toliau vardas, pavardė, ND pažymiai ir paskutinis skaičius yra egzaminas.

5 - sugeneruoti 5 testinius failus: gen1000.txt, gen10000.txt, gen100000.txt, gen1000000.txt ir gen10000000.txt.

6 - greičio testas. Reikia pasirinkti rūšiavimo kriterijų ir dalijimo strategiją (1, 2 arba 3). Testuojami abu konteineriai su visais 5 failais, kiekvienas failas 3 kartus. Prieš tai failai turi būti sugeneruoti per 5 punktą. Vargšiukai įrašomi į vargsiukai.txt, kietiakai į kietiakiai.txt.

0 - baigti.

## Failai

studentas.h ir studentas.cpp - studento struktūra, balų skaičiavimas, įvedimas, rūšiavimas ir dalijimo strategijos.

failai.h ir failai.cpp - failų skaitymas, rašymas, generavimas ir greičio testas.

main.cpp - meniu.

Makefile - kompiliavimas su make.




## Versijos

### v.pradinė

Pirmoji versija. Studento duomenys saugomi struktūroje, ND skaičius nežinomas iš anksto (baigiama tuščia eilute). Galutinis balas skaičiuojamas vidurkiu ir mediana. Pažymius galima generuoti atsitiktinai, yra meniu.

### v.pradinė.1

Pridėtas duomenų nuskaitymas iš failo kursiokai.txt.

### v0.1

Studentai rūšiuojami pagal pavardę, stulpeliai išlygiuoti. Kai studentų daug, rezultatai rašomi į failą. Pridėtas įvesties tikrinimas (raidės vietoj skaičių). Programa atidaro dėstytojo pateiktus testavimo failus.

### v0.2

Kodas išskaidytas į .h ir .cpp failus. Programa generuoja 5 failus, dalina studentus į vargšiukus ir kietiakus, išveda juos į du failus ir matuoja kiekvieno etapo laiką. Rūšiavimo kriterijų pasirenka vartotojas.

Testuota su AMD Ryzen 5 3600X, 16 GB RAM, SSD. Laikai sekundėmis, 3 testų vidurkis, rūšiuota pagal pavardę:

| Įrašų | Nuskaitymas | Dalijimas | Rūšiavimas | Išvedimas | Iš viso |
|---|---|---|---|---|---|
| 1 000 | 0.005 | 0.000 | 0.0003 | 0.004 | 0.010 |
| 10 000 | 0.047 | 0.001 | 0.003 | 0.015 | 0.066 |
| 100 000 | 0.469 | 0.007 | 0.035 | 0.167 | 0.678 |
| 1 000 000 | 4.672 | 0.101 | 0.533 | 1.467 | 6.774 |
| 10 000 000 | 47.073 | 0.842 | 6.967 | 14.828 | 69.710 |

Daugiausiai laiko užima nuskaitymas. Padidinus įrašų 10 kartų, laikas irgi išauga maždaug 10 kartų.

### v0.3

Programa veikia su std::vector ir std::list. Funkcijos padarytos šablonais (template), kad tas pats kodas tiktų abiem konteineriams. Įvedant ranka parodomas studento adresas atmintyje.

Testuota su MacBook Air M4, 16 GB RAM, SSD. Su 10 000 000 įrašų:

| Etapas | vector | list |
|---|---|---|
| Nuskaitymas | 11.938 | 11.899 |
| Dalijimas | 0.171 | 0.325 |
| Rūšiavimas | 1.092 | 0.769 |
| Išvedimas | 2.541 | 2.545 |
| Iš viso | 15.742 | 15.538 |

Dalijimas greitesnis su vector, nes jo elementai atmintyje yra vienas šalia kito. Rūšiavimas greitesnis su list, nes perkeliamos tik rodyklės, o ne patys objektai. Bendras laikas beveik vienodas.

![Adresai](img/adresai.png)

### v1.0

Realizuotos 3 studentų dalijimo strategijos abiem konteineriams, pridėtas Makefile, sutvarkyta repozitorija. Failų generavimas pagreitintas (eilutė surenkama į vieną string ir įrašoma vienu kartu), failai uždaromi prieš matuojant laiką. Strategijų tyrimas aprašytas žemiau.

## v1.0 dalijimo strategijų tyrimas

1 strategija: studentai kopijuojami į du naujus konteinerius (vargšiukai ir kietiakai), o pradinis lieka. Taip kiekvienas studentas atmintyje yra du kartus, todėl ši strategija neefektyvi atminties atžvilgiu.

2 strategija: naudojamas tik vienas naujas konteineris. Vargšiukas nukopijuojamas į jį ir ištrinamas iš pradinio su erase, todėl pradiniame lieka tik kietiakai.

3 strategija: ta pati 2 strategija, tik su std::partition. partition vienu perėjimu perkelia kietiakus į priekį, o vargšiukus į galą. Tada vargšiukai nukopijuojami su assign ir ištrinami vienu erase nuo ribos iki galo. Iš pasiūlytų algoritmų pasirinkau partition, nes jis viską padaro per vieną perėjimą, o tvarka nesvarbi, nes po to vis tiek rūšiuojama. Būtų galima naudoti ir remove_copy_if su remove_if, bet tada konteineris pereinamas du kartus.

Testuota su MacBook Air M4, 16 GB RAM, SSD, macOS Tahoe 26.6.2. Testuota su anksčiau sugeneruotais failais, kiekvienas failas 3 kartus, laikai yra vidurkis sekundėmis. Rūšiuota pagal pavardę.

### Dalijimo į dvi grupes laikas

| Įrašų | 1 str. vector | 1 str. list | 2 str. vector | 2 str. list | 3 str. vector | 3 str. list |
|---|---|---|---|---|---|---|
| 1 000 | 0.000086 | 0.000031 | 0.000499 | 0.000170 | 0.000015 | 0.000159 |
| 10 000 | 0.000161 | 0.000133 | 0.047164 | 0.000134 | 0.000079 | 0.000140 |
| 100 000 | 0.001185 | 0.001527 | 5.119750 | 0.001226 | 0.000611 | 0.001417 |
| 1 000 000 | 0.017665 | 0.018717 | - | 0.012102 | 0.007082 | 0.014314 |
| 10 000 000 | 0.222063 | 0.243093 | - | 0.127996 | 0.083838 | 0.158706 |

2 strategijos su vector 1 000 000 ir 10 000 000 įrašų netestavau, nes jau su 100 000 įrašų tai truko apie 5 sekundes, o su milijonu būtų trukę valandas.

### Bendras programos laikas

| Įrašų | 1 str. vector | 1 str. list | 2 str. vector | 2 str. list | 3 str. vector | 3 str. list |
|---|---|---|---|---|---|---|
| 1 000 | 0.0054 | 0.0032 | 0.0232 | 0.0019 | 0.0050 | 0.0032 |
| 10 000 | 0.0191 | 0.0141 | 0.0616 | 0.0142 | 0.0182 | 0.0145 |
| 100 000 | 0.1422 | 0.1457 | 5.2666 | 0.1505 | 0.1453 | 0.1445 |
| 1 000 000 | 1.5087 | 1.5382 | - | 1.4861 | 1.5373 | 1.5189 |
| 10 000 000 | 15.7065 | 15.6414 | - | 15.1507 | 15.9576 | 15.6052 |

### Išvados

Su vector greičiausia yra 3 strategija. Su 10 000 000 įrašų ji padalina per 0.084 s, o 1 strategija per 0.222 s, tai yra apie 2.6 karto greičiau.

2 strategija su vector yra labai lėta. Kiekvienas erase iš vektoriaus vidurio paslenka visus toliau esančius elementus, todėl padidinus įrašų 10 kartų laikas išauga apie 100 kartų (10 000 įrašų - 0.047 s, 100 000 - 5.1 s).

Su list greičiausia yra 2 strategija. Sąraše erase tik perjungia rodykles tarp gretimų elementų, todėl trynimas greitas. Su 10 000 000 įrašų ji padalina per 0.128 s, kai 1 strategija per 0.243 s. 3 strategija su list lėtesnė už 2, nes partition sąraše keičia vietomis pačius studentų objektus.

Bendras programos laikas beveik nepriklauso nuo strategijos, nes apie 75% laiko užima failo nuskaitymas. Dalijimas yra mažiausia programos dalis, bet būtent ten strategijos ir konteinerio pasirinkimas labiausiai keičia rezultatą.