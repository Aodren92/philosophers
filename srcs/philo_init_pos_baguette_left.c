#include "philosophers.h"

void	philo_init_pos_baguette_left_next(t_pos *pos)
{
	pos[25].rect_d.x = 570;
	pos[25].rect_d.y = 220;
	pos[25].rect_d.w = 30;
	pos[25].rect_d.h = 75;
	pos[25].angle = 0;
	pos[25].center = 0;
	pos[26].rect_d.x = 820;
	pos[26].rect_d.y = 285;
	pos[26].rect_d.w = 30;
	pos[26].rect_d.h = 75;
	pos[26].angle = 0;
	pos[26].center = 0;
	pos[27].rect_d.x = 1040;
	pos[27].rect_d.y = 330;
	pos[27].rect_d.w = 30;
	pos[27].rect_d.h = 75;
	pos[27].angle = 0;
	pos[27].center = 0;
	pos[28].rect_d.x = 1100;
	pos[28].rect_d.y = 450;
	pos[28].rect_d.w = 30;
	pos[28].rect_d.h = 85;
	pos[28].angle = 0;
	pos[28].center = 0;
}

void	philo_init_pos_baguette_left(t_pos *pos)
{
	pos[22].rect_d.x = 120;
	pos[22].rect_d.y = 440;
	pos[22].rect_d.w = 30;
	pos[22].rect_d.h = 85;
	pos[22].angle = 0;
	pos[22].center = 0;
	pos[23].rect_d.x = 160;
	pos[23].rect_d.y = 340;
	pos[23].rect_d.w = 30;
	pos[23].rect_d.h = 75;
	pos[23].angle = 0;
	pos[23].center = 0;
	pos[24].rect_d.x = 360;
	pos[24].rect_d.y = 290;
	pos[24].rect_d.w = 30;
	pos[24].rect_d.h = 75;
	pos[24].angle = 0;
	pos[24].center = 0;
	philo_init_pos_baguette_left_next(pos);
}
