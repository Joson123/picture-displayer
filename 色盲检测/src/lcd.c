#include "lcd.h"
int *plcd = NULL;
int fd;
/*
	初始化LCD屏幕
*/
void lcd_init()
{
 	fd = open("/dev/fb0",O_RDWR);
	if(fd == -1)
	{
		perror("open error\n");
	}
	plcd = mmap(NULL,800*480*4,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
}
/*
	绘制像素点函数
	@x:需要绘制的横坐标
	@y:需要绘制的纵坐标
	@color:需要绘制的颜色
*/
void draw_point(int x,int y, int color)
{
	if(x >= 0 && x < 800 && y >= 0 && y < 480)
	{
		*(plcd+y*800+x) = color;
	}
}
/*
	结束初始化
*/
void lcd_uninit()
{
	int a = munmap(plcd,800*480*4);
	if(a == -1)
	{
		perror("munmap error\n");
	}
	int b = close(fd);
	if(b == -1)
	{
		perror("close error\n");
	}
}