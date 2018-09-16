//.h
 #include <QDebug>

typedef quint32 word;
typedef quint8 type;

#define HHI(x) ((type)((word)(x)>>24)&255)
#define LHI(x) ((type)(((word)(x)>>16)&255))
#define HLO(x) ((type)(((word)(x)>>8)&255))
#define LLO(x) ((type)((word)(x)&255))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

int main()
{
    quint32 i=0x12345678;
    QList <quint8> Values;
    Values<<HHI(i)<<LHI(i)<<HLO(i)<<LLO(i);
    qDebug("原始值0x%x==%d",i,i);
    qDebug("0x%x==%d    0x%x==%d    0x%x==%d    0x%x==%d",
           Values.at(0),Values.at(0),Values.at(1),Values.at(1),Values.at(2),
           Values.at(2),Values.at(3),Values.at(3));
    qDebug("最高8位和次高8位最大值：0x%x<%d>",MAX(Values.at(0),Values.at(1)),MAX(Values.at(0),Values.at(1)));
    qDebug("次低8位和最低8位最大值：0x%x<%d>",MIN(Values.at(2),Values.at(3)),MIN(Values.at(2),Values.at(3)));
int i_new =(HLO(i)<<24)+(HHI(i)<<16)+(LLO(i)<<8)+LHI(i);
qDebug("重新组合后的数值：0x%x==%d",i_new,i_new);
qDebug("排序前：<%d,%d,%d,%d>",Values.at(0),Values.at(1),Values.at(2),Values.at(3));
std::sort(Values.begin(),Values.end(),std::greater<int>());
qDebug("排序后：<%d,%d,%d,%d>",Values.at(0),Values.at(1),Values.at(2),Values.at(3));
    return 0;
}
