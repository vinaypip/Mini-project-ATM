#include<conio.h>
#include<iostream>
#include<string>
using namespace std;


class atm										// class atm 
{
private:										// private member varibles
	long int account_No;
	string name;
	int PIN;
	double balance;
	string mobile_No;

public:											// public member functions

	// setData function is setting the Data into the private member variables
	void setData(long int account_No_a, const string &name_a, int PIN_a, double balance_a, const string& mobile_No_a)
	{
		account_No = account_No_a;	 // assigning the formal arguments to the private member var's
		name = name_a;
		PIN = PIN_a;
		balance = balance_a;
		mobile_No = mobile_No_a;
	}

	//getAccountNo function is returning the user's account no.
	long int getAccountNo() const
	{
		return account_No;
	}

	//getName function is returning the user's Name
	string getName() const
	{
		return name;
	}

	//getPIN function is returning the user's PIN
	int getPIN()
	{
		return PIN;
	}

	//getBalance is returning the user's Bank Balance
	double getBalance()
	{
		return balance;
	}

	//getMobileNo is returning the user's Mobile No.
	string getMobileNo()
	{
		return mobile_No;
	}

	//setMobile function is Updating the user mobile no
	void setMobile(const string& mob_prev, const string& mob_new)
	{
		if (mob_prev == mobile_No)						// it will check old Mobile no
		{
			mobile_No = mob_new;						// and Update with new, if old matches
			cout << endl << "Sucessfully Updated Mobile no.";
			_getch();				//getch is to hold the screen untill user press any key 																			
		}

		else							// Does not update if old mobile no. does not matches
		{
			cout << endl << "Incorrect !!! Old Mobile no";
			_getch();			  
		}
	}

	//cashWithDraw function is used to withdraw money from ATM
	void cashWithDraw(int amount_a)
	{
		if (amount_a > 0 && amount_a < balance)		// check entered amount validity
		{
			balance -= amount_a;		// balance = balance - amount_a
			cout << endl << "Please Collect Your Cash";
			cout << endl << "Available Balance :" << balance;
			_getch();				
		}

		else
		{
			cout << endl << "Invalid Input or Insufficient Balance";
			_getch();				
		}
	}

};

int main()
{
	int choice = 0;
	int enterPIN;		//enterPIN and enterAccountNo. ---> user authentication
	long int enterAccountNo;

	system("cls");

	// created User ( object )
	atm user1;
	// Set User Details ( into object )         ( Setting Default Data )
	user1.setData(987654321, "Hardik", 1234, 50000, "9370054900");


	void displayWelcomeMessage() {
    system("cls");
    std::cout << "\n****Welcome to ATM*****\n";
}

void displayMainMenu() {
    std::cout << "\n**** Welcome to ATM *****\n";
    std::cout << "\nSelect Options\n";
    std::cout << "1. Check Balance\n";
    std::cout << "2. Cash withdraw\n";
    std::cout << "3. Show User Details\n";
    std::cout << "4. Update Mobile no.\n";
    std::cout << "5. Exit\n";
}

void handleMainMenuChoice(int choice, YourUserClass& user1) {
    int amount = 0;
    std::string oldMobileNo, newMobileNo;

    switch (choice) {
        case 1:
            std::cout << "\nYour Bank balance is: " << user1.getBalance() << "\n";
            _getch();
            break;
        case 2:
            std::cout << "\nEnter the amount: ";
            std::cin >> amount;
            user1.cashWithDraw(amount);
            break;
        case 3:
            std::cout << "\n*** User Details are:-\n";
            std::cout << "-> Account no: " << user1.getAccountNo() << "\n";
            std::cout << "-> Name: " << user1.getName() << "\n";
            std::cout << "-> Balance: " << user1.getBalance() << "\n";
            std::cout << "-> Mobile No.: " << user1.getMobileNo() << "\n";
            _getch();
            break;
        case 4:
            std::cout << "\nEnter Old Mobile No. ";
            std::cin >> oldMobileNo;
            std::cout << "\nEnter New Mobile No. ";
            std::cin >> newMobileNo;
            user1.setMobile(oldMobileNo, newMobileNo);
            break;
        case 5:
            exit(0);
        default:
            std::cout << "\nEnter Valid Data !!!\n";
    }
}

int main() {
    int enterAccountNo, enterPIN, choice;
    YourUserClass user1;

    do {
        displayWelcomeMessage();
        std::cout << "\nEnter Your Account No ";
        std::cin >> enterAccountNo;
        std::cout << "\nEnter PIN ";
        std::cin >> enterPIN;

        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN())) {
            do {
                displayWelcomeMessage();
                displayMainMenu();
                std::cin >> choice;
                handleMainMenuChoice(choice, user1);
            } while (choice != 5);
        } else {
            std::cout << "\nUser Details are Invalid !!!\n";
            _getch();
        }
    } while (true);

    return 0;
}
