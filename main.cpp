//Mark Hentges 5814125
#include <iostream>

#include <memory>
#include "DiscList.h"

int main() {
    DiscList discList;
    int i = discList.getNumberOfDisks();



    char continue_ = 'Y';

    //while loop for the gui
    while(continue_ == 'Y' || continue_ == 'y'){
        char option;
        std::cout << "(A)dd a new disc" << std::endl;
        std::cout << "(R)emove a disc" << std::endl;
        std::cout << "(P)rint a disc" << std::endl;
        std::cout << "(L)ist discs" << std::endl;
        std::cout << "(Q)uit" << std::endl;
        std::cin >> option;

        switch(option){
            //add a new disk
            case 'A': case 'a':
                discList.insertDisc(Disk::getDiscFromUser());
                break;

            //remove a disk
            case 'R': case 'r':
                int diskNum;
                std::cout << "Enter the number of this disk you want to remove: " << std::endl;
                std::cin >> diskNum;
                discList.removeDisc(discList.retrieveDisc(diskNum));
                break;
            //print a disk
            case 'P': case 'p':
                int diskNum2;
                std::cout << "Enter the number of the disk you want to print: " << std::endl;
                std::cin >> diskNum2;
                discList.retrieveDisc(diskNum2)->printDisc();
                break;
            //list discs
            case 'L': case 'l':
                std::cout << "There are " << discList.getNumberOfDisks() << " discs:" << std::endl;
                for(int i = 1; i <= discList.getNumberOfDisks();++i){
                    std::cout << discList.retrieveDisc(i)->getTitle() << " by: " << discList.retrieveDisc(i)->getArtist() << std::endl;
                }
                std::cout << std::endl;
                break;
            //quit the program
            case 'Q': case 'q':
                continue_ = 'N';
                break;

        }
    }
}
