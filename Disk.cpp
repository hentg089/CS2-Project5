//Mark Hentges 5814125
//

#include "Disk.h"
#include <iostream>
#include "Track.h"

Disk::~Disk(){
    trackListPtr = std::make_unique<LinkedList<std::shared_ptr<Track>>>();
    //destructs the disk
}

Disk::Disk() {
    trackListPtr = std::make_unique<LinkedList<std::shared_ptr<Track>>>();
}

bool Disk::isEmpty() {
    //tells whether the tracks list is empy or not
    return trackListPtr->isEmpty();
}

int Disk::getNumberOfTracks() const{
    //uses the linked list we have to get the number of tracks
    return trackListPtr->getLength();
}

bool Disk::insertTrack(std::shared_ptr<Track> trackPtr) {
    //inserst a track ptr into our list
    trackListPtr->insert(trackListPtr->getLength()+1, trackPtr);
    addToTotalPlayTime(trackPtr->getPlayTime());
    return true;
}

std::shared_ptr<Track> Disk::retrieveTrackByNumber(int number){
    //finds a track associated with our number and returns it
    for(int i = 1;i <= trackListPtr->getLength();++i){
        if(trackListPtr->getEntry(i)->getNumber() == number){
            return trackListPtr->getEntry(i);
        }
    }
    return nullptr;
}

std::string Disk::getArtist() const {
    //gets our artist with the private variables
    return artist;
}

std::string Disk::getTitle() const {
    //gets our disk title
    return title;
}

bool Disk::isMultiArtist() const {
    //gets whether is a multi artist or not
    return multiArtist;
}

std::shared_ptr<Disk> Disk::getDiscFromUser() {
    //gets disc from user
    try {
        std::cin.ignore(1000,'\n');
        std::shared_ptr<Disk> discPtrNew = std::make_shared<Disk>();

        std::string title;
        std::cout << "Enter the Disc's title: " << std::endl;
        getline(std::cin, title);

        std::string multi;
        std::cout << "Is the disc multi-artist?(Y/N): " << std::endl;
        getline(std::cin, multi);

        std::string newArtist = "multi aritst";
        if(!(multi == "Y" || multi == "y")){
            std::cout << "Enter the aritst: " << std::endl;
            getline(std::cin, newArtist);
        }

        std::string newYear;
        std::cout << "Enter the discs release year: " << std::endl;
        getline(std::cin, newYear);

        std::string genre;
        std::cout << "Enter the disc's genre: " << std::endl;
        std::getline(std::cin, genre);

        discPtrNew->title = title;
        if(multi == "Y" || multi == "y"){
            discPtrNew->multiArtist = true;
        }else{
            discPtrNew->multiArtist = false;
        }
        discPtrNew->artist = newArtist;
        discPtrNew->year = std::stoi(newYear);
        discPtrNew->genre = genre;

        std::cout << "Enter some tracks: " << std::endl;
        std::string enterTrack = "Y";
        do{
            discPtrNew->insertTrack(Track::getTrackFromUser(discPtrNew));
            std::cout << "want to enter another track?(Y/N): " << std::endl;
            getline(std::cin, enterTrack);
        }while(enterTrack == "Y" || enterTrack == "y");

        return discPtrNew;
    }catch(std::bad_alloc& e){
        std::cerr << "Error: memory allocation failed" << std::endl;
        return nullptr;
    }
    catch(std::exception& e){
        std::cerr << "Some extraneous error has happened" << std::endl;
        return nullptr;
    }
}

void Disk::printDisc() const {
    //prints out the disc info
    if(multiArtist){
        std::cout << "Disc's year is: " << year << "\nThe disc is multi artist: " << "\nDisc's release year is: " <<
                  year << "\nDisc's genre is: " << genre << "\nDisc has this many tracks: " << getNumberOfTracks() <<
                  "\nThe disc runs for this many seconds: " << totalPlayTime << std::endl;
        for(int i = 1; i <= trackListPtr->getLength();++i){
            trackListPtr->getEntry(i)->printTrack();
        }
    }else{
        std::cout << "Disc's year is: " << year << "\nDisc's artist is: " << artist << "\nDisc's release year is: " <<
                  year << "\nDisc's genre is: " << genre << "\nDisc has this many tracks: " << getNumberOfTracks() <<
                  "\nThe disc runs for this many seconds: " << totalPlayTime << std::endl;
        std::cout << "The disc has " << getNumberOfTracks() << " tracks" << std::endl;
        for(int i = 1; i <= trackListPtr->getLength();++i){
            trackListPtr->getEntry(i)->printTrack();
            std::cout << std::endl;
        }
    }
}

void Disk::addToTotalPlayTime(int time) {
    //adds to the disks total play time
    totalPlayTime += time;
}
