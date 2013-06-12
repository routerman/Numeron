#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <functional>

#define DEBUG
using namespace std;

bool isValidNumber(int a);

class Entry{
public:
	int number;
	int probablity;
	int eat;
	int bite;
//private:
	Entry(){
		probablity=100;
		number=eat=bite=0;
	}
};

class Player{
private:
	Entry answer;
	int count;
public:
	list<Entry> anslist;
	//void setLastEntry(Entry test){this->anslist[count]=test;}
	void incCount(){this->count++;}
	int getCount(){return count;}
	void setAnswer(int ans){this->answer.number=ans;}
	int getAns(){return answer.number;}
	void viewAnsList(){
		for(list<Entry>::iterator it = anslist.begin(); it!=anslist.end(); it++){
			cout<<" : "<<it->number<<"="<<it->eat<<"-"<<it->bite<<endl;
		}
	}
	Entry respond(int test){
		Entry a;
		a.number=test;
		if(answer.number/100==test/100)a.eat++;
		if(answer.number/10%10==test/10%10)a.eat++;
		if(answer.number%10==test%10)a.eat++;
		if((answer.number/100==test/10%10)||(answer.number/100==test%10))a.bite++;
		if((answer.number/10%10==test/100)||(answer.number/10%10==test%10))a.bite++;
		if((answer.number%10==test/100)||(answer.number%10==test/10%10))a.bite++;
		//cout<<test<<"is"<<a.eat<<"-"<<a.bite<<endl;
		return a;
	}
	Player(){
		count=0;
	}
};


class Computer : public Player{
private:
	Entry entry[1000];
	int candidates;
public:
	void setEntry(Entry a){entry[a.number]=a;}
	void deleteEntry(int a){
		entry[a].probablity=0;
		candidates--;
	};	
	void think(){
		//とりあえず、今は何も考えていない
		//候補を削除するだけで十分強い。
		//良い質問を「多くの候補を削除できる質問」と定義する。
		for(int i=0;i<1000;i++){
			if(entry[i].probablity>0){
				//iを質問したとき。
//				for(){
					//削除される場合。
	//				if()entry[i].probablity++;
		//		}
			}
		}
	}
	void remove(int test,int eat,int bite){
		int m;
		deleteEntry(test);
		//xeatでなければ削除
		for(int i=0;i<1000;i++){
			if(entry[i].probablity==0)continue;
			m=0;
			if( (test/100==i/100) )m++;
			if( (test/10%10==i/10%10) )m++;
			if( (test%10==i%10) )m++;
			if(m!=eat)deleteEntry(i);
		}
		//xbite以外は削除
		for(int i=0;i<1000;i++){
			if(entry[i].probablity==0)continue;
			m=0;
			if( (i/100==test/10%10)||(i/100==test%10) )m++;
			if( (i/10%10==test/100)||(i/10%10==test%10) )m++;
			if( (i%10==test/100)||(i%10==test/10%10) )m++;
			if(m!=bite)deleteEntry(i);
		}
	}
	
	void Proc(Entry a){
		//deleteEntry(a.test);
		remove(a.number,a.eat,a.bite);
	}

	void viewEntry(){
		bool flag=false;
		cout<<"<< The candidates.. >>"<<endl;
#ifdef DEBUG
		for(int i=0;i<1000;i++){
			if(entry[i].probablity>0){
				cout<<entry[i].number<<",";
				flag=true;
			}else{
				cout<<"___,";
				flag=true;
			}
			if(i%10==0 && flag==true){
				cout<<endl;
				flag=false;
			}
		}
#endif
		cout<<"The number of candidates is "<<candidates<<endl;
	}
	int select(){
		/*
		//select in random from candidates.
		srand( (unsigned)time( NULL ) );
		int count2=rand()%500;
		do{
			for(int i=0;i<1000;i++){
				if(entry[i].probablity>0){
					count2--;
					if(count2==0)return entry[i].number;
				}
			}
		}while(count2>0);
		return 123;
		*/
		int max_probability=0;
		int cand;
		for(int i=0;i<1000;i++){
			if(entry[i].probablity>max_probability){
				max_probability=entry[i].probablity;
				cand=i;
			}
		}
		return cand;
	}
	Computer(){
		candidates=0;
		for(int i=0;i<1000;i++){
			if(isValidNumber(i)){
				entry[i].number=i;
				candidates++;
			}else{
				entry[i].probablity=0;
			}
		}
	}
};

