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


//Funcion para insertar al inicio de la lista.
//Esta funcion se puede implementar recibiendo como tal la referencia al nodo cabeza
//Complejidad Temporal : O(1)
//Complejidad Espacial: O(1)
void push(LinkedList *list, Node *&head_ref, int data ){
    //Creamos el nuevo nodo a insertar
    Node *new_node = new Node(data);
    //Decimos que el siguiente del nuevo nodo , es el que es ahora el siguiente de la cabeza
    new_node->next = head_ref->next;
    //Actualizamos que el siguiente de la cabeza es el nuevo nodo
    head_ref->next = new_node;
}

//Funcion para insertar al final de la lista.
//Complejidad Temporal : O(n)
//Complejidad Espacial : O(1)
void append(LinkedList *list, Node *&head, int data){
    //Creamos el nuevo nodo
    Node *new_node = new Node(data);
    //Si la lista es nula
    if (head == NULL){return;}
    //Si la lista esta vacia, insertamos el nuevo nodo como el siguiente de la cabeza, es decir, sera el primero de la lista
    if(head->next == NULL){
        head->next = new_node;
    }else{ //Sino iteramos sobre la lista para buscar el ultimo nodo
        //Creamos una variable temporal que apunte a cabeza, para asi poder desplazarnos por la lista y no modificar la referencia de la cabeza
        Node *last = head;
        //Iteramos hasta saber que last es el ultimo nodo, es decir, hasta que su siguiente sea nulo
        while(last->next != NULL){
            last = last->next;
        }
        //Cuando acaba el ciclo, ya sabemos que last esta apuntando al ultimo nodo de la lista
        //Como queremos apuntar al final, lo que toca hacer es que este ultimo nodo, apunte como siguiente al nuevo nodo
        last->next = new_node;
    }
    //Incrementamos la longitud de la lista
    list->size++;
}

//Funcion para insertar al final recursivamente
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(n)
//Esta funcion debe de recibir el puntero de la lista, la referencia al nodo encabezador, y la referencia del nodo a insertar
void _append(LinkedList *list, Node *&head, Node*& new_node){
    //Caso Base
    //Si la cabeza es nula retornamos, o la lista esta vacia, pegamos el nuevo nodo de primero en la lista, es decir, sera el siguiente de cabeza y retornamos
    if(head == NULL) return;
    if(head->next == NULL){
        head->next = new_node;
        list->size++;
        return;
    }else{ //Sino, recorreremos recursivamente la lista, hasta que se cumpla el caso base, si llega ahi es porque encontro el ultimo nodo ya que su siguiente es nulo, y alli pega el nuevo nodo
        //Creamos copia de la cabeza, para no perder su referencia
        Node *last = head;
        //Hacemos llamada recursiva en donde ya la cabeza, sera el siguiente de la cabeza actual
        _append(list, last->next , new_node);
    }
}

//Funcion para insertar un elemento en la lista en una posicion dada
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(1)
//Esta funcion recibira el puntero de la lista, la referencia al nodo cabeza, el elemento a insertar, y la posicion en donde se quiere insertar
void insert(LinkedList *list, Node *&head, int data, int pos){
    //Creamos el nuevo nodo
    Node *new_node = new Node(data);
    if(pos > list->size || pos <= 0 ){
        cout<<"Se esta accediendo a una posicion erronea"<<endl;
        return;
    }
    //Si la posicion es uno, insertamos al inicio de la lista
    //Es decir, el nuevo nodo sera el siguiente de cabeza
    if(pos == 1 ){
        new_node->next = head->next;
        head->next = new_node;
    }else{ //Sino, iteraremos hasta encontrar el nodo que corresponda con la posicion pasada
        //Crearemos contador para saber la posicion del nodo en el que estamos
        int cont = 1 ;
        //Creamos una copia del siguiente de la cabeza para estar en la primera posicion de la lista
        Node *curr = head->next;
        //Creamos un nodo previo a curr, el cual nos servira para tener una referencia al nodo previo
        Node *prev = head;
        //Iteramos hasta que el nodo curr, no llegue al final de la lista, es decir , hasta cuando sea Nulo
        while(curr != NULL){
            //Preguntamos si el contador esta en la posicion pasada
            if (cont == pos){
                //El siguiente de previo sera el nuevo nodo creado
                prev->next = new_node;
                //El siguiente del nuevo nodo sera curr
                new_node->next = curr;
                //Incrementamos la longitud de la lista
                list->size++;
                return;
            }else{
                //Si no estamos en la posicion, incrementamos contador y aumentamos cada uno de los nodos auxiliares a su siguiente
                cont++;
                prev = curr;
                curr = curr->next;
            }
        }

    }
}

