#include <iostream>
#include <map>
using namespace std;

class Transferer;
class Libro;
class Producto {
public:
	Producto(string nombre="generico")
		:nombre(nombre)
		,precio(0){

	}
	virtual ~Producto(){

	}
	virtual void transferir(Transferer *c, Transferer* v, unsigned int cantidad = 1);
	string nombre;
	float precio;

};
bool operator==(const Producto& a, const Producto& b){
	return a.nombre == b.nombre;
}
bool operator<(const Producto& a, const Producto& b){
	return a.nombre < b.nombre;
}

class Droga: public Producto {
public:
	void transferir(Transferer *c, Transferer* v, unsigned int cantidad = 1);
};

class Libro: public Producto {
public:
	void transferir(Transferer *c, Transferer* v, unsigned int cantidad = 1);

};
class Comida: public Producto {
};

class Transferer {
public:
	Transferer()
		:saldo(0){

	}
	virtual ~Transferer(){

	}
	void agregar(Producto p, unsigned int cantidad){
		stock[p]+=cantidad;
	}
	virtual bool entregar(Producto p, unsigned int cantidad){
		if(stock.count(p) >= cantidad){
			stock[p]-=cantidad;
			saldo += cantidad* p.precio;
			return true;
		}
		return false;
	}
	virtual bool recibir(Producto p, unsigned int cantidad){
		if(saldo >= cantidad* p.precio){
			stock[p]+=cantidad;
			saldo -= cantidad* p.precio;
			return true;
		}
		return false;
	}
	virtual void entregarDroga(Droga  d, int cantidad) {
		entregar(d, cantidad);
	}
	virtual void entregarLibro(Libro l, int cantidad) {
		entregar(l, cantidad);
	}
	virtual void recibirDroga(Droga  d, int cantidad) {
		recibir(d, cantidad);
	}
	virtual void recibirLibro(Libro l, int cantidad) {
		recibir(l, cantidad);
	}
	int getStock(Producto p){
		if(stock.count(p) > 0){
			return stock[p];
		}
		return 0;
	}
	int getNumProductos(){
		return stock.size();
	}
	map<Producto, int> stock;
	float saldo;
};


void Producto::transferir(Transferer *c, Transferer* v, unsigned int cantidad ) {
	cout << "Me compran" << endl;
}

void Droga::transferir(Transferer *c, Transferer * v, unsigned int cantidad ) {
	c->entregarDroga(*this,cantidad);
	v->recibirDroga(*this,cantidad);
}

void Libro::transferir(Transferer *c, Transferer * v, unsigned int cantidad ) {
	v->entregarLibro(*this,cantidad);
	v->recibirLibro(*this,cantidad);
}
class Jugador: public Transferer{
public:
	virtual ~Jugador(){

	}
	void recibirDroga(Droga   d, int cantidad) {
		Transferer::recibirDroga(d, cantidad);
		cout << "Las drogas son malas";
	}
	int status;
};
int main3() {
	Producto* cosas[3];
	cosas[0] = new Droga;
	cosas[1] = new Libro;
	cosas[2] = new Comida;

	Jugador * v1 = new Jugador;
	Jugador * v2 = new Jugador;
	for (Producto* p : cosas) {
		cout << "Antes de recibir: Transferer: " << v1->saldo << " Transferer: " << v2->saldo<< endl;
		p->transferir(v1, v2, 2);
		cout << "Antes de entregar: Transferer: " << v1->saldo << " Transferer: " << v2->saldo<< endl;
		p->transferir(v2, v1,5);
	}
	return 0;
}
