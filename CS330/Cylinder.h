#ifndef CYLINDER_H_INCLUDED
#define CYLINDER_H_INCLUDED

#include "Polyhedron.h"

class Cylinder : public Polyhedron {
    private:
        double height;
        double radius;

    public:
        /**
         * Default Constructor
         */
        Cylinder();

        Cylinder(const Cylinder& c);
        /**
         * Construct a cylinder with
         * specified height and radius 
         */
        Cylinder(double r, double h);

        Polyhedron* clone() const;

        void display(std::ostream& outs) const;

        void scale(double scalingFactor);

        void read(std::istream&);

        /**
         * Destructor
         */
        ~Cylinder();

        double getDiameter();



};
inline
Polyhedron* Cylinder::clone() const
{
    return new Cylinder(*this);
}
#endif