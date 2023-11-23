#pragma once
#include <iostream>
#include <string>

using namespace std;

enum eventType { THEATER, SPORT };

class Ticket {
private:
	string personName="";
	string company = "";
	char* id=nullptr;
	bool isSoldOut=false;
	int* number=nullptr;
    int totalNumber = 0;
public:

	friend istream& operator>>(istream& console, Ticket& ticket);
	friend ostream& operator<<(ostream& console, const Ticket& ticket);

	//default constructor
	Ticket():isSoldOut(false) {
		this->number = nullptr;
		this->id = nullptr;
		this->personName = "";
		this->company = "";
		this->totalNumber = 0;
	}
	//1st constructor with parameters
	Ticket(int* number, int totalNumber, char* id)
	{
		this->totalNumber = totalNumber;
		if (number != nullptr)
		{
			this->number = new int[totalNumber];
			for (int i = 0; i < totalNumber; i++)
			{
				this->number[i] = number[i];
			}
		}
		else
		{
			this->number = nullptr;
		}

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


	//proccesing the event

	int eventType = THEATER;

	void event() {
		switch (eventType) {
			
		case THEATER: cout << "You are buying a ticket for a theater play" << endl;
			break;
		case SPORT: cout << "You are buying a ticket for a sport match" << endl;
			break;
		}
	


	}




	//copy constructor 
	Ticket(const Ticket& ticket) {
		this->isSoldOut = ticket.isSoldOut;
		this->personName = ticket.personName;
		this->company = ticket.company;
		this->totalNumber = ticket.totalNumber;
		
		if (ticket.number != nullptr)
		{
			this->number = new int[this->totalNumber];
			for (int i = 0; i < this->totalNumber; i++)
			{
				this->number[i] = ticket.number[i];
			}
		}

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
		if (this->number != nullptr)
		{
			delete[] this->number;
		}

		if (this->id != nullptr)
		{
			delete[] this->id;
		}
	}

	//getters
	int* getNumber()
	{
		int* copy;
		if (this->number != nullptr)
		{
			copy = new int[this->totalNumber];
			for (int i = 0; i < this->totalNumber; i++)
			{
				copy[i] = this->number[i];
			}
		}
		else
		{
			copy = nullptr;
		}

		return copy;
	}

	char* getId()
	{
		char* copy = new char[strlen(this->id) + 1];
		strcpy(copy, this->id);
		return copy;
	}

	bool getValidation()
	{
		return this->isSoldOut;
	}
	int gettotalNumber()
	{
		return this->totalNumber;
	}

	string getPersonName() {
		return this->personName;
	}

	string getCompany() {
		return this->company;
	}
	//setters
	void setNumber(int* number)
	{
		if (this->number != nullptr)
		{
			delete[] this->number;
		}

		if (number != nullptr)
		{
			this->number = new int[this->totalNumber];
			for (int i = 0; i < this->totalNumber; i++)
			{
				this->number[i] = number[i];
			}
		}
		else
		{
			this->number = nullptr;
		}
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

	void setTotalNumber(int totalNumber)
	{
		this->totalNumber = totalNumber;
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
			this->totalNumber = ticket.totalNumber;
			if (ticket.number != nullptr)
			{
				this->number = new int[ticket.totalNumber];
				for (int i = 0; i < this->totalNumber; i++)
				{
					this->number[i] = ticket.number[i];
				}
			}
			else
			{
				this->number = nullptr;
			}

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


	int operator[](int index)
	{
		if (number != 0 && index >= 0 && index < totalNumber)
		{
			return number[index];
		}
	}

	string operator()( int totalnumber, int capacity)
	{
		if (this->totalNumber == totalNumber)
		{
			if (this->totalNumber > capacity)
			{
				return "Exceeds capacity";
			}
			else
			{
				return "There are still tickets";
			}
			
		}
		
	}


	//a method that prints the content of the ticket
	void showTicket()
	{
		cout << "This event will be provided by the company: " << this->company << "\n";

		if (this->id != nullptr)
		{
			
			
				cout << "Your id is" << this->id<<"associated with the name"<<this->personName<<"\n";
			
		}
		if (this->number != nullptr)
		{
			for (int i = 0; i < this->totalNumber; i++)
			{
				cout << "The number of people participating is " << this->number[i] << " people from a total of"<<this->totalNumber ;
			}
		}
	}

	//+ operator
	friend Ticket operator+(Ticket t1, Ticket t2)
	{
		t1.totalNumber += t2.totalNumber; 
		return t1;
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
