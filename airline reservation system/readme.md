# ***航空订票系统*** 技术文档
## 目录
- [编译运行](#编译运行)
- [文件结构](#文件结构)
- [题目要求](#题目要求)


### 编译运行
#### ***注意*** ：
    本技术文档只提供Ubuntu20.04编译方法。





### 文件结构
- [airline reservation system（航空订票系统）](../airline%20reservation%20system)
    - [build(可执行文件)](./build)
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
    - [References(航空订票系统初始化数据)](./References)      
    - [CMakeLists.txt(CMAKE编译文件)](./CMakeLists.txt)
    - [readme.md(航空订票系统技术文档)](./readme.md)
### 题目要求：
    题目：航空订票系统（单链表和队列的应用）
    【问题描述】航空客运订票的业务活动包括：查询航线、客票预订和承办退票等。
    【基本要求】构建的航空订票系统应具有如下功能：
    (1)数据录入
    (2)查询航线
    (3)客票预订
    (4)承办退票
    (5)修改航班信息
