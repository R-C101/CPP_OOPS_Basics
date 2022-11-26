#include<iostream>
using namespace std;

class date{
    
    int day,month,year;

    public:
   
    void init_date(int& d, int& m, int& y){
        if(m>12){
            y+=(m/12);
            m%=12;
        }
        
        switch(m){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: if(d>31){
                        m+=(d/31);
                        d%=31;
                    }
                    break;
            case 4:
            case 6:
            case 9:
            case 11: if(d>30){
                        m+=(d/30);
                        d%=30;
                    }
                    break;
            case 2: int l=0;
                    if(y%400==0) l=1;
                    else if(y%4==0)l=1;
                    if (l&&(d>29)){
                        m+=(d/29);
                        d%=29;                        
                    }
                    else if((!l)&&(d>28)){
                        m+=(d/28);
                        d%=28;
                    }
        }

        if(m>12){
            y+=(m/12);
            m%=12;
        }
        
    }

    
    date (int d=0, int m=0, int y=0){
        
        init_date(d,m,y);
        day=d;
        month=m;
        year=y;
    }

    //display
    void dis_date(){
        init_date(day,month,year);
        cout<<"\nDate : "<<day<<"/"<<month<<"/"<<year;
    }
    
    //setter
    void set_date(){
        cout<<"\nGive Day//Month//Year with space : ";
        cin>>day>>month>>year;
        init_date(day,month,year);
    }

    //getter
    int get_day(){return day;}
    int get_month(){return month;}
    int get_year(){return year;}
    
    //overloading operators
    bool operator < (const date &d){
        if(year<d.year) return true;
        else if((year==d.year)&&(month<d.month)) return true;
        else if((year==d.year)&&(month==d.month)&&(day<d.day)) return true;
        return false;
    }

    bool operator <= (const date &d){
        if(year<d.year) return true;
        else if((year==d.year)&&(month<d.month)) return true;
        else if((year==d.year)&&(month==d.month)&&(day<d.day)) return true;
        else if((year==d.year)&&(month==d.month)&&(day==d.day)) return true;
        return false;
    }

    bool operator > (const date &d){
        if(year>d.year) return true;
        else if((year==d.year)&&(month>d.month)) return true;
        else if((year==d.year)&&(month==d.month)&&(day>d.day)) return true;
        return false;
    }

    bool operator >= (const date &d){
        if(year>d.year) return true;
        else if((year==d.year)&&(month>d.month)) return true;
        else if((year==d.year)&&(month==d.month)&&(day>d.day)) return true;
        else if((year==d.year)&&(month==d.month)&&(day==d.day)) return true;
        return false;
    }

    bool operator == (const date &d){
        if((year==d.year)&&(month==d.month)&&(day==d.day)) return true;
        return false;
    }

    bool operator != (const date &d){
        if((year==d.year)&&(month==d.month)&&(day==d.day)) return false;
        return true;
    }

    date operator ++(){
        return date(++day, month, year);
    }

    date operator ++ (int){
        return date(day++, month, year);
    }

    date operator + (const date &d){
       date t;
       t.day=day+d.day;
       t.month=month+d.month;
       t.year=year+d.year;
       return t;
    }

    

    void operator = (int &days){
        days=day;

        for(int i=1; i<month; i++){
            switch(i){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12: days+=31;
                        break;
                case 4:
                case 6:
                case 9:
                case 11: days+=30;
                        break;
                case 2: int l=0;
                        if(year%400==0) l=1;
                        else if(year%4==0)l=1;

                        if (l)  days+=29;           
                        else days+=28;
            }
    
        } 
    }
};


int main(){
    date a(2,4,2018), b(20,2,2021);
    a.dis_date();
    b.dis_date();
    if(a<=b){
        cout<<"\ntrue";
    }
    else{
        cout<<"\nfalse";
    }
    a=a+(b++);
    a.dis_date();
    b.dis_date();
    int days;
    a=days;
    cout<<"\nDays : "<<days;
    return 0;
}