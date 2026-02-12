#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::string;
using std::vector;

const string vardai[10] = {"Jonas", "Petras", "Antanas", "Kazys", "Stasys", "Mantas", "Rytis", "Darius", "Romas", "Linas"};
const string pavardes[10] = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Stasytis", "Mantys", "Rytys", "Dariuskas", "Romaitis", "Linaitis"};

struct studentai
{
    string vardas = "A", pavarde = "B";
    vector<int> nd;
    double ndVidurkis;
    int egzaminas;
    double galutinis_vid, galutinis_med;
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
        int a = rand() % 11 - 1, b = rand() % 11 - 1;

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
void outputas(vector<studentai> &grupe)
{
    for (const auto &A : grupe)
    {
        cout << left << setw(10) << A.vardas << left << setw(10) << A.pavarde;
        cout << left << setw(10) << A.galutinis_vid << setw(10) << A.galutinis_med << endl;
    }
}
int main()
{
    srand(time(0));
    vector<studentai> grupe;
    bool iki = true;
    while (true)
    {
        cout << "MENIU: 1-ranka, 2-pazymiu generavimas, generuoti studentu vardus,pavardes,pazymius, 4- baigti darba" << endl;
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
        else
            break;

        outputas(grupe);
    }
    cout << "Programa baige darba." << endl;
    return 0;
}
