#include <cstdio>
#include <iostream>
#include <cmath>  
#include <algorithm>

int main()
{
	float a,b;
	printf("Please enter a,b:\n");
	scanf("%f%f",&a,&b);
	printf("%.2f",(b+sqrt(b*b+2*a))/(a-b));
	return 0;
} 
