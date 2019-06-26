//
//  main.cpp
//  学生成绩打分111
//
//  Created by s20181102931 on 2019/6/26.
//  Copyright © 2019 s20181102931. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct student
{
    string number;
    string name;
    string tel;
    double score[7];
    double sum;
    double max,min;
    double ave;
}stu[5];
bool cmp(student s1,student s2){
    return s1.ave>s2.ave;
}
int main()
{
    ifstream in("/Users/s20181102931/Desktop/wrj.txt");
    ifstream on("/Users/s20181102931/Desktop/we.txt");
    ofstream out("/Users/s20181102931/Desktop/finally score.txt");
    
    for(int t=0;t<3;t++)
    {
        in>>stu[t].number>>stu[t].name>>stu[t].tel;
        stu[t].sum=stu[t].ave=0;
        for(int i=0;i<7;i++)
        {
            on >> stu[t].score[i];
            stu[t].sum=stu[t].score[i]+stu[t].sum;
        }
        stu[t].max=stu[t].score[0];
        stu[t].min=stu[t].score[0];
        for(int j=0;j<7;j++)
        {
            if(stu[t].score[j]>stu[t].max)
                stu[t].max = stu[t].score[j];
            if(stu[t].score[j]<stu[t].min)
                stu[t].min = stu[t].score[j];
        }
        stu[t].sum = stu[t].sum- stu[t].max-stu[t].min;
        stu[t].ave = 1.0*stu[t].sum/5;
    }
    in.close();
    sort(stu,stu+3,cmp);
    for(int i=0;i<3;i++)
    {
        out<<left<<setw(3)<<stu[i].number<< " " <<left<<setw(3)<<stu[i].name<<" "<<left<<setw(3)<<stu[i].ave<<" "<<left<<setw(3)<<stu[i].tel<<endl;
    }
    out.close();
    return 0;
}


