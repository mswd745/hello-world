/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;

void print_v(vector<int> &v, vector<int> &v1) {
    int max = v.size()>100?100:v.size();
    for(int i=0; i<max; i++) {
        cout << v[i] << "," << v1[i] << endl; 
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> v1(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        v1[i] = 1;
    }
    
    int i=1,k;
    while(i<n) {
        if(v[i]>v[i-1]) {
            v1[i] = v1[i-1]+1;
            i++;
        } else if(v[i]<v[i-1]) {
            i++;
            while(i<n && v[i]<v[i-1])
                i++;
            k = i-2;
            while(k>=0 && v[k]>v[k+1]) {
                if(v1[k+1]+1 > v1[k])                
                    v1[k] = v1[k+1]+1;
                k--;
            }
        } else
            i++;
    }

print_v(v,v1);
    long int sum=0;
    for(int i=0; i<n; i++)
        sum += v1[i];
    cout << sum << endl;
    return 0;
}
