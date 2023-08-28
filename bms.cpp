#include <iostream>
#include <vector>
using namespace std;

class BankAccount{	
	private:
		string name;
		int AccNum;
		double balance;
	public:
		BankAccount(string n, int ac , double bal){
			name = n;
			AccNum = ac;
			balance = bal;
		}
		string getName(){
			return name;
		}
		int getAccountNum(){
			return AccNum;
		}
		double getBalance(){
			return balance;  
		}
		void deposit(double amount){
			balance = balance + amount;
		}
		void withdraw(double amount){
			if(balance>= amount){
				balance = balance - amount;
				cout<<"\t\tWithdraw Successfull!!"<<endl; 
			}else{
				cout<<"\t\tInsuficient Balance"<<endl;
			}
		}
};

class BankManagement{
	private:
		vector<BankAccount> accounts;
	public:
		void AddAcc(string name, int AccNum,double balance){
			accounts.push_back(BankAccount(name, AccNum, balance));
		}
		void ShowAllAccounts(){
			cout<<"\t\tAll Account Holders"<<endl;
			for(int i=0;i<accounts.size();i++){
				cout<<"Name : "<<accounts[i].getName()<<"  Account Number: "<<accounts[i].getAccountNum()<<" Balance : "<<accounts[i].getBalance()<<endl;
			}
		}
		void SearchAccount(int account){
			cout<<"\t\tAccount Holder "<<endl;
			for(int i =0;i<accounts.size();i++){
				if(accounts[i].getAccountNum()==account){
					cout<<"Name : "<<accounts[i].getName()<<"  Account Number: "<<accounts[i].getAccountNum()<<" Balance : "<<accounts[i].getBalance()<<endl;
				}
			}
		}
		BankAccount* FindAccount(int AccNum){
			for(int i =0 ; i<accounts.size();i++){
				if(accounts[i].getAccountNum()==AccNum){
					return &accounts[i];
				}
			}
		}
};
 
main(){

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

	BankManagement bank;
	int choice;
	char op;	
	do{
		system("cls");
		cout<<"\t\t::Bank Management System"<<endl;
		cout<<"\t\t\tMain Menu"<<endl;
		cout<<"\t\t 1.) Create Account"<<endl;
		cout<<"\t\t 2.) Show All Account"<<endl;
		cout<<"\t\t 3.) Seach Account"<<endl;
		cout<<"\t\t 4.) Deposit Money"<<endl;
		cout<<"\t\t 5.) Withdraw Money"<<endl;
		cout<<"\t\t 6.) Exit"<<endl;
		cout<<"------------------------------"<<endl;
		cout<<"\t\t Enter Your Choice :";
		cin>>choice; 
		switch(choice){
			case 1:{
				string name;
				int AccNum;
				double balance;
				cout<<"\t\t Enter Name: ";
				cin>>name;
				cout<<"\t\t Enter Account Number: ";
				cin>>AccNum;
				cout<<"\t\t Enter initial balance: ";
				cin>>balance;
				bank.AddAcc(name , AccNum , balance);
				cout<<"\t\t Account Created Successfully!!"<<endl;
				break;
			}
			case 2:{
				bank.ShowAllAccounts();
				break;
			}
			case 3:{
				int accountNum;
				cout<<"	Enter Account Number"<<endl;
				cin>>accountNum;
				bank.SearchAccount(accountNum);
				break;
			}
			case 4:{
				int accountNum;
				double amount;
				cout<<"\t\tEnter Account Number to desposit money : "<<endl;
				cin>>accountNum;
				BankAccount* account = bank.FindAccount(accountNum);
				if(account !=NULL){
					cout<<"\t\tEnter Amount to desposit :";
					cin>>amount;
					account->deposit(amount);
					cout<<"\t\t"<<amount<<"Desposit Successfull!!"<<endl;
				}else{
					cout<<"\t\tAccount Not Found!!"<<endl;
				}
				break;
			}
			case 5:{
				int accountNum;
				double amount;
				cout<<"\t\tEnter Account Number to Withdraw money : ";
				cin>>accountNum;
				BankAccount* account = bank.FindAccount(accountNum);
				if(account !=NULL){
					cout<<"\t\tEnter Amount to Withdraw :";
					cin>>amount;
					account->withdraw(amount);
				}else{
					cout<<"Account Not Found!!"<<endl;
				}
				break;
			}
			case 6:{
				exit(1);
				break;
			}		
	}
	cout<<"\t\tDo you want to continue or Exit [Y/N]?";
	cin>>op;
	}while(op == 'y' ||op=='Y');
}