#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct EMPLOYEE
{
	char id[10];    //Ա��ID
	char name[20];       //Ա������
	char Employee_Post[20];       //Ա����λ
	int Employee_Post_Rank;    //��λ�ȼ�
	int Working_Years;     //����*
	int Attendance_Days;    //��������*
	int Overtime_Days;    //�Ӱ�����*
	float Base_Salary;    //��������
	float Post_Salary;    //��λ����
	float Ach_Salary;    //��Ч����
	int Ach_Score;       //��Ч����
	float Skill_Wage;    //���ܹ���
	float Seniority_Wage;      //���乤��
	float Subsistence_Allowance;  //�������
	float Overtime_Pay;   //�Ӱ๤��
	float Bonus;          //����
	float All_Salary;    //Ӧ������
}EMPLOYEE[100];

int n = 0;  //��¼ְ��������ȫ�ֱ���

void Menu();    //ϵͳ����˵�
int Read_Record();        //��ȡ��¼����
int Save_Record();       //�����¼����
void List();        //��������
void Insert();         //��Ӻ���
void Get_Salary(int i);
void Input_Data();    //����Ա��������Ϣ
void Show_Data();    //��ӡԱ��������Ϣ

int main()
{
    char s[5], ch[5];
    int flag = 1;    //���ڿ���ѭ����
    Read_Record();

    while(flag)
    {
		Menu();
        printf("\n\n\t");
        printf("���ѡ���ǣ�");
        scanf("%s",  s);
        printf("\n\t");
		if(strcmp(s ,"1") == 0)
        {
			printf("\n\n\n\t");
            printf("�˹���δ����");
			getchar();
        }
        else if(strcmp(s ,"2") == 0)
        {
			printf("\n\n\n\t");
            printf("�˹���δ����");
			getchar();
        }
        else if(strcmp(s ,"3") == 0)
        {
            if(n < 100)
            {
                Insert();  //С��100�����ݣ�������Ӻ���
            }
            else
            {
                printf("\n\t�����������ƣ�\n\n");
				getchar();
            }
        }
        else if(strcmp(s ,"4") == 0)
        {
			printf("\n\n\n\t");
            printf("�˹���δ����");
			getchar();
        }
        else if(strcmp(s ,"5") == 0)
        {
            Save_Record();  //���ñ��溯��
        }
        else if(strcmp(s ,"6") == 0)
        {
            List();  //�����������
			getchar();
        }
        else if(strcmp(s ,"7") == 0)
        {
            printf("\n\t�Ƿ���Ҫ�����������ݣ��ǣ�y���������ַ�\n\t");
            scanf("%s", ch);

            if(strcmp(ch, "y") == 0)
            {
                Save_Record();  //�˳�ʱ��ѡ���Ƿ���ú�����������
				getchar();
            }

            printf("\n\t");
            printf("---------------------------�������˳�---------------------------");
            printf("\n\t");
            flag = 0;
        }
        else
        {
            printf("\n\t�޸�ָ����������룡\n\n");
			getchar();
        }
    }
    return 0;
}

void Menu()
{
	system("cls");
	printf("\n\n\n\t");
	printf("==========================���ʹ���ϵͳ==========================");
	printf("\n\n\n\t");
	printf("��ѡ��1 - 7����\n\t");
	printf("================================================================");
	printf("\n\t");
	printf("|        1. ��ѯְ�����ʼ�¼��unfinish��                       |");
	printf("\n\t");
	printf("|        2. �޸�ְ�����ʼ�¼��unfinish��                       |");
	printf("\n\t");
	printf("|        3. ���ְ�����ʼ�¼                                   |");
	printf("\n\t");
	printf("|        4. ɾ��ְ�����ʼ�¼(unfinish)                         |");
	printf("\n\t");
	printf("|        5. �����¼���ļ�                                     |");
	printf("\n\t");
	printf("|        6. ����ְ�����ʼ�¼                                   |");
	printf("\n\t");
	printf("|        7. �˳�ϵͳ                                           |");
	printf("\n\t");
	printf("================================================================");
}

