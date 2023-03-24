#ifndef SORTER_PARAMETERS_H
# define SORTER_PARAMETERS_H
# define OFFSET_LOWER_LIMIT -50
# define OFFSET_UPPER_LIMIT 50
# define OFFSET_SIZE_RATE_LIMIT 50
# define RATE_LOWER_LIMIT 1
# define RATE_UPPER_LIMIT 99

typedef struct s_sorter_parameters
{
	int	offset;
	int	rate;
	int	steps;
}	t_sorter_parameters;
typedef struct s_sorter_parameters	t_sorter_params;

void	copy_sorter_params(t_sorter_params *source, t_sorter_params *destiny);
void	set_sorter_params(t_sorter_params *params, int offset, int rate,
			int steps);

#endif
