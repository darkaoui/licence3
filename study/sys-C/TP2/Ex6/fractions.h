#ifndef FRACTIONS_H
#define FRACTIONS_H

#include "types_numeriques.h"
#include <stdio.h>

void affiche_fraction(fraction f);

int pgcd(int a, int b);

fraction reduit(fraction f);

fraction add_frac(fraction f1, fraction f2);

fraction sub_frac(fraction f1, fraction f2);

fraction div_frac(fraction f1, fraction f2);

int frac_eq(fraction f1, fraction f2);

float tof_loat(fraction f);

fraction of_int(int);

fraction heron(int,int);

#endif
