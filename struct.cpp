#include<iostream>
#include<conio.h>
#include<sstream>
using namespace std;
struct customer{
	string name;
	int cardnumber;
	int fee;
	int free_feed=0;
	string circle[10];
};
void g(){
	getch();
	system("cls");
}
string ok()
{
	string sure;
	cout<<"are you sure? ";
	cin>>sure;
	return sure;
}
int howmuch(){
	int much;
	cout<<"how much? 1-10% 2-20% ";
	cin>>much;
	return much;
}
string IntToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}
 int sel(){
 	int select;
	cout<<"1- create new account"<<"\n";
	cout<<"2- send money to customer account"<<"\n";
	cout<<"3- recive money from customer account"<<"\n";
	cout<<"4- to get customers list"<<endl;
	cout<<"5- from ---> to"<<endl;
	cout<<"6- balance"<<endl;
	cout<<"7- show Turnover"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"your select: ";
	cin>>select;
	return select;
 }
 int accn(){
 	int acn;
 	cout<<"enter account number(2 digit): ";
	cin>>acn;
	return acn;
 }
int main(){
	int select;
	customer a[5];
	int i=0;
	int t;
	s:
	select=sel();
	switch(select){
		int fe;
		case 1:
			system("cls");
			cout<<"SING IN"<<endl;
			cout<<"OK YOU ARE CREATING AN ACCOUNT!"<<endl;
			cout<<"--------------------"<<endl;
			cout<<"enter name: ";
			cin>>a[i].name;
			a[i].cardnumber=accn();
			cout<<"fee $: ";
			cin>>fe;
			a[i].fee=fe+5000;
			a[i].circle[a[i].free_feed]="hesab eftetah shod --->"+IntToString(a[i].fee);
			a[i].free_feed++;
			i++;
			t=i;
			cout<<"******************";
			cout<<"you already have "<<i<<" customer!";	
			cout<<"******************";
			g();
			goto s;
			break;
		case 2:
			system("cls");
			cout<<"OK YOU ARE GOING TO SEND MONEY TO SOME ACCOUNT!"<<endl;
			int cds;
			cds=accn();
			for(int i=0;i<t;i++){
				if(cds==a[i].cardnumber){
					cout<<"----------"<<endl;
					cout<<"that is customer number "<<i+1<<endl;
					cout<<"man/miss "<<a[i].name<<endl<<"id: "<<a[i].cardnumber<<endl<<"fee: "<<a[i].fee<<" $"<<endl;
					int trx;
					cout<<"now how many bucks you wanna send$? ";
					cin>>trx;
					cout<<"----------"<<endl;
					a[i].fee+=trx;
					cout<<"***********";
					cout<<"now "<<a[i].name<<" have "<<a[i].fee<<" $";
					cout<<"***********";
					string s=IntToString(trx);
					a[i].circle[a[i].free_feed]=s+"$ variz shod ---->"+IntToString(a[i].fee);
					a[i].free_feed++;
					g();
					goto s;
				}
				else{
					continue;
				}
			}
			break;
		case 3:
			system("cls");
			cout<<"OK YOU ARE GOING TO GIVE MONEY FROM SOME ACCOUNT!"<<endl;
			for(int i=0;i<t;i++){
				int cdds;
				cdds=accn();
				int point=a[i].cardnumber;
				if(point==cdds){
					cout<<"----------"<<endl;
					cout<<"well account founded!"<<endl;
					cout<<"man/miss "<<a[i].name<<endl<<"id: "<<a[i].cardnumber<<endl<<"fee: "<<a[i].fee<<" $"<<endl;
					int mine;
					cout<<"----------"<<endl;
					cout<<"how many bucks you wanna give $: ";
					cin>>mine;
					if(a[i].fee-mine>5000){
						a[i].fee-=mine;
						cout<<"*****your transaction done*****";
						cout<<"NOW"<<a[i].name<<" HAVE "<<a[i].fee<<" $";
						cout<<"******************";
						string smine=IntToString(mine);
						a[i].circle[a[i].free_feed]=smine+"$ bardasht shod ---->"+IntToString(a[i].fee);
						a[i].free_feed++;
					}
					else{
						cout<<"*****your transaction failed ):*****"<<endl;
					}	
					g();
					goto s;
				}
				else{
					continue;
				}
			}
			break;
		case 4:
			cs:
			system("cls");
			for(int i=0;i<t;i++){
				cout<<"name: "<<a[i].name<<endl;
				cout<<"id: "<<a[i].cardnumber<<endl;
				cout<<"cash: "<<a[i].fee<<" $";
				
				cout<<endl<<"*************************"<<endl;
			}
			g();
			goto s;
		case 5:
			int az;
			int be;
			cout<<"from: ";
			cin>>az;
			cout<<"to: ";
			cin>>be;
			for(int i=0;i<t;i++){
				if(a[i].cardnumber==az){
					cout<<"FROM "<<a[i].name;
					for(int j=0;j<t;j++){
						if(a[j].cardnumber==be){
							cout<<" TO "<<a[j].name;
							int trxx;
							cout<<" how many bucks? $:";
							cin>>trxx;
							if(a[i].fee-trxx>5000){
								a[i].fee-=trxx;
								a[j].fee+=trxx;
								cout<<"your transaction just done!";
								string strx=IntToString(trxx);
								a[j].circle[a[j].free_feed]=strx+"$ az "+a[i].name+" be hesab shoma variz shod ---->"+IntToString(a[i].fee);
								a[i].circle[a[i].free_feed]=strx+"$ tavasot "+a[j].name+" az hesab shoma bardasht shod ---->"+IntToString(a[i].fee);
								a[i].free_feed++;
								a[j].free_feed++;
							}
							else{
								cout<<"costumer have not enough money";
								
							}
							}
						}
					}
				};
			g();
			goto s;
		case 6:
			int v;
			system("cls");
			cout<<"1-special account balance?"<<endl;
			cout<<"2- expect one account"<<endl;
			cout<<"3-to all"<<endl;
			cin>>v;
			switch(v){
				case 1:
					{
					int id=accn();
					//id=accn;
					for(int i=0;i<t;i++){
						if(a[i].cardnumber==id){
							cout<<"fine!"<<a[i].name<<" with "<<a[i].fee<<" $"<<endl;
							string s=ok();
							if(s=="yes" || s=="yep" ||s=="ok"){
								string smuch;
								int h=howmuch();
								switch(h){
									case 1:
										smuch="10%";
										a[i].fee+=(a[i].fee*10)/100;
										a[i].circle[a[i].free_feed]=smuch+" sud variz shod ---->"+IntToString(a[i].fee);
										a[i].free_feed++;
										g();
										goto cs;
										break;
									case 2:
										smuch="20%";
										string s=ok();
										if(s=="yes"||s=="yep"||s=="ok"){
											a[i].fee+=(a[i].fee*20)/100;
											a[i].circle[a[i].free_feed]=smuch+" sud variz shod ---->"+IntToString(a[i].fee);
											a[i].free_feed++;
										}		
										g();
										goto cs;
										break;
										}
							}
							else{
								continue;
								}
						}
					}
					}
				break;
				goto cs;
				case 2:
					int expect;
					cout<<"so who is your expection?(enter him/her id number )";
					cin>>expect;
					for(int i=0;i<t;i++){
						if(a[i].cardnumber==expect){
							cout<<a[i].name<<" with "<<a[i].fee<<" $ is your expection "<<endl;
							string confirm=ok();
							if(confirm=="yes" || confirm=="yep" ||confirm=="ok"){
								string sb;
								int balance=howmuch();
								switch(balance){
									case 1:
										for(int i=0;i<t;i++){
											if(a[i].cardnumber!=expect){
												sb="10%";
												a[i].circle[a[i].free_feed]=sb+" sud variz shod ---->"+IntToString(a[i].fee);
												a[i].fee+=(a[i].fee*10)/100;
											}
											else{
												continue;
											}
										}
										g();
										goto cs;
										break;
									case 2:
										for(int i=0;i<t;i++){
											if(a[i].cardnumber!=expect){
												sb="20%";
												a[i].circle[a[i].free_feed]=sb+" sud variz shod ---->"+IntToString(a[i].fee);
												a[i].fee+=(a[i].fee*20)/100;
											}
											else{
												continue;
											}
										}
										g();
										goto cs;
										break;
						        }	
						   }
						}
					}
				case 3:
					string sba;
					int balance=howmuch();
					switch(balance){
						case 1: 
							for(int i=0;i<t;i++){
								cout<<a[i].name<<" with id "<<a[i].cardnumber<<" pocket: "<<a[i].fee<<" $ will have ---> "<<a[i].fee+(a[i].fee*10)/100<<endl;
								if(i==t-1){
									string confirm;
									cout<<"are you sure about these? ";
									cin>>confirm;							
									if(confirm=="yes" || confirm=="yep" ||confirm=="ok"){
										for(int i=0;i<t;i++){
											sba="10%";
											a[i].fee+=(a[i].fee*10)/100;
											a[i].circle[a[i].free_feed]=sba+" sud variz shod ---->"+IntToString(a[i].fee);
											a[i].free_feed++;
										}
									}
								}
							}
							g();
							goto cs;
							break;
						case 2:
							for(int i=0;i<t;i++){
								cout<<a[i].name<<" with id "<<a[i].cardnumber<<" pocket: "<<a[i].fee<<" $ will have ---> "<<a[i].fee+(a[i].fee*20)/100<<endl;
								if(i==t-1){
									string confirm;
									cout<<"are you sure about these? ";
									cin>>confirm;							
									if(confirm=="yes" || confirm=="yep" ||confirm=="ok"){
										for(int i=0;i<t;i++){
											sba="20%";
											a[i].fee+=(a[i].fee*20)/100;
											a[i].circle[a[i].free_feed]="20 % sud variz shod ---->"+IntToString(a[i].fee);
											a[i].free_feed++;
										}
									}
								}
							}
							g();
							goto cs;
							break;
					}	
					}
						case 7:
							
							for(int i=0;i<t;i++){
								cout<<"name: "<<a[i].name<<endl;
								cout<<"id: "<<a[i].cardnumber<<endl;
								cout<<"cash: "<<a[i].fee<<" $";
									cout<<endl<<"*************************"<<endl;
							}
							int j;
							cout<<"which costumer"<<endl;
							cin>>j;
							for(int i=0;i<t;i++){
								if(a[i].cardnumber==j){
									
									for(int j=0;j<=a[i].free_feed;j++){
										cout<<a[i].circle[j]<<endl;
									}
								goto s;
								}
							}				
							break;
			}
			}
