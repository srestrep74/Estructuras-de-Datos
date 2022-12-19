#include<bits/stdc++.h>
using namespace std;


//Definimnimos una variable constante la cual indicara el tamano que tendra la pila
const int MAX = 1000;


//Creamos la clase Stack. Esta contendra los siguiente elementos:
/*
- int max : Indicara el en que posicion del arreglo esta el valor maximo de la pila, es decir, el ultimo elemento en entrar
- int a [] : Asi se llamara el arreglo que lo utilizaremos como pila
- Stack () : Sera el constructor el cual inicializara el valor de top como -1 ya que no hay elementos en el arreglo inicialmente
- push() : Funcion para insertar elementos en la pila
- pop(): Funcion para eliminar elemento en la pila
- isEmpty : Funcion para saber si la pila esta vacia o no 
- peek() : Funcion para saber cual es el elemento en la cima de la pila
*/

class Stack{
    public:
        int top;
        int A[MAX];
        Stack(){this->top = -1;}
        void push(int data);
        int pop();
        bool isEmpty();
        int peek();
};


//Definamos como va a ser la funcion push
//Complejidad Temporal: O(1)
void Stack::push(int data){
    //Si el indice de top, no es mayor o igual al tamano del arreglo
    if(this->top < (MAX-1)){
        //Incrementamos top a la siguiente posicion, y alli insertamos
        A[++top] = data;
    }
}

//Definamos como va a ser la funcion pop
//Complejidad Temporal: O(1)
int Stack::pop(){
    //Si la pila no esta vacia
    int x;
    if(top > -1){
        //Guardamos en una variable, el valor de la ultima posicion del arreglo, y luego decrementamos el valor de top 
        x = A[top--];
    }
    return x ;
}

//Definamoa la funcion peek
//Complejidad Temporal: O(1)
int Stack::peek(){
    //Creamos variable en donde se guardara el valor que arroje peek
    int x ;
    //Si la pila no esta vacia
    if(top > -1){
        //Guardamos en una variable el ultimo dato del arreglo, es decir, el valor donde apunte top
        x = A[top];
    }
    return x;
}

//Definamos la funcion isEmpty
//Complejidad Temporal: O(1)
bool Stack::isEmpty(){
    return (top < 0);
}

//-------------------------------------------------------------------------



