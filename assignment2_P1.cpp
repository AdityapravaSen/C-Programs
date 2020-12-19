#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void roots(double a,double b,double c)
{
	double discriminant, root1, root2, realPart, imagPart;
	discriminant = b * b - 4 * a * c;
	if (discriminant > 0) {
        root1 = abs((-b + sqrt(discriminant)) / (2 * a));
        root2 =abs((-b - sqrt(discriminant)) / (2 * a));
        printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
    }

    else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %.2lf;", root1);
    }

    else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
    }
}
int main()
{
	double a,b,c;
	printf("coeff. of x^2	x	1:\n");
	scanf("%lf %lf %lf",&a,&b,&c);
	roots(a,b,c);
	return 0;
}
