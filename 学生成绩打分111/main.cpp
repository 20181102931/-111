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
#define m 4
using namespace std;
struct student
{
    string number;
    string name;
    string tel;
    string judge_name;
    double score[7];
    double sum;
    double max,min;
    double ave;
}stu[m];
bool cmp(student s1,student s2){
    return s1.ave>s2.ave;
}
int main()
{
    ifstream in("/Users/s20181102931/Desktop/学生成绩打分2931/information.txt");
    ifstream on("/Users/s20181102931/Desktop/学生成绩打分2931/score.txt");
    ofstream out("/Users/s20181102931/Desktop/学生成绩打分2931/finally/score.txt");
    
    for(int t=0;t<m;t++)
    {
        in>>stu[t].number>>stu[t].name>>stu[t].tel;
        stu[t].sum=stu[t].ave=0;
        for(int i=0;i<7;i++)
        {
            on >> stu[t].judge_name>>stu[t].score[i];
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
    sort(stu,stu+m,cmp);
    for(int i=0;i<m;i++)
    {
      
        out<<left<<"number : "<<setw(4)<<stu[i].number<<endl
    <<left<<setw(4)<<"name : "<<stu[i].name<<endl<<left<<setw(4)<<"telephone : "<<stu[i].tel<<endl<<left<<setw(4)<<"ave : "<<stu[i].ave<<endl;
    }
    out.close();
    return 0;
}


