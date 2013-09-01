#define BOOST_TEST_MODULE MyTest
#define  BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Maqueta.h"
#include <iostream>
using namespace std;
BOOST_AUTO_TEST_CASE( maqueta_test )
{
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
	BOOST_CHECK(j1->saldo==40);
	BOOST_CHECK(j2->saldo==20);
	BOOST_CHECK(j1->getStock(1) == 9);
	BOOST_CHECK(j2->getStock(1) == 1);
	BOOST_CHECK(j1->getNumProductos()==1);





}

