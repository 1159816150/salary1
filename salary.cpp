#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0;	//ѭ������
int n=0;    //Ա��������
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
void in_file();			
void out_file();
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

void change_worker();	//�޸ĺ���

void see_worker();		//�������

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
	save();
return 0;
}

