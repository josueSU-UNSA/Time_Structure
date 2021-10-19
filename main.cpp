//Nombres 1: Josue Gabriel Sumare Uscca++
//Nombres 2:Freddy Leonel Humpiri Valdivia+
//Nombres 3:MIGUEL ANGEL DEZA CUELA
//Fecha:18/10/2021
#include"BinaryTree.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;
template<typename T>
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
int main() 
{

    string ubicacion_input ="ENTRADA.TXT";
    string palabra;
    SimpleLinkedList<string>test;
    BinaryTree<string>tree;
    ifstream input(ubicacion_input);
    
    while(!input.eof()) {
        input >> palabra;
        cout<<"Hello";
        //test.pushFront(palabra);//Insertando en lista Simplemente enlazaada
        tree.insert(palabra);//Insertando en arbol binario
    }
    input.close();
    cout<<"TEST"<<endl;
    
    //test.printIterative();
    tree.printInorden();
    cout<<"Finish"<<endl;
    
    getch();
}