# Missions<br>
As C++ grows old it need to be updated in a morden way.<br>
## Non-Premitive DataTypes
  *String<br>
  *Int<br>
  *Double<br>  
## Multiple datatype array 
### Creating dynamic array with multiple datatypes in it
~~~
Array y = {50,70,"ram"};
~~~
### Get the value by position
~~~
std::string x = y.getValue<std::string>(2); // x now contains "ram"
std::cout<< x;

//OR USE

String x =  x = y.getValue<String>(2); // x now contains "ram"
x.debug();
~~~
