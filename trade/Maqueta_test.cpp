#define BOOST_TEST_MODULE MyTest
#define  BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Maqueta.h"
#include <iostream>
using namespace std;
class Effect;
class Marear;
class Manzana;

class Product {
public:
	virtual void accept(Effect * e);
	virtual void acceptMarear(Marear * e);
};

void Product::acceptMarear(Marear * e) {
	cout << "Product acceptMarear" << endl;

}
class Effect {
public:
	virtual void reactTo(Product *);

};
void Product::accept(Effect * e) {
	cout << "Producto accept Effect" << endl;
	e->reactTo(this);
}
void Effect::reactTo(Product * p) {
	cout << "Effect reactToProduct" << endl;

}
class Marear: public Effect {
public:
	void reactTo(Product*p) {
		p->acceptMarear(this);
	}
};

class Manzana: public Product {
public:
	void acceptMarear(Marear * e);
};
void Manzana::acceptMarear(Marear * e) {
	cout << "Manzana acceptMarear" << endl;

}

BOOST_AUTO_TEST_CASE( maqueta_test ) {
	Effect * efectos[2];
	Product * productos[2];
	efectos[0] = new Effect;
	efectos[1] = new Marear;
	productos[0] = new Product;
	productos[1] = new Manzana;
	productos[0]->accept(efectos[0]);
	productos[0]->accept(efectos[1]);
	productos[1]->accept(efectos[0]);
	productos[1]->accept(efectos[1]);

	Producto p("naranja");
	p.precio = 10;
	Producto q("manzana");
	q.precio = 20;
	Catalogo::addProducto(&p, 1);
	Catalogo::addProducto(&q, 2);

	Trader * j1 = new Trader;
	Trader * j2 = new Trader;
	j1->saldo = 30;
	j2->saldo = 30;
	BOOST_CHECK(j1->getStock(1) == 0);
	BOOST_CHECK(j2->getStock(2) == 0);
	j1->agregar(1, 10);
	BOOST_CHECK(j1->getStock(1) == 10);
	BOOST_CHECK(j2->getStock(2) == 0);
	j1->sale(1, j2, 1);
	BOOST_CHECK(j1->saldo == 40);
	BOOST_CHECK(j2->saldo == 20);
	BOOST_CHECK(j1->getStock(1) == 9);
	BOOST_CHECK(j2->getStock(1) == 1);
	BOOST_CHECK(j1->getNumProductos() == 1);

}

