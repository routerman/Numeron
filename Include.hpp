#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>

#include <cstdlib>
#include <ctime>
#include <functional>

#ifdef __linux__
   //sleep()
   #include <unistd.h>
#endif

using namespace std;

#define DEBUG

/*
typedef struct{
	int eat;
	int bite;
}Reply;

typedef struct{
	int a,b,c;
}Number;
*/

//グローバル関数はexternで前宣言する。
//基本的にヘッダファイルでは関数や変数の本体を宣言しない
//多数のソースファイルから呼ばれるヘッダファイルは特に。
extern bool isValidNumber(int query);
extern int getRandomNumber(int min,int max);
