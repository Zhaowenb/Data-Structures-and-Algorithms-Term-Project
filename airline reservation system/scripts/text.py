import xlwings
import numpy
import pandas as pd
import csv
from faker import Faker
from rich.progress import track
from tqdm import tqdm  
import art
import os

start_date = "-1y"  #开始日期
end_date = "+1y"  #结束日期
Max_seat = 300  #最大座位数
min_seat = 10  #最小座位数

def data_booked(x,date):
    fake = Faker()
    #生成数据
    data = []
    art.tprint("BOOKED    DATA",font="random")
    for i in tqdm(range(x)):
        order_no = date*1000+i+1
        name = fake.name()
        certificate = fake.ssn()
        certificate_n = str(certificate).split('-')
        certificate_no = int(certificate_n[0]+certificate_n[1]+certificate_n[2])
        amout = 1
        seat_no = i+1
        data.append([order_no, name, certificate_no, amout, seat_no])
    return data

def data_booking():
    fake = Faker()
    #生成数据
    data = []
    art.tprint("BOOKING     DATA",font="random")
    x = fake.random_digit_not_null()
    for i in tqdm(range(x)):
        order_no = i+1
        name = fake.name()
        certificate = fake.ssn()
        certificate_n = str(certificate).split('-')
        certificate_no = int(certificate_n[0]+certificate_n[1]+certificate_n[2])
        amout = 1
        seat_no = i+1
        data.append([order_no, name, certificate_no, amout, seat_no])
    return data

def data_plane(x):
    fake = Faker()
    #生成数据
    data = []
    art.tprint("PLANE     DATA",font="random")

    for i in track(range(x)):
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
        max_seat = fake.random_int(min=min_seat, max=Max_seat)
        remain_seat = numpy.random.randint(0, max_seat)
        data.append([destination, plane_no, date, week, time, line_no, price, discount, max_seat, remain_seat])
        booked=data_booked(max_seat-remain_seat,plane_no)
        booking=data_booking()
        path = "../References/Booked"+ str(plane_no)
        os.mkdir(path)
        with open(path+"/booked"+str(plane_no)+".csv", 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerows(booked)
        path = "../References/Booking"+ str(plane_no)
        os.mkdir(path)
        with open(path+"/booking"+str(plane_no)+".csv", 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerows(booking)
    return data



os.mkdir("../References")
art.tprint("Data   Creation",font="random")
plane =data_plane(10)
art.tprint("Data   Creation   Completed")
#写入csv文件
with open('../References/plane.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerows(plane)

