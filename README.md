# Projekto aprašymas
Programa skirta studentų akademinių pasiekimų informacijos apdorojimui. Vartotojas gali rinktis, ar studentų informaciją įveda jis pats, ar informacija yra generuojama automatiškai. Programa leidžia generuoti, nuskaityti studentų failus bei atlikti skirtingus programos veikimo laiko testus. Programos veikimo spartos testavimui naudojami skirtingi konteineriai.

# Naudojimosi instrukcija
1. Nusiklonuokite repozitoriją:
   
   ```
   git clone https://github.com/zukasdovis/objektinis.git
   ```

2. Įsidiekite CMake (Linux(Ubuntu/Debian))

   ```
   sudo apt update
   sudo apt install cmake
   ```

3. Projekto kompiliavimas su CMake
   
   ```
   cd OOP-1
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Paleiskite programą
   
   ```
   ./programa1
   ```
   
# Kompiuterio specifikacijos:

|       CPU      |  RAM |    SSD     | 
|----------------|------|------------| 
| Intel i5-12450HX | 16GB | NVMe 256GB |      
--------------------------------------

# Tyrimo rezultatai:

- Šiame tyrime analizuojamas skirtingų konteinerių (vector, list, deque) efektyvumas apdorojant studentų duomenis.
- Eksperimentuose naudojami skirtingo dydžio failai (nuo 1000 iki 10000000 studentų įrašų)
- Pirmoje strategijoje studentai yra padalinami į du naujus konteinerius
- Antroje strategijoje iš bendro studentų koneteinerio į naują konteinerį yra perkeliami tik nepažangūs studentai ir jie tuo pačaiu yra ištrinami iš pagrindinio konteinerio. Tai sutaupo atminties.
- Trečioje strategijoje, taip pat, iš bendro studentų koneteinerio į naują konteinerį yra perkeliami tik nepažangūs studentai ir jie tuo pačiu yra ištrinami iš pagrindinio konteinerio, bet šiuo atveju yra naudojami efektyvūs algoritmai


# 1 Strategija, pilnas tyrimas
| Container | Size       | Read (s) | Sort (s) | Write (s) | Total (s) |
| --------- | ---------- | -------- | -------- | --------- | --------- |
| Deque     | 1,000      | 0.008    | 0        | 0.042     | 0.050     |
| Deque     | 10,000     | 0.036    | 0.003    | 0.012     | 0.051     |
| Deque     | 100,000    | 0.326    | 0.036    | 0.086     | 0.448     |
| Deque     | 1,000,000  | 2.335    | 0.267    | 2.111     | 4.713     |
| Deque     | 10,000,000 | 29.953   | 2.768    | 11.485    | 44.206    |
| List      | 1,000      | 0.031    | 0        | 0.001     | 0.032     |
| List      | 10,000     | 0.052    | 0        | 0.001     | 0.053     |
| List      | 100,000    | 0.337    | 0        | 0.001     | 0.338     |
| List      | 1,000,000  | 3.449    | 0        | 0         | 3.449     |
| List      | 10,000,000 | 36.628   | 0        | 0.021     | 36.649    |
| Vector    | 1,000      | 0.005    | 0        | 0.041     | 0.046     |
| Vector    | 10,000     | 0.058    | 0.008    | 0.011     | 0.077     |
| Vector    | 100,000    | 0.410    | 0.075    | 0.142     | 0.627     |
| Vector    | 1,000,000  | 3.707    | 0.661    | 0.999     | 5.367     |
| Vector    | 10,000,000 | 60.129   | 11.309   | 10.895    | 82.333    |
# 2 Strategija, tik rušiavimas
| Container | Size       | Sort (s) |
| --------- | ---------- | -------- |
| Vector    | 1,000      | 0.072    |
| Vector    | 10,000     | 3.267    |
| Vector    | 100,000    | 0.285    |
| Vector    | 1,000,000  | 6.604    |
| Vector    | 10,000,000 | 50.557   |
| Deque     | 1,000      | 0.003    |
| Deque     | 10,000     | 0.027    |
| Deque     | 100,000    | 0.354    |
| Deque     | 1,000,000  | 4.715    |
| Deque     | 10,000,000 | 73.127   |
| List      | 1,000      | 0        |
| List      | 10,000     | 0.005    |
| List      | 100,000    | 0.109    |
| List      | 1,000,000  | 1.324    |
| List      | 10,000,000 | 28.173   |
# 3 Strategija, tik rušiavimas
| Container | Size       | Sort (s) |
| --------- | ---------- | -------- |
| Vector    | 1,000      | 0        |
| Vector    | 10,000     | 0.003    |
| Vector    | 100,000    | 0.023    |
| Vector    | 1,000,000  | 0.256    |
| Vector    | 10,000,000 | 2.350    |
| Deque     | 1,000      | 0.001    |
| Deque     | 10,000     | 0.003    |
| Deque     | 100,000    | 0.048    |
| Deque     | 1,000,000  | 0.312    |
| Deque     | 10,000,000 | 2.860    |
| List      | 1,000      | 0.001    |
| List      | 10,000     | 0.002    |
| List      | 100,000    | 0.035    |
| List      | 1,000,000  | 0.537    |
| List      | 10,000,000 | 3.817    |
