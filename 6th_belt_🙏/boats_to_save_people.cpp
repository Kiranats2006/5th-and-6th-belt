#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int resueBoats(vector<int>& people, int limit){
    int n=people.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(people[j]>people[j+1]){
                int temp=people[j];
                people[j]=people[j+1];
                people[j+1]=temp;
            }
        }
    }
    int i=0, j=n-1, boats=0;
    while(i<=j){
        if(people[i]+people[j]<=limit){
            i++;
        }
        j--;
        boats++;
    }
    return boats;
}
int main(){
    int n;
    cin>>n;
    vector<int> people(n);
    for(int i=0; i<n; i++){
        cin>>people[i];
    }
    int limit; 
    cin>>limit;
    cout<<resueBoats(people, limit);
}