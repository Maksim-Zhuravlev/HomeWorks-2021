#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void) {
	char s[100];
	gets_s(s);
	int w = 0, i = 0, k = 10, t;
	while (s[w] != '\0') {
		w++;
	}
	for (int i = 0; i < w; i++)
	{
		if (s[i] == ' ') { for (int r = i; r < w - 1; r++) { s[r] = s[r + 1]; } w--; }
		for (t = 0; t < 25; t++)
		{
			if (s[i] == 'A' + t) s[i] = 'a' + t;
		}
	}
	i = 0;
	while (i <= w - 1 - i)
	{
		if (s[i] != s[w - 1 - i])  k = -1;
		i++;
	}
	if (k == -1) printf("NO");
	else printf("YES");
}