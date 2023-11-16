#pragma once
#include <iostream>
#include <string>
#include <cstdlib>		


using namespace std;

class Ticket {
private:
	char* id;
	bool isValid;
	int number;


	//default constructor
	Ticket() {
		this->number = 0;
		this->isValid = false;
		this->id = nullptr;

	}
	//constructor with parameters
	Ticket(int number, bool isValid, char* id)
	{
		this->number = number;
		this->isValid = isValid;
		if (id != nullptr) {
			this->id = new char[strlen(id) + 1];
			strcpy(this->id, id);
		}
		number++;
	}

	//Copy constructor 
	Ticket(const Ticket& ticket) {
		this->number = ticket.number;
		this->isValid = ticket.isValid;
		if (ticket.id != nullptr)
		{
			this->id = new char[strlen(ticket.id) + 1];
			strcpy(this->id, ticket.id);
		}
		else
		{
			this->id = nullptr;
		}
	}

	//Destructor
	~Ticket()
	{
		if (this->id != nullptr)
		{
			delete[] this->id;
		}
	}

	//Getters
	int getNumber()
	{
		return this->number;
	}

	char* getId()
	{
		char* copy = new char[strlen(this->id) + 1];
		strcpy(copy, this->id);
		return copy;
	}

	int getValidation()
	{
		return this->isValid;
	}

	//Setters
	void setNumber(int number)
	{
		this->number = number;
	}

	void setId(const char* id)
	{
		if (this->id != nullptr)
		{
			delete[] this->id;
		}
		this->id = new char[strlen(id) + 1];
		strcpy(this->id, id);
	}

	void setValidation(bool isvalid)
	{
		this->isValid = isValid;
	}


	// >> operator 
	friend istream& operator>>(istream& in, Ticket& ticket) {
		cout << "ticket ID: ";
		in >> ticket.id;

		cout << "is valid? (1 = yes, 0 = no): ";
		in >> ticket.isValid;
		return in;
	}


	// << operator
	friend ostream& operator<<(ostream& out, const Ticket& ticket) 
	{
		out << "id: " << ticket.id << ", valid: " << (ticket.isValid ? "yes" : "no");
		return out;
	}


};


int main()
{
	std::cout << "Ticket :";
}