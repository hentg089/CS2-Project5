//Mark Hentges 5814125
//

#ifndef PROJ5_NEWHOPE_DISK_H
#define PROJ5_NEWHOPE_DISK_H
class Track;
#include <string>
#include <memory>
#include <iostream>
#include "LinkedList.cpp"

class Disk {
private:
    std::string title = "undefined";
    std::string artist = "undefined";
    int year = 0000;
    std::string genre = "undefined";
    int totalPlayTime = 0;
    bool multiArtist = false;
protected:
    std::unique_ptr<LinkedList<std::shared_ptr<Track>>> trackListPtr;

public:
    /**default constructor for disk
     *
     *
     */
    Disk();

    /**destructor for disk
     *
     * when it runs it should indicate we're destructing
     */
    ~Disk();

    /** checks to see if the track list is empy
     * @pre none
     * @post none
     * @return bool indicating if track list is empy
     */
    bool isEmpty();

    /** gets the size of the track list
     * @pre none
     * @post none
     * @return the lenght of the list
     */
    int getNumberOfTracks() const;

    /** inserts into the list
     * @pre trackPtr must be unique
     * @post the list will grow
     * @return bool whether it works or not
     */
    bool insertTrack(std::shared_ptr<Track> trackPtr);

    /** gives you a track based on a number you enter
     * @pre has to have track at the number
     * @post none
     * @return a track associated with the number
     */
    std::shared_ptr<Track> retrieveTrackByNumber(int number);

    /** getter for the artist
     * @pre has to have singular artist
     * @post none
     * @return the artist name
     */
    std::string getArtist() const;

    /** getter for the disk title
     * @pre has to have a title
     * @post none
     * @return the title of disk
     */
    std::string getTitle() const;

    /** getter for multi artist status
     *  @pre none
     *  @post none
     *  @return a bool value indicating if multi artist or not
     */
    bool isMultiArtist() const;

    /** class method for generating a disc
     * @pre none
     * @post none
     * @return a newly created disk
     */
    static std::shared_ptr<Disk> getDiscFromUser();

    /** prints the disks info
     * @pre disk needs info
     * @post none
     * @return none
     */
    void printDisc() const;

    /**adds to total playtime
     * @pre none
     * @post none
     * @return none
     */
    void addToTotalPlayTime(int time);
};


#endif //PROJ5_NEWHOPE_DISK_H
