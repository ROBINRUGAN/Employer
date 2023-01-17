//******************************************************************************************************
//���ʹ���ϵͳv1.0.1

//author: ���ٰ�_222200314_MEWWW

/*

    ����1�������ļ���д�����������ݣ�ʵ�����ݴ洢��Ч��

    ����2��ʵ����ʾʵʱʱ��

    ����3�����ð�������ص�������ķ�ʽ���������̨��������

    ����1������Ա����Ϣ������Ա���ţ��������Ա𣬳������ڣ���λ���ʣ������ܶ�����ܶ�

    ����2���������Ա����Ϣ��

    ����3�����Ա������ͳ����Ϣ

    ����4����Ҫ������Ա����Ϣ(��������ѡ��)

           ====================================

            =   1:��Ա���Ŵ�С��������         =

            =   2:��Ա���ŴӴ�С����         =

            =   3:��Ա����������               =

            =   4:��Ա���Ա�����               =

            =   5:��Ա�������С��������       =

            =   6:��Ա������Ӵ�С����       =

            =   7:��Ա��Ӧ�����ʴ�С��������   =

            =   8:��Ա��Ӧ�����ʴӴ�С����   =              =

            ====================================

    ����5����Ա���Ų���Ա�������������Ϣ

    ����6����Ա���Ų���Ա������ɾ���乤����Ϣ

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

const int MAX_NUM_OF_EMPLOYEE = 1000001;//���ʹ���ϵͳ���������

int num_of_the_employee;//���ʹ���ϵͳ�е�Ա��������

//Ա����Ϣ�ṹ��
struct employee
{

public:

    char name[100];//����

    char id[100];//Ա����

    char sex[10];//�Ա�

    char birthday[101];//��������(������ �õ����)

    double salary;//��λ����

    double subsidy;//�����ܶ�

    double paid;//�����ܶ�

    double the_final_salary;//Ӧ������
    
    /*���ܣ�����Ա����Ϣ
      ԭ�������ڹ��캯����д��������employees����Ϣ
      ����ֵ����*/
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

    /*���ܣ��������Ա����Ϣ
    ԭ������Ӧ��Ա����Ա���ţ��������Ա𣬳������ڣ���λ���ʣ������ܶ�����ܶӦ���������
    ����ֵ����*/
    void output_the_information()

    {

        printf("%-8s%-10s%-7s%-15s%-12.2f%-12.2f%-12.2f%-12.2f\n", id, name, sex, birthday, salary, subsidy, paid, the_final_salary);

    }

} employees[MAX_NUM_OF_EMPLOYEE];

FILE *fp;//�ļ�ָ��

/*���ܣ���ȡ�ļ��е�ԭ��Ա����Ϣ�����뱾����
����Ҳ������ļ����½�һ��information.bat�ļ�
����ֵ����*/
void fileread();

/*���ܣ������º������д��information.bat�ļ�
����ֵ����*/
void filewrite();

/*���ܣ���ӡʱ�䣬��ʱ��Ϊ���������ʱ��
����ֵ����*/
void print_time();

/*���ܣ��ӿ���̨����Ա����Ϣ
����ֵ����*/
void input();

/*���ܣ��������Ա����Ϣ
����ֵ����*/
void output();

/*���ܣ������������Ա���������ݣ�ͳ�Ƴ�����Ů�Ե�Ӧ������(������)���Լ�ƽ��ֵ
����ֵ����*/
void analysis();

/*���ܣ���Ա���Ŵ�С��������
����ֵ����*/
bool cmp_id_greater(employee s, employee t);

/*���ܣ���Ա���ŴӴ�С����
����ֵ����*/
bool cmp_id_less(employee s, employee t);

/*���ܣ���Ա��������������
����ֵ����*/
bool cmp_name(employee s, employee t);

/*���ܣ���Ա�����Ա�����(������ǰŮ���ں�)
����ֵ����*/
bool cmp_sex(employee s, employee t);

/*���ܣ��������С��������
����ֵ����*/
bool cmp_age_greater(employee s, employee t);

/*���ܣ�������Ӵ�С����
����ֵ����*/
bool cmp_age_less(employee s, employee t);

/*���ܣ���Ӧ�����ʴ�С��������
����ֵ����*/
bool cmp_salary_greater(employee s, employee t);

/*���ܣ���Ӧ�����ʴӴ�С����
����ֵ����*/
bool cmp_salary_less(employee s, employee t);

/*���ܣ�����˵���һ���а���
����ֵ����*/
void sort_menu();

/*���ܣ���Ա���Ų���Ա�������������Ϣ
����ֵ����*/
void find_employee();

/*���ܣ���Ա���Ų���Ա������ɾ����Ա��
����ֵ����*/
void delete_employee();

int main()

