#include "Include.hpp"
#include "Player.hpp"

/*
Humanクラス
playerクラスを継承する
*/
class Human : public Player{
private:

public:
	/* Playerクラスからオーバーライドする関数 */
	void ResvQuery(int query, int reply);
	void Init();
	void SelectMyNumber();
	int SendQuery();

	//コンストラクタ
	Human(bool turn) : Player(turn){
		cout << "What's your name?:";
		cin >> this->name;
	}
};