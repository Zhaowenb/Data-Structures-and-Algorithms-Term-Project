/*
    *booked.h --已预订客户信息链表
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

#ifndef _BOOKED_H_
#define _BOOKED_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Booked结构体，用于存储用户已经预定的航班信息，使用链表存储
typedef struct Booked
{
    //订单号，姓名，身份证号，票数，座位号
    //订单号
    unsigned long long orderform_no;
    //姓名
    char name[100];
    //身份证号
    unsigned long certificate_no;
    //购买票数
    int amount;
    //座位号
    int seat_no;
    //指向下一个节点的指针
    struct Booked *next; 

}Booked;

/*
初始化booked链表
函数名：InitBookedList
参数：无
返回值：空单链表
*/
Booked *InitBookedList();

/*
判断booked链表是否为空
函数名：isEmptyBookedList
参数：Booked *L
返回值：1为空，0为非空
*/
int isEmptyBookedList(Booked *L);

/*
在booked链表打印所有订单信息
函数名：PrintBookedList
参数：Booked *L
返回值：无
*/
void PrintBookedList(Booked *L);

/*
打印booked
函数名：PrintBooked
参数：Booked *b
返回值：无
*/
void PrintBooked(Booked *b);

/*
booked链表长度
函数名：LengthBookedList
参数：Booked *L
返回值：链表长度
*/
int LengthBookedList(Booked *L);

/*
在booked链表中按值查找
函数名：GetBooked
参数：Booked *L, double orderform_no
返回值：元素所在位置，若不存在则返回0
*/
int GetBooked(Booked *L, unsigned long long orderform_no);

/*
在booked链表中按位查找
函数名：getBookedByIndex
参数：Booked *L, int index
返回值：Booked指针
*/
Booked *getBookedByIndex(Booked *L, int index);

/*
在booked链表中插入元素
函数名：InsertBookedList
参数：Bo0ked *L, int index, Booked *b
返回值：成功返回1，失败返回0
*/
int InsertBookedList(Booked *L, int index, Booked *b);

/*
创建booked链表
函数名：CreateBookedList
参数：Booked *B，csv文件地址
返回值：无
*/
void CreateBookedList(Booked *B, char *filename);

/*
更新csv文件
函数名：UpdateBookedList
参数：Booked *L, char *filename
返回值：无
*/
void UpdateBookedList(Booked *L, char *filename);

/*
在booked链表中删除元素
函数名：DeleteBookedList
参数：Booked *L, int index
返回值：成功返回1，失败返回0
*/
int DeleteBookedList(Booked *L, int index);

/*
销毁booked链表
函数名：DestroyBookedList
参数：Booked *L
返回值：无
*/
void DestroyBookedList(Booked *L);



#endif