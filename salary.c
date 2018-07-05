/******************************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
 File name: salary.c    // �ļ���
 Author: ����      Version: 0.1    Date:2018.06.28     // ���ߡ��汾���������
 Description:  ���ڼ���Ա���Ĺ��� // ������ϸ˵���˳����ļ���ɵ���Ҫ���ܣ�������ģ��
                                  // �����Ľӿڣ����ֵ��ȡֵ��Χ�����弰������Ŀ�
                                  // �ơ�˳�򡢶����������ȹ�ϵ
 Others: �ɼ����������˰ // �������ݵ�˵��
 Function List: // ��Ҫ�����б�ÿ����¼Ӧ���������������ܼ�Ҫ˵��

 1.void grsds(struct worker *q)    //�����������˰����
 2.void add_worker()    //���Ա������
 3.void del_worker()       //ɾ��Ա������
 4.void seek_worker()		//����Ա������
 5.void change_worker()    //�޸�Ա����Ϣ����
 6.void see_worker()    //�������
 7.int Exit()	//    �˳�������

 History: // �޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸�

*******************************************************************************/
#include<stdio.h>
#include<windows.h>
#include <conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int i = 0, j = 0;	//ѭ������
int n = 0;    //Ա��������
typedef struct worker
{
    char id[10],name[20];    //Ա�����ź�����
    float post_salary;    //��λ����
    float age_salary;    //н������	
    float job_salary;    //ְ�����
    float ach_salary;    //Ч������
    float all_salary;    //Ӧ������
    float tax;    //��������˰	
    float ture_salary;    //ʵ������
    struct worker *prev;   
    struct worker *next;
}employee;

employee *createlist()       //������n��Ԫ�ص�˫������ 
{
	FILE *fp = fopen("gx.dat","rb");
	employee *head, *p, *q, *s;
	head = (employee *)malloc(sizeof(employee));
	head->prev = head;
	head->next = head;
	p = head;

	if(fp == NULL)
	{ 
		printf("can not open file!\n");
		getch();
		exit(-1);
	}

	while(!feof(fp))   //���ļ���Ա���ζ���ṹ��
	{
		q = (employee *)malloc(sizeof(employee));
		p->next = q;
		head->prev = q;
		q->prev = p;
		q->next = head;
		p = q;	

		fscanf(fp,"%s%s%f%f%f%f%f%f%f",
			&q->id , &q->name , &q->post_salary , 
			&q->job_salary , &q->age_salary , 
			&q->ach_salary , &q->all_salary ,
			&q->tax , &q->ture_salary);
		
		n = n + 1;
	}

	(q->prev)->next = q->next;
	(q->next)->prev = q->prev;
	free(q);
	n = n - 1;
	fclose(fp);
	printf("����%d����¼����ȡ\n\n",n);
	printf("press any key to continue");
	getch();
	system("cls");

	return head;
}

void grsds(struct worker *q)    //�����������˰����
{
    int flag = 1;    //�����ж�Ӧ�ý���λ��
    double sum = 0;    //�����������˰�ܺ�
    employee *p = q;    //��õ�ǰָ��ָ���Ա��
   

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
		printf("��ֵΪ��");
		return;
	}

	p -> tax = sum;

}

void add_worker(employee *head,int m)    //���Ա������
{
	int k;    //��¼���빤���Ƿ��ظ�
	char gonghao[10];    //����Ա������
	employee *p,*q;  
	
	p = head;    //��p�õ�����β��
	p->prev = head->prev;
	p = head->prev->next;
	head = p->next;
	head->prev = p;

	q = (employee *)malloc(sizeof(employee));    //����ڵ�
	(p->prev)->next = q;
	q->prev = p->prev;
	q->next = p;
	p->prev = q;
	printf("---------------------------���--------------------------\n\n");
	printf("���������Ա���Ĺ��ţ�");
	p = head;
	p = p->next;
	while(1)    //�����ṹ�����飬�������޸ñ�ŵ�Ա��
	{
		scanf("%s",gonghao);

		for(i = 0;i < n+2; i++)
		{
			k=strcmp(gonghao,p->id);
			p = p->next;
			if(k == 0)
			{
				printf("�����Ѵ���,����������:");	
				break;
			}
		}

		if(k != 0)
		{
			break;
		}
	}
	
	strcpy(q -> id,gonghao);
	
	printf("���������Ա����������");
	scanf("%s",q -> name);
	
	printf("���������Ա���ĸ�λ���ʣ�");
	scanf("%f",&(q -> post_salary));
	
	printf("���������Ա����н�����ʣ�");
	scanf("%f",&(q -> age_salary));
	
	printf("���������Ա����ְ�������");
	scanf("%f",&(q -> job_salary));
	
	printf("���������Ա����Ч�����ʣ�");
	scanf("%f",&(q -> ach_salary));
	
	printf("\n");

	q -> all_salary 
		= q -> ach_salary 
		+ q -> job_salary 
		+ q -> post_salary 
		+ q -> age_salary;

	grsds(q);
	
	q -> ture_salary = q -> all_salary - q-> tax;
	
	printf("ְ����Ϣ¼��ɹ���\n");
	n = n + 1;
	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
};	

