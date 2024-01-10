//
//  phanso.cpp
//  cppMacOS
//
//  Created by pc on 09/02/2023.
//
#include "iostream"
#include "phanso.hpp"
using namespace std;
struct PHANSO{
    int tuso;
    int mauso;
};
int UCLN(int a, int b){
    int t=(a>b)?b:a;
    int u=1;
    if (t>1){
        for(int i=2;i<=t; i++){
            if(((a%i)==0) && ((b%i)==0)){
                u=i;
            };
        }
    }
    return u;
}
void toigianPhanso(int *tuso,int *mauso){
    int u=UCLN(*tuso, *mauso);
    *tuso=(*tuso)/u;
    *mauso=(*mauso)/u;
}
void congPhanso(int tuso1, int mauso1, int tuso2, int mauso2){
    int mc=mauso1*mauso2;
    int tc=tuso1*mauso2+tuso2*mauso1;
    toigianPhanso(&tc, &mc);
    cout<<"ket qua cong hai phan so: ("<<tc<<"/"<<mc<<")"<<endl;
}
void nhanPhanso(int tuso1, int mauso1, int tuso2, int mauso2){
    int mc=mauso1*mauso2;
    int tc=tuso1*tuso2;
    toigianPhanso(&tc, &mc);
    cout<<"ket qua nhan hai phan so: ("<<tc<<"/"<<mc<<")"<<endl;
}
int main(){
    
    PHANSO ps1;
    PHANSO ps2;
    cout<<"nhap tu so:";
    cin>>ps1.tuso;
    cout<<endl;
    cout<<"nhap mau so:";
    cin>>ps1.mauso;
    cout<<endl;
    cout<<"(tu so/mau so):("<<ps1.tuso<<"/"<<ps1.mauso<<")"<<endl;
    toigianPhanso(&ps1.tuso, &ps1.mauso);
    cout<<"(tu so/mau so) da toi gian:("<<ps1.tuso<<"/"<<ps1.mauso<<")"<<endl;

    cout<<"nhap tu so:";
    cin>>ps2.tuso;
    cout<<endl;
    cout<<"nhap mau so:";
    cin>>ps2.mauso;
    cout<<endl;
    cout<<"(tu so/mau so):("<<ps2.tuso<<"/"<<ps2.mauso<<")"<<endl;
    toigianPhanso(&ps2.tuso, &ps2.mauso);
    cout<<"(tu so/mau so) da toi gian:("<<ps2.tuso<<"/"<<ps2.mauso<<")"<<endl;

    congPhanso(ps1.tuso, ps1.mauso, ps2.tuso, ps2.mauso);
    nhanPhanso(ps1.tuso, ps1.mauso, ps2.tuso, ps2.mauso);
}
