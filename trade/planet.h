/*
 * borrame.h
 *
 *  Created on: 25/08/2013
 *      Author: to
 */

#ifndef BORRAME_H_
#define BORRAME_H_

#include <string>
using namespace std;
#include "government.h"
#include "market.h"

class Planet{
	public:
		string name;
		Government government;
		Market market;
};



#endif /* BORRAME_H_ */
