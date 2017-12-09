#include "philosophers.h"

/*
** \XXX ad message box
*/

t_err	philo_error(t_env *env, t_err error)
{
	(void)env;
	if (error == E_INIT)
		ft_putstr_fd("Error SDL init\n", 2);
	if (error == E_TEXTURE)
		ft_putstr_fd("Error =, couldn't find files\n", 2);
	if (error == E_THREAD_CREATE)
		ft_putstr_fd("Error =, error create thread\n", 2);
	return (error);
}
