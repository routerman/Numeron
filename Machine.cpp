#include "Machine.hpp"

//乱数を生成して自分の数字を決定する
void Machine::SelectMyNumber(){
	int ans;
	srand((unsigned)time(NULL));
	ans = rand() % 1000;
	while (isValidNumber(ans) == false){
		//cout<<"Invalid!"<<endl;
		ans = ans*ans + ans + ans / 2;
		ans = ans % 1000;
	}
	this->number = ans;

	cout << this->name << " >> My number is ..???" << endl;
	//cout << this->number << endl;
}

//質問する数字を選ぶ
int Machine::SendQuery(){
	//候補数字の表示
	//for (list<int>::iterator it = numbers_list.begin(); it != numbers_list.end(); it++){
	//cout << *it << ",";
	//}
	//クエリ履歴の表示
	ShowQueryHistory();
	//とりあえず、候補数の最初
	list<int>::iterator it = numbers_list.begin();
	cout << name << " >> nokori..." << numbers_list.size() << " numbers, I guess your number is .." << *it << endl;
	return *it;

}

//結果を受けとり候補を削除する
void Machine::ResvQuery(int query, int reply){
	query_reply_map.insert( map<int, int>::value_type(query, reply) );
	//numbers_list.remove_if(noway(query,reply/10,reply%10));
	noway(query, reply);
}

//マイナンバーや候補数リストを初期化する
void Machine::Init(){
	number = 0;
	query_reply_map.clear();
	numbers_list.clear();
	for (int i = 0; i < 1000; i++){
		if (isValidNumber(i) == true){
			numbers_list.push_back(i);
		}
	}
	//自分の数字を選ぶ
	SelectMyNumber();
}

//
void Machine::noway(int query, int reply){
	int m;
	numbers_list.remove(query);
	//xeatでなければ削除
	for (list<int>::iterator it = numbers_list.begin(); it != numbers_list.end();){
		m = 0;
		if ((query / 100 == *it / 100))m++;
		if ((query / 10 % 10 == *it / 10 % 10))m++;
		if ((query % 10 == *it % 10))m++;
		if (m != reply / 10){
			//cout << *it <<",";
			if (it != numbers_list.end())it = numbers_list.erase(it);
			else numbers_list.erase(it);
		}
		else{
			if (it != numbers_list.end())it++;
		}
	}
	//xbite以外は削除
	for (list<int>::iterator it = numbers_list.begin(); it != numbers_list.end();){
		m = 0;
		if ((query / 100 == *it / 10 % 10) || (query / 100 == *it % 10))m++;
		if ((query / 10 % 10 == *it / 100) || (query / 10 % 10 == *it % 10))m++;
		if ((query % 10 == *it / 100) || (query % 10 == *it / 10 % 10))m++;
		if (m != reply % 10){
			//cout << *it << ",";
			if (it != numbers_list.end())it = numbers_list.erase(it);
			else numbers_list.erase(it);
		}
		else{
			if (it != numbers_list.end())it++;
		}
	}
}
