#include<iostream>
#include<iomanip>

using namespace std;

int main()

{
	int n;
    cout << "Enter the value of n : ";
    cin >> n;
	
    for(int i=1; i<n; i++) {
		cout << setw(i) << i;

		for(int j=i+1; j<n; j++) {
			cout << j;
		}

		cout << n;
		
        for(int j=n-1; j>=i; j--) {
			cout << j;
		}
		
        cout << endl;
	}
	
    cout << setw(n) << n << endl;
	
    for(int i=n-1; i>=1; i--) {
		cout << setw(i) << i;
		
        for(int j=i+1; j<n; j++) {
			cout << j;
		}
		
        cout << n;
		
        for(int j=n-1; j>=i; j--){
			cout << j;
		}
		cout << endl;
	}
	
    return 0;

}