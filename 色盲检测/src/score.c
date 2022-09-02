#include "score.h"


/*
	记录每次选项正确的分数
	@flag:触摸屏标志位
	@pitcure_flag:图片标志位
*/
int score_size(int flag, int picture_flag)
{
	if(flag == 3 && picture_flag == 2)
	{
		score = score + 2;
	}
	if(flag == 4 && picture_flag == 3)
	{
		score = score + 2;
	}
	if(flag == 2 && picture_flag == 4)
	{
		score = score + 2;
	}
	if(flag == 4 && picture_flag == 5)
	{
		score = score + 2;
	}
	if(flag == 2 && picture_flag == 6)
	{
		score = score + 2;
	}
	return score;
}