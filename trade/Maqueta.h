#include <iostream>
#include <map>
using namespace std;
class Producto {
public:
	Producto(string nombre = "generico") :
			nombre(nombre), precio(0) {

	}
	string nombre;
	float precio;
};
bool operator==(const Producto& a, const Producto& b) {
	return a.nombre == b.nombre;
}
bool operator<(const Producto& a, const Producto& b) {
	return a.nombre < b.nombre;
}

class Catalogo{
public:
	static Producto* getProducto(int id){
		if(productos.count(id)>0){
			return productos[id];
		}
		return 0;
	}
	static void addProducto(Producto * p, int id){
		productos[id]=p;
	}
	static map<int, Producto*> productos;
};
// productos del catalogo general
map<int, Producto* > Catalogo::productos;

Producto* getProducto(int id){
	return Catalogo::getProducto(id);
}

class Trader {
public:
	Trader() :
			saldo(0) {

	}
	virtual ~Trader() {

	}
	void agregar(int productoId, unsigned int cantidad) {
		if (stock.count(productoId) > 0) {
			stock[productoId] += cantidad;
		} else {
			stock[productoId] = cantidad;
		}
	}
	bool buy(int productoId, Trader * proveedor, int cantidad){
		if(proveedor->send(productoId, cantidad)){
			receive(productoId, cantidad);
		}
	}
	bool sale(int productoId, Trader * cliente, int cantidad){
		if(send(productoId, cantidad)){
			cliente->receive(productoId, cantidad);
		}
	}
	virtual bool send(int productoId, unsigned int cantidad) {
		if (stock.count(productoId) >= cantidad) {
			stock[productoId] -= cantidad;
			saldo += cantidad *getProducto(productoId)->precio;
			return true;
		}
		return false;
	}
	virtual bool receive(int productoId, unsigned int cantidad) {
		if (saldo >= cantidad * getProducto(productoId)->precio) {
			stock[productoId] += cantidad;
			saldo -= cantidad * getProducto(productoId)->precio;
			return true;
		}
		return false;
	}
 	int getStock(int productoId) {
		if (stock.count(productoId) > 0) {
			return stock[productoId];
		}
		return 0;
	}
	int getNumProductos() {
		return stock.size();
	}
	map<int, int> stock;
	float saldo;
};

 class Jugador: public Trader {
public:
	virtual ~Jugador() {

	}

	int status;
};



