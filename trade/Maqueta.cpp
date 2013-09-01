#include <iostream>
using namespace std;

class Comprador;
class Vendedor;
class Libro;
class Producto {
public:
	Producto()
		:precio(10){

	}
	virtual void comprar(Comprador *c, Vendedor* v);
	virtual void vender(Vendedor *v, Comprador* c);
	float precio;
};
class Droga: public Producto {
public:
	void comprar(Comprador *c, Vendedor* v);
	virtual void vender(Vendedor *v, Comprador* c);
};

class Libro: public Producto {
public:
	void comprar(Comprador *c, Vendedor* v);
	virtual void vender(Vendedor *v, Comprador* c);
};
class Comida: public Producto {
};

class Comprador {
public:
	virtual void comprarDroga(Droga * d) {
	}
	virtual void comprarLibro(Libro* l) {
	}
};
class Vendedor {
public:
	virtual void venderDroga(Droga * d) {
	}
	virtual void venderLibro(Libro* l) {
	}
};

class Jugador: public Comprador, public Vendedor {
public:
	Jugador()
		:saldo(100){

	}
	virtual void venderDroga(Droga * d) {
		cout << "Vendo droga" << endl;
		saldo += d->precio;
	}
	virtual void venderLibro(Libro* l) {
		cout << "Vendo libros" << endl;
		saldo += l->precio;
	}
	virtual void comprarDroga(Droga * d) {
		cout << "Compro drogas" << endl;
		saldo -= d->precio;
	}
	virtual void comprarLibro(Libro* l) {
		cout << "Compro libros" << endl;
		saldo -= l->precio;
	}
	float saldo;
};

void Producto::comprar(Comprador *c, Vendedor* v) {
	cout << "Me compran" << endl;
}
void Producto::vender(Vendedor *v, Comprador* c) {
	cout << "Me venden" << endl;
}
void Droga::comprar(Comprador *c, Vendedor * v) {
	c->comprarDroga(this);
}
void Droga::vender(Vendedor *v, Comprador * c) {
	v->venderDroga(this);
}

void Libro::comprar(Comprador *c, Vendedor * v) {
	c->comprarLibro(this);
}
void Libro::vender(Vendedor *v, Comprador * c) {
	v->venderLibro(this);
}

int main() {
	Producto* cosas[3];
	cosas[0] = new Droga;
	cosas[1] = new Libro;
	cosas[2] = new Comida;

	Jugador * v1 = new Jugador;
	Jugador * v2 = new Jugador;
	for (Producto* p : cosas) {
		cout << "Antes de comprar: Comprador: " << v1->saldo << " Vendedor: " << v2->saldo<< endl;
		p->comprar(v1, v2);
		cout << "Antes de vender: Comprador: " << v1->saldo << " Vendedor: " << v2->saldo<< endl;
		p->vender(v2, v1);
	}
}
