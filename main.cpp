#include <iostream>
#include <random>
#include <vector>
#include <string>
using namespace std;

//プレイヤーのクラス
class player{
public:
    vector<int> hand; //プレイヤーの手札
    string name; // プレイヤーの名前を登録
    
    int num; // プレイヤーの手札の数字
    int total;

    void cards(int T);
    void getName();
    void totalNum();
};

class CARD{
  
};

string ans; //各質問に対する入力値

//カードをT枚ランダムに引く関数
void player::cards(int T){
    int myNum;
    int min = 1;
    int max = 10;
    
    random_device random;
    default_random_engine eng(random());
    uniform_int_distribution<int> distr(min, max);
    for (int n = 0; n < T; ++n) {
        myNum = distr(eng);
        hand.push_back(myNum);
        }
}

//カードの枚数を合計する関数
void player::totalNum(){
    total = accumulate(hand.begin(), hand.end(), 0);
}

//プレイヤーの名前を取得する関数
void player::getName(){
    cout << "Type your name here!" << endl;
    cout << "▷ " ;
    cin >> name;
}

int main()
{
    player player1;
    player COM;
    
    player1.getName();
    cout << "Welcome to the Casino, " << player1.name << "!" << endl;
    Q1:
    cout << "Do you wanna play Black Jack, " << player1.name << "? (y/n)"<< endl;
    cin >> ans;
    if (ans == "n") {cout << "See you later!" << endl;}
    else if(ans == "y"){
    BJstart:
        player1.hand.clear();
        COM.hand.clear();
        
        player1.cards(2);
        COM.cards(2);
        
        player1.totalNum();
        COM.totalNum();
        
        do{
            cout << "Your hand is { " ;
            for (int N = 0; N < player1.hand.size(); ++N)
            {
                cout << player1.hand[N] << " ";
            }
            cout << "}" ;
            
            cout << "(Total:" << player1.total << ")" << endl;
            cout << "Hit or Stand? (h/s)" << endl;
            cin >> ans;
            if (ans == "s")
            {
                cout << endl;
                cout << "COM's hand is { ";
                for(int M = 0; M < COM.hand.size(); ++M)
                {
                    cout << COM.hand[M] << " ";
                }
                cout << "}";
                cout << "(Total:" << COM.total << ")" << endl;
                if (COM.total > player1.total)
                {
                    cout << "<<<<<  You lose...  >>>>>" << endl;
                    break;
                }
                else
                {
                    cout << "<<<<<  You win!  >>>>>" << endl;
                    cout << endl;
                    goto exit;
                }
             
            }
            else if (ans == "h"){
                player1.cards(1);
                player1.totalNum();
            }
        }while(player1.total < 21);
        cout << "Your hand is over 21..." << endl;
        cout << "**************************" << endl;
        cout << endl;
        
        exit:
        Q2:
        cout << "Play again? (y/n)" << endl;
        cin >> ans;
        if (ans == "y")
        {
            goto BJstart;
        }
        else if(ans == "n")
        {
           cout << "See you later!" << endl;
        }
        else
        {
            cout << "*** Invalid answer ***" << endl;;
            goto Q2;
        }
    }
    else {cout << "*** Invalid answer ***" << endl;;
        goto Q1;}
}

