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

//Funcion para eliminar el primer nodo de una lista doblemente enlazada
//Complejidad Temporal: O(1)
//Complejidad Espacial: O(1)
//Esta funcion recibira el puntero de la lista, la referencia del nodo cabeza
void pop(LinkedList *list, Node *&head){
    //Verificamos si la lista esta vacia o no 
    if(head->next != NULL){
        //Guardamos referencia del primer nodo el cual es el que se quiere eliminar
        Node *aux = head->next;
        //Como queremos eliminar le primer nodo, el que pasara a ser el primer nodo sera que el ahora es el segundo. Para que pase a ser el primero, la cabeza tiene que apuntar a este, es decir, la cabeza tiene que apuntar al siguiente del primer nodo
        head->next = aux->next;
        //Ahora, el previo del nuevo primer nuevo nodo, debe de ser la cabeza
        head->next->prev = head;
        //Ahora, el nodo que antiguamente era el primer nodo haremos que sus dos punteros, tanto prev como next, apunten a nulo. Esto hara que este nodo quede totalmente desvinculado de la lista
        aux->next = NULL;
        aux->prev = NULL;
        //Decrementamos el valor de la longitud de la lista
        list->size--;
        //Eliminamos de memoria este nodo
        delete aux;
    }
}

//Funcion para eliminar el ultimo nodo de una lista doblemente enlazada
//Complejidad Temporal: O(1)
//Complejidad Espacial: O(1)
//Esta funcion recibira la lista, la referencia de la cabeza y la referencia de la cola
void popLast(LinkedList *list, Node *&head, Node *&tail){
    //Si la lista no esta vacia
    if(head->next != NULL){
        //Como estamos trabajando listas doblemente enlazadas, podemos hacer directamente al ultimo nodo de la lista por medio del nodo cola.
        //Gracias a esto, podremos hacer la operacion eliminar eficientemente
        //Lo primero que haremos es crear un nuevo auxiliar con la referencia del ultimo nodo para no perderlo y poder acceder a el despues
        Node *aux = tail->prev;
        //Lo que tenemos que hacer es que el penultimo nodo de la lista pase a ser ahora el ultimo
        //Es decir, el penultimo debe de apuntar a la cola de la lista
        aux->prev->next = tail;
        //Ahora, como la cola siempre debe de apuntar al ultimo nodo de la lista, este debera de aputar con su previo, al nodo penultimo
        tail->prev = aux->prev;
        //Con esto , ya hicimos que el nodo que era penultimo ya sea el ultimo de la lista
        //Ya lo que haremos es desvincular totalmente, el nodo auxiliar que hicimos, de la lista.
        //Para esto, hacemos que sus punteros apunten a nulo
        aux->prev = NULL;
        aux->next = NULL;
        //Decrementamos la longitud de la lista 
        list->size--;
        //Eliminamos de memoria la referencia del nodo auxiliar, es decir, del que era el ultimo nodo
        delete aux;
    }
}

//Funcion para eliminar el nodo en una posicion en una lista doblemente enlazada
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(1)
//Esta funcion recibira la lista, la referencia a la cabeza, la referencia a la cola, y la posicion a eliminar
void erase(LinkedList *list, Node *&head, Node *&tail, int pos){
    //Verificamos que la posicion pasada este entre los rangos de la longitud de la lista
    if(pos <= list->size && pos > 0 ){
        //Miramos si se quiere eliminar la posicion 1, es decir el primer nodo
        if(pos == 1){
            //Si se quiere eliminar el primer nodo, lo mejor es llamar la funcion pop creada anteriormente
            pop(list, list->head);
            return;
        }
        //Miramos si el nodo a eliminar es el ultimo de la lista
        if(pos == list->size){
            //Lo mas recomendable es llamar la funcion popLast creada anteriormente
            popLast(list, list->head , list->tail);
            return;
        }
        //Si no se entra a las condiciones anteriores, signifia que la posicion a eliminar esta entre el rango de la longitud de la lista
        //Por ello, debemos de buscar cual es el nodo que esta en la posicion recibida para realizar alli la operacion de eliminado
        //Para esto , crearemos un contador que nos ayudara a saber en que posicion de la lista estamos
        int cont = 1;
        //Ademas, necesitamos crear un nodo que nos ayude a iterar sobre la lista hasta encontrar el nodo en la posicion indicada. Este nodo lo inicializaremos como el primero de la lista ya que este nodo siempre debera de corresponder al valor de la posicion que contenga el contador
        Node *aux = head->next;
        //Iteraremos hasta el valor de la posicion recibida
        for (int i = 1; i <= pos; i++)
        {
            //Si el contador es igual a la posicion
            if(cont == pos){
                //Si entramos aca, significa que ya el contador llego al valor de la posicion recibida.
                //Ademas , esto tambien quiere decir, que el nodo auxiliar ya esta parado sobre el nodo objetivo
                //Ya lo que haremos es decir, que el previo del nodo siguiente de donde estamos, sea el previo de donde estamos
                aux->next->prev = aux->prev;
                //Ahora diremos que el siguiente del previo de aux, sera el siguiente de aux
                aux->prev->next = aux->next;
                //Ahora lo que haremos es desvincular el nodo aux totalmente de la lista
                aux->prev = NULL;
                aux->next = NULL;
                //Eliminamos de memoria a aux
                delete aux;
                //Decrementamos el valor de la longitud de la lista
                list->size--;
            }else{
                //Si entramos aca, significa que el el contador aun no ha llegado al valor de la posicion recibida
                //Es decir, aun no hemos ubicado el nodo obejtivo, por lo que incrementamos el contador, y avanzamos el nodo auxiliar a su siguiente
                cont++;
                aux = aux->next;
            }
        }
         
    }
}

//----------------------------------------------------------------------------------