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