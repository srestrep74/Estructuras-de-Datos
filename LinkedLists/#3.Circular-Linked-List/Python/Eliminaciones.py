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

#Funcion para eliminar primer nodo de una lista circular
#Complejidad Temporal : O(n)
#Comlejidad Espacial : O(1)
def pop(List, head):
    #Si la lista no esta vacia y apenas tiene un nodo
    if head.next is not None and List.size == 1:
        #Si la lista apenas tiene un solo elemento , podemos eliminarlo directamente y dejar la lista vacia
        #Antes debemos de tener la referencia del primer nodo guardada para luego eliminarla
        first = head.next
        #Debemos de poner a la cabeza apuntar a nulo
        head.next = None
        #Decrementamos el valor de la longitud de la list
        List.size -= 1  
        #Eliminamos el que era el primer nodo
        del first
        return
    else:
        #Si la lista tiene mas de un nodo, debemos de buscar cual es el ultimo nodo, ya que al eliminar el primero, el ultimo debe de apuntar ya al nuevo primero.
        #Para esto, crearemos un nodo auxiliar para iterar sobre la lista hasta que llegue al ultimo
        last = head
        #Iteraremos hasta que el siguiente del nodo auxiliar sea el primer nodo. Esto indicara que hemos llegado al ultimo nodo
        while True:
            last = last.next
            if last.next is head.next: break
        #Ahora ya conocemos cual es el ultimo nodo,por lo que podemos pasar a eliminar el primer nodo
        #Empezaremos guardando la referencia del primer nodo
        first = head.next
        #Ahora lo que haremos es decir que el siguiente de cabeza sera el segundo nodo de la lista, es decir, el siguiente del primero
        head.next = first.next
        #Con esto, ya tenemos un nuevo primer nodo, lo que prosigue es conectar el ultimo nodo, con este nuevo primer nodo
        last.next = head.next
        #Ahora, el nodo que antiguamente era el primer nodo, lo haremos apuntar a nulo
        first.next = None
        #Decrementamos el valor de la longitud de la lista
        List.size -= 1
        #Eliminamor de memoria la referencia del antiguo primer nodo
        del first

#Funcion para eliminar ultimo nodo de una lista enlazada circular
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
def popLast(List, head):
    #Si la lista no esta vacia y apenas tiene un nodo
    if head.next is not None and List.size == 1:
        #Si la lista apenas tiene un nodo podemos llamar la funcion pop
        pop(List, head)
        return
    else: 
        #Si la lista tiene mas de un nodo, toca encontrar la referencia de este y de su previo para poder hacer alli la eliminacion
        #Lo que haremos es crearnos un nodo auxiliar con el cual recorrer para encontrar el ultimo nodo
        last = head
        #Ademas crearemos un nodo previo que siempre se actualizara con el valor de last cada vez que este avance en la lista
        prev = None
        #Ahora iteraremos en la lista con el nodo last, hasta que su siguiente sea el primer nodo de la lista, es decir, cuando se encuentre en el ultimo nodo
        while True:
            prev = last
            last = last.next
            if last.next is head.next : break
        #Ahora, ya tenemos una referencia al ultimo nodo , y a su previo por lo que ya podemos realizar la operacion de eliminado alli
        #Lo primero que haremos sera decir que el siguiente de previo sera el siguiente del ultimo nodo. Es decir, ahora el previo se convertira en el ultimo nodo y este apuntara ahora al primer nodo de la lista
        prev.next = last.next
        #Ahora, decimos que el siguiente del que era el ultimo nodo sera nulo
        last.next = None
        #Decrementamos el valor de la longitud de la lista
        List.size -= 1
        #Eliminamos de memoria el que era el ultimo nodo
        del last

#Funcion para eliminar nodo en una posicion determinada en una lista circular
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
def erase(List, head, pos):
    #Verificamos que la lista no este vacia
    if head.next is not None:
        #Si la posicion a eliminar es el primer nodo
        if pos == 1:
            #Aca por fines practicas utilizaremos la funcion pop
            pop(List, head)
            return
        #Si la posicion a eliminar es el ultimo nodo
        if pos == List.size:
            #Aca utilizaremos la funcion popLast
            popLast(List, head)
            return
        #Si no se cumplen los anteriores casos, significa que la posicion a eliminar esta entre el rango de la longitud de la lista
        #Por ello debemos de iterar hasta encontrar el nodo que corresponda a dicha posicion
        #Para empezar, crearemos un contador el cual nos ayudara a ir mirando en que posicion de la lista estamos
        cont = 1
        #Ahora crearemos un nodo auxiliar curr, el cual nos ayudara a recorrer la lista hasta encontrar el nodo que necesitamos. Ademas, este empezara siendo el primer nodo de la lista ya que este siempre necesitara estar en la misma posicion que tenga el contador
        curr = head.next
        #Por otro lado, siempre necesitamos un nodo previo del que estamos iterando para asi poder realizar la operacion de eliminado mas adelante
        prev = head
        #Ahora, iteraremos hasta llegar a la posicion recibida
        for i in range(1,pos+1):
            #Si el contador es igual a la posicion recibida
            if cont == pos:
                #Si entramos aca significa que ya hallamos el nodo objetivo con curr
                #Ahora toca hacer la operacion de eliminado, para eso haremos que el previo de curr, apunte al siguiente de curr
                prev.next = curr.next
                #Ahora haremos que curr apunte a nulo
                curr.next = None
                #Decrementamos el valor de la longitud de la lista
                List.size -= 1
                #Eliminamos de memoria el nodo objetivo
                del curr
                return
            else:
                #Si no se entra a lo anterior, significa que aun no hemos llegado al nodo obejtivo por lo que toca incrementar el contador y los dos nodos auxiliares
                cont += 1
                prev = curr
                curr = curr.next

#--------------------------------------------------------------------------------