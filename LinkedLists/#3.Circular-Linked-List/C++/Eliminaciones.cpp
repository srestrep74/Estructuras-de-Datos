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

//Funcion para eliminar el primer nodo de una lista circular
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(1)
void pop(LinkedList *list, Node *&head){
    //Verificamos que la lista no este vacia y si la lista solo tiene un nodo
    if(head->next != NULL && list->size == 1){
        //Como la lista solo tiene un nodo debemos solo desvincularlo de la lista
        //Primero guardamos la referencia del primer nodo
        Node *first = head->next;
        //Ahora hacemos que la cabeza apunte a nulo
        head->next = NULL;
        //ELiminamos la referencia del que era el primer nodo
        delete first;
        return;
    }else{
        //Si la lista tiene mas de un elemento, primero debemos de hallar cual es el ultimo nodo de a lista ya que este siempre apunta al primero nodo, pero como vamos a eliminar el primer nodo , este puntero del ultimo nodo cambiara 
        //Primero crearemos un nodo auxiliar el cual nos ayudara a recorrer la lista hasta encontrar el ultimo nodo
        Node *last = head;
        //Ahora iteraremos en la lista para encontrar el ultimo nodo
        do{
            last = last->next;
        }while(last->next != head->next);
        //Ya que acabamos el ciclo,sabemos que con last esta parado en el ultimo nodo
        //Ya podemos eliminar el primero nodo
        //Primero guardaremos una referencia del primer nodo
        Node *first = head->next;
        //Luego haremos que el siguiente de cabeza , sea el siguiente del primer nodo
        head->next = first->next;
        //Ahora, hacemos que el que era el primero apunte a nulo
        first->next = NULL;
        //Hacemos que last apunte al primer nodo 
        last->next = head->next;
        //Decrementamos el valor de la longitud de la lista
        list->size--;
        //Eliminamos de memoria el que era el primer nodo
        delete first;
    }
}

//Funcion para eliminar el ultimo nodo de una lista circular
//Complejidad Temporal: O(n)
//Complejidad Espacial: O(1)
void popLast(LinkedList *list, Node *&head){
    //Verificamos que la lista no este vacia y si la lista solo tiene un nodo
    if(head->next != NULL && list->size == 1){
        //Como la lista solo tiene un nodo debemos solo desvincularlo de la lista
        //Primero guardamos la referencia del primer nodo
        Node *first = head->next;
        //Ahora hacemos que la cabeza apunte a nulo
        head->next = NULL;
        //ELiminamos la referencia del que era el primer nodo
        delete first;
        return;
    }else{
        //Si la lista tiene mas de un elemento, primero debemos de hallar cual es el ultimo nodo de a lista ya que este siempre apunta al primero nodo, pero como lo vamos a eliminar, este puntero cambiara 
        //Primero crearemos un nodo auxiliar el cual nos ayudara a recorrer la lista hasta encontrar el ultimo nodo
        Node *last = head;
        //Tambien necesitamos un nodo previo al nodo last para poder hacer la conexion cuando encontremos el ultimo nodo
        Node *prev = NULL;
        //Ahora iteraremos en la lista para encontrar el ultimo nodo
        do{
            prev = last;
            last = last->next;
        }while(last->next != head->next);
        //Ya que acabamos el ciclo,sabemos que con last esta parado en el ultimo nodo, y prev esta antes de el
        //Lo que haremos es que el previo apuntara al siguiente de last. Es decir, apuntara al primer nodo de la lista
        prev->next = last->next;
        //Hacemos que last apunte a nulo para desvincularlo
        last->next = NULL;
        //Decrementamos el valor de la longitud de la lista
        list->size--;
        //Eliminamos de memoria el que era el ultimo nodo
        delete last;
    }
}

//Funcion para eliminar nodo en cierta posicion de una lista circular
//Complejidad Temporal: O(n)
//Comlejidad Espacial: O(1)
void erase(LinkedList *list, Node *&head, int pos){
    //Si la funcion a eliminar es la primera
    if(pos == 1){
        //Llamamos la funcion pop
        pop(list, head);
        return;
    }
    //Si la posicion a eliminar es la ultima
    if(pos == list->size){
        //Llamamos la funcion popLast
        popLast(list, head);
        return;
    }
    //Si no se entra a lo anterior, signfica que la posicion a eliminar se encuentra dentro del rango de la longitud de la lista
    //Por ello debemos de recorrer la lista hasta encontrar el nodo que se encuentra en dicha posicion
    //Para eso, crearemos primero un contador el cual nos ayudara a saber en que posicion de la lista estamos
    int cont = 1;
    //Ahora, crearemos un nodo auxiliar curr, el cual nos ayudara a iterar en la lista hasta encontrar el nodo que se debe de eliminar. Ademas, este comenzara siendo el primer nodo de la lista ya que este debe de corresponder con el valor de la posicion que tenga el contador
    Node *curr = head->next;
    //Sin embargo, para realizar el proceso de eliminacion cuando enconrtremos el nodo objetivo, tendremos que conocer la referencia de su nodo previo. Por ello, crearemos un nodo auxiliar prev el cual siempre ira detras de curr para asi tener una referencia del nodo previo del nodo objetivo
    Node *prev = head;
    //Ahora , debemos de iterar sobre la lista hasta el valor de la posicion recibida
    for(int i = 1 ; i<=pos ; i++){
        //Verificamos si el contador ya tiene el valor de la posicion recibida
        if(cont == pos){
            //Si el contador ya esta en la posicion recibida significa que ya curr esta en el nodo objetivo por lo que podemos realizar ya el proceso de eliminacion
            //Empezaremos diciendo que el siguiente del nodo previo del nodo objetivo, es el siguiente del nodo objetivo
            prev->next = curr->next;
            //El apuntador de curr ahora sera nulo
            curr->next = NULL;
            //Decrementamos el valor de la longitud de la lista
            list->size--;
            //Eliminamos la referencia del nodo objetivo
            delete curr;
            return;
        }else{
            //SI entramos aca, significa que aun no hemos llegado al nodo objetivo por lo que toca incrementar el contador y pasar los nodos auxiliares a sus siguientes
            cont++;
            prev = curr;
            curr = curr->next;
        }
    }
}

//---------------------------------------------------------- 