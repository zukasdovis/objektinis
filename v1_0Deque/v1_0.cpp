#include <bits/stdc++.h>

#include "studentas.h"
#include "ivedimas.h"
#include "failai.h"
#include "rusiavimas.h"
#include "output.h"
#include "generatorius.h"
#include "tyrimai.h"

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::ifstream;
using std::left;
using std::ofstream;
using std::right;
using std::setw;
using std::string;
using std::stringstream;
using std::ws;
using namespace std::chrono;
using std::exception;
using std::runtime_error;

int main()
{
    srand(time(0));

    deque<studentai> grupe;

    while (true)
    {
        cout << "1-ranka 2-generuoti pazymius 3-viska generuoti 4-skaityti faila\n";
        cout << "6-rusiuoti varda 7-pavarde 8-vidurkis 9-mediana\n";
        cout << "10-i faila 11-i ekrana 12-atlikti tyrimus 5-baigti\n";

        int x;

        try
        {
            cin >> x;

            if (!cin)
                throw runtime_error("Neteisinga ivestis");
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        try
        {
            if (x == 1)
                ranka(grupe);

            else if (x == 2)
                pazymiu_gen(grupe);

            else if (x == 3)
                visk_gen(grupe);

            else if (x == 4)
            {
                string failas;
                cout << "Iveskite failo pavadinima: ";
                cin >> failas;

                failu_nusk(grupe, failas);
            }

            else if (x == 6)
                sort(grupe.begin(), grupe.end(), pagalVarda);

            else if (x == 7)
                sort(grupe.begin(), grupe.end(), pagalPavarde);

            else if (x == 8)
                sort(grupe.begin(), grupe.end(), pagalGalutiniVid);

            else if (x == 9)
                sort(grupe.begin(), grupe.end(), pagalGalutiniMed);

            else if (x == 10)
                outputas_fr(grupe);

            else if (x == 11)
                outputas(grupe);

            else if (x == 12)
                tyrimai();

            else
                break;
        }
        catch (exception &e)
        {
            cout << "Klaida: " << e.what() << endl;
        }
    }

    cout << "Programa baige darba" << endl;

    return 0;
}