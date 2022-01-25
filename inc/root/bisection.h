/*
* Author - Ritesh Saha
* Bisection method.
*/

#ifndef _BISECTION_H_
#define _BISECTION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

double bisection(double, double, double (*f)(double), double);

bool csv_bisection(double*, double*, double (f)(double), double, double*, double*);

#ifdef __cplusplus
}
#endif

#endif // _BISECTION_H_