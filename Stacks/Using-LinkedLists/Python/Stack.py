#Lo primero que debemos de hacer para crear un stack utilizando listas , es crear la estructura nodo
#Como se vio en la seccion de listas enlazadas, cada nodo contiene el dato a almcanear y el puntero al siguiente nodo
class Node:
    def __init__(self):  #Constructor vacio
        self.data  = 0 
        self.next = None
    
    def __init__(self,data):  #Constructor que recibe el dato que contendra el nodo
        self.data  = data
        self.next = None

#Ahora debemos de crear la estructura que llamabamos lista en aquella seccion, la cual contenia el nodo cabeza de la lista
#En este caso, llamaremos a esta estructura Stack, y en lugar de hacer un nodo encabezador , lo llamaremos un nodo top el cual siempre apuntara al ultimo nodo en entrar a la pila
class Stack:
    def __init__(self):
        self.top = Node(None)
        self.size = 0

    #Funcion para insertar en un Stack, es decir, la funcion push
    #Complejidad Temporal: O(1)
    def push(self, data):
        #Creamos el nuevo nodo a ser insertado
        new_node = Node(data)
        #Ahora, debemos de hacer que este nuevo nodo apunte al nodo Top del Stack, para ello, crearemos un nodo auxiliar que guarde la referencia inicial del nodo Top
        aux = self.top
        #Con la copia anterior creada, haremos que el nuevo nodo apunte a esta
        new_node.next = aux.next
        #Ahora, como el nodo top siempre debe de apuntar al ultimo nodo en entrar , haremos eso 
        self.top.next = new_node
        #Incrementamos el tamano del Stack
        self.size += 1
    
    #Funcion para retirar elemento de la pila. Por definicion de la pila, solo se puede retirar el elemento que esta en la cima de la pila, es decir, el ultimo entrar 
    #Complejidad Temporal: O(1)
    def pop(self):
        #Verificamos que el Stack no este vacio
        if self.size > 0 :
            #Recordemos que en las pilas, solo se puede retirar el elemento de la cima de esta, no se puede retirar en la posicion que uno desee
            #Para esto, sabemos que el nodo top siempre apunta a este nodo que esta en la cima que necesitamos retirar
            #Como este sera retirado, el nodo top debera de apuntar al nuevo nodo que ocupe la cima, es decir, apuntara al siguiente del nodo que esta en la cima actualmente
            #Primero lo que haremos sera guardar una referencia del nodo que se encuentra actualmente en la cima
            peek = self.top.next
            #Ahora, haremos que el nodo Top apunte a la nueva cima, es decir, el siguiente del nodo de la cima
            self.top.next = peek.next
            #Para desvincular totalmente el nodo que estaba en la cima, lo haremos apuntar a nulo
            peek.next = None
            #Ahora, se pueden realizar dos opciones, se puede retornar este nodo con su dato, o directamente su dato, o se elimina directamente de memoria.
            #Esto dependera de lo que se desee hacer con el nodo expulsado de la pila
            #En este caso se eliminara de memoria
            del peek
            #Decrementamos el valor de la longitud de la pila
            self.size -= 1
    
    #Funcion para saber cual es el elemento que esta en la cima de la pila
    #Complejidad Temporal: O(1)
    def peek(self):
        #Verificamos que la lista no este vacia
        if self.size > 0 :
            #Aca como se esta trabajando con nodos, se puede retornar el nodo o directamente el dato que contiene
            #En este caso, retornaremos el dato que contiene el nodo
            return self.top.next.data
    
    #Funcion para determinar si la pila esta vacia o no
    #Complejidad Temporal: O(1)
    def isEmpty(self):
        #Retornamos el valor booleano del condicional 
        return self.size > 0


#------------------------------------------------------------------------------------

