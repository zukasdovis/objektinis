#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

void generuotiFaila(int kiekis)
{
    std::string failas = "studentai_" + std::to_string(kiekis) + ".txt";
    std::ofstream out(failas);

    out << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 ND6 ND7 ND8 ND9 ND10 Galutinis\n";

    for (int i = 1; i <= kiekis; i++)
    {

        out << "Vardas" << i << " "
            << "Pavarde" << i << " ";

        for (int i = 0; i < 10; i++)
        {
            int paz = rand() % 10 + 1;
            out << paz << " ";
        }
        int galutinis = rand() % 10 + 1;
        out << galutinis << "\n";
    }

    out.close();
}

void generuotiVisus()
{
    clock_t start = clock();
    generuotiFaila(1000);
    generuotiFaila(10000);
    generuotiFaila(100000);
    generuotiFaila(1000000);
    generuotiFaila(10000000);

    clock_t end = clock();
    double laikas = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Failai sukurtas per " << laikas << " s\n";
}
