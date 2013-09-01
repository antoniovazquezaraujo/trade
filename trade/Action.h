/*
 * Action.h
 *
 *  Created on: 01/09/2013
 *      Author: to
 */

#ifndef ACTION_H_
#define ACTION_H_
template<typename Actor, typename Receptor, typename Context>
class Action {

public:
	virtual void run(){
		actor->act(this);
		receptor->recept(this);
	}
	virtual ~Action(){

	}
	Actor * actor;
	Receptor * receptor;
	Context * context;
};
#endif /* ACTION_H_ */
