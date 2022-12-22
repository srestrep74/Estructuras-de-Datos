/*
En este archivo veremos uno de los problemas as comunes que se pueden resolver de una forma optima utilizando pilas monotonas.
Este problema se trata  que dado un arreglo de elementos numericos, hay que hallar cual es el siguiente elemento mayor en el arreglo, de cada posicion. Si el elemento no tiene uno mayor a la derecha, sera -1 la respuesta de este. 
Veamos un ejemplo de como seria una entrada y salida de esto:

Input: arr[] = [4,5,2,25]
Output:  4 -> 5
		 5 -> 25
		 2 -> 25
		 25 -> -1

Ahora bien , lo que primero se pensaria al hacer este problema es iterar todo el arreglo por cada elemento de este, buscando proximo mayor de la posicion del arreglo en  la que nos encontremos. Sin embargo, en cuanto a eficiencia es un mal algoritmo ya que su complejidad temporal es cuadratica. 
Por ello, es mas conveniente usar otras estructuras como lo es la pila monotona o un mapa, los cuales aumentando la complejidad espacial a lineal, se puede reducir la complejidad temporal a lineal, ya sea con pilas monotonas o con un mapa.

Sin embargo, en este ocasion veremos como resolver este problema de la forma tipica, es decir, con dos ciclos, y con pilas monotonas, para mirar las diferencias entre ambos algoritmos, y asi ver una de las tantas aplicaciones que nos permite esta variante de las pilas. En este caso, implementaremos nuestra pila mediante una lista enlazada. 
*/


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

//La primera funcion para resolver el problema en cuestion, sera iterando sobre todos los elementos del arreglo por cada elemento de este
//Complejidad Temporal: O(n^2)
//Esta funcion recibira el arreglo con los datos, y el tamano del arreglo .Luego,lo que hara al final es imprimir cada elemento del arreglo con su proximo mayor
void NGEArrays(int arr[], int n ){
    //Lo primero que se hara sera crear una varible la cual ira guardando el proximo elemento de cada elemento del vector
    int next;
    //Ahora, iteraremos hasta la longitud del arreglo
    for(int i = 0 ; i < n ; ++i){
        //Ahora bien , inicializaremos a next en -1 asumiendo que este no tendra valor mayor proximo 
        next = -1;
        //Ahora, como debemos de encontrar el elemento mayor a la derecha de la posicion sobre la que estamos, debemos de iterar todo el arreglo, empezando desde la posicion siguiente de la que nos encontramos
        for(int j = i + 1 ; j < n ; ++j){
            //Ahora debemos de verificar que si la posicion en i , es decir, la posicion sobre la que estamos parados, es menor a la posicion en j que es la que esta iterando sobre el resto de los elementos del vector, significa que ese dato en j es el proximo mayor al dato sobre el que estamos iterando. De modo, que la variable next guardara ese valor que esta en j.
            if (arr[i] < arr[j]){
                next = arr[j];
                break;
            }
        }
        //Ahora, que estamos afuera del ciclo interno, ya tenemos guardado el elemento mayor proximo de la posicion que indica el ciclo externo.
        //Por ello, podemos proceder a  imprimir el elemento de la posicion actual con su proximo 
        cout<<"Elemento actual: "<<arr[i]<<" . Su elemento mayor proximo es : "<<next<<endl;
    }
}

//Ahora veremos como optimizar el anterior algoritmo con pilas monotonas
//Complejidad Temporal: O(n)
//Esta funcion recibira el arreglo con los datos y la longitud de este 
void NGEStack(int arr[], int n){
    //Crearemos el Stack en donde se iran insertando los datos
    Stack *s = new Stack();
    //Insertamos en la pila el primer elemento del arreglo
    push(s, s->top , arr[0]);
    //Iteramos sobre todo el vector, empezando desde el indice uno ya que el elemento del indice cero ya lo insertamos en la pila
    for(int i = 1 ; i < n ; ++i){
        //Lo primero que debemos de verificar es si la pila esta vacia. Esto puede ocurrir ya que mas adelante en el codigo se podran hacer varios pops en la pila dejando la posibilidad de vaciarla en algunos casos
        //Si esto ocurre , lo que debemos de hacer es insertar en la pila, el dato de la posicion en la que nos encontramos y pasar a la siguiente iteracion
        if(s->size == 0){
            push(s, s->top , arr[i]);
            continue;
        }
        //Ahora lo que debemos de hacer es que mientras la pila no este vacia y el dato en la posicion que estamos es mayor al elemento Top de la pila, haremos pop en la pila, y el proximo mayor del elemento popeado de la pila sera la el dato de la posicion en la que estamos
        while(s->size > 0  && arr[i] > peek(s, s->top)){
            //Si las condiciones anteriores se cumplen, significa que el proximo del elemento Top de la pila , es el dato de la posicion en la que nos encontranos
            //Por ello, ya podemos imprimir el dato de la cima de la pila, con su siguiente proximo 
            cout<<"El siguiente mayor de "<<peek(s , s->top)<< " es "<< arr[i]<<endl;
            //Luego de imprimir,debemos de hacer pop en la pila, para que se puede comparar el siguiente elemento de la pila con el dato de la posicion en la que estamos
            pop(s, s->top);
        }
        //Luego de lo anterior, una vez que ya el dato en el que estamos sea menor , al dato de la cima de la pila, tendremos que hacerle un push a este para insertarlo en la pila y comparar con la siguiente posicion del arreglo
        push( s, s->top , arr[i]);
    }
    //Una vez terminado en el ciclo anterior, puede que en la pila queden datos. Esto significa que estos datos no tenian un proximo mayor, por lo que debemos de imprimir que su siguiente mayor es -1, y hacerles pop en la pila
    while(s->size > 0){
        //Imprimimos que el siguiente proximo mayor del dato en la cima de la pila es -1
        cout<<"EL siguiente mayor de "<<peek(s, s->top)<<" es "<<-1<<endl;
        //Hacemos pop en la pil
        pop(s, s->top);
    }
}

//------------------------------------------------------------------------------------------