


char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		else
			i++;
	}
	if (i >= 0)
		return ((char *)&str[i]);
	else
		return (0);
}

char **ft_split(char const *s, char c)
{
    char	*f;
	char	*r;
	int		n;

	f = s;
	while()
}

int main (void)
{
	char	s[100];
	char	c;

	s = ¨lore ipsum i tal i pascualtal¨;
	c = ¨ ¨;
}