#include<bits/stdc++.h>
using namespace std;

int printDivisorsBruteForce(int n){
    
    int count = 0;
    int sq = sqrt(n);
	for(int i = 1; i <= sq; i++) {
        if(n % i == 0) {
            cout << i << " ";
            if(i != n/i) {
                cout << n/i << " ";
                count = count + 2;
            }
            else {
                count = count + 1;
            }
        }
    }
    cout << endl;
    return count;
}

	
int main(){
		
	cout << endl << printDivisorsBruteForce(36);
	
return 0;
}