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

const string vardai[10] = {"Jonas", "Petras", "Antanas", "Kazys", "Stasys", "Mantas", "Rytis", "Darius", "Romas", "Linas"};
const string pavardes[10] = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Stasytis", "Mantys", "Rytys", "Dariuskas", "Romaitis", "Linaitis"};

struct studentai
{
    string vardas = "A", pavarde = "B";
    int *nd;
    int n = 0;
    int cap = 0;
    double ndVidurkis = 0.0;
    int egzaminas = 0;
    double galutinis_vid = 0.0, galutinis_med = 0.0;
};

void push_back_nd(studentai &A, int x)
{
    if (A.n == A.cap)
    {
        int newCap = (A.cap == 0 ? 1 : A.cap * 2);
        int *tmp = new int[newCap];

        for (int i = 0; i < A.n; i++)
            tmp[i] = A.nd[i];

        delete[] A.nd;
        A.nd = tmp;
        A.cap = newCap;
    }
    A.nd[A.n++] = x;
}
/// VEDIMAS RANKA
void ranka(studentai *&grupe, int &m, int &cap)
{
    while (true)
    {
        studentai A;
        A.nd = nullptr;
        A.n = 0;
        A.cap = 0;

        cout << "Iveskite varda ir pavarde, kad baigtumete, iveskite \"0 0\": ";
        cin >> A.vardas >> A.pavarde;
        if (A.vardas == "0" && A.pavarde == "0")
            break;

        int sum = 0;

        cout << "Iveskite pazymius (iveskite skaiciu daugiau uz 10 kad baigtumete): ";
        while (true)
        {
            int x;
            cin >> x;
            if (x > 10)
                break;
            sum += x;
            push_back_nd(A, x);
        }

        cout << "Iveskite egzamino pazymi: ";
        cin >> A.egzaminas;

        // vidurkis
        if (A.n == 0)
        {
            A.ndVidurkis = 0;
        }
        else
        {
            A.ndVidurkis = (double)sum / A.n;
        }

        // mediana
        sort(A.nd, A.nd + A.n);
        double median = 0;
        if (A.n != 0)
        {
            if (A.n % 2 == 0)
            {
                median = (A.nd[A.n / 2 - 1] + A.nd[A.n / 2]) / 2.0;
            }
            else
            {
                median = A.nd[A.n / 2];
            }
        }

        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;
        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;

        if (m == cap)
        {
            int newCap = (cap == 0 ? 1 : cap * 2);
            studentai *tmp = new studentai[newCap];
            for (int i = 0; i < m; i++)
                tmp[i] = grupe[i];
            delete[] grupe;
            grupe = tmp;
            cap = newCap;
        }
        grupe[m++] = A;
    }
}
/// AUTOMATINIS PAZYMIU GENERAVIMAS
void pazymiu_gen(studentai *&grupe, int &m, int &cap)
{
    while (true)
    {
        studentai A;
        A.nd = nullptr;
        A.n = 0;
        A.cap = 0;

        cout << "Iveskite varda ir pavarde, kad baigtumete, iveskite \"0 0\": ";
        cin >> A.vardas >> A.pavarde;
        if (A.vardas == "0" && A.pavarde == "0")
            break;

        int sum = 0;

        cout << "Iveskite kiek pazymiu generuoti: ";
        int kiek = 0;
        cin >> kiek;
        while (kiek--)
        {
            int x = rand() % 11;
            sum += x;
            push_back_nd(A, x);
        }

        A.egzaminas = rand() % 11;

        // vidurkis
        if (A.n == 0)
        {
            A.ndVidurkis = 0;
        }
        else
        {
            A.ndVidurkis = (double)sum / A.n;
        }

        // mediana
        sort(A.nd, A.nd + A.n);
        double median = 0;
        if (A.n != 0)
        {
            if (A.n % 2 == 0)
            {
                median = (A.nd[A.n / 2 - 1] + A.nd[A.n / 2]) / 2.0;
            }
            else
            {
                median = A.nd[A.n / 2];
            }
        }

        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;
        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;

        if (m == cap)
        {
            int newCap = (cap == 0 ? 1 : cap * 2);
            studentai *tmp = new studentai[newCap];
            for (int i = 0; i < m; i++)
                tmp[i] = grupe[i];
            delete[] grupe;
            grupe = tmp;
            cap = newCap;
        }
        grupe[m++] = A;
    }
}
/// AUTOMATINIS VISKO GENERAVIMAS
void visk_gen(studentai *&grupe, int &m, int &cap)
{
    cout << "Iveskite kiek mokiniu vesite: ";
    int stud = 0;
    cin >> stud;
    while (stud--)
    {
        studentai A;
        A.nd = nullptr;
        A.n = 0;
        A.cap = 0;
        int a = rand() % 10, b = rand() % 10;
        A.vardas = vardai[a];
        A.pavarde = pavardes[b];

        int sum = 0;

        cout << "Iveskite kiek pazymiu generuoti: ";
        int kiek = 0;
        cin >> kiek;
        while (kiek--)
        {
            int x = rand() % 11;
            sum += x;
            push_back_nd(A, x);
        }

        A.egzaminas = rand() % 11;

        // vidurkis
        if (A.n == 0)
        {
            A.ndVidurkis = 0;
        }
        else
        {
            A.ndVidurkis = (double)sum / A.n;
        }

        // mediana
        sort(A.nd, A.nd + A.n);
        double median = 0;
        if (A.n != 0)
        {
            if (A.n % 2 == 0)
            {
                median = (A.nd[A.n / 2 - 1] + A.nd[A.n / 2]) / 2.0;
            }
            else
            {
                median = A.nd[A.n / 2];
            }
        }

        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;
        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;

        if (m == cap)
        {
            int newCap = (cap == 0 ? 1 : cap * 2);
            studentai *tmp = new studentai[newCap];
            for (int i = 0; i < m; i++)
                tmp[i] = grupe[i];
            delete[] grupe;
            grupe = tmp;
            cap = newCap;
        }
        grupe[m++] = A;
    }
}

void outputas(studentai *grupe, int m)
{
    cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < m; i++)
    {
        cout << left << setw(10) << grupe[i].vardas << left << setw(10) << grupe[i].pavarde;
        cout << left << setw(10) << grupe[i].galutinis_vid << setw(10) << grupe[i].galutinis_med << endl;
    }
}
/// TRINIMAS
void trinimas(studentai *&grupe, int &m, int &cap)
{
    for (int i = 0; i < m; i++)
    {
        delete[] grupe[i].nd;
    }
    delete[] grupe;
    grupe = nullptr;
    m = 0;
    cap = 0;
}

int main()
{
    srand(time(0));
    studentai *grupe = nullptr;
    int m = 0;
    int cap = 0;
    while (true)
    {
        cout << "MENIU: 1-ranka, 2-pazymiu generavimas, 3-generuoti studentu vardus,pavardes,pazymius, 4-baigti darba" << endl;
        int x;
        cin >> x;

        if (x == 1)
        {
            ranka(grupe, m, cap);
        }
        else if (x == 2)
        {
            pazymiu_gen(grupe, m, cap);
        }
        else if (x == 3)
        {
            visk_gen(grupe, m, cap);
        }
        else
            break;

        outputas(grupe, m);
    }
    trinimas(grupe, m, cap);
    cout << "Programa baige darba." << endl;
    return 0;
}
