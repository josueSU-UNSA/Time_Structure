#include <iostream>
using namespace std;
template<typename T>
class Node{
    public:
        T value;
        Node<T>*m_pSon[2];
    public:
        Node(T value){
            this->value=value;
            this->m_pSon[0]=0;
            this->m_pSon[1]=0;
        }
};