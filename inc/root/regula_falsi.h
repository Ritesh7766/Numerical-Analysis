/*
* Author - Ritesh Saha
* Regula Falsi method.
*/

#ifndef _REGULA_FALSE_H_
#define _REGULA_FALSE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

double regula_falsi(double, double, double (*f)(double), double);

bool csv_regula_falsi(double*, double*, double(*f)(double), double, double*, double*);

#ifdef __cplusplus
}
#endif

#endif // _REGULA_FALSE_H_