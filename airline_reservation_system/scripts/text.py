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

def data_booked(seat,date):
    fake = Faker()
    #生成数据
    data = []
    art.tprint("BOOKED    DATA",font="random")
    for i in tqdm(range(seat)):
        order_no = str(date)+str(i+1)
        name = fake.name()
        certificate = fake.ssn()
        certificate_n = str(certificate).split('-')
        certificate_no = certificate_n[0]+certificate_n[1]+certificate_n[2]
        amout = 1
        seat_no = i+1
        data.append([order_no, name, certificate_no, amout, seat_no])
    return data

def data_booking(line_no,datestr,timestr):
    fake = Faker()
    #生成数据
    data = []
    art.tprint("BOOKING     DATA",font="random")
    x = fake.random_digit_not_null()
    for i in tqdm(range(x)):
        name = fake.name()
        certificate = fake.ssn()
        certificate_n = str(certificate).split('-')
        certificate_no = int(certificate_n[0]+certificate_n[1]+certificate_n[2])
        amout = 1       
        data.append([ name, certificate_no,line_no, datestr, timestr, amout])
    return data

def data_plane(x):
    fake = Faker()
    #生成数据
    data = []
    art.tprint("PLANE     DATA",font="random")
    path_booked = "../References/Booked"
    os.mkdir(path_booked)
    path_booking = "../References/Booking"
    os.mkdir(path_booking)
    for i in track(range(x)):
        destination = fake.city()
        plane_no = i+1
        date = fake.date_between(start_date=start_date, end_date=end_date) 
        datestr = str(date).split('-')
        date_str = datestr[0]+"-"+datestr[1]+"-"+datestr[2]
        week = fake.random_int(min=1, max=7)
        time = fake.time()
        timestr = str(time).split(':')
        time_str = timestr[0]+":"+timestr[1]
        if plane_no<10:
            plane_no_str = "00"+str(plane_no)
        elif plane_no<100 and plane_no>9:
            plane_no_str = "0"+str(plane_no)
        else:
            plane_no_str = str(plane_no)
        line_no = datestr[0][2]+datestr[0][3]+datestr[1]+datestr[2]+timestr[0]+timestr[1]+plane_no_str
        price = fake.pyfloat(left_digits=3, right_digits=2, positive=True)
        discount = fake.pyfloat(left_digits=1, right_digits=2, positive=True)
        max_seat = fake.random_int(min=min_seat, max=Max_seat)
        remain_seat = numpy.random.randint(0, max_seat)
        booked=data_booked((max_seat-remain_seat),line_no)
        booking=data_booking(line_no,date_str,time_str)
        with open(path_booked+"/booked"+str(plane_no)+".csv", 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerows(booked)
        
        with open(path_booking+"/booking"+str(plane_no)+".csv", 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerows(booking)
        data.append([destination, plane_no, date, week, time_str, line_no, price, discount, max_seat, remain_seat,path_booked+"/booked"+str(plane_no)+".csv",path_booking+"/booking"+str(plane_no)+".csv"])
        
    return data



os.mkdir("../References")
art.tprint("Data   Creation",font="random")
plane =data_plane(100)
art.tprint("Data   Creation   Completed")
#写入csv文件
with open('../References/plane.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerows(plane)

