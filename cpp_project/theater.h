#pragma once

#include <iostream>
#include <string>


 using namespace std;


class Theater {

private:
	char* name = nullptr;
	int numberSeat = 0;
	int numberRow = 0;

	static int min_number_seats;
	static int max_number_seats;
	static int number_rows;

public: 
	//default constructor
	Theater() {
		this->numberSeat = 0;
		this->numberRow = 0;
		this->name = nullptr;

	}

	//constructor with parameters
	Theater(const char* name, int numberSeat, int numberRow) {
		this->numberSeat = numberSeat;
		this->numberRow = numberRow;
		if (name != nullptr) {
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);

		}
	}

	//copy constructor 
	Theater(const Theater& play) {
		this->numberSeat= play.numberSeat;
		this->numberRow = play.numberRow;
		if (play.name != nullptr)
		{
			this->name = new char[strlen(play.name) + 1];
			strcpy(this->name, play.name);
		}
		else
		{
			this->name = nullptr;
		}
	}

  //getters

	int getNumberSeat() {
		return this->numberSeat;
	}

	int getNumberRow() {
		return this->numberSeat;
	}



	char* getName() {
		return this->name;
	}


	//setters
	void setNumberSeat(int numberSeat) {
		if (numberSeat < Theater::max_number_seats || numberSeat > Theater::min_number_seats) {
			this->numberSeat = numberSeat;
		}
		else {
			throw exception("Invalid");
		}
	}

	void setNumberRow(int numberRow) {
		if (numberRow < Theater::number_rows) {
			this->numberRow = numberRow;
		}
		else {
			throw exception("Invalid");
		}
	}

	void setName(const char* name) {
		if (this->name != nullptr) {
			delete[] this->name;

		}
		if (name != nullptr || strlen(name) < 15) {
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);


		}
		else {
			this->name = nullptr;
		}
	}

	//overloading of operator =
	Theater& operator=(const Theater& play)
	{
		if (this != &play)
		{
			this->numberSeat = play.numberSeat;
			this->numberRow = play.numberRow;
			if (this->name != nullptr)
			{
				delete[] this->name;
			}

			if (play.name != nullptr)
			{
				this->name = new char[strlen(play.name)+1];
				strcpy(this->name, name);
			}
			else
			{
				this->name = nullptr;
			}
		}

		return *this;
	}

	//a method that prints the name, number of seats and the number of rows
	void showPlay()
	{
		if (this->name != nullptr)
		{
			cout << "The play is " << this->name << '\n';
		}
		
		cout << "The number of seats that have been occupied is:" << this->numberSeat<<'\n';
		cout << "The number of rows that have been occupied is:" << this->numberRow << '\n';
		
	}


};


int Theater::min_number_seats = 15;
int Theater::max_number_seats = 350;
int Theater::number_rows = 20;


int main() {
	Theater t;
	t.setName("Teatrul Caragiale");



};
