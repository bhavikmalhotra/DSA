#include <iostream>
using namespace std;

int main(){
    int p,q;
    cin>>p>>q;
    int **p = int *[p];
    for(int i=0; i<p;i++){
        int k;
        cin>>k;
        p[i] = new int[k];
        for(int j=0;j<k;j++){
            cin>>p[i][j];
        }
    }

    int x,y;
    for(int i=0;i<p;i++){
        cin>>x>>y;
        cout<<seq[x][y]<<endl;
    }

}

/*
Input Format

The first line contains two space-separated integers denoting the respective values of
(the number of variable-length arrays) and (the number of queries).
Each line of the subsequent lines contains a space-separated sequence in the format k a[i]0 a[i]1 … a[i]k-1 describing the -element array located at .
Each of the subsequent lines contains two space-separated integers describing the respective values of (an index in array ) and (an index in the array referenced by

) for a query.

Constraints

All indices in this challenge are zero-based.
All the given numbers are non negative and are not greater than

Output Format

For each pair of
and values (i.e., for each query), print a single integer that denotes the element located at index of the array referenced by . There should be a total of

lines of output.

Sample Input

2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3

Sample Output

5
9
*/
