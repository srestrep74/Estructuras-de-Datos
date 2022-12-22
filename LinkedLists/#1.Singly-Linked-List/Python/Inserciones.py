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

#Funcion para insertar nodo al inicio de la lista
#Esta recibira la lista, el nodo cabeza, y el nuevo dato a insertar
#Complejidad Temporal: O(1)
#Complejidad Espacial Auxiliar: O(1)
def push(list, head, data):
    #Creamos el nuevo nodo
    new_node = Node(data)
    #Este nuevo nodo tiene que ir de primero, por lo que ahora este debe de apuntar al primer nodo de la lista, es decir, al siguiente de la cabeza
    new_node.next = head.next
    #Ahora, la cabeza debe de apuntar al primer nodo, es decir, al nuevo nodo creado
    head.next = new_node


#Funcion para insertar al final de la lista
#Esta recibira la lista , la referencia al nodo encabezador, y el nuevo dato a insertar
#Complejidad Temporal: O(n)
#Complejidad Espacial Auxiliar: O(1)
def append(List, head, data):
    #Creamos el nuevo nodo
    new_node = Node(data)
    #Si la lista es nula
    if head == None : return
    #Si la lista esta vacia, se insertara el nuevo nodo como primero, es decir, el siguiente de la cabeza
    if head.next == None:
        head.next = new_node
    else: #Sino, iteramos hasta encontrar el ultimo nodo, es decir, cuando el siguiente del nodo en el que nos encontramos sea Nulo
        #Creamos una copia de la cabeza, para poder iterar sobre la lista, ya que sino, perderemos la referencia original de la cabeza
        last = head
        #Iteramos hasta que el siguiente del nodo en el que estamos sea nulo, es decir, hasta cuando estemos en el ultimo nodo
        while last.next is not None:
            last = last.next
        #Cuando acaba el ciclo anterior, sabemos que estamos parados sobre el ultimo nodo
        #Como queremos insertar un nuevo nodo al final, el siguiente del nodo en el que estamos debe de ser el nuevo nodo creado
        last.next = new_node
    #Finalmente incrementamos el valor de la longitud de la lista
    List.size += 1

#Funcion para insertar al final de la lista recursivamente
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
#Esta funcion debe de recibir el puntero de la lista, la referencia al nodo encabezador, y la referencia del nodo a insertar
def _append(List, head, new_node):
    #Case Base
    #Si la cabeza es nula retornamos, o si el siguiente de cabeza es nulo, insertamos en nuevo nodo como primero, es decir, el siguiente de cabeza
    if head is None : return
    if head.next is None:
        head.next = new_node
        #Incrementamos la longitud de la lista
        List.size += 1
        return
    else: #Sino, llamamos recursivamente la funcion, hasta que se cumpla el caso base, en donde sabremos que llegamos al ultimo nodo, y ahi insertaremos
        #Creamos una copia de la cabeza para poder recorrer la lista sin perder la referencia de la cabeza
        last = head
        #Hacemos el llamado recursivo, en donde pasaremos como cabeza, el siguiente de la cabeza actual
        _append(List, last.next, new_node)

#Funcion para insertar en la lista en una posicion dada
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
#Esta funcion recibira la lista, el nodo cabeza, el dato a insertar, y la posicion donde se quiere insertar
def insert(List, head, data, pos):
    #Creamos el nuevo nodo
    new_node = Node(data)
    #Si la posicion es mayor a la longitud de la lista o menor o igual a cero retornamos error
    if pos > List.size or pos <= 0 :
        print("La posicion no es valida")
        return
    #Si la posicion es uno, insertamos al inicio de la lista
    #Es decir, el nuevo nodo sera el siguiente de la cabeza
    if pos == 1 :
        new_node.next = head.next
        head.next = new_node
    else:
        #Sino, iteraremos por toda la lista hasta llegar al nodo que este en la posicion pasada y alli insertar
        #Creamos un contador el cual ayudara a saber la posicion del nodo en el que estemos parados
        cont = 1
        #Crearemos una copia de el siguiente de la cabeza para asi iterar, y estar en el nodo que corresponde al contador
        curr = head.next
        #Necesitamos siempre tener la referencia al nodo previo del que estamos parados, en este caso;
        prev = head
        #Iteramos hasta que curr que es nuestro nodo actual llegue al final de la lista:
        while curr is not None:
            #Preguntamos si la posicion es igual al contador
            if cont == pos:
                #Si entramos, significa que nuestro nodo actual, esta en la posicion pasada
                #Aqui es donde debemos de insertar el nuevo nodo
                #Para esto, necesitamos que el previo al nodo actual, apunte a el nuevo nodo
                prev.next = new_node
                #Luego, el siguiente de nuestro nuevo nodo, debe ser el nodo actual
                new_node.next = curr
                #Incrementamos la longitud de la lista
                List.size += 1
                return
            else:
                #Si lo anterior no se cumple, debemos de incrementar el contador y a su vez, pasar los dos nodos auxiliares a sus siguientes
                cont += 1
                prev = curr
                curr = curr.next

#Ahora crearemos una algoritmo para insertar elementos en una lista con una posicion dada pero de forma recursiva
#Para realizar esto necesitaremos dos funciones:
#Una que reciba la lista, la cabeza, el nodo a insertar, y la posicion. En esta haremos un par de verificaciones, y luego crearemos 3 variables, un contador para llevar la cuenta de en que nodo estamos, un nodo actual que sera el siguiente de la lista, y un nodo previo al actual que nos servira como referencia a la hora de insertar el nuevo nodo
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(n)
#Primera funcion:
def _insert(List, head, new_node, pos):
    #Si la posicion es mayor a la longitud de la lista o menor o igual a cero retornamos error
    if pos > List.size or pos <= 0 :
        print("La posicion no es valida")
        return
    #Si la posicion es uno, insertamos al inicio de la lista
    #Es decir, el nuevo nodo sera el siguiente de la cabeza
    if pos == 1 :
        new_node.next = head.next
        head.next = new_node
        return
    #Ahora , si lo anterior no se cumple, crearemos un contador que nos servira para saber en que posicion de la lista estamos.
    cont  = 1 
    #Ahora crearemos un nodo que nos servira como nodo actual el cual estara ubicado inicialmente en el primer elemento de la lista. Con este recorreremos la lista hasta que este en la posicion que necesitamos
    curr = head.next
    #Ahora necesitamos un nodo que nos sirva como previo al nodo actual creado anteriormente
    prev = head
    #Con estos datos creados , podemos llamar la funcion que los recibira y hara la busqueda del nodo en la posicion recursivamente e insertara alli
    __insert(List, head, new_node, prev, curr, cont, pos)
#Segunda Funcion
def __insert(List, head, new_node, prev, curr, cont, pos):
    #Caso base:
    #Si el contador es igual a la posicion, debemos de insertar alli el nodo con ayuda de prev y curr
    if cont  == pos:
        prev.next = new_node
        new_node.next = curr
        List.size += 1
        return
    else:
        #Sino , debemos de incrementar el contador, y avanzar los dos nodos auxiliares a su siguiente
        cont += 1
        prev = curr
        curr = curr.next
        #Llamamos recursivamente la funcion con los nuevos datos
        __insert(List, head, new_node, prev, curr, cont, pos)

#-----------------------------------------------------------