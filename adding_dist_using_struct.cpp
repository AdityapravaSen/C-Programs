		//add 2 dist. using structure
#include<stdio.h>
struct dist
{
	float d1,d2;
};
int main()
{
	struct dist d;
	scanf("%f %f",&d.d1,&d.d2);
	printf("sum:%f",d.d1+d.d2);
	return 0;
}
