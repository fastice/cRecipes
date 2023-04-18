#include "clib/standard.h"

typedef float real;

/*
    Poisson deviate generator. From numerical recipes in C.
*/
real poidev(real xmArg, int32_t *idum);

/*
   Random number generator based around rand(). Input idum < 0 to initialize.
   Returns a number between 0 and 1.0.
*/
real ran0(int32_t *idum);
/*
   Log gamma function
*/
real gammln(real xxArg);
/*
    Sort.
*/
void sort(int32_t n, real ra[]);
/*
    Rational function interpolation
*/
void ratint(float xa[], float ya[], int32_t n, float x, float *y, float *dy);
/*
    FFT routine
*/
void four1(float data[], unsigned long nn, int32_t isign);
/*
    Least squares fit using svd and associated routines.
*/
void svdfit(void *x, double y[], double sig[], int32_t ndata, double a[],
            int32_t ma, double **u, double **v, double w[], double *chisq,
            void (*funcs)(void *, int32_t i, double *, int));

void svdvar(double **v, int32_t ma, double w[], double **cvm);

void svbksb(double **u, double w[], double **v, int32_t m, int32_t n,
            double b[], double x[]);
/*
    void svdcmp(double **a, int32_t m, int32_t n, double w[], double **v);
*/
void svdcmp(double **a, int32_t m, int32_t n, double *w, double **v);

/*
   Find nearest loc of x in array xx
*/
void hunt(double *xx, unsigned long n, double x, unsigned long *jlo);
/*
   Polynomial Interpolation
*/
void polint(double *xa, double *ya, int32_t n, double x, double *y, double *dy);
/*
    Solve set of equtions.
*/
void lubksb(float **a, int32_t n, int32_t *indx, float b[]);
/*
   LU decomposition
*/
void ludcmp(float **a, int32_t n, int32_t *indx, float *d);
/*
    Matrix inversion using LU decomposition
*/
void matinv(double **a, double **inv, int32_t n);
/*
    nonlinear fitting routines
*/
void mrqmin(float x[], float y[], float sig[], int32_t ndata, float a[], int32_t ia[],
            int32_t ma, float **covar, float **alpha, float *chisq,
            void (*funcs)(float, float[], float *, float[], int), float *alamda);

void mrqcof(float x[], float y[], float sig[], int32_t ndata, float a[], int32_t ia[],
            int32_t ma, float **alpha, float beta[], float *chisq,
            void (*funcs)(float, float[], float *, float[], int));

void covsrt(float **covar, int32_t ma, int32_t ia[], int32_t mfit);

void gaussj(float **a, int32_t n, float **b, int32_t m);
