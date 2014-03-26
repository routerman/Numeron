#include "Include.hpp"
#include "Game.hpp"

//staticは別にいらない。
bool isValidNumber(int query){
	if ((query >= 0) && (query < 1000)){
		return (query % 10 != query / 10 % 10)
			&& (query / 10 % 10 != query / 100)
			&& (query / 100 != query % 10);
	}
#ifdef DEBUG
	cout << "Invalid!" << endl;
#endif
	return false;
}

int getRandomNumber(int min, int max){
	srand((unsigned)time(NULL));
	return rand() % 1000;
}

int main(){
	Game *game;
	do{
		//ゲームモードを選ぶ
		cout << "1:   HUMAN vs HUMAN" << endl;
		cout << "2:   HUMAN vs COMPUTER" << endl;
		cout << "3:COMPUTER vs HUMAN" << endl;
		cout << "4:COMPUTER vs COMPUTER" << endl;
		int mode;
		do{
			cout << "Sir, Please, select GAME MODE >>";
			cin >> mode;
		} while ((mode<1) || (mode>4));
				
		game = new Game(mode);
		game->Proc();
		delete game;

		string command;
		cout << "continue?(y/n):";
		cin >> command;
		if (command[0] != 'y')break;
	} while (true);
	
	return 0;
}
