#if defined(__STDC__) || defined(ANSI) || defined(NRANSI) /* ANSI */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define NR_END 1
#define FREE_ARG char *

void nrerror(char error_text[])
/* Numerical Recipes standard error handler */
{
	fprintf(stderr, "Numerical Recipes run-time error...\n");
	fprintf(stderr, "%s\n", error_text);
	fprintf(stderr, "...now exiting to system...\n");
	exit(1);
}

float *vector(int32_t nl, int32_t nh)
/* allocate a float vector with subscript range v[nl..nh] */
{
	float *v;

	v = (float *)malloc((size_t)((nh - nl + 1 + NR_END) * sizeof(float)));
	if (!v)
		nrerror("allocation failure in vector()");
	return v - nl + NR_END;
}

int32_t *ivector(int32_t nl, int32_t nh)
/* allocate an int32_t vector with subscript range v[nl..nh] */
{
	int32_t *v;

	v = (int32_t *)malloc((size_t)((nh - nl + 1 + NR_END) * sizeof(int)));
	if (!v)
		nrerror("allocation failure in ivector()");
	return v - nl + NR_END;
}

unsigned char *cvector(int32_t nl, int32_t nh)
/* allocate an unsigned char vector with subscript range v[nl..nh] */
{
	unsigned char *v;

	v = (unsigned char *)malloc((size_t)((nh - nl + 1 + NR_END) * sizeof(unsigned char)));
	if (!v)
		nrerror("allocation failure in cvector()");
	return v - nl + NR_END;
}

uint32_t *lvector(int32_t nl, int32_t nh)
/* allocate an uint32_t 32_t vector with subscript range v[nl..nh] */
{
	uint32_t *v;

	v = (uint32_t *)malloc((size_t)((nh - nl + 1 + NR_END) * sizeof(long)));
	if (!v)
		nrerror("allocation failure in lvector()");
	return v - nl + NR_END;
}

double *dvector(int32_t nl, int32_t nh)
/* allocate a double vector with subscript range v[nl..nh] */
{
	double *v;

	v = (double *)malloc((size_t)((nh - nl + 1 + NR_END) * sizeof(double)));
	if (!v)
		nrerror("allocation failure in dvector()");
	return v - nl + NR_END;
}

float **matrix(int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch)
/* allocate a float matrix with subscript range m[nrl..nrh][ncl..nch] */
{
	int32_t i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	float **m;

	/* allocate pointers to rows */
	m = (float **)malloc((size_t)((nrow + NR_END) * sizeof(float *)));
	if (!m)
		nrerror("allocation failure 1 in matrix()");
	m += NR_END;
	m -= nrl;

	/* allocate rows and set pointers to them */
	m[nrl] = (float *)malloc((size_t)((nrow * ncol + NR_END) * sizeof(float)));
	if (!m[nrl])
		nrerror("allocation failure 2 in matrix()");
	m[nrl] += NR_END;
	m[nrl] -= ncl;

	for (i = nrl + 1; i <= nrh; i++)
		m[i] = m[i - 1] + ncol;

	/* return pointer to array of pointers to rows */
	return m;
}

double **dmatrix(int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch)
/* allocate a double matrix with subscript range m[nrl..nrh][ncl..nch] */
{
	int32_t i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	double **m;

	/* allocate pointers to rows */
	m = (double **)malloc((size_t)((nrow + NR_END) * sizeof(double *)));
	if (!m)
		nrerror("allocation failure 1 in matrix()");
	m += NR_END;
	m -= nrl;

	/* allocate rows and set pointers to them */
	m[nrl] = (double *)malloc((size_t)((nrow * ncol + NR_END) * sizeof(double)));
	if (!m[nrl])
		nrerror("allocation failure 2 in matrix()");
	m[nrl] += NR_END;
	m[nrl] -= ncl;

	for (i = nrl + 1; i <= nrh; i++)
		m[i] = m[i - 1] + ncol;

	/* return pointer to array of pointers to rows */
	return m;
}

