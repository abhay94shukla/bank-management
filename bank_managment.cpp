#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <istream>
#include <sstream>
#include <ostream>
#include <fstream>
using namespace std;

class bank
{
    const string b_name = "BANK OF ABHAY";
    string ifsc = "BANK00XXXXX", br_name = "INDIA";

private:
    string account_Number;
    string c_first_name, password, pwd, c_last_name, dob, c_f_name, Gender, permanent_add, present_add, y, poi_n, poa_n, poi, poa;
    int Customer_Id;
    string mob;
    double balance;

public:
    void open_account();
    void display_account();
    void credit();
    void debit();
};

// Account open:

void bank::open_account()
{
    cout << "Enter Your First Name (In Block Letters) : " << endl;
    cin >> c_first_name;
    cout << "Enter Your Last Name (In Block Letters) : " << endl;
    cin >> c_last_name;
    cout << "Enter Your Father's Name (In Block Letters) : " << endl;
    cin >> c_f_name;
    cout << "What is your gender (In Block Letters) : " << endl;
    cin >> Gender;
    cout << "Enter Your Mobile Number : " << endl;
    cin >> mob;
    cout << "Enter Your Date of Birth : " << endl;
    cin >> dob;
    cout << "Enter Last four Digit of your Registered Mobile No, and Enter your year of Birth :" << endl;
    cin >> account_Number;
    cout << "Enter Your Permanent Address : " << endl;
    std::cin >> permanent_add;
    cout << "Enter your Present Address : " << endl;
    cin >> present_add;
    cout << "What is your proof of identification (In Block Letters) : " << endl;
    cin >> poi;
    cout << "What is your " << poi << " number : " << endl;
    cin >> poi_n;
    cout << "What is your proof of address (In Block Letters) : " << endl;
    cin >> poa;
    cout << "What is your " << poa << " number " << endl;
    cin >> poa_n;
    cout << "What type of Account You want to open : saving (S), current (C) :: " << endl;
    cin >> y;
    cout << "Enter amount for deposite : ";
    cin >> balance;
    cout << " Your account is succesfully opened : " << endl;

    ofstream file;
    file.open("E:\\" + account_Number + ".txt");
    file << "Name : " + c_first_name + " " + c_last_name << endl
         << "Father's Name :" + c_f_name << endl
         << "Account Number :" + account_Number << endl
         << "Bank Name :" + b_name
         << "                       Branch: " + br_name << endl
         << "Mobile Number : " + mob << endl
         << "Gender :" + Gender << endl
         << "Address :" + present_add << endl
         << "Balance :" << balance << endl;
    file.close();
};

// Diposite Money:

void bank::credit()
{
    int a;
    string acc;
    ifstream file;
    cout << " Enter your account Number :" << endl;
    cin >> acc;
    file.open("E:\\" + acc + ".txt");
    if (!file)
    {
        cout << " Account Number Does not exist :" << endl;
        exit(1);
    }
    else
    {
        cout << "Enter the amount you want to deposite :: " << endl;
        cin >> a;
        balance = a + balance;
        cout << "Your total balance is :\t " << balance << endl;
        exit(1);
    }
}

// Display account:
void bank::display_account()
{
    cout << " Name : " << c_first_name << " " << c_last_name << endl;
    cout << " Account No is : " << account_Number << endl;
    cout << " Father's Name :  " << c_f_name << endl;
    cout << " Address: " << present_add << endl;
    cout << " Gender :  " << Gender << endl;
    cout << " Bank Name : " << b_name << endl;
    cout << " IFS Code :" << ifsc << endl;
    cout << " Branch : " << br_name << endl;
    cout << " Type of Account that you open :" << y << endl;
    cout << " Amount you deposite: " << balance << endl;
}

// Withdraw Money:

void bank::debit()
{
    double amount;
    cout << " withdraw :";
    cout << "Enter the amount you want to withdraw ::\t " << endl;
    cin >> amount;
    balance -= amount;
    cout << "Your remaining balance is::\t " << balance << endl;
}

int main()
{

    int ch, x;
    bank obj;
    do
    {
        cout << "WELCOME TO BANK OF ABHAY " << endl;
        cout << endl;
        cout << "SAPNE AAPKE :: JIMMEDARI HAMARI ";
        cout << "Select the option from below:: \t " << endl;
        cout << "1) New Customer " << endl;
        cout << "2) Deposit Money " << endl;
        cout << "3) Withdraw Money " << endl;
        cout << "4) Display Account " << endl;

        cin >> ch;

        switch (ch)
        {
        case 1:
            obj.open_account();
            break;

        case 2:

            obj.credit();
            break;
        case 3:
            obj.debit();
            break;
        case 4:
            "4) display account \n ";
            obj.display_account();
            break;

        default:
            cout << "You have not selected a valid option try again ::" << endl;
        }
        cout << "Do you want to select next option press Y \n";
        cout << "if you want to exit then press N ";
        x = _getch();
        if (x == 'n' || x == 'N')
            exit(0);
    } while (x == 'y' || x == 'Y');
    return 0;
}