#define NRANSI
#include "nrutil.h"
#include "stdint.h"

void mrqmin(float x[], float y[], float sig[], int32_t ndata, float a[], int32_t ia[],
			int32_t ma, float **covar, float **alpha, float *chisq,
			void (*funcs)(float, float[], float *, float[], int), float *alamda)
{
	void covsrt(float **covar, int32_t ma, int32_t ia[], int32_t mfit);
	void gaussj(float **a, int32_t n, float **b, int32_t m);
	void mrqcof(float x[], float y[], float sig[], int32_t ndata, float a[],
				int32_t ia[], int32_t ma, float **alpha, float beta[], float *chisq,
				void (*funcs)(float, float[], float *, float[], int));
	int32_t j, k, l;
	static int32_t mfit;
	static float ochisq, *atry, *beta, *da, **oneda;

	if (*alamda < 0.0)
	{
		atry = vector(1, ma);
		beta = vector(1, ma);
		da = vector(1, ma);
		for (mfit = 0, j = 1; j <= ma; j++)
			if (ia[j])
				mfit++;
		oneda = matrix(1, mfit, 1, 1);
		*alamda = 0.001;
		mrqcof(x, y, sig, ndata, a, ia, ma, alpha, beta, chisq, funcs);
		ochisq = (*chisq);
		for (j = 1; j <= ma; j++)
			atry[j] = a[j];
	}
	for (j = 1; j <= mfit; j++)
	{
		for (k = 1; k <= mfit; k++)
			covar[j][k] = alpha[j][k];
		covar[j][j] = alpha[j][j] * (1.0 + (*alamda));
		oneda[j][1] = beta[j];
	}
	gaussj(covar, mfit, oneda, 1);
	for (j = 1; j <= mfit; j++)
		da[j] = oneda[j][1];
	if (*alamda == 0.0)
	{
		covsrt(covar, ma, ia, mfit);
		free_matrix(oneda, 1, mfit, 1, 1);
		free_vector(da, 1, ma);
		free_vector(beta, 1, ma);
		free_vector(atry, 1, ma);
		return;
	}
	for (j = 0, l = 1; l <= ma; l++)
		if (ia[l])
			atry[l] = a[l] + da[++j];
	mrqcof(x, y, sig, ndata, atry, ia, ma, covar, da, chisq, funcs);
	if (*chisq < ochisq)
	{
		*alamda *= 0.1;
		ochisq = (*chisq);
		for (j = 1; j <= mfit; j++)
		{
			for (k = 1; k <= mfit; k++)
				alpha[j][k] = covar[j][k];
			beta[j] = da[j];
		}
		for (l = 1; l <= ma; l++)
			a[l] = atry[l];
	}
	else
	{
		*alamda *= 10.0;
		*chisq = ochisq;
	}
}
#undef NRANSI
