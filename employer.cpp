//******************************************************************************************************
//工资管理系统v1.0.1

//author: 吴荣榜_222200314_MEWWW

/*

    特性1：采用文件读写保存现有数据，实现数据存储的效果

    特性2：实现显示实时时间

    特性3：采用按任意键回到主界面的方式，避免控制台过于冗杂

    功能1：导入员工信息，包括员工号，姓名，性别，出生日期，岗位工资，补贴总额，代扣总额

    功能2：输出所有员工信息表

    功能3：输出员工工资统计信息

    功能4：按要求排序员工信息(八种排序选项)

           ====================================

            =   1:按员工号从小到大排序         =

            =   2:按员工号从大到小排序         =

            =   3:按员工姓名排序               =

            =   4:按员工性别排序               =

            =   5:按员工年龄从小到大排序       =

            =   6:按员工年龄从大到小排序       =

            =   7:按员工应发工资从小到大排序   =

            =   8:按员工应发工资从大到小排序   =              =

            ====================================

    功能5：按员工号查找员工，并输出其信息

    功能6：按员工号查找员工，并删除其工资信息

*/
//******************************************************************************************************

#include <stdio.h>

#include <string.h>

#include <time.h>

#include <math.h>

#include <stdlib.h>

#include <ctype.h>

#include <Windows.h>

#include <conio.h>

#include <cmath>

#include <stdint.h>

#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define min(a, b) ((a) < (b) ? (a) : (b))

const int MAX_NUM_OF_EMPLOYEE = 1000001;//工资管理系统的最大人数

int num_of_the_employee;//工资管理系统中的员工的数量

//员工信息结构体
struct employee
{

public:

    char name[100];//姓名

    char id[100];//员工号

    char sex[10];//性别

    char birthday[101];//出生日期(年月日 用点隔开)

    double salary;//岗位工资

    double subsidy;//补贴总额

    double paid;//代扣总额

    double the_final_salary;//应发工资
    
    /*功能：设置员工信息
      原理：类似于构造函数的写法，更新employees的信息
      返回值：无*/
    void set_the_information(char Id[], char Name[], char Sex[], char Birthday[], double Salary, double Subsidy, double Paid)
    
    {

        strcpy(name, Name);

        strcpy(id, Id);

        strcpy(sex, Sex);

        strcpy(birthday, Birthday);

        salary = Salary;

        subsidy = Subsidy;

        paid = Paid;

        the_final_salary = salary + Subsidy - paid;

    }

    /*功能：输出单个员工信息
    原理：将对应的员工的员工号，姓名，性别，出生日期，岗位工资，补贴总额，代扣总额，应付工资输出
    返回值：无*/
    void output_the_information()

    {

        printf("%-8s%-10s%-7s%-15s%-12.2f%-12.2f%-12.2f%-12.2f\n", id, name, sex, birthday, salary, subsidy, paid, the_final_salary);

    }

} employees[MAX_NUM_OF_EMPLOYEE];

FILE *fp;//文件指针

/*功能：读取文件中的原有员工信息，导入本程序，
如果找不到该文件就新建一个information.bat文件
返回值：无*/
void fileread();

/*功能：将更新后的数据写入information.bat文件
返回值：无*/
void filewrite();

/*功能：打印时间，此时间为计算机本地时间
返回值：无*/
void print_time();

/*功能：从控制台导入员工信息
返回值：无*/
void input();

/*功能：输出所有员工信息
返回值：无*/
void output();

/*功能：计算分析现有员工所有数据，统计出男性女性的应发工资(最高最低)，以及平均值
返回值：无*/
void analysis();

/*功能：将员工号从小到大排序
返回值：无*/
bool cmp_id_greater(employee s, employee t);

/*功能：将员工号从大到小排序
返回值：无*/
bool cmp_id_less(employee s, employee t);

/*功能：将员工名字姓氏排序
返回值：无*/
bool cmp_name(employee s, employee t);

/*功能：将员工号性别排序(男生在前女生在后)
返回值：无*/
bool cmp_sex(employee s, employee t);

/*功能：将年龄从小到大排序
返回值：无*/
bool cmp_age_greater(employee s, employee t);

/*功能：将年龄从大到小排序
返回值：无*/
bool cmp_age_less(employee s, employee t);

