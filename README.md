## Overview<br>
Creating dynamic array with multiple datatypes in it. Better and simpler than tupple.<br>
Adding more functionality to primitive datatypes. As C++ grows old it need to be updated in a morden way.<br>
[Array](https://github.com/LUCIF680/Nile#array)<br>
[String](https://github.com/LUCIF680/Nile/edit/master/README.md#array)<br>
[Int](https://github.com/LUCIF680/Nile/edit/master/README.md#array)<br>
[Double](https://github.com/LUCIF680/Nile/edit/master/README.md#array)<br>
[Namespace](https://github.com/LUCIF680/Nile/edit/master/README.md#array)<br>

### How to download 
Header only Library. Download the file from [here](https://lucif680.github.io/Nile/nile.h).
## Non-Premitive DataTypes
  *String<br>
  *Int<br>
  *Double<br>  
  
<section id="array">
</sction>
  
## Multiple datatype array 
#### Creating dynamic array with multiple datatypes in it
~~~
Array y = {50,70,"ram"};
~~~
#### Get the value by position
Return Type should be set by the developer
~~~
std::string x = y.getValue<std::string>(2); // x now contains "ram"
std::cout<< x;

//OR USE
// Non - Premitive class
String x =  x = y.getValue<String>(2); // x now contains "ram"
x.debug();
~~~
You must give return type in getValue function. Argument is the position of array.

#### Set the value by position
Return type void
~~~
Array y = {50,70,"ram"};
y.setValue(1,19); // now y = {50,19,"ram"}
~~~
It will change the value of exsisting index with new value. Type should be same.
You must give return type in getValue function. Argument is the position of array and the new value.


#### Return the length of Array
Return type is size_t
~~~
Array y = {50,70,"ram"};
size_t array_size = y.length();
std::cout << array_size; // Prints 3
~~~

#### Push array
Return type is void
~~~
Array y = {50,70,"ram"};
y.push("hello");
y.push(65.4);
// y = {50,70,"ram","hello",65.4}
~~~
Add an element at the end of the array.

## String 
In process to create it UTF-8 support.

#### Return the length of String
Return type is size_t
~~~
String y = "Hello World";
size_t array_size = y.length();
std::cout << array_size; // Prints 3
~~~
