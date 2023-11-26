#pragma once
#include <iostream>
#include <string>

using namespace std;

enum eventType { THEATER, SPORT };

class Ticket {
private:
	int* price; //dynamically defined array of numbers
	int maximumPrice;
	char* id; //dynamically defined array of characters
	string personName;
	int age; //statically defined array of numbers
    const string company;

	static int discount;
	
public:


	//default constructor
	Ticket(): company("iaBilet") {
		this->price = nullptr;
		this->id = nullptr;
		this->personName = "";
		


		
	}


	//1st constructor with parameters
	Ticket(string company, string personName, char* id) :company(company)
	{   
		this->personName = personName;
		if (id != nullptr) {
			this->id = new char[strlen(id) + 1];
			strcpy(this->id, id);
		}
	}


	//2nd constructor with parameters
	Ticket(int* price, string personName,string company, int age, int maximumPrice, char* id) : company(company)
	{
		if (price != nullptr)
		{
			this->price= new int[maximumPrice];
			for (int i = 0; i < maximumPrice; i++)
			{
				this->price[i] = price[i];
			}
		}
		else
		{
			this->price = nullptr;
		}

		this->age = age;
		this->maximumPrice = maximumPrice;
		this->personName = personName;

		if (id != nullptr) {
			this->id = new char[strlen(id) + 1];
			strcpy(this->id, id);
		}
		price++;
	}




	//proccesing the event

	int eventType = THEATER;

	void event() {
		switch (eventType) {
			
		case THEATER: cout << "You are buying a ticket for a theater play " << endl;
			break;
		case SPORT: cout << "You are buying a ticket for a sport match " << endl;
			break;
		}
	


	}




	//copy constructor 
	Ticket(const Ticket& ticket) : company(ticket.company) {
		this->personName = ticket.personName;
		this->age = ticket.age;
		this->maximumPrice = ticket.maximumPrice;
		

		if (ticket.price != nullptr) {
			this->price = new int[this->maximumPrice];
			for (int i = 0; i < this->maximumPrice; i++) {
				this->price[i] = ticket.price[i];
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
		if (this->price != nullptr)
		{
			delete[] this->price;
		}

		if (this->id != nullptr)
		{
			delete[] this->id;
		}
	}

	//getter Price
	int* getPrice()
	{
		int* copy;
		if (this->price != nullptr)
		{
			copy = new int[this->maximumPrice];
			for (int i = 0; i < this->maximumPrice; i++)
			{
				copy[i] = this->price[i];
			}
		}
		else
		{
			copy = nullptr;
		}

		return copy;
	}

	//setter Price

	void setPrice(int* price)
	{
		if (price != nullptr)
		{
			this->price = new int[this->maximumPrice];
			for (int i = 0; i < this->maximumPrice; i++)
			{
				this->price[i] = price[i];
			}
		}
		else
		{
			throw ("Invalid price");
		}
	}

	//getter Id

	char* getId()
	{
		char* copy = new char[strlen(this->id) + 1];
		strcpy(copy, this->id);
		return copy;
	}

	//setter Id

	void setId(const char* id)
	{
		if (id != nullptr)
		{
			if (this->id != nullptr)
			{
				delete[] this->id;
			}
			this->id = new char[strlen(id) + 1];
			strcpy(this->id, id);
		}
		else
		{
			throw ("invalid id");
		}
	}

	//getter Age
	
	int getAge()
	{
		return this->age;
	}

	//setter Age

	void setAge(int age)
	{
		if (age < 0||age>120) {
			throw exception("invalid age");
		}
		else this->age = age;

		if (age < 14) {
			discount = 15;
		}
		else {
			discount = 0;
		}
	}

	//getter Maximum Price

	int getMaximumPrice()
	{
		return this->maximumPrice;
	}

	//setter Maximum Price

	void setMaximumPrice(int maximumPrice)
	{
		if (maximumPrice > 0)
		{
			this->maximumPrice = maximumPrice;
		}
		else
		{
			throw ("invalid price");
		}
	}

	//getter Name

	string getPersonName() {
		return this->personName;
	}


	//setter Name


	void setPersonName(string personName)
	{
		
		if (personName.size() < 1) {
			throw exception("insufficient information");

		}
		else { 
			this->personName = personName;
		}
	}

	//company
	string getCompany() const {
		return company;
	}


	




	// overloading of operator =
	Ticket& operator=(const Ticket& ticket) {
		if (this != &ticket) {
			
			this->age = ticket.age;
			this->personName = ticket.personName;
			this->maximumPrice = ticket.maximumPrice;

			if (ticket.price != nullptr)
			{
				this->price = new int[ticket.maximumPrice];
				for (int i = 0; i < this->maximumPrice; i++)
				{
					this->price[i] = ticket.price[i];
				}
			}
			else
			{
				this->price = nullptr;
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


	




	//a method that prints the price of the ticket
	void showPrice()
	{
		cout << "This event will be provided by the company: " << this->company << "\n";

		if (this->id != nullptr)
		{
			
			
				cout << "Your id is" << this->id<<"associated with the name "<<this->personName<<"\n";
			
		}
		if (this->price != nullptr)
		{
			for (int i = 0; i < this->maximumPrice; i++)
			{
				cout << "The price for this ticket is " << this->price[i];
				cout<< " The maximum price for this event is " << this->maximumPrice;
			}
		}
	}

	//[] operator
	int operator[](int index)
	{
		if (id != 0 && index >= 0 && index < strlen(this->id) + 1)
		{
			return id[index];
		}
		else throw exception("invalid index");
	}

	

	//pre decrement operator
	Ticket& operator--() {
		if (this->price != nullptr) {
			this->price[1]--;
		}
		return *this;
	}

	//post decrement operator 
	Ticket operator--(int i) {
		Ticket copy = *this;
		if (this->price != nullptr) {

			this->price[1]--;
		}
		return copy;
	}

	//== operator 
	bool operator==(const Ticket& ticket) {
		if (this->maximumPrice == ticket.maximumPrice && this->price == ticket.price && strcmp(this->id, ticket.id) == 0)
			return true;
		else
			return false;
	}

	

	friend istream& operator>>(istream& console, Ticket& ticket);
	friend ostream& operator<<(ostream& console, const Ticket& ticket);
	
	// << operator
	friend ostream& operator<<(ostream& console, const Ticket& ticket)
	{
		console << "Person name:" << ticket.personName;
		console << "Id: " << ticket.id;
		console << "Age:" << ticket.age;
		
		return console;
	}

	
	// >> operator 
	friend istream& operator>>(istream& console, Ticket& ticket) {
		cout << "Person name:";
		console >> ticket.personName;

		
		cout << "ticket ID: ";
		console >> ticket.id;

		cout << "Age: ";
		console >> ticket.age;

		
		return console;
	}


	

};

// initializing static variables

int Ticket::discount = 25;
