#include "Polyhedron.h"
#include "Composite.h"
#include "Sphere.h"
#include "Cylinder.h"
/**
 *
 */
Composite::Composite()
    :Polyhedron("Composite"),
     numPolyhedra(0),
     polyhedra(nullptr)
{
    boundingBox.setUpperRightVertex(0, 0, 0);

}



void Composite::read(std::istream& ins)
{
    using std::string;
    polyhedra = new Polyhedron*[10];
    int x = 0;
    ins >> x;
    for(int i = 0; i < x; i++)
    {
        double boundx = 0;
        double boundy = 0;
        double boundz = 0;
        double x = 0;
        double y = 0;
        string hold = "";
        ins >> hold;
        if(hold == "sphere")
        {
            ins >> x;
            polyhedra[i] = new Sphere(x);
            numPolyhedra++;
            if(boundx < x*2)
            {
                boundx = x*2;
            }
            if(boundy < x*2)
            {
                boundy = x*2;
            }
            if(boundz < x*2)
            {
                boundz = x*2;
            }
        }
        else if(hold == "cylinder")
        {
            ins >> x;
            ins >> y;
            polyhedra[i] = new Cylinder(y, x);
            numPolyhedra++;
        }
        else
        {
            std::cout << "Error, invalid shape: " << hold << "\n";
        }
        boundingBox.setUpperRightVertex(boundx, boundy, boundz);
    }
}


//------------------------HINT------------------------
/**
 *
 */
void Composite::scale(double scalingFactor)
{
    for (int i = 0; i < numPolyhedra; i++) {
        polyhedra[i]->scale(scalingFactor);
    }

    boundingBox.scale(scalingFactor);
}

void Composite::display(std::ostream& outs) const
{
    Polyhedron::display(outs);

    outs << numPolyhedra << " polyhedra\n";
    for(int i = 0; i < numPolyhedra; i++)
    {
        outs << "  ";
        polyhedra[i]->display(outs);
        outs << "\n";
    } 
}



//
/**
 *
 */
Composite& Composite::operator=(Composite rhs)
{
    swap(*this, rhs);

    return *this;
}

Composite::~Composite()
{
    for(int i = 0; i < numPolyhedra; i++)
    {
        delete polyhedra[i];
    }
    delete[] polyhedra;
}

Composite::Composite(const Composite& src)
    :Polyhedron("Composite"),
    numPolyhedra(src.numPolyhedra)
{
    polyhedra = new Polyhedron*[10];
    for(int i = 0; i < numPolyhedra; i++)
    {
        polyhedra[i] = src.polyhedra[i]->clone();
    }
    boundingBox = src.boundingBox;
}

/**
 *
 */
void swap(Composite& lhs, Composite& rhs)
{
    using std::swap;

    std::swap(lhs.numPolyhedra, rhs.numPolyhedra);
    std::swap(lhs.polyhedra, rhs.polyhedra);

    // Friend functions allow direct access
    // to all data members.
    // This is well known 3-line
    // swap code
    BoundingBox temp = lhs.boundingBox;
    lhs.boundingBox  = rhs.boundingBox;
    rhs.boundingBox  = temp;
}