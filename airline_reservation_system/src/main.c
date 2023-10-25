#include "../include/main.h"

#define file_path "../References/plane.csv"
int flag = 0;

/*
    初始化全部链表和队列,并导入csv文件
    函数名：InitAll
    参数：无
    返回值：Linelist *L
*/
Linelist *InitAll()
{
    Linelist *L = InitLineList();
    ReadLineList(L, file_path);
    return L;
}

/*
    


*/
void case2(Linelist *L)

{
    printf("请输入目的地\n");
            char destination[100]; //目的地
            destination[0] = '\0'; //清空字符串
            getchar(); //清空缓冲区
            fgets(destination, 100, stdin); //到回车停止录入
            destination[strlen(destination) - 1] = '\0'; //去掉回车
            printf("请输入日期(输入方式：年月日，例如2023.04.26，输入230426)\n");
            char date[8];
            scanf("%s", date);
            printf("请输入时间(输入方式：时分，例如12:34，输入1234)\n");
            char time[4];
            scanf("%s", time);

            Linelist *p=SearchLineList(L, destination,date,time);
            if(p!=NULL)
            {
                PrintLine(p);
                printf("是否选择这个航班？(y/n)");
                char choice;
                getchar();
                scanf("%c",&choice);
                if(choice=='y' || choice=='Y')
                {
                    printf("请输入您的姓名：");
                    char name[100];
                    getchar();
                    fgets(name,100,stdin);
                    name[strlen(name)-1]='\0';
                    printf("请输入您的身份证号：");
                    unsigned long certificate_no;
                    scanf("%lu",&certificate_no);
                    if(p->remain_seat!=0)
                    {
                        printf("本航班还有剩余座位,是否预定？(y/n)");
                        getchar();
                        char choice2;
                        scanf("%c",&choice2);
                        if(choice2 == 'y' || choice2 == 'Y')
                        {

                            
                            printf("正在打印您的订单，请稍后...\n");
                            // usleep(1000000000);
                            int seat_no=p->max_seat-p->remain_seat+1;
                            p->remain_seat--;
                            //生成订单号
                            char seat_no_str[100]="\0" ;
                            sprintf(seat_no_str,"%d",seat_no);
                            unsigned long long orderform_no;
                            char orderform_no_str[100]="\0" ;
                            sprintf(orderform_no_str,"%llu",p->line_no);
                            strcat(orderform_no_str,seat_no_str);
                            orderform_no=atoll(orderform_no_str);
                            Booked *b=(Booked *)malloc(sizeof(Booked));
                            b->orderform_no=orderform_no;
                            strcpy(b->name,name);
                            b->certificate_no=certificate_no;
                            b->amount=1;
                            b->seat_no=seat_no;
                            b->next=NULL;
                            int a = LengthBookedList(p->booked);
                            if(a==0)
                            {
                                p->booked->next=b;
                            }
                            else
                            {
                                Booked *q=p->booked;
                                while(q->next!=NULL)
                                {
                                    q=q->next;
                                }
                                q->next=b;
                            }
                            PrintBooked(b);
                            printf("您的订单已打印完成，请妥善保管！\n");
                            char plane_path[100]="../References/Booked/booked";
                            char plane_no_str[10]="\0" ;
                            sprintf(plane_no_str,"%d",p->plane_no);
                            strcat(plane_path,plane_no_str);
                            strcat(plane_path,".csv");
                            UpdateBookedList(p->booked,plane_path);
                        
                       }

                }
                
                
            }
            else printf("退出\n");
            }
            else printf("未找到符合条件的航班！\n");}
