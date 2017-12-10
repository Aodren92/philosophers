#include "philosophers.h"

static void	philo_init_pos_name_next(t_env *env)
{
	env->text[4].rect_d.x = 0;
	env->text[4].rect_d.y = 100;
	env->text[4].rect_d.h = 30;
	env->text[4].rect_d.w = 100;
	env->text[5].rect_d.x = 150;
	env->text[5].rect_d.y = 100;
	env->text[5].rect_d.h = 30;
	env->text[5].rect_d.w = 100;
	env->text[6].rect_d.x = 350;
	env->text[6].rect_d.y = 100;
	env->text[6].rect_d.h = 30;
	env->text[6].rect_d.w = 100;
}

void		philo_init_pos_name(t_env *env)
{
	env->text[0].rect_d.x = 0;
	env->text[0].rect_d.y = 0;
	env->text[0].rect_d.h = 30;
	env->text[0].rect_d.w = 100;
	env->text[1].rect_d.x = 150;
	env->text[1].rect_d.y = 0;
	env->text[1].rect_d.h = 30;
	env->text[1].rect_d.w = 100;
	env->text[2].rect_d.x = 350;
	env->text[2].rect_d.y = 0;
	env->text[2].rect_d.h = 30;
	env->text[2].rect_d.w = 100;
	env->text[3].rect_d.x = 550;
	env->text[3].rect_d.y = 0;
	env->text[3].rect_d.h = 30;
	env->text[3].rect_d.w = 100;
	philo_init_pos_name_next(env);
}
