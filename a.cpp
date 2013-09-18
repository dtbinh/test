#include <iostream>
#include <stdlib.h>
using namespace std;
class person {
  private:
    char name[20];
    int scr1,scr2,scr3;
    int a,b;
  public:
    void input(){
    cout<<"请输入姓名"<<endl;
    cin>>name;
    cout<<"请输入三门课成绩"<<endl;
    cin>>scr1>>scr2>>scr3;
    }
    void cal(){
    a=scr1+scr2+scr3;
    b=a/3;
    }
    void show(){
    cout << "姓名:" << name<<endl;
    cout << "三门课成绩" <<scr1<<scr2<<scr3<<endl;
    cout <<"总分:"<<a<<"平均分"<<b<<endl;
    }
};

int main () {
  int num,i;
  person p[20];
  cout<<"请输入人数"<<endl;
  cin>>num;
  for ( i=0; i<num; i++ ){
    p[i].input();
    p[i].cal();
    p[i].show();
  
  }
  
}