/*功能：将应发工资从小到大排序
返回值：无*/
bool cmp_salary_greater(employee s, employee t);

/*功能：将应发工资从大到小排序
返回值：无*/
bool cmp_salary_less(employee s, employee t);

/*功能：排序菜单，一共有八种
返回值：无*/
void sort_menu();

/*功能：按员工号查找员工，并输出其信息
返回值：无*/
void find_employee();

/*功能：按员工号查找员工，并删除该员工
返回值：无*/
void delete_employee();

int main()

{

    char input_char = ' ';//记录主页菜单的输入选项

    fileread();

    while (1)

    {

        print_time();

        printf("\nMEWWWWWW!!!!!欢迎来到MEWWW的工资管理系统ヾ(≧▽≦*)o\n\n");

        printf("****************************************\n");

        printf("*   I:输入员工工资信息                 *\n");

        printf("*   O:输出员工工资信息                 *\n");

        printf("*   T:输出员工工资统计信息             *\n");

        printf("*   S:按要求排序后输出员工工资信息     *\n");

        printf("*   F:按员工号查找并输出其工资信息     *\n");

        printf("*   D:按员工号查找并删除其工资信息     *\n");

        printf("*   Q:退出系统                         *\n");

        printf("****************************************\n");

        printf("\n请选择(I,O,T,S,F,D,Q):\n");

        input_char = getch();

        if (!isalpha(input_char))

        {

            putchar(input_char);

            putchar('\n');

            printf("输入错误，请重新输入....\n\n");

        }

        else

        {

            printf("%c\n", input_char = toupper(input_char));
            
            switch (input_char)

            {

                case 'I':

                {

                    input();

                    break;

                }

                case 'O':

                {

                    output();

                    break;

                }

                case 'T':

                {

                    analysis();

                    break;

                }

                case 'S':

                {

                    sort_menu();

                    break;

                }

                case 'F':

                {

                    find_employee();

                    break;

                }

                case 'D':

                {

                    delete_employee();

                    break;

                }

                case 'Q':

                {

                    printf("\nMEWWWWW!!!!再见！！q(≧▽≦q)\n");

                    fclose(fp);

                    exit(0);

                }

                default:

                {

                    printf("输入错误，请重新输入....\n\n");

                    break;

                }

            }

        }

        printf("按任意键回到主菜单:)\n");

        getch();

        system("cls");

    }

    return 0;

}

void fileread()

{

    char id[1001], name[1001], sex[10], birthday[100];

    double subsidy, salary, paid;

    fp = fopen(".\\information.bat", "a+");

    while (~fscanf(fp, "%s %s %s %s %lf %lf %lf ", id, name, sex, birthday, &salary, &subsidy, &paid))

    {

        for (auto &i : birthday)

        {

            if (i == '-')

                i = '.';

        }

        // printf("%s\n",birthday);

        employees[++num_of_the_employee].set_the_information(id, name, sex, birthday, salary, subsidy, paid);

    }

    fclose(fp);

    return;
    
}

void filewrite()

{



    fp = fopen(".\\information.bat", "w");

    for (int i = 1; i <= num_of_the_employee; i++)

    {
        fprintf(fp, "%s %s %s %s %lf %lf %lf ",

                employees[i].id, employees[i].name, employees[i].sex, 

                employees[i].birthday, employees[i].salary, employees[i].subsidy, 

                employees[i].paid);

    }

    return;

}

void print_time()

{

    time_t timep;

    struct tm *p;

    char time1[100];

    char whichday[20];

    time(&timep);

    p = localtime(&timep);

    switch (p->tm_wday)

    {

    case 0:

        strcpy(whichday, "日");

        break;

    case 1:

        strcpy(whichday, "一");

        break;

    case 2:

        strcpy(whichday, "二");

        break;

    case 3:

        strcpy(whichday, "三");

        break;

    case 4:

        strcpy(whichday, "四");

        break;

    case 5:

        strcpy(whichday, "五");

        break;

    case 6:

        strcpy(whichday, "六");

        break;

    }

    sprintf(time1, "%d年%02d月%02d日 %02d:%02d:%02d 星期%s",

            1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour,

            p->tm_min, p->tm_sec, whichday);

    printf("当前时间为：%s\n", time1);

    return;

}

