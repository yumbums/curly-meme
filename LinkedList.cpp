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

	if(temp == nullptr)
	{
		temp = head;
	}

	if(temp->next == nullptr)
	{
		count++;
		temp = nullptr;
		return count;
	}
	else
	{
		count++;
		temp = temp->next;
		return count;
		LinkedList::size();
	}
}

void LinkedList::delete_list()
{
	if(temp == nullptr)
	{
		temp = head;
	}

	if(temp->next == nullptr)
	{
		free(temp);
		temp == nullptr;
		return;
	}
	else
	{
		free(temp);
		temp = temp->next;
		LinkedList::delete_list();
	}
}

void LinkedList::print_list()
{
	if(temp == nullptr)
	{
		temp = head;
	}

	if(temp->next == nullptr)
	{
		cout << temp->data->getId() << endl;
		cout << temp->data->getName() << endl;
		cout << temp->data->getAddress() << endl;
		cout << temp->data->getCity() << endl;
		cout << temp->data->getState() << endl;
		cout << temp->data->getZip() << endl;
		cout << temp->data->getBalance() << endl;
		temp = nullptr;
		return;
	}
	else
	{
		cout << temp->data->getId() << endl;
		cout << temp->data->getName() << endl;
		cout << temp->data->getAddress() << endl;
		cout << temp->data->getCity() << endl;
		cout << temp->data->getState() << endl;
		cout << temp->data->getZip() << endl;
		cout << temp->data->getBalance() << endl;

		temp = temp->next;
		LinkedList::print_list();
	}
}

Customer* LinkedList::pop_front()
{
	Customer*c1;
	node * temp1;

	if(temp == nullptr)
	{
		temp = head;
	}

	temp1 = temp->next;
	c1 = temp->data;
	free(temp);
	head = temp1;
	return c1;
}

Customer* LinkedList::pop_back()
{
	Customer*c1;

	if(temp == nullptr)
	{
		temp = head;
	}

	if(temp->next == nullptr)
	{
		c1 = temp->data;
		free(temp);
		temp = nullptr;
		return c1;
	}
	else
	{

		temp = temp->next;
		c1 = temp->data;
		return c1;
		LinkedList::pop_back();
	}
}

Customer* LinkedList::find(int ID)
{
	int i;
	Customer * c1;

	if(temp == nullptr)
	{
		temp = head;
	}

	c1 = temp->data;
	i = c1->getId();

	if(i == ID)
	{
		c1 = temp->data;
		temp = nullptr;
		return c1;
	}
	else
	{
		temp = temp->next;
		return c1;
		LinkedList::find(ID);
	}
}

bool LinkedList::exists(int ID)
{
	int i;
	Customer * c1;
	if(temp == nullptr)
	{
		temp = head;
	}

	c1 = temp->data;
	i = c1->getId();
	if(i == ID)
	{
		cout << "The ID does exist" << endl;
		return true;
		temp == nullptr;
	}
	else
	{
		temp = temp->next;
		return false;
		LinkedList::exists(ID);
		cout << "Unable to find ID" << endl;
	}
}

bool LinkedList::deleteit(int ID)
{
	int i;
	Customer*c1;

	if(temp == nullptr)
	{
		temp = head;
	}

	c1 = temp->data;
	i = c1->getId();

	if(i == ID)
	{
		free(temp);
		temp = nullptr;
		return true;
	}
	else
	{
		temp = temp->next;
		LinkedList::deleteit(ID);
		return false;
		cout << "Unable to find ID" << endl;
	}
}

LinkedList::LinkedList() {
	head = nullptr;
	temp = nullptr;
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
