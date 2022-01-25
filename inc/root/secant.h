/*
* Author - Ritesh Saha
* Secant method.
*/

#ifndef _SECANT_H_
#define _SECANT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

double secant(double, double, double (*f)(double), double);

bool csv_secant(double *x0, double *x1, double (*f)(double), double epsilon, double *prev_approximation, double *new_approximation);

#ifdef __cplusplus
}
#endif

#endif // _SECANT_H_