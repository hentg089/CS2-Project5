//Mark Hentges 5814125
//

#ifndef PROJ5_NEWHOPE_TRACK_H
#define PROJ5_NEWHOPE_TRACK_H

#include <string>
#include <iostream>
#include <memory>
#include "LinkedList.h"

class Disk;

class Track {
private:
    std::string name;
    std::string artist;
    int playTime;
    int number;
    std::string location;
protected:
    std::weak_ptr<Disk> discPtr;
public:
    /**default constructor for track - deleted
     * @pre none
     * @post none
     * @return none
     */
    Track() = delete;

    /** destructor for tracks - prints out track name when called
     * @pre none
     * @post none
     * @return none
     */
    ~Track();

    /** Constructor for track
     * @pre needs a correctly passed disc
     * @post the track will point to a disc
     * @return none
     */
    explicit Track(std::shared_ptr<Disk> associatedDisc);

    /**prints info about the track
     * @pre none
     * @post none
     * @return none
     */
    void printTrack() const;

    /**gets number associated with track
     * @pre none
     * @post none
     * @return number associated with track
     */
    int getNumber() const;

    /** gets length of track
     * @pre none
     * @post none
     * @return song lenght in seconds
     */
    int getPlayTime() const;

    /**class method for creating a track
     * @pre none
     * @post none
     * @return a newly created track
     */
    static std::shared_ptr<Track> getTrackFromUser(std::shared_ptr<Disk> associatedDisk);
};


#endif //PROJ5_NEWHOPE_TRACK_H
