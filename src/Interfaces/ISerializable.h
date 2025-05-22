//
// Created by philipp on 22.05.25.
//

#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <istream>

class ISerializable {
public:
    ISerializable() = default;
    virtual ~ISerializable() = default;

    virtual void serialize(std::ostream &out) const = 0;
    virtual void deserialize(std::istream& in) = 0;
};



#endif //ISERIALIZABLE_H
