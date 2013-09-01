#define BOOST_TEST_MODULE MyTest
#define  BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Maqueta.h"
#include <iostream>
using namespace std;
BOOST_AUTO_TEST_CASE( maqueta_test )
{
	Droga prod;
	prod.precio = 100;
	Jugador * j1 = new Jugador;
	j1->saldo = 100;
	j1->agregar(prod, 1000);
	Jugador * j2 = new Jugador;
	j2->saldo = 100;
	prod.transferir(j1, j2, 1);
	cout  << j1->saldo << ", " << j2->saldo<<endl;
	BOOST_CHECK(j1->saldo==200);
	BOOST_CHECK(j2->saldo==0);


}

