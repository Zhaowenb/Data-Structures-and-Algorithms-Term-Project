/*
    *booking.h -- 预约登记可会链式队列
    *作者：赵文渤
    *学校：东北林业大学
    *日期：2023年9月30日
    *联系方式：2976588531@qq.com
    *开源协议：GPL 3.0
    *开源地址：https://github.com/Zhaowenb/Data-Structures-and-Algorithms-Term-Project.git
    *本程序是自由软件，可以重新分配和修改它。
    *记得来我github的项目主页看看有没有更新版本。并且献上你的star！！！！！
    *谢谢
*/

#ifndef _BOOKING_H_
#define _BOOKING_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//预约登记可会链式队列表
typedef struct Booking
{
    //name, certificate_no, line_no, date, time, amount分别指向用户姓名，身份证号，航班号，出发日期，出发时间，预定票数
    //name指向用户姓名
    char name[100];
    //certificate_no指向用户身份证号
    unsigned long certificate_no;
    //line_no指向航班号
    unsigned long long line_no;
    //date指向出发日期
    int date[3];
    //time指向出发时间
    int time[2];
    //amount指向预定票数
    int amount;
    //指向下一个节点的指针
    struct Booking *next;

}Booking;
typedef struct BookingList
{
    //booking_head指向队列头，booking_tail指向队列尾
    Booking *booking_head;
    Booking *booking_tail;
}BookingList;

/*
    *初始化booking队列
    *函数名：InitBookingList
    *参数：BookingList *L
    *返回值：BookingList *L
*/
BookingList* InitBookingList(BookingList *L);

/*
判断Booking队列是否为空
函数名：IsEmptyBookingList
参数：BookingList *L
返回值：1为空，0为非空
*/
int IsEmptyBookingList(BookingList *L);

/*
Booking销毁
函数名：DestroyBookingList
参数：BookingList *L
返回值：无
*/
void DestroyBookingList(BookingList *L);

/*
Booking入队
函数名：EnBookingList
参数：BookingList *L,Booking *e
返回值：无
*/
void EnBookingList(BookingList *L,Booking *e);

/*
Booking出队
函数名：DeBookingList
参数：BookingList *L,Booking *e
返回值：无
*/
void DeBookingList(BookingList *L,Booking *e);

/*
Booking队列长度
函数名：LengthBookingList
参数：BookingList *L
返回值：Booking队列长度
*/
int LengthBookingList(BookingList *L);

/*
打印函数
函数名：PrintBooking
参数：Booking *e
返回值：无
*/
void PrintBooking(Booking *e);

/*
Booking队列遍历，对每个元素调用visit回调函数，
函数名：TraverseBookingList
参数：BookingList *L,void (*visit)(Booking)
返回值：无
*/
void TraverseBookingList(BookingList *L,void (*visit)(Booking *b));

/*
Booking队列查找
函数名：LocateBookingList
参数：BookingList *L,int i,Booking *e
返回值：无
*/
void LocateBookingList(BookingList *L,int i,Booking *e);

/*
Booking取头元素
函数名：GetHeadBookingList
参数：BookingList *L,Booking *e
返回值：成功返回1，失败返回0
*/
int GetHeadBookingList(BookingList *L,Booking *e);

/*
Booking读取csv文件初始化
函数名：InputBookingList
参数：BookingList *L，char *filename
返回值：无
*/
void InputBookingList(BookingList *L,char *filename);

/*
Booking更新csv文件
函数名：DataupBookingList
参数：BookingList *L， char *filename
返回值：无
*/
void DataupBookingList(BookingList *L,char *filename);

#endif