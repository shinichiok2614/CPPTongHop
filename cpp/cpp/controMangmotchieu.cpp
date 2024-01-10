//
//  controMangmotchieu.cpp
//  cppMacOS
//
//  Created by pc on 09/02/2023.
//
#include <iostream>
#include "controMangmotchieu.hpp"
using namespace std;
void nhapMang(int mang[20], int COL){
    int *m=mang;
    for(int i=0; i<COL;i++){
        cout<<"Nhap phan tu thu "<<i<<":";
        cin>>*m;
        m++;
        cout<<endl;
    }
}
void xuatMang(int mang[20], int COL){
    int *m=mang;
    for(int i=0; i<COL;i++){
        cout<<"Phan tu thu "<<i<<":"<<*m<<endl;
        m++;
    }
}
int main(){
    int COL;
    int mang[20];
    cout<<"Nhap so phan tu:";
    cin>>COL;
    cout<<endl;
    nhapMang(mang, COL);
    xuatMang(mang, COL);
}
