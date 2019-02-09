
// STL
#include <iostream>
#include <memory>

template <typename Elem>
class Array2D {

  Array2D();
  ~Array2D();

public:
  void init(int xSize, int ySize);

private:
  std::unique_ptr< std::unique_ptr<Elem> > m_pnt;
  int m_xSize, m_ySize;
};

template <typename Elem>
void Array2D<Elem>::init(int xSize, int ySize) {

  for (int i = 0; i < xSize; i++) {
    for (int j = 0; j < ySize; j++) {

    }
  }

}

class Elem {
public:

  Elem() {
    std::cout << "Constructor Called : " << no++ << std::endl;
  }

  ~Elem() {
    std::cout << "Destructor Called : " << no-- << std::endl;
  }

public:
  static int no;
};

int Elem::no = 0;

std::ostream& operator<<(std::ostream& os, const Elem& t) {
  os << "Elem " << t.no;
  return os;  
}

static void unique_ptr_test() {
  typedef std::unique_ptr< std::unique_ptr< std::unique_ptr<Elem>[] >[] > PtrArr2D;
  typedef std::unique_ptr< std::unique_ptr<Elem>[] > PtrArr1D;
  typedef std::unique_ptr< Elem > PtrElem;

  int xSize = 5;
  int ySize = 10;


  //PtrArr2D ptr = PtrArr2D(new PtrArr1D[xSize]);
  PtrArr2D ptr = 0;
  //std::unique_ptr< std::unique_ptr<Elem []>[] > arr2d 
  //  = std::unique_ptr< std::unique_ptr<Elem []>[] >(new std::unique_ptr<Elem []>[xSize]);

  /**
  for (int i = 0; i < xSize; i++) {
    //arr2d[i] = std::unique_ptr<Elem []>(new Elem [ySize]);
    ptr[i] = PtrArr1D(new PtrElem[ySize]);
    for (int j = 0; j < ySize; j++) {
      ptr[i][j].reset(new Elem());
    }
  }

  //arr2d[2] = std::unique_ptr<Elem []>(new Elem [ySize]);
  //arr2d[1] = std::unique_ptr<Elem []>(new Elem [ySize]);
  //arr2d[3] = std::unique_ptr<Elem []>(new Elem [ySize]);
  //arr2d = std::unique_ptr< std::unique_ptr<Elem []>[] >();
  //arr2d = nullptr;

  /**
  if (ptr.get() == nullptr) {
    std::cout << "Null Pointer is Set" << std::endl;
  }

  std::cout << "After assignment" << std::endl;
  ptr[1][1] = nullptr;
  ptr[1][1].reset(new Elem());
  **/

  //std::cout << (ptr[0] == nullptr) << std::endl;
  //std::cout << "Null Ptr is set." << std::endl;

  int** ptrInt;
  std::cout << ptrInt[0] << std::endl;

  //ptr.reset(new std::unique_ptr<Elem []>[xSize]);

/**  
  for (int i = 0; i < xSize; i++) {
    ptr[i] = std::unique_ptr<Elem []>(new Elem [ySize]);
  }
  **/
/**
  for (int i = 0; i < xSize; i++) {
    for (int j = 0; j < ySize; j++) {
      std::cout << arr2d[i][j] << std::endl;      
    }
  }
**/

}

static void array_test() {
  int* a = new int[0];
}

int main(int, char const **)
{
  // unique_ptr のテスト
  unique_ptr_test();

  //array_test();
  return 0;
}
