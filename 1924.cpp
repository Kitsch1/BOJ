#include <iostream>
using namespace std;

void print_day(int mod){
    if(mod == 0) cout << "MON\n";
    if(mod == 1) cout << "TUE\n";
    if(mod == 2) cout << "WED\n";
    if(mod == 3) cout << "THU\n";
    if(mod == 4) cout << "FRI\n";
    if(mod == 5) cout << "SAT\n";
    if(mod == 6) cout << "SUN\n";
}

int main(){
    int month,day;
    cin >> month >> day;

    int month_start = 1;
    int day_elapsed = 0;

    for(int i=month_start;i<month;i++){
        if(i == 2) day_elapsed += 28;
        else if(i == 4 || i == 6 || i == 9 || i == 11) day_elapsed += 30;
        else day_elapsed += 31;
    }
    day_elapsed += (day - 1);
    print_day(day_elapsed % 7);

    return 0;
}