/*
Ejercicio: Programe recursivamente un método que me indique si un string es
palíndrome.

Ejercicio: Defina recursivamente la función P(n) que define el
número de palíndromes de largo n.

Ejercicio: Sea la siguiente función definida recursivamente como
f: NxN -> N
f(0,y) = y+1
f(x+1,0) = f(x,1)
f(x+1,y+1) = f(x,f(x+1,y))

Programela. (RECURSIVAMENTE... Dah!)
*/

#include <cstdlib>
#include <iostream>

using namespace std;

int foo(int x, int y){
	if(x == 0) return y+1;
	if(y == 0) return foo(x-1,1);
	return foo(x-1,foo(x,y-1));
}

int main()
{
	cout<<foo(3,1)<<endl;
	return 0;
}

