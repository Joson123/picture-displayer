#include "ts.h"



/*
	触摸屏点击函数
	@a:标志位，判断是否为第一张图片
*/
int touch_dik(int a)
{
	//打开触摸屏
	int touch_fd = open("/dev/input/event0",O_RDWR);
	if(touch_fd == -1)
	{
		perror("open touch error\n");
	}
	//读取信息
	struct input_event ev; 			//获取事件的结构体
	int x,y;
	int start_x,start_y;
	int stop_x,stop_y;
	while(1)
	{
		int ret = read(touch_fd,&ev,sizeof(ev));
		if(ret != sizeof(ev))
		{
			perror("read error\n");
			continue;
		}
		if(ev.type == EV_ABS && ev.code == ABS_X)
		{
			x = ev.value;
		}
		if(ev.type == EV_ABS && ev.code == ABS_Y)
		{
			y = ev.value;
		}
		if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value != 0)  //按下去了
		{
			start_x = x;
			start_y = y;
			if(a == 2)
			{
				return 6;
			}
		}
		if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)			//弹起来
		{
			stop_x = x;
			stop_y = y;
		}
		if(start_x >= 315 && start_x <= 600 && start_y >= 465 && start_y <= 580 && a == 0)		//开始检测按下了
		{
			return 1;
		}
		else if(start_x >= 2 && start_x <= 247 && start_y >= 500 && start_y <= 600 && a == 1)		//A选项按下了
		{
			return 2;
		}
		else if(start_x >= 269 && start_x <= 512 && start_y >= 500 && start_y <= 600 && a == 1)		//B选项按下了
		{
			return 3;
		}
		else if(start_x >= 521 && start_x  <= 779 && start_y >= 500 && start_y <= 600 && a == 1)		//C选项按下了
		{
			return 4;
		}
		else if(start_x >= 800 && start_x <= 1024 && start_y >= 500 && start_y <= 600 && a == 1)	//D选项按下了
		{
			return 5;
		}
		else if(abs(stop_x - start_x) < abs(stop_y - start_y) && abs(stop_y - start_y) > 50 && a != 0)
		{
			if(stop_y - start_y > 0)
			{
				return 7;
			}
		}
	}
}