int32_t **imatrix(int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch)
/* allocate a int32_t matrix with subscript range m[nrl..nrh][ncl..nch] */
{
	int32_t i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	int32_t **m;

	/* allocate pointers to rows */
	m = (int32_t **)malloc((size_t)((nrow + NR_END) * sizeof(int *)));
	if (!m)
		nrerror("allocation failure 1 in matrix()");
	m += NR_END;
	m -= nrl;

	/* allocate rows and set pointers to them */
	m[nrl] = (int32_t *)malloc((size_t)((nrow * ncol + NR_END) * sizeof(int)));
	if (!m[nrl])
		nrerror("allocation failure 2 in matrix()");
	m[nrl] += NR_END;
	m[nrl] -= ncl;

	for (i = nrl + 1; i <= nrh; i++)
		m[i] = m[i - 1] + ncol;

	/* return pointer to array of pointers to rows */
	return m;
}

float **submatrix(float **a, int32_t oldrl, int32_t oldrh, int32_t oldcl, int32_t oldch,
				  int32_t newrl, int32_t newcl)
/* point32_t a submatrix [newrl..][newcl..] to a[oldrl..oldrh][oldcl..oldch] */
{
	int32_t i, j, nrow = oldrh - oldrl + 1, ncol = oldcl - newcl;
	float **m;

	/* allocate array of pointers to rows */
	m = (float **)malloc((size_t)((nrow + NR_END) * sizeof(float *)));
	if (!m)
		nrerror("allocation failure in submatrix()");
	m += NR_END;
	m -= newrl;

	/* set pointers to rows */
	for (i = oldrl, j = newrl; i <= oldrh; i++, j++)
		m[j] = a[i] + ncol;

	/* return pointer to array of pointers to rows */
	return m;
}

float **convert_matrix(float *a, int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch)
/* allocate a float matrix m[nrl..nrh][ncl..nch] that points to the matrix
declared in the standard C manner as a[nrow][ncol], where nrow=nrh-nrl+1
and ncol=nch-ncl+1. The routine should be called with the address
&a[0][0] as the first argument. */
{
	int32_t i, j, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	float **m;

	/* allocate pointers to rows */
	m = (float **)malloc((size_t)((nrow + NR_END) * sizeof(float *)));
	if (!m)
		nrerror("allocation failure in convert_matrix()");
	m += NR_END;
	m -= nrl;

	/* set pointers to rows */
	m[nrl] = a - ncl;
	for (i = 1, j = nrl + 1; i < nrow; i++, j++)
		m[j] = m[j - 1] + ncol;
	/* return pointer to array of pointers to rows */
	return m;
}

float ***f3tensor(int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch, int32_t ndl, int32_t ndh)
/* allocate a float 3tensor with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
	int32_t i, j, nrow = nrh - nrl + 1, ncol = nch - ncl + 1, ndep = ndh - ndl + 1;
	float ***t;

	/* allocate pointers to pointers to rows */
	t = (float ***)malloc((size_t)((nrow + NR_END) * sizeof(float **)));
	if (!t)
		nrerror("allocation failure 1 in f3tensor()");
	t += NR_END;
	t -= nrl;

	/* allocate pointers to rows and set pointers to them */
	t[nrl] = (float **)malloc((size_t)((nrow * ncol + NR_END) * sizeof(float *)));
	if (!t[nrl])
		nrerror("allocation failure 2 in f3tensor()");
	t[nrl] += NR_END;
	t[nrl] -= ncl;

	/* allocate rows and set pointers to them */
	t[nrl][ncl] = (float *)malloc((size_t)((nrow * ncol * ndep + NR_END) * sizeof(float)));
	if (!t[nrl][ncl])
		nrerror("allocation failure 3 in f3tensor()");
	t[nrl][ncl] += NR_END;
	t[nrl][ncl] -= ndl;

	for (j = ncl + 1; j <= nch; j++)
		t[nrl][j] = t[nrl][j - 1] + ndep;
	for (i = nrl + 1; i <= nrh; i++)
	{
		t[i] = t[i - 1] + ncol;
		t[i][ncl] = t[i - 1][ncl] + ncol * ndep;
		for (j = ncl + 1; j <= nch; j++)
			t[i][j] = t[i][j - 1] + ndep;
	}

	/* return pointer to array of pointers to rows */
	return t;
}

void free_vector(float *v, int32_t nl, int32_t nh)
/* free a float vector allocated with vector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_ivector(int32_t *v, int32_t nl, int32_t nh)
/* free an int32_t vector allocated with ivector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_cvector(unsigned char *v, int32_t nl, int32_t nh)
/* free an unsigned char vector allocated with cvector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_lvector(uint32_t *v, int32_t nl, int32_t nh)
/* free an uint32_t 32_t vector allocated with lvector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_dvector(double *v, int32_t nl, int32_t nh)
/* free a double vector allocated with dvector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_matrix(float **m, int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch)
/* free a float matrix allocated by matrix() */
{
	free((FREE_ARG)(m[nrl] + ncl - NR_END));
	free((FREE_ARG)(m + nrl - NR_END));
}

