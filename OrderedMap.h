//
//  OrderedMap.h
//  Homework 3
//
//  Created by Ty-Ty Hensley on 5/10/18.
//  Copyright © 2018 Ty-Ty Hensley. All rights reserved.
//

#ifndef OrderedMap_h
#define OrderedMap_h

#include "BinarySearchTrees.h"
#include "BinaryTrees.h"

template <typename KK, typename VV>
class OrderedMap: public SearchTree<Entry<KK,VV>> {
public:
    // Usefull Typedef
    typedef  SearchTree<Entry<KK,VV>> BST;
    typedef typename SearchTree<Entry<KK,VV>>::Iterator BSTIterator;
    
public:
    OrderedMap(): SearchTree<Entry<KK,VV>>(){}
    int size () const ;
    bool empty () const ;
    BSTIterator find (KK k) {return BST::find(k);}
    BSTIterator put (KK k, VV v){return BST::insert(k,v) ;}
    BSTIterator& operator++() {return BST::operator++();}
    void erase (KK& k) ;
    void erase ( const BSTIterator & p);
    BSTIterator begin () {return BST::begin(); }
    BSTIterator end () {return BST::end();}
    BSTIterator firstEntry() {return BST::begin();}//returns an iterator to the entry with the lowest key
    BSTIterator lastEntry();
    BSTIterator ceilingEntry(KK k);
    BSTIterator floorEntry(KK k);
    BSTIterator higherEntry(KK k);
    BSTIterator lowerEntry(KK k) {return floorEntry(k);}//returns an iterator to the greatest key value smaller than k
} ;

template <typename KK, typename VV>
int OrderedMap<KK,VV>::size() const {return SearchTree<Entry<KK,VV>>::getSize() ;}

template <typename KK, typename VV>
bool OrderedMap<KK,VV>::empty() const {return SearchTree<Entry<KK,VV>>::isEmpty() ; }

//Last entry function, returns iterator to greatest key value
template <typename KK, typename VV>
typename OrderedMap<KK,VV>::BSTIterator OrderedMap<KK,VV>::lastEntry() {
    if(empty()==true){
        return end();
    }
    else{
        BSTIterator p = begin();
        BSTIterator w = begin();
        while( !((w=BST::increment((*w).key())) == end())){
            p=BST::increment((*p).key());
        }
        return p;
    }
}

//Ceiling function returns the lowest key greater than or equal to k
template <typename KK, typename VV>
typename OrderedMap<KK,VV>::BSTIterator OrderedMap<KK,VV>::ceilingEntry(KK k) {
    if(empty()==true){
        return end();
    }
    BSTIterator v=lastEntry();
    if ( k== (*v).key()){
        return end();
    }
    else{
        BSTIterator p = BST::increment(k);
        return p;
    }
}

//Floor function, returns the largest key samller than or equal to k
template <typename KK, typename VV>
typename OrderedMap<KK,VV>::BSTIterator OrderedMap<KK,VV>::floorEntry(KK k) {
    if(empty()==true){
        return end();
    }
    BSTIterator v= begin();
    if ( k== (*v).key()){
        return end();
    }
    else{
        BSTIterator p=begin();
        BSTIterator w=begin();
        BSTIterator s=find(k);
        while (!((w=BST::increment((*w).key())) == s)){
            p=BST::increment((*p).key());
        }
        return p;
    }
}

//Higher function returns the lowest key greater than k
template <typename KK, typename VV>
typename OrderedMap<KK,VV>::BSTIterator OrderedMap<KK,VV>::higherEntry(KK k) {
    if(empty()==true){
        return end();
    }
    BSTIterator v=lastEntry();
    if ( k== (*v).key()){
        return end();
    }
    else{
        BSTIterator p = BST::increment(k);
        while((*p).key() == k) {
           p = BST::increment(k);
        }
        return p;
    }
}


/*SearchTree<Entry<flight, details>>::Iterator x=oMap.firstEntry() ;
 cout<<&(*x).key()<<", "<<&(*x).value()<<endl;
 
 SearchTree<Entry<flight,flight>>::Iterator y=oMap.lastEntry();
 cout<<&(*y).key()<<", "<<&(*y).value()<<endl;*/




#endif /* OrderedMap_h */
