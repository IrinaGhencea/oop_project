#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Ticket {
private:
	int* price; //dynamically defined array of numbers
	int maximumNumber;
	string id; 
	string personName;
	int age; 
    const string company;
	

	static int discount;
	
public:


	//default constructor
	Ticket(): company("iaBilet") {
		this->price = nullptr;
		this->id = "";
		this->personName = "";
		this->age = 0;
		this->maximumNumber = 0;
		


		
	}


	//1st constructor with parameters
	Ticket(string company, string personName, string id) :company(company)
	{   
		this->personName = personName;
		this->id = id;
	}


	//2nd constructor with parameters
	Ticket(int* price, string personName,string company, int age, int maximumNumber, string id) : company(company)
	{
		if (price != nullptr)
		{
			this->price= new int[maximumNumber];
			for (int i = 0; i < maximumNumber; i++)
			{
				this->price[i] = price[i];
			}
		}
		else
		{
			this->price = nullptr;
		}

		this->age = age;
		this->maximumNumber = maximumNumber;
		this->personName = personName;

		this->id = id;
		price++;
	}






	//copy constructor 
	Ticket(const Ticket& ticket) : company(ticket.company) {
		this->personName = ticket.personName;
		this->age = ticket.age;
		this->maximumNumber = ticket.maximumNumber;
		this->id = ticket.id;
		

		if (ticket.price != nullptr) {
			this->price = new int[this->maximumNumber];
			for (int i = 0; i < this->maximumNumber; i++) {
				this->price[i] = ticket.price[i];
			}
		}
		
	}

		



	

	//destructor
	~Ticket()
	{
		if (this->price != nullptr)
		{
			delete[] this->price;
		}

	
	}



	//getter Price
	int* getPrice()
	{
		int* copy;
		if (this->price != nullptr)
		{
			copy = new int[this->maximumNumber];
			for (int i = 0; i < this->maximumNumber; i++)
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
			this->price = new int[this->maximumNumber];
			for (int i = 0; i < this->maximumNumber; i++)
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

	string getId()
	{
		return this->id;
	}

	//setter Id

	void setId(string id)
	{
		this->id = id;
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

	int getmaximumNumber()
	{
		return this->maximumNumber;
	}

	//setter Maximum Price

	void setmaximumNumber(int maximumNumber)
	{
		if (maximumNumber > 0)
		{
			this->maximumNumber = maximumNumber;
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
			this->maximumNumber = ticket.maximumNumber;
			this->id = ticket.id;

			if (ticket.price != nullptr)
			{
				this->price = new int[ticket.maximumNumber];
				for (int i = 0; i < this->maximumNumber; i++)
				{
					this->price[i] = ticket.price[i];
				}
			}
			else
			{
				this->price = nullptr;
			}


			
		}
		return *this;
	}


	



	//a method that prints the price of the ticket
	void showPrice()
	{
		cout << "This event will be provided by the company: " << this->company << "\n";

		
			
			
	    cout << "Your id is " << this->id<<" associated with  "<<this->personName<<"\n";
			
		
		if (this->price != nullptr)
		{
			for (int i = 0; i < this->maximumNumber; i++)
			{
				cout << "The price for this ticket is " << this->price[i] << '\n';
				cout<< " The maximum number of tickets for this event is " << this->maximumNumber << '\n';
			}
		}
	}

	int priceWithDiscount(int age) {
		
		if (age < 14) {
			price[0] = price[0] - Ticket::discount;
			
		}
		return price[0];
	}

	//[] operator
	int operator[](int index)
	{
		if (price != nullptr && index >= 0 )
		{
			return price[index];
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
		if (this->maximumNumber == ticket.maximumNumber && this->price == ticket.price)
			return true;
		else
			return false;
	}

	//binary files

	void saveInBfile() {
		ofstream f("Ticket.bin", ios::out | ios::binary);
		

			unsigned length = personName.length();
			const char* ca = personName.c_str();

			f.write((char*)&length, sizeof(length));
			f.write(ca, length + 1);
			

			

			f.close();
		
	}


	void readFromBfile() {
		ifstream f("Ticket.bin", ios::in | ios::binary);
		
		unsigned length = 0;
		f.read((char*)&length, sizeof(length));
		char* n = new char[length + 1];
		f.read(n, length + 1);
		personName = n;
		delete[] n;
		
		
	}

	

	friend istream& operator>>(istream& console, Ticket& ticket);
	friend ostream& operator<<(ostream& console, const Ticket ticket);
	friend ofstream& operator<<(ofstream& fout, const Ticket& ticket);
	friend ifstream& operator>>(ifstream& fin, Ticket& ticket);
	
	


	

};

// initializing static variables

int Ticket::discount = 5;


//<< operator 
ostream& operator<<(ostream& console, const Ticket ticket)
{
	console << " Person name:" << ticket.personName << "\n";
	console << " Id: " << ticket.id << '\n';
	console << " Minimum age:" << ticket.age << '\n';

	return console;
}

// >> operator 
istream& operator>>(istream& console, Ticket& ticket) {
	cout << " Person name:" << '\n';
	console >> ticket.personName;


	cout << " ticket ID: " << '\n';

	char buffer[100];
	console.getline(buffer, 100);
	console.clear();
	ticket.setId(buffer);
	cout << "Minimum age: " << ticket.age << '\n';





	return console;
}




ofstream& operator<<(ofstream& fout, const Ticket& ticket) {
	fout << ticket.personName << endl;

	return fout;
}

ifstream& operator>>(ifstream& fin, Ticket& ticket) {
	getline(fin, ticket.personName);
	return fin;
}


//virtual method

 class EventInformation {
 public:
	 virtual void showEventCategory() = 0;

	 virtual ~EventInformation() {}
 };

 class ArtisticEventInformation : public EventInformation {
 public:
	
	 void showEventCategory() {
		 cout << " You can buy a ticket for a concert or a movie here. " << "\n";
	 }
 };

 
 class SportsEventInformation : public EventInformation {
 public:
	
	 void showEventCategory() {
		 cout << " You can buy a ticket for a sports event here. " << "\n";
	 }
 };