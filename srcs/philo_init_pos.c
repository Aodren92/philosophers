#include "philosophers.h"

/*
** 7 pos philosophers + 3 * 7 pos baguettes  => 7 + 21 = 28 pos + 1(empty first
** one 29
*/

static void	philo_init_pos_baguette_next(t_pos *pos)
{
	pos[11].rect_d.x = 620;
	pos[11].rect_d.y = 420;
	pos[11].rect_d.w = 30;
	pos[11].rect_d.h = 85;
	pos[11].angle = 180;
	pos[11].center = 0;
	pos[12].rect_d.x = 780;
	pos[12].rect_d.y = 430;
	pos[12].rect_d.w = 30;
	pos[12].rect_d.h = 85;
	pos[12].angle = 240;
	pos[12].center = 0;
	pos[13].rect_d.x = 940;
	pos[13].rect_d.y = 460;
	pos[13].rect_d.w = 30;
	pos[13].rect_d.h = 85;
	pos[13].angle = 270;
	pos[13].center = 0;
	pos[14].rect_d.x = 940;
	pos[14].rect_d.y = 540;
	pos[14].rect_d.w = 30;
	pos[14].rect_d.h = 85;
	pos[14].angle = 285;
	pos[14].center = 0;
}

static void	philo_init_pos_baguette(t_pos *pos)
{
	pos[8].rect_d.x = 350;
	pos[8].rect_d.y = 540;
	pos[8].rect_d.w = 30;
	pos[8].rect_d.h = 85;
	pos[8].angle = 70;
	pos[8].center = 0;
	pos[9].rect_d.x = 360;
	pos[9].rect_d.y = 470;
	pos[9].rect_d.w = 30;
	pos[9].rect_d.h = 85;
	pos[9].angle = 90;
	pos[9].center = 0;
	pos[10].rect_d.x = 490;
	pos[10].rect_d.y = 420;
	pos[10].rect_d.w = 30;
	pos[10].rect_d.h = 85;
	pos[10].angle = 120;
	pos[10].center = 0;
	philo_init_pos_baguette_next(pos);
}

void		philo_init_pos(t_pos *pos)
{
	pos[0].rect_d.x = 0;
	pos[0].rect_d.y = 0;
	pos[0].rect_d.w = 0;
	pos[0].rect_d.h = 0;
	pos[0].angle = 0;
	pos[0].center = 0;
	philo_init_pos_philo(pos);
	philo_init_pos_baguette(pos);
	philo_init_pos_baguette_right(pos);
	philo_init_pos_baguette_left(pos);
}
