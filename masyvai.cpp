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

struct studentai
{
    string vardas = "A", pavarde = "B";
    int *nd;
    int n;
    double ndVidurkis;
    int egzaminas;
    double galutinis_vid, galutinis_med;
};

void inputas(vector<studentai> &grupe)
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

        cout << " Ar norite generuoti atsitiktinius pazymius? (1 - taip, 0 - ne) ";

        int tikr;
        cin >> tikr;
        int sum = 0;
        int n = 0;
        /// Jei NENORI generuoti
        if (tikr == 0)
        {
            int dydis = 1;
            int *tarp = new int[dydis];
            cout << "Iveskite mokinio pazymius, kad baigtumete, iveskite skaiciu daugiau uz 10: ";
            while (true)
            {
                int x;
                cin >> x;

                if (x > 10)
                {
                    break;
                }
                if (n == dydis)
                {
                    int *naujas = new int[dydis * 2];
                    dydis *= 2;
                    for (int i = 0; i < n; i++)
                    {
                        naujas[i] = tarp[i];
                    }
                    delete[] tarp;
                    tarp = naujas;
                }
                sum += x;
                n++;
                tarp[n - 1] = x;
            }
            A.nd = tarp;
            A.n = n;
            if (n == 0)
            {
                A.ndVidurkis = 0;
            }
            else
                A.ndVidurkis = (double)sum / n;

            cout << "iveskite egzamino pazymi: ";
            cin >> A.egzaminas;
        }
        /// Jei nori GENERUOTI
        else
        {

            cout << "Iveskite kiek pazymiu norite sugeneruoti: ";
            int kiek = 0;
            cin >> kiek;
            int *tarp = new int[kiek];
            while (kiek--)
            {
                int x;
                x = rand() % 11;
                cout << x << " ";
                n++;
                sum += x;
                tarp[n - 1] = x;
            }
            A.nd = tarp;
            A.n = n;
            if (n == 0)
            {
                A.ndVidurkis = 0;
            }
            else
                A.ndVidurkis = (double)sum / n;

            cout << "Sugeneruotas egzamino pazymys: ";
            A.egzaminas = rand() % 11;
            cout << A.egzaminas << endl;
        }

        sort(A.nd, A.nd + A.n);
        double median;
        if (A.n != 0)
        {
            if (A.n % 2 == 0)
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
void trinimas(vector<studentai> &grupe)
{
    for (int i = 0; i < grupe.size(); i++)
    {
        delete[] grupe[i].nd;
    }
}

int main()
{
    srand(time(0));
    vector<studentai> grupe;
    bool iki = true;
    while (iki)
    {
        inputas(grupe);

        outputas(grupe);

        cout << "Ar yra dar grupiu? (1 - taip, 0 - ne) ";
        int x;
        cin >> x;
        if (x == 0)
        {
            iki = false;
        }
    }
    trinimas(grupe);
    cout << "Programa baige darba." << endl;
    return 0;
}
