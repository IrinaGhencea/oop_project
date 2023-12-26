#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;



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
			
			
				cout << "Your id is " << this->id<<" associated with the name "<<this->personName<<"\n";
			
		}
		if (this->price != nullptr)
		{
			for (int i = 0; i < this->maximumPrice; i++)
			{
				cout << "The price for this ticket is " << this->price[i] << '\n';
				cout<< " The maximum number of tickets for this event is " << this->maximumPrice << '\n';
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


	void saveInBfile() {
		ofstream fout("ticket.bin", ios::out | ios::binary);

		unsigned length = strlen(id);
		fout.write((char*)&length, sizeof(length));
		fout.write(id, length + 1);
		fout.write((char*)&age, sizeof(age));
		fout.write((char*)&maximumPrice, sizeof(maximumPrice));

		fout.close();
	}
	

	void readFromBfile() {
		ifstream fin("ticket.bin", ios::in | ios::binary);

		unsigned length = 0;
		fin.read((char*)&length, sizeof(length));
		char* n = new char[length + 1];
		fin.read(n, length + 1);

		id = n;
		delete[] n;
		fin.read((char*)&age, sizeof(age));
		fin.read((char*)&maximumPrice, sizeof(maximumPrice));

		fin.close();
	}

	friend istream& operator>>(istream& console, Ticket& ticket);
	friend ostream& operator<<(ostream& console, const Ticket ticket);

	friend ofstream& operator<<(ofstream& fout, const Ticket& ticket);
	friend  ifstream& operator>>(std::ifstream& fin, Ticket& ticket);
	
	


	

};

// initializing static variables

int Ticket::discount = 25;


// << operator
ostream& operator<<(ostream& console, const Ticket ticket)
{
	console << " Person name:" << ticket.personName << "\n";
	console << "Id: " << ticket.id << '\n';
	console << "Age:" << ticket.age << '\n';

	return console;
}


// >> operator 
 istream& operator>>(istream& console, Ticket& ticket) {
	cout << "Person name:" << '\n';
	console >> ticket.personName;


	cout << "ticket ID: " << '\n';

	char buffer[100];
	console.getline(buffer, 100);
	console.clear();
	ticket.setId(buffer);
	cout<<"age: "<< ticket.age << '\n';





	return console;
}

 ofstream& operator<<(ofstream& fout, const Ticket& ticket) {
	 unsigned length = strlen(ticket.id);
	 fout.write((char*)&length, sizeof(length));
	 fout.write(ticket.id, length + 1);
	 fout.write((char*)&ticket.age, sizeof(ticket.age));
	 fout.write((char*)&ticket.maximumPrice, sizeof(ticket.maximumPrice));
	 return fout;
 }

 ifstream& operator>>(std::ifstream& fin, Ticket& ticket) {
	 unsigned length = 0;
	 fin.read((char*)&length, sizeof(length));
	 char* n = new char[length + 1];
	 fin.read(n, length + 1);
	 ticket.id = n;
	 delete[] n;
	 fin.read((char*)&ticket.age, sizeof(ticket.age));
	 fin.read((char*)&ticket.maximumPrice, sizeof(ticket.maximumPrice));
	 return fin;
 }


 class EventInfo {
 public:
	 virtual void displayEventType() const = 0;

	 virtual ~EventInfo() {}
 };

 class ArtisticEventInfo : public EventInfo {
 public:
	
	 void displayEventType() const override {
		 cout << "This is a concert or a movie." << "\n";
	 }
 };

 
 class SportsEventInfo : public EventInfo {
 public:
	
	 void displayEventType() const override {
		 cout << "This is a sports event." << "\n";
	 }
 };