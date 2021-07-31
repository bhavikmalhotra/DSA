#include <iostream>
using namespace std;

int all_index(int a[],int size, int x,int output){ 
    if(size == 0){
        return -1;
    }

    

    int ans = all_index(a+1,size-1,x,output);
    for(int i = 0; i< ans;i++)
    if(num == -1){
        if(a[0] == x){
            m++;
        }
        else {
            return -1;
        }

    }
    else{
        
        return num;
    }

    if(a[size-1] == x){
        return size-1;
    }


}

void AllIndexes(int input[], int n, int x)
{
	int output[n];
	int size = all_index(input, n, x, output);
	for (int i = 0; i < size; i++) {
		cout << output[i] << " ";
	}
}
int main(){

    int *p = new int[m];
    for(int i = 0; i<m;i++){
        p[i] += all_index(a,5,5);
    }

}