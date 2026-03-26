#include "failai.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using std::exception;
using std::ifstream;
using std::ofstream;
using std::runtime_error;
using std::string;
using std::stringstream;
using std::vector;
using std::ws;

void failu_nusk(std::list<studentai> &grupe, std::string failas)
{
    ifstream fd(failas);

    if (!fd)
        throw runtime_error("Failas neegzistuoja arba negali buti atidarytas.");

    string line, niekas;

    getline(fd, line);

    stringstream ss(line);

    int n = 0;

    ss >> niekas >> niekas;

    while (ss >> niekas)
        n++;

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

        if (n != 0)
            A.ndVidurkis = (double)sum / n;

        sort(A.nd.begin(), A.nd.end());

        double median = 0;

        if (n != 0)
        {
            if (n % 2 == 0)
                median = (A.nd[n / 2 - 1] + A.nd[n / 2]) / 2.0;
            else
                median = A.nd[n / 2];
        }

        ss >> A.egzaminas;

        A.galutinis_vid = 0.4 * A.ndVidurkis + 0.6 * A.egzaminas;
        A.galutinis_med = 0.4 * median + 0.6 * A.egzaminas;

        grupe.push_back(A);
    }
}
