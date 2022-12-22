#include<bits/stdc++.h>
using namespace std;

//Creamos la clase nodo con sus respectivos atributos: datos, puntero a siguiente, puntero a previo.
//Ademas creamos dos constructores: Uno vacio y otro que reciba el dato que almacenara el nodo
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(){this->data = 0 ; this->next = NULL ; this->prev = NULL;}
        Node(int data){this->data = data ; this->next = NULL ; this->prev = NULL;}
};

//Ahora debemos de crear la clase lista, la cual tendra tres atributos: El tamano de la lista, el nodo cabeza y el nodo cola
//Ademas crearemos un constructor vacio
class LinkedList{
    public:
        int size;
        Node *head;
        Node *tail;
        LinkedList(){this->size = 0 ; this->head = new Node() ; this->tail = new Node();}
};

//Funcion para recorrer la lista doblemente enlazada partiendo de la cabeza
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(1)
//Esta funcion recibira un puntero de la cabeza y un puntero de la cola
void traverse(Node *head, Node *tail){
    //Iteramos hasta que el siguiente no sea la cola
    while(head->next != tail){
        //Actualizamos la referencia del puntero
        head = head->next;
        //Imprimimos el dato
        cout<<head->data<<" ";
    }
}

//Funcion para recorrer lista doblemente enlazada recursivamente empezando desde la cabeza
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(n)
//Esta funcion recibira el puntero de la cabeza y el puntero de la cola
void _traverse(Node *head, Node *tail){
    //Caso base
    //Necesitamos parar cuando el siguiente sea la cola
    if(head->next == tail){
        return;
    }else{
        //Sino se cumplio el caso base significa que aun no hemos llegado a la cola
        //Por ello, pasamos del valor del puntero al siguiente
        head = head->next;
        //Imprimimos el datos
        cout<<head->data<<" ";
        //LLamamos recursivamente la funcion con el nuevo valor del puntero
        _traverse(head, tail);
    }
}

//Funcion para recorrer lista doblemente enlazada empezando desde la cola
//Complejidad Temporal: O(n)
//Complejidad Espacial : O(1)
//Esta funcion recibira el puntero de la cabeza y el puntero de la cola
void traverse2(Node *head, Node *tail){
    //Iteramos hasta que el siguiente no se la cabeza
    while(tail->prev != head){
        //Actualizamos el puntero al siguiente
        tail = tail->prev;
        //Imprimimos el dato
        cout<<tail->data<<" ";
    }
}

//Funcion para recorrer lista doblemente enlazada recursivamente empezando desde la cola
//Complejidad Temporal: O(n)
//Comlejidad espacial: O(n)
void _traverse2(Node *head, Node *tail){
    //Caso base
    //Necesitamos parar cuando el siguiente sea la cabeza
    if(tail->prev == head){
        return;
    }else{
        //Sino se cumplio el caso base significa que aun no hemos llegado a la cola
        //Por ello, pasamos del valor del puntero al siguiente
        tail = tail->prev;
        //Imprimimos el datos
        cout<<tail->data<<" ";
        //LLamamos recursivamente la funcion con el nuevo valor del puntero
        _traverse2(head, tail);
    }
}

//-------------------------------------------------------------------------