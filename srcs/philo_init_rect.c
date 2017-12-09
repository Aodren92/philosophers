#include "philosophers.h"

static void	philo_init_rect_philo(t_env *env)
{
	env->texture[1].rect_s.x = 0;
	env->texture[1].rect_s.y = 0;
	env->texture[1].rect_s.w = 950;
	env->texture[1].rect_s.h = 346;
	env->texture[1].pos = 1;
	env->texture[2].rect_s.x = 0;
	env->texture[2].rect_s.y = 0;
	env->texture[2].rect_s.w = 150;
	env->texture[2].rect_s.h = 150;
	env->texture[2].pos = 2;
	env->texture[3].rect_s.x = 0;
	env->texture[3].rect_s.y = 0;
	env->texture[3].rect_s.w = 2000;
	env->texture[3].rect_s.h = 1312;
	env->texture[3].pos = 3;
	env->texture[4].rect_s.x = 250;
	env->texture[4].rect_s.y = 0;
	env->texture[4].rect_s.w = 865;
	env->texture[4].rect_s.h = 1540;
	env->texture[4].pos = 4;
	env->texture[5].rect_s.x = 250;
	env->texture[5].rect_s.y = 0;
	env->texture[5].rect_s.w = 1280;
	env->texture[5].rect_s.h = 720;
	env->texture[5].pos = 5;
	env->texture[6].rect_s.x = 0;
	env->texture[6].rect_s.y = 0;
	env->texture[6].rect_s.w = 460;
	env->texture[6].rect_s.h = 280;
	env->texture[5].pos = 6;
	env->texture[7].rect_s.x = 0;
	env->texture[7].rect_s.y = 0;
	env->texture[7].rect_s.w = 526;
	env->texture[7].rect_s.h = 240;
	env->texture[5].pos = 7;
}

t_err	philo_init_rect(t_env *env)
{
	philo_init_rect_philo(env);
		// baguettes
	env->texture[8].rect_s.x = 40;
	env->texture[8].rect_s.y = 0;
	env->texture[8].rect_s.w = 564;
	env->texture[8].rect_s.h = 1168;
	env->texture[8].pos = 8;


	env->texture[9].rect_s.x = 40;
	env->texture[9].rect_s.y = 0;
	env->texture[9].rect_s.w = 564;
	env->texture[9].rect_s.h = 1168;
	env->texture[9].pos = 9;

	env->texture[10].rect_s.x = 40;
	env->texture[10].rect_s.y = 0;
	env->texture[10].rect_s.w = 564;
	env->texture[10].rect_s.h = 1168;
	env->texture[10].pos = 10;

	env->texture[11].rect_s.x = 40;
	env->texture[11].rect_s.y = 0;
	env->texture[11].rect_s.w = 564;
	env->texture[11].rect_s.h = 1168;
	env->texture[11].pos = 11;

	env->texture[12].rect_s.x = 40;
	env->texture[12].rect_s.y = 0;
	env->texture[12].rect_s.w = 564;
	env->texture[12].rect_s.h = 1168;
	env->texture[12].pos = 12;

	env->texture[13].rect_s.x = 40;
	env->texture[13].rect_s.y = 0;
	env->texture[13].rect_s.w = 564;
	env->texture[13].rect_s.h = 1168;
	env->texture[13].pos = 13;

	env->texture[14].rect_s.x = 40;
	env->texture[14].rect_s.y = 0;
	env->texture[14].rect_s.w = 564;
	env->texture[14].rect_s.h = 1168;
	env->texture[14].pos = 14;
	return (NONE);
}
