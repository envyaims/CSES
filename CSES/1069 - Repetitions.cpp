#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    string a;
    cin>>a;
    int output,tempout = 1;
    for(int i = 0; i < a.length()-1; i++){
        if(a[i] == a[i+1]){
            tempout++;
        }
        else{
            output = fmax(output,tempout);
            tempout = 1;
        }
    }
    output = fmax(output,tempout);
    cout<<output;

    return 0;
}

