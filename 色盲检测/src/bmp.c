#include "bmp.h"
/*
	图片显示函数
	@pathname:传入图片的路径(格式要是bmp的格式)
	@x:从屏幕的哪个x坐标开始显示
	@y:从屏幕的哪个y坐标开始显示
*/
void show_bmp(char *pathname,int x,int y)
{
	/*打开图片*/
	int picture_fd = open(pathname,O_RDWR);
	if(picture_fd == -1)
	{
		perror("open error\n");
	}
	/*测量出图片的宽度*/
	int wide = 0;
	lseek(picture_fd,0x12,SEEK_SET);
	int ret = read(picture_fd,&wide,4);
	if(ret != 4)
	{
		perror("read wide error\n");
	}
	/*测量出图片的高度*/
	int height = 0;
	lseek(picture_fd,0x16,SEEK_SET);
	ret = read(picture_fd,&height,4);
	if(ret != 4)
	{
		perror("read height error\n");
	}
	/*计算图片的实际宽度字节数*/
	int realbyte;
	int depth = 24; 			//像素点的颜色深度，RGB  通常为24位
	int kd = 0;					//如果不是4的倍数则用空洞填写
	if(wide * depth / 8 % 4)
	{
		realbyte = wide * depth / 8 + 4 - wide * depth / 8 % 4;
		kd = 4 - wide * depth / 8 % 4;
	}
	else
	{
		realbyte = wide * depth / 8;
	}
	/*读取图片内容*/
	unsigned char buf[800*480*3] = {0};
	lseek(picture_fd,54,SEEK_SET);
	ret = read(picture_fd,buf,height*realbyte);
	if(ret != height*realbyte)
	{
		perror("read picture error\n");
	}
	/*将 24 位的转化位32位，并显示图片*/
	int color = 0;
	unsigned char a = 0;			//透明度
	int num = 0;
	int i,j;
	for(i = 0 ; i < height ; i++)
	{
		for(j = 0 ; j < wide ; j++)
		{
			color = a << 24 | buf[num + 2] << 16 | buf[num + 1] << 8 | buf[num + 0];
			num = num + 3;
			draw_point(x + j,y + height-1-i,color);
		}
		num = num + kd;
	}
	close(picture_fd);
}
/*
	图片初始化
	返回值为初始化完成的头结点
*/
List *picture_init(char *pathname)
{
	List *h = creat_list();
	DIR *fs = opendir(pathname);
	if(fs == NULL)
	{
		perror("opendir error\n");
	}
	struct dirent *st = NULL;
	char str[1024] = {0};
 	while(1)
	{
		st = readdir(fs);
		if(st == NULL)
		{
			break;
		}
		if(strcmp((st->d_name) + strlen(st->d_name)-4,".bmp") == 0)
		{
			sprintf(str,"%s/%s",pathname,st->d_name);
			add_a_node(h,str);
		}
	}
	int a = closedir(fs);
	if(a == -1)
	{
		perror("close dir error\n");
	}
	return h;
}