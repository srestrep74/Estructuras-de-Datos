#include<bits/stdc++.h>
using namespace std;

//Creamos la clase nodo en donde damos la estructura de lo que contiene un nodo con dos constructores disponibles
class Node{
    public:
        int data; //Dato que contiene el nodo
        Node *next; //Puntero al siguiente nodo
        Node(){this->data = 0 ; this->next = NULL;}
        Node(int data){this->data = data ; this->next = NULL;}
};

//Creamos la clase lista la cual contendra la cabeza de la lista y un atributo adicional para llevar un control del tamano de la lista
class LinkedList{
    public:
        int size; //Atributo que se ira actualizando con el tamano de la lista 
        Node *head; //Creamos un puntero hacia el nodo cabeza de nuestra lista
        LinkedList(){this->size = 0 ; this->head = new Node();} //Constructor
};

//Funcion para eliminar el primer nodo de una lista
//Complejidad Temporal: O(1)
//Complejidad Espacial: O(1)
//Esta funcion recibira el puntero a la lista, y la referencia del nodo cabeza
void pop(LinkedList *list, Node *&head){
    //Verificamos que la lista no este vacia
    if(list->size > 0){
        //Guardaremos la referencia del primer elemento para no perderla luego de hacer las otras operaciones
        Node *temp = head->next;
        //El primer elemento de la lista ahora debe de ser el siguiente del actual primero
        //Es decir, el siguiente de cabeza debe de apuntar al siguiente del primer elemento
        head->next = head->next->next;
        //Ahora, como guardamos en el nodo temp, la referencia al nodo que fue el primero de la lista, lo debemos desvincular de ella, por lo que pondremos a apuntar como su siguiente a nulo
        temp->next = NULL;
        //Decrementamos la longitud de la lista
        list->size--;
        //Eliminamos esta referencia de memoria ya que no la utilizaremos mas 
        delete temp;
    }
}

//Funcion para eliminar ultimo nodo de una lista enlazada
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(1)
//Esta funcion recibira el puntero a la lista, y la referencia del nodo cabeza
void popLast(LinkedList *list, Node *&head){
    //Verificamos que la lista no este vacia
    if(list->size > 0){
        //Creamos un nodo que nos servira como nodo actual, y este lo inicializaremos en el primer nodo, es decir, el siguiente de la cabeza
        Node *curr = head->next;
        //Crearemos otro nodo el cual servira para siempre tener una referencia al nodo previo de curr
        Node *prev = head;
        //Iteramos hasta que el siguiente de curr sea nulo. Esto quiere decir que curr se encuentra en el ultimo nodo de la lista y alli es donde debemos de parar para realizar las respectivas operaciones de eliminado de ese nodo
        while(curr->next != NULL){
            //Corremos ambos nodos a sus siguientes , empezando actualizando el prev
            prev = curr;
            curr = curr->next;
        }
        //Una vez finalizado el ciclo, sabemos que curr esta actualmente en el ultimo, y prev es el nodo antes de este
        //Antes de eliminar este ultimo nodo, debemos de asegurarnos que la lista siga su flujo normal, por lo que el previo debe de apuntar al siguiente de curr
        prev->next = curr->next;
        //Desvincularemos de la lista a curr haciendolo apuntar a nulo
        curr->next = NULL;
        //Decrementamos la longitud de la lista
        list->size--;
        //Eliminamos de memoria curr, el cual correspondia al ultimo nodo de la lista
        delete curr;
    }
}

//Funcion para eliminar ultimo nodo de la lista recursivamente
//Complejidad Temporal : O(n)
//Complejidad Espacial : O(n)
//Esta funcion recibira el puntero a la lista, la referencia al nodo cabeza, y dos nodos auxiliares prev y curr, en donde llegara siendo el primer nodo de la lista y prev, la cabeza.
void _popLast(LinkedList *list, Node *&head, Node *&prev, Node *&curr){
    //Caso Base:
    //Si el nodo curr, el cual es el que se va a mover en el algoritmo junto con prev, si el siguiente de curr es nulo, quiere decir que ha llegado al ultimo nodo de la lista, por lo que ahi toca parar y hacer la operacion de eliminar
    if(curr->next == NULL){
        //En este punto, antes de eliminar el ultimo nodo , es decir, curr, debemos de asegurarnos de que la lista siga conectada y no pierda su flujo
        //Para esto haremos que prev, apunte al siguiente de curr, lo que hara que la lista siga normal, y ya no se tenga acceso a curr pr ningun lado de la lista
        prev->next = curr->next;
        //Desvinculamos a curr de la lista haciendolo apuntar a nulo
        curr->next = NULL;
        //Decrementamos el valor de la longitud de la lista
        list->size--;
        //Eliminamos el ultimo nodo de memoria, es decir, a curr
        delete curr;
        return;
    }else{
        //Si el caso base no se cumple, significa que no hemos llegado al final de la lista, por lo que toca avanzar los dos nodos auxiliares a sus siguientes
        prev = curr;
        curr = curr->next;
        //Con estos datos actualizados, llamamos recursivamente la funcion con estos nuevos valores
        _popLast(list, head, prev, curr);
    }
}

//Funcion para eliminar un nodo en un posicion determinada
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(1)
//Esta funcion recibira el puntero a la lista, la referencia del nodo cabeza, y la posicion
void erase(LinkedList *list, Node *&head, int pos){
    //Verificamos que la lista no este vacia y que la posicion no sea ni mayor ni menor que la longitud de la lista
    if(head != NULL && pos <= list->size && pos > 0 ){
        //Crearemos un contador empezado desde 1 para asi llevar la cuenta de en que nodo nos encontramos a medida que iteramos
        int cont = 1;
        //Crearemos un nodo curr el cual empezara desde el primer nodo de la lista, ya que este siempre debe de corresponder con la posicion que indica el contador. Ademas, este nos ayudara a tener la referencia al nodo que se encuentra en la posicion recibida.
        Node *curr = head->next;
        //Por otro lado, crearemos un nodo prev el cual nos servira para siempre tener referencia al nodo previo de curr, para asi poder hacer bien el proceso de eliminado cuando curr se encuentre en el nodo objetivo.
        Node *prev = head;
        //Iteraremos desde 1, hasta la el valor de la posicion recibida
        for (int i = 1; i <= pos; i++)
        {
            //Preguntamos si contador es igual a la posicion para asi saber si ya estamos en el nodo objetivo
            if(cont == pos){
                //Si se entra aca, significa que ya curr esta sobre el nodo objetivo y prev anterior a el
                //Antes de eliminar el nodo que nos interesa, debemos de asegurarnos que la lista siga su flujo.
                //Para esto, haremos que prev apunte al siguiente de curr
                prev->next = curr->next;
                //Con lo anterior, la lista sigue estando bien conectada, y ya on se tiene acceso por nigun lado de la lista a curr
                //Ahora pasaremos a desvincular a curr de la lista haciendolo apuntar a nulo
                curr->next = NULL;
                //Decrementamos la longitud de la lista
                list->size--;
                //Eliminamos de memoria a curr, es decir, al nodo objetivo
                delete curr;
            }else{
                //Si no entro a la anterior condicion, significa que aun curr no ha llegado al objetivo, por lo que debemos de aumentar el contador, y por consiguiente, los dos nodos auxiliares pasarlos a sus siguientes
                cont++;
                prev = curr;
                curr = curr->next;
            }
        }
        
    }
}

//-------------------------------------------