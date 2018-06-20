#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0;	//循环变量
int n=0;    //员工总人数
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
void in_file();			
void out_file();
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

void change_worker();	//修改函数

void see_worker();		//浏览函数

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
	save();
return 0;
}

