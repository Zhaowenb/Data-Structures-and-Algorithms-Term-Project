import xlwings
import numpy
import pandas as pd
import csv
from faker import Faker

max_seat = 300  #最大座位数
min_seat = 10  #最小座位数

def data_booked(x,date):
    fake = Faker()
    #生成数据
    data = []
    for i in range(x):
        order_no = date*1000+i+1
        name = fake.name()
        certificate_no = fake.ssn()
        amout = 1
        seat_no = i+1
        data.append([order_no, name, certificate_no, amout, seat_no])
    return data

def data_booking():
    fake = Faker()
    #生成数据
    data = []
    x = fake.random_digit_not_null()
    for i in range(x):
        order_no = date*1000+i+1
        name = fake.name()
        certificate_no = fake.ssn()
        amout = 1
        seat_no = i+1
        data.append([order_no, name, certificate_no, amout, seat_no])
    return data
