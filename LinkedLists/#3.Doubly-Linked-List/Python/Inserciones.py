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

#Funcion para insertar nodo al inicio de una lista doblemente enlazada
#Complejidada Temporal: O(1)
#Complejidad Espacial: O(1)
#Esta funcion recibira la lista, la referencia de la cabeza, la referencia de la cola, y el nuevo dato a insertar
def push(List, head, tail, data):
    #Creamos el nuevo nodo a insertar
    new_node = Node(data)
    #Verificamos si la lista esta vacia
    if head.next is None:
        #Si la lista esta vacia, el nodo a insertar sera el primero y a la vez el ultimo.
        #Por ello, debemos manipular la cabeza y la cola
        #Lo primero que haremos es conectar el nodo con la cabeza. Como estamos insertando al inicio, el siguiente de la cabeza sera el nuevo nodo
        head.next = new_node
        #Ahora como el nodo esta de primero, debemos de decir que su previo ahora sera la cabeza
        new_node.prev = head
        #Luego, como hay un solo nodo en la lista, este tambien sera el ultimo, por lo que la cola debe de apuntar a este,
        #Asi haremos que el previo de la cola, sea el nuevo nodo
        tail.prev = new_node
        #Ahora, debemos de indicar que el siguiente del nuevo nodo es la cola, ya que es el ultimo elemento
        new_node.next = tail
        #Incrementamos el valor de la longitud de la lista
        List.size += 1 
        return
    else:
        #Si la lista no esta vacia, ya no necesitaremos manipular la cola, ya que esta estara apuntando al ultimo nodo que se encuentre en la lista
        #Ademas, como estamos insertando al inicio, la cola no intervendra
        #Ahora bien, como debemos de insertar al inicio, debemos de manipular la cabeza, y el primer nodo que se encuentra actualmente
        #Empezaremos diciendo que el siguiente del nuevo nodo, sera el primer nodo de la lista, es decir, el siguiente de cabeza
        new_node.next = head.next
        #Ahora, el previo del que es el primer nodo, debe de ser el que lo apunta, es decir, el nuevo nodo
        head.next.prev = new_node
        #Con esto ya desplazamos al que era el primer nodo, a la segunda posicion de la lista.
        #Ahora debemos de conectar el nuevo nodo con la cabeza para ubicarlo asi de primero
        #Decimos que el siguiente de la cabeza ahora sera el nuevo nodo
        head.next = new_node
        #Finalmente, decimos que el previo del nuevo nodo, sera que lo apunta, es decir, la cabeza
        new_node.prev = head
        #Incrementamos la longitud de la lista
        List.size += 1

#Funcion para insertar elemento al final de una lista doblemente enlazada
#Complejidad Temporal: O(1)
#Comlejidad Espacial: O(1)
#Esta funcion recibira la lista, la referencia de la cabeza, la referencia de la cola, y el nuevo dato a insertar
def append(List, head, tail, data):
    #Creamos el nuevo nodo
    new_node = Node(data)
    #Verificamos si la lista esta vacia
    if head.next is None:
        #Si la lista esta vacia, el elemento a insertar, sera el primero y el ultimo a la vez, es decir que debemos de manipular tanto la cabeza como la cola para esta insercion
        #Empecemos primero por la cabeza, como sera el primero de la lista, quiere decir que el nuevo nodo sera el siguiente de la cabeza
        head.next = new_node
        #Ahora, como el nuevo nodo esta de primeras, su previo sera la cabeza
        new_node.prev = head
        #Por otro lado, como el nodo tambien es a su vez el utlimo de la lista, debera apuntar a la cola
        new_node.next = tail
        #Finalmente, la cola siempre debe de apuntar al ultimo nodo de la lista como su previo
        tail.prev = new_node
        #Incrementamos el valor de la longitud de la lista
        List.size += 1 
        return
    else:
        #Si la lista no esta vacia, debemos de encontrar el ultimo nodo de la lista para poder hacer alli la insercion
        #Sin embargo, como estamos trabajando con listas doblemente enlazadas, tenemos acceso directo al ultimo nodo de la lista por medio de la cola
        #Esto nos evita tener que iterar a traves de  toda la lista y hacer una insercion mas rapida
        #Ahora bien , como se quiere insertar el nuevo nodo al final, lo primero que haremos es decir que el siguiente del ultimo nodo sera el nuevo nodo
        tail.prev.next = new_node
        #Ahora, diremos que el previo del nuevo nodo, sera el que lo apunta, es decir, el ultimo nodo
        new_node.prev = tail.prev
        #Con esto, el que era el ultimo nodo ya no lo es, ya quedo de penultimo en la lista
        #Ya para volver el nuevo nodo de la lista en el ultimo, este debe de apuntar a la cola
        new_node.next = tail
        #Finalmente, la cola debe de apuntar al ultimo nodo de la lista. Es decir, el previo de la cola sera el nuevo nodo
        tail.prev = new_node
        #Incrementamos el valor de la longitud de la lista
        List.size += 1

