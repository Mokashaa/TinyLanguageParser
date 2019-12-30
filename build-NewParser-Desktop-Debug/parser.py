import sys

import pygraphviz as pgv
from PIL import Image

graph = pgv.AGraph()
counter = 0
node_id = 0
index=0
nonTerminals = ['READ','WRITE','IF','REPEAT']


def drow():
    global graph
    graph.draw('output.png',prog='dot')   

def connectHorizontal( firstNode, secondNode, color='black'):
    global graph
    graph.subgraph(nbunch=[firstNode,secondNode],rank= 'same')
    graph.add_edge(firstNode,secondNode, color=color)
    
def tree( label=''):
    global graph
    global node_id
    global nonTerminals 
    global counter
    global TypeList
    global ValueList
    if not label:
        label = ValueList[counter]
    if label.__contains__('READ') or label.__contains__('ASSIGN') or  TypeList[counter] in nonTerminals:
        graph.add_node(node_id, label=label, shape='rectangle')
    else:
        graph.add_node(node_id, label=label)
    temp = graph.get_node(node_id)
    node_id += 1
    return temp

def edge( parent, left, right=None):
    graph.add_edge(parent, left)
    if not right is None:
        graph.add_edge(parent, right)


def updateCounter():
    global counter
    global TypeList
    global ValueList
    if(len(ValueList)==1):
        result.write("Error! Expected statement")
        result.close()
        sys.exit(0)
    if counter < len(ValueList)-1 :
        counter= counter + 1
   
        
def match(expectedToken):
    global TypeList
    global ValueList
    if expectedToken == ValueList[counter] or expectedToken == TypeList[counter] :
        updateCounter()
    else:
        string1="Matching Error!Expected "+expectedToken +' , At line '+str(counter+1)+" to replace "+ValueList[counter]
        result.write(string1)
        result.close()
        sys.exit(0)

def stmt_seq () :
    global TypeList
    global ValueList
    temp = statment()
    nativeChild = temp
    while (ValueList[counter] == ";") :
        match(";")
        leftChild = temp
        rightChild = statment()
        connectHorizontal(leftChild, rightChild)
        temp = rightChild
    if TypeList[counter] != "UNTIL" and TypeList[counter] != "ELSE" and counter < len(TypeList)-1 and TypeList[counter] != "END" :
        string2="Error! Expected ; before "+TypeList[counter]
        result.write(string2)
        result.close()
        sys.exit(0)

    return nativeChild


def statment ():
    if (TypeList[counter] == "IF"):
        return if_stmt()
    elif(TypeList[counter] == "REPEAT"):
        return repeat_stmt()
    elif(TypeList[counter] == "IDENTIFIER"):
        return assign_stmt()
    elif(TypeList[counter] == "READ"):
        return read_stmt()
    elif(TypeList[counter] == "WRITE"):
        return write_stmt()
    else:
        result.write("Error! Expected statement")
        result.close()
        sys.exit(0)

def if_stmt():
    global TypeList
    global ValueList
    parent = tree()
    match("IF")
    leftChild = exp()
    match("THEN")
    middleChild = stmt_seq()
    if(TypeList[counter]=="ELSE"):
        match("ELSE")
        rightChild = stmt_seq()
        edge(parent, leftChild)
        edge(parent, middleChild, rightChild)
        connectHorizontal(leftChild, middleChild, color='white')
        connectHorizontal(middleChild, rightChild, color='white')

    elif TypeList[counter] == "END":
        edge(parent, leftChild, middleChild)
        connectHorizontal(leftChild, middleChild, color='white')

    match("END")
    return parent


def repeat_stmt():
    parent = tree()
    match("REPEAT")
    leftChild = stmt_seq()
    match("UNTIL")
    rightChild = exp()
    edge(parent, leftChild, rightChild)
    return parent

def assign_stmt():
    label = 'ASSIGN \n'+ ValueList[counter]
    parent = tree(label)
    match("IDENTIFIER")
    match(":=")
    child = exp()
    edge(parent, child)
    return parent

def read_stmt():
    global TypeList
    global ValueList
    match("READ")
    label = 'READ \n'+ ValueList[counter]
    parent = tree(label)
    match("IDENTIFIER")
    return parent

def write_stmt ():
    parent = tree()
    match("WRITE")
    child = exp()
    edge(parent, child)
    return parent


def is_addop():
    global TypeList
    global ValueList
    if ValueList[counter]=='+' or ValueList[counter]=='-' :
        return 1 
    return 0

def simple_exp():
    temp = term()
    while(is_addop()):
        parent = tree()
        addop() 
        leftChild = temp
        rightChild = term()
        edge(parent, leftChild, rightChild)
        temp = parent
    return temp

def factor():
    global TypeList
    global ValueList
    if ValueList[counter] == "(":
        match("(")
        temp = exp()
        match(")")
        return temp
    elif TypeList[counter] == "NUMBER":
        parent = tree()
        match("NUMBER")
        return parent
    elif TypeList[counter] == "IDENTIFIER":
        parent = tree()
        match("IDENTIFIER")
        return parent
    else :
        result.write("Error! Expected  (exp) or NUMBER or IDENTIFIER ")
        result.close()
        sys.exit(0)

	
 
def addop():
    global TypeList
    global ValueList
    error = 0 
    if ValueList[counter] == "+":
        match("+")
    elif ValueList[counter] == "-":
        match("-")
    else :
        result.write("Error! Expected  + or - ")
        result.close()
        sys.exit(0)
    return error

def compop():
    global TypeList
    global ValueList
    error = 0 
    if ValueList[counter] == "<":
        match("<")
    elif ValueList[counter] == "=":
        match("=")
    else :
        result.write("Error! Expected  < or = ")
        result.close()
        sys.exit(0)
    return error

def is_compop():
    global TypeList
    global ValueList
    if ValueList[counter] == "<" or ValueList[counter] == "=":
        return 1
    return 0

def exp():
    temp = simple_exp()
    if(is_compop()):
        parent = tree()
        compop()
        leftChild = temp
        rightChild = simple_exp()
        edge(parent, leftChild, rightChild)
        temp = parent
    return temp
		
		
def term():
    global TypeList
    global ValueList
    temp=factor()
    while ValueList[counter] == "*" or ValueList[counter] == "/" :
        parent=tree()
        match(ValueList[counter])
        leftChild = temp
        rightChild =factor()
        edge(parent, leftChild, rightChild)
        temp = parent
    return temp



#f = open("demofile.txt","r")
path = sys.argv[1]
f = open(path,"r")
TokensList = list(f)
TypeList = list()
ValueList = list()
for i in TokensList:
    tokenvalue,tokentype = i.split(",")
    tokenvalue="".join(tokenvalue.split())
    tokentype = "".join(tokentype.split())
    ValueList.append(str(tokenvalue))
    TypeList.append(str(tokentype))


result = open ("result.txt", "w+")
root = stmt_seq()
drow()
img = Image.open('output.png')
img.show()
# print("Finished Successfully!")
result.write("Finished Successfully!")
result.close()

