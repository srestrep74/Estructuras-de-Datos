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

#Funcion para insertar elemento al inicio de una lista circular enlazada
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
def push(List, head, data):
    #Creamos el nuevo nodo a insertar
    new_node = Node(data)
    #Si la lista esta vacia
    if head.next is None:
        #Si la lista esta vacia, significa que el nodo a insertar sera el primero y a la vez el ultimo
        #Ademas, como estamos trabajando en una lista circular, el ultimo nodo debe de apuntar al primero, por lo que como este nodo es el primero y el ultimo, se apuntara asi mismo por definicion de la lista circular
        #Empecemos ubicando este nuevo nodo como el primero, es decir, que la cabeza debe de apuntar a el
        head.next = new_node
        #Ahora, como este nodo es el ultimo, debe de apuntar al primero, en este caso, a si mismo
        new_node.next = new_node
        #Incrementamos la longitud de la list
        List.size += 1
        return
    else:
        #Si entramos aca, significa que la lista no esta vacia. Sin embargo, como vamos a insertar en el inicio de la lista, este nodo debe de ser apuntado por el ultimo, por lo que primero debemos hallar cual es el ultimo nodo de la lista
        #Para esto, crearemos un nodo auxiliar llamado last, el cual nos ayudara a recorrer la lista hasta encontrar el ultimo nodo
        last = head
        #Ahora lo que haremos es recorrer la lista hasta que volvamos al primer nodo
        #A comparacion de c++, aca en python no existen bucles do-while, por lo que toca emularlo con un while True
        while True:
            last = last.next
            if last.next is head.next: break
        #Luego del ciclo anterior, ya tenemos la referencia del ultimo nodo localizada
        #Por ello, ya podemos continuar normal con la insercion del nuevo nodo en la primera posicion
        #Para ello, haremos que el nuevo nodo apunte al que es el actual primer nodo de la lista
        new_node.next = head.next
        #Para terminar de ubicar el nuevo nodo como el primero, debemos de hacer que el siguiente de la cabeza sea este
        head.next = new_node
        #Finalmente, haremos que el ultimo nodo ya apunte al primero de la lista, es decir, al nuevo nodo
        last.next = new_node
        #Incrementamos el valor de la lista
        List.size += 1

#Funcion para insertar nodo al final de una lista circular enlazada
#Complejidad Temporal: O(n)
#Complejidad Espacial: O(1)
def append(List, head, data):
    #Si la lista esta vacia
    if head.next is None:
        #Llamamos la funcion push para insertar en la primera posicion
        push(List, head, data)
        return
    else:
        #Si la lista, no esta vacia, debemos de buscar cual es el ultimo nodo de la lista para alli insertar
        #Primero debemos de crear el nuevo nodo a insertar
        new_node  = Node(data)
        #Ahora, debemos de crear un nodo auxiliar para recorrer la lista hasta encontrar el ultimo nodo, es decir, hasta que su siguiente sea el primer nodo de la lista
        last = head
        #Ahora con este nodo auxiliar recorreremos la lista hasta encontrar el ultimo nodo
        while True:
            last = last.next
            if last.next is head.next : break
        #Ya como encontramos el ultimo nodo de la lista, podemos insertar alli el nodo
        #Lo primero que haremos es decir que el siguiente del nuevo nodo, es el actual siguiente del ultimo nodo
        #Aca implicitamente , estamos diciendo que el siguiente del nuevo nodo sera el primero de la lista
        new_node.next = last.next
        #Ahora diremos que el siguiente del ultimo nodo sera el nuevo nodo
        last.next = new_node
        #Incrementamos el valor de la longitud de la lista
        List.size += 1

def traverse(head):
    first = head.next
    while True:
        head = head.next
        print(head.data , end=" ")
        if head.next is first: break

def main():
    List = LinkedList()
    for i in range(1,11):
        append(List, List.head, i)
    traverse(List.head)

main()