#include "philosophers.h"

# define FONT "angelina.ttf"

t_err	philo_init_text(t_env *env)
{
	if (!(env->sys.font = TTF_OpenFont(FONT, 600)))
		return (E_INIT);
	return (NONE);

}
