#include<iostream>
#include<algorithm>
using namespace std;

string bubbleSort(string& s){
    int n=s.length();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(s[j]>s[j+1]){
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
bool checkInclusion(string s1, string s2){
    int n1=s1.length(), n2=s2.length();
    if(n1>n2){
        return false;
    }
    bubbleSort(s1);
    int freq1[26]={0}, freq2[26]={0};
    for(int i=0; i<n1; i++){
        freq1[s1[i]-'a']++;
        freq2[s2[i]-'a']++;
    }
    bool match=true;
    for(int i=0; i<26; i++){
        if(freq1[i]!=freq2[1]){
            match=false;
            break;
        }
    }
    if(match) return true;
    for(int i=n1; i<n2; i++){
        freq2[s2[i]-'a']++;
        freq2[s2[i-n1]-'a']--;
        match=true;
        for(int j=0; j<26; j++){
            if(freq1[j]!=freq2[j]){
                match= false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(checkInclusion(s1,s2)){
        cout<<true;
    }
    else{
        cout<<false;
    }
    return 0;
}