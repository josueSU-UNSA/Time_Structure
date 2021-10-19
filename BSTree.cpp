#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
class Nodo{
    private:

        Nodo<T>*m_pSig;
        T value;

    public:

        Nodo(T value){
            this->value=value;
            this->m_pSig=0;
        }

        Nodo<T>* getM_pSig(){
            return this->m_pSig;
        }

        void setM_pSig(Nodo<T>*m_pSig){
            this->m_pSig=m_pSig;
        }

        T getValue(){
            return this->value;
        }

        void setValue(T value){
            this->value=value;
        }
};
template <typename T>
class SimpleLinkedList{

    private:

        Nodo<T>*m_pHead;
        int longitud;

    public:
        SimpleLinkedList(){
            this->m_pHead=0;
            this->longitud=0;
        }
        int getLongitud(){
            return this->longitud;
        }
        void pushBackIterative(T value){
            if(!this->m_pHead){
                this->m_pHead=new Nodo<T>(value);
                this->longitud++;
                return;
            }
            Nodo<T>*pAux=this->m_pHead;
            
            while(pAux->getM_pSig()){
                pAux=pAux->getM_pSig();
            }

            pAux->setM_pSig(new Nodo<T>(value));
            this->longitud++;
        }

        void pushBackRecursive(T value,Nodo<T>*pAux){
            if(!this->m_pHead){
                this->m_pHead=new Nodo<T>(value);
                this->longitud++;
                return;
            }
            if(!pAux->getM_pSig()){
                pAux->setM_pSig(new Nodo<T>(value));
                this->longitud++;
                return;
            }
            else pushBackRecursive(value,pAux->getM_pSig());
        } 

        void pushBackRecursive(T value){
            pushBackRecursive(value,this->m_pHead);
        }

        void pushFront(T value){
            Nodo<T>*pAux=new Nodo<T>(value);
            pAux->setM_pSig(this->m_pHead);
            this->m_pHead=pAux;
            this->longitud++;
        }

        void printIterative(){
            Nodo<T>*pAux=this->m_pHead;
            while(pAux){
                cout<<pAux->getValue()<<" -> ";
                pAux=pAux->getM_pSig();
            }
            cout<<endl;
        }

        void printRecursive(Nodo<T>*pAux){
            if(!pAux) return;
            else{
                cout<<pAux->getValue()<<" -> ";
                printRecursive(pAux->getM_pSig());
            }

        }

        void printRecursive(){
            printRecursive(this->m_pHead);
            cout<<endl;
        }

        void popBackIterative(){

            if(!this->m_pHead)return;
            if(!this->m_pHead->getM_pSig()){
                delete this->m_pHead;
                this->m_pHead=0;
            }
            Nodo<T>*pAux=this->m_pHead;
            while(pAux->getM_pSig()->getM_pSig()){
                pAux=pAux->getM_pSig();
            }
            delete pAux->getM_pSig();
            pAux->setM_pSig(0);
            this->longitud--;

        }
        void popBackRecursive(Nodo<T>*pAux){
            if(!this->m_pHead) return;
            if(!this->m_pHead->getM_pSig()){
                delete this->m_pHead;
                this->m_pHead=0;
            }
            if(!pAux->getM_pSig()->getM_pSig()){
                delete pAux->getM_pSig();
                pAux->setM_pSig(0);
                this->longitud--;
            }
            else popBackRecursive(pAux->getM_pSig());

        }
        void popBackRecursive(){
            popBackRecursive(this->m_pHead);

        }
        void popFront(){
            if(!this->m_pHead)return;
            else{
                Nodo<T>*pAux=this->m_pHead->getM_pSig();
                delete this->m_pHead;
                this->m_pHead=pAux;
                this->longitud--;
            }
        }

        bool findIterative(T value){

            Nodo<T>*pAux=this->m_pHead;
            while(pAux){

                if(pAux->getValue()==value) return true;
                pAux=pAux->getM_pSig();

            }
            return false;

        }

        bool findRecursive(T value,Nodo<T>*pAux){

            if(!pAux) return false;
            if(pAux->getValue()==value) return true;
            else return findRecursive(value,pAux->getM_pSig());

        }
        bool findRecursive(T value){
            return findRecursive(value,this->m_pHead);
        }

        void printReverseRecursive(Nodo<T>*pAux){
            if(!pAux)return;
            else{
                printReverseRecursive(pAux->getM_pSig());
                cout<<pAux->getValue()<<" -> ";
            }
        }

        void printReverseRecursive(){
            printReverseRecursive(this->m_pHead);
            cout<<endl;
        }

