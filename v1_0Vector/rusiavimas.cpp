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

template <typename Container>
void splitContainer(Container &grupe, Container &silpniakai)
{
    auto it = std::partition(grupe.begin(), grupe.end(), [](const studentai &s)
                             { return s.galutinis_vid >= 5.0; });

    silpniakai.insert(silpniakai.end(), it, grupe.end());
    grupe.erase(it, grupe.end());
}
void failoRusiavimas1(int kiekis)
{
    string failas = "studentai_" + to_string(kiekis) + ".txt";
    vector<studentai> grupe;
    /// failo nuskaitymas
    clock_t start = clock();

    failu_nusk(grupe, failas);

    clock_t end = clock();
    double laikas1 = double(end - start) / CLOCKS_PER_SEC;

    cout << "Faila nuskaite per " << laikas1 << " s\n";

    vector<studentai> silpniakai, kietiakai;

    clock_t start1 = clock();

    for (const auto &student : grupe)
    {
        if (student.galutinis_vid > 5.0)
        {
            kietiakai.push_back(student);
        }
        else
        {
            silpniakai.push_back(student);
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

void failoRusiavimas2(int kiekis)
{
    string failas = "studentai_" + to_string(kiekis) + ".txt";
    vector<studentai> grupe;
    /// failo nuskaitymas
    clock_t start = clock();

    failu_nusk(grupe, failas);

    clock_t end = clock();
    double laikas1 = double(end - start) / CLOCKS_PER_SEC;

    cout << "Faila nuskaite per " << laikas1 << " s\n";

    vector<studentai> silpniakai;

    clock_t start1 = clock();

    sort(grupe.begin(), grupe.end(), pagalGalutiniVid);
    for (int i = grupe.size() - 1; i >= 0; i--)
    {
        if (grupe[i].galutinis_vid > 5.0)
            break;
        silpniakai.push_back(grupe[i]);
        grupe.pop_back();
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
        sort(grupe.begin(), grupe.end(), pagalVarda);
        sort(silpniakai.begin(), silpniakai.end(), pagalVarda);
        break;
    case 2:
        sort(grupe.begin(), grupe.end(), pagalPavarde);
        sort(silpniakai.begin(), silpniakai.end(), pagalPavarde);
        break;
    case 3:
        sort(grupe.begin(), grupe.end(), pagalGalutiniVid);
        sort(silpniakai.begin(), silpniakai.end(), pagalGalutiniVid);
        break;
    case 4:
        sort(grupe.begin(), grupe.end(), pagalGalutiniMed);
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
    for (auto &x : grupe)
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

void failoRusiavimas3(int kiekis)
{
    string failas = "studentai_" + to_string(kiekis) + ".txt";
    vector<studentai> grupe;
    /// failo nuskaitymas
    clock_t start = clock();

    failu_nusk(grupe, failas);

    clock_t end = clock();
    double laikas1 = double(end - start) / CLOCKS_PER_SEC;

    cout << "Faila nuskaite per " << laikas1 << " s\n";

    vector<studentai> silpniakai;

    clock_t start1 = clock();

    splitContainer(grupe, silpniakai);

    clock_t end1 = clock();
    double laikas2 = double(end1 - start1) / CLOCKS_PER_SEC;

    cout << "Faila rusiuoti uztruko " << laikas2 << " s\n";

    cout << "Pagal ka rusiuoti? 1-varda 2-pavarde 3-vidurkis 4-mediana\n";
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        sort(grupe.begin(), grupe.end(), pagalVarda);
        sort(silpniakai.begin(), silpniakai.end(), pagalVarda);
        break;
    case 2:
        sort(grupe.begin(), grupe.end(), pagalPavarde);
        sort(silpniakai.begin(), silpniakai.end(), pagalPavarde);
        break;
    case 3:
        sort(grupe.begin(), grupe.end(), pagalGalutiniVid);
        sort(silpniakai.begin(), silpniakai.end(), pagalGalutiniVid);
        break;
    case 4:
        sort(grupe.begin(), grupe.end(), pagalGalutiniMed);
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
    for (auto &x : grupe)
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
