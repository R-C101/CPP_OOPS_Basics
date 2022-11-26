#include <iostream>
using namespace std;
class Complex{
private:
    int real, imag;
public:
    Complex(int r=0, int i=0){  //parameterised constructor
      real = r;
      imag = i;
    }
    Complex operator + (Complex const &obj){
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }
    void print()
    {
        cout<<real<<"+i"<<imag<<endl;
    
    }
};
int main(){
    Complex c1(1,2),c2(3,4);
    Complex c3=c1+c2;
    c3.print();
}