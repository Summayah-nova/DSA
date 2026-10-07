#include<iostream>
using namespace std;
template<typename T>
class shape {
public:
	virtual T area()const = 0;
	virtual ~shape() {}
};
template<typename T>
class circle{
private:
	T radius;
public:
	circle(T r) :radius(r) {}
	T area() {
		return 3.14159 * radius * radius;
	}
};
template<typename T>
class rectangle{
private:
	T length;
	T width;
public:
	rectangle(T l, T w) :length(l), width(w) {}
	T area() {
		return length * width;
	}
};
int main(){
	circle<double> c(5.5);
	rectangle<int> r(4, 2);
	cout << "Area of circle = " << c.area() << endl;
	cout << "Area of rectngle = " << r.area() << endl;

	return 0;
	}