int Read_Record()    //��ȡ�ļ���Ա����������
{
	FILE *fp = fopen("Salary.dat","rb");
	int i, nRes;  //i ���ڿ���ѭ���壬nRes�����ж��ļ���ȡ�Ƿ���ȷ
    if(fp == NULL)    //�򿪵�ǰĿ¼���ļ�
    {
        printf("\n\t�ļ���ʧ�ܣ�\n\t");
        printf("\n\tPress any key");
		getchar();
        return 0;  //�ļ���ʧ�ܣ�ֱ�ӻص�������
    }
	while(1)
    {
        if(fread(&EMPLOYEE[i], sizeof(EMPLOYEE[i]), 1, fp)==0)//�ж��Ƿ�����ļ�β
        {
            break;
        }
		EMPLOYEE[i].All_Salary = EMPLOYEE[i].Base_Salary + EMPLOYEE[i].Post_Salary
			+ EMPLOYEE[i].Ach_Salary + EMPLOYEE[i].Skill_Wage + EMPLOYEE[i].Seniority_Wage
			+ EMPLOYEE[i].Subsistence_Allowance + EMPLOYEE[i].Overtime_Pay + EMPLOYEE[i].Bonus;
    }
	n = i;
	
    printf("\n\t��д��%d������\n", n);
    printf("\n\tPress any key...");
    getchar();
    system("cls");
	fclose(fp);
}

int Save_Record()  //����ְ���������ݺ���
{  
    //ֻд�򿪻��߽���һ���������ļ���ֻ����д����
    FILE *fp = fopen("Salary.dat","wb");
    int i;

	if(n <= 0)
	{
		printf("\n\tְԱ����Ϊ��\n\t");
        return 0;  //�ļ���ʧ�ܣ�ֱ�ӻص�������
	}
    else if(fp == NULL)  //�򿪵�ǰĿ¼���ļ�
    {
        printf("\n\t�ļ���ʧ�ܣ�\n\t");
        return 0;  //�ļ���ʧ�ܣ�ֱ�ӻص�������
    }
    for (i = 0; i < n; i ++)
    {
        fwrite(&(EMPLOYEE[i]), sizeof(EMPLOYEE[i]), 1, fp); //������д��������ļ�
    }

    fclose(fp);  //�ر��ļ�

    printf("\n\t");
    printf("-------------------------�ļ�������ϣ�-------------------------");
    printf("\n");
	getchar();
    return 0;
}

void List()
{
    int i;
    printf("\n\t");
    printf("------------------------���ְ����������------------------------");
    
    for(i = 0; i < n; i ++)
    {
        Show_Data(i);  //ͨ��ѭ����ʾ����ְԱ������Ϣ
    }
    printf("\n\t");
    printf("----------------------------�������----------------------------");
	getchar();
}

void Insert()
{
	char s[10];  //��¼Ҫ���ְԱ�Ĺ���
    int i;
    int flag = 1;  //����ѭ����
    int flag_1 = 0;  //�����Ƿ���������

    printf("\n\t");
    printf("------------------------------���------------------------------");
    printf("\n\t������ְ��������Ϣ��\n");

    while(flag)
    {
        printf("\n\tְԱ���ţ�");
        scanf("%s", s);  //����ְԱ����

        for(i = 0; i < n; i ++)
        {
            if(strcmp(s, EMPLOYEE[i].id) == 0)  //�жϹ����Ƿ��Ѵ���
            {
                printf("\n\t��ְԱ�����Ѵ��ڣ�\n");
                printf("\n\t�Ƿ��������룿�ǣ�y���������ַ�\n\t");
                scanf("%s", s);  //����ָ��

                if(strcmp(s, "y") == 0)
                {
                    flag = 1;  //ͬ�����������¹��������ְԱ������Ϣ
                }
                else
                {
                    flag = 0;  //��ͬ���������룬�˻����˵�
                }
                break;  //�˳�ѭ��
            }
        }
        if(i == n)  //ְԱ�������ظ�
        {
            flag = 0;  //�˳�whileѭ��
            flag_1 = 1;  //ȷ�����ְԱ��Ϣ
        }
    }
    if(flag_1) //��flag_1����1ʱִ��
    {
        strcpy(EMPLOYEE[n].id, s);  //����ְԱ���Ÿ�ֵ

        printf("\n\tְԱ������");
        scanf("%s", EMPLOYEE[n].name);  //����ְԱ����

        Input_Data(n);  //����ְԱ������Ϣ

        printf("\n\t");
        printf("--------------------------����ְ����Ϣ--------------------------");

        Show_Data(n);  //���ְԱ������Ϣ

        n += 1;  //�ܹ�����������+1
    }
    printf("\n\t");
    printf("--------------------------���ִ�н���--------------------------");
	getchar();
}

