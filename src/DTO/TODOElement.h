//
// Created by philipp on 21.05.25.
//

#ifndef TODOELEMENT_H
#define TODOELEMENT_H

#include <string>
#include <istream>
#include <ostream>

class TODOElement {
public:
    std::string priority;
    std::string content;
    bool completed = false;

    void searialize(std::ostream &out) const {
        size_t priorityLen = priority.size();
        out.write(reinterpret_cast<const char*>(&priorityLen), sizeof(priorityLen));
        out.write(priority.c_str(), priorityLen);

        size_t contentLen = content.size();
        out.write(reinterpret_cast<const char*>(&contentLen), sizeof(contentLen));
        out.write(content.c_str(), contentLen);

        out.write(reinterpret_cast<const char*>(&completed), sizeof(completed));
    }

    void deserialize(std::istream& in) {
        size_t priorityLen;
        in.read(reinterpret_cast<char*>(&priorityLen), sizeof(priorityLen));
        priority.resize(priorityLen);
        in.read(&priority[0], priorityLen);

        size_t contentLen;
        in.read(reinterpret_cast<char*>(&contentLen), sizeof(contentLen));
        content.resize(contentLen);
        in.read(&content[0], contentLen);

        in.read(reinterpret_cast<char*>(&completed), sizeof(completed));
    }
};

#endif //TODOELEMENT_H
