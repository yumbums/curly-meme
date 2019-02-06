 /*
 * LinkedList.hpp
 *
 *  Created on: Feb 1, 2019
 *      Author: Shailesh
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_
#include "Customer.hpp"

struct node {

	Customer * data;
	node * next;
};



namespace std {

class LinkedList {
private:
	node * head;
	node * temp;
	//temp = head;
public:
	//member functions
	void push_back(Customer*);
	void push_front(Customer*);
	int size();
	void delete_list();
	void print_list();
	Customer* pop_front();
	Customer* pop_back();
	Customer* find(int);
	bool exists(int);
	bool deleteit(int);

	LinkedList();
	virtual ~LinkedList();
};

} /* namespace std */

#endif /* LINKEDLIST_HPP_ */
