#ifndef SORTER_PARAMETERS_H
# define SORTER_PARAMETERS_H

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
