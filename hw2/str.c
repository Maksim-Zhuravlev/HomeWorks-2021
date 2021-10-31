int strlen(char* s1)
{
	int i;
	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	return (i);
}
int strcmp(char* s1, char* s2)
{
	int i;
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
void strcpy(char* s1, char* s2)
{
	int i;
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i + 1] = '\0';
}
void strcat(char* s1, char* s2)
{
	int i, h = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[h] != '\0')
	{
		s1[h] = s2[h - i];
		h++;
	}
}