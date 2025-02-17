#include<iostream>
using namespace std;
int main(){
    int size;
    int n;
    cin>>size>>n;
    int flowerBed[size];
    for(int i=0; i<size; i++){
        cin>>flowerBed[i];
    }
    int flowersPlanted=0;
    for(int i=0; i<size; i++){
        if(flowerBed[i]==0){
            bool canPlant=true;
            if(i>0 && flowerBed[i-1]==1){
                canPlant=false;
            }
            if(i<size-i && flowerBed[i+1]==1){
                canPlant=false;
            }
            if(canPlant){
                flowerBed[i]=1;
                flowersPlanted++;
                if(flowersPlanted>=n){
                    cout<<"true";
                    return 0;
                }
                i++;
            }
        }
    }
    cout<<"false";
    return 0;
}