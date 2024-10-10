#include <stdlib.h>
#include <stdio.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (s2[n] && (s2[n] != ' ' || s2[n] != '\t' || s2[n] != '\n'))
	{
		s1[i] = s2[n];
		i++;
		n++;
		if (s2[n] && (s2[n] == ' ' || s2[n] == '\t' || s2[n] == '\n'))
			break ;
	}
	s1[i] = '\0';
	return (s1);
}

int ft_skip_w(char *str)
{
	int i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
		i++;
	while ((str[i] != ' ' || str[i] != '\t' || str[i] != '\n') && str[i])                                            //"   	bonjo  ur je maplll"
	{
		if (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			break ;
		i++;
	}
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **argv;

	i = 0;
	j = 0;
	k = 0;
	if (!str)
		return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	argv = malloc(sizeof(char *) * 1000);
	while(str[i])
	{
		argv[k] = malloc(sizeof(char) * 1000);
		argv[k] = ft_strncpy(argv[k], str, i);
		printf("argv =%s\n", argv[k]);
		k++;
		i += ft_skip_w(&str[i]);
	}
	argv[k] = NULL;
	return (argv);
}

int main(void)
{
	char str[] = "Ici, tu alloues de la mémoire pour 1000 pointeurs vers des pointeurs de type";
	ft_split(str);
	return (0);
}