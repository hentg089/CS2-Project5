//Mark Hentges 5814125
//

#include "Track.h"
#include "Disk.h"

Track::Track(std::shared_ptr<Disk> associatedDisc) {
    //makes it point to a disk
    discPtr = associatedDisc;
}

Track::~Track(){
    std::cout << "track destructor called - track name: "<< name << std::endl;
}

void Track::printTrack() const {
    //prints out track information
    std::cout << "Track number: " << number << "\nTrack name: " << name << "\nTrack Artist: " << artist <<
    "\nTrack play time: " << playTime/60 << ":" << playTime%60 << "\nTrack location: " << location << std::endl;
}

int Track::getNumber() const {
    //prints
    return number;
}

int Track::getPlayTime() const {
    //printss out play time
    return playTime;
}

std::shared_ptr<Track> Track::getTrackFromUser(std::shared_ptr<Disk> associatedDisk) {
    //generates a track form user
    try{
        std::shared_ptr<Track> newTrack = std::move(std::make_shared<Track>(Track(associatedDisk)));


        //all of our inputting proceeds this
        std::string newName;
        std::cout << "Enter the name of the track: " << std::endl;
        std::getline(std::cin, newName);

        std::string newArtist = "multi artist";
        if(!associatedDisk->isMultiArtist()){
            std::cout << "Enter the artist name: " << std::endl;
            std::getline(std::cin, newArtist);
        }

        std::string strPlayTime;
        std::cout << "Enter the play time of the track(\"min:sec\"): " << std::endl;
        getline(std::cin, strPlayTime);

        std::string newNum;
        std::cout << "Enter the track's associated number: " << std::endl;
        getline(std::cin, newNum);

        int intPlaytime = 0;
        for(int i = 0;i < strPlayTime.length(); ++i){
            if(strPlayTime[i] == ':'){
                intPlaytime += std::stoi(strPlayTime.substr(0, i)) * 60;
                intPlaytime += std::stoi(strPlayTime.substr(i+1));
                break;
            }
        }

        std::string filePath;
        std::cout << "Enter the path name: " << std::endl;
        std::getline(std::cin, filePath);

        newTrack->name = newName;
        newTrack->artist = newArtist;
        newTrack->playTime = intPlaytime;
        newTrack->location = filePath;
        newTrack->number = std::stoi(newNum);

        return newTrack;
    }catch(std::bad_alloc& e){
        std::cerr << "ERROR: memory allocation failed" << std::endl;
        return nullptr;
    }catch(std::exception& e){
        std::cerr << "Some extraneous error has happened" << std::endl;
        return nullptr;
    }


}