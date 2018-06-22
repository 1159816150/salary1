#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0;	//循环变量
int n=0;    //员工总人数
struct worker{
	char id[10],name[20];   //员工工号和姓名
	double post_salary;		//岗位工资
	double age_salary;		//薪级工资	
	double job_salary;		//职务津贴
	double ach_salary;		//效绩工资
	double all_salary;		//应发工资
	double tax;				//个人所得税	
	double ture_salary;		//实发工资
	struct worker *next;
}employee[50],*p;
void grsds()    //计算个人所得税函数
{
	p=&employee[i];
	if(p->all_salary <= 500)
	{
		p->tax=p->all_salary*0.05;
	}
	else if(p->all_salary > 500 && p->all_salary <= 2000)
	{
		p->tax=p->all_salary*0.1;
	}
	else if(p->all_salary > 2000 && p->all_salary <= 5000)
	{
		p->tax=p->all_salary*0.15;
	}
	else if(p->all_salary > 5000 && p->all_salary <= 20000)
	{
		p->tax=p->all_salary*0.2;
	}
	else if(p->all_salary > 20000 && p->all_salary <= 40000)
	{
		p->tax=p->all_salary*0.25;
	}
	else if(p->all_salary > 40000 && p->all_salary <= 60000)
	{
		p->tax=p->all_salary*0.3;
	}
	else if(p->all_salary > 60000 && p->all_salary <= 80000)
	{
		p->tax=p->all_salary*0.35;
	}
	else if(p->all_salary > 80000 && p->all_salary <= 100000)
	{
		p->tax=p->all_salary*0.4;
	}
	else if(p->all_salary > 100000)
	{
		p->tax=p->all_salary*0.45;
	}
	else
	{
	printf("数值为负");
	}
}	//计算个人所得税函数

void add_worker();		//添加函数

void del_worker();		//删除函数

void seek_worker()		//查找函数
{		
	char gonghao[10];
	printf("请输入需要查找员工的工号:");
	gets(gonghao);

	for(i=0;i<n;i++)
	{
		if(strcmp(gonghao,employee[i].id)==0)
		{
			printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f",employee[i].id,employee[i].name,employee[i].post_salary,employee[i].job_salary,employee[i].age_salary,employee[i].ach_salary,employee[i].all_salary,employee[i].tax,employee[i].ture_salary);
			printf("\n");
		}
	}
}

void change_worker()    //修改函数
{
	char gonghao[10];
	printf("请输入需要修改员工的工号:");
	gets(gonghao);

	for(i=0;i<n;i++)
	{
		if(strcmp(gonghao,employee[i].id)==0)
		{
			printf("请输入员工工号：");
			scanf("%s",&employee[i].id);
			printf("\n");
			printf("姓名：");
			scanf("%s",&employee[i].name);
			printf("\n");
			printf("岗位工资：");
			scanf("%f",&employee[i].post_salary);
			printf("\n");
			printf("薪级工资：");
			scanf("%f",&employee[i].age_salary);
			printf("\n");
			printf("职务津贴:");
			scanf("%f",&employee[i].job_salary);
			printf("\n");
			printf("效绩工资:");
			scanf("%f",&employee[i].ach_salary);
			printf("\n");
			//printf("应发工资：");
			employee[i].all_salary=employee[i].ach_salary+employee[i].job_salary+employee[i].post_salary+employee[i].age_salary;
			grsds();
			employee[i].ture_salary=employee[i].all_salary-employee[i].tax;
		}
		else
		{
			printf("该员工不存在\n");
		}
	}
};	

void see_worker()    //浏览函数
{	
	p=employee;
	employee[n].next=NULL;
	for(i=0;i<n;i++)
	{
		printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f",p->id,p->name,p->post_salary,p->job_salary,p->age_salary,p->ach_salary,p->all_salary,p->tax,p->ture_salary);
		printf("\n");
		employee[i].next=&employee[i+1];
		p=p->next;
		if(p==NULL)
			{	
				break;
			}
	}

};		

void save()			//保存函数
{
	if(n<=0)
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
		rewind(fp);
		fwrite( employee , sizeof(struct worker) , n , fp );
		for ( i = 0;i < n;i ++)
	{
		printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f",employee[i].id,employee[i].name,employee[i].post_salary,employee[i].job_salary,employee[i].age_salary,employee[i].ach_salary,employee[i].all_salary,employee[i].tax,employee[i].ture_salary);
		printf("\n");
	}
		fclose(fp);
	}	

}

void Exit();			//退出函数	

void open_file()		//打开文件函数
{

	FILE *fp = fopen("22.txt","rb");

	if(fp == NULL)
	{ 
		printf("can not open file!\n");
		getchar();
		exit(-1);
	}

	for( i = 0;i < 100;i ++)
	{
		int nRes = fscanf(fp,"%s%s%f%f%f%f%f%f%f",&employee[i].id,&employee[i].name,&employee[i].post_salary,&employee[i].job_salary,&employee[i].age_salary,&employee[i].ach_salary,&employee[i].all_salary,&employee[i].tax,&employee[i].ture_salary);
		
		if (nRes == -1)
		{
			n = i;
			fclose(fp);
			break;
		}	
		
	}

	printf("共有%d条记录被输入数组\n",n);

	/*for ( i = 0;i < n;i ++)
	{
		printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f",employee[i].id,employee[i].name,employee[i].post_salary,employee[i].job_salary,employee[i].age_salary,employee[i].ach_salary,employee[i].all_salary,employee[i].tax,employee[i].ture_salary);
		printf("\n");
	}
	*/
}

int main(){
	open_file();
	
return 0;
}

