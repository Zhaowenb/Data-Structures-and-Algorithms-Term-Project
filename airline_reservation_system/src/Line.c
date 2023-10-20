/*
    *航班链表--Line.c
    *航班链表的初始化、插入、删除、销毁、打印、查询、排序等操作
    *作者：赵文渤
    *学号：2022213132
    *班级：电子信息类5班
    *完成日期：2023.9.30
    *学校：东北林业大学
    *版本：1.0
    *编译环境：GCC
    *运行环境：Linux（Ubuntu20.04）
    *开源地址：https://www.github.com/zhao
*/

#include "../include/Line.h"

/*
初始化航班链表
函数名：InitLineList
参数：无
返回值：空单链表
*/
Linelist *InitLineList()
{
    Linelist *head = (Linelist *)malloc(sizeof(Linelist));
    head->booked=(Booked *)malloc(sizeof(Booked));
    head->booking=(BookingList *)malloc(sizeof(BookingList));
    head->booked = InitBookedList();
    head->booking=InitBookingList(head->booking);
    head->next = NULL;
    return head;
}

/*
    判断航班链表是否为空
    函数名：isEmptyLineList
    参数：Linelist *L
    返回值：1为空，0为非空
*/
int isEmptyLineList(Linelist *L)
{
    if(L->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
    在航班链表打印所有航班信息
    函数名：PrintLineList
    参数：Linelist *L
    返回值：无
*/
void PrintLineList(Linelist *L)
{
    Linelist *p = L->next;
    while(p != NULL)
    {
        printf("航班号：%llu\t目的地：%s\t日期：%d-%d-%d\t星期：%d\t时间：%d:%d\t价格：%f\t折扣：%f\t座位数：%d\t剩余座位数：%d\n",p->line_no,p->destination,p->date[0],p->date[1],p->date[2],p->week,p->time[0],p->time[1],p->price,p->discount,p->max_seat,p->remain_seat);
        p = p->next;
    }
}

/*
    打印航班
    函数名：PrintLine
    参数：Linelist *p
    返回值：无
*/
void PrintLine(Linelist *p)
{
    printf("航班号：%llu\t目的地：%s\t日期：%d-%d-%d\t星期：%d\t时间：%d:%d\t价格：%f\t折扣：%f\t座位数：%d\t剩余座位数：%d\n",p->line_no,p->destination,p->date[0],p->date[1],p->date[2],p->week,p->time[0],p->time[1],p->price,p->discount,p->max_seat,p->remain_seat);
}

/*
    在航班链表尾部插入航班信息
    函数名：InsertLineList
    参数：Linelist *L,Linelist *e
    返回值：无
*/
void InsertLineList(Linelist *L,Linelist *e)
{
    Linelist *p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = e;
    e->next = NULL;
}

/*
    航班数量
    函数名：LengthLineList
    参数：Linelist *L
    返回值：航班数量
*/
int LengthLineList(Linelist *L)
{
    Linelist *p = L->next;
    int length = 0;
    while(p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

/*
    航班链表排序
    函数名：SortLineList
    参数：Linelist *L
    返回值：无
    注：按照航班号从小到大排序
*/
void SortLineList(Linelist *L)
{
    Linelist *p = L->next;
    Linelist *q = NULL;
    Linelist *min = NULL;
    Linelist *minp = NULL;
    Linelist *temp = NULL;
    while(p != NULL)
    {
        min = p;
        minp = p;
        q = p->next;
        while(q != NULL)
        {
            if(q->line_no < min->line_no)
            {
                min = q;
                minp = q;
            }
            q = q->next;
        }
        if(min != p)
        {
            temp = p->next;
            p->next = min->next;
            min->next = temp;
            minp->next = p;
        }
        p = p->next;
    }
}
// void SortLineList(Linelist *L)
// {
//     if(L == NULL || L->next == NULL) // 如果链表为空或只有一个节点，直接返回
//         return;
//     Linelist *p = L->next;
//     Linelist *q = NULL;
//     Linelist *min = NULL;
//     Linelist *temp = NULL;
//     while(p != NULL)
//     {
//         min = p;
//         q = p->next;
//         while(q != NULL)
//         {
//             if(q->line_no < min->line_no)
//             {
//                 min = q;
//             }
//             q = q->next;
//         }
//         if(min != p)
//         {
//             temp = min->next; // 保存min后面的节点
//             q = p; // 找到p前面的节点
//             if(q->next == NULL) // 如果q已经是最后一个节点，直接跳出循环
//                 break;

//             while(q->next != p)
//                 q = q->next;
//             q->next = min; // 将min插入到p前面
//             min->next = p; // 将p接在min后面
//             p->next = temp; // 将min后面的节点接在p后面
//         }
//         p = p->next; // 移动到下一个要排序的节点
//     }
// }


/*
    查询航班
    函数名：SearchLineList
    参数：Linelist *L,char *destination,int *date,int *time
    返回值：Linelist *p
*/
Linelist *SearchLineList(Linelist *L,char *destination,char *date,char *time)
{
    Linelist *p = L->next;
    while(p != NULL)
    {  
        if(strcmp(p->destination,destination) == 0 )
        {
            char data[100];
            strcpy(data,date);
            strcat(data,time);
            
            unsigned long long date_int = atoi(data);
            if(p->line_no >= date_int)
            { 
                return p;
            }
        }
        p = p->next;
    }
    return NULL;
}

/*
    删除航班
    函数名：DeleteLineList
    参数：Linelist *L,unsigned long line_no
    返回值：无
*/
void DeleteLineList(Linelist *L,unsigned long line_no)
{
    Linelist *p = L;
    Linelist *q = L->next;
    while(q != NULL)
    {
        if(q->line_no == line_no)
        {
            p->next = q->next;
            free(q);
            DestroyBookedList(q->booked);
            DestroyBookingList(q->booking);
            return;
        }
        p = q;
        q = q->next;
    }
}

/*
    销毁航班链表
    函数名：DestroyLineList
    参数：Linelist *L
    返回值：无
*/
void DestroyLineList(Linelist *L)
{
    Linelist *p = L;
    Linelist *q = L->next;
    while(q != NULL)
    {
        DestroyBookedList(q->booked);
        DestroyBookingList(q->booking); 
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

/*
    从文件中读取航班信息
    函数名：ReadLineList
    参数：Linelist *L char *filename
    返回值：无
*/
void ReadLineList(Linelist *L,char *filename)
{
    FILE *fp = fopen(filename,"r");
    if(fp == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    Linelist *p = L;
    Linelist *q = NULL;
    while(!feof(fp))
    {
        q = (Linelist *)malloc(sizeof(Linelist));
        char BookedFileName[100];
        char BookingFileName[100];
        fscanf(fp,"%[^,],%d,%d-%d-%d,%d,%d:%d,%llu,%f,%f,%d,%d,%[^,],%s\n",q->destination,&q->plane_no,&q->date[0],&q->date[1],&q->date[2],&q->week,&q->time[0],&q->time[1],&q->line_no,&q->price,&q->discount,&q->max_seat,&q->remain_seat,BookedFileName,BookingFileName);
        q->next = NULL;
        p->next = q;
        p = q;
        q->booked = InitBookedList();
        q->booking = InitBookingList(q->booking);
        
        CreateBookedList(q->booked,BookedFileName);
        // printf("%s\n",BookedFileName);
        InputBookingList(q->booking,BookingFileName);


        // printf("%s\n",BookedFileName);
        // printf("%s\n",BookingFileName);
        

        printf("读取成功！\n");
    }
    fclose(fp);
}

/*
    将航班信息写入文件
    函数名：WriteLineList
    参数：Linelist *L char *filename
    返回值：无
*/
void WriteLineList(Linelist *L,char *filename)
{
    FILE *fp = fopen(filename,"w");
    if(fp == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    Linelist *p = L->next;
    while(p != NULL)
    {
        fprintf(fp,"%s,%d,%d-%d-%d,%d,%d:%d,%llu,%f,%f,%d,%d,%s%d%s,%s%d%s\n",p->destination,p->plane_no,p->date[0],p->date[1],p->date[2],p->week,p->time[0],p->time[1],p->line_no,p->price,p->discount,p->max_seat,p->remain_seat,"../References/Booked/booked",p->plane_no,".csv","../References/Booking/booking",p->plane_no,".csv");
        p = p->next;
    }
    fclose(fp);
}

/*
    添加航班
    函数名：AddLineList
    参数：Linelist *L
    返回值：Linelist *L
*/
Linelist *AddLineList(Linelist *L)
{
    Linelist *p = (Linelist *)malloc(sizeof(Linelist));
    printf("请输入目的地：");
    p->destination[0] = '\0'; //清空字符串
    fgets(p->destination, 100, stdin); 
    p->destination[strlen(p->destination) - 1] = '\0'; //去掉回车
    p->plane_no=LengthLineList(L)+1;
    printf("请输入日期(输入方式：年-月-日，例如2023.04.26，输入2023-04-26)：");
    char date1[5];
    char date2[3];
    char date3[3];
    char date0[9];
    scanf("%s",date0);
    date1[0]=date0[0];
    date1[1]=date0[1];
    date1[2]=date0[2];
    date1[3]=date0[3];
    date1[4]='\0';
    date2[0]=date0[4];
    date2[1]=date0[5];
    date2[2]='\0';
    date3[0]=date0[6];
    date3[1]=date0[7];
    date3[2]='\0';
    p->date[0]=atoi(date1);
    p->date[1]=atoi(date2);
    p->date[2]=atoi(date3);
    printf("%s\n",date1);
    printf("%s\n",date2);
    printf("%s\n",date3);
    printf("%d\n",p->date[0]);
    printf("%d\n",p->date[1]);
    printf("请输入星期：");
    scanf("%d",&p->week);
    printf("请输入时间(输入方式：时：分，例如12:34，输入12：34)：");
    char time1[3];
    char time2[3];
    char time0[5];
    scanf("%s",time0);
    time1[0]=time0[0];
    time1[1]=time0[1];
    time1[2]='\0';
    time2[0]=time0[2];
    time2[1]=time0[3];
    time2[2]='\0';
    printf("%s\n",time1);
    printf("%s\n",time2);
    
    p->time[0]=atoi(time1);
    p->time[1]=atoi(time2);
    printf("%s\n",time1);
    printf("%s\n",time2);
    printf("请输入价格：");
    scanf("%f",&p->price);
    printf("请输入折扣：");
    scanf("%f",&p->discount);
    printf("请输入座位数：");
    scanf("%d",&p->max_seat);
    p->remain_seat=p->max_seat;
    char line_no_str[100]="\0" ;
    line_no_str[0]=date1[2];
    line_no_str[1]=date1[3];
    strcat(line_no_str,date2);
    printf("%s\n",line_no_str);
    strcat(line_no_str,date3);
    printf("%s\n",line_no_str);
    strcat(line_no_str,time1);
    strcat(line_no_str,time2);
    p->line_no=atoll(line_no_str)*1000+p->plane_no;
    char plane_path[100]="../References/Booked/booked";
    char plane_no_str[10]="\0" ;
    char plane_path2[100]="../References/Booking/booking";
    sprintf(plane_no_str,"%d",p->plane_no);
    strcat(plane_path,plane_no_str);
    strcat(plane_path2,plane_no_str);
    strcat(plane_path2,".csv");
    strcat(plane_path,".csv");
    p->booked=InitBookedList();
    p->booking=InitBookingList(p->booking);
    p->next=NULL;
    InsertLineList(L,p);
    WriteLineList(L,"../References/plane.csv");
    UpdateBookedList(p->booked,plane_path);
    DataupBookingList(p->booking,plane_path2);
    printf("添加成功！\n");
    return L;
}



/*
    修改航班
    函数名：ModifyLineList
    参数：Linelist *L
    返回值：无
*/
void ModifyLineList(Linelist *L)
{
    printf("请输入要修改的航班号：");
    unsigned long long line_no;
    scanf("%llu",&line_no);
    Linelist *p = L->next;
    while(p != NULL)
    {
        if(p->line_no == line_no)
        {
            printf("成功找到该航班！\n");
            PrintLine(p);
            printf("请输入目的地：");
            p->destination[0] = '\0'; //清空字符串
            getchar(); //清空缓冲区
            fgets(p->destination, 100, stdin); 
            p->destination[strlen(p->destination) - 1] = '\0'; //去掉回车
            printf("请输入日期(输入方式：年-月-日，例如2023.04.26，输入20230426)：");
            char date1[5];
            char date2[3];
            char date3[3];
            char date0[9];
            scanf("%s",date0);
            date1[0]=date0[0];
            date1[1]=date0[1];
            date1[2]=date0[2];
            date1[3]=date0[3];
            date1[4]='\0';
            date2[0]=date0[4];
            date2[1]=date0[5];
            date2[2]='\0';
            date3[0]=date0[6];
            date3[1]=date0[7];
            date3[2]='\0';
            p->date[0]=atoi(date1);
            p->date[1]=atoi(date2);
            p->date[2]=atoi(date3);


            printf("请输入星期：");
            scanf("%d",&p->week);
            printf("请输入时间(输入方式：时：分，例如12:34，输入12：34)：");
            char time1[3];
            char time2[3];
            char time0[5];
            scanf("%s",time0);
            time1[0]=time0[0];
            time1[1]=time0[1];
            time1[2]='\0';
            time2[0]=time0[2];
            time2[1]=time0[3];
            time2[2]='\0';
            p->time[0]=atoi(time1);
            p->time[1]=atoi(time2);
            
            printf("请输入价格：");
            scanf("%f",&p->price);
            printf("请输入折扣：");
            scanf("%f",&p->discount);
            printf("请输入座位数：");
            int max_seat=p->max_seat;
            scanf("%d",&p->max_seat);
            p->remain_seat=p->remain_seat+p->max_seat-max_seat;
            char line_no_str[100]="\0" ;
            line_no_str[0]=date1[2];
            line_no_str[1]=date1[3];
            strcat(line_no_str,date2);
            strcat(line_no_str,date3);
            strcat(line_no_str,time0);
            p->line_no=atoll(line_no_str);
            WriteLineList(L,"../References/plane.csv");
            char plane_path[100]="../References/Booked/booked";
            char plane_no_str[10]="\0" ;
            char plane_path2[100]="../References/Booking/booking";
            sprintf(plane_no_str,"%d",p->plane_no);
            strcat(plane_path,plane_no_str);
            strcat(plane_path2,plane_no_str);
            strcat(plane_path2,".csv");
            strcat(plane_path,".csv");
            if(p->booked==NULL)
            {
                p->booked=InitBookedList();
                CreateBookedList(p->booked,plane_path);

            }
            if (p->booking==NULL)
            {
                p->booking=InitBookingList(p->booking);
                InputBookingList(p->booking,plane_path2);
            }
            if(LengthBookedList(p->booked)==0)
            {
                printf("修改成功，且该航班无人购买\n");
                return;
            }
            while (p->booked->next!=NULL)
            {
                char seat_no_str[5]="\0" ;
                char orderform_no_str[100]="\0" ;
                sprintf(seat_no_str,"%d",p->booked->seat_no);
                strcat(orderform_no_str,line_no_str);
                strcat(orderform_no_str,seat_no_str);
                p->booked->orderform_no=atoll(orderform_no_str);
                p->booked=p->booked->next;
            }
            UpdateBookedList(p->booked,plane_path);
            if(LengthBookingList(p->booking)==0)
            {
                printf("修改成功，且该航班无人预定\n");
                return;
            }
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
            printf("修改成功！\n");
            return;
        }
        p = p->next;
    }
    printf("未找到该航班！\n");
}



int main()
{
    Linelist *L = InitLineList();
    ReadLineList(L,"../References/plane.csv");
    PrintLineList(L);
    printf("航班数量：%d\n",LengthLineList(L));
    // L= AddLineList(L);
    PrintLineList(L);
    printf("航班数量：%d\n",LengthLineList(L));
    ModifyLineList(L);
    PrintLineList(L);
    return 0;

}




