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

#Funcion para eliminar primer nodo de la lista
#Complejidad Temporal: O(1)
#Complejidad Espacial: O(1)
#Esta funcion recibira la lista y su cabeza
def pop(List, head):
    #Verificamos que la lista no este vacia
    if List.size > 0:
        #Creamos un nodo temporal que guarde la referencia al primer nodo de la lista, para luego poder acceder a el y realizar otras operaciones
        temp = head.next
        #Como necesitamos eliminar el primer nodo de la lista, antes de hacerlo, debemos de hacer que el la cabeza, la cual siempre apunta al primer elemento, ahora debe de apuntar , al siguiente del primer nodo actual.
        head.next = head.next.next
        #Con la cabeza ya apuntando al nuevo primer nodo, el antiguo primer nodo, lo desvincularemos de la lista, es decir, lo pondremos a apuntar a nulo
        temp.next = None
        #Decrementaremos el valor de la longitud de la lista
        List.size -= 1
        #Eliminamos la referencia al antiguo primer nodo
        del temp

#Funcion para eliminar ultimo nodo de una lista 
#Complejidad: O(n)
#Complejidad: O(1)
#Esta funcion recibira la lista, y su cabeza
def popLast(List, head):
    #Verificamos que la lista no este vacia
    if List.size > 0:
        #Creamos un nodo auxliar que nos servira como nodo actual a la hora de recorrer la lista. Este lo inicializaremos en el primer nodo de la lista
        curr = head.next
        #Ahora necesitamos tener un nodo que nos sirva para tener siempre una referencia al nodo previo del nodo curr. En este caso, empezaremos inicializando a prev en la cabeza
        prev = head
        #Ahora, iteraremos hasta que el siguiente de curr sea nulo, es decir, hasta que curr se encuentre en el ultimo nodo de la lista y a su vez tengamos referencia de su previo , con el nodo prev
        while curr.next is not None:
            #Ahora tenemos que empezar a pasar nuestros nodos auxiliares a sus siguiente, empezando actualizando a prev
            prev = curr
            curr = curr.next
        #Acabado el ciclo, sabemos que ya curr se encuentra en el ultimo nodo, y prev es su previo
        #Antes de pasar a eliminar a curr, es decir, el ultimo nodo de la lista, debemos de asegurarnos de que la lista siga su flujo normal. Para haremos que prev apunte ahora al siguiente de curr. Esto desvinculara a prev de curr, y asi la lista tendra un nuevo flujo en donde no accede a curr
        prev.next = curr.next
        #Ahora debemos de desvincular a curr de la lista, haciendolo apuntar a nulo
        curr.next = None
        #Decrementamos el valor de la longitud de la lista
        List.size -= 1
        #Eliminamos a curr de memoria, es decir, el ultimo nodo
        del curr

#Funcion para eliminar ultimo nodo de una lista recursivamente
#Comlejidad Temporal: O(n)
#Complejidad Espacial :O(n)
#Esta funcion recibira la lista , la cabeza, y dos nodos auxiliares: prev y curr. El primero llegare inicializado con la referencia de la cabeza de la lista y el segundo llegare con la referencia del primer nodo de a lista
def _popLast(List, head, prev, curr):
    #Caso base:
    #Debemos de parar cuando estemos ubicados en el utlimo ya que alli es donde se tendra que realizar la operacion de eliminar.
    #Para esto iremos moviendo a curr durante toda la lista hasta que llegue al ultimo elemento, es decir, hasta que su siguiente sea nulo.
    #De igual manera, moveremos a prev simultaneamente ya que este nos servira para tener una referencia al nodo pervio de curr
    if curr.next is None:
        #En este punto sabemos que curr esta en el ultimo nodo y prev esta antes de el.
        #Antes de pasar a eliminar el ultimo nodo, es decir a curr, debemos de asegurarnos de la que lista siga teniendo un flujo normal, y para esto si eliminamos a curr, dejaremos a prev sin ningun siguiente establecid.
        #Por ello, debemos de decir que e siguiente de prev sera el siguiente de curr. De esta manera ya no tendremos acceso a curr por niguna nodo de la lista
        prev.next = curr.next
        #Desvincularemos a curr de la lista haciendolo apuntar a nulo
        curr.next = None
        #Decrementamos la longitud de la lista
        List.size -=1
        #Eliminamos de memoria curr, es decir, el ultimo nodo
        del curr
        return
    else:
        #Si no se entro al caso base, significa que curr aun ha llegado al ultimo nodo. Por lo que debemos de actualizarlo y pasarlo a su siguiente.
        #Sin embargo, siempre necesitamos la referencia al nodo previo de curr, por lo tanto, tambien debemos de actualizar a prev
        prev = curr
        curr = curr.next
        #Ahora que los datos estan actualizados, podemos llamar la funcion recursivamente pasandole estos nuevos datos
        _popLast(List, head, prev, curr)

#Funcion para eliminar nodo en una posicion recibida de una lista
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
#Esta funcion recibe la lista, su cabeza y la posicion de la lista a eliminar
def erase(List, head, pos):
    #Verificamos que la lista no este vacia y la posicion no se ni mayor ni menor a la longitud de la lista
    if head is not None and pos <= List.size and pos > 0:
        #Crearemos nuestra variable contador empezando desde uno la cual nos ayudara a identificar en que posicion de a lista estamos hasta identificar que esta el valor de posicion
        cont = 1
        #Ahora crearemos un nodo curr el cual empezara desde el primer nodo de la lista, ya que este siempre debe de corresponder con la posicion que tenga el contador. Es decir, este terminara ubicandose en la posicion del nodo objetivo
        curr = head.next
        #Por otro lado, tambien necesitamos siempre una referencia al nodo anterior de curr para poder realizar la operacion de eliminado. Por eso, debemos de crear otro nodo llamado a prev el cual siempre sera el anterior a curr
        prev = head
        #Ahora iteraremos hasta el valor de la posicion
        for i in range(1,pos+1):
            #Debemos de preguntar si el contador es igual a la posicion y asi sabremos si ya estamos parados sobre el nodo objetivo o no
            if cont == pos:
                #Si se entra aca, significa que curr ya esta en el nodo objetivo asi que se debe de seguir con la operacion de eliminar
                #Antes de eliminar el nodo objetivo, debemos de asegurarnos siga con el flujo normal. Para esto, haremos que prev apunte al siguiente de curr. 
                #De esta forma , por ningun lado de la lista se tendra acceso ahora a curr, el cual es el nodo objetivo
                prev.next = curr.next
                #Ahora desvincularemos a curr de la lista haciendolo apuntar a nulo
                curr.next = None
                #Decrementamos la longitud de la lista
                List.size -= 1
                #Eliminamos de memoria a curr, es decir, al nodo objetivo
                del curr
            else: 
                #Si se entra aca significa que el contador aun no ha igualado el valor de la posicion recibida.
                #Es decir, curr aun no se ha ubicado en el nodo objetivo
                #Por lo tanto debemos de incrementar el contador y actualizar los nodos auxiliares a sus siguientes
                cont += 1
                prev = curr
                curr = curr.next

#--------------------------------------------------------------