#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int i = 0, j = 0;	//循环变量
int n = 0;    //员工总人数
typedef struct worker
{
	char id[10],name[20];   //员工工号和姓名
    float post_salary;		//岗位工资
    float age_salary;		//薪级工资	
    float job_salary;		//职务津贴
    float ach_salary;		//效绩工资
    float all_salary;		//应发工资
    float tax;				//个人所得税	
    float ture_salary;		//实发工资
    struct worker *prev;
    struct worker *next;
}employee;

employee *createlist()       //创建有n个元素的双向链表 并输入元素
{
    employee *head, *p, *q;
    head = (employee *)malloc(sizeof(employee));
    head->prev = head;
    head->next = head;
    p = head;

    for(i = 0;i < 50;i++)
    {
        q = (employee *)malloc(sizeof(employee));
        p->next = q;
        head->prev = q;
        q->prev = p;
        q->next = head;
        p = q;
    }

	return head;
}

void grsds(struct worker *q)    //计算个人所得税函数
{
	int flag = 1;    //用于判断应得金额的位置
    double sum = 0;    //计算个人所得税总和
    employee *p = q;    //获得当前指针指向的员工
   

    if(p -> all_salary > 100000 )
	{ 
        flag = 1;  
        sum = ( p -> all_salary - 100000 ) * 0.45;
	}
	else
	{
        flag = 0;
	}
	
	if(flag == 1)
	{
		sum = sum + ( 100000 - 80000 ) * 0.4;
	}
	else
	{
		if(p -> all_salary > 80000 && p -> all_salary <= 100000 )
		{
			flag = 1;
			sum = ( p -> all_salary - 80000 ) * 0.4;
		}
		else
		{
			flag = 0;
		}
	}

	if(flag == 1)
	{
        sum = sum + ( 80000 - 60000 ) * 0.35;
	}
	else
	{
		if(p -> all_salary > 60000 && p -> all_salary <= 80000)
		{
			flag = 1;
			sum = sum + ( p -> all_salary - 60000 ) * 0.35;
		}
		else
		{
			flag = 0;
		}
	}

	if(flag == 1)
	{ 
        sum = sum + ( 60000 - 40000 ) * 0.3;
	}
	else
	{
		if(p -> all_salary > 40000 && p -> all_salary <= 60000)
		{
			flag = 1;
			sum = sum + ( p -> all_salary - 40000 ) * 0.3;
		}
		else
		{
			flag = 0;
		}
	}

	if(flag == 1)
	{
		sum = sum + ( 40000 - 20000 ) * 0.25;
	}
	else
	{
		if(p -> all_salary > 20000 && p -> all_salary <= 40000)
		{
			flag = 1;
			sum = sum + ( p -> all_salary - 20000 ) * 0.25;
		}
		else
		{
			flag = 0;
		}
	}

	if(flag == 1)
	{ 
		sum = sum + ( 20000 - 5000 ) * 0.2;
	}
	else
	{
		if(p -> all_salary > 5000 && p -> all_salary <= 20000)
		{
			flag = 1;
			sum = sum + ( p -> all_salary - 5000 ) * 0.2;
		}
		else
		{
			flag = 0;
		}
	}

	if(flag == 1)
	{
		sum = sum + ( 5000 - 2000 ) * 0.15;
	}
	else
	{
		if(p -> all_salary > 2000 && p -> all_salary <= 5000)
		{
			flag=1;
			sum = sum + ( p -> all_salary - 2000 ) * 0.15;
		}
		else
		{
			flag = 0;
		}
	}

	if(flag == 1)
	{
		sum = sum + ( 2000 - 500 ) * 0.1;
	}
	else
	{
		if(p -> all_salary > 500 && p -> all_salary <= 2000)
		{
			flag = 1;
			sum = sum + ( p -> all_salary - 500 ) * 0.1;
		}
		else
		{
			flag = 0;
		}
	}

	
	if(flag == 1)
	{
		sum = sum + 500 * 0.05;
	}
	else
	{
		if(p -> all_salary > 0 && p -> all_salary <= 500)
		{
			flag = 1;
			sum = sum + p -> all_salary * 0.05;
		}
		else
		{
			flag = 0;
		}
	}
	
	if( p -> all_salary < 0 )
	{
		printf("数值为负");
		exit(-1);
	}

	p -> tax = sum;

}

