#Crearemos la clase nodo, el cual contendra dos atributos: El valor que contendra el nodo y el puntero al siguiente nodo
#Ademas, tendra dos constructores, uno vacio, y otro en donde se reciba el dato que contendra el nodo
class Node:
    def __init__(self):
        self.data = None
        self.next = None
    
    def __init__(self, data):
        self.data  = data
        self.next = None


#Ahora, crearemos la clase lista, la cual contendra la longitud de la lista, y el nodo encabezador
class LinkedList:
    def __init__(self):
        self.size = 0

#Funcion para recorrer una lista circular
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
def traverse(head):
    #Lo primero que haremos sera guardar la referencia del primer nodo, ya que debemos recorrer la lista hasta volver a el
    first = head.next
    #Ahora lo que haremos, sera iterar hasta que el siguiente del nodo con el que iteramos sea el primero
    while True:
        head = head.next
        print(head.data, end=" ")
        if head.next is first : break
