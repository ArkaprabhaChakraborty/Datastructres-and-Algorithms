import files as f
import pandas as pd
import os
import numpy as np

c = 1
#making a directory ... flexing purposes only
try:
    os.mkdir("data")
    fle = open("D:/DataStructres/data/student.txt","w+")
    fle.write("Roll-number Name Address Phone-number HS-marks Department\n")
    fle.close()
except:
    pass
def create():
    r = pd.read_csv("data/student.txt",sep = " ",header = 0)
    n = input("Enter number of students")
    n = int(n)
    roll = []
    name = []
    address = []
    phno = []
    marks = []
    dept = []
    for i in range(n):
        roll.append(input("Roll number:"))
        name.append(input("Name :"))
        address.append(input("Address :"))
        phno.append(input("Phone number :"))
        marks.append(input("HS marks :"))
        dept.append(input("Department :"))
    r['Roll-number'] = roll
    r['Name'] = name
    r['Address'] = address
    r['Phone-number'] = phno
    r['HS-marks'] = marks
    r['Department'] = dept
    print("\n------New Data------\n")
    print(r)
    r.to_csv('data/student.txt', header=0, index=None, sep=' ', mode='a')

def update_by_rollnumber(n):
    df = pd.read_csv("data/student.txt",sep = " ",header=0)
    header = list(df.columns)
    row = df.index[df["Roll-number"]==n]
    print("Enter type of data to be changed")
    s = input()
    print("Enter new value")
    new = input()
    df.at[row,s] = new
    df.to_csv("data/student.txt",header=header,sep=' ',index=None)


def delete(n):
    df = pd.read_csv("data/student.txt",sep = " ",header=0)
    header = list(df.columns)
    df = df[df["Roll-number"]!=n]
    df.to_csv("data/student.txt",header=header,sep=' ',index=None)

def count_dep(dep):
    df = pd.read_csv("data/student.txt",sep = " ",header=0)
    row = df.index[df["Department"]==dep]
    print("No of students in "+ dep + " department is " + str(len(row)))

def max_dep_marks(dep):
    df = pd.read_csv("data/student.txt",sep = " ",header=0)
    row = df.index[df["Department"]==dep]
    mini = df.iloc[row]
    mini = mini.sort_values(by="HS-marks",ascending = False)
    max = mini.iloc[0]
    print("Max marks in "+dep+" Department is " + str(max["HS-marks"]) + " Scored by "+ max["Name"])

def search_by_name(name):
    df = pd.read_csv("data/student.txt",sep = " ",header=0)
    mini = df[df["Name"]==name]
    print(mini)

def search_by_rollnumber(n):
    df = pd.read_csv("data/student.txt",sep = " ",header=0)
    mini = df[df["Roll-number"]==n]
    print(mini)

#update_by_rollnumber(321358)
#count_dep("CSE")
#max_dep_marks("CSE")

while(c==1):
 print("1. To create Student.txt with your data\n2. To Update by roll number\n3. to delete by roll number\n4. Count no of students in a department \n5. To get the Max marks in a department\n6. Search by name\n7. Search by Roll number\n8. To Display\n")
 x = input("Enter choice : ")
 x = int(x)
 if x==1:
    create()
 elif x==2:
     r = input("Enter roll number : ")
     r = int(r)
     update_by_rollnumber(r)
 elif x==3:
     r = input("Enter roll number : ")
     r = int(r)
     delete(r)
 elif x==4:
     r = input("Enter Department : ")
     count_dep(r)
 elif x==5:
     r = input("Enter Department : ")
     max_dep_marks(r)
 elif x==6:
     r = input("Enter Name: ")
     search_by_name(r)
 elif x==7:
     r = input("Enter Roll Number: ")
     search_by_rollnumber(int(r))
 elif x==8:
     df = pd.read_csv("data/student.txt",headers = 0,sep = " ")
     print(df)
 else:
     c=0


