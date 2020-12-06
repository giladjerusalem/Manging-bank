#include "myBank.h"
#include <stdio.h>

int main(){

//deposite
char c;
int id;
double money;
	do {
	printf("\nPlease choose a transaction type: \nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");	//if im any char-do!
	scanf("\n%c", &c);
	if (c=='O') {	//Open account
		printf("Please enter amount for deposit: ");
		if(scanf("%lf", &money)==0){	//put inside id - int/
			printf("Failed to read the amount\n");
		}
		else{
			int id = OpenAccount(money);
			printf("New account number is: %d \n", id );
		}
	}else if (c=='B') {	//BalanceInquiry 
		printf("Please enter account number: ");
		if(scanf("%d", &id)==0){	//put inside id - int/
			printf("Failed to read account number\n");
		}
		else {
			double money = BalanceInquiry (id);
			if (money!=-1){
				printf("The balance of account number %d is: %.2lf\n",id, money);
			}
		}
	}else if (c=='D') {	//Deposite
		printf("Please enter account number: ");
		if(scanf("%d", &id)==0){	//put inside id - int/
			printf("Failed to read account number\n");
		}
		else {
			printf("Please enter amount for deposit");
			if(scanf("%lf", &money)==0){	//put inside id - int/
				printf("Failed to read the amount\n");
			}	
			else {
				double newBalance = Deposite(id, money);
				if (newBalance!=-1){
					printf("Account number: %d\nAmount int this account is: %lf", id, newBalance);
				}
			}
		}
	}else if (c=='W') {	//withdrawal
		printf("Please enter account number: ");
		if(scanf("%d", &id)==0){	//put inside id - int/
			printf("Failed to read account number\n");
		}
		else {
			printf("Please enter the amount to withdrawal: ");
			if(scanf("%lf", &money)==0){	//put inside id - int/
				printf("Failed to read the amount\n");
			}
			else{
				double newBalance = Withdrawal (id, money);
				if (newBalance!=-1){
					printf("The new balance is: %.2lf\n", newBalance);
				}
			}
		}
	}else if (c=='C') {	//close Account 
		printf("Please enter the number of your account");
		if(scanf("%d", &id)==0){	//put inside id - int/
			printf("Failed to read account number\n");
		}
		else{
			CloseAccount (id);
			printf("The account number %d deleated", id);
		}
	}else if (c=='I') {	//add interest to all accounts
		printf("Please enter interst rate: ");
		double interest; 
		if(scanf("%lf", &interest)==0){//put inside number account - int
			printf("Failed to read interest rate\n");
		}
		else{
		Interest(interest);
		}
	}else if (c=='P') {	//print all accounts
		ToString();
	}else if (c=='E') 	{
		CloseAllAcounts();
	}
	else {printf("Invalid transaction type\n");}
	}while (c!='E');			//if im E-go out.
}
	
