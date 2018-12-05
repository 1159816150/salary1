#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct EMPLOYEE
{
	char id[10];    //员工ID
	char name[20];       //员工姓名
	char Employee_Post[20];       //员工岗位
	int Employee_Post_Rank;    //岗位等级
	int Working_Years;     //工龄*
	int Attendance_Days;    //出勤天数*
	int Overtime_Days;    //加班天数*
	float Base_Salary;    //基本工资
	float Post_Salary;    //岗位工资
	float Ach_Salary;    //绩效工资
	int Ach_Score;       //绩效分数
	float Skill_Wage;    //技能工资
	float Seniority_Wage;      //工龄工资
	float Subsistence_Allowance;  //生活津贴
	float Overtime_Pay;   //加班工资
	float Bonus;          //奖金
	float All_Salary;    //应发工资
}EMPLOYEE[100];

int n = 0;  //记录职工数量的全局变量

void Menu();    //系统界面菜单
int Read_Record();        //读取记录函数
int Save_Record();       //保存记录函数
void List();        //遍历函数
void Insert();         //添加函数
void Get_Salary(int i);
void Input_Data();    //输入员工基本信息
void Show_Data();    //打印员工工资信息

int main()
{
    char s[5], ch[5];
    int flag = 1;    //用于控制循环体
    Read_Record();

    while(flag)
    {
		Menu();
        printf("\n\n\t");
        printf("你的选择是：");
        scanf("%s",  s);
        printf("\n\t");
		if(strcmp(s ,"1") == 0)
        {
			printf("\n\n\n\t");
            printf("此功能未开放");
			getchar();
        }
        else if(strcmp(s ,"2") == 0)
        {
			printf("\n\n\n\t");
            printf("此功能未开放");
			getchar();
        }
        else if(strcmp(s ,"3") == 0)
        {
            if(n < 100)
            {
                Insert();  //小于100条数据，调用添加函数
            }
            else
            {
                printf("\n\t人数超出限制！\n\n");
				getchar();
            }
        }
        else if(strcmp(s ,"4") == 0)
        {
			printf("\n\n\n\t");
            printf("此功能未开放");
			getchar();
        }
        else if(strcmp(s ,"5") == 0)
        {
            Save_Record();  //调用保存函数
        }
        else if(strcmp(s ,"6") == 0)
        {
            List();  //调用浏览函数
			getchar();
        }
        else if(strcmp(s ,"7") == 0)
        {
            printf("\n\t是否需要帮您保存数据？是：y，否：任意字符\n\t");
            scanf("%s", ch);

            if(strcmp(ch, "y") == 0)
            {
                Save_Record();  //退出时可选择是否调用函数保存数据
				getchar();
            }

            printf("\n\t");
            printf("---------------------------程序已退出---------------------------");
            printf("\n\t");
            flag = 0;
        }
        else
        {
            printf("\n\t无该指令，请重新输入！\n\n");
			getchar();
        }
    }
    return 0;
}

void Menu()
{
	system("cls");
	printf("\n\n\n\t");
	printf("==========================工资管理系统==========================");
	printf("\n\n\n\t");
	printf("请选择（1 - 7）：\n\t");
	printf("================================================================");
	printf("\n\t");
	printf("|        1. 查询职工工资记录（unfinish）                       |");
	printf("\n\t");
	printf("|        2. 修改职工工资记录（unfinish）                       |");
	printf("\n\t");
	printf("|        3. 添加职工工资记录                                   |");
	printf("\n\t");
	printf("|        4. 删除职工工资记录(unfinish)                         |");
	printf("\n\t");
	printf("|        5. 保存记录到文件                                     |");
	printf("\n\t");
	printf("|        6. 遍历职工工资记录                                   |");
	printf("\n\t");
	printf("|        7. 退出系统                                           |");
	printf("\n\t");
	printf("================================================================");
}

int Read_Record()    //读取文件中员工工资数据
{
	FILE *fp = fopen("Salary.dat","rb");
	int i, nRes;  //i 用于控制循环体，nRes用于判断文件读取是否正确
    if(fp == NULL)    //打开当前目录下文件
    {
        printf("\n\t文件打开失败！\n\t");
        printf("\n\tPress any key");
		getchar();
        return 0;  //文件打开失败，直接回到主函数
    }
	while(1)
    {
        if(fread(&EMPLOYEE[i], sizeof(EMPLOYEE[i]), 1, fp)==0)//判读是否读到文件尾
        {
            break;
        }
		EMPLOYEE[i].All_Salary = EMPLOYEE[i].Base_Salary + EMPLOYEE[i].Post_Salary
			+ EMPLOYEE[i].Ach_Salary + EMPLOYEE[i].Skill_Wage + EMPLOYEE[i].Seniority_Wage
			+ EMPLOYEE[i].Subsistence_Allowance + EMPLOYEE[i].Overtime_Pay + EMPLOYEE[i].Bonus;
    }
	n = i;
	
    printf("\n\t共写入%d条数据\n", n);
    printf("\n\tPress any key...");
    getchar();
    system("cls");
	fclose(fp);
}

