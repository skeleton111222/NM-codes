#include<stdio.h>

#include<math.h>
int main()
{
	int n,i;
	double x[20],y[20],sumx=0,sumy=0,sumxy=0,sumx2=0,a,b;
	printf("C program for linear curvefitting\n");
	printf("Enter the value of number of terms n: ");
	scanf("%d",&n);
	printf("Enter the value of x :\n");
	for(i=1;i<=n;i++){
		scanf("%lf",&x[i]);
	}
	printf("Enter the value of y :\n");
	for(i=1;i<=n;i++){
		scanf("%lf",&y[i]);
	}
	for(i=1;i<=n;i++){
		sumx=sumx+x[i];sumx2=sumx2+x[i]*x[i];
		sumy=sumy+y[i];sumxy=sumxy+x[i]*y[i];
	} /*Calculating a and b*/
	b=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
	a=(sumy-b*sumx)/n;
	printf("The line is y=%.3f+%.3fx",a,b); /*Display value of a and b*/
	return(0);
}