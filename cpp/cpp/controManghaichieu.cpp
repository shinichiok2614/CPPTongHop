//
//  controManghaichieu.cpp
//  cppMacOS
//
//  Created by pc on 09/02/2023.
//
#include <iostream>
#include "controManghaichieu.hpp"
using namespace std;
//void nhapMang(int mang[20][20], int ROW, int COL){
//    int **m;
//    *m=new int[1];
//
//}
int main(){
    int mang[5][5];
//    int mang1[2][3]=[(1,2,3),(2,3,4)];
    int ROW, COL;
//    nhapMang(*mang[20], ROW, COL);
    int** m=new int*[5];
    for(int i=0;i<20;i++){
        m[i]=new int(5);
    }
    
//
//    cout<<"nhap so hang:";
//    cin>>ROW;
//    cout<<endl;
//    cout<<"nhap so cot:";
//    cin>>COL;
//    cout<<endl;
    
    m=&mang[0][0];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<"nhap phan tu thu ("<<i<<";"<<j<<"):";
            cin>>m[i][j];
            cout<<endl;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;i<5;j++){
            cout<<"phan tu thu ("<<i<<","<<j<<")";
            cout<<mang[i][j]<<endl;
        }
    }
    return 0;
}
