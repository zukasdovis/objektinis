#include "ivedimas.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

void ranka(vector<studentai> &grupe)
{
    while (true)
    {
        studentai A;

        cout << "Iveskite varda ir pavarde (0 0 - baigti): ";

        if (!(cin >> A.vardas >> A.pavarde))
            throw runtime_error("Klaida ivestyje");

        if (A.vardas == "0" && A.pavarde == "0")
            break;

        cout << "Iveskite pazymius (>10 baigti): ";

        int x, sum = 0, n = 0;

        while (true)
        {
            cin >> x;

            if (!cin)
                throw runtime_error("Blogas pazymys");

            if (x > 10)
                break;

            A.nd.push_back(x);
            sum += x;
            n++;
        }

        if (n != 0)
            A.ndVidurkis = (double)sum / n;

        cout << "Iveskite egzamino pazymi: ";
        cin >> A.egzaminas;

        sort(A.nd.begin(), A.nd.end());

        double median = 0;

        if (n != 0)
        {
            if (n % 2 == 0)
                median = (A.nd[n / 2 - 1] + A.nd[n / 2]) / 2.0;
            else
                median = A.nd[n / 2];
        }

        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;
        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;

        grupe.push_back(A);
    }
}

void pazymiu_gen(vector<studentai> &grupe)
{
    while (true)
    {
        studentai A;

        cout << "Iveskite varda pavarde (0 0 - baigti): ";
      
        if (!(cin >> A.vardas >> A.pavarde))
            throw runtime_error("Klaida ivestyje");

        if (A.vardas == "0" && A.pavarde == "0")
            break;

        cout << "Kiek pazymiu generuoti: ";

        int kiek, sum = 0, n = 0;
        cin >> kiek;

        while (kiek--)
        {
            int x = rand() % 11;
            A.nd.push_back(x);
            sum += x;
            n++;
        }

        if (n != 0)
            A.ndVidurkis = (double)sum / n;

        A.egzaminas = rand() % 11;

        sort(A.nd.begin(), A.nd.end());

        double median = 0;

        if (n != 0)
        {
            if (n % 2 == 0)
                median = (A.nd[n / 2 - 1] + A.nd[n / 2]) / 2.0;
            else
                median = A.nd[n / 2];
        }

        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;
        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;

        grupe.push_back(A);
    }
}

void visk_gen(vector<studentai> &grupe)
{
    const string vardai[10] = {"Jonas", "Petras", "Antanas", "Kazys", "Stasys", "Mantas", "Rytis", "Darius", "Romas", "Linas"};
    const string pavardes[10] = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Stasytis", "Mantys", "Rytys", "Dariuskas", "Romaitis", "Linaitis"};

    int stud;

    cout << "Kiek studentu generuoti: ";
    cin >> stud;

    while (stud--)
    {
        studentai A;

        A.vardas = vardai[rand() % 10];
        A.pavarde = pavardes[rand() % 10];

        cout << "Kiek pazymiu generuoti: ";

        int kiek, sum = 0, n = 0;
        cin >> kiek;

        while (kiek--)
        {
            int x = rand() % 11;
            A.nd.push_back(x);
            sum += x;
            n++;
        }

        if (n != 0)
            A.ndVidurkis = (double)sum / n;

        A.egzaminas = rand() % 11;

        sort(A.nd.begin(), A.nd.end());

        double median = 0;

        if (n != 0)
        {
            if (n % 2 == 0)
                median = (A.nd[n / 2 - 1] + A.nd[n / 2]) / 2.0;
            else
                median = A.nd[n / 2];
        }

        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;
        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;

        grupe.push_back(A);
    }
}
