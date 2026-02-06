#include <bits/stdc++.h>

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
    double galutinis;
};

void inputas(vector<studentai> &grupe)
{
    cout << "Iveskite kiek mokyniu yra grupeje: ";
    int nn;
    cin >> nn;
    for (int ii = 0; ii < nn; ii++)
    {
        studentai A;
        cout << "Iveskite varda ir pavarde: ";
        cin >> A.vardas >> A.pavarde;

        int n;
        cout << "Kiek pazymiu? ";
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cout << "Iveskite " << i + 1 << " pazymi is " << n << ": ";
            cin >> x;
            sum += x;
            A.nd.push_back(x);
        }
        A.ndVidurkis = (double)sum / n;
        cout << "iveskite egzamino pazymi: ";
        cin >> A.egzaminas;

        A.galutinis = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;
        grupe.push_back(A);
        A.nd.clear();
    }
}
void outputas(vector<studentai> &grupe)
{
    for (const auto &A : grupe)
    {
        cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde << endl;
        cout << setw(10) << A.galutinis << endl;
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
