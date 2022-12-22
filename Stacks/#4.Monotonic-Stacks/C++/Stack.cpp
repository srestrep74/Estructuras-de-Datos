#include<bits/stdc++.h>
using namespace std;

//Lo primero que necesitamos hacer es crear la estructura nodo
//Para esto crearemos una clase llamada Node, la cual contendra los atributos que contiene un nodo: El valor y el puntero al siguiente nodo
class Node{
    public:
        int data;
        Node *next;
        Node(){this->data = 0 ; this->next = NULL;}
        Node(int data){this->data = data ; this->next = NULL;}
};

//Ahora crearemos la estructura Lista , en este caso, Stack
//Si bien en la seccion de listas veiamos que esta estructura tenia un nodo cabeza, en este caso para las pilas, lo llamaremos el nodo top el cual se ira acomodando en el ultimo elemento en insertar de la lista
class Stack{
    public:
        Node *top;
        int size;
        Stack(){this->top = new Node() ; this->size = 0;}
};

//Ahora veremos como retirar el elemento de la pila, es decir, la funcion pop
//Como se vio en la teoria, en una pila, solo se puede ir sacando desde el dato mas es la cima\
//Complejidad Temporal: O(1)
void pop(Stack *S , Node *&top){
    //Verificamos que el Stack no este vacio
    if(S->size > 0){
        //Como bien sabemos, el nodo top , siempre estara apuntando al nodo en la cima de la pila, es decir, al nodo top
        //Por ello, debemos de actualizar el valor de top, ya que debe de apuntar al siguiente del que esta apuntando
        //Para empezar, guardaremos en un nodo auxiliar, el nodo en la cima de la pila
        Node *peek = top->next;
        //Ya guardado el nodo de la cima, haremos que ahora el nodo top apunte al siguiente del nodo de la cima
        top->next = peek->next;
        //Desvinculamos el que era el nodo de la cima del stack haciendolo apuntar a nulo
        peek->next = NULL;
        //Ahora bien, con el nodo que estaba en la cima del Stack, hay dos opciones, retornar este para utilizarlo en alguna operacion o eliminarlo directamente de memoria. 
        //Esto dependera de que se quiera hacer con este, ya sea solo expusarlo de la pila y  manipularlo, o directamente eliminarlo
        //En este caso eliminaremos el nodo
        delete peek;
        //Decrementamos el vamor de la pila
        S->size--;
    }   
}

bool isEmpty(Stack *S){
    //Retorna el valor booleano de la siguiente condicion, indicando si es verdadero o falso
    return S->size > 0;
}

//Ahora veremos una funcion la cual retornara cual es el dato que esta en la cima de la pila
//En este caso, como estamos trabajando con nodos, podemos decidir si retornar el nodo en donde se encuentra el dato o directamente el dato que se encuentra en el nodo
//Para este caso, se retornara el dato del nodo
//Complejidad Temporal : O(1)
int peek(Stack *S, Node*&top){
    //Verificamos que la pila no este vacia
    if(S->size > 0){
        //Retornamos el dato del nodo que esta en la cima del Stack
        return top->next->data;
    }
}

//Ahora veremos la funcion de insertar en la pila, es decir, la funcion push
//Complejidad Temporal: O(1)
void push(Stack *S ,Node *&top, int data){
    //Creamos el nuevo nodo a insertar
    Node *new_node = new Node(data);
    //Ahora lo que debemos hacer, es que el nuevo nodo creado, apunte al nodo que apunta top
    new_node->next = top->next;
    //Ahora, ya que hay un nuevo nodo en el Stack, debemos de actualizar el puntero de Top ya que este siempre debe de apuntar al nodo que esta en la cima de la pila, es decir, el ultimo nodo en ser insertado
    top->next = new_node;
    //Incrementamos el valor del tamano del Stack
    S->size++;
}

//Funcion para crear pila monotona creciente. Para esta utilizaremos como pila la implementacion con nodos, es decir, en una lista enlazada
//Esta funcion recibira la referencia de la pila creada vacia, al igual que un arreglo en el cual hay datos numericos a insertar en la pila
//Complejidad Temporal: O(n)
//Complejidad Temporal: O(n)
void monotonicStack(Stack *&s, int arr[]){
    //Iteramos hasta la longitud del vector
    for(int i = 0 ; i < 6 ; ++i){
        //Ahora debemos de hacer pop a todos lo elementos de la pila mientras se cumpla las siguiente condiciones:
            //Mientras la pila no este vacia
            //Mientras el elemento en Top sea mayor al dato a insertar
            while(s->size > 0  && peek(s, s->top) > arr[i]){
                //Hacemos pop en la pila
                pop(s, s->top);
            }
            //Cuando se acabe el ciclo anterior, significa que el elemento a insertar en mayor al que esta en la cima o la pila esta vacia
            //En este caso ya se puede insertar en la pila
            push(s, s->top , arr[i]);
    }
}

void traverse(Stack *&s){
    while(s->top->next != NULL){
        s->top = s->top->next;
        cout<<s->top->data<<" ";
    }
}

int main(){
    Stack *s = new Stack();
    int arr[] = {1,4,5,3,12,10};
    //int n = sizeof(arr) / sizeof(arr[0]);
    monotonicStack(s, arr);
    for(int i = 0 ; i < 6; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    traverse(s);
}