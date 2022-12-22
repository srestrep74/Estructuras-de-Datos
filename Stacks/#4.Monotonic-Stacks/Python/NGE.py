"""
En este archivo veremos uno de los problemas as comunes que se pueden resolver de una forma optima utilizando pilas monotonas.
Este problema se trata  que dado un arreglo de elementos numericos, hay que hallar cual es el siguiente elemento mayor en el arreglo, de cada posicion. Si el elemento no tiene uno mayor a la derecha, sera -1 la respuesta de este. 
Veamos un ejemplo de como seria una entrada y salida de esto:

Input: arr[] = [4,5,2,25]
Output:  4 -> 5
		 5 -> 25
		 2 -> 25
		 25 -> -1

Ahora bien , lo que primero se pensaria al hacer este problema es iterar todo el arreglo por cada elemento de este, buscando proximo mayor de la posicion del arreglo en  la que nos encontremos. Sin embargo, en cuanto a eficiencia es un mal algoritmo ya que su complejidad temporal es cuadratica. 
Por ello, es mas conveniente usar otras estructuras como lo es la pila monotona o un mapa, los cuales aumentando la complejidad espacial a lineal, se puede reducir la complejidad temporal a lineal, ya sea con pilas monotonas o con un mapa.

Sin embargo, en este ocasion veremos como resolver este problema de la forma tipica, es decir, con dos ciclos, y con pilas monotonas, para mirar las diferencias entre ambos algoritmos, y asi ver una de las tantas aplicaciones que nos permite esta variante de las pilas. En este caso, implementaremos nuestra pila mediante una lista enlazada. 
"""

#Lo primero que debemos de hacer para crear un stack utilizando listas , es crear la estructura nodo
#Como se vio en la seccion de listas enlazadas, cada nodo contiene el dato a almcanear y el puntero al siguiente nodo
class Node:
    def __init__(self):  #Constructor vacio
        self.data  = 0 
        self.next = None
    
    def __init__(self,data):  #Constructor que recibe el dato que contendra el nodo
        self.data  = data
        self.next = None

#Ahora debemos de crear la estructura que llamabamos lista en aquella seccion, la cual contenia el nodo cabeza de la lista
#En este caso, llamaremos a esta estructura Stack, y en lugar de hacer un nodo encabezador , lo llamaremos un nodo top el cual siempre apuntara al ultimo nodo en entrar a la pila
class Stack:
    def __init__(self):
        self.top = Node(None)
        self.size = 0

    #Funcion para insertar en un Stack, es decir, la funcion push
    #Complejidad Temporal: O(1)
    def push(self, data):
        #Creamos el nuevo nodo a ser insertado
        new_node = Node(data)
        #Ahora, debemos de hacer que este nuevo nodo apunte al nodo Top del Stack, para ello, crearemos un nodo auxiliar que guarde la referencia inicial del nodo Top
        aux = self.top
        #Con la copia anterior creada, haremos que el nuevo nodo apunte a esta
        new_node.next = aux.next
        #Ahora, como el nodo top siempre debe de apuntar al ultimo nodo en entrar , haremos eso 
        self.top.next = new_node
        #Incrementamos el tamano del Stack
        self.size += 1
    
    #Funcion para retirar elemento de la pila. Por definicion de la pila, solo se puede retirar el elemento que esta en la cima de la pila, es decir, el ultimo entrar 
    #Complejidad Temporal: O(1)
    def pop(self):
        #Verificamos que el Stack no este vacio
        if self.size > 0 :
            #Recordemos que en las pilas, solo se puede retirar el elemento de la cima de esta, no se puede retirar en la posicion que uno desee
            #Para esto, sabemos que el nodo top siempre apunta a este nodo que esta en la cima que necesitamos retirar
            #Como este sera retirado, el nodo top debera de apuntar al nuevo nodo que ocupe la cima, es decir, apuntara al siguiente del nodo que esta en la cima actualmente
            #Primero lo que haremos sera guardar una referencia del nodo que se encuentra actualmente en la cima
            peek = self.top.next
            #Ahora, haremos que el nodo Top apunte a la nueva cima, es decir, el siguiente del nodo de la cima
            self.top.next = peek.next
            #Para desvincular totalmente el nodo que estaba en la cima, lo haremos apuntar a nulo
            peek.next = None
            #Ahora, se pueden realizar dos opciones, se puede retornar este nodo con su dato, o directamente su dato, o se elimina directamente de memoria.
            #Esto dependera de lo que se desee hacer con el nodo expulsado de la pila
            #En este caso se eliminara de memoria
            del peek
            #Decrementamos el valor de la longitud de la pila
            self.size -= 1
    
    #Funcion para saber cual es el elemento que esta en la cima de la pila
    #Complejidad Temporal: O(1)
    def peek(self):
        #Verificamos que la lista no este vacia
        if self.size > 0 :
            #Aca como se esta trabajando con nodos, se puede retornar el nodo o directamente el dato que contiene
            #En este caso, retornaremos el dato que contiene el nodo
            return self.top.next.data

#Ahora haremos la funcion que halla el NGE de cada elemento del arreglo pero usando dos ciclos anidados, es decir, la solucion con complejidad Cuadratica
#Complejidad Temporal: O(n^2)
#Esta funcion recibira el vector sobre el cual se iterara para hallar los maximos siguientes de cada elemento
def NGEArrays(arr):
    #Lo primero que debemos de hacer es crear una variable la cual ira almacenando el elemento mayor proximo de cada posicion del arreglo. Inicialmente, este valdra cero como para decir que no tiene ningun valor actualmente, ya que este se ira actualizando a lo largo del algoritmo 
    Next = 0
    #Ahora lo que tendremos que hacer es iterar toda la longitud del arreglo
    for i in range(len(arr)):
        #Una vez dentro del arreglo, antes de hacer el ciclo interno, debemos de indicar que ahora la variable Next valdra -1.
        #Esto es con el motivo, que con el ciclo interno se tendra el proposito de encontrar el siguiente mayor del elemento en el que estamos. Sin embargo, si no hay uno mayor, la variable next necesitara tener el valor de -1 como respuesta
        Next = -1
        #Ahora, podemos hacer el ciclo interno. Como bien se sabe , este se encargara de hallar el proximo elemento a la derecha de la posicion que indique el ciclo externo . Por ello, debemos de iniciar este ciclo, desde la posicion siguiente de la que indica el ciclo externo 
        for j in range((i+1), len(arr)):
            #Dentro del ciclo interno , lo que debemos de hacer es que si el elemento que indica la posicion del ciclo externo es menor al elemento que indica la posicion del ciclo interno, quiere decir que ese sera el elemento proximo mayor, y este debera de ser almacenado en la variable Next que creamos
            #Ademas , alli ya podemos parar el ciclo interno ya que de nada sirve seguir iterando sobre el resto del arreglo
            if arr[i] < arr[j]:
                Next = arr[j]
                break
        #Ahora bien, ya que estamos afuera del ciclo  interno , ya tenemos guardado en la variable Next el valor del proximo mayor elemento de la posicion que estamos. Por ello , podemos pasar a imprimir en que elemento estamos y cual es su siguiente
        print(f"Elemento actual : {arr[i]} . Su proximo elemento mayor es : {Next}")

#Ahora veremos un algoritmo optimizado del problema anterior utilizando pilas monotonas
#Complejidad Temporal: O(n)
def NGEStack(arr):
    #Lo primero que debemos de hacer es crear la pila que utilizaremos para el algoritmo 
    stack = Stack()
    #Ahora lo que haremos sera insertar en la pila el primer elemento del vector
    stack.push(arr[0])
    #Ahora deberemos de iterar sobre el arreglo, En este caso partiendo desde el indice 1 ya que el dato del elemento cerp ya esta insertado en la pila
    for i in range(1, len(arr)):
        #Ahora, debemos de verificar que si la pila esta vacia deberemos de insertar el dato en la posicion que nos encontremos actualmente, y continuar en la siguiente iteracion
        #Es importante validar estos primero ya que en proximos pasos del algoritmo se podran realizar varias veces pops de la pila, por lo que no sabremos si en algun momento esta quedara vacia. De ahi, el motivo de que insertemos el dato en la posicion en que nos encontremos si esto ocurre
        if stack.size == 0 :
            stack.push(arr[i])
            continue
        #Luego de lo anterior, significa que la pila no se encuentra vacia, por lo que debemos de comparar el dato en la posicion en la que estamos del vector, con el dato que esta en el Top de la pila. 
        #Si el dato en la cima de la pila es menor al dato en la posicion en la que nos encontramos, significara que el siguiente proximo del dato que esta en la cima de la pila, sera el dato en el que nos encontremos.
        #Por ello, debemos imprimir que el siguiente de la cima de la pila, es el dato en el que nos encontramos y luego hacer un pop de la pila para que los otros datos que se encuentran en ella , pueden seguir comparandose con el dato de la posicion en la que nos encontramos
        while stack.size > 0 and stack.peek() < arr[i]:
            print(f"El siguiente proximo mayor de {stack.peek()} es {arr[i]}")
            stack.pop()
        #Al salir del ciclo anterior, significa que el dato en la cima de la pila es mayor al dato en el que nos encontramos o que la pila esta vacia
        #Por ello, debemos de insertar en la pila ahora el dato en el que nos encontramos
        stack.push(arr[i])
        #Con esto, podemos continuar con las iteraciones del ciclo principal
    #Ahora, afuera del ciclo principal, podran quedar varios datos aun en la pila. Estos datos significan que no tiene proximo mayor , por lo tanto la respuesta de estos sera -1. 
    #Por ellos, debemos de iterar en la pila imprimiendo que el siguiente proximo mayor de la cima de la pila sera -1 , e ir haciendo pops en la pila hasta que esta quede vacia
    while stack.size > 0 :
        print(f"El siguiente proximo mayor de {stack.peek()} es {-1}")
        stack.pop()

#''''''''''''''''''''''''''''''''''''''''''''''''''''''''''