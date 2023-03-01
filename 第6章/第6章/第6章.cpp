
#include <stdio.h>
int main()
{
	int f1 = 1, f2 = 1, f3;
	int n = 6, i;
	printf("输入序列的长度：");
	scanf("%d", &n);
	if (n == 1)
		printf("%12d\n", f1);
	else if (n == 2)
		printf("%12d\n%12d\n", f1, f2);
	else if (n == 6)
	{
		for (i = 3; i <= n; i++)
		{
			f3 = f1 + f2;
			printf("%12d\n", f3);
			f1 = f2;
			f2 = f3;
		}
	}
	return 0;
}
}