void free_dmatrix(double **m, int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch)
/* free a double matrix allocated by dmatrix() */
{
	free((FREE_ARG)(m[nrl] + ncl - NR_END));
	free((FREE_ARG)(m + nrl - NR_END));
}

void free_imatrix(int32_t **m, int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch)
/* free an int32_t matrix allocated by imatrix() */
{
	free((FREE_ARG)(m[nrl] + ncl - NR_END));
	free((FREE_ARG)(m + nrl - NR_END));
}

void free_submatrix(float **b, int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch)
/* free a submatrix allocated by submatrix() */
{
	free((FREE_ARG)(b + nrl - NR_END));
}

void free_convert_matrix(float **b, int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch)
/* free a matrix allocated by convert_matrix() */
{
	free((FREE_ARG)(b + nrl - NR_END));
}

void free_f3tensor(float ***t, int32_t nrl, int32_t nrh, int32_t ncl, int32_t nch,
				   int32_t ndl, int32_t ndh)
/* free a float f3tensor allocated by f3tensor() */
{
	free((FREE_ARG)(t[nrl][ncl] + ndl - NR_END));
	free((FREE_ARG)(t[nrl] + ncl - NR_END));
	free((FREE_ARG)(t + nrl - NR_END));
}

#else /* ANSI */
/* traditional - K&R */

#include <stdio.h>
#define NR_END 1
#define FREE_ARG char *

void nrerror(error_text) char error_text[];
/* Numerical Recipes standard error handler */
{
	void exit();

	fprintf(stderr, "Numerical Recipes run-time error...\n");
	fprintf(stderr, "%s\n", error_text);
	fprintf(stderr, "...now exiting to system...\n");
	exit(1);
}

float *vector(nl, nh)
int32_t nh, nl;
/* allocate a float vector with subscript range v[nl..nh] */
{
	float *v;

	v = (float *)malloc((uint32_t)((nh - nl + 1 + NR_END) * sizeof(float)));
	if (!v)
		nrerror("allocation failure in vector()");
	return v - nl + NR_END;
}

int32_t *ivector(nl, nh)
int32_t nh, nl;
/* allocate an int32_t vector with subscript range v[nl..nh] */
{
	int32_t *v;

	v = (int32_t *)malloc((uint32_t)((nh - nl + 1 + NR_END) * sizeof(int)));
	if (!v)
		nrerror("allocation failure in ivector()");
	return v - nl + NR_END;
}

unsigned char *cvector(nl, nh)
int32_t nh, nl;
/* allocate an unsigned char vector with subscript range v[nl..nh] */
{
	unsigned char *v;

	v=(unsigned char *)malloc((uint32_t)) ((nh-nl+1+NR_END)*sizeof(unsigned char)));
	if (!v)
		nrerror("allocation failure in cvector()");
	return v - nl + NR_END;
}

uint32_t 32_t * lvector(nl, nh)
int32_t nh, nl;
/* allocate an uint32_t 32_t vector with subscript range v[nl..nh] */
{
	uint32_t 32_t * v;

	v=(uint32_t 32_t *)malloc((uint32_t)) ((nh-nl+1+NR_END)*sizeof(long)));
	if (!v)
		nrerror("allocation failure in lvector()");
	return v - nl + NR_END;
}

double *dvector(nl, nh)
int32_t nh, nl;
/* allocate a double vector with subscript range v[nl..nh] */
{
	double *v;

	v=(double *)malloc((uint32_t)) ((nh-nl+1+NR_END)*sizeof(double)));
	if (!v)
		nrerror("allocation failure in dvector()");
	return v - nl + NR_END;
}

float **matrix(nrl, nrh, ncl, nch)
int32_t nch, ncl, nrh, nrl;
/* allocate a float matrix with subscript range m[nrl..nrh][ncl..nch] */
{
	int32_t i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	float **m;

	/* allocate pointers to rows */
	m=(float **) malloc((uint32_t))((nrow+NR_END)*sizeof(float*)));
	if (!m)
		nrerror("allocation failure 1 in matrix()");
	m += NR_END;
	m -= nrl;

	/* allocate rows and set pointers to them */
	m[nrl]=(float *) malloc((uint32_t))((nrow*ncol+NR_END)*sizeof(float)));
	if (!m[nrl])
		nrerror("allocation failure 2 in matrix()");
	m[nrl] += NR_END;
	m[nrl] -= ncl;

	for (i = nrl + 1; i <= nrh; i++)
		m[i] = m[i - 1] + ncol;

	/* return pointer to array of pointers to rows */
	return m;
}

