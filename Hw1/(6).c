#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N, i, t = 0;
	scanf("%d", &N);
	const int A[N];
	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		if (A[i] == 0) {
			t = -1;
			break;
		}
		else {
			if (A[i] < 0)
				t++;
			if (t > 2) t -= 2;
		}
	}
	if (t == -1) printf("%d", t + 1);
	else {
		if (t == 1) printf("-");
		else printf("+");
	}
}