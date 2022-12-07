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

//Funcion para recorrer una lista simplemente enlazada
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(1)
// Esta funcion recibira un puntero al nodo cabeza de la list
void traverse(Node *head){
    //Iteramos hasta que el siguiente de cabeza sea nulo
    while (head->next != NULL)
    {
        //Actualizamos cabeza a su siguiente
        head = head->next;
        //Imprimimos el dato que se encuentra en cabeza
        cout<<head->data<<" ";
    }
    /*Importante:
    Seguramente muchos piensen por que esta vez a comparacion de otras funciones como la de agregar nodo, solo recibe el puntero de la cabeza, y no su referencia.
    En este caso, no se va a modificar ningun dato, por lo que no es necesario pasar la referencia como tal de la cabeza y esto ademas, permite que no modifiquemos datos durante el recorrido por error.
    Por ello, se envia el puntero de la cabeza, que ira pasando nodo por nodo, pero en ningun momento, se modificara la referencia de la cabeza.
    Ademas, este puntero solo cambiara su estado dentro de esta funcion, fuera de esta, seguira apuntanto a la cabeza
    */
    
}

//Funcion para recorrer lista recursivamente
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(n)
//Esta funcion recibira el puntero a la cabeza de la lista
void _traverse(Node *head){
    //Caso base:
    //Si el siguiente de la cabeza es nulo, se para la funcion
    if(head->next == NULL){
        return;
    }else{
        //Sino, significa que no hemos llegado al ultimo nodo, por lo que actulizamos el puntero de head a su siguiente
        head = head->next;
        //Imprimimos le valor de head
        cout<<head->data<<" ";
        //Llamamos recursivamente la funcion con el nuevo valor de la cabeza
        _traverse(head);
    }
}


//-------------------------------------------------------