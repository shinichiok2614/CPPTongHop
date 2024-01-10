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
