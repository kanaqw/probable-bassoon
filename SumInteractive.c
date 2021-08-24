#include <stdio.h>
#define TWENTY 20
int main(void)
{
	int count, sum;
	scanf("%d", &count);
	sum = count;
	int summer = count + TWENTY;
	while (count++ < summer)
		sum = sum + count;
	printf("sum = %d\n", sum);
	return 0;
}