void add_worker(employee *head,int m)    //添加员工函数
{
	int k;    //记录输入工号是否重复
	char gonghao[10];
	employee *p,*q;
	p = head;
	p = p->next;

	while(m)
	{
		p = p->next;
		m=m-1;
	}

	q = (employee *)malloc(sizeof(employee));
    (p->prev)->next = q;
	q->prev = p->prev;
	q->next = p;
	p->prev = q;
	printf("---------------------------添加--------------------------\n\n");
	printf("请输入添加员工的工号：");
	p = head;
	p = p->next;
	while(1)
	{
		scanf("%s",gonghao);

		for(i = 0;i < n+1; i++)
		{
			k=strcmp(gonghao,p->id);
			p = p->next;
			if(k == 0)
			{
				printf("工号已存在,请重新输入:");	
				break;
			}
		}

		if(k != 0)
		{
			break;
		}
	}
	
	strcpy(q -> id,gonghao);
	
	printf("请输入添加员工的姓名：");
	scanf("%s",q -> name);
	
	printf("请输入添加员工的岗位工资：");
	scanf("%f",&(q -> post_salary));
	
	printf("请输入添加员工的薪级工资：");
	scanf("%f",&(q -> age_salary));
	
	printf("请输入添加员工的职务津贴：");
	scanf("%f",&(q -> job_salary));
	
	printf("请输入添加员工的效绩工资：");
	scanf("%f",&(q -> ach_salary));
	
	printf("\n");

	q -> all_salary 
		= q -> ach_salary 
		+ q -> job_salary 
		+ q -> post_salary 
		+ q -> age_salary;

	grsds(q);
	
	q -> ture_salary = q -> all_salary - q-> tax;
	
	printf("职工信息录入成功！\n");
	n = n + 1;

};	

void del_worker(employee *head)       //删除函数
{
	int flag = 0;    //用于判断员工是否删除
	int k = 1;    //用于判断员工工号是否相等
	char gonghao[10];
	employee *p;
	p = head;
	p = p->next;

	printf("---------------------------删除--------------------------\n\n");
	printf("请输入需要删除员工的工号:");
	scanf("%s",gonghao);
	
	while(p!=head)
	{
		k = strcmp(gonghao,p->id);
		if(k == 0)
		{
			printf("该职工信息：\n\n");

			printf("工号：");
			printf("%s\n", p->id);
			
			printf("姓名：");
			printf("%s\n", p->name);
			
			printf("岗位工资：");
			printf("%.2f\n", p->post_salary);
			
			printf("薪级工资：");
			printf("%.2f\n", p->job_salary);
			
			printf("职务津贴：");
			printf("%.2f\n", p->age_salary);
			
			printf("效绩工资：");
			printf("%.2f\n", p->ach_salary);
			
			printf("应发工资：");
			printf("%.2f\n", p->all_salary);
			
			printf("个人所得税：");
			printf("%.2f\n", p->tax);
			
			printf("实发工资：");
			printf("%.2f\n", p->ture_salary);
			
			printf("--------------------------------------\n");
			printf("请确认是否删除,确认删除请按1，放弃删除请按0\n");
			
			scanf("%d",&flag);

			if(flag==1)
			{
				(p->prev)->next = p->next;
				(p->next)->prev = p->prev;
				free(p);
			}
			break;
		}
		p = p->next;
	}
	
	if(k!=0)
	{
		printf("该员工不存在\n");
	}
	
	if(flag)
	{
		n=n-1;
		printf("删除成功\n");
	}
	else
	{
		printf("取消删除\n");
	}
};		

void seek_worker(employee *head)		//查找函数
{
	int k = 1;    //用于判断员工工号是否相等
	char gonghao[10];
	employee *p;
	p = head;
	p = p->next;
	printf("---------------------------查询--------------------------\n\n");
	printf("请输入需要查找员工的工号:");
	scanf("%s",gonghao);
	while(p!=head)
	{
		k = strcmp(gonghao,p->id);
		if(k == 0)
		{
			printf("该职工信息：\n\n");

			printf("工号：");
			printf("%s\n", p->id);
			
			printf("姓名：");
			printf("%s\n", p->name);
			
			printf("岗位工资：");
			printf("%.2f\n", p->post_salary);
			
			printf("薪级工资：");
			printf("%.2f\n", p->job_salary);
			
			printf("职务津贴：");
			printf("%.2f\n", p->age_salary);
			
			printf("效绩工资：");
			printf("%.2f\n", p->ach_salary);
			
			printf("应发工资：");
			printf("%.2f\n", p->all_salary);
			
			printf("个人所得税：");
			printf("%.2f\n", p->tax);
			
			printf("实发工资：");
			printf("%.2f\n", p->ture_salary);
			
			printf("--------------------------------------\n");

		break;
			
		}

		p = p->next;
	}

	if(k != 0)
	{
		printf("该员工不存在\n");
	}
}

void change_worker(employee *head)    //修改函数
{
	int k = 1;    //用于判断员工工号是否相等
	char gonghao[10];
	employee *p;
	p = head;
	p = p->next;
	
	printf("---------------------------修改--------------------------\n\n");
	printf("请输入需要修改员工的工号:");
	scanf("%s",gonghao);
	while(p!=head)
	{
		k = strcmp(gonghao , p->id);
		if(k == 0)
		{
			printf("请输入员工工号：");
			scanf("%s", &p->id);
			
			printf("姓名：");
			scanf("%s", &p->name);
			
			printf("岗位工资：");
			scanf("%f", &p->post_salary);
			
			printf("薪级工资：");
			scanf("%f", &p->age_salary);
			
			printf("职务津贴:");
			scanf("%f", &p->job_salary);
			
			printf("效绩工资:");
			scanf("%f", &p->ach_salary);
			
			p->all_salary = 
				p->ach_salary 
				+ p->job_salary 
				+ p->post_salary 
				+ p->age_salary;
			
			grsds(p);
			
			p->ture_salary = p->all_salary - p->tax;
			
			break;
		}

		p=p->next;
	}
	if(k!=0)
	{
		printf("该员工不存在\n");
	}
};
	