int Save_Record()  //保存职工工资数据函数
{  
    //只写打开或者建立一个二进制文件，只允许写数据
    FILE *fp = fopen("Salary.dat","wb");
    int i;

	if(n <= 0)
	{
		printf("\n\t职员数据为空\n\t");
        return 0;  //文件打开失败，直接回到主函数
	}
    else if(fp == NULL)  //打开当前目录下文件
    {
        printf("\n\t文件打开失败！\n\t");
        return 0;  //文件打开失败，直接回到主函数
    }
    for (i = 0; i < n; i ++)
    {
        fwrite(&(EMPLOYEE[i]), sizeof(EMPLOYEE[i]), 1, fp); //将数据写入二进制文件
    }

    fclose(fp);  //关闭文件

    printf("\n\t");
    printf("-------------------------文件保存完毕！-------------------------");
    printf("\n");
	getchar();
    return 0;
}

void List()
{
    int i;
    printf("\n\t");
    printf("------------------------浏览职工工资数据------------------------");
    
    for(i = 0; i < n; i ++)
    {
        Show_Data(i);  //通过循环显示所有职员工资信息
    }
    printf("\n\t");
    printf("----------------------------浏览结束----------------------------");
	getchar();
}

void Insert()
{
	char s[10];  //记录要添加职员的工号
    int i;
    int flag = 1;  //控制循环体
    int flag_1 = 0;  //控制是否输入数据

    printf("\n\t");
    printf("------------------------------添加------------------------------");
    printf("\n\t请输入职工基本信息：\n");

    while(flag)
    {
        printf("\n\t职员工号：");
        scanf("%s", s);  //输入职员工号

        for(i = 0; i < n; i ++)
        {
            if(strcmp(s, EMPLOYEE[i].id) == 0)  //判断工号是否已存在
            {
                printf("\n\t该职员工号已存在！\n");
                printf("\n\t是否重新输入？是：y，否：任意字符\n\t");
                scanf("%s", s);  //输入指令

                if(strcmp(s, "y") == 0)
                {
                    flag = 1;  //同意重新输入新工号来添加职员工资信息
                }
                else
                {
                    flag = 0;  //不同意重新输入，退回主菜单
                }
                break;  //退出循环
            }
        }
        if(i == n)  //职员工号无重复
        {
            flag = 0;  //退出while循环
            flag_1 = 1;  //确认添加职员信息
        }
    }
    if(flag_1) //当flag_1等于1时执行
    {
        strcpy(EMPLOYEE[n].id, s);  //进行职员工号赋值

        printf("\n\t职员姓名：");
        scanf("%s", EMPLOYEE[n].name);  //输入职员姓名

        Input_Data(n);  //输入职员工资信息

        printf("\n\t");
        printf("--------------------------所增职工信息--------------------------");

        Show_Data(n);  //输出职员工资信息

        n += 1;  //总工资数据数量+1
    }
    printf("\n\t");
    printf("--------------------------添加执行结束--------------------------");
	getchar();
}

void Input_Data(int i)  //用于输入职员工资信息
{
	printf("\n\t岗位：");
	scanf("%s", EMPLOYEE[i].Employee_Post);

	printf("\n\t岗位等级：");
	scanf("%d", &EMPLOYEE[i].Employee_Post_Rank);

	printf("\n\t工龄：");
	scanf("%d", &EMPLOYEE[i].Working_Years);
	
	printf("\n\t出勤天数：");
	scanf("%d", &EMPLOYEE[i].Attendance_Days);

	printf("\n\t加班天数：");
	scanf("%d", &EMPLOYEE[i].Overtime_Days);
	/*
	printf("\n\t基本工资：");
	scanf("%f", &EMPLOYEE[i].Base_Salary);

	printf("\n\t岗位工资：");
	scanf("%f", &EMPLOYEE[i].Post_Salary);

	printf("\n\t绩效工资：");
	scanf("%f", &EMPLOYEE[i].Ach_Salary);
	*/
	printf("\n\t绩效分数：");
	scanf("%d", &EMPLOYEE[i].Ach_Score);
	/*
	if(EMPLOYEE[i].Ach_Score<90)
	{
		EMPLOYEE[i].Ach_Salary *= EMPLOYEE[i].Ach_Score/100.0;
	}
	*/
	/*
	printf("\n\t技能工资：");
	scanf("%f", &EMPLOYEE[i].Skill_Wage);

	printf("\n\t工龄工资：");
	scanf("%f", &EMPLOYEE[i].Seniority_Wage);

	printf("\n\t生活津贴：");
	scanf("%f", &EMPLOYEE[i].Subsistence_Allowance);

	printf("\n\t加班工资：");
	scanf("%f", &EMPLOYEE[i].Overtime_Pay);

	printf("\n\t奖金：");
	scanf("%f", &EMPLOYEE[i].Bonus);
	*/
	Get_Salary(i);
}

