#include "Human.hpp"


void Human::ResvQuery(int query, int reply){
	//query_reply_map.insert(map<int, int>::value_type(query, reply));	//����Ƃ��̓����𗚗��ɒǉ�����
   QueryReply a(query,reply);
	query_reply_list.push_back(a);	//����Ƃ��̓����𗚗��ɒǉ�����
}

void Human::Init(){
	//query_reply_map.clear();	//����̗������폜
	query_reply_list.clear();	//����̗������폜
	SelectMyNumber();	//�����̐��������߂�
}

//�����̐��������߂�
void Human::SelectMyNumber(){
	do{
		//�l�Ԃ͕W�����͂Ő��������߂�
		cout << this->name << " >> My number is ..";
		cin >> this->number;
	} while (isValidNumber(this->number) == false);
}

//���₷�鐔����I��
int Human::SendQuery(){
	ShowQueryHistory();	//���◚���̕\��
	int test;
	do{
		cout << name << " >> I guess your number is..";
		cin >> test;
	} while (isValidNumber(test) == false);
	return test;
}
