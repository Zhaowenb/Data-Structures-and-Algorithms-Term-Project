#ifndef _MAIN_H_
#define _MAIN_H_

#include "Line.h"
#include "booked.h"
#include "booking.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
// #include <ncurses.h>
// #include <string.h>
// #include <conio.h>
#define file_path "../References/plane.csv"

/*
    初始化全部链表和队列,并导入csv文件
    函数名：InitAll
    参数：无
    返回值：Linelist *L
*/
Linelist *InitAll();


void case2(Linelist *L);

//客票退票
void case3(Linelist *L);

int password();

void case4(Linelist *L);



#endif // _MAIN_H_
