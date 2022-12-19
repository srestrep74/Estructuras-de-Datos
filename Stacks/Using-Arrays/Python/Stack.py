#Crearemos la clase Stack la cual nos servira para definir los componentes que componen una pila , en este caso con arreglos. Veamos cuales son los elementos que la componen : 
"""
- int top : Indicara el en que posicion del arreglo esta el valor maximo de la pila, es decir, el ultimo elemento en entrar
- int a [] : Asi se llamara el arreglo que lo utilizaremos como pila
- Stack () : Sera el constructor el cual inicializara el valor de top como -1 ya que no hay elementos en el arreglo inicialmente
- push() : Funcion para insertar elementos en la pila
- pop(): Funcion para eliminar elemento en la pila
- isEmpty : Funcion para saber si la pila esta vacia o no 
- top() : Funcion para saber cual es el elemento en la cima de la pila

"""

class Stack:
    def __init__(self):
        self.A = []
    
    #Ahora crearemos la funcion push para insertar elementos en la pila
    def push(self, data):
        #Insertamos en el arreglo el nuevo dato que se quiere insertar en la pila
        #Como estamos trabajando en python, no nos tenemos que preocupar por el espacio que contiene el arreglo ya que este es dinamico
        self.A.append(data)
    
    #Ahora crearemos la funcion para retirar el primer ultimo elemento en entrar a la pila, es decir, la funcion pop
    def pop(self):
        #Si la pila no esta vacia
        if len(self.A) > 0:
            #Sacamos el ultimo elemento en entrar a la pila
            return self.A.pop()
        else: return -1
    
    #Ahora crearemos a funcion la cual retornara el ultimo elemento en la pila, es decir, el elemento que esta en la cima de la pila
    def peek(self):
        #Si la pila no esta vacia
        if len(self.A) > 0 :
            #Retornamos el ultimo elemento que esta en la pila
            return self.A[len(self.A)-1]
    
    #Funcion para saber si a pila esta vacia o no
    def isEmpty(self):
        return len(self.A) == 0

#---------------------------------