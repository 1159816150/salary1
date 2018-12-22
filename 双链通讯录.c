#include<stdio.h>
#include<windows.h>
#include <conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int i = 0, j = 0;	//循环变量
int n = 0;    //员工总人数
typedef struct dnode{
int number;
char name[20];
int counter;
struct dnode *prev,*next;
}dlnode;
dlnode *createlist()       //创建有n个元素的双向链表 
{
	FILE *fp = fopen("gx.dat","rb");
	dlnode *head, *p, *q;
	head = (dlnode *)malloc(sizeof(dlnode));
	head->prev = head;
	head->next = head;
	p = head;

	if(fp == NULL)
	{ 
		printf("can not open file!\n");
		getch();
		exit(-1);
	}

	while(!feof(fp))   //将文件货物依次读入结构体
	{
		q = (dlnode *)malloc(sizeof(dlnode));
		p->next = q;
		head->prev = q;
		q->prev = p;
		q->next = head;
		p = q;	

		fscanf(fp,"%d%s%d",
			&q->number , &q->name , &q->counter);
		
		n = n + 1;    //每输入一个增加一个货物数
	}

	(q->prev)->next = q->next;    //由于while（！feof（fp））会多输入一条数据
	(q->next)->prev = q->prev;
	free(q);    //清掉多余数据
	n = n - 1;    //货物数减一
	fclose(fp);

	printf("共有%d条记录被读取\n\n",n);
	printf("press any key to continue");
	getch();
	system("cls");

	return head;
}

int add_goods(dlnode *head)    //添加货物函数
{
	int k;    //记录输入工号是否重复
	int bianhao;    //定义货物编号
	dlnode *p,*q;  
	
	p = head;    //将p得到链表尾部
	p->prev = head->prev;
	p = head->prev->next;
	head = p->next;
	head->prev = p;

	q = (dlnode *)malloc(sizeof(dlnode));    //插入节点
	(p->prev)->next = q;
	q->prev = p->prev;
	q->next = p;
	p->prev = q;
	printf("---------------------------添加--------------------------\n\n");
	printf("请输入添加货物编号：");
	p = head;
	p = p->next;
	while(1)    //遍历结构体数组，查找有无该编号的货物
	{
		scanf("%d",&bianhao);

		for(i = 0;i < n+2; i++)
		{
			p = p->next;
			if(bianhao==p->number)
			{
				printf("货物编号已存在,是否重新输入？:\n");
				printf("若要重新输入请输入1，若退出请输入任意键\n");
				scanf("%d",&k);
				if(k==1)
				break;
				else
				{
					system("cls");
					return 0;
				}
			}
	
		}

		if(bianhao!=p->number)
		{
			break;
		}
	}
	
	q->number=bianhao;

	printf("请输入添加货物名称：");
	scanf("%s",q -> name);

	printf("请输入添加货物数量：");
	scanf("%d",&q -> counter);

	printf("货物信息录入成功！\n");
	n = n + 1;
	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
	return 0;
};	

void del_goods(dlnode *head)       //删除函数
{
	int flag = 0;    //用于判断货物是否删除
	int k = 1;    //用于判断货物编号是否相等
    int bianhao;   //定义货物编号
	dlnode *p;
	p = head;
	p = p->next;

	printf("---------------------------删除--------------------------\n\n");
	printf("请输入需要删除货物编号:");
	scanf("%d",&bianhao);
		
	if(p->number!=bianhao)
	{
		printf("该货物不存在\n");

		system("pause");
	}

	while(p != head)
	{
	
		if(bianhao==p->number)
		{


		    printf("货物编号：");
     	    printf("%d\n",p -> number);

        	printf("货物名称：");
        	printf("%s\n",p -> name);

    	    printf("货物数量：");
        	printf("%d\n",p -> counter);

	        printf("\n");
			printf("\n---------------------------------------------------------\n");
			printf("请确认是否删除,确认删除请按1，放弃删除请按0\n");
			
			scanf("%d",&flag);

			if(flag == 1 )
			{
				(p->prev)->next = p->next;
				(p->next)->prev = p->prev;
				free(p);
			}
			break;
		}
		p = p->next;
	}
	

	
	if(flag)
	{
		n = n - 1;
		printf("删除成功\n");
	}
	else
	{
		printf("取消删除\n");
	}
	
	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
};		

