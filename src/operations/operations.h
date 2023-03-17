#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "application/application.h"

// Swap

int	swap_a(t_app *app, int verbose);
int	swap_b(t_app *app, int verbose);
int	swap_both(t_app *app, int verbose);

// Push

int	push_a(t_app *app, int verbose);
int	push_b(t_app *app, int verbose);

// Rotate

int	rotate_a(t_app *app, int verbose);
int	rotate_b(t_app *app, int verbose);
int	rotate_both(t_app *app, int verbose);

// Reverse rotate

int	reverse_rotate_a(t_app *app, int verbose);
int	reverse_rotate_b(t_app *app, int verbose);
int	reverse_rotate_both(t_app *app, int verbose);

#endif
