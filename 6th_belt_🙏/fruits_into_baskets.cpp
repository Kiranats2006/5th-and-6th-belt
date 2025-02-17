#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int totalFruits(vector<int>& fruits){
    int n=fruits.size();
    if(n<=2){
        return 0;
    }
    int maxFruits=0, left=0, fruit1=-1, fruit2=-1, count1=0, count2=0;
    for(int right=0; right<n; right++){
        int currentFruit=fruits[right];
        if(currentFruit==fruit1) count1++;
        else if(currentFruit==fruit2) count2++;
        else{
            while(count1>0 && count2>0){
                int leftFruit=fruits[left];
                if(leftFruit==fruit1){
                    count1--;
                }
                else if(leftFruit==fruit2){
                    count2--;
                }
                left++;
            }
        }
        if(count1==0){
            fruit1=currentFruit;
            count1=1;
        }
        else{
            fruit2=currentFruit;
            count2=1;
        }
        maxFruits=max(maxFruits, right-left+1);
    }
    return maxFruits;
}
int main(){
    int n;
    cin>>n;
    vector<int> fruits(n);
    for(int i=0; i<n; i++){
        cin>>fruits[i];
    }
    cout<<totalFruits(fruits);
}