{

    char input_char = ' ';//��¼��ҳ�˵�������ѡ��

    fileread();

    while (1)

    {

        print_time();

        printf("\nMEWWWWWW!!!!!��ӭ����MEWWW�Ĺ��ʹ���ϵͳ�d(�R���Q*)o\n\n");

        printf("****************************************\n");

        printf("*   I:����Ա��������Ϣ                 *\n");

        printf("*   O:���Ա��������Ϣ                 *\n");

        printf("*   T:���Ա������ͳ����Ϣ             *\n");

        printf("*   S:��Ҫ����������Ա��������Ϣ     *\n");

        printf("*   F:��Ա���Ų��Ҳ�����乤����Ϣ     *\n");

        printf("*   D:��Ա���Ų��Ҳ�ɾ���乤����Ϣ     *\n");

        printf("*   Q:�˳�ϵͳ                         *\n");

        printf("****************************************\n");

        printf("\n��ѡ��(I,O,T,S,F,D,Q):\n");

        input_char = getch();

        if (!isalpha(input_char))

        {

            putchar(input_char);

            putchar('\n');

            printf("�����������������....\n\n");

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

                    printf("\nMEWWWWW!!!!�ټ�����q(�R���Qq)\n");

                    fclose(fp);

                    exit(0);

                }

                default:

                {

                    printf("�����������������....\n\n");

                    break;

                }

            }

        }

        printf("��������ص����˵�:)\n");

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

        strcpy(whichday, "��");

        break;

    case 1:

        strcpy(whichday, "һ");

        break;

    case 2:

        strcpy(whichday, "��");

        break;

    case 3:

        strcpy(whichday, "��");

        break;

    case 4:

        strcpy(whichday, "��");

        break;

    case 5:

        strcpy(whichday, "��");

        break;

    case 6:

        strcpy(whichday, "��");

        break;

    }

    sprintf(time1, "%d��%02d��%02d�� %02d:%02d:%02d ����%s",

            1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour,

            p->tm_min, p->tm_sec, whichday);

    printf("��ǰʱ��Ϊ��%s\n", time1);

    return;

}

void input()

{

    char id[1001], name[1001], sex[10], birthday[100];

    double subsidy, salary, paid;

    printf("\n�����벻����%d��Ա����\n\n", MAX_NUM_OF_EMPLOYEE - num_of_the_employee);

    printf("Ա���š��������Ա𡢳������ڡ���λ���ʡ������ܶ�����ܶ\n\n");

    printf("������Ŀ֮�������<�ո�>�ֿ���\n\n");

    printf("���磺1006 ��ָ�� Ů 1991.01.02 3009.00 1500.00 300.00<�س�>\n\n");

    printf("�����������������ݣ��������װ�<Ctrl>+Z��<�س�>\n\n");

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

                strcpy(sex, "��");

            else if (sex[0] == 'W' || sex[0] == 'w')

                strcpy(sex, "Ů");

        } 

        for(int i=1;i<=num_of_the_employee;i++)

        {

            if(!strcmp(employees[i].id,id))

            {

                printf("\n�Ѿ������Ա���ˣ�����o((>��< ))o\n\n");

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

        printf("һ��Ա����û�е���qwq��������\n");

        return;

    }

    printf("\n����Ա������Ϊ��%d\n\n", num_of_the_employee);

    printf("Ա����   ����    �Ա�    ��������      ��λ����    �����ܶ�    �����ܶ�     Ӧ������\n");

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

        if (strcmp(employees[i].sex, "��") == 0)

        {

            num_man++;

            salary_man += employees[i].the_final_salary;

        }

        if (strcmp(employees[i].sex, "Ů") == 0)

        {

            num_woman++;

            salary_woman += employees[i].the_final_salary;

        }

    }

    average_all = sum_salary / num_of_the_employee;

    average_man = salary_man / num_man;

    average_woman = salary_woman / num_woman;

    printf("\nӦ���������Ϊ��%.2f�����Ϊ��%.2f������Ա��Ӧ�������ܶ�Ϊ��%.2f\n\n", max_salary, min_salary, sum_salary);

    printf("����Ա������Ϊ��%d��Ů��Ա������Ϊ��%d\n\n", num_man, num_woman);

    printf("Ӧ������ƽ��ֵΪ��%.2f(���У�����ƽ��ֵΪ��%.2f��Ů��ƽ��ֵΪ��%.2f)\n\n", average_all, average_man, average_woman);

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

    printf("\n       ����ʽѡ��˵�         \n");

    printf("====================================\n");

    printf("=   1:��Ա���Ŵ�С��������         =\n");

    printf("=   2:��Ա���ŴӴ�С����         =\n");

    printf("=   3:��Ա����������               =\n");

    printf("=   4:��Ա���Ա�����               =\n");

    printf("=   5:��Ա�������С��������       =\n");

    printf("=   6:��Ա������Ӵ�С����       =\n");

    printf("=   7:��Ա��Ӧ�����ʴ�С��������   =\n");

    printf("=   8:��Ա��Ӧ�����ʴӴ�С����   =\n");

    printf("=   q:�������˳�                   =\n");

    printf("====================================\n");

    printf("��ѡ��(1--8��q):\n");

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

            printf("\nѡ�����������ѡ��.....\n\n");

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

    printf("\n���������ѯ��Ա���ţ�\n");

    scanf("%s", find_id);

    printf("\n");

    for (auto i : employees)

    {

        if (strcmp(i.id, find_id) == 0)

        {

            flag = 1;

            printf("Ա����   ����    �Ա�    ��������      ��λ����    �����ܶ�    �����ܶ�     Ӧ������\n");

            i.output_the_information();

            printf("\n");

            break;

        }

    }

    if (!flag)

    {

        printf("Ա��[%s]�����ڣ�\n\n", find_id);

    }

    return;

}

void delete_employee()

{

    char delete_id[1001];

    bool flag = 0;

    printf("������Ҫɾ����Ա���ţ�");

    scanf("%s", delete_id);

    printf("\n");

    for (int i = 1; i <= num_of_the_employee; i++)

    {

        if (strcmp(employees[i].id, delete_id) == 0)

        {

            flag = 1;

            printf("Ա��[%s]��ɾ����\n\n", delete_id);

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

        printf("Ա��[%s]�����ڣ�\n\n", delete_id);

    }

    filewrite();

    return;

}