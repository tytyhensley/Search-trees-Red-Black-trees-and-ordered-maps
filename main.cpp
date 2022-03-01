//
//  main.cpp
//  Homework 3
//
//  Created by Ty-Ty Hensley on 5/10/18.
//  Copyright © 2018 Ty-Ty Hensley. All rights reserved.
//

#include <iostream>
#include <string>
#include <tuple>
#include "BinaryTrees.h"
#include "BinarySearchTrees.h"
#include "OrderedMap.h"

#define PART  3

using namespace std;
using flight = tuple<string, string, string, int>;//tuple definition for the key
using details = tuple<string, string, string, string, string>;//tuple definition foor the key

int main()
{
#if PART==1
    // LinkedBinaryTree of int type elems
    LinkedBinaryTree<int>  tr ;
    cout<<"Size tr1= "<<tr.getSize()<<endl ;
    tr.addRoot() ;
    tr.expandExternal(tr.root()) ;
    cout<<"Size tr1= "<<tr.getSize()<<endl ;
    
    // LinkedBinaryTree of Entry type elems
    LinkedBinaryTree<Entry<int, string>>  tr2 ;
    cout<<"\nSize tr2= "<<tr2.getSize()<<endl ;
    tr2.addRoot() ;
    tr2.expandExternal(tr2.root()) ;
    cout<<"Size tr2= "<<tr2.getSize()<<endl ;
    
    
#elif PART==2
    // Create a Search tree, fill it, then disply it
    SearchTree<Entry<int,int>> search ;
    cout<<"nSize= "<<search.getSize()<<endl ;
    
    search.insert(25,125) ;
    search.insert(35,135) ;
    search.insert(55,145) ;
    search.insert(55,155) ;
    cout<<"Size= "<<search.getSize()<<endl ;
    
    SearchTree<Entry<int,int>>::Iterator iter=search.begin() ;
    while( !(iter == search.end())) {
        cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
        ++iter;
    }
    
#elif PART==3
    // Create an OrderedMap, fill it, then disply it
    OrderedMap<flight, details> oMap ;//initializing the class orderedmap to accept the tuple defintions as tehe arbitrary values of the key and value
    cout<<"nSize= "<<oMap.getSize()<<endl ;
    oMap.put(make_tuple("ORD","PVD","05May",1739),make_tuple("AA 416", "F3","Y9","02:09","$365"));
    oMap.put(make_tuple("ORD","PVD","05May",953), make_tuple("AA 1850", "F5","Y15","02:05","$251'"));
    oMap.put(make_tuple("ORD","PVD","05May",1950),make_tuple("AA 1828", "F9","Y25","02:13","$186"));
    oMap.put(make_tuple("ORD","PVD","05May",1329),make_tuple("AA 600", "F2","Y0","02:16","$713"));
    oMap.put(make_tuple("ORD","PVD","05May",930), make_tuple("AA 1450", "F6","Y13","02:00","$411'"));
  
    
    cout<<"nSize= "<<oMap.getSize()<<endl ;
    
    SearchTree<Entry<flight,details>>::Iterator z=oMap.ceilingEntry(make_tuple("ORD","PVD","05May",930));
    //printing the individual components of the tuple after the fnction was performed 
    cout<<"("<<get<0>((*z).key())<<", "<<get<1>((*z).key())<<", "<<get<2>((*z).key())<<", "<<get<3>((*z).key())<<"), ("<<get<0>((*z).value())<<", "<<get<1>((*z).value())<<", "<<get<2>((*z).value())<<", "<<get<3>((*z).value())<<", "<<get<4>((*z).value())<<")"<<endl;
    
    SearchTree<Entry<flight, details>>::Iterator c=oMap.higherEntry((*z).key());
    cout<<"("<<get<0>((*c).key())<<", "<<get<1>((*c).key())<<", "<<get<2>((*c).key())<<", "<<get<3>((*c).key())<<"), ("<<get<0>((*c).value())<<", "<<get<1>((*c).value())<<", "<<get<2>((*c).value())<<", "<<get<3>((*c).value())<<", "<<get<4>((*c).value())<<")"<<endl;
    
    SearchTree<Entry<flight,details>>::Iterator a=oMap.higherEntry((*c).key());
    cout<<"("<<get<0>((*a).key())<<", "<<get<1>((*a).key())<<", "<<get<2>((*a).key())<<", "<<get<3>((*a).key())<<"), ("<<get<0>((*a).value())<<", "<<get<1>((*a).value())<<", "<<get<2>((*a).value())<<", "<<get<3>((*a).value())<<", "<<get<4>((*a).value())<<")"<<endl;
     
    SearchTree<Entry<flight,details>>::Iterator b=oMap.higherEntry((*a).key());
    cout<<"("<<get<0>((*b).key())<<", "<<get<1>((*b).key())<<", "<<get<2>((*b).key())<<", "<<get<3>((*b).key())<<"), ("<<get<0>((*b).value())<<", "<<get<1>((*b).value())<<", "<<get<2>((*b).value())<<", "<<get<3>((*b).value())<<", "<<get<4>((*b).value())<<")"<<endl;
    
    
#endif
    return 0;
}
