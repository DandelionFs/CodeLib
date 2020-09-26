---
title : java
---

> Q: What is `AnyType` in java. When should i use it. For example `TestRpn>` in this code snippet what is `AnyType`, and what kind of data it can have (i.e, like Integer,Boolean)

A: There is no predefined type named `AnyType`. I am guessing you have come across a poorly named type parameter variable. The naming convention for type variables is [suggested to be single uppercase letters](http://docs.oracle.com/javase/tutorial/java/generics/types.html), to avoid this type of confusion.

In your case, `TestRpn>` should be rephrased as `TestRpn>`, which in turn means that you can substitute any type for E that  implements Comparable for it's own type. Example: java.lang.String  implements `Comparable`, so `TestRpn` is a valid parametrization of the above base type.



A: AnyType is actually used in java7+. It can be said that its usage is  same as that of  E or T or something. As the name suggests it can any  type of generic data. for example, when I implemented my generic linked list in Java, I used

```
private Node<AnyType> head;
```

where the word AnyType stands for the generic type Node.