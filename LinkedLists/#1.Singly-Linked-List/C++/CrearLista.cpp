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

