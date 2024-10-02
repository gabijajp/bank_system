//
// Created by Gabija J on 26.09.24.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct Account {
   int idNumber;
   string firstName;
   string lastName;
   double moneyBalance;
   char type;

   void displayInfo() {
      ofstream writeFile;
      writeFile.open("accounts.txt", ofstream::app); //Writes at the end of the file
      if (writeFile.is_open()) {
         writeFile << idNumber << " " << firstName << " " << lastName << " " << moneyBalance << " " << type << endl;
         writeFile.close();
      } else {
         cout << "Unable to open file" << endl;
      }
   }

   void changeInfo() {
      ofstream writeFile;
      writeFile.open("accounts.txt", ofstream::out);
      if (writeFile.is_open()) {
         writeFile << idNumber << " " << firstName << " " << lastName << " " << moneyBalance << " " << type << endl;
         writeFile.close();
      } else {
         cout << "Unable to open file" << endl;
      }
   }
   };

char displayMenu();
void createAccount();
void checking(char function);
void deposit();
void withdraw();
void balance();

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
            checking(*"b");
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
            choice=displayMenu();
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
   cin>>accounts.moneyBalance;
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
      if(function == 'd') deposit();
      if(function == 'w') withdraw();
      if(function == 'b') balance();
   }
   else if( answer == 'n' || answer == 'N') {
      cout << "Create an account by selecting 1 from Main Menu" << endl;
   }
   else {
      cout << "Invalid choice." << endl;
   }
}

void deposit() {
   Account accounts;
   string idNum;
   int sum2=0, sum1=0, givenIdNum;
   double money;
   accounts.idNumber = 0;
   cout << "Enter you ID number: ";
   cin >> givenIdNum;
   cout << "Enter amount of money you'd like to deposit: ";
   cin >> money;
   ifstream readFile;
   readFile.open("accounts.txt", ifstream::in);
   if (readFile.is_open()) {
      while (!readFile.eof()) {
         sum1++;
      }
      while(sum2 != sum1) {
         readFile >> idNum >> accounts.firstName >> accounts.lastName >> accounts.moneyBalance >> accounts.type;
         accounts.idNumber = stoi(idNum); //change string into int
         if(givenIdNum != accounts.idNumber) {
            accounts.changeInfo();
         } else {
            accounts.moneyBalance += money;
            accounts.changeInfo();
         }
         sum2++;
      }
      readFile.close();
   } else {
      cout << "Unable to open file" << endl;
   }
}

void withdraw() {
   cout << "Withdraw ";
}

void balance() {
   cout << "Balance ";
}