void Input_Data(int i)  //��������ְԱ������Ϣ
{
	printf("\n\t��λ��");
	scanf("%s", EMPLOYEE[i].Employee_Post);

	printf("\n\t��λ�ȼ���");
	scanf("%d", &EMPLOYEE[i].Employee_Post_Rank);

	printf("\n\t���䣺");
	scanf("%d", &EMPLOYEE[i].Working_Years);
	
	printf("\n\t����������");
	scanf("%d", &EMPLOYEE[i].Attendance_Days);

	printf("\n\t�Ӱ�������");
	scanf("%d", &EMPLOYEE[i].Overtime_Days);
	/*
	printf("\n\t�������ʣ�");
	scanf("%f", &EMPLOYEE[i].Base_Salary);

	printf("\n\t��λ���ʣ�");
	scanf("%f", &EMPLOYEE[i].Post_Salary);

	printf("\n\t��Ч���ʣ�");
	scanf("%f", &EMPLOYEE[i].Ach_Salary);
	*/
	printf("\n\t��Ч������");
	scanf("%d", &EMPLOYEE[i].Ach_Score);
	/*
	if(EMPLOYEE[i].Ach_Score<90)
	{
		EMPLOYEE[i].Ach_Salary *= EMPLOYEE[i].Ach_Score/100.0;
	}
	*/
	/*
	printf("\n\t���ܹ��ʣ�");
	scanf("%f", &EMPLOYEE[i].Skill_Wage);

	printf("\n\t���乤�ʣ�");
	scanf("%f", &EMPLOYEE[i].Seniority_Wage);

	printf("\n\t���������");
	scanf("%f", &EMPLOYEE[i].Subsistence_Allowance);

	printf("\n\t�Ӱ๤�ʣ�");
	scanf("%f", &EMPLOYEE[i].Overtime_Pay);

	printf("\n\t����");
	scanf("%f", &EMPLOYEE[i].Bonus);
	*/
	Get_Salary(i);
}

