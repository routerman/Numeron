#include "Game.hpp"

void Game::Proc(){
	do{
		//初期化
		int que, rep, try_count;

		//両プレイヤーの答えを決める
		player[0]->Init();
		player[1]->Init();

		//ゲーム開始
		while (!end){
			//sleep(1);
			cout << endl << "<<--- " << player[turn]->getName() << "'s turn!! (" << this->count << ") --->>" << endl;
			//3回続けて無効な質問を送信したら負け
			try_count = 0;
			do{
				if (++try_count == 3){
					end = true;
					break;
				}
				que = player[turn]->SendQuery();
			} while (isValidNumber(que) == false);
			if (end) continue;

			//有効な質問に対し、返事をする。
			rep = player[!turn]->SendReply(que);
			//sleep(1);

			//3-0の場合は終了する
			if (rep == 30){
				end = true;
			}else{
				//結果を受け取り、処理する
				player[turn]->ResvQuery(que, rep);
				if (turn == true) count++;
				turn = !turn;	//交代
			}
		}
		//答え合わせ
		cout << "winner:" << player[turn]->getName() << endl;
		player[turn]->ShowMyNumber();

		string command;
		cout << "revenge?(y/n):";
		cin >> command;
		if (command[0] != 'y')break;
		this->end = false;	//初期化
		this->count = 1;
	} while (true);
}

//
Game::Game(int mode){
	turn = false;
	//"this"はこのクラスの変数であることを明示的に示す。
	this->end = false;
	this->count = 1;
	switch (mode)
	{
	case 1:
		player[0] = new Human(false);
		player[1] = new Human(true);
		break;
	case 2:
		player[0] = new Human(false);
		player[1] = new Machine(true);
		break;
	case 3:
		player[0] = new Machine(false);
		player[1] = new Human(true);
		break;
	case 4:
		player[0] = new Machine(false);
		player[1] = new Machine(true);
		break;
	default:
		break;
	}
}

Game::~Game(){
	delete player[0];
	delete player[1];
}