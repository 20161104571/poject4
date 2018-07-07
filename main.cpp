//
//  main.cpp
//  poject4
//
//  Created by 20161104571 on 18/7/7.
//  Copyright © 2018年 20161104571. All rights reserved.
//


#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct student
{
    char name[10];  //姓名
    char sex;       //性别
    char clas;      //班级
    char pro;       //节目名称
    char type;      //节目类型
    char tel;       //电话
    char ach;       //成绩
}student;


void add()
{
    int i,j,m=0;
    double max=0,min=100;
    double sf;
    int f[10];
    cout<<"输入要添加的选手人数：";
    cin>>i;
    for(j=0;j<i;j++)
    {
        ofstream outfile("C:\\Users\\Apple\\Desktop\\01.csv",ios::app);  //写入文件
        cout<<"选手姓名：";
        cin>>student.name;
        outfile<<student.name<<",";
        
        cout<<"选手性别：";
        cin>>student.sex;
        outfile<<student.sex<<",";
        
        cout<<"选手班级：";
        cin>>student.clas;
        outfile<<student.clas<<",";
        
        cout<<"选手节目名称：";
        cin>>student.pro;
        outfile<<student.pro<<",";
        
        cout<<"选手节目类型：";
        cin>>student.type;
        outfile<<student.type<<",";
        
        cout<<"选手电话：";
        cin>>student.ach;
        outfile<<student.ach<<",";
        
        cout<<"是否对选手进行打分「是（1）否（0）」"<<endl;
        cin>>m;
        if(m==1)
        {
            for(j=1;j<=5;j++)//评分
            {
                max=0;
                min=100;
                sf=0;
                cout<<"评委 "<<j<<" 给分:";
                cin>>f[j];
                sf=sf+f[j];
                if(max<f[j])
                {
                    max=f[j];
                }
                if(min>f[j])
                {
                    min=f[j];
                }
            }
            cout<<"去一个max:"<<max<<endl;
            cout<<"去一个min:"<<min<<endl;
            sf=(sf-max-min)/3;
            cout<<"选手最终得分:"<<sf<<endl;
            outfile<<sf<<endl;
        }
        else
        {
            outfile<<endl;
        }
    }
}

void Score()//评委打分
{
    int j,max=0,min=100,m;
    double sf;
    int f[10];
    ifstream fin("C:\\Users\\Apple\\Desktop\\01.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        max=0;
        min=100;
        sf=0;
        cout <<"姓名,性别,班级,节目名称,节目类型,电话："<< endl << line << endl; //整行输出
        
        for(j=1;j<=5;j++)//评分
        {
            cout<<"评委 "<<j<<" 给分:";
            cin>>f[j];
            sf=sf+f[j];
            if(max<f[j])
            {
                max=f[j];
            }
            if(min>f[j])
            {
                min=f[j];
            }
        }
        cout<<"去一个max:"<<max<<endl;
        cout<<"去一个min:"<<min<<endl;
        sf=(sf-max-min)/3;
        cout<<"选手最终得分:"<<sf<<endl;
        
        ofstream outfile("C:\\Users\\Apple\\Desktop\\02.csv",ios::app);  //写入文件
        outfile<<line<<","<<sf<<endl;
        
        cout<<"是否继续「是（1）否（0）」"<<endl;//中途结束评分
        cin>>m;
        if(m==0)
        {
            break;
        }
    }
    cout<<"完成"<<endl;
}

void Show()//选手信息
{
    int i=0;
    ifstream fin("C:\\Users\\Apple\\Desktop\\01.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        i++;
        cout<<"第 "<< i <<" 位选手:"<<endl;
        cout <<"姓名,性别,班级,节目名称,节目类型,电话："<< endl << line << endl;
    }
}

void Teacher()//评委信息
{
    int i=0;
    ifstream fin("C:\\Users\\Apple\\Desktop\\03.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        i++;
        cout <<"         姓名,性别,电话："<< endl << line << endl;
    }
    
}


int main()
{
    
    int i;
    while(1)
    {
        cout<<"      | ---------------------------------- |\n";
        cout<<"      | ********欢迎来比赛打分系统!********|\n";
        cout<<"      | ---------------------------------- |\n";
        cout<<"      |         1.添加选手信息             |\n";
        cout<<"      |         2.显示表演名单             |\n";
        cout<<"      |         3.显示评委名单             |\n";
        cout<<"      |         4.评委进行评分             |\n";
        cout<<"      |         5.修改所有信息             |\n";
        cout<<"      |         6.退出打分系统             |\n";
        cout<<"      | ---------------------------------- |\n";
        cout<<"\n 请选择功能：";
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                add();
                break;
            case 2:
                Show();
                break;
            case 3:
                Teacher();
                break;
            case 4:
                Score();
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}
