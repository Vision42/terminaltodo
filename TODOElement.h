//
// Created by philipp on 21.05.25.
//

#ifndef TODOELEMENT_H
#define TODOELEMENT_H

#include <string>

class TODOElement {
public:
    std::string priority;
    std::string content;
    bool completed = false;
};

#endif //TODOELEMENT_H