double **dmatrix(nrl, nrh, ncl, nch)
int32_t nch, ncl, nrh, nrl;
/* allocate a double matrix with subscript range m[nrl..nrh][ncl..nch] */
{
	int32_t i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	double **m;

	/* allocate pointers to rows */
	m = (double **)malloc((uint32_t)((nrow + NR_END) * sizeof(double *)));
	if (!m)
		nrerror("allocation failure 1 in matrix()");
	m += NR_END;
	m -= nrl;

	/* allocate rows and set pointers to them */
	m[nrl] = (double *)malloc((uint32_t)((nrow * ncol + NR_END) * sizeof(double)));
	if (!m[nrl])
		nrerror("allocation failure 2 in matrix()");
	m[nrl] += NR_END;
	m[nrl] -= ncl;

	for (i = nrl + 1; i <= nrh; i++)
		m[i] = m[i - 1] + ncol;

	/* return pointer to array of pointers to rows */
	return m;
}

int32_t **imatrix(nrl, nrh, ncl, nch)
int32_t nch, ncl, nrh, nrl;
/* allocate a int32_t matrix with subscript range m[nrl..nrh][ncl..nch] */
{
	int32_t i, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	int32_t **m;

	/* allocate pointers to rows */
	m = (int32_t **)malloc((uint32_t)((nrow + NR_END) * sizeof(int *)));
	if (!m)
		nrerror("allocation failure 1 in matrix()");
	m += NR_END;
	m -= nrl;

	/* allocate rows and set pointers to them */
	m[nrl] = (int32_t *)malloc((uint32_t)((nrow * ncol + NR_END) * sizeof(int)));
	if (!m[nrl])
		nrerror("allocation failure 2 in matrix()");
	m[nrl] += NR_END;
	m[nrl] -= ncl;

	for (i = nrl + 1; i <= nrh; i++)
		m[i] = m[i - 1] + ncol;

	/* return pointer to array of pointers to rows */
	return m;
}

float **submatrix(a, oldrl, oldrh, oldcl, oldch, newrl, newcl)
float **a;
int32_t newcl, newrl, oldch, oldcl, oldrh, oldrl;
/* point32_t a submatrix [newrl..][newcl..] to a[oldrl..oldrh][oldcl..oldch] */
{
	int32_t i, j, nrow = oldrh - oldrl + 1, ncol = oldcl - newcl;
	float **m;

	/* allocate array of pointers to rows */
	m = (float **)malloc((uint32_t)((nrow + NR_END) * sizeof(float *)));
	if (!m)
		nrerror("allocation failure in submatrix()");
	m += NR_END;
	m -= newrl;

	/* set pointers to rows */
	for (i = oldrl, j = newrl; i <= oldrh; i++, j++)
		m[j] = a[i] + ncol;

	/* return pointer to array of pointers to rows */
	return m;
}

float **convert_matrix(a, nrl, nrh, ncl, nch)
float *a;
int32_t nch, ncl, nrh, nrl;
/* allocate a float matrix m[nrl..nrh][ncl..nch] that points to the matrix
declared in the standard C manner as a[nrow][ncol], where nrow=nrh-nrl+1
and ncol=nch-ncl+1. The routine should be called with the address
&a[0][0] as the first argument. */
{
	int32_t i, j, nrow = nrh - nrl + 1, ncol = nch - ncl + 1;
	float **m;

	/* allocate pointers to rows */
	m = (float **)malloc((uint32_t)((nrow + NR_END) * sizeof(float *)));
	if (!m)
		nrerror("allocation failure in convert_matrix()");
	m += NR_END;
	m -= nrl;

	/* set pointers to rows */
	m[nrl] = a - ncl;
	for (i = 1, j = nrl + 1; i < nrow; i++, j++)
		m[j] = m[j - 1] + ncol;
	/* return pointer to array of pointers to rows */
	return m;
}

