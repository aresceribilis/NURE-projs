#include<iostream>
#include<iomanip>
using namespace std;

int main() {
  for (int i = 0, itr = 1, arr[] = { 1,2,3,4,5,6 }; i < 6; i++)
    for (int j = 1 + i, itr_k = 0; j < 6; j++, itr_k++)
      for (int k = 2 + itr_k + i; k < 6; k++, itr++)
        cout << setw(3) << arr[i] << setw(3) << arr[j] << setw(3) << arr[k] << setw(5) 
      << itr << endl;

  system("pause");
  return 0;
}
