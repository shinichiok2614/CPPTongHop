#include <iostream>
#include <math.h>
#include "Point.h"
using namespace std;
class Triangular{
    private:
    float AB;
    float AC;
    float BC;
    public:
    Triangular(float, float, float);
    void set(Point , Point , Point );
    float getAB();
    float getBC();
    float getAC();
    float tinhcanh(Point , Point );
    bool canA();
    bool canB();
    bool canC();
    bool vuongA();
    bool vuongB();
    bool vuongC();
    bool deu();
};
Triangular::Triangular(float a, float b, float c){
    this->AB=a;
    this->AC=b;
    this->BC=c;
}
float Triangular::tinhcanh(Point a, Point b){
    float c=sqrt(pow((a.getX()-b.getX()),2)+pow((a.getY()-b.getY()),2));
    return round(c*100)/100;
}
void Triangular::set(Point a, Point b, Point c){
    this->AB=tinhcanh(a, b);
    this->AC=tinhcanh(a, c);
    this->BC=tinhcanh(b, c);
}
float Triangular::getAB(){
    return this->AB;
}
float Triangular::getBC(){
    return this->BC;
}
float Triangular::getAC(){
    return this->AC;
}
//bool Triangular::canA(){
//    return (this->AB==this->AC);
//}
bool Triangular::canA(){
    bool c;
    if(this->AB-this->AC) c=1;
    else c=0;
    return c;
}
bool Triangular::canB(){
    bool c;
    if(this->AB-this->BC) c=1;
    else c=0;
    return c;
}
bool Triangular::canC(){
    bool c;
    if(this->AC-this->BC) c=1;
    else c=0;
    return c;
}
bool Triangular::vuongA(){
    float a=pow(this->AB,2)+pow(this->AC,2);
    float b=pow(this->BC,2);
    return a==b;
}
bool Triangular::vuongB(){
    float a=pow(this->AB,2)+pow(this->BC,2);
    float b=pow(this->AC,2);
    return a==b;
}
bool Triangular::vuongC(){
    float a=pow(this->AC,2)+pow(this->BC,2);
    float b=pow(this->AB,2);
    return a==b;
}
bool Triangular::deu(){
    return (this->AB==this->AC && this->AB==this->BC);
}

int main(){
    Triangular t(0,0,0);
    Point A(0,0);
    Point B(0,0);
    Point C(0,0);
    float a,b;

    cout<<"nhap diem A: ";
    cin>>a>>b; cout<<endl;
    A.set(a,b);
    cout<<"nhap diem B: ";
    cin>>a>>b; cout<<endl;
    B.set(a,b);
    cout<<"nhap diem C: ";
    cin>>a>>b; cout<<endl;
    C.set(a,b);
    t.set(A, B, C);
    //test
//    cout<<t.AB<<t.AC<<t.BC;
//    int g=t.canA()+t.canB()+t.canC();
//    cout<<g;
//    g=t.vuongA()+t.vuongB()+t.vuongC();
//    cout<<g;
    cout<<"AB:"<<t.getAB()<<endl;
    cout<<"AC:"<<t.getBC()<<endl;
    cout<<"BC:"<<t.getAC()<<endl;
    cout<<"canA:"<<(t.canA())<<endl;
    cout<<"canB:"<<(t.canB())<<endl;
    cout<<"canC:"<<(t.canC())<<endl;
    cout<<(t.vuongA())<<endl;
    cout<<(t.vuongB())<<endl;
    cout<<(t.vuongC())<<endl;
    cout<<(t.deu())<<endl;

    if(!(t.canA()+t.canB()+t.canC()+t.vuongA()+t.vuongB()+t.vuongC())){
        cout<<"t="<<(t.canA()+t.canB()+t.canC()+t.vuongA()+t.vuongB()+t.vuongC())<<endl;
        cout<<"tam giac thuong"<<endl;
    }
    return 0;
}
