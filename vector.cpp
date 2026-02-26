#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::ws;
using namespace std::chrono;

const string vardai[10] = {"Jonas", "Petras", "Antanas", "Kazys", "Stasys", "Mantas", "Rytis", "Darius", "Romas", "Linas"};
const string pavardes[10] = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Stasytis", "Mantys", "Rytys", "Dariuskas", "Romaitis", "Linaitis"};

struct studentai
{
    string vardas = "A", pavarde = "B";
    vector<int> nd;
    double ndVidurkis = 0.0;
    int egzaminas = 0;
    double galutinis_vid = 0.0, galutinis_med = 0.0;
};
/// VISKAS VESTI RANKA
void ranka(vector<studentai> &grupe)
{
    studentai A;

    while (true)
    {
        cout << "Iveskite varda ir pavarde, kad baigtumete, iveskite \"0 0\": ";
        cin >> A.vardas >> A.pavarde;
        if (A.vardas == "0" && A.pavarde == "0")
        {
            break;
        }
        cout << "Iveskite pazymius (iveskite skaiciu daugiau uz 10 kad baigtumete): ";
        int x;
        int sum = 0;
        int n = 0;
        while (true)
        {
            cin >> x;
            if (x > 10)
            {
                break;
            }
            sum += x;
            n++;
            A.nd.push_back(x);
        }
        if (n == 0)
        {
            A.ndVidurkis = 0;
        }
        else
            A.ndVidurkis = (double)sum / n;

        cout << "Iveskite egzamino pazymi: ";
        cin >> A.egzaminas;

        sort(A.nd.begin(), A.nd.end());
        double median;
        if (n != 0)
        {
            if (n % 2 == 0)
            {
                median = (A.nd[n / 2 - 1] + A.nd[n / 2]) / 2.0;
            }
            else
            {
                median = A.nd[n / 2];
            }
        }
        else
        {
            median = 0;
        }

        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;
        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;

        grupe.push_back(A);
    }
}
/// TIK PAZYMIU GENERAVIMAS
void pazymiu_gen(vector<studentai> &grupe)
{
    while (true)
    {
        studentai A;
        cout << "Iveskite varda ir pavarde, kad baigtumete, iveskite \"0 0\": ";
        cin >> A.vardas >> A.pavarde;

        if (A.vardas == "0" && A.pavarde == "0")
        {
            break;
        }

        cout << "Iveskite kiek pazymiu generuoti: ";
        int kiek, sum = 0, n = 0;
        cin >> kiek;
        while (kiek--)
        {
            int x = rand() % 11;

            sum += x;
            n++;
            A.nd.push_back(x);
        }
        if (n == 0)
        {
            A.ndVidurkis = 0;
        }
        else
            A.ndVidurkis = (double)sum / n;

        A.egzaminas = rand() % 11;

        sort(A.nd.begin(), A.nd.end());
        double median;
        if (n != 0)
        {
            if (n % 2 == 0)
            {
                median = (A.nd[n / 2 - 1] + A.nd[n / 2]) / 2.0;
            }
            else
            {
                median = A.nd[n / 2];
            }
        }
        else
        {
            median = 0;
        }

        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;
        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;

        grupe.push_back(A);
    }
}
/// VISKO GENERAVIMAS
void visk_gen(vector<studentai> &grupe)
{
    cout << "Iveskite kiek mokiniu vesite: ";
    int stud;
    cin >> stud;
    while (stud--)
    {
        studentai A;
        int a = rand() % 10, b = rand() % 10;

        A.vardas = vardai[a];
        A.pavarde = pavardes[b];

        cout << "Iveskite kiek pazymiu generuoti: ";
        int kiek, sum = 0, n = 0;
        cin >> kiek;
        while (kiek--)
        {
            int x = rand() % 11;

            sum += x;
            n++;
            A.nd.push_back(x);
        }
        if (n == 0)
        {
            A.ndVidurkis = 0;
        }
        else
            A.ndVidurkis = (double)sum / n;

        A.egzaminas = rand() % 11;

        sort(A.nd.begin(), A.nd.end());
        double median;
        if (n != 0)
        {
            if (n % 2 == 0)
            {
                median = (A.nd[n / 2 - 1] + A.nd[n / 2]) / 2.0;
            }
            else
            {
                median = A.nd[n / 2];
            }
        }
        else
        {
            median = 0;
        }

        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;
        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;

        grupe.push_back(A);
    }
}

