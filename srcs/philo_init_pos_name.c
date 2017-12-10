#include "philosophers.h"

static void	philo_init_pos_name_next(t_env *env)
{
	env->text[4].rect_d.x = 10;
	env->text[4].rect_d.y = 90;
	env->text[4].rect_d.h = 60;
	env->text[4].rect_d.w = 150;
	env->text[5].rect_d.x = 200;
	env->text[5].rect_d.y = 90;
	env->text[5].rect_d.h = 60;
	env->text[5].rect_d.w = 150;
	env->text[6].rect_d.x = 370;
	env->text[6].rect_d.y = 90;
	env->text[6].rect_d.h = 60;
	env->text[6].rect_d.w = 150;
}

void		philo_init_pos_name(t_env *env)
{
	env->text[0].rect_d.x = 10;
	env->text[0].rect_d.y = 20;
	env->text[0].rect_d.h = 60;
	env->text[0].rect_d.w = 150;
	env->text[1].rect_d.x = 200;
	env->text[1].rect_d.y = 20;
	env->text[1].rect_d.h = 60;
	env->text[1].rect_d.w = 150;
	env->text[2].rect_d.x = 370;
	env->text[2].rect_d.y = 20;
	env->text[2].rect_d.h = 60;
	env->text[2].rect_d.w = 150;
	env->text[3].rect_d.x = 550;
	env->text[3].rect_d.y = 55;
	env->text[3].rect_d.h = 60;
	env->text[3].rect_d.w = 150;
	philo_init_pos_name_next(env);
}
