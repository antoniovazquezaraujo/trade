#include <iostream>
#include <map>
using namespace std;

class Transferer;
class Libro;
class Producto {
public:
	Producto()
		:precio(10){

	}
	virtual void transferir(Transferer *c, Transferer* v);
	float precio;
	float cantidad;
};
class Droga: public Producto {
public:
	void transferir(Transferer *c, Transferer* v);
};

class Libro: public Producto {
public:
	void transferir(Transferer *c, Transferer* v);

};
class Comida: public Producto {
};

class Transferer {
public:
	Transferer()
		:saldo(0){

	}
	virtual void entregar(Producto * p, int cantidad){
		if(stock.count(p) > 0){
			stock[p]-=cantidad;
			saldo += p->precio;
		}
	}
	virtual void recibir(Producto * p, int cantidad){
		stock[p]+=cantidad;
		saldo -= p->precio;

	}
	virtual void entregarDroga(Droga * d, int cantidad) {
		entregar(d, cantidad);
	}
	virtual void entregarLibro(Libro* l, int cantidad) {
		entregar(l, cantidad);
	}
	virtual void recibirDroga(Droga * d, int cantidad) {
		recibir(d, cantidad);
	}
	virtual void recibirLibro(Libro* l, int cantidad) {
		entregar(l, cantidad);
	}
	map<Producto*, int> stock;
	float saldo;
};


void Producto::transferir(Transferer *c, Transferer* v) {
	cout << "Me compran" << endl;
}

void Droga::transferir(Transferer *c, Transferer * v) {
	c->entregarDroga(this,1);
	v->recibirDroga(this,1);
}

void Libro::transferir(Transferer *c, Transferer * v) {
	v->entregarLibro(this,1);
	v->recibirLibro(this,1);
}
class Jugador: public Transferer{

};
int main() {
	Producto* cosas[3];
	cosas[0] = new Droga;
	cosas[1] = new Libro;
	cosas[2] = new Comida;

	Jugador * v1 = new Jugador;
	Jugador * v2 = new Jugador;
	for (Producto* p : cosas) {
		cout << "Antes de recibir: Transferer: " << v1->saldo << " Transferer: " << v2->saldo<< endl;
		p->transferir(v1, v2);
		cout << "Antes de entregar: Transferer: " << v1->saldo << " Transferer: " << v2->saldo<< endl;
		p->transferir(v2, v1);
	}
}
