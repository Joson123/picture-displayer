#ifndef __BMP_H__
#define __BMP_H__
#include "lcd.h"
#include "filelist.h"
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
void show_bmp(char *pathname,int x,int y);			//bmp格式的图片显示
void display_result(int flag);						//播放结果图
List *picture_init(char *pathname);								//图片初始化




#endif