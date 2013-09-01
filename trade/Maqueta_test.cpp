#define BOOST_TEST_MODULE MyTest
#define  BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Maqueta.h"
#include <iostream>
using namespace std;
BOOST_AUTO_TEST_CASE( maqueta_test )
{
	Droga prod;
	prod.precio = 10;
	Jugador * j1 = new Jugador;
	Jugador * j2 = new Jugador;
	j1->saldo = 10;
	j2->saldo = 10;
	BOOST_CHECK(j1->getStock(prod) == 0);
	BOOST_CHECK(j2->getStock(prod) == 0);
	j1->agregar(prod, 10);
	BOOST_CHECK(j1->getStock(prod) == 10);
	BOOST_CHECK(j2->getStock(prod) == 0);
	prod.transferir(j1, j2, 1);
//	cout  << j1->saldo << ", " << j2->saldo<<endl;
	BOOST_CHECK(j1->saldo==20);
	BOOST_CHECK(j2->saldo==0);
	BOOST_CHECK(j1->getStock(prod) == 9);
	BOOST_CHECK(j2->getStock(prod) == 1);
	BOOST_CHECK(j1->getNumProductos()==1);
	UsuarioAdicto * u = new UsuarioAdicto;
	prod.transferir(j2, u, 1);
	prod.transferir(u, j2, 1);




}

