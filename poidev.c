
/*
    Poisson deviate generator. From numerical recipes in C.
*/

#include <math.h>
#include "cRecipes.h"


    real poidev( real xmArg,int *idum)
{
	static float sq,alxm,g,oldm=(-1.0);
	float em,t,y,xm;
        xm = (float) xmArg;

	if (xm < 12.0) {
		if (xm != oldm) {
			oldm=xm;
			g=exp(-xm);
		}
		em = -1;
		t=1.0;
		do {
			em += 1.0;
			t *= (float) ran0(idum);
		} while (t > g);
	} else {
		if (xm != oldm) {
			oldm=xm;
			sq=sqrt(2.0*xm);
			alxm=log(xm);
			g=xm*alxm-gammln(xm+1.0);
		}
		do {
			do {
				y=tan(PI*(float)ran0(idum));
				em=sq*y+xm;
			} while (em < 0.0);
			em=floor(em);
			t=0.9*(1.0+y*y)*exp(em*alxm-gammln(em+1.0)-g);
		} while (ran0(idum) > t);
	}
	return (real) em;
}

