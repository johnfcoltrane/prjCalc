#include <iostream>
#include <string.h>
#include <functional>

using namespace std;

/**
 *
 * バッファーからR/G/Bデータをrow×col分を取得
 * → SaveDataクラスへ格納 → 保存データを表示
 *
*/

const char* a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int rows = 3;
const int cols = 4;

typedef unsigned char BYTE;
typedef struct RGB_data_ {
    BYTE r;
    BYTE g;
    BYTE b;
    RGB_data_():r(0),g(0),b(0){
    }
    RGB_data_(BYTE r,BYTE g,BYTE b):r(r),g(g),b(b){
    }
    void show(const char* msg="== RGB_data =="){
        printf("%s\n", msg);
        printf("  r=%c g=%c b=%c\n",r,g,b);
    }
} RGB_data_t;

class GetData {
private:
    int rows;
    int cols;
    BYTE* buf;
public:
    GetData(int rows, int cols, BYTE* buf)
        :rows(rows),cols(cols),buf(buf){
    }
    RGB_data_t get(int i, int j){
        int n = sizeof(RGB_data_t);
        int ix = (cols*i+j)*n;
        RGB_data_t rgb(
            buf[ix], buf[ix+1], buf[ix+2]
            );
        return(rgb);
    }   
    void show(){
        cout << "== GetData ==" << endl;
        cout << "buf: " << buf << endl;
    }
};

class SaveData{
private:
    int rows;
    int cols;
    BYTE* buf;
    GetData* getdata;
    BYTE buf2[100][100][3];
public:
    SaveData(int rows, int cols, BYTE* buf, GetData* getdata)
        :rows(rows),cols(cols),buf(buf),getdata(getdata){
    }
    //typedef function<RGB_data_t(GetData*,int,int)> fnGetData_t;
    void data_copy(){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                RGB_data_t rgb = getdata->get(i,j);
                buf2[i][j][0] = rgb.r;
                buf2[i][j][1] = rgb.g;
                buf2[i][j][2] = rgb.b;
            }
        }
    }
    void show(){
        cout << "==== SaveData ====" << endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout << buf2[i][j][0]; 
                cout << buf2[i][j][1]; 
                cout << buf2[i][j][2];
                cout << "/";
            }
            cout << endl;
        }
    }
};

int main(){
    GetData gdt(rows, cols, (BYTE *)a);

    cout << "** Hello! **" << endl;
    //cout << sizeof(a) << endl;
    cout << sizeof(RGB_data_t) << endl;
    //cout << strlen(a) << endl;
    gdt.show();
    RGB_data_t rgb = gdt.get(0,0);
    rgb.show();
#if 0
    gdt.get(0,1).show();
    gdt.get(0,2).show();
    gdt.get(0,3).show();
    cout << "------------" << endl;
    gdt.get(0,1).show();
    gdt.get(1,0).show();
    gdt.get(2,0).show();
#endif
    //typedef RGB_data_t (*fnGetData_t)(GetData* buf, int i, int j);
    //typedef function<RGB_data_t(GetData*,int,int)> fnGetData_t;
    //fnGetData_t 
    auto fngetdata = [](GetData* oGetdata, int i, int j){
        return(oGetdata->get(i, j));
    };
    RGB_data_t rgb2 = fngetdata(&gdt, 0, 1);
    rgb2.show(); 
    
    SaveData svdt(rows, cols, (BYTE*) a, &gdt);
    svdt.data_copy();
    svdt.show();
}