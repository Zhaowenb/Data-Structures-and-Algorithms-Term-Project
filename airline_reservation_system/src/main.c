#include "../include/main.h"

#define file_path "../References/Line.csv"

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

