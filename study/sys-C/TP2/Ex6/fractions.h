#ifndef FRACTIONS_H
#define FRACTIONS_H

#include "types_numeriques.h"
#include <stdio.h>

void affiche_fraction(fraction f);

unsigned int pgcd(unsigned int a, unsigned int b);

fraction reduit(fraction f);

fraction add_frac(fraction f1, fraction f2);

fraction sub_frac(fraction f1, fraction f2);

fraction div_frac(fraction f1, fraction f2);

unsigned int frac_eq(fraction f1, fraction f2);

float to_float(fraction f);

fraction of_int(unsigned int);

#endif
