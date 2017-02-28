#include "stdafx.h"
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "Singleton.h"
using namespace std;

int main(int argc, char* argv[])
{
	Catch::Session().run(argc, argv);
	getchar();
	return 0;
}

TEST_CASE("Addition"){
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int a = rand() % 10;
		sum += a;
		Singleton::getInstance()->addMoney(a);
		CHECK(Singleton::getInstance()->getBalance() == sum);
	}
}

TEST_CASE("Subtraction"){
	int sum = 100;
	Singleton::getInstance()->setMoney(100);
	for (int i = 0; i < 5; i++) {
		int a = rand() % 10;
		sum -= a;
		int take = Singleton::getInstance()->takeMoney(a);
		CHECK(take == a);
		CHECK(Singleton::getInstance()->getBalance() == sum);
	}
}

TEST_CASE("Subtraction not enough balance"){
	for (int i = 0; i < 5; i++){
		int a = 100 + rand() % 100;
		Singleton::getInstance()->setMoney(a);
		int take = Singleton::getInstance()->takeMoney(200);
		CHECK(take == a);
		CHECK(Singleton::getInstance()->getBalance() == 0);
	}
}

TEST_CASE("Set negative"){
	for (int i = 0; i < 5; i++){
		int a = -100 + rand() % 10;
		Singleton::getInstance()->setMoney(a);
		CHECK(Singleton::getInstance()->getBalance() == 0);
	}
}