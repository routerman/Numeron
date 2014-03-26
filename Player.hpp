/*
複数のヘッダファイルから読み込まれるヘッダファイルには
"#pragma once"をつけ、クラスの再定義を避ける。 
*/
#pragma once
#include "Include.hpp"

/*
HumanとMachineの基底クラスで、「プレイヤー」として必要な機能を持つ。
また、純仮想関数があるため、抽象クラスでもある。
*/
class Player{
protected:	
	//子クラスで使う変数のアクセス修飾子はprivateではなくprotected
	bool turn;	//自分のターン
	int number;	//自分の数字
	map<int, int> query_reply_map;	//質問と返事の履歴
	string name;	//名前
public:

	/* 純仮想関数( 関数=0;のやつ )は子クラスで必ずオーバーライドしなければならない */
	//自分の数字を選ぶ
	virtual void SelectMyNumber()=0;
	
	//相手に質問を送る
	virtual int SendQuery()=0;
	
	//相手の質問を受け取る
	virtual void ResvQuery(int query, int reply)=0;
	
	//name以外を初期化する関数
	virtual void Init()=0;

	/* そのまま継承したい関数 */
	//返事をする
	int SendReply(int query);

	//名前を返す
	string getName(){return this->name;}

	//自分の数字を表示する
	void ShowMyNumber(){ cout << this->name << ">>my number is" << number << endl; }

	//質問の履歴を表示する
	void ShowQueryHistory();

	//コンストラクタ
	Player(bool turn){
		this->turn = turn;
	}

};
