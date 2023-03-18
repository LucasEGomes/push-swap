#ifndef SORTERS_H
# define SORTERS_H
# include "application/application.h"
# include "merge_sort/merge_sort.h"

// Validators

int	is_sorted(t_app *app);

// Sorters

int	bubble_sort(t_app *app, int verbose);
int	natural_merge_sort(t_app *app, int verbose);

#endif