void Show_Data(int i)  //��ʾĳְԱ������Ϣ�ĺ���
{
    printf("\n\t���ţ�%s", EMPLOYEE[i].id);

	printf("\n\t������%s", EMPLOYEE[i].name);
    
	printf("\n\t��λ��%s", EMPLOYEE[i].Employee_Post);

	printf("\n\t��λ�ȼ���%d", EMPLOYEE[i].Employee_Post_Rank);

	printf("\n\t���䣺%d", EMPLOYEE[i].Working_Years);
	
	printf("\n\t����������%d", EMPLOYEE[i].Attendance_Days);

	printf("\n\t�Ӱ�������%d", EMPLOYEE[i].Overtime_Days);

	printf("\n\t�������ʣ�%.2f", EMPLOYEE[i].Base_Salary);

	printf("\n\t��λ���ʣ�%.2f", EMPLOYEE[i].Post_Salary);

	printf("\n\t��Ч���ʣ�%.2f", EMPLOYEE[i].Ach_Salary);

	printf("\n\t��Ч������%d", EMPLOYEE[i].Ach_Score);

	printf("\n\t���ܹ��ʣ�%.2f", EMPLOYEE[i].Skill_Wage);

	printf("\n\t���乤�ʣ�%.2f", EMPLOYEE[i].Seniority_Wage);

	printf("\n\t���������%.2f", EMPLOYEE[i].Subsistence_Allowance);

	printf("\n\t�Ӱ๤�ʣ�%.2f", EMPLOYEE[i].Overtime_Pay);

	printf("\n\t����%.2f", EMPLOYEE[i].Bonus);

	printf("\n\tӦ������:%.2f", EMPLOYEE[i].All_Salary);
	printf("\n");
}
void Get_Salary(int i)
{
	int choose,password;
	EMPLOYEE[i].Base_Salary=3000 / 26.0 * EMPLOYEE[i].Attendance_Days;
	
	if(strcmp(EMPLOYEE[i].Employee_Post , "����" )|| strcmp(EMPLOYEE[i].Employee_Post , "���ܾ���"))
	{
		EMPLOYEE[i].Post_Salary = 10000+500 * EMPLOYEE[i].Ach_Score / 26.0 * EMPLOYEE[i].Attendance_Days;
	}
	else if(strcmp(EMPLOYEE[i].Employee_Post , "��������"))	
	{
		EMPLOYEE[i].Post_Salary = 8000 + 300 * EMPLOYEE[i].Ach_Score / 26.0 * EMPLOYEE[i].Attendance_Days;
	}
	else if(strcmp(EMPLOYEE[i].Employee_Post , "��������") || strcmp(EMPLOYEE[i].Employee_Post , "���γ�") || strcmp(EMPLOYEE[i].Employee_Post , "���鳤"))	
	{
		EMPLOYEE[i].Post_Salary = 5000 + 150 * EMPLOYEE[i].Ach_Score / 26.0 * EMPLOYEE[i].Attendance_Days;
	}
	else if(strcmp(EMPLOYEE[i].Employee_Post , "��ͨԱ��"))	
	{
		EMPLOYEE[i].Post_Salary = 3000 + 100 * EMPLOYEE[i].Ach_Score / 26.0 * EMPLOYEE[i].Attendance_Days;
	}

	EMPLOYEE[i].Ach_Salary = 300;    //���輨Ч��������90

	if(EMPLOYEE[i].Ach_Score<90)
	{
		EMPLOYEE[i].Ach_Salary *= EMPLOYEE[i].Ach_Score * 0.01;
	}

	EMPLOYEE[i].Subsistence_Allowance = 100 / 26.0 * EMPLOYEE[i].Attendance_Days;

	EMPLOYEE[i].Skill_Wage = 300 / 26.0 * EMPLOYEE[i].Attendance_Days;

	EMPLOYEE[i].Seniority_Wage = EMPLOYEE[i].Working_Years * 100/26.0 * EMPLOYEE[i].Attendance_Days;

	EMPLOYEE[i].Overtime_Pay = 800 / 26.0 * EMPLOYEE[i].Overtime_Days;

	printf("\n\t�Ƿ��Ա��%s��������", EMPLOYEE[i].id);
	printf("\n\t1���� �� 2����\n");

	while(1)
	{
		scanf("%d",&choose);
		if(choose == 1||choose == 2)
		{
			EMPLOYEE[i].Bonus = 0;
			break;
		} 

		else printf("\n\t������1 �� 2\n");
	
	}

	if(choose == 1)
	{
	    while(1)
	    {
			printf("\n\t�����뽱������");
			scanf("%d",&password);
			if(password != 123456) 
			{
				printf("\n\t�������");
			    printf("\n\t�Ƿ�������룿 1���� �� 2����");
				scanf("%d",&choose);
				if(choose != 1 || choose != 2) printf("\n\t������1 �� 2");
				if(choose == 1) continue;
				else break;
			}
			else
			{
	    		EMPLOYEE[i].Bonus = 5000;
				break;
    	    }
	    }
	}
	EMPLOYEE[i].All_Salary = EMPLOYEE[i].Base_Salary + EMPLOYEE[i].Post_Salary
		+ EMPLOYEE[i].Ach_Salary + EMPLOYEE[i].Skill_Wage + EMPLOYEE[i].Seniority_Wage
		+ EMPLOYEE[i].Subsistence_Allowance + EMPLOYEE[i].Overtime_Pay + EMPLOYEE[i].Bonus;
}