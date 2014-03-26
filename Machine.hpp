#include "Include.hpp"
#include "Player.hpp"


//人間クラス
class Machine : public Player{
private:
	list<int> numbers_list;	//"vector list 違い"で検索

public:
	/* Playerクラスからオーバーライドする関数 */
	void SelectMyNumber();
	int SendQuery();
	void ResvQuery(int query, int reply);
	void Init();
	
	//新たに追加する関数
	void noway(int query, int reply);
	int isEffective(int query);
	int vnoway(int query, int reply);

	//コンストラクタ
	Machine(bool turn) : Player(turn){
		this->name = "Machine";
		if (turn){ this->name += "2"; }
		else{ this->name += "1"; }
		for (int i = 0; i < 1000; i++){
			if (isValidNumber(i) == true){
				numbers_list.push_back(i);
			}
		}

	}
};
