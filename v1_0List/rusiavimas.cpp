#include "rusiavimas.h"
using namespace std;
bool pagalVarda(const studentai &A, const studentai &B)
{
    return A.vardas < B.vardas;
}

bool pagalPavarde(const studentai &A, const studentai &B)
{
    return A.pavarde < B.pavarde;
}

bool pagalGalutiniVid(const studentai &A, const studentai &B)
{
    return A.galutinis_vid < B.galutinis_vid;
}

bool pagalGalutiniMed(const studentai &A, const studentai &B)
{
    return A.galutinis_med < B.galutinis_med;
}

void failoRusiavimas(int kiekis)
{
    string failas = "studentai_" + to_string(kiekis) + ".txt";
    list<studentai> grupe;
    /// failo nuskaitymas
    clock_t start = clock();

    failu_nusk(grupe, failas);

    clock_t end = clock();
    double laikas1 = double(end - start) / CLOCKS_PER_SEC;

    cout << "Faila nuskaite per " << laikas1 << " s\n";

    list<studentai> kietiakai;

    clock_t start1 = clock();
    grupe.sort(pagalGalutiniVid);
    for (auto it = grupe.begin(); it != grupe.end();)
    {
        if (it->galutinis_vid > 5.0)
        {
            kietiakai.push_back(*it);
            it = grupe.erase(it);
        }
        else
        {
            ++it;
        }
    }

    clock_t end1 = clock();
    double laikas2 = double(end1 - start1) / CLOCKS_PER_SEC;

    cout << "Faila rusiuoti uztruko " << laikas2 << " s\n";

    cout << "Pagal ka rusiuoti? 1-varda 2-pavarde 3-vidurkis 4-mediana\n";
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        grupe.sort(pagalVarda);
        kietiakai.sort(pagalVarda);
        break;
    case 2:
        grupe.sort(pagalPavarde);
        kietiakai.sort(pagalPavarde);
        break;
    case 3:
        grupe.sort(pagalGalutiniVid);
        kietiakai.sort(pagalGalutiniVid);
        break;
    case 4:
        grupe.sort(pagalGalutiniMed);
        kietiakai.sort(pagalGalutiniMed);
        break;
    default:
        cout << "Neteisinga ivestis\n";
        return;
    }

    /// rusiuotu failu irasymas
    clock_t start2 = clock();

    string kietiakaiFailas = "kietiakai_" + to_string(kiekis) + ".txt";
    string silpniakaiFailas = "silpniakai_" + to_string(kiekis) + ".txt";
    ofstream kietiakaiF(kietiakaiFailas);
    ofstream silpniakaiF(silpniakaiFailas);

    kietiakaiF << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 ND6 ND7 ND8 ND9 ND10 Galutinis\n";
    for (auto &x : kietiakai)
    {
        kietiakaiF << x.vardas << " " << x.pavarde << " ";
        for (auto &y : x.nd)
            kietiakaiF << y << " ";
        kietiakaiF << x.egzaminas << "\n";
    }

    silpniakaiF << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 ND6 ND7 ND8 ND9 ND10 Galutinis\n";
    for (auto &x : grupe)
    {
        silpniakaiF << x.vardas << " " << x.pavarde << " ";
        for (auto &y : x.nd)
            silpniakaiF << y << " ";
        silpniakaiF << x.egzaminas << "\n";
    }
    clock_t end2 = clock();
    double laikas3 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Faila irasyti uztruko " << laikas3 << " s\n";
    /// programa uztruko
    cout << "Programa uztruko" << laikas1 + laikas2 + laikas3 << " s\n";
}