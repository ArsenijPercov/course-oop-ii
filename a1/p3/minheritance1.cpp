/*
CH08-320143
a1 p3.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <iostream>
using namespace std;

class A
{
  int x;

public:
  void setX(int i) { x = i; }
  void print() { cout << x; }
};

class B : public virtual A // initially the problem was here, it was declared as 'public A'
{
public:
  B() { setX(10); }
};

class C : public virtual A // also here, it was declared 'public A'
{
public:
  C() { setX(20); }
};

class D : public B, public C
{
};

int main()
{
  D d;
  /* The problem is fixed now. The reason that caused the problem was
  ambiguity of the print() method. Since class D inherits both from B and C, while B and C
  both contain print() method they do not know which method to use. Therefore, to create unambigouseness
  (idk if i spelled that correct),  we can make C and B extend 'public virtual A' */
  d.print();
  return 0;
}
