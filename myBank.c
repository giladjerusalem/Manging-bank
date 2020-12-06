#include "myBank.h"
#include <stdio.h>

#define NUM 50

double acounts[2][NUM];
int OpenAccount (double money){
	if(money<0){		//if input ok
		return -1;
	}
	for (int i=0; i<NUM; i++){
		if (acounts[0][i]==0){		//if acount close
			acounts[1][i]=money;	//put money inside
			acounts[0][i]=1;	//change to open
			return 901+i;
		}	
	}
	return -1;
}

double BalanceInquiry (int id){
	if (id<901||id>950){ //if input ok
		printf("The id is wrong");
		return -1;
	}
	if(acounts[0][id-901]==0){	//if acount close
		printf("This account is closed\n");
		return -1;
	}
	return acounts[1][id-901]; 	//return amount of money
}
	
double Deposite (int id, double money){
	if(money<=0){	// if money positive
	return -1;
	}
	if (id<901||id>950){ //if input acount ok
		printf("The id is wrong");
		return -1;
	}
	if(acounts[0][id-901]==0){	//if acount close
		return -1;
	}
	acounts[1][id-901]=acounts[1][id-901]+money; //add money
	return acounts[1][id+901];
}

double Withdrawal (int id, double money){
	if(money<=0)	{// if money positive
		return -1;
	}
	if (id<901||id>950){ //if input acount ok
		printf("The id is wrong\n");
		return -1;
	}
	if(acounts[0][id-901]==0){	//if acount close
		printf("This account is closed\n");
		return -1;
	}
	if (acounts[1][id-901]<money){	//if not possible overdruft
		printf("Cannot withdrawal more then the balance\n");
		return -1;
	}
	acounts[1][id-901]=acounts[1][id-901]-money;	//update acount
	return acounts[1][id-901];
}
void CloseAccount (int id){
	acounts[0][id-901]=0;	//close acount
}

void Interest(double percent){
	double interest = (percent*0.01)+1;	//transfer to precent
	for (int i=0; i<NUM; i++){	//run all acoumts
		acounts[1][i]=acounts[1][i]*interest;	//calculation
	}
}

void ToString(){
	for (int i=0; i<NUM; i++){	//run all acounts
		if(acounts[0][i]!=0){	//if acount open
	printf("The balance of account number %d is: %.2lf\n",i+901 ,acounts[1][i]);
		} //print
	}
}
void CloseAllAcounts(){
	for (int i=0; i<NUM; i++){	//run all acoumts
		acounts[0][i]=0;	//close all acounts
	}
}
