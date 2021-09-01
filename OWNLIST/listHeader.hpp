#ifndef __LIST_HEADER_
#define __LIST_HEADER_



// including spesific library //

#if LIST_USAGE == 1

#include <iostream>
#include <string>

// end including spesific library //


// decleration // 
// end decleration // 

// template //

template<class T>
class ownList{
private:
    class Node{
        T data;
        Node *pNext;

        friend class ownList;
    };

    Node *ObtainNode(T data){
        Node *pNewNode = new Node;
        pNewNode->data = data;
        pNewNode->pNext = nullptr;

        return pNewNode;
    }

    Node GetBasisNode(){
        return m_BasisNode;
    }

    static Node *m_BasisNode;

public:
    class Iterator{
    private:
        const Node *pCurrentNode;
    public:
        Iterator() noexcept : pCurrentNode(m_BasisNode){
        }

        Iterator(const Node *pNode) noexcept : pCurrentNode(pNode){
        }

        Iterator &operator=(Node *pNode){
            this->pCurrentNode = pNode;
            return *this;
        }

        Iterator &operator++(){
            if(pCurrentNode){
                pCurrentNode = pCurrentNode->pNext;
            }
            return *this;
        }

        Iterator operator++(int){
            Iterator iter = *this;
            ++*this;
            return iter;
        }

        bool operator!=(const Iterator &iterator){
            return pCurrentNode != iterator.pCurrentNode;
        }

        T operator*(){
            return pCurrentNode->data;
        }

        T *operator->(){
            return pCurrentNode;
        }
    };

    ownList<T>() noexcept {
        m_BasisNode = nullptr;
    }

    // list have these funcs //
    Iterator begin(){
        return Iterator(m_BasisNode);
    }

    Iterator end(){
        return Iterator(nullptr);
    }

    void push_back(T data){
        Node *pTemp = ObtainNode(data);
        if(!GetBasisNode()){
            GetBasisNode() = pTemp;
        }else{
            Node *pAdditionElement = GetBasisNode();
            while(pAdditionElement->pNext){
                pAdditionElement = pAdditionElement->pNext;
            }
            pAdditionElement->pNext = pTemp;
        }
    }

    void Traverse(){

    }
    // end list have these funcs //

};

template<typename T>
typename ownList<T>::Node *ownList<T>::m_BasisNode = nullptr;
// end template //

#else
#error C++ does not have this kind of template class
#endif

#endif