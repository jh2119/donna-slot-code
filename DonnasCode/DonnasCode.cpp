// DonnasCode.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

const int PULL = 1440;
const int SIZE = 7;

int winningNum(int winNum);
double acceptBets(double bet);
void addToJackpot(double jackpot, double bet, double plusJackpot);
void payOut(double bet, double jackpot, double totalJackpot, double moneyPaidOut);
int playerNum(int playNum);
void endOfDay(double finalTotal, double moneyPaidOut, double finalJackpot, double plusJackpot);
void printWin(ofstream& outFile, double totalJackpot);
void print(ofstream& outFile, double jackpot, double bet, int setWinNum, int playerNum);
void printEnd(ofstream& outFile, double finalTotal, double moneyPaidOut, double finalJackpot);

int main() {
  // Write your main here
  ofstream outFile;
  outFile.open("resultFile");
  if (!outFile.is_open())
  {
    cout << "outfile is not open" << endl;
  }

  int num;
  double allJackpot;
  double endTotal;
  double endPaidOut;
  double endJackpot;

  winningNum(num);

  for (int p = 0; p <= PULL; p++)
  {
    int num;
    int pNum;
    double betMade;
    double theJackpot;
    double money = 10000.00;
    double allJackpot;

    acceptBets(betMade);
    addToJackpot(money, betMade, allJackpot);
    playerNum(pNum);
    if (pNum == num)
    {
      payOut(betMade, money, theJackpot, endPaidOut);
      cout << "You WIN!: $" << theJackpot << endl;
      playerNum(pNum);
      winningNum(num);
      printWin(outFile, theJackpot);
    }
    else
      cout << "Try your luck and pull again!" << endl;
    print(outFile, allJackpot, betMade, num, pNum);
  }

  endOfDay(endTotal, endPaidOut, endJackpot, allJackpot);
  printEnd(outFile, endTotal, endPaidOut, endJackpot);

  return 0;
}

void printWin(ofstream& outFile, double totalJackpot)
{
  outFile << "Winning jackpot: " << totalJackpot << endl;
  outFile << "*********************" << endl << endl;
}

void print(ofstream& outFile, double plusJackpot, double bet, int winNum, int playNum)
{
  outFile << "The amount of the jackpot: $" << plusJackpot << endl;
  outFile << "The current bet: $" << bet << endl;
  outFile << "The winning number is: " << winNum << endl;
  outFile << "The players number is: " << playNum << endl;
  outFile << "***********************" << endl << endl;
}

void printEnd(ofstream& outFile, double finalTotal, double moneyPaidOut, double finalJackpot)
{
  outFile << "The final amount in the jackpot: $" << finalJackpot << endl;
  outFile << "The final amount paid out to winners: $" << moneyPaidOut << endl;
  outFile << "The total amount the casino made/losed: $" << finalTotal << endl;
  outFile << "***********************" << endl;
}

void endOfDay(double finalTotal, double moneyPaidOut, double finalJackpot, double plusJackpot)
{
  finalJackpot = plusJackpot - 10000.00;//seed money subtracted
  finalTotal = finalJackpot - moneyPaidOut;
}

int winningNum(int winNum)
{
  //start at beginning of day with "else" and after payOut with if statement.
  if (payOut > 0)
  {
    srand(time(0));
    winNum = (rand() % 999) + 1;
  }
  else
  {
    srand(time(0));
    winNum = (rand() % 999) + 1;
  }
  return winNum;
}

double acceptBets(double bet)
{
  int rIndex;
  double wagerAmts[SIZE] = { 1.00, 5.00, 10.00, 20.00, 50.00, 100.00, 1000.00 };
  srand(time(0));
  rIndex = rand() % 7 + 1;
  bet = wagerAmts[rIndex];

  return bet;
}

void addToJackpot(double jackpot, double bet, double plusJackpot)
{

  if (bet == 1.00)
  {
    jackpot = jackpot + 1.00;
  }
  else if (bet == 5.00)
  {
    jackpot = jackpot + 5.00;
  }
  else if (bet == 10.00)
  {
    jackpot = jackpot + 10.00;
  }
  else if (bet == 20.00)
  {
    jackpot = jackpot + 20.00;
  }
  else if (bet == 50.00)
  {
    jackpot = jackpot + 50.00;
  }
  else if (bet == 100.00)
  {
    jackpot = jackpot + 100.00;
  }
  else if (bet == 1000.00)
  {
    jackpot = jackpot + 1000.00;
  }

  plusJackpot = plusJackpot + jackpot;

}

void payOut(double bet, double jackpot, double totalJackpot, double moneyPaidOut)
{
  double jackpot1, jackpot2, jackpot3, jackpot4, jackpot5, jackpot6;

  jackpot1 = (jackpot * .01) / 100;
  jackpot2 = (jackpot * .05) / 100;
  jackpot3 = (jackpot * 1) / 100;
  jackpot4 = (jackpot * 2) / 100;
  jackpot5 = (jackpot * 5) / 100;
  jackpot6 = (jackpot * 10) / 100;

  if (bet == 1.00)
  {
    if (jackpot1 > 100.00)
      totalJackpot = jackpot1;
    else
      totalJackpot = 100.00;
  }
  else if (bet == 5.00)
  {
    if (jackpot2 > 500.00)
      totalJackpot = jackpot2;
    else
      totalJackpot = 500.00;
  }
  else if (bet == 10.00)
  {
    if (jackpot3 > 1000.00)
      totalJackpot = jackpot3;
    else
      totalJackpot = 1000.00;
  }
  else if (bet == 20.00)
  {
    if (jackpot4 > 2000.00)
      totalJackpot = jackpot4;
    else
      totalJackpot = 2000.00;
  }
  else if (bet == 50.00)
  {
    if (jackpot5 > 5000.00)
      totalJackpot = jackpot5;
    else
      totalJackpot = 5000.00;
  }
  else if (bet == 100.00)
  {
    if (jackpot6 > 10000.00)
      totalJackpot = jackpot6;
    else
      totalJackpot = 10000.00;
  }
  else if (bet == 1000.00)
  {
    if (jackpot > 100000.00)
      totalJackpot = jackpot;
    else
      totalJackpot = 100000.00;
  }
  moneyPaidOut = moneyPaidOut + totalJackpot;
}

int playerNum(int playNum)
{
  srand(time(0));
  playNum = (rand() % 999) + 1;
  return playNum;
}