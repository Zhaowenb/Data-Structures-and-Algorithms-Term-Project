<!DOCTYPE html>
<html>
<head>
    <style>
        .centered-text {
            text-align: center;
        }
    </style>
</head>
<body>
    <!-- <h1 style="text-align: end;">东北林业大学</h1 -->
    <h1 class="centered-text">数据结构 PBL</h1>
    <h3 class="centered-text">技术文档和设计说明</h3>
    <h6 style="text-align: right;">代码:赵文渤 <br>PPT:袁龙坤 <br>文档:吴柏强<br>视频:赵文渤</h6>
</body>

<div STYLE="page-break-after: always;"></div>



---

## ***航空订票系统*** 技术文档
### 目录
- [***航空订票系统*** 技术文档](#航空订票系统-技术文档)
  - [目录](#目录)
  - [设计任务和要求](#设计任务和要求)
  - [设计环境](#设计环境)
  - [总体设计](#总体设计)
  - [文件结构](#文件结构)
  - [源代码](#源代码)


<div STYLE="page-break-after: always;"></div>

---

### 设计任务和要求

    题目1：航空订票系统（单链表和队列的应用）
    【问题描述】
    航空客运订票的业务活动包括：查询航线、客票预订和承办退票等。
    【基本要求】构建的航空订票系统应具有如下功能：
    (1)数据录入 
    (2)查询航线 
    (3)客票预订 
    (4)承办退票 
    (5)修改航班信息
* 1.航班数据录入和维护： 
  

    每条航线所涉及的信息有：终点站名、航班号、飞机号、飞行周日(星期几飞行)、起飞时间、航班票价、票价折扣、乘员定额、余票量、已订票的乘客名单以及等候替补的客户名单。
* 2.查询航线：
    根据旅客提出的终点站名，输出下列信息：航班号、飞机号、星期几飞行、起飞时间、最近一天航班的日期，航班票价、票价折扣，确定航班是否满仓、余票额。
* 3.客票预订： 
    根据客户提出的要求：终点站、航班号、飞机号、日期，查询该航班票额情况，若尚有余票，则为客户办理订票手续，输出订单编号和座位号；若已满员或余票少于订票额，则可以提供相关可选择航班，并需重新询问客户要求。若客户需要，可预约登记排队等候。
* 4.承办退票：
    根据客户提供的订单编号和姓名，核实客户资料：订单编号、姓名、证件号、订票额，若无误则办理退票手续；
    然后查询该航班是否有人预约登记，首先询问队列中第一位客户，若所退票额能满足他的要求，则为他办理订票手续，否则依次询问其它排队预约的客户

<div STYLE="page-break-after: always;"></div>


---


### 设计环境
    Ubuntu22.04
    Python==3.10.8
    Cmake==3.27.4

### 总体设计

1. #### 数据结构： ####

> 本系统的数据格式为：单列表和队列 
2. #### 程序组织： ####
> 程序由主程序文件和函数程序文件等组成
3. #### 主程序文件： ####
>    main.c
4. #### 函数文件： ####
>booked.c
>booking.c
>Line.c
5. #### 所需要的头文件：
>booked.h
>booking.h
>Line.h
>main.h


---

### 文件结构

- [airline reservation system（航空订票系统）](../airline_reservation_system)
    - [build(可执行文件)](./build)
        - [main(可执行文件)](./build/main)
        - [Makefile(编译文件)](./build/Makefile)
    - [include(库文件)](./include)
        - [booked.h(已订票客户处理库)](./include/booked.h)
        - [booking.h(预约登记的客户处理库)](./include/booking.h)
        - [Line.h(航线名单处理库)](./include/Line.h)
        - [main.h(主程序函数库)](./include/main.h)
    - [src(源码)](./src)
        - [booked.c(已订票客户处理函数)](./src/booked.c)
        - [booking.c(预约登记的客户处理函数)](./src/booking.c)
        - [Line.c(航线名单处理函数)](./src/Line.c)
        - [main.c(主程序)](./src/main.c)
    - [scripts(数据处理python脚本)](./scripts) 
        - [text.py(生成数据的脚本)](./scripts/text.py)
    - [References(航空订票系统初始化数据)](./References)  
        - [plane.csv(航班信息数据)](./References/plane.csv)
        - [Booked(已成功购票的客户信息)](./References/Booked/)
        - [Booking(预定的客户信息)](./References/Booking/)    
    - [CMakeLists.txt(CMAKE编译文件)](./CMakeLists.txt)
    - [readme.md(航空订票系统技术文档)](./readme.md)

<div STYLE="page-break-after: always;"></div>


---

### 源代码

