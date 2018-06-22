#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i = 0;	//循环变量
int n = 0;    //员工总人数
struct worker{
	char id[10],name[20];   //员工工号和姓名
	float post_salary;		//岗位工资
	float age_salary;		//薪级工资	
	float job_salary;		//职务津贴
	float ach_salary;		//效绩工资
	float all_salary;		//应发工资
	float tax;				//个人所得税	
	float ture_salary;		//实发工资
}employee[50],*p;

void grsds()    //计算个人所得税函数
{
	
/*	if(p -> all_salary <= 500 && p -> all_salary >= 0)
	{
		p -> tax = p -> all_salary * 0.05;
	}
	else if(p -> all_salary > 500 && p -> all_salary <= 2000)
	{
		p -> tax= p -> all_salary * 0.1;
	}
	else if(p -> all_salary > 2000 && p -> all_salary <= 5000)
	{
		p -> tax = p -> all_salary * 0.15;
	}
	else if(p -> all_salary > 5000 && p -> all_salary <= 20000)
	{
		p -> tax = p -> all_salary * 0.2;
	}
	else if(p -> all_salary > 20000 && p -> all_salary <= 40000)
	{
		p -> tax = p -> all_salary * 0.25;
	}
	else if(p -> all_salary > 40000 && p -> all_salary <= 60000)
	{
		p -> tax = p -> all_salary * 0.3;
	}
	else if(p -> all_salary > 60000 && p -> all_salary <= 80000)
	{
		p -> tax = p -> all_salary * 0.35;
	}
	else if(p -> all_salary > 80000 && p -> all_salary <= 100000)
	{
		p -> tax = p -> all_salary * 0.4;
	}
	else if(p -> all_salary > 100000)
	{
		p -> tax = p -> all_salary * 0.45;
	}
	else
	{
	printf("数值为负");
	}*/
}	

void add_worker()    //添加函数
{   
	n++;
	p=&employee[n];
	printf("请输入添加员工的工号：");
	scanf("%s",&p -> id);
	printf("请输入添加员工的姓名：");
	scanf("%s",&p -> name);
	printf("请输入添加员工的岗位工资：");
	scanf("%s",&p -> post_salary);
	printf("请输入添加员工的薪级工资：");
	scanf("%s",&p -> age_salary);
	printf("请输入添加员工的职务津贴：");
	scanf("%s",&p -> job_salary);
	printf("请输入添加员工的效绩工资：");
	scanf("%s",&p -> ach_salary);
	printf("\n");
	//printf("应发工资：");
	p -> all_salary = p -> ach_salary + p -> job_salary + p -> post_salary + p -> age_salary;
	grsds();
	p -> ture_salary= p -> all_salary - p-> tax;
};	

void del_worker()       //删除函数
{
	int k;    //记录查找员工下标	
	char gonghao[10];
	printf("请输入需要删除员工的工号:");
	scanf("%s",gonghao);
	for(i=0;i<n;i++)
	{
		if(strcmp(gonghao,employee[i].id)==0)
		{
			printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f",employee[i].id,employee[i].name,employee[i].post_salary,employee[i].job_salary,employee[i].age_salary,employee[i].ach_salary,employee[i].all_salary,employee[i].tax,employee[i].ture_salary);
			printf("\n");
		}
	}
};		

void seek_worker()		//查找函数
{
	int k=1;    //记录查找员工下标	
	char gonghao[10];
	printf("请输入需要查找员工的工号:");
	scanf("%s",gonghao);
	for(i=0;i<n;i++)
	{	
		k=strcmp(gonghao,employee[i].id);

		if(k==0)
		{	
			printf("工号：");
			printf("%s\n",employee[i].id);

			printf("姓名：");
			printf("%s\n",employee[i].name);

			printf("岗位工资：");
			printf("%.2f\n",employee[i].post_salary);

			printf("薪级工资：");
			printf("%.2f\n",employee[i].job_salary);

			printf("职务津贴：");
			printf("%.2f\n",employee[i].age_salary);

			printf("效绩工资：");
			printf("%.2f\n",employee[i].ach_salary);

			printf("应发工资：");
			printf("%.2f\n",employee[i].all_salary);

			printf("个人所得税：");
			printf("%.2f\n",employee[i].tax);

			printf("实发工资：");
			printf("%.2f\n",employee[i].ture_salary);

			printf("\n");
			break;
		
		}
	}

	if(k!=0)
	{
		printf("该员工不存在\n");
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
			scanf("%s", &employee[i].id);
			printf("\n");
			printf("姓名：");
			scanf("%s", &employee[i].name);
			printf("\n");
			printf("岗位工资：");
			scanf("%f", &employee[i].post_salary);
			printf("\n");
			printf("薪级工资：");
			scanf("%f", &employee[i].age_salary);
			printf("\n");
			printf("职务津贴:");
			scanf("%f", &employee[i].job_salary);
			printf("\n");
			printf("效绩工资:");
			scanf("%f", &employee[i].ach_salary);
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

	for ( i = 0;i < n;i ++)
	{
		printf("工号：");
		printf("%s\n", employee[i].id);

		printf("姓名：");
		printf("%s\n", employee[i].name);

		printf("岗位工资：");
		printf("%.2f\n", employee[i].post_salary);

		printf("薪级工资：");
		printf("%.2f\n", employee[i].job_salary);

		printf("职务津贴：");
		printf("%.2f\n", employee[i].age_salary);

		printf("效绩工资：");
		printf("%.2f\n", employee[i].ach_salary);

		printf("应发工资：");
		printf("%.2f\n", employee[i].all_salary);

		printf("个人所得税：");
		printf("%.2f\n", employee[i].tax);

		printf("实发工资：");
		printf("%.2f\n", employee[i].ture_salary);

		printf("\n");
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

	//	fwrite( employee , sizeof(struct worker) , n , fp );
	
	/*	for ( i = 0;i < n;i ++)
		{
		}		
*/
	for ( i = 0;i < n;i ++)
	{
		fprintf(fp,"%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f",employee[i].id,employee[i].name,employee[i].post_salary,employee[i].job_salary,employee[i].age_salary,employee[i].ach_salary,employee[i].all_salary,employee[i].tax,employee[i].ture_salary);
		fprintf(fp,"\n");
		printf("\n");
	}
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

	for( i = 0;i < 100; i ++ )
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

	for ( i = 0;i < n;i ++)
	{
		printf("%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f",employee[i].id,employee[i].name,employee[i].post_salary,employee[i].job_salary,employee[i].age_salary,employee[i].ach_salary,employee[i].all_salary,employee[i].tax,employee[i].ture_salary);
		printf("\n");
	}
	
}

int main(){
int member;
int flag = 1;
open_file();
while(flag)
{
	printf("\n");
	printf("\n");
	printf("***************************************************************************\n");
	printf("1、查询员工信息\t");
	printf("2、浏览员工信息\t");
	printf("3、修改员工信息\t");
	printf("4、添加员工\n");
	printf("5、删除员工\t");
	printf("6、保存员工信息\t");
	printf("7、退出程序\n");
	printf("请根据数字使用相应功能\n");
	printf("***************************************************************************\n");
	scanf("%d",&member);
	switch(member)
	{
	case 1:seek_worker();break;
	case 2:see_worker();break;
	case 3:change_worker();break;
	//case 4:add_worker();break;
	case 5:del_worker();break;
	case 6:save();break;	
	case 7: flag = 0; break;
	default:printf("没有此功能");
	}
}	
return 0;
}

