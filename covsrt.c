#include "stdint.h"

#define SWAP(a, b)  \
	{               \
		swap = (a); \
		(a) = (b);  \
		(b) = swap; \
	}

void covsrt(float **covar, int32_t ma, int32_t ia[], int32_t mfit)
{
	int32_t i, j, k;
	float swap;

	for (i = mfit + 1; i <= ma; i++)
		for (j = 1; j <= i; j++)
			covar[i][j] = covar[j][i] = 0.0;
	k = mfit;
	for (j = ma; j >= 1; j--)
	{
		if (ia[j])
		{
			for (i = 1; i <= ma; i++)
				SWAP(covar[i][k], covar[i][j])
			for (i = 1; i <= ma; i++)
				SWAP(covar[k][i], covar[j][i])
			k--;
		}
	}
}
#undef SWAP
