

// In C++, a namespace is a declarative region that provides a scope
// to the identifiers (names of types,functions, variables, etc.) inside it.
// Namespaces are used to organize code into logical
// groups and to prevent name conflicts that can occur
// especially when your code base includes multiple
// libraries.


#include<iostream>

// First namespace

namespace FirstNamespace{

   void sayHello() {

     std::cout << "Hello from FirstNamespace!" << std::endl;

   }

}

// Second namespace

namespace SecondNamespace {
    void sayHello() {
        std::cout << "Hello from SecondNamespace!" << std::endl;
    }
}

int main()
{
  // Calling function from FirstNamespace

  FirstNamespace::sayHello();

  // Calling function from SecondNamespace

  SecondNamespace::sayHello();

  return 0;
}

// Explanation

// Defining a Namespace:
// Namespaces are defiend using the 'namespace'
// keyword followed by the name of the namespace
// Scope Resolution Operator: To access members of a namespace, the scope resolution
// operator '::' is used. For example, 'FirstNamespace::sayHello()' calls the 'sayHello'
// function from 'FirstNamespace'.
// Preventing Name Conflicts: By defining functions with the same name in different
// namespace, you avoid conflicts and ambiguities.

// Nested Namespace

// Namespaces can also be nested within each other

namespace OuterNamespace
{

  namespace InnerNamespace
    {
      void sayHello()
      {
         std::cout << "Hello from InnerNamespace!" << std::endl;
      }

    }

}

///////////////

// We can simply access to namespaces with the 'using'
// directive or 'using' declaration

using namespace FirstNamespace;

int main()
{

 // No need to use scope resolution operator

 sayHello();

 // To call SecondNamespace:: sayHello, still need scope resolution

 SecondNamespace::sayHello();

 return 0;

}

// Namespace are a powerful feature in C++ that help
// manage large codebases and avoid name
// collions, making the code more modular and maintainable
/////
// The 'std' namespace is a standard namespace in C++
// that contains the definations for all the
//

// The 'std' namespace is a standard namespace in C++ that contains the definations for all the
// standard library functions, classes, objects and other entities. This includes the standard input
// and output stream objects ('cin','cout',etc.),containers
// ( such as 'vector','map'),placing them  in a
// namespace ensures that they won't clash with names
// in your code or third-party libraries.

// How to use 'std' Namespace

// To access the entities within the 'std' namespace,you typically
// have two options: using the scope resolution operator '::'
// or the 'using' directive

// Using the  Scope Resolution Operator

// This method involves prefixing the entities from the 'std' namespace with 'std::'.
// #include<iostream>
// #include<vector>

int main()
{
    std::cout << "Hello, World!" << std::endl; // Using std::cout
    std::vector<int> numbers; // Using std::vector

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end();++it)
    {
    std::cout << *it << " ";
    }

    return 0;
}

// Best Practices

// Use Scope Resolution for clarity: Especially in larger projects, using 'std::'
// can make your code clearer by explicity showing that you'are using stnadard libray components.

//Using Directive in Limited Scope: If you the 'using' directive , limit its scope to avoid
// potential name clashes, such as placing it within functions or limited scopes.

// Avoid in Headers: Avoid 'using namespace std;' in hader files to prevent bringing all
// names into the global scope for any file that includes the header.

///---------------------------------------------------------------------------------------------------------------//////

// In C++, a template is a powerful feature that allows you to write generic and reusable code.
// Templated enable functions and classes to operate with generic types, meaning you can define a
// function or class template to work with any data type without sacrificing type safety.
//There are two main types of templates in C++:
// Function templates and Class templates.


// Function Templates

// Function templated allow you to write a function that
// can work with any data type. Here's an example

#include<iostream>
using namespace std;

// Function template

template <typename T>

T add(T a,T b) {
    return a + b;
}

int main()
{
    cout << add(3, 4) << endl;
    cout << add(3.5, 4.5) << endl;

    cout << add(string("Hello, "), string("world!")) << endl;
    // works with string

    return 0;

}

// Class Templates
// Class templates allow you to define a class that can handle any data type. Here's an example:

// #include<iostream>
// using namespace std;

// Class template

template <typename T>
class Container {

 private:
     T value;
 public:
    Container(T val):value(val){}
    void display(){

        cout << "Value: " << value << endl;
    }
};

int main()
{
    Container<int> intContainer(42);
    intContainer.display();  // Works with int

    Container<double> doubleContainer(3.14);
    doubleContainer.display(); // Works with double

    Container<string> stringContainer("Hello, world!");
    stringContainer.display();

    return 0;
}
// Advantages of Templates

// Code Reusability: Write code once and ust it for any data type
// Type Safety: Templates ensure that the code remains type-safe.
// Performance: Templates are often used in the Standard Template Library(STL) and can be
// optimized by the compiler for different data types.

// Conclusion

// Templates in C++ provide a way to create flexible and reusable code that can work
// with any data type. They are an essential feature for writing generic programming and are widely used in
// the C++ Standard Library (STL)