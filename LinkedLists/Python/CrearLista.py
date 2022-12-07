#Creamos la clase nodo en donde damos la estructura de lo que contiene un nodo con dos constructores disponibles
class Node:
    def __init__(self): #Constructor vacio
        self.data = None #Dato que almacenara el nodo
        self.next = None #Nodo siguiente
    
    def __init__(self,data): #Constructor que recibe el valor del nodo
        self.data = data
        self.next = None

#Creamos la clase lista la cual contendra la cabeza de la lista y un atributo para llevar el control del tamano de la lista
class LinkedList:
    def __init__(self):
        self.head = Node(None)
        self.size = 0