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
    double galutinis_vid, galutinis_med;
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
