#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class atm{
    private:
    long int account_no;
    string name;
    int pin;
    double balance;
    string mobile_no;

    public:
    void setData(long int account_no, string name, int pin, double balance, string mobile_no){
        this->account_no=account_no;
        this->name=name;
        this->pin=pin;
        this->balance=balance;
        this->mobile_no=mobile_no;
    }
    long int getAccountNo(){
        return account_no;
    }
    string getName(){
        return name;
    }
    int getPin(){
        return pin;
    }
    double getBalance(){
        return balance;
    }
    string getMobileNo(){
        return mobile_no;
    }
    void setMobileNo(string prev, string newNo){
        if(mobile_no==prev){
            this->mobile_no=newNo;
            cout<<"Successfully updated mobile number."<<endl;
            _getch();
        }
        else{
            cout<<"Old mobile number is invalid.";
            _getch();
        }
    }
    void cashWithdraw(int amount){
        if(amount>0 and amount<=balance){
            balance-=amount;
            cout<<endl<<"Please collect your cash.";
            cout<<endl<<"Available balance: "<<balance;
            _getch();
        }
        else{
            cout<<endl<<"Invalid input or Insufficient balance";
            _getch();
        }
    }
};

int main(){
    int choice=0;
    int enterPin=0;
    long int enterAccountNo=0;
    system("cls");
    atm user1;
    user1.setData(1234567,"Tim",1111,4500.90,"Sundar");

    do{
        system("cls");
        cout<<endl<<"*****Welcome to ATM*****"<<endl;
        cout<<endl<<"Enter your Account No: ";
        cin>>enterAccountNo;
        cout<<endl<<"Enter PIN";
        cin>>enterPin;

        if(enterAccountNo==user1.getAccountNo() and enterPin==user1.getPin()){
            while(1){
                int amount=0;
                string oldMobileNo,newMobileNo;
                system("cls");
                cout<<endl<<"*****Welcome to ATM*****"<<endl;
                cout<<endl<<"Select options";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash Withdraw";
                cout<<endl<<"3. Show User Details";
                cout<<endl<<"4. Update Mobile No.";
                cout<<endl<<"5. Exit"<<endl;
                cin>>choice;
                switch(choice){
                    case 1:
                        cout<<endl<<"Your Bank Balance is: "<<user1.getBalance();
                        _getch();
                        break;
                    case 2:
                        cout<<endl<<"Enter the amount: ";
                        cin>>amount;
                        user1.cashWithdraw(amount);
                        break;
                    case 3:
                        cout<<endl<<"*****User Details are :-";
                        cout<<endl<<"-> Account no. "<<user1.getAccountNo();
                        cout<<endl<<"-> Name: "<<user1.getName();
                        cout<<endl<<"-> Balance: "<<user1.getBalance();
                        cout<<endl<<"-> Mobile No: "<<user1.getMobileNo();
                        _getch();
                        break;
                    case 4:
                        cout<<endl<<"Enter old mobile no. ";
                        cin>>oldMobileNo;
                        cout<<endl<<"Enter new mobile no. ";
                        cin>>newMobileNo;
                        user1.setMobileNo(oldMobileNo,newMobileNo);
                        break;
                    case 5:
                        exit(0);
                        break;
                    default:
                        cout<<endl<<"Enter valid data!!!";
                }
            }
        }
        else{
            cout<<end<<"User Details are invalid !!!";
            _getch();
        }
    }while(1);
    return 0;
}