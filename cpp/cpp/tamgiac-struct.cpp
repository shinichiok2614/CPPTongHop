//bt vi du, k dung dau
#include <iostream>
#include <math.h>
using namespace std;
struct toado
{
    int a, b;
};
float AB, BC, AC;
float khoangcach(int a1, int b1, int a2, int b2){
    return sqrt(pow(a1-a2,2)+pow(b1-b2,2));
}
bool deu=0;
bool vuong=0;
bool canA=0;
bool canB=0;
bool canC=0;
int main()
{
    toado diemA, diemB, diemC;
    cout<<"Nhap A:"<<endl;
    cin>>diemA.a;
    cin>>diemA.b;
    cout<<"Nhap B:"<<endl;
    cin>>diemB.a;
    cin>>diemB.b;
    cout<<"Nhap C:"<<endl;
    cin>>diemC.a;
    cin>>diemC.b;
    AB=khoangcach(diemA.a,diemA.b, diemB.a,diemB.b);
    AC=khoangcach(diemA.a,diemA.b, diemC.a,diemC.b);
    BC=khoangcach(diemB.a,diemB.b, diemC.a,diemC.b);
    cout<<"AB"<<AB<<endl;
    cout<<"AC"<<AC<<endl;
    cout<<"BC"<<BC<<endl;
    if ((((AB+BC)>AC)&&((AB+AC)>BC)&&((BC+AC)>AB)) && AB>0 && AC>0 && BC>0)
    {
        if (AB==AC)
        {
            if (AB=BC){
                deu=1;
            }
            else{
                canA=1;
            }
        }
        else if (AB==BC)
        {
                canB=1;
        }
        else if (AC==BC)
        {
                canC=1;
        }
        //kiem tra tam giac vuong
        //kiem tra tam giac vuong can
        
    }
    else
    {
        cout<<"ABC khong la tam giac";
    }
    return 0;

}