        void reverse(){
            Nodo<T>*pAux=this->m_pHead;
            Nodo<T>*pAuxSig;
            //int count=0;
            while(pAux){    
                pushFront(pAux->getValue());
                this->longitud--;
                pAuxSig=pAux->getM_pSig();
                delete pAux;
                if(pAux==this->m_pHead->getM_pSig())this->m_pHead->setM_pSig(0);
                pAux=pAuxSig;
            }
        }
        void reverseRecursive(Nodo<T>*pAux){
            if(!pAux)return;
            else{
                Nodo<T>*pAuxSig;
                pushFront(pAux->getValue());
                this->longitud--;
                pAuxSig=pAux->getM_pSig();
                delete pAux;
                if(pAux==this->m_pHead->getM_pSig())this->m_pHead->setM_pSig(0);
                reverseRecursive(pAuxSig);
            }
        }
        void reverseRecursive(){
            reverseRecursive(this->m_pHead);
        }
        Nodo<T>*begin(){
            return this->m_pHead;
        }
        Nodo<T>*end(){
            Nodo<T>*pAux=this->m_pHead;
            if(!this->m_pHead)return 0;
            else{
                while (pAux->getM_pSig())
                {
                    pAux=pAux->getM_pSig();
                }
                return pAux;
            }
            
        }
        bool isEmpty(){
            return(!this->m_pHead);
        }
        void addPos(int pos,T value){
            int count=0;
            Nodo<T>*pAuxR=this->m_pHead;
            Nodo<T>*pAuxL;
            if(pos==0 ||!this->m_pHead)pushFront(value);
            else{
                while (count<pos)
                {
                    pAuxL=pAuxR;
                    pAuxR=pAuxR->getM_pSig();
                    count++;
                }
                pAuxL->setM_pSig(new Nodo<T>(value));
                pAuxL->getM_pSig()->setM_pSig(pAuxR);
                this->longitud++;
            }
        }
        /*
        void united(SimpleLinkedList <T>temp){
            

        }
        */
        ~SimpleLinkedList(){
            Nodo<T>*pAuxL;
            Nodo<T>*pAuxR=this->m_pHead;
            while(pAuxR){
                pAuxL=pAuxR;
                pAuxR=pAuxR->getM_pSig();
                delete pAuxL;
            }
            this->longitud=0;
            this->m_pHead=0;
        }
        /*
        void sort(){
            Nodo<T>*pAuxl,*pAuxR;
            while(pAuxR){
                while(){

                }
            }
        }*/
};
void readDatatype(std::string&A)
{
    std::ifstream myfile("words.txt");
    if (myfile.is_open())
    {
        std::string line;
        if (getline(myfile, line))A=line;
    }
    else std::cout << "Unable to open file"; 
}

template <typename T>
class Node
{
private:
    T data;
    Node *LNode;  
    Node *RNode;  
public:
    Node();
    Node(T new_data);
    ~Node();
    T getData();

    template <class U> friend class BST;
    template <class U> friend std::ostream& operator<<(std::ostream& os,  Node<T>& dt);

};

template <class T>
Node<T>:: Node(){
    LNode = NULL;
    RNode = NULL;
}

template <class T>
Node<T>:: Node(T new_data){
    data = new_data;
    LNode = NULL;
    RNode = NULL;
}

template <class T>
Node<T>:: ~Node(){
    delete LNode;
    delete RNode;
}

template <class T>
T Node<T>::getData(){
    return data;
}
template <class T> 
std::ostream& operator<<(std::ostream& os, Node<T>& dt){
    os << dt.getData();
    return os;
}

template <typename T>
class BST
{
private:
    Node<T> * Root;
public:
    BST();
    BST(T data);
    Node<T>* buscar(T data);
    bool insertar(T data);
    Node<T>* minNode(Node<T>* node);
    Node<T>* maxNode(Node<T>* node);
    Node<T>* eliminar(Node<T>* node , T data);
    bool eliminar(T data);
    void inOrder(Node<T>*node,std::vector<T>&);
    void preOrder(Node<T>*node,std::vector<T>&);
    void postOrder(Node<T>*node,std::vector<T>&);
    void listar(int);
};

template <class T>
BST<T>:: BST(){
    Root=NULL;
}

template <class T>
BST<T>:: BST(T data){
    Root = new Node<T>(data);
}

template <class T>
Node<T>* BST<T>::buscar(T data){
     Node<T>*tmp = Root;
     while(tmp!=NULL){
        if(tmp->data>data)
            tmp=tmp->LNode;
        else if (tmp->data<data)
            tmp=tmp->RNode;
        else
            return tmp;
     }
     return NULL;
}

template <class T>
bool BST<T>:: insertar(T data){
    if (Root==NULL){
        Root=new Node<T>(data);
    }
    else{
        Node<T>*temp=Root;
        Node<T>*temp2=temp;
        while(temp){
            temp2=temp;
            if(temp->getData()>data)
                temp=temp->LNode;
            else if(temp->getData()<data)
                temp=temp->RNode;
            else if(temp->getData()==data){
                return false; 
            }
        }
        if(temp2->getData()<data)
            temp2->RNode=new Node<T>(data);
        else if(temp2->getData()>data)
            temp2->LNode = new Node<T>(data);
    }
    return true;
}

/*Halla el menor hijo nodo de un nodo*/
template <class T>
Node<T>* BST<T>:: minNode(Node<T>* node){
    if(node->LNode==NULL)
        return node;
    return minNode(node->LNode);
}

/*Halla el mayor hijo nodo de un nodo*/
template <class T>
Node<T>* BST<T>:: maxNode(Node<T>* node){
    if(node->RNode==NULL)
        return node;
    return maxNode(node->RNode);
}

