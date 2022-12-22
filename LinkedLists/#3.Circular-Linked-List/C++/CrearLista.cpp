#include<bits/stdc++.h>
using namespace std;

//Aqui daremos forma a la estructura nodo la cual tendra los dos atributos de siempre: Un dato y un puntero al siguiente nodo
//Ademas tendremos dos constructores, uno vacio, y un constructor que reciba el dato que contendra el nodo
class Node{
    public:
        int data;
        Node *next;
        Node(){this->data = 0 ; this->next = NULL;}
        Node(int data){this->data = data ; this->next = NULL;}
};

//Creamos la clase lista, la cual contendra dos atributos, la longitud de la lista, y el nodo cabeza vacio
//Ademas, crearemos un constructor
class LinkedList{
    public:
        int size;
        Node *head;
        LinkedList(){this->size = 0 ; this->head = new Node();}
};

