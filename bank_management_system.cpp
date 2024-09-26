//
// Created by Gabija J on 26.09.24.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib> //for generating a series of random numbers

using namespace std;

struct makeAccount {
   int idNumber;
   string name;
   double balance;
   char type;
};

void createAccount(string name, double balance, char type) {
   makeAccount account;
   account.name = name;
   account.balance = balance;
   account.type = type;
   //account.idNumber = rand()-rand()*10;

}

void displayMenu() {
   cout << "\n\t\t\t#######################" << endl;
   cout << "\t\t\tBank Management System" << endl;
   cout << "\t\t\t#######################" << endl;
   cout << "\t\t\t\tMain Menu:" << endl;
   cout << "\t\t\t1. Create New Account" << endl;
   cout << "\t\t\t2. Deposit Money" << endl;
   cout << "\t\t\t3. Withdraw Money" << endl;
   cout << "\t\t\t4. Check Balance" << endl;
   cout << "\t\t\t5. Account List" << endl;
   cout << "\t\t\t6. Exit" << endl;
}

int main() {
   char choice;
   displayMenu();
   cin >> choice;
   switch (choice) {
      case '1':
         cout << "1";
      break;
      case '2':
         cout << "2";
      break;
      case '3':
         cout << "3";
      break;
      case '4':
         cout << "4";
      break;
      case '5':
         cout << "5";
      break;
      case '6':
         cout << "Thank you. Goodbye!";
      break;
      default:
         cout << "Invalid choice." << endl;
      displayMenu();
      break;
   }
}
