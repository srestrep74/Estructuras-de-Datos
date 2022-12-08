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