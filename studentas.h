#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

struct studentai
{
    std::string vardas = "A";
    std::string pavarde = "B";
    std::vector<int> nd;
    double ndVidurkis = 0.0;
    int egzaminas = 0;
    double galutinis_vid = 0.0;
    double galutinis_med = 0.0;
};

#endif
