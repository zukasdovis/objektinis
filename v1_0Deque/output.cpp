#include "output.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <deque>

using std::cout;
using std::deque;
using std::endl;
using std::fixed;
using std::left;
using std::ofstream;
using std::right;
using std::setprecision;
using std::setw;
using std::string;
using std::stringstream;

void outputas(deque<studentai> &grupe)
{
    cout << fixed << setprecision(2);

    for (const auto &A : grupe)
    {
        cout << left << setw(15) << A.vardas
             << setw(15) << A.pavarde
             << setw(15) << A.galutinis_vid
             << setw(15) << A.galutinis_med << endl;
    }
}

void outputas_fr(deque<studentai> &grupe)
{
    ofstream fr("rezultatai.txt");

    fr << fixed << setprecision(2);

    for (const auto &A : grupe)
    {
        fr << left << setw(15) << A.vardas
           << setw(15) << A.pavarde
           << setw(15) << A.galutinis_vid
           << setw(15) << A.galutinis_med << endl;
    }
}