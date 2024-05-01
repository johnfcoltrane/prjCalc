// AllocDealloc.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;

static int g_cnt = 0;
static int g_cnt2 = 0;

class A {
    int x;
public:
    A() {
        g_cnt++;
        x = g_cnt;
        //cout << "** new A():x=" << x << endl;
    }
    ~A() {
        g_cnt2++;
        //cout << "** delete ~A();x=" << x << endl;
    }
};
void pause() {
    cout << g_cnt << " / " << g_cnt2 << endl;
    cout << "pause:";
    int x = getchar();
}
void test1()
{
    int x;
    pause();
    std::cout << "@@@@@ Start @@@@@\n";
    //A a[0x10000];
    A* pa = new A[0x10000];
    //cout << g_cnt << endl;
    //cout << "pause:";
    pause();
    //cin >> x;
    //x = getchar();
    std::cout << "@@@@@ End @@@@@\n";
    //cout << g_cnt << endl;
    delete[] pa;
    pause();
}
int main(){
    test1();
    pause();
}
// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