bool isValidNumber(int a){
	if( (a>=100)&&(a<1000)){
		return (a%10!=a/10%10)&&(a/10%10!=a/100)&&(a/100!=a%10);
	}
#ifdef DEBUG
	cout<<"Invalid!"<<endl;
#endif
	return false;
}

int main(){
	int ans;
	bool turn=false;
	do{
		Player player;
		Computer computer;
		Entry sample;
		//Ready..
		srand( (unsigned)time( NULL ) );
		ans=rand()%1000;
		while(isValidNumber(ans)==false){
			//cout<<"Invalid!"<<endl;
			ans=ans*ans+ans+ans/2;
			ans=ans%1000;
		}			
		computer.setAnswer(ans);

		do{
			cout<<"Please, input your number=";
			cin>>ans;
		}while(isValidNumber(ans)==false);
		player.setAnswer(ans);

		cout<<"OK!Start!Numeron."<<endl;
		//Start!!
		do{
			turn=!turn;
			if(turn){
				//player
				cout<<"<<PLAYER ("<<player.getCount()<<")>>"<<endl;
				player.viewAnsList();
				do{
					cout<<"(player)OK! Computer's number must be ";
					cin>>sample.number;
				}while(isValidNumber(sample.number)==false);
				sample=computer.respond(sample.number);
				//player.setLastEntry(sample);
				player.anslist.insert(player.anslist.end(),sample);
				player.incCount();
				cout<<"(computer)"<<sample.number<<"is"<<sample.eat<<"-"<<sample.bite<<endl;
			}else{
				//computer
				cout<<"<<COMPUTER ("<<computer.getCount()<<")>>"<<endl;
				computer.viewEntry();
				computer.viewAnsList();
				do{
					cout<<"(computer)Sir, Player's number may be ";
					computer.think();
					sample.number=computer.select();
					cout <<sample.number<<endl;
				}while(isValidNumber(sample.number)==false);
				sample=player.respond(sample.number);
				cout<<"(player)"<<sample.number<<"is"<<sample.eat<<"-"<<sample.bite<<endl;
				computer.anslist.insert(computer.anslist.end(),sample);
				//computer.setLastEntry(sample);
				computer.incCount();
				computer.setEntry(sample);
				computer.Proc(sample);
			}
		}while(sample.eat!=3);
		if(turn){
			cout<<"# #  #  # #  # # # ### #  # ##"<<endl;
			cout<<"# # # # # #  # # #  #  ## # ##"<<endl;
			cout<<"### # # # #  # # #  #  #### ##"<<endl;
			cout<<" #  # # # #  ## ##  #  # ##   "<<endl;
			cout<<" #   #   #    # #  ### #  # ##"<<endl;
		}else{
			cout<<"# #  #  # #  #    #   ## ###"<<endl;
			cout<<"# # # # # #  #   # # #   #  "<<endl;
			cout<<"### # # # #  #   # #  #  ###"<<endl;
			cout<<" #  # # # #  #   # #   # #  "<<endl;
			cout<<" #   #   #   ###  #  ##  ###"<<endl;
		}
		cout<<"<<<END>>> : count="<< computer.getCount()<<endl;
		cout<<"computer's number is"<<computer.getAns()<<endl; 
		cout<<"player's number is"<<player.getAns()<<endl; 
		cout<<"if you want to finish, input '0'."<<endl;
		cin>>ans;
	}while(ans!=0);
	cout<<"Matched!"<<endl;
	return 0;
}