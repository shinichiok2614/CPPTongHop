// Bai3_kiemtra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include"Hoadon.h"
#include"Hoadontiendien.h"
#include"Hoadontiennuoc.h"
using namespace std;
vector <Hoadontiendien> listdien;
vector <Hoadontiennuoc> listnuoc;

void nhaphoadon() {
    cout << "Nhap hoa don:" << endl;
    int choice = 0;
    while (choice != 3) {
        cout << "Enter 1(hoa don tien dien):" << endl;
        cout << "Enter 2(hoa don tien nuoc):" << endl;
        cout << "Enter 3 de thoat:" << endl;
        cin >> choice;
        if (choice == 1) {
            Hoadontiendien a;
            cin >> a;
            listdien.push_back(a);
        }
        else if (choice == 2) {
            Hoadontiennuoc b;
            cin >> b;
            listnuoc.push_back(b);
        }
    }
}
void Sapxep() {
    for (int i = 0; i < listdien.size(); i++) {
        for (int j = i; j < listdien.size(); j++) {
            if (listdien[i].Thanhtien() > listdien[j].Thanhtien()) {
                swap(listdien[i], listdien[j]);
            }
        }
    }
    for (int i = 0; i < listnuoc.size(); i++) {
        for (int j = i; j < listnuoc.size(); j++) {
            if (listnuoc[i].Thanhtien() > listnuoc[j].Thanhtien()) {
                swap(listnuoc[i], listnuoc[j]);
            }
        }
    }
}
void Timkiem(int sohoadon, string ngayrahoadon) {
    for (int i = 0; i < listdien.size(); i++)
    {
        if (listdien[i].getSohoadon() == sohoadon && listdien[i].getNgayrahoadon() == ngayrahoadon) {
            listdien[i].GetInfo();
        }
    }
    for (int i = 0; i < listnuoc.size(); i++)
    {
        if (listnuoc[i].getSohoadon() == sohoadon && listnuoc[i].getNgayrahoadon() == ngayrahoadon) {
            listnuoc[i].GetInfo();
        }
    }
}
int main()
{
    nhaphoadon();
    Sapxep();
    int sohoadon; string ngayrahoadon;
    cout << "Nhap so hoa don:"; cin >> sohoadon;
    cout << "Nhap ngay ra hoa don:"; cin >> ngayrahoadon;
    Timkiem(sohoadon, ngayrahoadon);

}

