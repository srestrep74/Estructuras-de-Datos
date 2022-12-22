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

#Funcion para eliminar el primer nodo de una lista doblemente enlazada
#Complejidad Temporal : O(1)
#Complejidad Espacial : O(1)
#Esta funcion recibira la lista y la cabeza
def pop(List, head):
    #Verificamos si la lista esta vacio o no 
    if head.next is not None:
        #Si la lista no esta vacia, podemos realizar la operacion que necesitamos
        #Lo primero que haremos es guardar la referencia del primer nodo el cual es el que se quiere eliminar
        aux = head.next
        #Lo que tenemos que hacer, es que el que es ahora el segundo nodo de la lista, pase a ser el primero
        #Para esto, primero haremos que la cabeza apunte a este segundo nodo
        head.next = aux.next
        #Ahora, ya el que era el segundo nodo , paso a ser el primero, sin embargo, como es el primero, su previo debe de apuntar a la cabeza
        head.next.prev = head
        #Ya lo que haremos es desvincular totalmente el nodo auxiliar que creamos el cual contiene la referencia del nodo que era el primero en la lista
        #Para esto, haremos que sus punteros apunten  a nulo
        aux.prev , aux.next = None, None
        #Decrementaremos el valor de la longitud de la lista
        List.size -= 1
        #Eliminamos de memoria la referencia que era del primer nodo
        del aux

#Funcion para eliminar el ultimo nodo de una lista doblemente enlazada
#Complejidad Temporal: O(1)
#Complejidad Espacial: O(1)
#Funcion que recibe la lista, la referencia de la cabeza, y la referencia de la cola
def popLast(List, head, tail):
    #Verificamos que la lista no este vacia
    if head.next is not None:
        #Como no esta vacia, debemos de acceder al ultimo nodo de la lista.
        #Sin embargo, como estamos trabajando con listas doblemente enlazadas podemos acceder al ultimo nodo de la lista directamente
        #Empezaremos guardando la referencia del ultimo nodo en un nodo auxiliar para poder acceder a este nodo mas adelante sin perder su referencia
        aux = tail.prev
        #Ahora lo que debemos de hacer es que el penultimo nodo de la lista se vuelve el ultimo.
        #Para esto, tenemos que hacer que el este penultimo nodo, apunte a la cola
        aux.prev.next = tail
        #Como bien se sabe, la cola siempre tiene que apuntar al ultimo nodo de la cabeza, que en este caso se esta volviendo el penultimo nodo
        tail.prev = aux.prev
        #Con esto, el que era el penultimo nodo, ahora paso a ser el ultimo al estar conectado con la cola
        #Ya lo que debemos de hacer , es desvincular totalmente el nodo auxiliar que hicimos, es decir, desvincular totalmente el nodo que era el ultimo. Para esto hacemos que sus punteros apunten a nulo
        aux.prev , aux.next  = None , None
        #Decrementamos la longitud de la lista
        List.size -= 1
        #Eliminamos de memoria al referencia del nodo auxiliar
        del aux

#Funcion para eliminar un nodo en una posicion en una lista doblemente enlazada
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
#Esta funcion recibira la lista, la cabeza, la cola y la posicion a eliminar
def erase(List, head, tail, pos):
    #Verificamos que el valor de pos este entre el rango de la longitud de la lista
    if pos <= List.size and pos > 0:
        #Si la posicion a eliminar es el primer nodo
        if pos == 1 :
            #Lo mas recomendable es utilizar la funcion pop que hicimos anteriormente
            pop(List, head)
            return
        #Si la posicion a eliminar es el ultimo nodo
        if pos == List.size : 
            #Lo mas recomendable es utilizar la funcion popLast que hicimos anteriormente
            popLast(List, List.head, tail)
            return
        #Si no se entra a los nodos anteriores, significa que la posicion a eliminar se encuentra entre el rango de la longitud de la lista
        #Por ella, toca recorrer la lista hasta encontrar el nodo en dicha posicion
        #Para empezar, debemos de crear un contador el cual nos servira para llevar la cuenta de que posicion de la lista estamos
        cont = 1
        #Por otro lado, debemos de crear un nuevo nodo auxiliar que nos permita recorrer en la lista. Inicializaremos este nodo en el primero de la lista ya que la posicion de este siempre debe de corresponder con el valor del contador
        aux = head.next
        #Iteramos en la lista hasta el valor de la posicion recibidaL
        for i in range(1,pos+1):
            #Si el contador es igual a la posicion recibida
            if cont == pos:
                #Si entramos aca significa que ya el contador es igual al valor de la posicion recibida
                #Es decir, ya tenemos referenciado el nodo objetivo con el nodo auxiliar que creamos
                #Lo que tenemos que hacer ahora es que tanto el previo del nodo actual, con su siguiente se conecten, para asi desconectar el nodo objetivo de la lista
                #Lo primero que haremos es que el previo del siguiente nodo del que estamos, sera el previo del nodo actual
                aux.next.prev = aux.prev
                #Lo que debemos de hacer ahora es que el siguiente del nodo previo al que estamos, debe de ser el siguiente nodo del nodo actual
                aux.prev.next = aux.next
                #Con esto, desconectamos a aux de la lista. Ahora haremos que sus punteros apunten a nulo
                aux.prev , aux.next = None , None
                #Decrementamos el valor de la longitud de la list
                List.size -= 1
                #Eliminamos de memoria a aux
                del aux
            else:
                #Si no se cumple la condicion anterior significa que el contador aun no ha llegado a ser el valor de la posicion recibida
                #Esto quiere decir que aun no hemos encontrado el nodo objetivo por lo que debemos de incrementar el valor del contador y avanzar el nodo auxiliar a su siguiente
                cont += 1
                aux = aux.next


#---------------------------------------------------------------