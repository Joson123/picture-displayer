#include "filelist.h"


/*
	创建一个链表，保存文件的路径
	函数返回值:
   		返回链表的头结点
*/
List *creat_list()
{
	List *h = malloc(sizeof(List));
	h->first = NULL;
	h->last = NULL;
	h->num = 0;
	return h;
}

/*
	增加一个结点，结点内容为路径的首地址
	函数参数:
	@h:头结点
	@pnew:新增加的结点的内容
*/
void add_a_node(List *h, Element *x)
{
	if(h == NULL)
	{
		return;
	}
	Node *pnew = malloc(sizeof(Node));
	strcpy(pnew->data,x);
	pnew->pre = NULL;
	pnew->next = NULL;
	if(h->first == NULL)
	{
		h->first = pnew;
		h->last = pnew;
	}
	else
	{
		h->last->next = pnew;
		pnew->pre = h->last;
		h->last = pnew;
	}
	h->first->pre = h->last;
	h->last->next = h->first;
	h->num++;
}
/*
	销毁一个链表
	@h:要销毁链表的头结点
*/
void destory_list(List *h)
{
	int flag = 0;
	Node *p = h->first;
	while(p && flag == 0)
	{
		if(p == h->last)
		{
			flag++;
		}
		h->first = h->first->next;
		p->next = NULL;
		p->pre = NULL;
		free(p);
		p = h->first;
	}
	free(h);
}
/*
	删除一个结点
	@h:头结点
	@x:要删除的内容
*/
void delete_a_node(List *h,Element *x)
{
	int flag = 0;
	Node *p = h->first;
	while(p && flag == 0)
	{
		if(p == h->last)
		{
			flag++;
		}
		if(p->data == x)
		{
			h->num--;
			break;
		}
		p = p->next;
	}
	if(p)
	{
		if(p == h->first)
		{
			h->first = h->first->next;
			h->first->pre = h->last;
			h->last->next = h->first;
			p->pre = NULL;
			p->next = NULL;
		}
		else if(p == h->last)
		{
			h->last = h->last->pre;
			h->last->next = h->last;
			h->first->pre = h->last;
			p->next = NULL;
			p->pre = NULL;
		}
		else
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
			p->next = NULL;
			p->pre = NULL;
		}
		free(p);
		p = NULL;
	}
}
/*
	打印链表的内容
	@h:头结点
*/
void print_list(List *h)
{
	int flag = 0;
	Node *p = h->first;
	while(p && flag == 0)
	{
		if(p == h->last)
		{
			flag++;
		}
		printf("%s\n",p->data);
		p = p->next;
	}
	printf("%d\n",h->num);
}