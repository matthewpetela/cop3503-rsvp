/*
 * objects.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Kimmy Spencer
 */

#ifndef OBJECTS_H_
#define OBJECTS_H_

#include <iostream>
#include <string>

using namespace std;

class objects{
private:


	string name;
	int amnt;
public:
	objects(string name, int amnt);

	void setRegistry(string gift);
	void setAmount(int qnty);

	string getRegistry();
};




#endif /* OBJECTS_H_ */
