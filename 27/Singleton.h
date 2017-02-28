#pragma once

class Singleton {

private:
	static Singleton* instance;
	int balance;

	Singleton();
	Singleton(const Singleton&);
	Singleton& operator=(Singleton const&);

public:
	static Singleton* getInstance();
	int getBalance();
	void addMoney(int);
	int takeMoney(int);
	void setMoney(int);
};