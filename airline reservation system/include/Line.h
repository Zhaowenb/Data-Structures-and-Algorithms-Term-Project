#ifndef _LINE_H_
#define _LINE_H_

#include "booking.h"
#include"booked.h"

typedef struct Linelist
{
    //航班信息
    //destination:目的地
    char destination[50];
    //line_no:航班号
    unsigned long line_no;
    //plane_no:飞机号
    int plane_no;
    //date:日期
    int date[3];
    //week:星期
    int week;
    //time:时间
    int time[2];
    //price:价格
    float price;
    //discount:折扣
    float discount;
    //max_seat:座位数
    int max_seat;
    //remain_seat:剩余座位数
    int remain_seat;
    //booked:已购买的订单
    Booked *booked;
    //booking:预定的订单
    BookingList *booking;
    //next:指向下一个航班的指针
    struct Linelist *next;
}Linelist;

/*
初始化航班链表
函数名：InitLineList
参数：无
返回值：空单链表
*/
Linelist *InitLineList();

/*
    判断航班链表是否为空
    函数名：isEmptyLineList
    参数：Linelist *L
    返回值：1为空，0为非空
*/
int isEmptyLineList(Linelist *L);

/*
    在航班链表打印所有航班信息
    函数名：PrintLineList
    参数：Linelist *L
    返回值：无
*/
void PrintLineList(Linelist *L);

/*
    打印航班
    函数名：PrintLine
    参数：Linelist *p
    返回值：无
*/
void PrintLine(Linelist *p);

/*
    在航班链表中插入航班
    函数名：InsertLineList
    参数：Linelist *L,Linelist *e
    返回值：无
*/
void InsertLineList(Linelist *L,Linelist *e);

/*
    航班数量
    函数名：LengthLineList
    参数：Linelist *L
    返回值：航班数量
*/
int LengthLineList(Linelist *L);

/*
    航班链表排序
    函数名：SortLineList
    参数：Linelist *L
    返回值：无
    注：按照航班号从小到大排序
*/
void SortLineList(Linelist *L);

/*
    查询航班
    函数名：SearchLineList
    参数：Linelist *L,char *destination,int *date,int *time
    返回值：Linelist *p
*/
Linelist *SearchLineList(Linelist *L,char *destination,int *date,int *time);

/*
    删除航班
    函数名：DeleteLineList
    参数：Linelist *L,unsigned long line_no
    返回值：无
*/
void DeleteLineList(Linelist *L,unsigned long line_no);

/*
    销毁航班链表
    函数名：DestroyLineList
    参数：Linelist *L
    返回值：无
*/
void DestroyLineList(Linelist *L);

/*
    从文件中读取航班信息
    函数名：ReadLineList
    参数：Linelist *L char *filename
    返回值：无
*/
void ReadLineList(Linelist *L,char *filename);

/*
    将航班信息写入文件
    函数名：WriteLineList
    参数：Linelist *L char *filename
    返回值：无
*/
void WriteLineList(Linelist *L,char *filename);




#endif// _LINE_H_