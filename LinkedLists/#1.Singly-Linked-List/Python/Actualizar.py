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

#Funcion para actualizar el dato de un nodo en la lista
#Comlejidad Temporal: O(n)
#Complejidad Espacial: O(1)
#Esta funcion recibira la lista, la cabeza, el nuevo dato y la posicion del nodo a modificar
def update(List, head, new_data, pos):
    #Verificamos que la posicion recibida este entre los rangos de la longitud de la lista
    if pos <= List.size and pos > 0 :
        #Creamos el contador que nos ayudara a identificar en que posicion de la lista vamos
        cont = 1
        #Actualizamos la referencia de la cabeza al primer nodo ya que este nos ayudara a iterar sobre la lista, y ademas debe de corresponder con el valor del contador
        head = head.next
        #Iteraremos hasta el valor de la posicion recibido
        for i in range(1,pos+1):
            #Si el contador es igual a la posicion recibida, significa que ya estamos sobre el nodo a modificar
            if cont == pos:
                #Si entramos aca, significa que ya el apuntador de head, esta en el nodo de la posicion recibida
                # Por lo que aqui ya podemos modificar el dato de este nodo por el nuevo
                head.data = new_data
                #Luego de esto, ya podemos romper la ejecucion de esta funcion
                return
            else:
                #Si entramos aca, significa que el contador aun no tiene el valor de la posicion recibida, es decir, que head aun no esta en el nodo a modificar
                # Por lo tanto, debemos de incrementar el contador y avanzar el puntero de head
                cont += 1
                head = head.next 

#------------------------------------------------------