#include "philosophers.h"

static void	philo_init_pos_baguette_right_next(t_pos *pos)
{
	pos[18].rect_d.x = 920;
	pos[18].rect_d.y = 285;
	pos[18].rect_d.w = 30;
	pos[18].rect_d.h = 75;
	pos[18].angle = 0;
	pos[18].center = 0;
	pos[19].rect_d.x = 1140;
	pos[19].rect_d.y = 330;
	pos[19].rect_d.w = 30;
	pos[19].rect_d.h = 75;
	pos[19].angle = 0;
	pos[19].center = 0;
	pos[20].rect_d.x = 1210;
	pos[20].rect_d.y = 450;
	pos[20].rect_d.w = 30;
	pos[20].rect_d.h = 85;
	pos[20].angle = 0;
	pos[20].center = 0;
	pos[21].rect_d.x = 220;
	pos[21].rect_d.y = 440;
	pos[21].rect_d.w = 30;
	pos[21].rect_d.h = 85;
	pos[21].angle = 0;
	pos[21].center = 0;
}

void		philo_init_pos_baguette_right(t_pos *pos)
{
	pos[15].rect_d.x = 250;
	pos[15].rect_d.y = 340;
	pos[15].rect_d.w = 30;
	pos[15].rect_d.h = 75;
	pos[15].angle = 0;
	pos[15].center = 0;
	pos[16].rect_d.x = 440;
	pos[16].rect_d.y = 290;
	pos[16].rect_d.w = 30;
	pos[16].rect_d.h = 75;
	pos[16].angle = 0;
	pos[16].center = 0;
	pos[17].rect_d.x = 660;
	pos[17].rect_d.y = 220;
	pos[17].rect_d.w = 30;
	pos[17].rect_d.h = 75;
	pos[17].angle = 0;
	pos[17].center = 0;
	philo_init_pos_baguette_right_next(pos);
}
