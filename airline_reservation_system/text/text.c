// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     printf("请输入目的地\n");
//             char destination[100];
//             //到回车停止录入
//             // fflush(stdin);
//             destination[0] = '\0';
//             // printf("%d",1);

//             fgets(destination, 100, stdin);
//             // printf("%d",2);
//             printf("%s", destination);
//             printf("请输入日期(输入方式：年-月-日\n");
//             return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include <unistd.h>
// #include <ncurses.h>
// #include <locale.h>
// int main(int argc, char const *argv[])
// {
//     initscr();
//     raw();
//     noecho();
//     keypad(stdscr, TRUE);
//     curs_set(0);
//     char* c="my first window";
//     mvprintw(LINES/2,(COLS-strlen(c))/2,c);
//     refresh();
//     getch();
//     endwin();
//     return 0;
// }

void case4(Linelist *L)
{
    int a=0;
    a = password();
    
    while(a)
    {
        printf("1.添加航班\n");
        printf("2.删除航班\n");
        printf("3.修改航班\n");
        printf("4.退出管理系统\n");
        printf("请输入您的选择：");
        int choice;
        scanf("%d",&choice);
        unsigned long line_no;
        Linelist *p=Linelist *)malloc(sizeof(Linelist));
        char Booked_path[100]="../References/Booked/booked";
        char Booking_path[100]="../References/Booking/booking";
        switch (choice)
        {
        case 1:
            printf("正在添加航班，请稍后...\n");
            printf("请输入目的地：");
            p->destination[0] = '\0'; //清空字符串
            getchar(); //清空缓冲区
            fgets(p->destination, 100, stdin); 
            p->destination[strlen(p->destination) - 1] = '\0'; //去掉回车
            p->plane_no=LengthLineList(L)+1;
            printf("请输入日期(输入方式：年-月-日，例如2023.04.26，输入2023-04-26)：");
            scanf("%d-%d-%d",&p->date[0],&p->date[1],&p->date[2]);
            printf("请输入星期：");
            scanf("%d",&p->week);
            printf("请输入时间(输入方式：时：分，例如12:34，输入12：34)：");
            scanf("%d:%d",&p->time[0],&p->time[1]);
            printf("请输入价格：");
            scanf("%f",&p->price);
            printf("请输入折扣：");
            scanf("%f",&p->discount);
            printf("请输入座位数：");
            scanf("%d",&p->max_seat);
            p->remain_seat=p->max_seat;
            p->booked=InitBookedList();
            p->booking=InitBookingList(p->booking);
            p->next=NULL;
            
            char line_no_str[100]="\0" ;
            sprintf(x,"%d",p->date[0]);
            strcat(line_no_str,&x[2]);
            strcat(line_no_str,&x[3]);
            sprintf(x,"%d",p->date[1]);
            strcat(line_no_str,x);
            sprintf(x,"%d",p->date[2]);
            strcat(line_no_str,x);
            sprintf(x,"%d",p->time[0]);
            strcat(line_no_str,x);
            sprintf(x,"%d",p->time[1]);
            strcat(line_no_str,x);
            sprintf(x,"%d",p->plane_no);
            strcat(line_no_str,x);
            p->line_no=atoll(line_no_str);
            InsertLineList(L,p);
            WriteLineList(L,file_path);
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
            PrintLine(p);
            printf("添加航班成功！\n");


            break;
        case 2: 
            printf("请输入要删除的航班号：");
            scanf("%lu",&line_no);
            printf("正在删除航班，请稍后...\n");
            DeleteLineList(L,line_no);
            WriteLineList(L,file_path);
            printf("删除航班成功！\n");
            break;
        case 3:
            printf("请输入要修改的航班号：");
            scanf("%lu",&line_no);
            
            while(p!=NULL)
            {
                if(p->line_no==line_no)
                {
                    printf("找到航班！\n");
                    break;
                }
                p=p->next;
            }
            if (p==NULL)
            {
                printf("未找到航班！\n");
                break;
            }
            printf("输入想要修改的信息：\n");
            printf("请输入目的地：");
            p->destination[0] = '\0'; //清空字符串
            getchar(); //清空缓冲区
            fgets(p->destination, 100, stdin);
            p->destination[strlen(p->destination) - 1] = '\0'; //去掉回车
            printf("请输入日期(输入方式：年-月-日，例如2023.04.26，输入2023-04-26)：");
            scanf("%d-%d-%d",&p->date[0],&p->date[1],&p->date[2]);
            printf("请输入星期：");
            scanf("%d",&p->week);
            printf("请输入时间(输入方式：时：分，例如12:34，输入12：34)：");
            scanf("%d:%d",&p->time[0],&p->time[1]);
            printf("请输入价格：");
            scanf("%f",&p->price);
            printf("请输入折扣：");
            scanf("%f",&p->discount);
            int max_seat=p->max_seat;
            printf("请输入座位数：");
            scanf("%d",&p->max_seat);
            p->remain_seat=p->remain_seat+p->max_seat-max_seat;
            &line_no_str=
            sprintf(x,"%d",p->date[0]);
            strcat(line_no_str,x[2]);
            strcat(line_no_str,x[3]);
            sprintf(x,"%d",p->date[1]);
            strcat(line_no_str,x);
            sprintf(x,"%d",p->date[2]);
            strcat(line_no_str,x);
            sprintf(x,"%d",p->time[0]);
            strcat(line_no_str,x);
            sprintf(x,"%d",p->time[1]);
            strcat(line_no_str,x);
            sprintf(x,"%d",p->plane_no);
            strcat(line_no_str,x);
            p->line_no=atoll(line_no_str);
            WriteLineList(L,file_path);
            char plane_path[100]="../References/Booked/booked";
            char plane_no_str[10]="\0" ;
            char plane_path2[100]="../References/Booking/booking";
            sprintf(plane_no_str,"%d",p->plane_no);
            strcat(plane_path,plane_no_str);
            strcat(plane_path2,plane_no_str);
            strcat(plane_path2,".csv");
            strcat(plane_path,".csv");
            while (p->booked->next!=NULL)
            {
                p->booked->orderform_no=p->line_no*1000+p->booked->seat_no;
                p->booked=p->booked->next;

            }
            UpdateBookedList(p->booked,plane_path);
            Booking *b = p->booking->booking_head;
            while (b->next!=p->booking->booking_tail)
            {
                b->line_no=p->line_no;
                b->date[0]=p->date[0];
                b->date[1]=p->date[1];
                b->date[2]=p->date[2];
                b->time[0]=p->time[0];
                b->time[1]=p->time[1];
                b=b->next;
            }
            p->booking->booking_tail->line_no=p->line_no;
            p->booking->booking_tail->date[0]=p->date[0];
            p->booking->booking_tail->date[1]=p->date[1];
            p->booking->booking_tail->date[2]=p->date[2];
            p->booking->booking_tail->time[0]=p->time[0];
            p->booking->booking_tail->time[1]=p->time[1];

            DataupBookingList(p->booking,plane_path2);
            // char destination[100]; //目的地
            // destination[0] = '\0'; //清空字符串
            // getchar(); //清空缓冲区
            // fgets(destination, 100, stdin); //到回车停止录入
            // destination[strlen(destination) - 1] = '\0'; //去掉回车
            // printf("请输入日期(输入方式：年-月-日，例如2023.04.26，输入2023-04-26)：");
            // char date[11];
            // scanf("%s",date);
            // printf("请输入星期：");
            // int week;
            // scanf("%d",&week);
            // printf("请输入时间(输入方式：时：分，例如12:34，输入12：34)：");
            // char time[6];
            // scanf("%s",time);
            // printf("请输入价格：");
            // float price;
            // scanf("%f",&price);
            // printf("请输入折扣：");
            // float discount;
            // scanf("%f",&discount);
            // printf("请输入座位数：");
            // int max_seat;
            // scanf("%d",&max_seat);
            // int remain_seat;
            // remain_seat=max_seat;
      

            break;
      
        case 4:
            a=0;
            break;
        default:
            break;
        }


    }
    return;
}