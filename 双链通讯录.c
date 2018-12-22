#include<stdio.h>
#include<windows.h>
#include <conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int i = 0, j = 0;	//ѭ������
int n = 0;    //Ա��������
typedef struct dnode{
int number;
char name[20];
int counter;
struct dnode *prev,*next;
}dlnode;
dlnode *createlist()       //������n��Ԫ�ص�˫������ 
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

	while(!feof(fp))   //���ļ��������ζ���ṹ��
	{
		q = (dlnode *)malloc(sizeof(dlnode));
		p->next = q;
		head->prev = q;
		q->prev = p;
		q->next = head;
		p = q;	

		fscanf(fp,"%d%s%d",
			&q->number , &q->name , &q->counter);
		
		n = n + 1;    //ÿ����һ������һ��������
	}

	(q->prev)->next = q->next;    //����while����feof��fp�����������һ������
	(q->next)->prev = q->prev;
	free(q);    //�����������
	n = n - 1;    //��������һ
	fclose(fp);

	printf("����%d����¼����ȡ\n\n",n);
	printf("press any key to continue");
	getch();
	system("cls");

	return head;
}

int add_goods(dlnode *head)    //��ӻ��ﺯ��
{
	int k;    //��¼���빤���Ƿ��ظ�
	int bianhao;    //���������
	dlnode *p,*q;  
	
	p = head;    //��p�õ�����β��
	p->prev = head->prev;
	p = head->prev->next;
	head = p->next;
	head->prev = p;

	q = (dlnode *)malloc(sizeof(dlnode));    //����ڵ�
	(p->prev)->next = q;
	q->prev = p->prev;
	q->next = p;
	p->prev = q;
	printf("---------------------------���--------------------------\n\n");
	printf("��������ӻ����ţ�");
	p = head;
	p = p->next;
	while(1)    //�����ṹ�����飬�������޸ñ�ŵĻ���
	{
		scanf("%d",&bianhao);

		for(i = 0;i < n+2; i++)
		{
			p = p->next;
			if(bianhao==p->number)
			{
				printf("�������Ѵ���,�Ƿ��������룿:\n");
				printf("��Ҫ��������������1�����˳������������\n");
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

	printf("��������ӻ������ƣ�");
	scanf("%s",q -> name);

	printf("��������ӻ���������");
	scanf("%d",&q -> counter);

	printf("������Ϣ¼��ɹ���\n");
	n = n + 1;
	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
	return 0;
};	

void del_goods(dlnode *head)       //ɾ������
{
	int flag = 0;    //�����жϻ����Ƿ�ɾ��
	int k = 1;    //�����жϻ������Ƿ����
    int bianhao;   //���������
	dlnode *p;
	p = head;
	p = p->next;

	printf("---------------------------ɾ��--------------------------\n\n");
	printf("��������Ҫɾ��������:");
	scanf("%d",&bianhao);
		
	if(p->number!=bianhao)
	{
		printf("�û��ﲻ����\n");

		system("pause");
	}

	while(p != head)
	{
	
		if(bianhao==p->number)
		{


		    printf("�����ţ�");
     	    printf("%d\n",p -> number);

        	printf("�������ƣ�");
        	printf("%s\n",p -> name);

    	    printf("����������");
        	printf("%d\n",p -> counter);

	        printf("\n");
			printf("\n---------------------------------------------------------\n");
			printf("��ȷ���Ƿ�ɾ��,ȷ��ɾ���밴1������ɾ���밴0\n");
			
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

void seek_goods(dlnode *head)		//���Һ���
{
	int k = 1;    //�����жϻ������Ƿ����
	int bianhao;
	dlnode *p;
	p = head;
	p = p->next;
	printf("---------------------------��ѯ--------------------------\n\n");
	printf("��������Ҫ���һ���ı��:");
	scanf("%d",&bianhao);
	while(p != head)
	{
	
		if(bianhao==p->number)
		{
			printf("�û�����Ϣ��\n\n");

		    printf("�����ţ�");
     	    printf("%d\n",p -> number);

        	printf("�������ƣ�");
        	printf("%s\n",p -> name);

    	    printf("����������");
        	printf("%d\n",p -> counter);

	        printf("\n");
			
			printf("\n---------------------------------------------------------\n");
		break;
			
		}

		p = p->next;
	}

	if(bianhao!=p->number)
	{
		printf("�û��ﲻ����\n");
	}

	printf("\n\n");
	printf("press any key to continue");
	getch();
	system("cls");
}

void change_goods(dlnode *head)    //�޸ĺ���
{
	int k = 1;    //�����жϻ������Ƿ����
	int bianhao;
	dlnode *p;
	p = head;
	p = p->next;
	
	printf("---------------------------�޸�--------------------------\n\n");
	printf("��������Ҫ�޸Ļ���ı��:");
	scanf("%d",&bianhao);
	if(bianhao!=p->number)
	{
		printf("�û��ﲻ����\n");
	
		getch();
		system("cls");
	}

	while(p != head)
	{
	
		if(bianhao==p->number)
		{
			printf("�������޸Ļ����ţ�");
        	scanf("%d",&p -> number);

        	printf("�������޸Ļ������ƣ�");
        	scanf("%s",&p -> name);

	        printf("�������޸Ļ���������");
        	scanf("%d",&p -> counter);
        	printf("\n");
			
			printf("�޸ĳɹ�\n");
			getchar();
			system("pause");
			break;
		}

		p=p->next;
	}

	
	system("cls");
};
	
void see_goods(dlnode *head)    //�������
{
	dlnode *p;
	int i=1;
	p = head;
	p = p->next;

	printf("---------------------------���--------------------------\n\n");

	printf("������Ϣ���£�\n");

	while(p != head)
	{
		printf("\n");

		printf("�ڡ�%d����������Ϣ��\n",i);

	    printf("�����ţ�");
        printf("%d\n",p -> number);

      	printf("�������ƣ�");
       	printf("%s\n",p -> name);

        printf("����������");
       	printf("%d\n",p -> counter);
		i++;
		p = p->next;
	}

	printf("\n---------------------------------------------------------\n");
	printf("press any key to continue");
	getch();
	system("cls");
};		
	
void save(dlnode *head)			//���溯��
{
	dlnode *p;
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
			fprintf(fp,"%d %s %d\n\t" ,
				p->number , p->name , p->counter);
			
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
	dlnode *head;
	int choose;    //��Ϊѡ�����
	int flag = 1;    //��Ϊѭ�������ж�
	head = createlist();    //��ȡͷ���
	while(flag)
	{
		printf("\t###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###\n\n");
		printf("\t��ѡ��<1 - 7>:\n");
		printf("\t===============================================================\n");
		printf("\t|\t1.��ѯ������Ϣ                                        |\n");
		printf("\t|\t2.�޸Ļ�����Ϣ                                        |\n");
		printf("\t|\t3.��ӻ�����Ϣ                                        |\n");
		printf("\t|\t4.ɾ��������Ϣ                                        |\n");
		printf("\t|\t5.�������ݵ��ļ�                                      |\n");
		printf("\t|\t6.��������¼                                        |\n");
		printf("\t|\t7.�˳�ϵͳ                                            |\n");
		printf("\t===============================================================\n\n");
		printf("\t���ѡ���ǣ�\n");
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
		default:printf("û�д˹���\n\n");
		}
	}


return 0;
}