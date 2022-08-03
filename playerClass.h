#include <iostream>
#include <vector>
#include <string>

//プレイヤーのクラス
class player{
public:
    std::vector<int> hand; //プレイヤーの手札
    std::string name; // プレイヤーの名前を登録
    
    int num; // プレイヤーの手札の数字
    int total;

    void getName(); //プレイヤーの名前を取得する関数
    void cards(int T);//カードをT枚ランダムに引く関数
    void totalNum();//カードの数を合計する関数
};

std::string ans; //各質問に対する入力値
