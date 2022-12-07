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

//Funcion para actulizar dato de un nodo en una posicion de la lista
//Comlejidad Temporal: O(n)
//Complejidad Espacial: O(1)
//Esta funcion recibira, el puntero de la lista, el puntero de la cabeza, el nuevo dato a modificar y la posicion del nodo a modificar
void update(LinkedList *list, Node *head, int new_data, int pos){
    //Verificamos la posicion ingresada este entre los rango de la longitud de la lista
    if(pos <= list->size && pos > 0 ){
        //Creamos contador que nos ayudara a saber en que posicion de la lista estamos
        int cont = 1;
        //Pasamos que el puntero de cabeza, ahora apunte al primer nodo, ya que este puntero nos ayudara a recorrer la lista, y este siempre debe de corresponder al valor del contador
        head = head->next;
        //Iteramos hasta elm valor de la posicion ingresada
        for (int i = 1; i <= pos; i++)
        {
            //Verificamos si el contador es igual a la posicion recibida
            if(cont == pos){
                //Si se entra aca, quiere decir que el contador ya es igual a la posicion recibida,es decir, el puntero a la cabeza ya este en el nodo a modificar
                //Procedemos a modificar el dato de este nodo
                head->data = new_data;
                //Ya en este punto no debemos hacer mas nada asi que paramos
                return;
            }else{
                //Si entramos aca es por que el contador aun no es igual al valor de la posicion recibida, es decir, el puntero de head, aun no apunta al nodo a modificar
                //Por ellos, incrementamos el valor del contador, y avanzamos el puntero de head a su siguiente
                cont++;
                head = head->next;
            }
        }
        
    }
}

//--------------------------------------------------------------------------