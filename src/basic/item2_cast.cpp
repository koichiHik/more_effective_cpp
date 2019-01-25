
#include <iostream>
#include <string>
#include <typeinfo>

class Parent {

  virtual void hoge() = 0;

};

class ChildA : public Parent {

  virtual void hoge() {}

public:
  int m_a;

};

class ChildB : public Parent  {

  virtual void hoge() {}

public:
  int m_b;

};

static void const_cast_test() {
 
  // Const Cast のサンプルコード
  const int original = 100;
  const int* a = &original;
  *(const_cast<int*>(&original)) = 1000;
  std::cout << "Original : " << original << std::endl;
  std::cout << "*(&Original) : " << *(&original) << std::endl;
  std::cout << "a : " << *a << std::endl;

  return;
}

static void dynamic_cast_test() {

  // dynamic_cast を使ったポインタのダウンキャスト．成功例
  {
    Parent *pp;
    ChildA ca;
    pp = &ca;
    ChildA* cc = dynamic_cast<ChildA*>(pp);
    if (cc != nullptr) {
      std::cout << "ダウンキャスト成功！" << std::endl;
    } else {
      std::cout << "ダウンキャスト失敗！" << std::endl;
    }
  }

  // dynamic_cast を使ったポインタのダウンキャスト．失敗例
  {
    Parent *pp;
    ChildB cb;
    pp = &cb;
    ChildA* ca = dynamic_cast<ChildA*>(pp);
    if (ca != nullptr) {
      std::cout << "ダウンキャスト成功" << std::endl;
    } else {
      std::cout << "ダウンキャスト失敗！" << std::endl;
    }
  }

  // dynamic_cast を使った参照のダウンキャスト．成功例
  {
    Parent *pp;
    ChildA ca;
    pp = &ca;
    try {
      ChildA cc = dynamic_cast<ChildA &>(*pp);
      std::cout << "ダウンキャスト成功！" << std::endl;
    } catch (std::exception &e) {
      std::cout << "ダウンキャスト失敗！" << std::endl;
      std::cout << e.what() << std::endl;
    }
  }

  // dynamic_cast を使った参照のダウンキャスト．失敗例
  {
    Parent *pp;
    ChildB cb;
    pp = &cb;
    try {
      ChildA ca = dynamic_cast<ChildA &>(*pp);
      std::cout << "ダウンキャスト成功" << std::endl;
    } catch (std::exception &e) {
      std::cout << "ダウンキャスト失敗！" << std::endl;
      std::cout << e.what() << std::endl;
    }
  }

}

double func1() {
  std::cout << "func1 Called!" << std::endl;
  return 1.0;
}

static void reinterpret_cast_test() {

  typedef void (*FuncPtr)();
  // 戻り値の型が違うので，コンパイルが通らない．
  //FuncPtr funcPtr = &func1;

  // FuncPtrのシグニチャに合わせてあげると，OK！
  FuncPtr funcPtr = reinterpret_cast<FuncPtr>(&func1);
  funcPtr();
}

int main(int, char const**)
{
  std::cout << __FILE__ << "Started!" << std::endl;

  // Const Cast のサンプル．
  const_cast_test();

  // Dynamic Cast のサンプル．
  dynamic_cast_test();

  // Reinterpret Cast のサンプル．
  reinterpret_cast_test();

  return 0;
}
