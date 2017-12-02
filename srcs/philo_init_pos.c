#include "philosophers.h"

/*
** 7 pos philosophers + 3 * 7 pos baguettes  => 7 + 21 = 28 pos + 1(empty first
** one 29
*/

void	philo_init_pos(t_pos *pos)
{

	//empty one
	pos[0].rect_d.x = 0;
	pos[0].rect_d.y = 0;
	pos[0].rect_d.w = 0;
	pos[0].rect_d.h = 0;
	pos[0].angle = 0;
	pos[0].center = 0;
	
	//philosophers 
	pos[1].rect_d.x = 380;
	pos[1].rect_d.y = 290;
	pos[1].rect_d.w = 70;
	pos[1].rect_d.h = 75;
	pos[1].angle = 0;
	pos[1].center = 0;


	pos[2].rect_d.x = 600;
	pos[2].rect_d.y = 220;
	pos[2].rect_d.w = 70;
	pos[2].rect_d.h = 75;
	pos[2].angle = 0;
	pos[2].center = 0;

	pos[3].rect_d.x = 190;
	pos[3].rect_d.y = 340;
	pos[3].rect_d.w = 70;
	pos[3].rect_d.h = 75;
	pos[3].angle = 0;
	pos[3].center = 0;

	pos[4].rect_d.x = 140;
	pos[4].rect_d.y = 440;
	pos[4].rect_d.w = 80;
	pos[4].rect_d.h = 85;
	pos[4].angle = 0;
	pos[4].center = 0;

	pos[5].rect_d.x = 850;
	pos[5].rect_d.y = 285;
	pos[5].rect_d.w = 70;
	pos[5].rect_d.h = 75;
	pos[5].angle = 0;
	pos[5].center = 0;

	pos[6].rect_d.x = 1070;
	pos[6].rect_d.y = 330;
	pos[6].rect_d.w = 70;
	pos[6].rect_d.h = 75;
	pos[6].angle = 0;
	pos[6].center = 0;

	pos[7].rect_d.x = 1130;
	pos[7].rect_d.y = 450;
	pos[7].rect_d.w = 80;
	pos[7].rect_d.h = 85;
	pos[7].angle = 0;
	pos[7].center = 0;

	//baguettes init pos
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
