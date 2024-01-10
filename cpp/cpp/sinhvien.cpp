#include <iostream>
using namespace std;
class SinhVien{
    private:
        // string hoten;
        // string ngaysinh;
        // string gioitinh;
        float toan;
        float ly;
        float hoa;
        float diemtb;
    public:
        void set(float,float,float);
        void get(float,float,float);
        SinhVien(float, float, float,float);
        float tinhdtb();
};
SinhVien::SinhVien(float t, float l, float h, float dtb){
    this->toan=t;
    this->ly=l;
    this->hoa=h;
    this->diemtb=dtb;
    // return (toan+ly+hoa)/3;
}
void SinhVien::set(float t, float l, float h){
    this->toan=t;
    this->ly=l;
    this->hoa=h;
}
float SinhVien::tinhdtb(){
    return (this->toan+this->ly+this->hoa)/3;
}
int main(){
    SinhVien sv(0,0,0,0);
    int a,b,c;
    cout<<"nhap (toan,ly,hoa):";
    cin>>a>>b>>c;
    cout<<endl;
    sv.set(a,b,c);
    cout<<"diem trung binh: "<<sv.tinhdtb();
}