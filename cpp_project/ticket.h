#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ticket {
private:
	string personName="";
	string company = "";
	char* id=nullptr;
	bool isSoldOut;
	int number=0;
public:

	//default constructor
	Ticket() {
		this->number = 0;
		this->isSoldOut = false;
		this->id = nullptr;
		this->personName = "";
		this->company = "";
	}
	//1st constructor with parameters
	Ticket(int number, char* id)
	{
		this->number = number;
		if (id != nullptr) {
			this->id = new char[strlen(id) + 1];
			strcpy(this->id, id);
		}
		number++;
	}


	//2nd constructor with parameters
	Ticket(string personName,string company, char* id)
	{
		this->personName= personName;
		this->company = company;
		if (id != nullptr) {
			this->id = new char[strlen(id) + 1];
			strcpy(this->id, id);
		}
		number++;
	}









	//copy constructor 
	Ticket(const Ticket& ticket) {
		this->number = ticket.number;
		this->isSoldOut = ticket.isSoldOut;
		this->personName = ticket.personName;
		this->company = ticket.company;
		
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

	//destructor
	~Ticket()
	{
		if (this->id != nullptr)
		{
			delete[] this->id;
		}
	}

	//getters
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
		return this->isSoldOut;
	}


	string getPersonName() {
		return this->personName;
	}

	string getCompany() {
		return this->company;
	}
	//setters
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

	void setValidation(bool isSoldOut)
	{
		this->isSoldOut = isSoldOut;
	}

	void setPersonName(string personName)
	{
		this->personName = personName;
	}


	void setCompany(string company)
	{
		this->company = company;
	}



	// overloading of operator =
	Ticket& operator=(const Ticket& ticket) {
		if (this != &ticket) {
			this->isSoldOut = ticket.isSoldOut;
			this->number = ticket.number;
			this->personName = ticket.personName;
			this->company = ticket.company;
			if (this->id!= nullptr) {
				delete[] this->id;
			}
			if (ticket.id != nullptr) {
				this->id = new char[strlen(ticket.id) + 1];
				strcpy(this->id, ticket.id);
			}
			else {
				this->id = nullptr;
			}
		}
		return *this;
	}

	// << operator
	friend ostream& operator<<(ostream& console, const Ticket& ticket)
	{
		console << "Person name:" << ticket.personName;
		console << "Company responsible for selling the tickets:" << ticket.company;
		console << "id: " << ticket.id;
		console << "Is it sold out? " << (ticket.isSoldOut ? "yes" : "no");
		return console;
	}

	// >> operator 
	friend istream& operator>>(istream& console, Ticket& ticket) {
		cout << "Person name:";
		console >> ticket.personName;

		cout << "Company responsible for selling the tickets:";
		console >> ticket.company;

		cout << "ticket ID: ";
		console >> ticket.id;

		cout << "is valid? (1 = yes, 0 = no): ";
		console>> ticket.isSoldOut;
		return console;
	}


	

};
