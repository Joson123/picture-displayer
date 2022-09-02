#include "bmp.h"
#include "ts.h"
#include "score.h"
int score = 0;
int score_pre;
int main(int argc,char *argv[])
{
	List *h = picture_init(argv[1]);
	lcd_init();
	Node *p = h->first;
	int flag = 0;
	int picture_flag;
	while(1)
	{
		if(p == h->first)
		{
			score = 0;
			flag = 0;
			picture_flag = 1;
		}
		else
		{
			flag = 1;
			picture_flag++;
		}
		show_bmp(p->data,0,0);
		int a = touch_dik(flag);
		score_pre = score;
		score = score_size(a,picture_flag);
		printf("score is %d\n",score);
		if(p == h->last && score >= 6)
		{
			flag = 2;
			show_bmp("./result/8.bmp",0,0);
			a = touch_dik(flag);
		}
		else if(p == h->last && score < 6)
		{
			flag = 2;
			show_bmp("./result/7.bmp",0,0);
			a = touch_dik(flag);
		}
		if(a != 7)
		{
			p = p->next;
		}
		else
		{
			score = score_pre;
			p = p->pre;
		}
	}
}
