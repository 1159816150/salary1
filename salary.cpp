#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i = 0;	//ѭ������
int n = 0;    //Ա��������
struct worker{
	char id[10],name[20];   //Ա�����ź�����
	float post_salary;		//��λ����
	float age_salary;		//н������	
	float job_salary;		//ְ�����
	float ach_salary;		//Ч������
	float all_salary;		//Ӧ������
	float tax;				//��������˰	
	float ture_salary;		//ʵ������
}employee[50],*p;

void grsds()    //�����������˰����
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
	printf("��ֵΪ��");
	}*/
}	

void add_worker()    //��Ӻ���
{   
	n++;
	p=&employee[n];
	printf("���������Ա���Ĺ��ţ�");
	scanf("%s",&p -> id);
	printf("���������Ա����������");
	scanf("%s",&p -> name);
	printf("���������Ա���ĸ�λ���ʣ�");
	scanf("%s",&p -> post_salary);
	printf("���������Ա����н�����ʣ�");
	scanf("%s",&p -> age_salary);
	printf("���������Ա����ְ�������");
	scanf("%s",&p -> job_salary);
	printf("���������Ա����Ч�����ʣ�");
	scanf("%s",&p -> ach_salary);
	printf("\n");
	//printf("Ӧ�����ʣ�");
	p -> all_salary = p -> ach_salary + p -> job_salary + p -> post_salary + p -> age_salary;
	grsds();
	p -> ture_salary= p -> all_salary - p-> tax;
};	

void del_worker()       //ɾ������
{
	int k;    //��¼����Ա���±�	
	char gonghao[10];
	printf("��������Ҫɾ��Ա���Ĺ���:");
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

void seek_worker()		//���Һ���
{
	int k=1;    //��¼����Ա���±�	
	char gonghao[10];
	printf("��������Ҫ����Ա���Ĺ���:");
	scanf("%s",gonghao);
	for(i=0;i<n;i++)
	{	
		k=strcmp(gonghao,employee[i].id);

		if(k==0)
		{	
			printf("���ţ�");
			printf("%s\n",employee[i].id);

			printf("������");
			printf("%s\n",employee[i].name);

			printf("��λ���ʣ�");
			printf("%.2f\n",employee[i].post_salary);

			printf("н�����ʣ�");
			printf("%.2f\n",employee[i].job_salary);

			printf("ְ�������");
			printf("%.2f\n",employee[i].age_salary);

			printf("Ч�����ʣ�");
			printf("%.2f\n",employee[i].ach_salary);

			printf("Ӧ�����ʣ�");
			printf("%.2f\n",employee[i].all_salary);

			printf("��������˰��");
			printf("%.2f\n",employee[i].tax);

			printf("ʵ�����ʣ�");
			printf("%.2f\n",employee[i].ture_salary);

			printf("\n");
			break;
		
		}
	}

	if(k!=0)
	{
		printf("��Ա��������\n");
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
			scanf("%s", &employee[i].id);
			printf("\n");
			printf("������");
			scanf("%s", &employee[i].name);
			printf("\n");
			printf("��λ���ʣ�");
			scanf("%f", &employee[i].post_salary);
			printf("\n");
			printf("н�����ʣ�");
			scanf("%f", &employee[i].age_salary);
			printf("\n");
			printf("ְ�����:");
			scanf("%f", &employee[i].job_salary);
			printf("\n");
			printf("Ч������:");
			scanf("%f", &employee[i].ach_salary);
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

	for ( i = 0;i < n;i ++)
	{
		printf("���ţ�");
		printf("%s\n", employee[i].id);

		printf("������");
		printf("%s\n", employee[i].name);

		printf("��λ���ʣ�");
		printf("%.2f\n", employee[i].post_salary);

		printf("н�����ʣ�");
		printf("%.2f\n", employee[i].job_salary);

		printf("ְ�������");
		printf("%.2f\n", employee[i].age_salary);

		printf("Ч�����ʣ�");
		printf("%.2f\n", employee[i].ach_salary);

		printf("Ӧ�����ʣ�");
		printf("%.2f\n", employee[i].all_salary);

		printf("��������˰��");
		printf("%.2f\n", employee[i].tax);

		printf("ʵ�����ʣ�");
		printf("%.2f\n", employee[i].ture_salary);

		printf("\n");
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

	printf("����%d����¼����������\n",n);

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
	printf("1����ѯԱ����Ϣ\t");
	printf("2�����Ա����Ϣ\t");
	printf("3���޸�Ա����Ϣ\t");
	printf("4�����Ա��\n");
	printf("5��ɾ��Ա��\t");
	printf("6������Ա����Ϣ\t");
	printf("7���˳�����\n");
	printf("���������ʹ����Ӧ����\n");
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
	default:printf("û�д˹���");
	}
}	
return 0;
}

