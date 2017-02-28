#include "stdafx.h"
#include "Singleton.h"

Singleton* Singleton::instance = nullptr;

Singleton::Singleton(){
	balance = 0;
}

Singleton* Singleton::getInstance(){
	if (!instance) {
		//new Singleton();
		instance = new Singleton();
	}
	return instance;
}

int Singleton::getBalance(){
	return balance;
}

void Singleton::addMoney(int amount){
	balance += amount;
}

int Singleton::takeMoney(int amount){
	int res = balance >= amount ? amount : balance;
	balance -= res;
	return res;
}

void Singleton::setMoney(int amount){
	balance = amount < 0 ? 0 : amount;
}