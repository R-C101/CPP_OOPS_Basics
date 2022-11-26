#include<iostream>
using namespace std;
int main(){
    string s;
    char temp;
    cout<<"String : ";
    cin>>s;
    cout<<"String : "<<s<<endl;   
    int n = s.length();
    for(int i =0;i<n;i++){ 
        s[i] = tolower(s[i]);
    } 
    for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (s[i] > s[j]) {
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
			}
		}
	}
    cout<<"Sorted String : "<<s;
    return 0;
}