#include "Human.hpp"


void Human::ResvQuery(int query, int reply){
	//query_reply_map.insert(map<int, int>::value_type(query, reply));	//質問とその答えを履歴に追加する
   QueryReply a(query,reply);
	query_reply_list.push_back(a);	//質問とその答えを履歴に追加する
}

void Human::Init(){
	//query_reply_map.clear();	//質問の履歴を削除
	query_reply_list.clear();	//質問の履歴を削除
	SelectMyNumber();	//自分の数字を決める
}

//自分の数字を決める
void Human::SelectMyNumber(){
	do{
		//人間は標準入力で数字を決める
		cout << this->name << " >> My number is ..";
		cin >> this->number;
	} while (isValidNumber(this->number) == false);
}

//質問する数字を選ぶ
int Human::SendQuery(){
	ShowQueryHistory();	//質問履歴の表示
	int test;
	do{
		cout << name << " >> I guess your number is..";
		cin >> test;
	} while (isValidNumber(test) == false);
	return test;
}
