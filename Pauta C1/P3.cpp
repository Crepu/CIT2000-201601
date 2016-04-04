#include <iostream>
#include <stack>

using namespace std;

bool balanced(string par){
	stack <char> pila;
	for(int i = 0;i < par.size(); i++){
		if(par[i] == '('){
			pila.push(')');
		}
		else if(par[i] == '['){
			pila.push(']');
		}
		if((par[i] == ')' || par[i] == ']') && pila.size() == 0){
			return false;
		}
		if(par[i] == ')' || par[i] == ']'){
			char aux = pila.top();
			pila.pop();

			if(aux != par[i]){
				return false;
			}
		}
	}
	if(pila.size() != 0) return false;
}

int main(int argc, char const *argv[])
{
	string par;
	cin>>par;
	if(balanced(par)) cout<<"balanced"<<endl;
	else cout<<"unbalanced"<<endl;


	return 0;
}