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

//测试代码
// int main()
// {
//     Linelist *L = InitLineList();
//     ReadLineList(L,"../References/plane.csv");
//     PrintLineList(L);
//     printf("航班数量：%d\n",LengthLineList(L));
//     SortLineList(L);
//     PrintLineList(L);
    
//    while(L->next != NULL)
//     {
//         // DeleteLineList(L,L->next->line_no);
//         PrintBookedList(L->next->booked);
//         // PrintBookingList(L->next->booking);
//         L = L->next;


//     }
//     // WriteLineList(L,"../References/plane1.csv");
    
//     return 0;

// }