void Show_Data(int i)  //显示某职员工资信息的函数
{
    printf("\n\t工号：%s", EMPLOYEE[i].id);

	printf("\n\t姓名：%s", EMPLOYEE[i].name);
    
	printf("\n\t岗位：%s", EMPLOYEE[i].Employee_Post);

	printf("\n\t岗位等级：%d", EMPLOYEE[i].Employee_Post_Rank);

	printf("\n\t工龄：%d", EMPLOYEE[i].Working_Years);
	
	printf("\n\t出勤天数：%d", EMPLOYEE[i].Attendance_Days);

	printf("\n\t加班天数：%d", EMPLOYEE[i].Overtime_Days);

	printf("\n\t基本工资：%.2f", EMPLOYEE[i].Base_Salary);

	printf("\n\t岗位工资：%.2f", EMPLOYEE[i].Post_Salary);

	printf("\n\t绩效工资：%.2f", EMPLOYEE[i].Ach_Salary);

	printf("\n\t绩效分数：%d", EMPLOYEE[i].Ach_Score);

	printf("\n\t技能工资：%.2f", EMPLOYEE[i].Skill_Wage);

	printf("\n\t工龄工资：%.2f", EMPLOYEE[i].Seniority_Wage);

	printf("\n\t生活津贴：%.2f", EMPLOYEE[i].Subsistence_Allowance);

	printf("\n\t加班工资：%.2f", EMPLOYEE[i].Overtime_Pay);

	printf("\n\t奖金：%.2f", EMPLOYEE[i].Bonus);

	printf("\n\t应发工资:%.2f", EMPLOYEE[i].All_Salary);
	printf("\n");
}
void Get_Salary(int i)
{
	int choose,password;
	EMPLOYEE[i].Base_Salary=3000 / 26.0 * EMPLOYEE[i].Attendance_Days;
	
	if(strcmp(EMPLOYEE[i].Employee_Post , "厂长" )|| strcmp(EMPLOYEE[i].Employee_Post , "主管经理"))
	{
		EMPLOYEE[i].Post_Salary = 10000+500 * EMPLOYEE[i].Ach_Score / 26.0 * EMPLOYEE[i].Attendance_Days;
	}
	else if(strcmp(EMPLOYEE[i].Employee_Post , "部门主管"))	
	{
		EMPLOYEE[i].Post_Salary = 8000 + 300 * EMPLOYEE[i].Ach_Score / 26.0 * EMPLOYEE[i].Attendance_Days;
	}
	else if(strcmp(EMPLOYEE[i].Employee_Post , "车间主任") || strcmp(EMPLOYEE[i].Employee_Post , "工段长") || strcmp(EMPLOYEE[i].Employee_Post , "班组长"))	
	{
		EMPLOYEE[i].Post_Salary = 5000 + 150 * EMPLOYEE[i].Ach_Score / 26.0 * EMPLOYEE[i].Attendance_Days;
	}
	else if(strcmp(EMPLOYEE[i].Employee_Post , "普通员工"))	
	{
		EMPLOYEE[i].Post_Salary = 3000 + 100 * EMPLOYEE[i].Ach_Score / 26.0 * EMPLOYEE[i].Attendance_Days;
	}

	EMPLOYEE[i].Ach_Salary = 300;    //假设绩效分数大于90

	if(EMPLOYEE[i].Ach_Score<90)
	{
		EMPLOYEE[i].Ach_Salary *= EMPLOYEE[i].Ach_Score * 0.01;
	}

	EMPLOYEE[i].Subsistence_Allowance = 100 / 26.0 * EMPLOYEE[i].Attendance_Days;

	EMPLOYEE[i].Skill_Wage = 300 / 26.0 * EMPLOYEE[i].Attendance_Days;

	EMPLOYEE[i].Seniority_Wage = EMPLOYEE[i].Working_Years * 100/26.0 * EMPLOYEE[i].Attendance_Days;

	EMPLOYEE[i].Overtime_Pay = 800 / 26.0 * EMPLOYEE[i].Overtime_Days;

	printf("\n\t是否给员工%s奖励工资", EMPLOYEE[i].id);
	printf("\n\t1、是 或 2、否\n");

	while(1)
	{
		scanf("%d",&choose);
		if(choose == 1||choose == 2)
		{
			EMPLOYEE[i].Bonus = 0;
			break;
		} 

		else printf("\n\t请输入1 或 2\n");
	
	}

	if(choose == 1)
	{
	    while(1)
	    {
			printf("\n\t请输入奖励密码");
			scanf("%d",&password);
			if(password != 123456) 
			{
				printf("\n\t密码错误");
			    printf("\n\t是否继续输入？ 1、是 或 2、否");
				scanf("%d",&choose);
				if(choose != 1 || choose != 2) printf("\n\t请输入1 或 2");
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