void see_worker(employee *head)    //浏览函数
{
	employee *p;
	p = head;
	p = p->next;

	printf("---------------------------浏览--------------------------\n\n");

	printf("职工信息如下：\n\n");

	for(i = 0;i < n;i++)
	{
		printf("\n\n");

		printf("工号：");
		printf("%s\n", p->id);
			
		printf("姓名：");
		printf("%s\n", p->name);
			
		printf("岗位工资：");
		printf("%.2f\n", p->post_salary);
			
		printf("薪级工资：");
		printf("%.2f\n", p->job_salary);
			
		printf("职务津贴：");
		printf("%.2f\n", p->age_salary);
			
		printf("效绩工资：");
		printf("%.2f\n", p->ach_salary);
			
		printf("应发工资：");
		printf("%.2f\n", p->all_salary);
		
		printf("个人所得税：");
		printf("%.2f\n", p->tax);
			
		printf("实发工资：");
		printf("%.2f\n", p->ture_salary);

		p = p->next;
	}

	printf("\n\n");
};		
	
void save(employee *head)			//保存函数
{
	employee *p;
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
		FILE *fp = fopen("22.txt","wb+");
		
		if(fp == NULL)
		{
			printf("can not open file!\n");
			getchar();
			exit(-1);
		}
		
		for(i = 0;i < n;i++)    //写入文件
		{
			fprintf(fp,"%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f" ,
				p->id , p->name , p->post_salary , 
				p->job_salary , p->age_salary , 
				p->ach_salary , p->all_salary , 
				p->tax , p->ture_salary);
			
			fprintf(fp,"\n");
			p=p->next;
		}
		
		fclose(fp);
	}
	
	printf("文件保存成功\n");

}

int Exit()	//退出函数	
{
	int flag = 0;
	printf("---------------------------退出--------------------------\n\n");
	printf("已安全退出\n");
	return flag;
};		

void open_file(employee *head)		//打开文件函数
{
	FILE *fp = fopen("22.txt","rb");
	employee *p = head;
	p = p->next;
		
	if(fp == NULL)
	{ 
		printf("can not open file!\n");
		getchar();
		exit(-1);
	}
	
	for( i = 0;i < 100; i++)
	{
		int nRes = fscanf(fp,"%s%s%f%f%f%f%f%f%f",
			&p->id , &p->name , &p->post_salary , 
			&p->job_salary , &p->age_salary , 
			&p->ach_salary , &p->all_salary ,
			&p->tax , &p->ture_salary);

		p = p->next;
		
		if (nRes == -1)
		{
			n = i;
			fclose(fp);
			break;
		}	
		
	}

	p=head;
	p=p->next;

	for(i = 0;i < n;i++)
	{
		printf("工号：");
		printf("%s\n", p->id);
		
		printf("姓名：");
		printf("%s\n", p->name);
		
		printf("岗位工资：");
		printf("%.2f\n", p->post_salary);
		
		printf("薪级工资：");
		printf("%.2f\n", p->job_salary);
		
		printf("职务津贴：");
		printf("%.2f\n", p->age_salary);
		
		printf("效绩工资：");
		printf("%.2f\n", p->ach_salary);
		
		printf("应发工资：");
		printf("%.2f\n", p->all_salary);
		
		printf("个人所得税：");
		printf("%.2f\n", p->tax);
		
		printf("实发工资：");
		printf("%.2f\n", p->ture_salary);

		p=p->next;
		printf("\n");
	}
}


int main()
{
	employee *head;
	int member;    //作为选项参数
	int flag = 1;
	head = createlist();
	open_file(head);
	while(flag)
	{
		printf("\t###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###\n\n");
		printf("\t请选择<1 - 7>:\n");
		printf("\t===============================================================\n");
		printf("\t|\t1.查询职工工资记录                                    |\n");
		printf("\t|\t2.修改职工工资记录                                    |\n");
		printf("\t|\t3.添加职工工资记录                                    |\n");
		printf("\t|\t4.删除职工工资记录                                    |\n");
		printf("\t|\t5.保存数据到文件                                      |\n");
		printf("\t|\t6.浏览职工记录                                        |\n");
		printf("\t|\t7.退出系统                                            |\n");
		printf("\t===============================================================\n\n");
		printf("\t你的选择是：\n");
		scanf("%d",&member);
		switch(member)
		{
		case 1:seek_worker(head);break;
		case 2:change_worker(head);break;
		case 3:add_worker(head,n);break;
		case 4:del_worker(head);break;
		case 5:save(head);break;
		case 6:see_worker(head);break;
		case 7:flag=Exit();break;
		default:printf("没有此功能");
		}
	}


return 0;
}