#include "philosophers.h"

static void	philo_init_pos_philo_next(t_pos *pos)
{
	pos[4].rect_d.x = 500;
	pos[4].rect_d.y = 200;
	pos[4].rect_d.w = 250;
	pos[4].rect_d.h = 150;
	pos[4].angle = 0;
	pos[4].center = 0;
	pos[5].rect_d.x = 860;
	pos[5].rect_d.y = 235;
	pos[5].rect_d.w = 280;
	pos[5].rect_d.h = 200;
	pos[5].angle = 0;
	pos[5].center = 0;
	pos[6].rect_d.x = 970;
	pos[6].rect_d.y = 310;
	pos[6].rect_d.w = 280;
	pos[6].rect_d.h = 200;
	pos[6].angle = 0;
	pos[6].center = 0;
	pos[7].rect_d.x = 1040;
	pos[7].rect_d.y = 420;
	pos[7].rect_d.w = 280;
	pos[7].rect_d.h = 160;
	pos[7].angle = 0;
	pos[7].center = 0;
}

void		philo_init_pos_philo(t_pos *pos)
{
	pos[1].rect_d.x = 80;
	pos[1].rect_d.y = 430;
	pos[1].rect_d.w = 320;
	pos[1].rect_d.h = 110;
	pos[1].angle = 0;
	pos[1].center = 0;
	pos[2].rect_d.x = 190;
	pos[2].rect_d.y = 340;
	pos[2].rect_d.w = 70;
	pos[2].rect_d.h = 75;
	pos[2].angle = 0;
	pos[2].center = 0;
	pos[3].rect_d.x = 180;
	pos[3].rect_d.y = 220;
	pos[3].rect_d.w = 450;
	pos[3].rect_d.h = 345;
	pos[3].angle = 0;
	pos[3].center = 0;
	philo_init_pos_philo_next(pos);
}
