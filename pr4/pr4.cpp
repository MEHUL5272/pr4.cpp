#include<iostream>
using namespace std;

class BankAccount
{
		protected:
		    int accountNumber;
		    string accountHolderName;
		    float balance;
		
		public:
		
		    BankAccount(int accNo, string name, float bal)
		    {
		        accountNumber = accNo;
		        accountHolderName = name;
		        balance = bal;
		    }
		
		    void deposit(float amount)
		    {
		        balance += amount;
		        cout << "Amount Deposited Successfully!\n";
		    }
		
		    virtual void withdraw(float amount)
		    {
		        if(amount <= balance)
		        {
		            balance -= amount;
		            cout << "Withdrawal Successful! \n";
		        }
		        else
		        {
		            cout << "Insufficient Balance! \n";
		        }
		    }
		
		    float getBalance()
		    {
        		return balance;
			}

		    virtual void displayAccountInfo()
		    {
		        cout << "Account Number:-  \n" << accountNumber;
		        cout << "Name:- \n" << accountHolderName;
		        cout << "Balance:-  \n" << balance << endl;
		    }
		
		    virtual void calculateInterest()
		    {
		        cout << "No Interest for this Account \n";
		    }
};
class SavingsAccount : public BankAccount
{
		private:
		    float interestRate;
		
		public:
		    SavingsAccount(int accNo, string name, float bal, float rate)
		    : BankAccount(accNo, name, bal)
		    {
		        interestRate = rate;
		    }
		
		    void calculateInterest()
		    {
		        float interest = balance * interestRate / 100;
		        cout << "Savings Interest:- \n" << interest << endl;
		    }
};
class CheckingAccount : public BankAccount
{
		private:
		    float overdraftLimit;
		
		public:
		    CheckingAccount(int accNo, string name, float bal, float limit)
		    : BankAccount(accNo, name, bal)
		    {
		        overdraftLimit = limit;
		    }
		
		    void withdraw(float amount)
		    {
		        if(amount <= balance + overdraftLimit)
		        {
		            balance -= amount;
		            cout << "Withdrawn with Overdraft! \n";
		        }
		        else
		        {
		            cout << "Overdraft Limit Exceeded! \n";
		        }
		    }
};
class FixedDepositAccount : public BankAccount
{
		private:
		    int term;
		    float rate;
		
		public:
		    FixedDepositAccount(int accNo, string name, float bal, int t, float r)
		    : BankAccount(accNo, name, bal)
		    {
		        term = t;
		        rate = r;
		    }
		
		    void calculateInterest()
		    {
		        float interest = (balance * rate * term) / 100;
		        cout << "FD Interest:-  \n" << interest << endl;
		    }
};
int main()
{
    int choice;

    SavingsAccount sa(101, "Mehul", 5000, 5);
    CheckingAccount ca(102, "Payal", 3000, 2000);
    FixedDepositAccount fd(103, "Mp", 10000, 12, 6);

    BankAccount* acc;

    do
    {
        cout << "\n--- BANK MENU ---\n";
        cout << "1. Savings Account \n";
        cout << "2. Checking Account \n";
        cout << "3. Fixed Deposit Account \n";
        cout << "4. Exit \n";
        cout << "Enter choice:- ";
        cin >> choice;

        switch(choice)
        {
            case 1: acc = &sa; break;
            case 2: acc = &ca; break;
            case 3: acc = &fd; break;
            case 4: exit(0);
            default: cout << "Invalid Choice \n"; continue;
        } 

        int op;
        
	        cout << "1. Deposit \n";
			cout << "2. Withdraw \n";
			cout << "3. Balance \n";
			cout << "4. Display \n";
			cout << "5. Interest \n";
			cout << "Enter option:- ";
	        cin >> op;

        float amt;

        switch(op)
        {
            case 1:
                cout << "Enter amount: ";
                cin >> amt;
                acc->deposit(amt);
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amt;
                acc->withdraw(amt);
                break;

            case 3:
                cout << "Balance: " << acc->getBalance() << endl;
                break;

            case 4:
                acc->displayAccountInfo();
                break;

            case 5:
                acc->calculateInterest(); 
                break;

            default:
                cout << "Invalid Option \n";
        }
    } while(true);

    return 0;
}
