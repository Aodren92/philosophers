#include "philosophers.h"

static void	philo_init_color_next(t_env *env)
{
	env->text[4].sdl_color.r = 255;
	env->text[4].sdl_color.g = 255;
	env->text[4].sdl_color.b = 20;
	env->text[4].sdl_color.a = 0;
	env->text[5].sdl_color.r = 120;
	env->text[5].sdl_color.g = 120;
	env->text[5].sdl_color.b = 120;
	env->text[5].sdl_color.a = 255;
	env->text[6].sdl_color.r = 20;
	env->text[6].sdl_color.g = 255;
	env->text[6].sdl_color.b = 255;
	env->text[6].sdl_color.a = 0;
	env->text_timeout.sdl_color.r = 255;
	env->text_timeout.sdl_color.g = 0;
	env->text_timeout.sdl_color.b = 0;
	env->text_timeout.sdl_color.a = 0;
}

void		philo_init_color(t_env *env)
{
	env->text[0].sdl_color.r = 120;
	env->text[0].sdl_color.g = 120;
	env->text[0].sdl_color.b = 255;
	env->text[0].sdl_color.a = 0;
	env->text[1].sdl_color.r = 255;
	env->text[1].sdl_color.g = 120;
	env->text[1].sdl_color.b = 120;
	env->text[1].sdl_color.a = 0;
	env->text[2].sdl_color.r = 120;
	env->text[2].sdl_color.g = 255;
	env->text[2].sdl_color.b = 120;
	env->text[2].sdl_color.a = 0;
	env->text[3].sdl_color.r = 255;
	env->text[3].sdl_color.g = 225;
	env->text[3].sdl_color.b = 255;
	env->text[3].sdl_color.a = 0;
	philo_init_color_next(env);
}
