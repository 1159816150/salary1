#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0;	//ѭ������
int n=0;    //Ա��������
struct worker{
	char id[10],name[20];   //Ա�����ź�����
	double post_salary;		//��λ����
	double age_salary;		//н������	
	double job_salary;		//ְ�����
	double ach_salary;		//Ч������
	double all_salary;		//Ӧ������
	double tax;				//��������˰	
	double ture_salary;		//ʵ������
	struct worker *next;
}employee[50],*p;
void grsds()    //�����������˰����
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
	printf("��ֵΪ��");
	}
}	//�����������˰����

void add_worker();		//��Ӻ���

void del_worker();		//ɾ������

void seek_worker()		//���Һ���
{		
	char gonghao[10];
	printf("��������Ҫ����Ա���Ĺ���:");
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

void change_worker()    //�޸ĺ���
{
	char gonghao[10];
	printf("��������Ҫ�޸�Ա���Ĺ���:");
	gets(gonghao);

	for(i=0;i<n;i++)
	{
		if(strcmp(gonghao,employee[i].id)==0)
		{
			printf("������Ա�����ţ�");
			scanf("%s",&employee[i].id);
			printf("\n");
			printf("������");
			scanf("%s",&employee[i].name);
			printf("\n");
			printf("��λ���ʣ�");
			scanf("%f",&employee[i].post_salary);
			printf("\n");
			printf("н�����ʣ�");
			scanf("%f",&employee[i].age_salary);
			printf("\n");
			printf("ְ�����:");
			scanf("%f",&employee[i].job_salary);
			printf("\n");
			printf("Ч������:");
			scanf("%f",&employee[i].ach_salary);
			printf("\n");
			//printf("Ӧ�����ʣ�");
			employee[i].all_salary=employee[i].ach_salary+employee[i].job_salary+employee[i].post_salary+employee[i].age_salary;
			grsds();
			employee[i].ture_salary=employee[i].all_salary-employee[i].tax;
		}
		else
		{
			printf("��Ա��������\n");
		}
	}
};	

void see_worker()    //�������
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

void save()			//���溯��
{
	if(n<=0)
	{
	printf("������Ա��");
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

void Exit();			//�˳�����	

void open_file()		//���ļ�����
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

	printf("����%d����¼����������\n",n);

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

