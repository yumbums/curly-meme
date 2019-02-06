/*
 * LinkedList.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: Shailesh
 */

#include "LinkedList.hpp"
#include <iostream>

namespace std {

void LinkedList::push_front(Customer* cptr)
{
	if(head == nullptr)
	{
		head = new node;
		head->data = cptr;
		head->next = nullptr;
	}
	else
	{
		if(temp == nullptr)
		{
			temp = head;
		}
		temp->next = head;
		temp->data = cptr;
		push_front(cptr);
	}
}

void LinkedList::push_back(Customer* cptr)
{

	if(head == nullptr)
	{
		head = new node;
		head->data = cptr;
		head->next = nullptr;
	}
	else
	{
		if(temp == nullptr)
		{
			temp = head;
		}
		if(temp->next == nullptr)
		{
			temp->next = new node;
			temp->next->data = cptr;
			temp->next->next = nullptr;
			temp = nullptr;
		}
		else
		{
			temp = temp->next;
			push_back(cptr);
		}
	}
}

int LinkedList::size()
{

	int count = 0;
	temp = head;
	if(temp->next == nullptr)
	{
		return count;
	}
	else
	{
		count = LinkedList::size() + 1;
		temp = temp->next;
	}
}

void LinkedList::delete_list()
{

	if(temp == nullptr)
	{
		return;
	}
	else
	{
		free(temp);
		temp = temp->next;
		LinkedList::delete_list();
	}
	temp = head;
}

void LinkedList::print_list()
{

	if(temp == nullptr)
	{
		return;
	}
	else
	{
		cout << temp->data << endl;
		temp = temp->next;
		LinkedList::print_list();
	}
	temp = head;
}

Customer* LinkedList::pop_front()
{
	Customer*c1;
	node * temp1;
	temp1 = temp->next;
	c1 = temp->data;
	free(temp);
	head = temp1;
	return c1;

}

Customer* LinkedList::pop_back()
{
	Customer*c1;
	if(temp->next == nullptr)
	{
		c1 = temp->data;
		free(temp);
		return c1;
	}
	else
	{

		temp = temp->next;
		c1 = temp->data;
		LinkedList::pop_back();
		return c1;
	}
}

Customer* LinkedList::find(int ID)
{
	int i;
	Customer*c1;
	c1 = temp->data;
	i = c1->getId();
	if(i = ID)
	{
		c1 = temp->data;
		return c1;
	}
	else
	{
		temp = temp->next;
		LinkedList::find(ID);
		return c1;
	}
}

bool LinkedList::exists(int ID)
{
	int i;
	Customer*c1;

	c1 = temp->data;
	i = c1->getId();
	if(i = ID)
	{
		return true;
	}
	else
	{
		temp = temp->next;
		LinkedList::exists(ID);
		return false;
	}
}

bool LinkedList::deleteit(int ID)
{

}

LinkedList::LinkedList() {
	head = nullptr;

}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
