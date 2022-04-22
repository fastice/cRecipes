#include "/Users/ian/progs/clib/standard.h"

typedef float real;

/*
    Poisson deviate generator. From numerical recipes in C.
*/
   real poidev( real xmArg,int *idum);

/*
   Random number generator based around rand(). Input idum < 0 to initialize.
   Returns a number between 0 and 1.0.
*/
    real ran0(int *idum);
/*
   Log gamma function
*/
    real gammln(real xxArg);
/*
    Sort.
*/
    void sort(int n,real ra[]);
/*
    Rational function interpolation
*/
    void ratint(float xa[], float ya[], int n, float x, float *y, float *dy);
/*
    FFT routine
*/
    void four1(float data[], unsigned long nn, int isign);
/*
    Least squares fit using svd and associated routines.
*/
    void svdfit(void *x, double y[], double sig[], int ndata, double a[], 
                int ma,double **u, double **v, double w[], double *chisq,
	void (*funcs)(void *, int i,double *, int)  );

	void svdvar(double **v, int ma, double w[], double **cvm);

    void svbksb(double **u, double w[], double **v, int m, int n,
                double b[], double x[]);
/*
    void svdcmp(double **a, int m, int n, double w[], double **v);
*/
    void svdcmp(double **a,int m,int n, double *w,double **v);

/*
   Find nearest loc of x in array xx
*/
void hunt(double *xx, unsigned long n, double x, unsigned long *jlo);
/*
   Polynomial Interpolation
*/
void polint(double *xa, double *ya, int n, double x, double *y, double *dy);
/*
    Solve set of equtions.
*/
void lubksb(float **a, int n, int *indx, float b[]);
/*
   LU decomposition
*/
void ludcmp(float **a, int n, int *indx, float *d);
/*
    Matrix inversion using LU decomposition
*/
void matinv(double **a, double **inv, int n );
/*
	nonlinear fitting routines
*/
void mrqmin(float x[], float y[], float sig[], int ndata, float a[], int ia[],
	int ma, float **covar, float **alpha, float *chisq,
	void (*funcs)(float, float [], float *, float [], int), float *alamda);

void mrqcof(float x[], float y[], float sig[], int ndata, float a[], int ia[],
	int ma, float **alpha, float beta[], float *chisq,
	void (*funcs)(float, float [], float *, float [], int));

void covsrt(float **covar, int ma, int ia[], int mfit);

void gaussj(float **a, int n, float **b, int m);
