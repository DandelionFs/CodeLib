---
date: 2020-09-29 19:06:18 
---

本质和函数模板相同.

## TEMPLETE

LINK: http://www.cplusplus.com/doc/oldtutorial/templates/

```cpp
template <class myType>
myType GetMax (myType a, myType b) {
 return (a>b?a:b);
}
```

### USAGE
> Here we have created a template function with myType as its template parameter. This template parameter represents a type that has not yet been specified, but that can be used in the template function as if it were a regular type.

我们以myType作为模板参数创建了一个模板函数。此模板参数表示尚未指定的类型，但是可以在模板函数中使用它，就像它是常规类型一样


### FUNCTION

> When the compiler encounters this call to a template function, it uses the template to automatically generate a function replacing each appearance of myType by the type passed as the actual template parameter (int in this case) and then calls it. This process is automatically performed by the compiler and is invisible to the programmer.

当编译器遇到对模板函数的调用时，它将使用模板自动生成一个函数，该函数将myType的每个外观替换为作为实际模板参数（在本例中为int）传递的类型，然后对其进行调用。该过程由编译器自动执行，并且对于程序员是不可见的。

> In this specific case where the generic type T is used as a parameter for GetMax the compiler can find out automatically which data type has to instantiate without having to explicitly specify it within angle brackets (like we have done before specifying <int> and <long>).

如果处理的多个参数是同一类型, 那么`<>`里面的类型可以隐形调用, 而不用显示说明.

We can also define function templates that accept more than one type parameter, simply by specifying more template parameters between the angle brackets. For example:

```cpp
template <class T, class U>
T GetMin (T a, U b) {
  return (a<b?a:b);
}
```

当出现多个参数类型的时候需要使用多个模板参数得以实现.


### ClASS USAGE

```cpp
template <class T>
T mypair<T>::getmax ()
```

>  The first one is the template parameter. 
> 
> The second T refers to the type returned by the function. 
> 
> And the third T (the one between angle brackets) is also a requirement: It specifies that this function's template parameter is also the class template parameter.


### Non-type parameters for templates

```cpp
template<typename T, int N>
void func(){
  T a[N];
}
```

### SPECIALIZATION

This is the syntax used in the class template specialization:

```cpp
template <> class mycontainer <char> { ... };
```

First of all, notice that we precede the class template name with an empty template<> parameter list. This is to explicitly declare it as a template specialization.

But more important than this prefix, is the <char> specialization parameter after the class template name. This specialization parameter itself identifies the type for which we are going to declare a template class specialization (char). Notice the differences between the generic class template and the specialization:

```cpp
template <class T> class mycontainer { ... };
template <> class mycontainer <char> { ... };
```

The first line is the generic template, and the second one is the specialization.

When we declare specializations for a template class, we must also define all its members, even those exactly equal to the generic template class, because there is no "inheritance" of members from the generic template to the specialization.

当我们为模板类声明特殊化时，我们还必须定义其所有成员，甚至那些与通用模板类完全相同的成员，因为从通用模板到特殊化之间没有成员的“继承性”。

但是，比此前缀更重要的是类模板名称后面的`<char>`专门化参数。这个特殊化参数本身标识了要为其声明模板类特殊化（`char`）的类型。请注意，通用类模板和专业化之间的区别：

即专门模板与通用模板的一些区别


### MUTI-FILES

> From the point of view of the compiler, templates are not normal functions or classes. They are compiled on demand, meaning that the code of a template function is not compiled until an instantiation with specific template arguments is required. At that moment, when an instantiation is required, the compiler generates a function specifically for those arguments from the template.
>
> When projects grow it is usual to split the code of a program in different source code files. In these cases, the interface and implementation are generally separated. Taking a library of functions as example, the interface generally consists of declarations of the prototypes of all the functions that can be called. These are generally declared in a "header file" with a .h extension, and the implementation (the definition of these functions) is in an independent file with c++ code.
>
> Because templates are compiled when required, this forces a restriction for multi-file projects: the implementation (definition) of a template class or function must be in the same file as its declaration. That means that we cannot separate the interface in a separate header file, and that we must include both interface and implementation in any file that uses the templates.
>
> Since no code is generated until a template is instantiated when required, compilers are prepared to allow the inclusion more than once of the same template file with both declarations and definitions in a project without generating linkage errors.



从编译器的角度来看，模板不是正常的函数或类。它们是按需编译的，这意味着直到需要使用特定模板参数的实例化之后，才编译模板函数的代码。那时，需要实例化时，编译器会为模板中的这些参数专门生成一个函数。

当项目增长时，通常会将程序的代码拆分为不同的源代码文件。在这些情况下，接口和实现通常是分开的。以函数库为例，该接口通常由可调用的所有函数的原型的声明组成。这些通常在带有.h扩展名的“头文件”中声明，并且实现（这些函数的定义）在具有c ++代码的独立文件中。

由于模板是在需要时编译的，因此对多文件项目施加了限制：模板类或函数的实现（定义）必须与声明的文件位于同一文件中。这意味着我们不能在单独的头文件中分离接口，并且必须在使用模板的任何文件中同时包含接口和实现。

由于在需要时实例化模板之前不会生成任何代码，因此编译器准备允许在项目中使用声明和定义在同一模板文件中多次包含该模板文件，而不会产生链接错误。

## MORE

1. https://blog.csdn.net/EmSoftEn/article/details/50421124