#Funcion para insertar un elemento en una posicion dada en una lista doblemente enlazada
#Complejidad Temporal : O(n)
#Complejidad Espacial: O(1)
#Esta funcion recibira la lista, la referencia de la cabeza, la referencia de la cola, la posicion a insertar y el dato a insertar
def insert(List, head, tail, pos, data):
    #Si la posicion recibida es 1, es decir, si pos == 1
    if pos == 1:
        #Llamamos a la funcion push, o podemos copiar su codigo directamente aca
        #Por fines practicos se llamara a la funcion
        push(List, head, tail, data)
        return
    #Si la posicion es la ultima de la lista, es decir, si pos == list.size
    if pos == List.size:
        #Llamamos la funcion append o copiamos su codigo directamente aca
        append(List, head, tail, data)
        return
    #Si no se ejecutaron las anteriores condiciones, quiere decir que la posicion recibida se encuentre entre el rango de la longitud de la lista
    #Por ello, debemos de iterar sobre la lista hasta encontrar el nodo objetivo, y alli realizar la operacion de insertar
    #Primero debemos de crear el nuevo nodo a insertar
    new_node = Node(data)
    #Creamos un contador el cual nos ayudara a saber en que posicio de la lista estamos
    cont = 1
    #Crearemos un nodo auxiliar el cual nos servira para iterar sobre la lista en busca del nodo objetivo. Ademas, este debe de empezar en el primer nodo de la lista ya que este nodo siempre debe de corresponder con la posicion que lleve el contador
    temp = head.next
    #Iteramos hasta la longitud de la lista
    for i in range(1,pos+1):
        #Si el contador es igual a la posicion
        if cont == pos:
            #Si entramos aca, significa que ya el contador alcanzo el valor de la posicion recibida, y por lo tanto, nuestro nodo auxiliar temp, esta en el nodo objetivo
            #Aca es donde toca hacer la operacionde insercion del nuevo nodo
            #Para empezar, crearemos un copia de la referencia del nodo previo al que estamos del nodo objetivo
            aux = temp.prev
            #Ahora , lo que haremos es decir que el siguiente del nuevo nodo, sera el nodo objetivo
            new_node.next = temp
            #Ahora diremos que el previo del nodo objetivo es el nuevo nodo
            temp.prev = new_node
            #Ahora, la referencia que guardamos del nodo previo al nodo objetivo, su siguiente sera el nuevo nodo
            aux.next = new_node
            #Finalmente, diremos que el previo del nuevo nodo, sera la referencia del nodo previo 
            new_node.prev = aux
            #Incrementamos el valor de la longitud de la list
            List.size += 1
        else:
            #Si entramos aca, significa que el contador aun no es igual a la posicion recibida , por lo tanto, nuestro nodo temp, aun no llega al nodo objetivo
            #Para esto, incrementamos el contador y pasamos nuestro nodo temp a su siguiente
            cont += 1
            temp = temp.next

#----------------------------------------------------------------------------