#include <stdio.h>

int main(void)
{
	double n, m;
	double dN, dM;
	double sa;

	scanf("%lf %lf", &n, &m);

	dN = n * 30 + (30 * (m / 60));
	dM = m * 6;

	if (dN >= dM)
	{
		sa = dN - dM;
	}else{
		sa = dM - dN;
	}

	if (sa >= 360)
	{
		sa -= 360;
	}else if (180 < sa){
		sa -= 180;
	}
// -１８０忘れてた
	
	printf("%.4lf\n", sa);

	return 0;
}