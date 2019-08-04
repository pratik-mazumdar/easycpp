## Overview<br>
Framework for adding more
Adding more functionality to primitive datatypes. As C++ grows old it need to be updated in a morden way.<br>
We will be using namespace easycpp in our following documentation.

```
using namespace easycpp;
```

## INDEX

       
<details open>
<summary>Tupple Methods</summary>
<br>
   STL contains tupple but its not very easy to use.easycpp tupple adds more functionality and simplicity. 

   [constructor](https://github.com/LUCIF680/easycpp#creating-tupple)<br>
   [get_value](https://github.com/LUCIF680/easycpp#get-the-value-by-position)<br>
   [set_value](https://github.com/LUCIF680/easycpp#set-the-value-by-position)<br>
   [length](https://github.com/LUCIF680/easycpp#return-the-length-of-tupple)<br>
   [pop](https://github.com/LUCIF680/easycpp#pop-an-element-tupple)<br>
   [push](https://github.com/LUCIF680/easycpp#push-an-element-tupple)<br>
   [concatenate](https://github.com/LUCIF680/easycpp#concatenate-two-tupple)<br>
</details>
<br>
<details open>
<summary>String Methods (In Work)</summary>
<br>
       
   [length](https://github.com/LUCIF680/easycpp#return-the-length-of-string)<br>
</details>
       

### How to download 
Header only Library. Download the file from [here](https://lucif680.github.io/Nile/nile.h).
## Non-Premitive DataTypes
  *String<br>
  *Int<br>
  *Double<br>  

### Header files used
*iostream<br>
*string<br>
*map<br>

## Tupple
#### Creating tupple
~~~
Tupple y = {50,70,"ram"};
~~~
#### Get the value by position
Return Type should be set by the developer.<br>
Possible return types are<br>
long double for all double,float types<br>
long for int,long types<br>
std::string for strings and const char*<br>
~~~
std::string x = y.getValue<std::string>(2); // x now contains "ram"
std::cout<< x;

//OR USE
// Non - Premitive class
String x = y.get_value<String>(2); // x now contains "ram"
x.debug();
~~~
You must give return type in getValue function. Argument is the position of array.

#### Set the value by position
Return type void
~~~
Tupple y = {50,70,"ram"};
y.set_value(1,19); // now y = {50,19,"ram"}
~~~
It will change the value of exsisting index with new value. Type should be same.
You must give return type in getValue function. Argument is the position of array and the new value.


#### Return the length of tupple
Return type is size_t
~~~
Tupple y = {50,70,"ram"};
size_t tupple_size = y.length();
std::cout << array_size; // Prints 3
~~~

#### Push an element tupple
Return type is void
~~~
Tupple y = {50,70,"ram"};
y.push("hello");
y.push(65.4);
// y = {50,70,"ram","hello",65.4}
~~~
Add an element at the end of the array.

#### Pop an element tupple
Return type is void
~~~
Tupple y = {50,70,"ram"};
y.pop(0);
// y = {70,"ram"}
~~~
Add an element at the end of the array.

#### Concatenate two tupple
Return type is Array
~~~
Tupple y = {50,70,"ram"};
Tupple x = {36.1,12,"shyam"};
Tupple z = x + y;
// z = {50,70,"ram",36.1,12,"shyam"}
~~~
Add an element at the end of the array.


## String 
In process to create it UTF-8 support.

#### Return the length of String
Return type is size_t
~~~
String y = "Hello World";
size_t length = y.length();
std::cout << length; // Prints 11
~~~
