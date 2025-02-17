#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count5=0, count10=0;
    int bill;
    for(int i=0; i<n; i++){
        cin>>bill;
        if(bill==5){
            count5++;
        }
        else if(bill==10){
            if(count5>0){
                count5--;
                count10++;
            }
            else{
                cout<<"false";
                return 0;
            }
        }
        else if(bill==20){
            if(count10>0 && count5>0){
                count10--;
                count5--;
            }
            else if(count5>=3){
                count5-=3;
            }
            else{
                cout<<"false";
                return 0;
            }
        }
    }
    cout<<"true"<<endl;
    return 0;
}