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

//Funcion para insertar al inicio de una lista circular enlazada
//Complejidad Temporal : O(n)
//Complejidad Espacial: O(1)
//Esta funcion recibira la lista,la referencia del nodo cabeza y el dato a insertar
void push(LinkedList *list, Node *&head , int data){
    //Creamos el nodo a insertar
    Node *new_node = new Node(data);
    //Si la lista esta vacia
    if(head->next == NULL){
        //Si la lista esta vacia significa que el nodo a insertar sera el primero y a la vez el ultimo
        //Como se trata una lista circular, se supone que el ultimo nodo, debe de apuntar al primero, por lo que este nodo tendra como siguiente a si mismo
        //Lo primero que haremos es decir que el siguiente de la cabeza sera el nuevo , para de esta forma, ubicarlo como primero
        head->next = new_node;
        //Ahora , como este nodo tambien es el ultimo, su siguiente, debe de ser el primero de la lista, es decir, a si mismo
        new_node->next = new_node;
        //Incrementamos la longitud de la lista
        list->size++;
        return;
    }else{
        //Si la lista no esta vacia, tendremos que insertar el nodo de forma normal en la primer posicion como se hacia en las otras variantes de listas.
        //Sin embargo, como el ultimo nodo siempre debe de apuntar al primero, primero debemos de hallar este ultimo nodo para ponerlo a apuntar a nuestro nodo el cual ahora insertaremos como primero
        //Por ello, crearemos un nodo auxiliar llamado last, el cual nos ayudara a iterar hasta hallar el ultimo nodo de la lista
        Node *last = head;
        //Iteramos hasta que el siguiente de last, sea el primer nodo, es decir, hasta que volvamos a iniciar el ciclo de la lista
        do{
            last = last->next;
        }while(last->next != head->next);
        //Ya al obtener la referencia del ultimo nodo, podemos proceder a insertar el nuevo nodo al inicio
        //Primero diremos que el siguiente del nuevo nodo, sera el nodo que actualmente es el primero
        new_node->next = head->next;
        //Ahora, para terminar de ubicar al nuevo nodo como primero la cabeza tiene que apuntar a este
        head->next = new_node;
        //Finalmente, el ultimo nodo tiene que apuntar al primero, es decir, al nuevo nodo
        last->next = new_node;
        //Incrementamos el valor de la longitud de la lista
        list->size++;
    }
}

//Funcion para insertar al final de una lista circular enlazada
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(1)
void append(LinkedList *list, Node *&head, int data){
    //Si la lista esta vacia
    if(head->next == NULL){
        //Lo mejor es llamara la funcion push, la cual insertar el nodo en la primera posicion
        push(list, head, data);
        return;
    }else{
        //Si la lista no esta vacia
        //Creamos el nuevpop nodo a insertar
        Node *new_node = new Node(data);
        //Debemos de buscar cual es el ultimo nodo para alli insertar el nuevo
        //Por ello, crearemos un nodo auxiliar el cual nos servira para recorrer la lista hasta que su siguiente sea de nuevo el primer nodo
        Node *last = head;
        //Iteramos hasta que el siguiente del nodo actual, sea el primero de la lista
        do{
            //Actualizamos el valor del nodo
            last = last->next;
        }while(last->next != head->next);
        //Luego de acabado el ciclo anterior, ya tenemos la posicion del ultimo nodo por lo que podemos proceder con la insercion del nuevo nodo alli
        //Lo que haremos es decir que el siguiente del nuevo nodo, sera el siguiente del nodo actual. Es decir, implicatemente, estamos diciendo que el siguiente del nuevo nodo sera el primero
        new_node->next = last->next;
        //Ahora diremos que el siguiente del ultimo nodo, sera el nuevo nodo
        last->next = new_node;
        //Incrementamos el valor de la longitud de la lista
        list->size++;
    }
}

//---------------------------------------------------------------------------