//Funcion para insertar en la lista en una posicion dada recursivamente
//Para implementar esto necesitamos dos funciones, la primera recibe la lista, la cabeza, el nodo a insertar y la posicion a insertar
//Alli hace verificaciones y si todo esta bien , crea tres variables necesarias
//Un contador para llevar la cuenta de que nodo estamos, un nodo actual y un nodo previo
//De alli llama la segunda funcion la cual es la que hace el proceso recursivo para insertar el nuevo nodo en la posicion pasada.
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(n)
//Declaremos primero las funciones:
void __insert(LinkedList *, Node *&, Node *&, int);
void _insert(LinkedList *, Node *&, Node *&, Node *&, Node *&, int, int);
//Primera Funcion:
void __insert(LinkedList *list, Node *&head, Node *&new_node, int pos){
    //Verificamos que la posicion pasada sea valida
    //Es decir, no sea ni mayor ni menos a la longitud de la lista
    if(pos > list->size || pos <= 0 ){
        cout<<"La posicion ingresada es erronea"<<endl;
        return;
    }
    //Si la posicion es uno, insertamos al inicio de la lista
    if(pos == 1){
        new_node->next = head->next;
        head->next = new_node;
        return;
    }
    //Creamos variable contador que se ubicara en el primero elemento de la lista, e ira incrementando hasta llegar a la posicion dada
    int cont = 1;
    //Crearmos la variable nodo que nos permitira iterar sobre la lista
    //Esta debe de decir el primer elemento de la lista, ya que este debe de concordar con la posicion dada con el contador siempre
    Node *curr = head->next;
    //Necesitamos una variable nodo que siempre sea el previo de la variable actual (curr)
    Node *prev = head;
    //Aca, ya podemos llamar a la funcion _insert la cual recibira todos estos todas para asi insertar el nuevo nodo de forma recursiva
    _insert(list, head, new_node, prev, curr, cont, pos);
}
//Segunda Funcion:
//Esta funcion recibira el puntero a la lista, la referencia del nodo cabeza, la referencia del nodo que se va a insertar, un nodo llamado previo el cual lo recibiremos inicialmente apuntando a la cabeza, otro nodo llamado curr el cual lo recibiremos apuntando al siguiente de cabeza,el contador  y la posicion
void _insert(LinkedList *list, Node *&head, Node *&new_node, Node *&prev , Node*&curr,int cont,  int pos){
    //Caso Base:
    //Si la posicion es igual al contador, insertamos y retornamos
    if(cont == pos){
        //El siguiente del previo es el nuevo nodo
        prev->next = new_node;
        //El siguiente del nuevo nodo, es el nodo actual
        new_node->next = curr;
        //Incrementamos el valor de la longitud de la lista
        list->size++;
        return;
    }else{
        //Incrementamos contador
        cont++;
        //Pasamos prev y curr a sus siguientes
        prev = curr;
        curr = curr->next;
        //Pasamos recursivamente los datos
        _insert(list, head, new_node, prev, curr,cont, pos);
    }
}
//---------------------------------------------------------------


