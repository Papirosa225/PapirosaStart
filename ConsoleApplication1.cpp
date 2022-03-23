#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d:%d", &a, &b);
	scanf("%d:%d", &c, &d);
	int t = (a + c) * 60 + b + d;
	printf("%02d:%02d", t / 2 / 60, t / 2 % 60);
}