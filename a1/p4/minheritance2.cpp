/*
CH08-320143
a1 p4.cpp
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <iostream>
using namespace std;

class A
{
  int x;

public:
  A(int i) { x = i; }
  void print() { cout << x; }
};

class B : public virtual A // instead of virtual public, wrote public virtual
{
public:
  B() : A(10) {}
};

class C : public virtual A // instead of virtual public, wrote public virtual
{
public:
  C() : A(10) {}
};

class D : public B, public C
{
  /* Since B and C are 'public virtual A', extending D with B and C
  does not make a direct connection with A, i.e., D does not have any
  concept of A constructor. Therefore we need to call it manually. */
  public: 
  D() : A(20), B(), C() {}
};

int main()
{
  D d;
  d.print();
  return 0;
}
