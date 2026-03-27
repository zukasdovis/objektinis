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
    vector<studentai> grupe;
    /// failo nuskaitymas
    clock_t start = clock();

    failu_nusk(grupe, failas);

    clock_t end = clock();
    double laikas1 = double(end - start) / CLOCKS_PER_SEC;

    cout << "Faila nuskaite per " << laikas1 << " s\n";

    vector<studentai> kietiakai, silpniakai;
    /// rusiuojam pagal galutini vidurki ir skiriam i dvi grupes
    clock_t start1 = clock();
    for (auto &x : grupe)
    {
        if (x.galutinis_vid > 5.0)
            kietiakai.push_back(x);
        else
            silpniakai.push_back(x);
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
        sort(kietiakai.begin(), kietiakai.end(), pagalVarda);
        sort(silpniakai.begin(), silpniakai.end(), pagalVarda);
        break;
    case 2:
        sort(kietiakai.begin(), kietiakai.end(), pagalPavarde);
        sort(silpniakai.begin(), silpniakai.end(), pagalPavarde);
        break;
    case 3:
        sort(kietiakai.begin(), kietiakai.end(), pagalGalutiniVid);
        sort(silpniakai.begin(), silpniakai.end(), pagalGalutiniVid);
        break;
    case 4:
        sort(kietiakai.begin(), kietiakai.end(), pagalGalutiniMed);
        sort(silpniakai.begin(), silpniakai.end(), pagalGalutiniMed);
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

    kietiakaiF << "Vardas Pavarde GalutinisMed GalutinisVid\n";
    for (auto &x : kietiakai)
    {
        kietiakaiF << x.vardas << " " << x.pavarde << " ";

        kietiakaiF << x.galutinis_med << " " << x.galutinis_vid << "\n";
    }

    silpniakaiF << "Vardas Pavarde GalutinisMed GalutinisVid\n";
    for (auto &x : silpniakai)
    {
        silpniakaiF << x.vardas << " " << x.pavarde << " ";

        silpniakaiF << x.galutinis_med << " " << x.galutinis_vid << "\n";
    }
    clock_t end2 = clock();
    double laikas3 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Faila irasyti uztruko " << laikas3 << " s\n";
    /// programa uztruko
    cout << "Programa uztruko" << laikas1 + laikas2 + laikas3 << " s\n";
}
