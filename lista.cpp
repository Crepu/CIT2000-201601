#include <cstdlib>
#include <iostream>

using namespace std;

class Nodo{
public:
    int valor;
    Nodo *next;

    Nodo(){
        valor = 0;
        next = NULL;
    }

    Nodo(int valor){
        this->valor = valor;
        next = NULL;
    }
};

class lista{
public:
    Nodo *head;


    void agregar(Nodo *nuevo){
        nuevo->next = head;
        head = nuevo;
    }

    void agregar(int numero){
        Nodo *nodo = new Nodo();
        nodo->valor = numero;
        agregar(nodo);
    }

    void imprimir(){
        Nodo *aux = head;
        while(aux){
            cout<<aux->valor<<"->";
            aux = aux->next;
        }
        cout<<"\n";
    }

    Nodo *buscar(int n){
        Nodo *aux = head;
        //if(aux == NULL) return NULL;
        while(aux){
            if(aux->valor == n){
                return aux;
            }
            aux =  aux->next;
        }
        return NULL;
    }

    void eliminar(int valor){
        Nodo *aux =  head;
        /*if(head != NULL && head->valor == valor){
            head = head->next;
        }
        while(aux){
            if(aux->next->valor == valor){
                aux->next = aux->next->next;
            }
            aux = aux->next;
        }*/
        if(head != NULL && head->valor == valor){
            head = head->next;
        }
        while(aux){
            if(aux->next && aux->next->valor == valor){
                aux->next = aux->next->next;
            }
            aux = aux->next;
        }
    }

    void agregarR(Nodo *nuevo, Nodo *p){
        if (!head){
            head = nuevo;
        }
        else{
            if(p && !p->next){
                p->next = nuevo;
            }
            else if(!p){
                agregarR(nuevo,head);
            }
            else if(p && p->next){
                agregarR(nuevo, p->next);
            }
            else{
                return;

            }
        }
    }
    void eliminarR(int valor, Nodo *posicion){
        //Hacer este método.
                if(!head){
            return;
        }
        else{

            if (head->valor == valor){
                head = head->next;
                return;
            }
            if (posicion->next && posicion->next->valor == valor){
                posicion->next = posicion->next->next;
                return;
            }
            else if(!posicion -> next){
                eliminarR(valor,head);
            }
            else{
                eliminarR(valor, posicion->next);
            }
        }
    }

};

 main(){
    lista *L = new lista();
    Nodo *aux = new Nodo(8);
    L->agregarR(aux,L->head);
    aux = new Nodo(6);
    L->agregarR(aux,L->head);
    aux = new Nodo(7);
    L->agregarR(aux,L->head);
    L->imprimir();

    L->eliminarR(7,L->head);
    L->imprimir();

    aux = new Nodo(7);
    L->agregarR(aux,L->head);    
    L->imprimir();

    L->eliminarR(6,L->head);
    L->imprimir();
    
    aux = new Nodo(6);
    L->agregarR(aux,L->head);    
    L->imprimir();

    L->eliminarR(8,L->head);
    L->imprimir();


    //cout<<aux->valor<<endl;
}
