#include "rusiavimas.h"

bool pagalVarda(const studentai &A, const studentai &B)
{
    return A.vardas < B.vardas;
}

bool pagalPavarde(const studentai &A, const studentai &B)
{
    return A.pavarde < B.pavarde;
}

bool pagalGalutiniVid(const studentai &A, const studentai &B)
{
    return A.galutinis_vid < B.galutinis_vid;
}

bool pagalGalutiniMed(const studentai &A, const studentai &B)
{
    return A.galutinis_med < B.galutinis_med;
}
