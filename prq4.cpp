#include<iostream>
using namespace std;
int main()
{
int i,can[5],ballot,count[5];
char ch;
for(i=0;i<=5;i++)
{
count[i]=0;
}
do
{
cout<<"\nEnter the ballot number :";
cin>>ballot;
switch(ballot)
{
case 1: count[1]++;
break;
case 2: count[2]++;
break;
case 3: count[3]++;
break;
case 4: count[4]++;
break;
case 5: count[5]++;
break;
default: count[0]++;
}
cout<<" \nWant to vote again\n";
cin>> ch;
}
while(ch=='y');
for(i=1;i<=5;i++)
{
cout<<"\nNo:of votes for candidate "<< i <<"="<<count[i];

}
cout<<"\n Sploit ballots are "<<count[0];
return 0;
}