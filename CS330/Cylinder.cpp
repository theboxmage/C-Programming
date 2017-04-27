#include "Cylinder.h"

/**
 * 
 */
Cylinder::Cylinder()
    :Polyhedron("Cylinder"),
     height(0),
     radius(0)
{
    boundingBox.setUpperRightVertex(0, 0, 0);
}

void Cylinder::read(std::istream& ins)
{
    ins >> height;
    ins >> radius;
    boundingBox.setUpperRightVertex(2*radius, 2*radius, height);
    
}

void Cylinder::display(std::ostream& outs) const
{
    Polyhedron::display(outs);

    outs << "Radius: " << radius 
         << " "
         << "Height: " << height;

}

void Cylinder::scale(double scalingFactor)
{
    height = height * scalingFactor;
    radius = radius * scalingFactor;
    boundingBox.setUpperRightVertex(2*radius, 2*radius, height);
}

//------------------------HINT------------------------
/**
 * 
 */
Cylinder::Cylinder(double r, double h)
    :Polyhedron("Cylinder"),
     height(h),
     radius(r)
{
    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}


Cylinder::Cylinder(const Cylinder& c)
:Polyhedron("Cylinder")
{
    height = c.height;
    radius = c.radius;
    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}
/**
 * 
 */
Cylinder::~Cylinder()
{
}

double Cylinder::getDiameter()
{
    return radius*2;
}