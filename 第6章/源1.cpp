#include <stdio.h>
int main(void)
{
	int n;
	int f1 = 1, f2 = 1, f3, n;
	printf("%12d\n%12d\n", f1, f2);
	scanf_s("%d", &n);
	for (n = 1; n <= 10; n++)
	{
		f3 = f1 + f2;
		printf("%12d\n", f3);
		f1 = f2;
		f2 = f3;
	}
	return 0;