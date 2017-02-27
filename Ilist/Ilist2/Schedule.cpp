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