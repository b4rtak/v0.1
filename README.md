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