void seek_goods(dlnode *head)		//查找函数
{
	int k = 1;    //用于判断货物编号是否相等
	int bianhao;
	dlnode *p;
	p = head;
	p = p->next;
	printf("---------------------------查询--------------------------\n\n");
	printf("请输入需要查找货物的编号:");
	scanf("%d",&bianhao);
	while(p != head)
	{
	
		if(bianhao==p->number)
		{
			printf("该货物信息：\n\n");

		    printf("货物编号：");
     	    printf("%d\n",p -> number);

        	printf("货物名称：");
        	printf("%s\n",p -> name);

    	    printf("货物数量：");
        	printf("%d\n",p -> counter);

	        printf("\n");
			
			printf("\n---------------------------------------------------------\n");
		break;
			
		}

		p = p->next;
	}

	if(bianhao!=p->number)
	{
		printf("该货物不存在\n");
	}

	printf("\n\n");
	printf("press any key to continue");
	getch();
	system("cls");
}

void change_goods(dlnode *head)    //修改函数
{
	int k = 1;    //用于判断货物编号是否相等
	int bianhao;
	dlnode *p;
	p = head;
	p = p->next;
	
	printf("---------------------------修改--------------------------\n\n");
	printf("请输入需要修改货物的编号:");
	scanf("%d",&bianhao);
	if(bianhao!=p->number)
	{
		printf("该货物不存在\n");
	
		getch();
		system("cls");
	}

	while(p != head)
	{
	
		if(bianhao==p->number)
		{
			printf("请输入修改货物编号：");
        	scanf("%d",&p -> number);

        	printf("请输入修改货物名称：");
        	scanf("%s",&p -> name);

	        printf("请输入修改货物数量：");
        	scanf("%d",&p -> counter);
        	printf("\n");
			
			printf("修改成功\n");
			getchar();
			system("pause");
			break;
		}

		p=p->next;
	}

	
	system("cls");
};
	
void see_goods(dlnode *head)    //浏览函数
{
	dlnode *p;
	int i=1;
	p = head;
	p = p->next;

	printf("---------------------------浏览--------------------------\n\n");

	printf("货物信息如下：\n");

	while(p != head)
	{
		printf("\n");

		printf("第【%d】个货物信息：\n",i);

	    printf("货物编号：");
        printf("%d\n",p -> number);

      	printf("货物名称：");
       	printf("%s\n",p -> name);

        printf("货物数量：");
       	printf("%d\n",p -> counter);
		i++;
		p = p->next;
	}

	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
};		
	
void save(dlnode *head)			//保存函数
{
	dlnode *p;
	p = head;
	p = p->next;

	printf("---------------------------保存--------------------------\n\n");
	
	if(n <= 0)
	{
		printf("不存在员工");
		exit(-1);
	}
	else
	{
		FILE *fp = fopen("gx.dat","wb+");
		
		if(fp == NULL)
		{
			printf("can not open file!\n");
			getchar();
			exit(-1);
		}
		
		while(p != head)    //写入文件
		{
			fprintf(fp,"%d %s %d\n\t" ,
				p->number , p->name , p->counter);
			
			fprintf(fp,"\n");
			p = p->next;
		} 
		
		fclose(fp);
	}
	
	printf("文件保存成功\n");
	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
}

int Exit()	//退出函数	
{
	int flag = 0;
	printf("---------------------------退出--------------------------\n\n");
	printf("已安全退出\n");
	printf("\n---------------------------------------------------------\n");
	return flag;
};		

int main()
{
	dlnode *head;
	int choose;    //作为选项参数
	int flag = 1;    //作为循环结束判断
	head = createlist();    //获取头结点
	while(flag)
	{
		printf("\t###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###\n\n");
		printf("\t请选择<1 - 7>:\n");
		printf("\t===============================================================\n");
		printf("\t|\t1.查询货物信息                                        |\n");
		printf("\t|\t2.修改货物信息                                        |\n");
		printf("\t|\t3.添加货物信息                                        |\n");
		printf("\t|\t4.删除货物信息                                        |\n");
		printf("\t|\t5.保存数据到文件                                      |\n");
		printf("\t|\t6.浏览货物记录                                        |\n");
		printf("\t|\t7.退出系统                                            |\n");
		printf("\t===============================================================\n\n");
		printf("\t你的选择是：\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:seek_goods(head); break;
		case 2:change_goods(head); break;
		case 3:add_goods(head); break;
		case 4:del_goods(head); break;
		case 5:save(head); break;
		case 6:see_goods(head); break;
		case 7:flag=Exit(); break;
		default:printf("没有此功能\n\n");
		}
	}


return 0;
}