template <class T>
bool BST<T>:: eliminar(T data){
    if(buscar(data)==NULL)
        return false;
    else{
        Root=eliminar(Root,data);
        return true; 
    }
}

template <class T>
Node<T>* BST<T>:: eliminar(Node<T>* node , T data){
    if(node->data < data)
        node->RNode = eliminar(node->RNode, data);
    else if(node->data > data)
        node->LNode = eliminar(node->LNode, data);
    else //cuando encuentra el nodo
    {
        //caso 1:Nodo hoja
        if(node->RNode==NULL && node->LNode==NULL)
            return NULL;
        else{
            //caso 2:Nodo con un hijo
            if(node->RNode==NULL){
                node=node->LNode; 
            }
            else if(node->LNode==NULL){
                node=node->RNode; 
            }
            //caso 3:Nodo con dos hijos
            else{
                int op;
                std::cout<<"Eliminar por\n0 -> Predecesor\n1-> Sucesor?\n : ";
                std::cin>>op;
                if(op==0){
                    Node<T>*predecesor =  maxNode(node->LNode);
                    node->data = predecesor->data;
                    node->LNode=eliminar(node->LNode,predecesor->data);
                }
                else{
                    Node<T>*sucesor =  minNode(node->RNode);
                    node->data = sucesor->data;
                    node->RNode=eliminar(node->RNode,sucesor->data);
                }
            }  
        }
    }
    return node;
}

template <class T>
void BST<T>:: inOrder(Node<T>*node,std::vector<T>&vector){
    if (node != NULL) { 
        inOrder(node->LNode,vector); 
        vector.push_back(node->data);  
        inOrder(node->RNode,vector); 
    }  
}

template <class T>
void BST<T>:: preOrder(Node<T>*node,std::vector<T>&vector){
    if (node != NULL) { 
        vector.push_back(node->data);      
        preOrder(node->LNode,vector); 
        preOrder(node->RNode,vector); 
    }  
}

template <class T>
void BST<T>:: postOrder(Node<T>*node,std::vector<T>&vector){
    if (node != NULL) { 
        postOrder(node->LNode,vector);
        postOrder(node->RNode,vector); 
        vector.push_back(node->data);     
    }  
}

/*
op = 1 -> Listar Preorden
op = 2 -> Listar inOrden
op = 3 -> Listar PostOrden
Con cualquier otra opcion se imprimirá Preorden
*/
template <class T>
void BST<T>::listar(int op){
    std::vector<T> vectorDeNodos; 
    if(op==3)
        postOrder(Root,vectorDeNodos);
    else if(op==2)
        inOrder(Root,vectorDeNodos);
    else
        preOrder(Root,vectorDeNodos);
    for (auto i = vectorDeNodos.begin(); i != vectorDeNodos.end(); ++i) 
        std::cout << *i << " ";
}

template <class T>
void sistema()
{
    int op=-1;
    T op2;
    BST<T> myTree; 

    std::ifstream myfile("words.txt"); //ingreso de los datos del .txt al BST
    if (myfile.is_open())
    {
        T line;
        std::string temp; 
        getline(myfile, temp); //salto de la primera linea
        while(myfile>>line){
            myTree.insertar(line);
        }
    }
    else std::cout << "Unable to open file"; 

    while(op!=0){
        if(op==1){

            std::cout<<"\n1 Listar PreOrden\n2 Listar InOrden\n3 Listar PostOrden\nOpcion: ";
            std::cin>>op;
            myTree.listar(op);
            std::cout<<"\n=================================\n";
        }
        else if(op==2){
            std::cout<<"\nElemento a ingresar: ";
            std::cin>>op2;
            if(myTree.insertar(op2))
                std::cout<<"\nInsertado\n";
            else
                std::cout<<"\nEl elemento ya se encuentra en el arbol\n";
            std::cout<<"\n=================================\n";
        }
        else if(op==3)
        {
            std::cout<<"\nElemento que desea buscar: ";
            std::cin>>op2;
            Node<T> *temp = myTree.buscar(op2);
            if(temp==NULL)
                 std::cout<<"\nNo se encontro coincidencia\n"; 
            else
                std::cout<<*temp;
        
            std::cout<<"\n=================================\n";
        }
        else if(op==4)
        {
            std::cout<<"\nElemento que desea eliminar: ";
            std::cin>>op2;
            if(myTree.eliminar(op2))
                std::cout<<"\nEliminado\n";
            else
                std::cout<<"\nNo encontrado\n";
            std::cout<<"\n=================================\n";
        }
        std::cout<<"Acciones Disponibles:\n1 Listar \n2 Insertar\n3 Buscar \n4 Eliminar \n0 Salir\nElija opcion (1,2,3,4,0):";
        std::cin>>op;
    }
}

int main()
{
    std::string datatype;
    readDatatype(datatype);
    if(datatype=="int"){
        sistema<int>();
    }
    else if(datatype=="char"){
        sistema<char>();
    }
    else if(datatype=="string"){
        sistema<std::string>();
    }

    
}