void input()

{

    char id[1001], name[1001], sex[10], birthday[100];

    double subsidy, salary, paid;

    printf("\n请输入不超过%d名员工的\n\n", MAX_NUM_OF_EMPLOYEE - num_of_the_employee);

    printf("员工号、姓名、性别、出生日期、岗位工资、补贴总额、代扣总额。\n\n");

    printf("输入项目之间必须用<空格>分开！\n\n");

    printf("例如：1006 林指愤 女 1991.01.02 3009.00 1500.00 300.00<回车>\n\n");

    printf("如果不想继续输入数据，请在行首按<Ctrl>+Z、<回车>\n\n");

    while (~scanf("%s %s %s %s %lf %lf %lf", id, name, sex, birthday, &salary, &subsidy, &paid))

    {

        for (auto &i : birthday)

        {

            if (i == '-')

                i = '.';

        }

        // printf("%s\n",birthday);

         if (strlen(sex) == 1)

        {

            if (sex[0] == 'm' || sex[0] == 'M')

                strcpy(sex, "男");

            else if (sex[0] == 'W' || sex[0] == 'w')

                strcpy(sex, "女");

        } 

        for(int i=1;i<=num_of_the_employee;i++)

        {

            if(!strcmp(employees[i].id,id))

            {

                printf("\n已经有这个员工了！！！o((>ω< ))o\n\n");

                getchar();

                return;

            }

        }

        employees[++num_of_the_employee].set_the_information(id, name, sex, birthday, salary, subsidy, paid);

        // printf("%s %s %s %lf %lf %lf\n",id,name,sex,salary,subsidy,paid);

        getchar();

    }

    filewrite();

    return;

}

void output()

{

    if (num_of_the_employee == 0)

    {

        printf("一个员工都没有的捏qwq！！！！\n");

        return;

    }

    printf("\n现有员工总数为：%d\n\n", num_of_the_employee);

    printf("员工号   姓名    性别    出生日期      岗位工资    补贴总额    代扣总额     应发工资\n");

    printf("=====================================================================================\n");

    for (int i = 1; i <= num_of_the_employee; i++)

    {

        employees[i].output_the_information();

    }

    printf("=====================================================================================\n\n");

    return;

}

void analysis()

{

    int num_man = 0;

    int num_woman = 0;

    double max_salary = INT_MIN;

    double min_salary = INT_MAX;

    double sum_salary = 0;

    double salary_man = 0;

    double salary_woman = 0;

    double average_all = 0;

    double average_man = 0;

    double average_woman = 0;

    for (int i = 1; i <= num_of_the_employee; i++)

    {

        sum_salary += employees[i].the_final_salary;

        max_salary = max(max_salary, employees[i].the_final_salary);

        min_salary = min(min_salary, employees[i].the_final_salary);

        if (strcmp(employees[i].sex, "男") == 0)

        {

            num_man++;

            salary_man += employees[i].the_final_salary;

        }

        if (strcmp(employees[i].sex, "女") == 0)

        {

            num_woman++;

            salary_woman += employees[i].the_final_salary;

        }

    }

    average_all = sum_salary / num_of_the_employee;

    average_man = salary_man / num_man;

    average_woman = salary_woman / num_woman;

    printf("\n应发工资最高为：%.2f，最低为：%.2f，所有员工应发工资总额为：%.2f\n\n", max_salary, min_salary, sum_salary);

    printf("男性员工人数为：%d，女性员工人数为：%d\n\n", num_man, num_woman);

    printf("应发工资平均值为：%.2f(其中，男性平均值为：%.2f，女性平均值为：%.2f)\n\n", average_all, average_man, average_woman);

    return;

}

bool cmp_id_greater(employee s, employee t)

{

    if (strcmp(s.id, t.id) != 0)

    return strcmp(s.id, t.id) < 0;

}

bool cmp_id_less(employee s, employee t)

{

    if (strcmp(s.id, t.id) != 0)

        return strcmp(s.id, t.id) > 0;

}

bool cmp_name(employee s, employee t)

{

    if (strcmp(s.name, t.name) != 0)

        return strcmp(s.name, t.name) < 0;

}

bool cmp_sex(employee s, employee t)

