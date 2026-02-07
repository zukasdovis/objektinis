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
    vector<int> nd;
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

        srand(time(0));

        cout << " Ar norite generuoti atsitiktinius pazymius? (1 - taip, 0 - ne) ";

        int tikr;
        cin >> tikr;
        int sum = 0;
        int n = 0;

        if (tikr == 0)
        {

            cout << "Iveskite mokinio pazymius, kad baigtumete, iveskite skaiciu daugiau uz 10: ";
            while (true)
            {
                int x;
                cin >> x;

                if (x > 10)
                {
                    break;
                }
                sum += x;
                n++;
                A.nd.push_back(x);
            }

            A.ndVidurkis = (double)sum / n;

            cout << "iveskite egzamino pazymi: ";
            cin >> A.egzaminas;
        }
        else
        {

            cout << "Iveskite kiek pazymiu norite sugeneruoti: ";
            int kiek = 0;
            cin >> kiek;
            while (kiek--)
            {
                int x;
                x = rand() % 11;
                cout << x << " ";
                n++;
                sum += x;
                A.nd.push_back(x);
            }

            A.ndVidurkis = (double)sum / n;

            cout << "Sugeneruotas egzamino pazymys: ";
            A.egzaminas = rand() % 11;
            cout << A.egzaminas << endl;
        }

        sort(A.nd.begin(), A.nd.end());
        double median;
        if (n % 2 == 0)
        {
            median = (A.nd[n / 2 - 1] + A.nd[n / 2]) / 2.0;
        }
        else
        {
            median = A.nd[n / 2];
        }

        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;
        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;

        grupe.push_back(A);
        A.nd.clear();
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
    cout << "Programa baige darba." << endl;
    return 0;
}
