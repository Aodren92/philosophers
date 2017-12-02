#include "philosophers.h"

/*
** \XXX ad message box
*/
void	philo_error(t_env *env, t_err error)
{
	(void)env;
	if (error == E_INIT)
		ft_putstr_fd("Error SDL init\n", 2);
}
