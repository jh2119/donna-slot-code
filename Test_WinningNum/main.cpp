// DonnasCode.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

int winningNum() {
  int winningNumber = 0;

  winningNumber = (rand() % 999) + 1;

  return winningNumber;
}


int main() {

  // do once!
  srand(time(0));

  for (int index = 0; index < 50; index++) {
    std::cout << winningNum() << "\t";
  }

  return 0;
}