#include <iostream>
#include <stdlib.h>
#include <strings.h>
using namespace std;

class ATM {
private:
    string name;
    long long acc_number;
    double balance;
    string type;
    int passwoard;
    int pin;

public:

    ATM() {
    	cout << "Hello well-Come to our ATM system !" << endl;
    	cout << "|| Please Enter Details of Account Holder ||" << endl << endl;
    	cout << "Enter Account Holder's Name :- "; getline(cin, name);
    	cout << "Enter your Account Number : "; cin >> acc_number;
    	cout << "Enter your Account type : "; cin.ignore(); getline(cin, type);    	
    	cout << "Enter your ultimate PIN : "; cin >> passwoard;
    	balance = 0.0;
    	
    }

    void checkBalance() {
        cout <<"Enter PIN : ";
        cin >> pin;
        if(pin == passwoard){
        cout << "Your balance is: $" << balance << endl;
		}
		else
		{
			cout << "Please enter correct PIN !!" << endl;
		}
    }

    void deposit() {
        double amount;
        cout << "Enter the amount to deposit: $";
        cin >> amount;
        cout <<"Enter PIN : ";
        cin >> pin;
        if(pin == passwoard){
           if (amount > 0) {
               balance += amount;
               cout << "Deposit successful. Your new balance is: $" << balance << endl;
           } 
	   else {
               cout << "Invalid amount. Please enter a positive amount to deposit." << endl;
           }
	}
	else{
	    cout<< "Please enter correct PIN !!" <<endl;
	}
    }

    void withdraw() {
        double amount;
        cout << "Enter the amount to withdraw: $";
        cin >> amount;
        cout <<"Enter PIN : ";
        cin >> pin;
        if(pin == passwoard){
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Your new balance is: $" << balance << endl;
        } 
	else if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive amount to withdraw." << endl;
        } 
	else {
            cout << "Insufficient funds. Your balance is: $" << balance << endl;
        }
        }
        else {
        	cout<< "Please enter correct PIN !!" << endl;
	}
    }
    
    void credentials()
    {
    	cout <<"Enter PIN : ";
        cin >> pin;
        if(pin == passwoard){
    	   cout << "Account Holder Name : " << name << endl;
    	   cout << "Account Number : " << acc_number << endl;
    	   cout << "Account Type : " << type << endl;
    	   cout << "Current Balance : $" << balance << endl;
	}
	else{
	    cout<< "Please enter correct PIN !!" << endl;
	}
	}

    void menu() {
        int choice;
        do {
            cout << "\nATM Menu:" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Display all credentials" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    credentials();
                	break;
                case 5:
                    cout << "Thank you for using the ATM. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    ATM atm;
    atm.menu();
    return 0;
}
