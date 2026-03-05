#include "output.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void outputas(vector<studentai> &grupe)
{
    cout << fixed << setprecision(2);

    for (const auto &A : grupe)
    {
        cout << left << setw(10) << A.vardas
             << setw(10) << A.pavarde
             << setw(10) << A.galutinis_vid
             << setw(10) << A.galutinis_med << endl;
    }
}

void outputas_fr(vector<studentai> &grupe)
{
    ofstream fr("rezultatai.txt");

    fr << fixed << setprecision(2);

    for (const auto &A : grupe)
    {
        fr << left << setw(10) << A.vardas
           << setw(10) << A.pavarde
           << setw(10) << A.galutinis_vid
           << setw(10) << A.galutinis_med << endl;
    }
}
