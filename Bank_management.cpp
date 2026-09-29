#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// ACCOUNT CLASS 
class Account {
	
private:
    int accountNumber;
    string name;
    string cnic;
    double balance;
    int pin;

public:
    Account(int accNo, string n, string c, int p, double b = 0)
    {
        accountNumber = accNo;
        name = n;
        cnic = c;
        pin = p;
        balance = b;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    int getPin()
    {
        return pin;
    }

    void displayAccount()
    {
        cout << " ACCOUNT DETAILS"<<endl;
        cout << "Account No : " << accountNumber << endl;
        cout << "Name       : " << name << endl;
        cout << "CNIC       : " << cnic << endl;
        cout << "Balance    : " << balance << endl;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit Successful!"<<endl;
        }
        else
        {
            cout << "Invalid Amount!"<<endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful!"<<endl;
        }
        else
        {
            cout << "Insufficient Balance or Invalid Amount!"<<endl;
        }
    }

    double getBalance()
    {
        return balance;
    }
};

// BANK CLASS 
class Bank {
private:
    vector<Account> accounts;
    int nextAccountNo = 1001;

public:

    void createAccount()
    {
        string name, cnic;
        int pin;

        cout << "Enter Name: "<<endl;
        cin >> name;

        cout << "Enter CNIC: "<<endl;
        cin >> cnic;

        cout << "Set 4-digit PIN: "<<endl;
        cin >> pin;

        Account newAcc(nextAccountNo, name, cnic, pin, 0);
        accounts.push_back(newAcc);

        cout << "Account Created! Your Account No is: " << nextAccountNo << endl;

        nextAccountNo++;
    }

    Account* login(int accNo, int pin)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNumber() == accNo &&
                accounts[i].getPin() == pin)
            {
                return &accounts[i];
            }
        }
        return NULL;
    }

    void adminViewAll()
    {
        cout << "ALL ACCOUNTS "<<endl;

        for (int i = 0; i < accounts.size(); i++)
        {
            accounts[i].displayAccount();
        }
    }
};

// MAIN 
int main()
{
    Bank bank;
    int choice;

    while (true)
    {
        cout << " BANK SYSTEM"<<endl;
        cout << "1. Create Account"<<endl;
        cout << "2. Login"<<endl;
        cout << "3. Admin View All Accounts"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

        if (choice == 1)
        {
            bank.createAccount();
        }
        else if (choice == 2)
        {
            int accNo, pin;
            cout << "Enter Account No: "<<endl;
            cin >> accNo;

            cout << "Enter PIN: "<<endl;
            cin >> pin;

            Account* user = bank.login(accNo, pin);

            if (user != NULL)
            {
                int c;

                do
                {
                    cout << " CUSTOMER MENU "<<endl;
                    cout << "1. Deposit"<<endl;
                    cout << "2. Withdraw"<<endl;
                    cout << "3. Check Balance"<<endl;
                    cout << "4. View Account"<<endl;
                    cout << "5. Logout"<<endl;
                    cout << "Enter choice: "<<endl;
                    cin >> c;

                    if (c == 1)
                    {
                        double amt;
                        cout << "Enter amount: "<<endl;
                        cin >> amt;
                        user->deposit(amt);
                    }
                    else if (c == 2)
                    {
                        double amt;
                        cout << "Enter amount: "<<endl;
                        cin >> amt;
                        user->withdraw(amt);
                    }
                    else if (c == 3)
                    {
                        cout << "Balance: " << user->getBalance() << endl;
                    }
                    else if (c == 4)
                    {
                        user->displayAccount();
                    }

                } while (c != 5);
            }
            else
            {
                cout << "Invalid Credentials!"<<endl;
            }
        }
        else if (choice == 3)
        {
            bank.adminViewAll();
        }
        else if (choice == 4)
        {
            cout << "Exiting..."<<endl;
            break;
        }
    }

    return 0;
}
