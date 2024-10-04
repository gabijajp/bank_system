//
// Created by Gabija J on 26.09.24.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Account {
   int idNumber;
   string firstName;
   string lastName;
   double balance;
   char type;

   void displayInfo() {
      fstream writeFile;
      writeFile.open("accounts.cvs", ios::out | ios::app); //Writes at the end of the file
      if (writeFile.is_open()) {
         writeFile << idNumber << ", "
                   << firstName << ", "
                   << lastName << ", "
                   << balance << ", "
                   << type
                   << "\n";
         writeFile.close();
      } else {
         cout << "Unable to open file" << endl;
      }
   }

   };

char displayMenu();
void createAccount();
void checking(char function);
void actionWithMoney(char function);
void moneyBalance();

int main() {
   char choice = displayMenu();
   do {
      switch (choice) {
         case '1':
            createAccount();
            choice = displayMenu();
            break;
         case '2':
            checking(*"d");
            choice = displayMenu();
            break;
         case '3':
            checking(*"w");
            choice = displayMenu();
            break;
         case '4':
            choice = displayMenu();
            break;
         case '5':
            cout << "Account list";
            choice = displayMenu();
            break;
         case '6':
            cout << "Thank you. Goodbye!" << endl;
            break;
         default:
            cout << "Invalid choice." << endl;
            choice = displayMenu();
            break;
      }
   } while (choice <'6' || choice >'6');
}

char displayMenu() {
   char choice;
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
   cin >> choice;
   return choice;
}

void createAccount() {
   Account accounts;
   cout << "Enter your first name: ";
   cin>>accounts.firstName;
   cout << "Enter your last name: ";
   cin>>accounts.lastName;
   cout << "Enter your balance: ";
   cin>>accounts.balance;
   cout << "Enter your bank account type (c-checking or s-savings): ";
   cin>>accounts.type;
   cout << "Enter your ID number: ";
   cin>>accounts.idNumber;
   accounts.displayInfo();
}

void checking(char function) {
   char answer;
   cout << "Do you have an account?(y/n): ";
   cin >> answer;
   if(answer == 'y' || answer == 'Y') {
      actionWithMoney(function);
   }
   else if (answer == 'n' || answer == 'N') {
      cout << "Let's create an account for you." << endl;
      createAccount();
   }
   else {
      cout << "Invalid choice." << endl;
   }
}

void actionWithMoney(char function) {
   int givenIdNum, idNumber, list_size, i;
   double money;
   vector <string> list;
   string line, word;
   cout << "Enter you ID number: ";
   cin >> givenIdNum;
   if (function == 'd') cout << "Enter amount of money you'd like to deposit: ";
   if (function == 'w') cout << "Enter amount of money you'd like to withdraw: ";
   cin >> money;
   fstream readFile, updateFile;
   readFile.open("accounts.cvs", ifstream::in);
   updateFile.open("accountsnew.cvs", ofstream::out);
   if (readFile.good()) {
      while (!readFile.eof()) {
         list.clear();
         getline(readFile, line); //gets line from .cvs file
         stringstream s(line); //breaks the line into words
         while(getline(s, word, ',')) {
            list.push_back(word);
         }
         idNumber = stoi(list[0]);
         list_size = list.size();
         if (givenIdNum == idNumber) {
            if (function == 'd') money += stoi(list[3]); // changes string to int and adds
            if (function == 'w') money = stoi(list[3]) - money; // changes string to int and subtracts
            stringstream changeBalance;
            changeBalance << money;
            list[3] = changeBalance.str(); //changes double to string
            for (i = 0; i < list_size - 1; i++) {
               updateFile << list[i] << ", ";
            }
            updateFile << list[list_size - 1] << "\n";
         } else {
            for (i = 0; i < list_size - 1; i++) {
               updateFile << list[i] << ", ";
            }
            updateFile << list[list_size - 1] << "\n";
         }
      }
      readFile.close();
      updateFile.close();
      remove("accounts.cvs"); //removing old file
      rename("accountsnew.cvs", "accounts.cvs"); //renaming updated file to old file's name
   }
}

void moneyBalance() {
   cout << "Balance ";
}
