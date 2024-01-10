#include <iostream>
using namespace std;
class Point{
    private:
    int x;
    int y;
    public:
    Point(int,int);
    void set(int a,int b);
    int getX();
    int getY();
};
Point::Point(int a, int b){
    this->x=a;
    this->y=b;
}
void Point::set(int a, int b){
    this->x=a;
    this->y=b;
}
int Point::getX(){
    return this->x;
}
int Point::getY(){
    return this->y;
}
int main(){
    Point p(0,0);
    int a, b;
    cout<<"nhap hoanh do x:";
    cin>>a;
    cout<<endl;
    cout<<"nhap tung do y:";
    cin>>b;
    cout<<endl;
    p.set(a,b);
    cout<<"diem P("<<p.getX()<<","<<p.getY()<<")";
}