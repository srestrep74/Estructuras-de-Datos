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

//Funcion para insertar nodo al inicio de lista doblemente enlazada
//Complejidad Temporal : O(1)
//Complejidad Espacial: O(1)
//Esta funcion recibira el puntero a la lista, la referencia al nodo cabeza, la referencia al nodo cola, y el dato a insertar a la lista
void push(LinkedList *list, Node *&head, Node *&tail, int data){
    //Creamos el nuevo nodo a insertar
    Node *new_node = new Node(data);
    //Verificamos si la lista esta vacia
    if(head->next == NULL){
        //Como esta vacia, debemos de insertar el nodo como si fuera el primero, es decir, debe de ser el siguiente de cabeza
        head->next = new_node;
        //Como es una lista doblemente enlazada, debemos de decir cual sera el previo del nuevo nodo. En este caso como es el primer nodo, su nodo previo sera la cabeza
        new_node->prev = head;
        //Ahora , como ahora hay un solo nodo en la lista, la cola debe de apuntar hacia el como si fuera su previo
        tail->prev = new_node;
        //Finalmente, debemos de decir, que el siguiente del nuevo nodo, sera la cola, ya que este es el ultimo nodo
        new_node->next = tail;
        //Incrementamos la longitud de la lista
        list->size++;
        return;
    }else{
        //Sino esta vacia, ya no necesitaremos utilizar la cola, ya que esta estara apuntando al ultimo nodo que tenga lista y como vamos a insertar al inicio no la necesitamos
        //Como insertaremos el nuevo nodo al inicio, debemos de tener en cuenta la cabeza y el primer nodo de la lista
        //Lo primero que tenemos que hacer es decir que el siguiente del nuevo nodo es el siguiente de cabeza, es decir, el primer nodo
        new_node->next = head->next;
        //Ahora , el previo del siguiente de cabeza, es decir, el previo del primer nodo , sera ahora el nuevo nodo
        head->next->prev = new_node;
        //Ahora debemos de decir que el siguiente de la cabeza ya sea el nuevo nodo para ubicarlo como primero en la lista
        head->next = new_node;
        //Finalmente debemos de decir, que ahora como el nuevo nodo es el primero , su previo sera la cabeza
        new_node->prev = head;
        //Incrementamos el valor de la longitud de la lista
        list->size++;
    }
}

//Funcion para insertar elemento al final de la lista doblemente enlazada
//Complejidad Temporal: O(1)
//Complejidad Espacial: O(1)
//Esta funcion recibira, el puntero de la lista, la referencia a la cabeza, al referencia a la cola, y el dato a insertar
void append(LinkedList *list, Node *&head, Node *&tail, int data){
    //Creamos el nuevo nodo a insertar
    Node *new_node = new Node(data);
    //Verificamos si la lista esta vacia
    if(head->next == NULL){
        //Como la lista esta vacia, solo insertamos el nodo al inicio, es decir, el nuevo nodo sera el siguiente de la cabeza
        head->next = new_node;
        //Ahora, el previo del nuevo nodo, sera el que lo apunta, es decir, la cabeza
        new_node->prev = head;
        //Ahora, la lista estaba vacia, e insertamos este nuevo nodo, este es el primero y el ultimo de la lista.
        //Por ello, debemos de hacer que la cola, apunta a este ya que es el ultimo. Es decir, el previo de la cola, sera el nuevo nodo
        tail->prev = new_node;
        //Ademas, debemos de decir que ahora el siguiente del nuevo nodo sera la cola, ya que esta en la ultima posicion
        new_node->next = tail;
        //Incrementamos el valor de la longitud de la lista
        list->size++;
        return;
    }else{
        //Sino esta vacia la lista, debemos de buscar el ultimo nodo de la lista para alli hacer la operacion'
        //Sin embargo, como estamos trabajando con listas doblemente enlazadas, tenemos acceso directo al ultimo nodo por medio de la cola
        //Esto nos evita tener que iterar toda la lista para encontrar el ultimo nodo
        //Como queremos insertar el nuevo nodo al final, tenemos que decir que el siguiente del ultimo nodo ya sera el nuevo nodo creado
        tail->prev->next = new_node;
        //Ahora, el previo del nuevo nodo debe ser el nodo que lo apunta, es decir, el ultimo nodo
        new_node->prev = tail->prev;
        //Con esto, el que era el ultimo nodo, ya quedo desplazado y se encuentra de penultimo en la lista
        //Ahora como el nuevo nodo se encuentra de ultimo en la lista, debe de ser apuntado por la cola
        tail->prev = new_node;
        //De igual manera, como el nuevo nodo es el ultimo, debe de apuntar a la cola de la lista
        new_node->next = tail;
        //Incrementamos la longitud de la lista
        list->size++;
    }
}

