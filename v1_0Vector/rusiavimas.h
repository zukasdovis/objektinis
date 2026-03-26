#ifndef RUSIAVIMAS_H
#define RUSIAVIMAS_H

#include "studentas.h"
#include "failai.h"
#include <bits/stdc++.h>
bool pagalVarda(const studentai &, const studentai &);
bool pagalPavarde(const studentai &, const studentai &);
bool pagalGalutiniVid(const studentai &, const studentai &);
bool pagalGalutiniMed(const studentai &, const studentai &);
template <typename Container>
void splitContainer(Container &grupe, Container &silpniakai);
void failoRusiavimas1(int kiekis);
void failoRusiavimas2(int kiekis);
void failoRusiavimas3(int kiekis);

#endif