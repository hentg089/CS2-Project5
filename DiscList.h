//Mark Hentges 5814125
//

#ifndef PROJ5_NEWHOPE_DISCLIST_H
#define PROJ5_NEWHOPE_DISCLIST_H

#include <memory>
#include "Disk.h"

class DiscList {
private:

    /**finds position in list of a disc
     * @pre disc is in list
     * @post none
     * @return the position of the disc
     */
    int findDiscPosition(std::shared_ptr<Disk> discPtr) const;
protected:
    std::unique_ptr<LinkedList<std::shared_ptr<Disk>>> discListPtr;
public:
    /**default constructor
     * @pre none
     * @post none
     * @return none
     */
    DiscList();

    /** destructor that outputs its being destructor
     * @pre none
     * @post none
     * @return none
     */
    ~DiscList();

    /** tells if the list is empty
     *@pre none
     * @post none
     * @return if the list is empty or not
     */
    bool isEmpty();

    /**tells the size og the list
     * @pre none
     * @post none
     * @return none
     */
    int getNumberOfDisks();

    /**inserts into the list
     * @pre none
     * @post the list gets bigger
     * @return whether was successful or not
     */
    bool insertDisc(std::shared_ptr<Disk> discPtr);

    /**remove disk from list
     * @pre disk needs to be in list
     * @post list gets smaller
     * @return whether successful or not
     */
    bool removeDisc(std::shared_ptr<Disk> diskPtr);

    /**returns a disc from the link
     * @pre disc is in the list
     * @post none
     * @return retrieved disc
     */
    std::shared_ptr<Disk> retrieveDisc(int number);
};


#endif //PROJ5_NEWHOPE_DISCLIST_H