//Funcion para insertar en una posicion en una lista doblemente enlazada
//Complejidad Temporal: O(n)
//Comlejidad Espacial: O(1)
//Esta funcion recibira el puntero de la lista, la referencia a la cabeza, la referencia a la cola, la posicion a insertar, y el dato a insertar
void insert(LinkedList *list, Node*&head, Node *&tail, int pos, int data){
    //Verificamos que la posicion recibida si este entre los rangos de la longitud de la lista
    if(pos <= list->size && pos > 0){
        //Si la posicion es la primera , es decir, si pos == 1
        if(pos == 1){
            //Llamamos la funcion push, o copiamos directamenete el codigo de esa aca
            //Por fines practicos, se llamara la funcion
            push(list, head, tail, data);
            return;
        }
        //Si la posicion es la ultimo, es decir, si pos == list->size
        if(pos == list->size){
            //Llamamos la funcion append, o copiamos el codigo de dicho funcion en esta parte
            append(list, head, tail, data);
            return;
        }
        //Si las anteriores condiciones no se cumplieron, significa que la posicion a insertar esta entre el rango de la longitud de la lista
        //Por ello toca iterar, para encontrar el nodo en dicho posicion, y alli insertar el nuevo nodo
        //Crearemos un contador el cual nos servira para ir llevando la posicion en que nos estamos parando en la lista
        int cont = 1;
        //Ahora crearemos un nodo auxiliar, el cual nos servira para iterar sobre la lista. Este empezara siendo el primer nodo de la lista
        Node *temp = head->next;
        //Creamos el nuevo nodo a insertar
        Node *new_node = new Node(data);
        //Iteramos hasta la posicion recibida
        for (int i = 1; i <= pos; i++)
        {
            //Si el contador es igual a la posicion
            if(cont == pos){
                //Si se entra aca, significa que ya contador es igual al valor de la posicion recibido
                //Es decir, ya el nodo auxiliar, se encuentra en el nodo objetivo
                //Primero guardaremos la referencia del nodo previo del que estamos
                Node *aux = temp->prev;
                //Ahora para insertar aca, diremos que el siguiente del nuevo nodo, sera en el que estamos, es decir, el nodo objetivo
                new_node->next = temp;
                //Ahora, el previo del nodo objetivo, sera el nuevo nodo
                temp->prev = new_node;
                //Con la referencia que guardamos del nodo previo del nodo objetivo, ahora diremos que el siguiente de este nodo, es el nuevo nodo
                aux->next = new_node;
                //Finalmente, diremos que el previo del nuevo nodo, sera la referencia del nodo previo del nodo objetivo
                new_node->prev = aux;
                //Incrementamos la longitud de la lista
                list->size++;
                return;
            }else{
                //Si aun contador no es igual al valor de la posicion recibida, aumentaremos el contador, y pasaremos nuestro nodo auxiliar a su siguiente
                cont++;
                temp = temp->next;
            }
        }
        
    }
}


//------------------------------------------------------------------