#include <iostream>
#include <cstring>
using namespace std;

bool helper(char input[], int start, int end){
    if(input[0]=='\0'||input[1]=='\0'){
        return false;
    }
    if(input[start]==input[end]){
        return helper(input+1,start+1,end-1);
    }
}



int len(char input[]){
    int count=0;
    for (int i = 0;input[i]!='\0';i++){
        count++;
    }
    cout<<count;
    return count;
}


bool checkPalindrome(char input[]) {
    int length = len(input);
    
  return helper(input,0,length);
}

 