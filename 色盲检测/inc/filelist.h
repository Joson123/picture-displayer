#ifndef __FILELIST_H__
#define __FILELIST_H__
#define MAX 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char  Element;
typedef struct node
{
	Element data[MAX];
	struct node *next;
	struct node *pre;
}Node;
typedef struct list
{
	Node *first;
	Node *last;
	int num;
}List;


List *creat_list();								//初始化一个链表
void add_a_node(List *h,Element *x);	 	    //增加一个结点
void destory_list(List * h);					//销毁一个链表
void delete_a_node(List * h, Element *x);		//删除一个结点
void print_list(List *h);						//打印一个链表
#endif