#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Account{
    private:
    string AccountNo,Password;
    int Balance;

    public:
    Account():AccountNo(""),Password(""),Balance(0){};

    void setAccountNo(string id){
        AccountNo=id;
    }

    void setPassword(string pw){
        Password=pw;
    }

    void setBalance(int balance){
        Balance=balance;
    }

    string getAccountNo(){
        return AccountNo;
    }

    string getPassword(){
        return Password;
    }

    int getBalance(){
        return Balance;
    }

};

void openAccount(Account user){
    system("cls");
    string id,pw;

    cout<<"\tEnter Account No: ";
    cin>>id;
    user.setAccountNo(id);

    cout<<"\tEnter a strong Password: ";
    cin>>pw;
    user.setPassword(pw);

    user.setBalance(0);

    ofstream outfile("C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account.txt",ios::app);
    if(!outfile){
        cout<<"\tError:File cant open!"<<endl;
    }else{
        outfile<<"\t"<<user.getAccountNo()<<" : "<<user.getPassword()<<" : "<<" : "<<user.getBalance()<<endl<<endl;
        cout<<"\tAccount Created Successfully!"<<endl;
    }
    outfile.close();

    Sleep(5000);
}

void addCash(){
    system("cls");

    string id;
    cout<<"\tEnter Account No: ";
    cin>>id;

    ifstream infile("C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account.txt");
    ofstream outfile("C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account Temp.txt");
    if(!infile || !outfile){
        cout<<"\tError: File Can't Open!"<<endl;
    }

    string line;
    bool found=false;

    while(getline(infile,line)){
        stringstream ss;
        ss<<line;
        string userID,userPW;
        int userBalance;
        char delimiter;

        ss>>userID>>delimiter>>userPW>>delimiter>>userBalance;

        if(id==userID){
            found=true;
            int cash;
            cout<<"\tEnter Cash: ";
            cin>>cash;

            int newBalance=userBalance+cash;
            userBalance=newBalance;
            outfile<<"\t"<<userID<<" : "<<userPW<<" : "<<userBalance<<endl;
            cout<<"\t New Balance is: "<<userBalance<<endl;
        }else{
            outfile<<line<<endl;
        }
    }

    if(!found){
        cout<<"\tEnter Valid Account No!"<<endl;
    }

    outfile.close();
    infile.close();
    remove("C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account.txt");
    rename("C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account Temp.txt","C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account.txt");

    Sleep(5000);
}

void withdraw(){
    string id,pw;
    cout<<"\tEnter Account No: ";
    cin>>id;

    cout<<"\tEnter Password: ";
    cin>>pw;

    ifstream infile("C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account.txt");
    ofstream outfile("C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account Temp.txt");

    if(!infile || !outfile){
        cout<<"\tError File Can't Open!"<<endl;
    }

    string line;
    bool found=false;
    while(getline(infile,line)){
        stringstream ss;
        ss<<line;
        string userID,userPW;
        int userBalance;
        char delimiter;

        ss>>userID>>delimiter>>userPW>>delimiter>>userBalance;

        if(id==userID && pw==userPW){
            found=true;
            int cash;
            cout<<"\tEnter Cash: ";
            cin>>cash;
            if(cash <= userBalance){
                int newBalance=userBalance-cash;
                userBalance=newBalance;
                outfile<<"\t"<<userID<<" : "<<userPW<<" : "<<userBalance<<endl;
                cout<<"\tTransaction Was Successful!"<<endl;
                cout<<"\tRemaining Balance: "<<userBalance<<endl;
            }else{
                cout<<"\tLow Balance!"<<endl;
                outfile<<"\t"<<userID<<" : "<<userPW<<" : "<<userBalance<<endl;
            }
            
        }else{
            outfile<<line<<endl;

        }

    }

    if(!found){
        cout<<"\tInvalid Account No. or Password!"<<endl;
    }

    outfile.close();
    infile.close();
    remove("C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account.txt");
    rename("C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account Temp.txt","C:/Users/prabh/OneDrive/Desktop/Web Dev/IronVault/Account.txt");

    Sleep(5000);
}

int main(){
    Account user;

    bool exit=false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome to Bank Account Management System"<<endl;
        cout<<"\t******************************************"<<endl;
        cout<<"\t1.Open new Account."<<endl;
        cout<<"\t2.Add Cash."<<endl;
        cout<<"\t3.Withdraw Cash."<<endl;
        cout<<"\t4.Exit."<<endl;
        cout<<"\tEnter Your Choice: ";
        cin>>val;

        if(val==1){
            openAccount(user);
        }
        else if(val==2){
            addCash();
        }
        else if(val==3){
            withdraw();
        }else if(val==4){
            system("cls");
            exit=true;
            cout<<"\tGood Luck!";
            Sleep(2000);
        }

        Sleep(3000);
    }
}