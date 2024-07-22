#include<bits/stdc++.h>
using namespace std;
int count_values(int n){
   int count = 0;
   string number = bitset<8>(n).to_string();
   int length = number.length();
   for (int i = 0; i < length; i++){
      if (number.at(i) == '1')
         { count++; }
   }
   count = (int)pow(2, count);
   return count;
}
int main(){
   int n = 15;
   cout<<"Count of values of x <= n for which (n XOR x) = (n – x) are: "<<count_values(n);
   return 0;
}