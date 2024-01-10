#include <iostream>
using namespace std;
// void nhapMang(int (&matran)[m][n], int m, int n){
//     cout<<"nhap phan tu thu ";
// }
void nhapMang(int *mang, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"nhap phan tu thu ("<<i<<","<<j<<")=";
            cin>>*mang;
            cout<<endl;
            mang++;
        }
    }
}
void xuatMang(int *mang, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<*mang;
            mang++;
        }
        cout<<endl;
    }
}
int main(){
    int m,n;
    int matran[m][n];
    cout<<"nhap ma tran (m x n)"<<endl;
    cout<<"m=";
    cin>>m;
    cout<<endl;
    cout<<"n=";
    cin>>n;
    cout<<endl;
    //lay dia chi phan tu dau tien cua ma tran 2 chieu
    //ma tran 1 chieu thi ten ma tran chinh la dia chi dau tien nhung ma tran 2 chieu thi khac
    nhapMang(&matran[0][0],m,n);
    xuatMang(&matran[0][0],m,n);
    
    return 0;   
}