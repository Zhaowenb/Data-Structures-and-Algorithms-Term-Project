#数据处理脚本
#处理csv文件，将数据存入数据库

import xlwings
import numpy
from faker import Faker
import pandas as pd
import csv

num = 9 #生成数据的数量
max_seat = 300  #最大座位数
min_seat = 10  #最小座位数
start_date = "-1y"  #开始日期
end_date = "+1y"  #结束日期

def output_data():  #输出数据，向csv文件中写入数据
    fake = Faker()
    #生成数据
    data = []
    for i in range(num):
        '''
    //航班信息
    //destination:目的地
    char destination[50];
    //line_no:航班号
    unsigned long line_no=date[0]*1000000+date[1]*10000+date[2]*100+time[0]*60+time[1]+plane_no;
    //plane_no:飞机号
    int plane_no=i+1;
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
    booked_i.csv 文件
    //booking:预定的订单
    booking_i.csv 文件

        '''
        #生成航班信息
        destination = fake.city()
        plane_no = i+1
        date = fake.date_between(start_date=start_date, end_date=end_date)
        datestr = str(date).split('-')
        week = date.weekday()
        time = fake.time()
        timestr = str(time).split(':')
        line_no = int(datestr[0])*10000000000+int(datestr[1])*100000000+int(datestr[2])*1000000+int(timestr[0])*10000+int(timestr[1])*100+plane_no
        price = fake.pyfloat(left_digits=3, right_digits=2, positive=True)
        discount = fake.pyfloat(left_digits=1, right_digits=2, positive=True)
        max_seat = numpy.random.randint(min_seat, max_seat)
        remain_seat = numpy.random.randint(0, max_seat)

        #生成乘客信息
        for j in range(max_seat-remain_seat):
            orderform_no = fake.pyint()
            name = fake.name()
            certificate_no = fake.ssn()
            amount = fake.random_digit_not_null()
            seat_no = j+1
            
'''
    //已经预定成功乘客信息
    //订单号，姓名，身份证号，票数，座位号
    //订单号
    long orderform_no;
    //姓名
    char name[20];
    //身份证号
    long certificate_no;
    //购买票数
    int amount;
    //座位号
    int seat_no;
''' 
            

    #写入csv文件
    with open('../References/text.csv', 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['name', 'address', 'phone_number', 'email', 'ssn', 'date_of_birth', 'credit_card_number'])
        for i in range(100):
            writer.writerow(data[i])

output_data()


