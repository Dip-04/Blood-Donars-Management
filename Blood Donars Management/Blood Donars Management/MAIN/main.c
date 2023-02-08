#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 50
#define SZ 5
#define tab printf("\t\t\t")

struct donor
{

    char fname[SIZE], mname[SIZE], lname[SIZE], add[SIZE], sex[SIZE], grp[SZ], no[SIZE];
    char id[SIZE], t[SIZE];
    int age;
} d, d1;
void login()
{
    system("pause");
    system("COLOR 4F");
    char user[20], pass[13], q[10] = "2213535", p[20] = "Diptish", ch, c;
    int i;

q:
    system("cls");
    printf("\n\t\t__________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("\n\n\t\t\t                                                                       WELCOME TO BLOOD BANK                                                                                                                                                \n");
    printf("\n\t\t_________________________________________________________________________________________________________________________________________________________________________________________\n");

    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tUSERNAME : ");
    scanf("%s", user);
    printf("\n\t\t\t\t\t\t\t\t\t\t\tPASSWORD : ");

    i = 0;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        pass[i++] = ch;
        printf("*");
    }
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t");
    printf("Loading");
    printf(".");
    Sleep(600);
    printf(".");
    Sleep(600);
    printf(".");
    Sleep(600);

    if ((strcmp(pass, q) || strcmp(user, p)))
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\t\t\t                                                       !!!!!!!! YOU ENTERED WRONG USERNAME & PASSWORD !!!!!!!!                                                                                           ");
        printf("\n");
        printf("\n");
        printf("\n");
        getch();

        goto q;
    }
    else
    {
        system("cls");
        system("COLOR a0");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t                                                                     ACCESS GRANTED   \n                                                                                               ");
        printf("\n\t\t\t                                                                      PRESS ENTER   \n                                                                                                  ");
    }

    getch();
    system("cls");
}
void create()
{

    FILE *fp;
    fp = fopen("E:\\Hobby Projects\\Blood Donars Management\\User Data\\data.txt", "ab+");
    system("cls");
    int x, y;
    tab;
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf(" \t\t\t                                                                       CREATE NEW  RECORD                                                                                                               \n");
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\tEnter first name : ");
    fflush(stdin);
    scanf("%[^\n]%*c", d.fname);
    printf("\n\t\t\tEnter middle name : ");
    fflush(stdin);
    scanf("%[^\n]%*c", d.mname);
    printf("\n\t\t\tEnter last name : ");
    fflush(stdin);
    scanf("%[^\n]%*c", d.lname);
    printf("\n\t\t\tEnter city : ");
    fflush(stdin);
    scanf("%[^\n]%*c", d.add);
    printf("\n\t\t\tEnter contact number : ");
    fflush(stdin);
    scanf("%s", d.no);
    printf("\n\t\t\t gender : ");
    printf("\n\t\t\t-------------------- ");
    printf("\n\t\t\t 1. Male");
    printf("\n\t\t\t 2. Female");
    printf("\n\t\t\t 3. Other");
f:
    printf("\n ");
    printf("\n\t\t\t Select gender : ");
    fflush(stdin);
    scanf("%d", &y);
    switch (y)
    {
    case 1:
        strcpy(d.sex, "Male");

        break;
    case 2:
        strcpy(d.sex, "Female");

        break;
    case 3:
        strcpy(d.sex, "Other");

        break;
    default:
        printf("\n\t\t\tInvalid Input.....");
        goto f;
        break;
    }

    printf("\n\t\t\tEnter age : ");
    fflush(stdin);
    scanf("%d", &d.age);
    if (d.age > 18 || d.age < 60)
    {
        printf("\n\t\t\tYou Are Not Eligible.....\n");
        system("pause");
        login();
    }
    else
    {

        printf("\n\t\t\t blood group ");
        printf("\n\t\t\t-------------------- ");
        printf("\n\t\t\t 1. A+");
        printf("\n\t\t\t 2. A-");
        printf("\n\t\t\t 3. B+");
        printf("\n\t\t\t 4. B-");
        printf("\n\t\t\t 5. AB+");
        printf("\n\t\t\t 6. AB-");
        printf("\n\t\t\t 7. O+");
        printf("\n\t\t\t 8. O-");
    e:
        ("\n ");
        printf("\n\t\t\tSelect blood group : ");
        fflush(stdin);
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            strcpy(d.grp, "A+");

            break;
        case 2:
            strcpy(d.grp, "A-");

            break;
        case 3:
            strcpy(d.grp, "B+");

            break;
        case 4:
            strcpy(d.grp, "B-");

            break;
        case 5:
            strcpy(d.grp, "AB+");

            break;
        case 6:
            strcpy(d.grp, "AB-");

            break;
        case 7:
            strcpy(d.grp, "O+");

            break;
        case 8:
            strcpy(d.grp, "O-");

            break;
        default:
            printf("\n\t\t\tInvalid Input.....");
            break;
        }

        time_t t;
        time(&t);
        strcpy(d.t, ctime(&t));

        fprintf(fp, "%s %s %s %s %s %d %s %s %s  %s \n", d.fname, d.mname, d.lname, d.grp, d.sex, d.age, d.id, d.add, d.no, d.t);
        fprintf(fp, "\n");
        printf("\n");
        fclose(fp);
        tab;
        printf("=======SUCCESSSFUL=======\n");
        system("pause");
    }
}
void search()
{

    int ch, f = 0;
    FILE *fp;
    fp = fopen("E:\\Hobby Projects\\Blood Donars Management\\User Data\\data.txt", "r");

    system("cls");
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf(" \t\t\t                                                                      SEARCH RECORD                                                                                                               \n");
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n\t\t\t***** SEARCH BY ***** \n");
    printf("\t\t\t01.NAME");
    printf("\n");
    printf("\t\t\t02.BLOOD GROUP");
    printf("\n");
    printf("\t\t\t0.EXIT ");
    printf("\n");
    printf("\t\t\tPlease Enter an Option: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        system("cls");

        printf("\n\t\t\tSearch by name : ");
        fflush(stdin);
        scanf("%s", d1.fname);

        while (fscanf(fp, "%s %s %s %s %s %d %s %s %s %[^\n]%*c \n", d.fname, d.mname, d.lname, d.grp, d.sex, &d.age, d.id, d.add, d.no, d.t) != EOF)
        {
            if (strcmpi(d1.fname, d.fname) == 0)
            {
                f = 1;
                printf("\n_________________________________________________________________________________________________________________________________________________________________________________________\n");

                printf("\n\t\t\tNAME :: %s", d.fname);
                printf("\n\t\t\tBLOOD GROUP :: %s", d.grp);
                printf("\n\t\t\tAGE:: %d", d.age);
                printf("\n\t\t\tGENDER :: %s", d.sex);
                printf("\n\t\t\tID NUMBER :: %s", d.id);
                printf("\n\t\t\tCITY :: %s", d.add);
                printf("\n\t\t\tMOBILE NUMBER :: %s\n", d.no);
                printf("\n\t\t\tDATE & TIME :: %s ", d.t);

                printf("\n_________________________________________________________________________________________________________________________________________________________________________________________\n");
                system("pause");
            }
        }
        fclose(fp);

        if (f == 0)
        {
            printf("\n\t\t\tCannot not found!!!!!\n");
            system("pause");
        }
        break;
    case 2:
        system("cls");

        printf("\n\t\t\tSearch by Blood group : ");
        fflush(stdin);
        scanf("%s", d1.grp);

        while (fscanf(fp, "%s %s %s %s %s %d %s %s %s %[^\n]%*c \n", d.fname, d.mname, d.lname, d.grp, d.sex, &d.age, d.id, d.add, d.no, d.t) != EOF)
        {
            if (strcmpi(d1.grp, d.grp) == 0)
            {
                f = 1;
                printf("\n_________________________________________________________________________________________________________________________________________________________________________________________\n");

                printf("\n\t\t\tNAME :: %s", d.fname);
                printf("\n\t\t\tBLOOD GROUP :: %s", d.grp);
                printf("\n\t\t\tAGE:: %d", d.age);
                printf("\n\t\t\tGENDER :: %s", d.sex);
                printf("\n\t\t\tID NUMBER :: %s", d.id);
                printf("\n\t\t\tCITY :: %s", d.add);
                printf("\n\t\t\tMOBILE NUMBER :: %s\n", d.no);
                printf("\n\t\t\tDATE & TIME :: %s\n", d.t);

                printf("\n_________________________________________________________________________________________________________________________________________________________________________________________\n");
                system("pause");
            }
        }
        fclose(fp);

        if (f == 0)
        {
            printf("\n\t\t\tCannot not found!!!!!\n");
            system("pause");
        }
        break;

    case 0:
        break;
    default:
        break;
    }
}
void edit()
{
    system("cls");

    int ch, f = 0;
    FILE *fp, *fp1;
    fp = fopen("E:\\Hobby Projects\\Blood Donars Management\\User Data\\data.txt", "r");
    fp1 = fopen("E:\\Hobby Projects\\Blood Donars Management\\User Data\\temp.txt", "w");
    tab;
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf(" \t\t\t                                                                       EDIT RECORD                                                                                                               \n");
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    int c, r;
    printf("\n\t\t\tSearch by Mob NO. : ");
    fflush(stdin);
    scanf("%s", d1.no);

    while (fscanf(fp, "%s %s %s %s %s %d %s %s %s %[^\n]%*c \n", d.fname, d.mname, d.lname, d.grp, d.sex, &d.age, d.id, d.add, d.no, d.t) != EOF)
    {
        if (strcmpi(d1.no, d.no) == 0)
        {
            f = 1;
            do
            {
                system("cls");
                printf("\n\t\t\t*************************\n");
                printf("\n\t\t\t What you want to edit\n");
                printf("\n\t\t\t*************************\n");
                printf("\n");
                printf("\n");
                printf("\t\t\t01.First NAME");
                printf("\n");
                printf("\t\t\t02.Middle NAME");
                printf("\n");
                printf("\t\t\t03.Last NAME");
                printf("\n");
                printf("\t\t\t04.MOBILE NUMBER");
                printf("\n");
                printf("\t\t\t05.CITY");
                printf("\n");
                printf("\t\t\t06.ID NUMBER");
                printf("\n");
                printf("\t\t\t07.BLOOD GRP");
                printf("\n");
                printf("\t\t\t08.GENDER ");
                printf("\n");
                printf("\t\t\t09.AGE ");
                printf("\n");
                printf("\t\t\t0.EXIT ");
                printf("\n");
                printf("\t\t\tPlease Enter an Option: ");
                scanf("%d", &ch);

                switch (ch)
                {
                case 1:
                    printf("\n\t\t\tENTER NEW NAME : ");
                    fflush(stdin);
                    scanf("%s", d.fname);

                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                case 2:
                    printf("\n\t\t\tENTER NEW MIDDLE NAME : ");
                    fflush(stdin);
                    scanf("%s", d.mname);

                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                case 3:
                    printf("\n\t\t\tENTER NEW LAST NAME : ");
                    fflush(stdin);
                    scanf("%s", d.lname);

                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                case 4:
                    printf("\n\t\t\tENTER NEW CONTACT NUMBER : ");
                    fflush(stdin);
                    scanf("%s", &d.no);
                    tab;
                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                case 5:
                    printf("\n\t\t\tENTER NEW CITY : ");
                    fflush(stdin);
                    scanf("%s", d.add);
                    tab;
                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                case 6:
                    printf("\n\t\t\tEnNTER NEW ID NUMBER : ");
                    fflush(stdin);
                    scanf("%s", d.id);
                    tab;
                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                case 7:
                    printf("\n\t\t\t blood group ");
                    printf("\n\t\t\t-------------------- ");
                    printf("\n\t\t\t 1. A+");
                    printf("\n\t\t\t 2. A-");
                    printf("\n\t\t\t 3. B+");
                    printf("\n\t\t\t 4. B-");
                    printf("\n\t\t\t 5. AB+");
                    printf("\n\t\t\t 6. AB-");
                    printf("\n\t\t\t 7. O+");
                    printf("\n\t\t\t 8. O-");
                b:
                    ("\n ");
                    printf("\n\t\t\tSelect blood group : ");
                    fflush(stdin);
                    scanf("%d", &c);
                    switch (c)
                    {
                    case 1:
                        strcpy(d.grp, "A+");

                        break;
                    case 2:
                        strcpy(d.grp, "A-");

                        break;
                    case 3:
                        strcpy(d.grp, "B+");

                        break;
                    case 4:
                        strcpy(d.grp, "B-");

                        break;
                    case 5:
                        strcpy(d.grp, "AB+");

                        break;
                    case 6:
                        strcpy(d.grp, "AB-");

                        break;
                    case 7:
                        strcpy(d.grp, "O+");

                        break;
                    case 8:
                        strcpy(d.grp, "O-");

                        break;
                    default:
                        printf("\n\t\t\tInvalid Input.....");
                        goto b;
                        break;
                    }
                    tab;
                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                case 8:
                    printf("\n\t\t\t gender : ");
                    printf("\n\t\t\t-------------------- ");
                    printf("\n\t\t\t 1. Male");
                    printf("\n\t\t\t 2. Female");
                    printf("\n\t\t\t 3. Other");
                a:
                    printf("\n ");
                    printf("\n\t\t\t Select gender : ");
                    fflush(stdin);
                    scanf("%d", &r);
                    switch (r)
                    {
                    case 1:
                        strcpy(d.sex, "Male");

                        break;
                    case 2:
                        strcpy(d.sex, "Female");

                        break;
                    case 3:
                        strcpy(d.sex, "Other");

                        break;
                    default:
                        printf("\n\t\t\tInvalid Input.....");
                        goto a;
                        break;
                    }
                    tab;
                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                case 9:
                    printf("\n\t\t\tENTER NEW AGE: ");
                    fflush(stdin);
                    scanf("%d", &d.age);
                    tab;
                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                case 0:
                    fprintf(fp1, "%s %s %s %s %s %d %s %s %s  %s \n", d.fname, d.mname, d.lname, d.grp, d.sex, d.age, d.id, d.add, d.no, d.t);
                    tab;
                    printf("=======SUCCESSSFUL=======\n");
                    system("pause");
                    break;
                }

            } while (ch != 0);
        }
        else
        {
            fprintf(fp1, "%s %s %s  %s %s %d %s %s %s  %s \n", d.fname, d.mname, d.lname, d.grp, d.sex, d.age, d.id, d.add, d.no, d.t);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("E:\\Hobby Projects\\Blood Donars Management\\User Data\\data.txt");
    rename("E:\\Hobby Projects\\Blood Donars Management\\User Data\\temp.txt", "E:\\Hobby Projects\\Blood Donars Management\\User Data\\data.txt");
    if (f == 0)
    {
        printf("\n\t\t\tCANNOT FOUND THE NAME\n");
        system("pause");
    }
}

void delete()
{
    int n, a, f = 0;
    FILE *fp, *fp1;
    fp = fopen("E:\\Hobby Projects\\Blood Donars Management\\User Data\\data.txt", "r");
    fp1 = fopen("E:\\Hobby Projects\\Blood Donars Management\\User Data\\temp.txt", "w");

    tab;
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf(" \t\t\t                                                                       DELETE RECORD                                                                                                              \n");
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\tSearch by Mob NO. : ");
    fflush(stdin);
    scanf("%s", d1.no);

    while (fscanf(fp, "%s %s %s %s %s %d %s %s %s %[^\n]%*c \n", d.fname, d.mname, d.lname, d.grp, d.sex, &d.age, d.id, d.add, d.no, d.t) != EOF)
    {

        if (strcmpi(d1.no, d.no) == 0)
        {
            f = 1;
        }
        else
        {
            fprintf(fp1, "%s %s %s %s %s %d %s %s %s  %s \n", d.fname, d.mname, d.lname, d.grp, d.sex, d.age, d.id, d.add, d.no, d.t);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("E:\\Hobby Projects\\Blood Donars Management\\User Data\\data.txt");
    rename("E:\\Hobby Projects\\Blood Donars Management\\User Data\\temp.txt", "E:\\Hobby Projects\\Blood Donars Management\\User Data\\data.txt");
    if (f == 0)
    {
        printf("\n\t\t\tCANNOT FOUND THE NAME\n");
        system("pause");
    }
    else
    {
        printf("\n\t\t\tSUCCESSFULLY DELETED\n");
        system("pause");
    }
}
void display()
{

    int ch, f = 0;
    FILE *fp;
    fp = fopen("E:\\Hobby Projects\\Blood Donars Management\\User Data\\data.txt", "r");

    system("cls");
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf(" \t\t\t                                                                       DISPLAYING RECORD                                                                                                               \n");
    printf("\n\t\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n");

    while (fscanf(fp, "%s %s %s %s %s %d %s %s %s %[^\n]%*c \n", d.fname, d.mname, d.lname, d.grp, d.sex, &d.age, d.id, d.add, d.no, d.t) != EOF)
    {
        printf("\n_________________________________________________________________________________________________________________________________________________________________________________________\n");

        printf("\n\t\t\t NAME :: %s %s %s", d.fname, d.mname, d.lname);
        printf("\n\t\t\tBLOOD GROUP :: %s", d.grp);
        printf("\n\t\t\tAGE:: %d", d.age);
        printf("\n\t\t\tGENDER :: %s", d.sex);
        printf("\n\t\t\tID NUMBER :: %s", d.id);
        printf("\n\t\t\tCITY :: %s", d.add);
        printf("\n\t\t\tMOBILE NUMBER :: %s\n", d.no);
        printf("\n\t\t\tDATE & TIME :: %s ", d.t);

        printf("\n_________________________________________________________________________________________________________________________________________________________________________________________\n");
    }

    fclose(fp);
    system("pause");
}
void main()
{
    int a;
    char ch;

    login();
    do
    {
        system("cls");
        system("COLOR 84");
        printf("\n\t\t__________________________________________________________________________________________________________________________________________________________________________________________\n");
        printf("\n\n\t\t\t                                                                       WELCOME TO BLOOD BANK                                                                                                                                                \n");
        printf("\n\t\t_________________________________________________________________________________________________________________________________________________________________________________________\n");

        printf("\n\n\n\n\t                                                                        01.CREATE A NEW RECORD                                                                                             ");
        printf("\n");
        printf("\n\t                                                                        02.SEARCH                                                                                                          ");
        printf("\n");
        printf("\n\t                                                                        03.EDIT RECORDS                                                                                                    ");
        printf("\n");
        printf("\n\t                                                                        04.DISPLAY ALL THE RECORDS                                                                                         ");
        printf("\n");
        printf("\n\t                                                                        05.DELETE A RECORD                                                                                                 ");
        printf("\n");
        printf("\n\t\t______________________________________________________________________________________________________________________________________________________________________________________________\n");
        printf("\n\t\t\t\t\t\t\t\t\t\tPlease Enter an Option:");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            system("COLOR 80");
            create();
            break;
        case 2:
            system("COLOR 0f");
            search();
            break;
        case 3:
            system("COLOR 02");
            edit();
            break;
        case 4:
            system("COLOR 0f");
            display();
            break;
        case 5:
            system("COLOR 84");
            delete ();
            break;
        }

    } while (ch != 'n');
}
