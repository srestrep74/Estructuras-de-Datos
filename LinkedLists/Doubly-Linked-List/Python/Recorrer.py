#Creamos la clase nodo, la cual tendra tres atributos: EL dato que contendra el nodo, el puntero a su siguiente y el puntero a su previo
#Ademas tendra dos constructores, uno vacio, y otro que reciba el dato que almacenara el nodo
class Node:
    def __init__(self):
        self.data = None
        self.next = None
        self.prev = None

    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

#Ahora crearemos la clase lista, la cual tendra el tamano de la lista, el nodo cabeza y el nodo cola
#Ademas, tendra un solo constructor vacio
class LinkedList:
    def __init__(self):
        self.size = 0
        self.head = Node(None)
        self.tail = Node(None)

#Funcion para recorrer lista doblemente enlazada partiendo de la cabeza
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
#Esta funcion recibira la cabeza y la cola de la lista
def traverse(head, tail):
    #Iteramos hasta que el siguiente de la cabeza sea la cola
    while head.next is not tail:
        #Actualizamos la cabeza al siguiente
        head = head.next
        #Imprimimos el dato
        print(head.data, end=" ")

#Funcion para recorrer lista doblemente enlazada recursivamente partiendo desde la cabeza
#Complejidad temporal : O(n)
#Complejidad Espacial: O(n
#Esta funcion recibira la cabeza y la cola de la lista
def _traverse(head, tail):
    #Caso base
    #Se parara cuando el siguiente del nodo iterador sea la cola
    if head.next is tail: return
    else:
        #Se actualiza el valor del nodo iterador
        head = head.next
        #Se imprime el dato
        print(head.data, end=" ")
        #Se llama recursivamente la funcion
        _traverse(head, tail)

#Funcion para recorrer una lista doblemente enlazada empezando por la cola
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
def traverse2(head, tail):
    #Se iterara hasta que el siguiente del nodo iterador sea la cabeza
    while tail.prev is not head:
        #Actualizamos el valor del nodo iterador
        tail = tail.prev
        #Imprimimos el dato
        print(tail.data, end=" ")

#Funcion para recorrer lista doblemente enlazada recursivamente partiendo desde la cola
#Complejidad temporal : O(n)
#Complejidad Espacial: O(n)
#Esta funcion recibira la cabeza y la cola de la lista
def _traverse2(head, tail):
    #Caso base
    #Se parara cuando el siguiente del nodo iterador sea la cola
    if tail.prev is head: return
    else:
        #Se actualiza el valor del nodo iterador
        tail = tail.prev
        #Se imprime el dato
        print(tail.data, end=" ")
        #Se llama recursivamente la funcion
        _traverse2(head, tail)

#------------------------------------------------------------------------