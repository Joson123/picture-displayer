#ifndef __LCD_H_
#define __LCD_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
void lcd_init();								//初始化LCD屏幕
void draw_point(int x,int y, int color);		//绘制函数
void lcd_uninit();								//结束初始化




#endif