/// NUSKAITYMAS IS FAILO
void failu_nusk(vector<studentai> &grupe, string failas)
{
    auto start = high_resolution_clock::now();

    ifstream fd(failas);
    if (!fd)
    {
        cout << "Nepavyko atidaryti failo\n";
        return;
    }
    string line, niekas;
    int n = 0;
    getline(fd, line);
    stringstream ss(line);
    ss >> niekas >> ws >> niekas >> ws;
    while (ss >> niekas >> ws)
    {
        n++;
    }
    n--;
    while (getline(fd, line))
    {
        studentai A;
        stringstream ss(line);
        ss >> A.vardas >> A.pavarde;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            ss >> x;
            A.nd.push_back(x);
            sum += x;
        }
        if (n == 0)
        {
            A.ndVidurkis = 0;
        }
        else
            A.ndVidurkis = (double)sum / n;

        sort(A.nd.begin(), A.nd.end());
        double median;

        if (n != 0)
        {
            if (n % 2 == 0)
            {
                median = (A.nd[n / 2 - 1] + A.nd[n / 2]) / 2.0;
            }
            else
            {
                median = A.nd[n / 2];
            }
        }
        else
        {
            median = 0;
        }
        ss >> A.egzaminas;

        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;
        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;
        grupe.push_back(A);
    }
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "10 000 000 elementų užpildymas užtruko: " << diff.count() << " s\n";
    cout << "10 000 000 elementų užpildymas užtruko: " << duration_cast<milliseconds>(end - start).count() << " msec\n";
}

/// RUSIAVIMAS
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

void outputas(vector<studentai> &grupe)
{
    cout << std::fixed << std::setprecision(2);
    for (const auto &A : grupe)
    {
        cout << left << setw(20) << A.vardas << left << setw(20) << A.pavarde;
        cout << left << setw(20) << A.galutinis_vid << setw(20) << A.galutinis_med << endl;
    }
}

int main()
{
    srand(time(0));

    vector<studentai> grupe;
    grupe.reserve(1000000);
    while (true)
    {
        cout << "MENIU: 1-ranka, 2-pazymiu generavimas, 3-generuoti studentu vardus,pavardes,pazymius, 5-baigti darba, 4-nuskaityti is failo, 6-rusiuoti pagal varda, 7-rusiuoti pagal pavarde, 8-rusiuoti pagal galutini vidurki, 9-rusiuoti pagal galutini mediana" << endl;
        int x;
        cin >> x;

        if (x == 1)
        {
            ranka(grupe);
        }
        else if (x == 2)
        {
            pazymiu_gen(grupe);
        }
        else if (x == 3)
        {
            visk_gen(grupe);
        }
        else if (x == 4)
        {
            string failas;
            cout << "Iveskite failo pavadinima: ";
            cin >> failas;
            failu_nusk(grupe, failas);
        }
        else if (x == 6)
        {
            sort(grupe.begin(), grupe.end(), pagalVarda);
        }
        else if (x == 7)
        {
            sort(grupe.begin(), grupe.end(), pagalPavarde);
        }
        else if (x == 8)
        {
            sort(grupe.begin(), grupe.end(), pagalGalutiniVid);
        }
        else if (x == 9)
        {
            sort(grupe.begin(), grupe.end(), pagalGalutiniMed);
        }
        else
            break;

        outputas(grupe);
    }
    cout << "Programa baige darba." << endl;
    return 0;
}