float ***f3tensor(nrl, nrh, ncl, nch, ndl, ndh)
int32_t nch, ncl, ndh, ndl, nrh, nrl;
/* allocate a float 3tensor with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
	int32_t i, j, nrow = nrh - nrl + 1, ncol = nch - ncl + 1, ndep = ndh - ndl + 1;
	float ***t;

	/* allocate pointers to pointers to rows */
	t = (float ***)malloc((uint32_t)((nrow + NR_END) * sizeof(float **)));
	if (!t)
		nrerror("allocation failure 1 in f3tensor()");
	t += NR_END;
	t -= nrl;

	/* allocate pointers to rows and set pointers to them */
	t[nrl] = (float **)malloc((uint32_t)((nrow * ncol + NR_END) * sizeof(float *)));
	if (!t[nrl])
		nrerror("allocation failure 2 in f3tensor()");
	t[nrl] += NR_END;
	t[nrl] -= ncl;

	/* allocate rows and set pointers to them */
	t[nrl][ncl] = (float *)malloc((uint32_t)((nrow * ncol * ndep + NR_END) * sizeof(float)));
	if (!t[nrl][ncl])
		nrerror("allocation failure 3 in f3tensor()");
	t[nrl][ncl] += NR_END;
	t[nrl][ncl] -= ndl;

	for (j = ncl + 1; j <= nch; j++)
		t[nrl][j] = t[nrl][j - 1] + ndep;
	for (i = nrl + 1; i <= nrh; i++)
	{
		t[i] = t[i - 1] + ncol;
		t[i][ncl] = t[i - 1][ncl] + ncol * ndep;
		for (j = ncl + 1; j <= nch; j++)
			t[i][j] = t[i][j - 1] + ndep;
	}

	/* return pointer to array of pointers to rows */
	return t;
}

void free_vector(v, nl, nh) float *v;
int32_t nh, nl;
/* free a float vector allocated with vector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_ivector(v, nl, nh)
	int32_t *v;
int32_t nh, nl;
/* free an int32_t vector allocated with ivector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_cvector(v, nl, nh)
	int32_t nh,
	nl;
unsigned char *v;
/* free an unsigned char vector allocated with cvector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_lvector(v, nl, nh)
	int32_t nh,
	nl;
uint32_t *v;
/* free an uint32_t 32_t vector allocated with lvector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_dvector(v, nl, nh) double *v;
int32_t nh, nl;
/* free a double vector allocated with dvector() */
{
	free((FREE_ARG)(v + nl - NR_END));
}

void free_matrix(m, nrl, nrh, ncl, nch) float **m;
int32_t nch, ncl, nrh, nrl;
/* free a float matrix allocated by matrix() */
{
	free((FREE_ARG)(m[nrl] + ncl - NR_END));
	free((FREE_ARG)(m + nrl - NR_END));
}

void free_dmatrix(m, nrl, nrh, ncl, nch) double **m;
int32_t nch, ncl, nrh, nrl;
/* free a double matrix allocated by dmatrix() */
{
	free((FREE_ARG)(m[nrl] + ncl - NR_END));
	free((FREE_ARG)(m + nrl - NR_END));
}

void free_imatrix(m, nrl, nrh, ncl, nch)
	int32_t **m;
int32_t nch, ncl, nrh, nrl;
/* free an int32_t matrix allocated by imatrix() */
{
	free((FREE_ARG)(m[nrl] + ncl - NR_END));
	free((FREE_ARG)(m + nrl - NR_END));
}

void free_submatrix(b, nrl, nrh, ncl, nch) float **b;
int32_t nch, ncl, nrh, nrl;
/* free a submatrix allocated by submatrix() */
{
	free((FREE_ARG)(b + nrl - NR_END));
}

void free_convert_matrix(b, nrl, nrh, ncl, nch) float **b;
int32_t nch, ncl, nrh, nrl;
/* free a matrix allocated by convert_matrix() */
{
	free((FREE_ARG)(b + nrl - NR_END));
}

void free_f3tensor(t, nrl, nrh, ncl, nch, ndl, ndh) float ***t;
int32_t nch, ncl, ndh, ndl, nrh, nrl;
/* free a float f3tensor allocated by f3tensor() */
{
	free((FREE_ARG)(t[nrl][ncl] + ndl - NR_END));
	free((FREE_ARG)(t[nrl] + ncl - NR_END));
	free((FREE_ARG)(t + nrl - NR_END));
}

#endif /* ANSI */
