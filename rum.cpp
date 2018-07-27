#include <iostream>

using namespace std;


int main()
{
    int add[6] = {1,4,2,6,9,10};
    int N = 6;
    for(int i = 0; i < N - 1; i++)
      for(int j = 1; j < N-i; j++){
          if(add[j] < add[j-1]){
             int tmp = add[j];
             add[j] = add[j+1];
             add[j + 1] = tmp;
          }
      }
}