//客票退票
void case3(Linelist *L)
{
    printf("请输入您的订单号：");
    unsigned long long orderform_no;
    scanf("%llu",&orderform_no);
    Linelist *p=L->next;
    printf("正在查询订单号，请稍后...\n");
    while (p!=NULL)
    {
        // LengthBookedList(p->booked)
        Booked *q=p->booked->next;
        while(q != NULL)
        {
            int a=0;
            a=GetBooked(p->booked,orderform_no);
            if(a!=0)
            {
                printf("正在退票，请稍后...\n");
                Booking *b=(Booking *)malloc(sizeof(Booking));
                DeBookingList(p->booking,b);
                //找到a位置的booked
                Booked *b2=getBookedByIndex(p->booked,a);
                PrintBooked(b2);
                b2->certificate_no=b->certificate_no;
                strcpy(b2->name,b->name);
                // PrintBooked(b2);
                printf("退票成功！\n");
                char plane_path[100]="../References/Booked/booked";
                char plane_no_str[10]="\0" ;
                char plane_path2[100]="../References/Booking/booking";
                sprintf(plane_no_str,"%d",p->plane_no);
                strcat(plane_path,plane_no_str);
                strcat(plane_path2,plane_no_str);
                strcat(plane_path2,".csv");
                strcat(plane_path,".csv");
                UpdateBookedList(p->booked,plane_path);
                DataupBookingList(p->booking,plane_path2);
                return ;
            }
            q=q->next;
        }
        p=p->next;
    }
    printf("未找到订单号，请检查输入是否正确！\n");
}
int password()
{
     int a=0;
    char username[20]; //用户名
    char password[20]; //密码
    char input1[20]; //用户输入缓冲区
    char input[20]; //用户输入缓冲区
    strcpy(username, "admin"); //预设用户名为admin
    strcpy(password, "123456"); //预设密码为123456
    printf("请输入用户名：\n");
    scanf("%s", input1); //获取用户名
    printf("请输入密码：\n");
    scanf("%s", input); //获取密码
    if(strcmp(username, input1) == 0) //如果用户名正确，继续判断密码
    {
        if(strcmp(password, input) == 0) //如果密码正确，输出登录成功
        {
            a=1;
            printf("\n登录成功！\n");
            return a;
        }
        else //如果密码错误，输出登录失败
        {
            printf("\n密码错误！\n");
            return a;
        }
    }
    else //如果用户名错误，输出登录失败
    {
        printf("\n用户名错误！\n");
        return a;
    }
}
void case4(Linelist *L)
{
    int a;
    a=password();
    while(a)
    {
        printf("1.添加航班\n");
        printf("2.删除航班\n");
        printf("3.修改航班\n");
        printf("4.退出管理系统\n");
        printf("请输入您的选择：");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("正在添加航班，请稍后...\n");
            L=AddLineList(L);
            break;
        case 2:
            printf("请输入要删除的航班号：");
            unsigned long line_no;
            scanf("%lu",&line_no);
            printf("正在删除航班，请稍后...\n");
            DeleteLineList(L,line_no);
            WriteLineList(L,file_path);
            printf("删除航班成功！\n");
            break;
        case 3:
            ModifyLineList(L);
            break;
        case 4:
            return;
            break;
        default:
            break;
        }
    }




    
}

int main()
{
    // setlocale(LC_ALL, "zh_CN");
    //  initscr();
    //  raw();
    // noecho();
    // keypad(stdscr, TRUE);
    // curs_set(0);
    // attron(A_BOLD); //开启粗体属性
   Linelist *L = InitAll();
   printf("正在初始化系统，请稍后...\n");
  
    while (flag==0)
    {
        // printf("按回车继续\n");
        // getchar();
        // printf("\33[2J");
        printf("欢迎使用航空订票系统！\n");
        printf("1.查询航班信息\n");
        printf("2.客票订票\n");
        printf("3.客票退票\n");
        printf("4.管理系统\n");
        printf("5.退出系统\n");
        printf("输入其他数字或字符循环系统\n");
        printf("请输入您的选择：");
        scanf("%d", &flag);
        // refresh();
        switch (flag)
        {
        case 1:
            printf("请输入目的地\n");
            char destination[100]; //目的地
            destination[0] = '\0'; //清空字符串
            getchar(); //清空缓冲区
            fgets(destination, 100, stdin); //到回车停止录入
            destination[strlen(destination) - 1] = '\0'; //去掉回车
            printf("请输入日期(输入方式：年月日，例如2023.04.26，输入230426)\n");
            char date[8];
            scanf("%s", date);
            printf("请输入时间(输入方式：时分，例如12:34，输入1234)\n");
            char time[4];
            scanf("%s", time);
            printf("正在查询航班信息，请稍后...\n");
            Linelist *p=SearchLineList(L, destination,date,time);
            if(p==NULL)
            {
                printf("未找到符合条件的航班！\n");
                
            }
            else PrintLine(p);
            flag = 0;
            break;
        case 2:
            case2(L);
            flag = 0;
            break;
        case 3:
        //客票退票
            case3(L);
            flag = 0;
            break;
        case 4:
            //管理系统
            case4(L);
            flag = 0;
            break;  
        
        case 5:
            break;
        default:
            flag = 0;
            // continue;
            break;
        }
        

    }
    return 0;

}




