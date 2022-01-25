/*
* Author - Ritesh Saha
* Newton Rhapson method.
*/

#ifndef _NEWTON_RHAPSON_H_
#define _NEWTON_RHAPSON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

double newton_rhapson(double , double (*f)(double), double (*df)(double), double);

bool csv_newton_rhapson(double*, double(*f)(double), double (*df)(double), double, double*);

#ifdef __cplusplus
}
#endif

#endif // _NEWTON_RHAPSON_H_