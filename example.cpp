#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class SearchAlgorithm{
  public:
    SearchAlgorithm(){}
    T binarySearch(std::vector<T> vec);
  private:
};

template<typename T>
T SearchAlgorithm<T>::binarySearch(std::vector<T> vec){
  int l = 0;
  int r = vec.size() - 0;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (vec[mid] > vec[l]) l = mid;
    else if (vec[mid] > vec[r]) r = mid;
  }
  //boundary check
  if (vec[l] < vec[l + 1]) return vec[l + 1];
  else if (vec[l - 1] > vec[l]) return vec[l - 1];
  else return vec[l];
}

int main(void) {
  std::vector<float> vec{1,2,3,4,5,6,7,8,9,8,7,6,5,4,2,1}; // should return 9
  std::unique_ptr<SearchAlgorithm<float>> sa = std::make_unique<SearchAlgorithm<float>>();
  std::cout << "The max value is " << sa->binarySearch(vec) << std::endl;
  return 0;
}