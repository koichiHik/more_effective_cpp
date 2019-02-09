
#include <iostream>

void double_pointer_array_test() {

  int x_len = 10;
  int y_len = 5;

  // リソースの確保．
  double** arr = new double*[x_len];
  for (int i = 0; i < x_len; i++) {
    arr[i] = new double[y_len];
  }

  // リソースの解放．
  for (int i = 0; i < x_len; i++) {
    delete [] arr[i];
  }
  delete [] arr;
}

int main(int, char const **)
{
  std::cout << __FILE__ << " Started!" << std::endl;

  // double の二重ポインタ領域を確保するテスト．
  double_pointer_array_test();

  int a = 8;
  std::cout << (a >> 1) << std::endl;

  return 0;
}
