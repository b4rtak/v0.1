# Studentų galutinio balo skaičiavimas

Mano C++ programa objektinio programavimo užduočiai. Ji apskaičiuoja studentų galutinius balus pagal namų darbų ir egzamino rezultatus.

Galutinis balas skaičiuojamas taip: 0.4 × namų darbų įvertinimas + 0.6 × egzaminas. Namų darbų įvertinimas gali būti vidurkis arba mediana (programa parodo abu).

# Ką programa moka

Duomenis galima suvesti pačiam: įrašai vardą, pavardę, tada namų darbų pažymius po vieną, o kai baigi, tiesiog paspaudi Enter ant tuščios eilutės. Jei nesinori vesti pažymių patiems, programa gali juos sugeneruoti atsitiktinai. Taip pat galima nuskaityti studentus iš failo, pavyzdžiui `kursiokai.txt`.

Rezultatai surūšiuojami pagal pavardę. Jei studentų nedaug, lentelė parodoma ekrane, o jei daugiau nei 50, ji įrašoma į `rezultatai.txt`, kad nereikėtų slinkti per tūkstančius eilučių.

## Po paleidimo

Paleidus atsiranda meniu, kuriame pasirenki, ką daryti. Testavimo failus (`studentai10000.txt` ir kitus) įdėk į tą patį aplanką kaip programą.

## Versijos

**v.pradinė** – pirmoji veikianti versija: įvedimas, vidurkis ir mediana, random generavimas, meniu ir skaitymas iš failo.

**v0.1** – patobulinta versija: rūšiavimas, didelių rezultatų įrašymas į failą, apsauga nuo neteisingos įvesties ir darbas su dideliais testavimo failais.