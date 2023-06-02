//Mark Hentges 5814125
//

#include "DiscList.h"
#include <iostream>

DiscList::DiscList() {
    discListPtr = std::make_unique<LinkedList<std::shared_ptr<Disk>>>();
}

DiscList::~DiscList() {
    std::cout << "DiscList destructor has been called" << std::endl;
}

bool DiscList::isEmpty() {
    return discListPtr->isEmpty();
}

int DiscList::getNumberOfDisks() {
    return discListPtr->getLength();
}

bool DiscList::insertDisc(std::shared_ptr<Disk> discPtr) {
    //trys to insert a disk
    try{
        discListPtr->insert(1, discPtr);
        return true;
    }catch(std::exception& e){
        //what to do if we fail to insert a disk
        return false;
    }
}

bool DiscList::removeDisc(std::shared_ptr<Disk> diskPtr) {
    //trys to remove a disk
    try{
        for(int i = 1; i <= discListPtr->getLength(); ++i){
            if(discListPtr->getEntry(i)->getTitle() == diskPtr->getTitle()){
                discListPtr->remove(i);
                return true;
            }
        }
    }catch(std::exception& e){
        //returns false if we get an exception
        return false;
    }
    return false;
}

std::shared_ptr<Disk> DiscList::retrieveDisc(int number) {
    //trys ot retrieve a disk based off f a nubmer
    return discListPtr->getEntry(number);
}