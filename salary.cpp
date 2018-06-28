/******************************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
 File name: salary.c    // 文件名
 Author: Version: Date:     // 作者、版本及完成日期
 Description: // 用于详细说明此程序文件完成的主要功能，与其他模块
 // 或函数的接口，输出值、取值范围、含义及参数间的控
 // 制、顺序、独立或依赖等关系
 Others: // 其它内容的说明
 Function List: // 主要函数列表，每条记录应包括函数名及功能简要说明
 1. ....
 History: // 修改历史记录列表，每条修改记录应包括修改日期、修改

*******************************************************************************/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i = 0, j = 0;	//循环变量
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

void grsds(struct worker *q)    //计算个人所得税函数
{
    p = q;    //获得当前指针指向的员工
    int flag = 1;    //用于判断应得金额的位置
    double sum = 0;    //计算个人所得税总和

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

void add_worker()    //添加函数
{   
	int k;    //记录输入工号是否重复
	char gonghao[10];
	p = &employee[n];    //获取添加员工的地址
	printf("---------------------------添加--------------------------\n\n");
	printf("请输入添加员工的工号：");
	while(1)
	{
		scanf("%s",gonghao);

		for(i = 0;i < n;i++)
		{
			k=strcmp(gonghao,employee[i].id);
			
			if(k == 0)
			{
				printf("工号已存在,请重新输入:");	
				break;
			}
		}

		if(k!=0)
		{
			break;
		}
	}
	
	strcpy(p -> id,gonghao);
	
	printf("请输入添加员工的姓名：");
	scanf("%s",p -> name);
	
	printf("请输入添加员工的岗位工资：");
	scanf("%f",&(p -> post_salary));
	
	printf("请输入添加员工的薪级工资：");
	scanf("%f",&(p -> age_salary));
	
	printf("请输入添加员工的职务津贴：");
	scanf("%f",&(p -> job_salary));
	
	printf("请输入添加员工的效绩工资：");
	scanf("%f",&(p -> ach_salary));
	
	printf("\n");

	p -> all_salary 
		= p -> ach_salary 
		+ p -> job_salary 
		+ p -> post_salary 
		+ p -> age_salary;

	grsds(p);
	
	p = &employee[n];
	
	p -> ture_salary = p -> all_salary - p-> tax;
	
	printf("职工信息录入成功！\n");
	n = n + 1;
};	

void del_worker()       //删除函数
{
	int flag=0;    //用于判断员工是否删除
	int k=1;    //用于判断员工工号是否相等
	char gonghao[10];
	printf("---------------------------删除--------------------------\n\n");
	printf("请输入需要删除员工的工号:");
	scanf("%s",gonghao);
	
	for(i = 0;i < n;i++)
	{
		k = strcmp(gonghao,employee[i].id);
		if(k == 0)
		{
			printf("该职工信息：\n\n");

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
			
			printf("--------------------------------------\n");
			printf("请确认是否删除,确认删除请按1，放弃删除请按0\n");
			
			scanf("%d",&flag);

			if(flag==1)
			{
				for(j=i;j<n;j++)
				{
					employee[j]=employee[j+1];
				}
			}
			break;
		}
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

void seek_worker()		//查找函数
{
	int k=1;    //用于判断员工工号是否相等
	char gonghao[10];
	printf("---------------------------查询--------------------------\n\n");
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
	int k = 1;    //用于判断员工工号是否相等
	char gonghao[10];
	printf("---------------------------修改--------------------------\n\n");
	printf("请输入需要修改员工的工号:");
	scanf("%s",gonghao);
	for(i = 0 ; i < n;i++)
	{
		k = strcmp(gonghao , employee[i].id);
		if(k == 0)
		{
			printf("请输入员工工号：");
			scanf("%s", &employee[i].id);
			
			printf("姓名：");
			scanf("%s", &employee[i].name);
			
			printf("岗位工资：");
			scanf("%f", &employee[i].post_salary);
			
			printf("薪级工资：");
			scanf("%f", &employee[i].age_salary);
			
			printf("职务津贴:");
			scanf("%f", &employee[i].job_salary);
			
			printf("效绩工资:");
			scanf("%f", &employee[i].ach_salary);
			
			employee[i].all_salary = 
				employee[i].ach_salary 
				+ employee[i].job_salary 
				+ employee[i].post_salary 
				+ employee[i].age_salary;
			
			grsds(&employee[i]);
			
			employee[i].ture_salary = employee[i].all_salary - employee[i].tax;
			
			break;
		}
	}
	if(k!=0)
	{
		printf("该员工不存在\n");
	}
};	

void see_worker()    //浏览函数
{	
	printf("---------------------------浏览--------------------------\n\n");

	for ( i = 0;i < n;i++)
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

		for ( i = 0;i < n;i ++)    //写入文件
		{
			fprintf(fp,"%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f" ,
				employee[i].id , employee[i].name , employee[i].post_salary , 
				employee[i].job_salary , employee[i].age_salary , 
				employee[i].ach_salary , employee[i].all_salary , 
				employee[i].tax , employee[i].ture_salary);
			
			fprintf(fp,"\n");
		}
		
		fclose(fp);
	}
	
	printf("文件保存成功\n");

}
int Exit()	//退出函数	
{
	int flag = 1;    //用于判断是否退出循环
	int m;    //判断是否退出变量
	printf("---------------------------退出--------------------------\n\n");
	printf("您是否已保存文件，若未保存请选取是否保存\n1--Y\t0--N\n");
	while(flag)
	{
		scanf("%d",&m);
		switch(m)
		{
		case 0: flag=0;	break;
		case 1:	flag=0;	save();	break;
		default: printf("请选择1\tor\t0\n"); flag = 1;				
		}

	}
	printf("已安全退出\n");
	return flag;
};		

void open_file()		//打开文件函数
{
	FILE *fp = fopen("22.txt","rb");
	
	if(fp == NULL)
	{ 
		printf("can not open file!\n");
		getchar();
		exit(-1);
	}
	
	for( i = 0;i < 100; i++)
	{
		int nRes = fscanf(fp,"%s%s%f%f%f%f%f%f%f",
			&employee[i].id , &employee[i].name , &employee[i].post_salary , 
			&employee[i].job_salary , &employee[i].age_salary , 
			&employee[i].ach_salary , &employee[i].all_salary ,
			&employee[i].tax , &employee[i].ture_salary);
		
		if (nRes == -1)
		{
			n = i;
			fclose(fp);
			break;
		}	
		
	}

	for ( i = 0;i < n; i++)
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
	
	printf("共有%d条记录被输入数组\n",n);	
}

int main(){
	int member;    //作为选项参数
	int flag = 1;
	open_file();
	while(flag)
	{
		printf("\n");
		printf("\n");
		printf("---------------------------------------------------------------\n");
		printf("1、查询员工信息\t");
		printf("2、修改员工信息\t");
		printf("3、添加员工信息\t");
		printf("4、删除员工信息\n");
		printf("5、保存员工信息\t");
		printf("6、浏览员工信息\t");
		printf("7、退出程序\n");
		printf("请根据数字使用相应功能\n");
		printf("---------------------------------------------------------------\n");
		scanf("%d",&member);
		switch(member)
		{
		case 1:seek_worker();break;
		case 2:change_worker();break;
		case 3:add_worker();break;
		case 4:del_worker();break;
		case 5:save();break;
		case 6:see_worker();break;
		case 7:flag=Exit();break;
		default:printf("没有此功能");
		}
	}
    return 0;
}