#include <iostream>
#include <vector>
using namespace std;


vector<int> mergeSort(vector<int> A);
vector<int> merge(vector<int> A, vector<int> B);

int main() {
  vector<int> test = {2,3,4,6,9,1,11,-2};
  vector<int> testSmall = {2,1};

  cout << mergeSort(testSmall);
  return 0;
}

// Making a function that returns an array
// vector<int> makeArray() {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     return arr;  // returns a whole vector
// }

vector<int> mergeSort(vector<int> A) {
  if (A.size() <= 1) {
    return A;
  }
  else {
    int i = int(A.size() / 2);
    // List slicing in cpp can be done like. vector<int> sub(nums.begin() + 1, nums.begin() + 4);
    vector<int> X = mergeSort(A.begin(), A.begin() + i);
    vector<int> Y = mergeSort(A.begin() + i, A.begin() + A.size());
    return merge(X, Y);
  }
}

vector<int> merge(vector<int> A, vector<int> B) {
  vector<int> D;
  int i = 0;
  int j = 0;

  while (i < A.size()) and (j < B.size()) {
    if (A.begin() + i) < (B.begin() + i) {
      // to append to a vector it is myVector.push_back(x);
      D.push_back(A.begin() + i);
      i++;
    }
    else {
      D.push_back(B.begin() + j);
      j++;
    }
  }
  if (!A.empty()){
    while i < A.size() {
      D.push_back(A.begin() + i);
      i++;
    }
  }
  if (!B.empty()){
    while j < B.size() {
      D.push_back(A.begin() + i);
      j++;
    }
  }
  return D
}