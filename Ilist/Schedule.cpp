#include <utility>

#include "Schedule.h"

using namespace std::rel_ops;

/**
 *
 */
Schedule::Schedule()
    :head(nullptr), 
     tail(nullptr),
     totalCredits(0)
{
}

Schedule::Schedule(Schedule const& sch)
{
    Node* schIt = sch.head;

    // Important - every constructor must initialize
    // every private data member (attribute)
    this->head  = nullptr;
    this->tail  = nullptr;
    this->totalCredits = 0;

    while (schIt != nullptr) {
        this->add(schIt->data);

        schIt = schIt->next;
    }
}


Schedule::~Schedule()
{
    Node* del = head;
    while(del != NULL)
    {
        head = head->next;
        delete del;
        del = head;
    }  
    tail = NULL;
    head = NULL;
}


/**
 *
 */
bool Schedule::add(Course course)
{
    if (head==nullptr)
    {
        Node* hold = new Node(course);
        head = hold;
        tail = hold;
        totalCredits += course.getCredits();
        return true;
    }
    Node* itr = head;
    while( itr != nullptr) 
    {
        if(course.getNumber() == itr->data.getNumber())
        {
            return false;
        }
        itr = itr->next;
    }
    if(totalCredits + course.getCredits() <= 12)
    {
        Node* hold = new Node(course);
        tail->next=hold;
        tail = tail->next;
        totalCredits += course.getCredits();
        return true;
    }
    return false;
}

/*
*/
Schedule& Schedule::operator=(const Schedule& rhs)
{

    if (this != &rhs) {
        // Destructor for this
        Node *this_iterator = nullptr; // Loop control pointer
        Node *to_delete     = nullptr; // Node to delete        
        
        //start at the beginning of the this
        this_iterator = this->head;
        
        //iterate through the this and delete each node
        while( this_iterator != nullptr  ){
            to_delete = this_iterator;
            
            //move to next node
            this_iterator = this_iterator->next;
           
            //delete the current node        
            delete to_delete;
            
            to_delete = nullptr; //dangling pointers are bad

            // Such output would not be included in
            // a non-academic exercise
            std::cerr << "Deleting Node" << "\n";
        }
                
        // Are these three lines necessary?
        head  = nullptr;
        tail  = nullptr;
        totalCredits = 0;

        // Copy rhs into this
        Node* srcIt = rhs.head;

        while (srcIt != nullptr) {
            this->add(srcIt->data);

            srcIt = srcIt->next;
        }
    }

    return *this;
}


/**
 *
 */
void Schedule::display(std::ostream& outs) const
{
    Node* it = head;

    outs << "  (" << totalCredits << " Total Credits)" << "\n";

    while (it != nullptr) {
        // oops I forgot to remove most of this function    "$NAME (CRN $CRN)"
        outs << "  - " << it->data.getCredits() << " credits - " << it->data.getNumber() << " (CRN " << it->data.getCrn() << ")\n";
        it = it->next;
    }    
}



/**
 * You may ignore this function, or use it, the choice is yours
 */
void Schedule::deAllocateList()
{

}

/**
 * You may ignore this function, or use it, the choice is yours
 */
void Schedule::copyList(const Schedule& rhs)
{
    
}