#include <QCoreApplication>
#include <QDebug>
#include <QList>
using namespace std;//定义std结构体

struct students
{
    QString name;
    int num;
    int Num1;
    int Num2;
};//构造一个函数

void Students(QList<students> &stud,int num,QString name, int num1, int num2)
{
    students stu;
    stu.num=num;
    stu.name=name;
    stu.Num1=num1;
    stu.Num2=num2;
    stud.push_back(stu);
}
bool sort1(const students &st1,const students &st2)
{
    return st1.name > st2.name;
}
bool sort2(const students &st1,const students &st2)
{
    return st1.Num1 > st2.Num1;
}
bool sort3(const students &st1,const students &st2)
{
    return st1.Num2 > st2.Num2;
}
int main()
{
    QList<students> stud;
    Students(stud,1403130209,"鲁智深",80,72);
    Students(stud,1403140101,"林冲",82,76);
    Students(stud,1403140102,"宋江",76,85);
    Students(stud,1403140103,"武松",88,80);
    //原成绩的输出以及排名
     qDebug()<< "排序前:" << endl;
    for(int i=0;i<4;i++)
    {
        qDebug()<<stud.at(i).num<<" "<< stud.at(i).name<<" "<< stud.at(i).Num1<< " "<< stud.at(i).Num2 << endl;
    }
     qDebug()<< "按姓名排序:" << endl;
        std::sort(stud.begin(),stud.end(),sort1);
        for(int i=0;i<4;i++)
        {
            qDebug()<<stud.at(i).num<<" "<< stud.at(i).name<<" "<< stud.at(i).Num1<< " "<< stud.at(i).Num2 << endl;
        }
         qDebug()<<"按课程1排序:"<< endl;
            std::sort(stud.begin(),stud.end(),sort2);
            for(int i=0;i<4;i++)
            {
                qDebug()<<stud.at(i).num<<" "<< stud.at(i).name<<" "<< stud.at(i).Num1<< " "<< stud.at(i).Num2 << endl;
            }
             qDebug()<<"按课程2排序:"<< endl;
                std::sort(stud.begin(),stud.end(),sort3);
                for(int i=0;i<4;i++)
                {
                    qDebug()<<stud.at(i).num<<" "<< stud.at(i).name<<" "<< stud.at(i).Num1<< " "<< stud.at(i).Num2 << endl;
                }
}
