int	is_digit(char value)
{
	return (value > '0' && value < '9');
}

static int	is_valid_input(char value)
{
	return (is_digit(value) || value == ' ' || value == '-');
}

int	validate_input(int argc, char **argv)
{
	int		index;
	char	*string;

	index = 1;
	while (index < argc)
	{
		string = argv[index];
		while (is_valid_input(*string))
			string++;
		if (*string != '\0')
			return (1);
		index++;
	}
	return (0);
}