{

    if (strcmp(s.sex, t.sex) != 0)

        return strcmp(s.sex, t.sex) < 0;

}

bool cmp_age_greater(employee s, employee t)

{

    if (strcmp(s.birthday, t.birthday) != 0)

        return strcmp(s.birthday, t.birthday) > 0;

}

bool cmp_age_less(employee s, employee t)

{

    if (strcmp(s.birthday, t.birthday) != 0)

        return strcmp(s.birthday, t.birthday) < 0;

}

bool cmp_salary_greater(employee s, employee t)

{

    if (s.the_final_salary != t.the_final_salary)

        return s.the_final_salary < t.the_final_salary;

}

bool cmp_salary_less(employee s, employee t)

{

    if (s.the_final_salary != t.the_final_salary)

        return s.the_final_salary > t.the_final_salary;

}

void sort_menu()

{

    char option = 0;

AGAIN:

{

    printf("\n       排序方式选择菜单         \n");

    printf("====================================\n");

    printf("=   1:按员工号从小到大排序         =\n");

    printf("=   2:按员工号从大到小排序         =\n");

    printf("=   3:按员工姓名排序               =\n");

    printf("=   4:按员工性别排序               =\n");

    printf("=   5:按员工年龄从小到大排序       =\n");

    printf("=   6:按员工年龄从大到小排序       =\n");

    printf("=   7:按员工应发工资从小到大排序   =\n");

    printf("=   8:按员工应发工资从大到小排序   =\n");

    printf("=   q:不排序退出                   =\n");

    printf("====================================\n");

    printf("请选择(1--8和q):\n");

    option = getche();

    putchar('\n');

    switch (option)

    {

        case '1':

        {

            std::sort(employees + 1, employees + num_of_the_employee + 1, cmp_id_greater);

            output();

            break;

        }

        case '2':

        {

            std::sort(employees + 1, employees + num_of_the_employee + 1, cmp_id_less);

            output();

            break;

        }

        case '3':

        {

            std::sort(employees + 1, employees + num_of_the_employee + 1, cmp_name);

            output();

            break;

        }

        case '4':

        {

            std::sort(employees + 1, employees + num_of_the_employee + 1, cmp_sex);

            output();

            break;

        }

        case '5':

        {

            std::sort(employees + 1, employees + num_of_the_employee + 1, cmp_age_greater);

            output();

            break;

        }

        case '6':

        {

            std::sort(employees + 1, employees + num_of_the_employee + 1, cmp_age_less);

            output();

            break;

        }

        case '7':

        {

            std::sort(employees + 1, employees + num_of_the_employee + 1, cmp_salary_greater);

            output();

            break;

        }

        case '8':

        {

            std::sort(employees + 1, employees + num_of_the_employee + 1, cmp_salary_less);

            output();

            break;

        }

        case 'q':

        {

            printf("\n");

            break;

        }

        default:

        {

            printf("\n选择错误，请重新选择.....\n\n");

            goto AGAIN;

        }

    }

}

    return;

}

void find_employee()

{

    char find_id[1001];

    bool flag = 0;

    printf("\n请输入待查询的员工号：\n");

    scanf("%s", find_id);

    printf("\n");

    for (auto i : employees)

    {

        if (strcmp(i.id, find_id) == 0)

        {

            flag = 1;

            printf("员工号   姓名    性别    出生日期      岗位工资    补贴总额    代扣总额     应发工资\n");

            i.output_the_information();

            printf("\n");

            break;

        }

    }

    if (!flag)

    {

        printf("员工[%s]不存在！\n\n", find_id);

    }

    return;

}

void delete_employee()

{

    char delete_id[1001];

    bool flag = 0;

    printf("请输入要删除的员工号：");

    scanf("%s", delete_id);

    printf("\n");

    for (int i = 1; i <= num_of_the_employee; i++)

    {

        if (strcmp(employees[i].id, delete_id) == 0)

        {

            flag = 1;

            printf("员工[%s]已删除！\n\n", delete_id);

            for (int j = i; j <= num_of_the_employee - 1; j++)

            {

                employees[j] = employees[j + 1];

            }

            num_of_the_employee--;

            break;

        }

    }

    if (!flag)

    {

        printf("员工[%s]不存在！\n\n", delete_id);

    }

    filewrite();

    return;

}