void del_worker(employee *head)       //ɾ������
{
	int flag = 0;    //�����ж�Ա���Ƿ�ɾ��
	int k = 1;    //�����ж�Ա�������Ƿ����
	char gonghao[10];    //����Ա������
	employee *p;
	p = head;
	p = p->next;

	printf("---------------------------ɾ��--------------------------\n\n");
	printf("��������Ҫɾ��Ա���Ĺ���:");
	scanf("%s",gonghao);
	
	while(p!=head)
	{
		k = strcmp(gonghao,p->id);
		if(k == 0)
		{
			printf("��ְ����Ϣ��\n\n");

			printf("���ţ�");
			printf("%s\n", p->id);
			
			printf("������");
			printf("%s\n", p->name);
			
			printf("��λ���ʣ�");
			printf("%.2f\n", p->post_salary);
			
			printf("н�����ʣ�");
			printf("%.2f\n", p->job_salary);
			
			printf("ְ�������");
			printf("%.2f\n", p->age_salary);
			
			printf("Ч�����ʣ�");
			printf("%.2f\n", p->ach_salary);
			
			printf("Ӧ�����ʣ�");
			printf("%.2f\n", p->all_salary);
			
			printf("��������˰��");
			printf("%.2f\n", p->tax);
			
			printf("ʵ�����ʣ�");
			printf("%.2f\n", p->ture_salary);
			printf("\n---------------------------------------------------------\n");
			printf("��ȷ���Ƿ�ɾ��,ȷ��ɾ���밴1������ɾ���밴0\n");
			
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
		printf("��Ա��������\n");
		getchar();
	}
	
	if(flag)
	{
		n=n-1;
		printf("ɾ���ɹ�\n");
	}
	else
	{
		printf("ȡ��ɾ��\n");
	}
	
	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
};		

void seek_worker(employee *head)		//���Һ���
{
	int k = 1;    //�����ж�Ա�������Ƿ����
	char gonghao[10];
	employee *p;
	p = head;
	p = p->next;
	printf("---------------------------��ѯ--------------------------\n\n");
	printf("��������Ҫ����Ա���Ĺ���:");
	scanf("%s",gonghao);
	while(p!=head)
	{
		k = strcmp(gonghao,p->id);
		if(k == 0)
		{
			printf("��ְ����Ϣ��\n\n");

			printf("���ţ�");
			printf("%s\n", p->id);
			
			printf("������");
			printf("%s\n", p->name);
			
			printf("��λ���ʣ�");
			printf("%.2f\n", p->post_salary);
			
			printf("н�����ʣ�");
			printf("%.2f\n", p->job_salary);
			
			printf("ְ�������");
			printf("%.2f\n", p->age_salary);
			
			printf("Ч�����ʣ�");
			printf("%.2f\n", p->ach_salary);
			
			printf("Ӧ�����ʣ�");
			printf("%.2f\n", p->all_salary);
			
			printf("��������˰��");
			printf("%.2f\n", p->tax);
			
			printf("ʵ�����ʣ�");
			printf("%.2f\n", p->ture_salary);
			
			printf("\n---------------------------------------------------------\n");
		break;
			
		}

		p = p->next;
	}

	if(k != 0)
	{
		printf("��Ա��������\n");
		printf("press any key to continue");
	}

	printf("\n\n");
	printf("press any key to continue");
	getch();
	system("cls");
}

void change_worker(employee *head)    //�޸ĺ���
{
	int k = 1;    //�����ж�Ա�������Ƿ����
	char gonghao[10];
	employee *p;
	p = head;
	p = p->next;
	
	printf("---------------------------�޸�--------------------------\n\n");
	printf("��������Ҫ�޸�Ա���Ĺ���:");
	scanf("%s",gonghao);
	while(p!=head)
	{
		k = strcmp(gonghao , p->id);
		if(k == 0)
		{
			printf("������Ա�����ţ�");
			scanf("%s", &p->id);
			
			printf("������");
			scanf("%s", &p->name);
			
			printf("��λ���ʣ�");
			scanf("%f", &p->post_salary);
			
			printf("н�����ʣ�");
			scanf("%f", &p->age_salary);
			
			printf("ְ�����:");
			scanf("%f", &p->job_salary);
			
			printf("Ч������:");
			scanf("%f", &p->ach_salary);
			
			p->all_salary = 
				p->ach_salary 
				+ p->job_salary 
				+ p->post_salary 
				+ p->age_salary;
			
			grsds(p);
			
			p->ture_salary = p->all_salary - p->tax;
		
			printf("�޸ĳɹ�\n");
			break;
		}

		p=p->next;
	}
	if(k!=0)
	{
		printf("��Ա��������\n");
		printf("press any key to continue");
		getch();
		system("cls");
	}
	
	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
};
	
void see_worker(employee *head)    //�������
{
	employee *p;
	p = head;
	p = p->next;

	printf("---------------------------���--------------------------\n\n");

	printf("ְ����Ϣ���£�\n");
	printf("����\t����\t��λ����\tн������\tְ�����\tЧ������\tӦ������\t��������˰\tʵ������\t\n");

	while(p!=head)
	{
		printf("\n");

		printf("%s\t", p->id);
			
		printf("%s\t", p->name);
			
		printf("%.2f\t\t", p->post_salary);
			
		printf("%.2f\t\t", p->job_salary);
			
		printf("%.2f\t\t", p->age_salary);
			
		printf("%.2f\t\t", p->ach_salary);
			
		printf("%.2f\t\t", p->all_salary);

		p->all_salary = 
			p->ach_salary 
			+ p->job_salary 
			+ p->post_salary 
			+ p->age_salary;
			
		grsds(p);
			
		p->ture_salary = p->all_salary - p->tax;
		
		printf("%.2f\t\t", p->tax);
			
		printf("%.2f\t\t", p->ture_salary);

		p = p->next;
	}

	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
};		
	
void save(employee *head)			//���溯��
{
	employee *p;
	p = head;
	p = p->next;

	printf("---------------------------����--------------------------\n\n");
	
	if(n <= 0)
	{
		printf("������Ա��");
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
		
		while(p != head)    //д���ļ�
		{
			fprintf(fp,"%s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n\t" ,
				p->id , p->name , p->post_salary , 
				p->job_salary , p->age_salary , 
				p->ach_salary , p->all_salary , 
				p->tax , p->ture_salary);
			
			fprintf(fp,"\n");
			p = p->next;
		} 
		
		fclose(fp);
	}
	
	printf("�ļ�����ɹ�\n");
	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
}

int Exit()	//�˳�����	
{
	int flag = 0;
	printf("---------------------------�˳�--------------------------\n\n");
	printf("�Ѱ�ȫ�˳�\n");
	printf("\n---------------------------------------------------------\n");
	return flag;
};		

int main()
{
	employee *head;
	int choose;    //��Ϊѡ�����
	int flag = 1;    //��Ϊѭ�������ж�
	head = createlist();    //��ȡͷ���
	while(flag)
	{
		printf("\t###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###\n\n");
		printf("\t��ѡ��<1 - 7>:\n");
		printf("\t===============================================================\n");
		printf("\t|\t1.��ѯְ�����ʼ�¼                                    |\n");
		printf("\t|\t2.�޸�ְ�����ʼ�¼                                    |\n");
		printf("\t|\t3.���ְ�����ʼ�¼                                    |\n");
		printf("\t|\t4.ɾ��ְ�����ʼ�¼                                    |\n");
		printf("\t|\t5.�������ݵ��ļ�                                      |\n");
		printf("\t|\t6.���ְ����¼                                        |\n");
		printf("\t|\t7.�˳�ϵͳ                                            |\n");
		printf("\t===============================================================\n\n");
		printf("\t���ѡ���ǣ�\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:seek_worker(head);break;
		case 2:change_worker(head);break;
		case 3:add_worker(head,n);break;
		case 4:del_worker(head);break;
		case 5:save(head);break;
		case 6:see_worker(head);break;
		case 7:flag=Exit();break;
		default:printf("û�д˹���\n\n");
		}
	}


return 0;
}