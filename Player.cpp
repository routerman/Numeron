#include "Player.hpp"


//����̎���ɑ΂��A�����̐����Ɣ�r���A������Ԃ�
int Player::SendReply(int query){
	cout << this->name << " >> " << query << " is ";
	int reply = 0;
	if (this->number / 100 == query / 100)reply += 10;
	if (this->number / 10 % 10 == query / 10 % 10)reply += 10;
	if (this->number % 10 == query % 10)reply += 10;
	if ((this->number / 100 == query / 10 % 10) || (this->number / 100 == query % 10))reply++;
	if ((this->number / 10 % 10 == query / 100) || (this->number / 10 % 10 == query % 10))reply++;
	if ((this->number % 10 == query / 100) || (this->number % 10 == query / 10 % 10))reply++;
	//sleep(2);
	cout << reply / 10 << "-" << reply % 10 << endl;
	return reply;
}

//����̗�����\������B�I�[�o�[���C�h����K�v�͂Ȃ�
void Player::ShowQueryHistory(){
	int i = 0;
	//for (map<int, int>::iterator it = query_reply_map.begin(); it != query_reply_map.end(); it++){
	//	cout << ++i << ":" << (*it).first << ":" << (*it).second / 10 << "-" << (*it).second % 10 << endl;
	//}
   for( list<QueryReply>::iterator it = query_reply_list.begin(); it != query_reply_list.end(); it++ ){
		cout << ++i << ":";
      it->show();
   }
}
