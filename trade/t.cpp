#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Product{
	public:
		string name;
		int stock;
		int price;
};
class Market{
	public:
		vector<Product*> products;
};
class Government{
	public:
};
class Planet{
	public:
		string name;
		Government government;
		Market market;
};
class Universe{
	public:
		vector<Planet> planets;
};
class Bay{
	vector<Product> products;
};
class ProductCargo{
	vector<Bay>bays;
};
class Ship{
	public:
		string model;
		int speed;
		int shield;
		int atack;
		int damages;
};
class PirateShip: public Ship{
	public:
};
class PoliceShip: public Ship{
	public:
};
class CargoShip: public Ship{
	public:
		ProductCargo cargo;
};
class Expert{
	public:
};
class Crew{
	vector<Expert *>tripulation;
};
class UserShip: public CargoShip{
	public:
		Crew crew;
};
class Encounter{
};
class ShipView{
};
class PlanetView{
};
class BuyView{
};
class UniverseView{
};
class EncounterView{
};
