//6-4 2017final点的个数
class Point{
private:
    int x,y;
public:
    static int count;
    Point();
    Point(Point &a);
    Point(int a,int b);
    Point(int c);
    int getX();
    int getY();
    static void showCount();
};
int Point::count=0;
Point::Point() {
    x=0;
    y=0;
    Point::count++;
}
Point::Point(Point &a) {
    x=a.x;
    y=a.y;
    Point::count++;
}
Point::Point(int a,int b) {
    x=a;
    y=b;
    Point::count++;
}
Point::Point(int c) {
    x=c;
    y=0;
    Point::count++;
}
int Point::getX() {
    return x;
}
int Point::getY() {
    return y;
}
void Point::showCount() {
    cout<<Point::count<<endl;
}
