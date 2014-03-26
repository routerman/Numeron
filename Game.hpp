#include "Include.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "Machine.hpp"

class Game{
private:
	//int mode;
	int count; 
	bool turn; //今、先攻か後攻か
	Player *player[2];	//Playerクラスを継承したクラスのインスタンスへのポインタ
	bool end; //ゲームが終了したか
public:
	void Proc();
	Game(int mode);
	~Game();
};
