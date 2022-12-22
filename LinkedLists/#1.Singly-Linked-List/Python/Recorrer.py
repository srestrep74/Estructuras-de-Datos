#Creamos la clase nodo en donde damos la estructura de lo que contiene un nodo con dos constructores disponibles
class Node:
    def __init__(self): #Constructor vacio
        self.data = None #Dato que almacenara el nodo
        self.next = None #Nodo siguiente
    
    def __init__(self, data): #Constructor que recibe el valor del nodo
        self.data = data
        self.next = None

#Creamos la clase lista la cual contendra la cabeza de la lista y un atributo para llevar el control del tamano de la lista
class LinkedList:
    def __init__(self):
        self.head = Node(None)
        self.size = 0

#Funcion para recorrer lista simple 
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
#Esta funcion recibira como parametro la referencia de la cabeza
def traverse(head):
    #Iteramos hasta que el siguiente de cabeza sea nulo
    while head.next is not None:
        #Actualizamos la referencia de head
        head = head.next
        #Imprimimos el dato de head
        print(head.data, end=" ")
    """
    Seguramente muchos piensen por que esta vez a comparacion de otras funciones como la de agregar nodo, solo recibe el puntero de la cabeza, y no su referencia.
    En este caso, no se va a modificar ningun dato, por lo que no es necesario pasar la referencia como tal de la cabeza y esto ademas, permite que no modifiquemos datos durante el recorrido por error.
    Por ello, se envia el puntero de la cabeza, que ira pasando nodo por nodo, pero en ningun momento, se modificara la referencia de la cabeza.
    Ademas, este puntero solo cambiara su estado dentro de esta funcion, fuera de esta, seguira apuntanto a la cabeza
    """

#Funcion para recorrer lista recursivamente
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(n)
def _traverse(head):
    #Case Base;
    #Si el siguiente de la cabeza es nulo, quiere decir que estamos en el final de la lista, por lo tanto, paramos
    if head.next is None: return
    else:
        #Sino, quiere decir que no hemos llegado al final por lo que pasamos el puntero de cabeza a su siguiente
        head = head.next
        #Imprimimos el dato que contenga head
        print(head.data, end=" ")
        #Llamamos recursivamente la funcion con el nuevo valor de head
        _traverse(head)

#------------------------------------------------