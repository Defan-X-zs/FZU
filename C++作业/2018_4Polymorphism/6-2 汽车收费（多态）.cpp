//6-2 汽车收费（多态）
class Car:public Vehicle{
protected:
	int guest;
	int weight;
public:
	Car(string n, int g, int w):Vehicle(n),guest(g),weight(w){}
	int fee(){
		return guest*8+weight*2;
	}
};
class Truck:public Vehicle{
protected:
	int weight;
public:
	Truck(string n, int w):Vehicle(n),weight(w){}
	int fee(){
		return weight*5;
	}
};
class Bus:public Vehicle{
protected:
	int guest;
public:
	Bus(string n, int g):Vehicle(n),guest(g){}
	int fee(){
		return guest*3;
	}
};