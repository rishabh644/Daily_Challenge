#include<iostream>

using namespace std;


class Base
{
   public:
     virtual void show()
     {
         cout << "Base\n";
     }
};


class Derv1:public Base // derived class 1
{
    public:
       void show()
       {
           cout << "Derv1\n";
       }
};


class Derv2:public Base
{
   public:
      void show()
        {
            cout << "Derv2\n";
        }
};

int main()
{

    // Base bad; can't make object from abstract class

    Base *arr[2];

    Derv1 dv1;
    Derv2 dv2;

    arr[0] = &dv1; // put address of dv1 in array
    arr[1] = &dv2; // put address of dv2 in array

    arr[0]->show();
    arr[1]->show();

    return 0;
}