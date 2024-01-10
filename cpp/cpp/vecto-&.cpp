//
//  vecto.cpp
//  cppMacOS
//
//  Created by pc on 10/02/2023.
//

#include "vecto.hpp"
#include "iostream"
using namespace std;
struct vt{
    int x;
    int y;
};
void nhapvt(vt *a){
    cout<<"nhap vector: x=";
    cin>>a->x;
    cout<<"nhap vector: y=";
    cin>>a->y;
}
void xuatvt(vt a){
    cout<<"vector 1: ("<<a.x<<","<<a.y<<")"<<endl;
}
void tongvt(vt a, vt b){
    cout<<"tong 2 vector: ("<<a.x+b.x<<","<<a.y+b.y<<")"<<endl;
}
void nhanvt(vt a, vt b){
    cout<<"nhan 2 vector: ("<<a.x*b.x<<","<<a.y*b.y<<")"<<endl;
}
int main(){
    vt a;
    vt b;
    nhapvt(&a);
    nhapvt(&b);
    xuatvt(a);
    xuatvt(b);
    tongvt(a,b);
    nhanvt(a,b);
}
