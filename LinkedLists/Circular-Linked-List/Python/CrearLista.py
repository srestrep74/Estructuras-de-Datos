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
        self.head = Node(None)

