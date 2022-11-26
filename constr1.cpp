#include <iostream>
using namespace std;
class automobile
{
public:
    string brand;
    string model;
    int num_plate;
    automobile(string x, string y, int z); // constructor prototype with arguments

};
automobile::automobile (string x, string y, int z)
{
    brand = x;
    model = y;
    num_plate = z;

}
int main()
{
    automobile car1("alto","k10",1234);
    automobile car2("Audi", "q9",4567);
    automobile car3("Tonga","dhanno",6789);
    cout<< car1.brand <<" "<< car1.model <<" "<<car1.num_plate<<endl;
    cout<< car2.brand <<" "<< car2.model <<" "<<car2.num_plate<<endl; 
    cout<< car3.brand <<" "<< car3.model <<" "<<car3.num_plate<<endl;
}