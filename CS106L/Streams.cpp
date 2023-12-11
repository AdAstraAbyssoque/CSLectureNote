#include<bits/stdc++.h>
using namespace std;

int main(){
    string initial_quote = "Bjarne Stroustrup C makes it easy to shoot yourself in the foot";
    stringstream ss(initial_quote);
    string first;
    string last;
    string language,extracted_quote;
    ss>>first>>last>>language>>extracted_quote;
    getline(ss,extracted_quote,'\n');
    std::cout << first << " "<< last << " said this: "<< language << " " <<extracted_quote << std::endl;
    return 0;
}