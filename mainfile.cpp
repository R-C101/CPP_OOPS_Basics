#include <iostream>
using namespace std;
void greatest(){
  int a,b,c;
  cin>>a;
  cin>>b;
  cin>>c;
  if(a>b && a>c){
    cout<<a<<"is the greatest"<<endl;
  }
  else if(b>c && b>a){
    cout<<b<<"is the greatest"<<endl;
  }
  else{
    cout<<c<<"is the greatest"<<endl;
  
  }

}
int main(){
  cout<<"Enter 3 numbers one by one:"<<endl;
  greatest();
  return 0;
}