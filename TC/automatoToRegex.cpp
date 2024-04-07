#include "automato.h"
#include <iostream>
#include <string>
#include <vector>

void Automato::normalize() {
    // Normalize Start
    if (this->select(this->start)->inConCount()) {
        std::string name = this->start + "_1";
        this->addNode(name);
        this->addCon(name, this->start, "$");
        this->setStart(name);
    };
    // Normalize End
    
    ;
}

void Automato::toRegex() {
    while (true) {
        this->normalize();
        ;
    }
}

int main() {
    Automato a;
    a.addNode("s0");
    a.addNode("s1");
    a.addNode("s2");
    a.addNode("s3");
    a.addNode("s4");
    a.addNode("s5");
    a.addNode("s6");
    a.addNode("s7");
    a.addNode("s8");
    a.addNode("s9");
    a.setStart("s0");
    a.addAccepting("s0");

    a.select("s0")->addCon(Con{ "s1", "0" });
    a.select("s1")->addCon(Con{ "s2", "0" });
    a.select("s2")->addCon(Con{ "s3", "0" });
    a.select("s3")->addCon(Con{ "s4", "0" });
    a.select("s4")->addCon(Con{ "s0", "0" });

    a.select("s5")->addCon(Con{ "s6", "0" });
    a.select("s6")->addCon(Con{ "s7", "0" });
    a.select("s7")->addCon(Con{ "s8", "0" });
    a.select("s8")->addCon(Con{ "s9", "0" });
    a.select("s9")->addCon(Con{ "s5", "0" });

    a.select("s0")->addCon(Con{ "s5", "1" });
    a.select("s1")->addCon(Con{ "s6", "1" });
    a.select("s2")->addCon(Con{ "s7", "1" });
    a.select("s3")->addCon(Con{ "s8", "1" });
    a.select("s4")->addCon(Con{ "s9", "1" });

    a.select("s5")->addCon(Con{ "s0", "1" });
    a.select("s6")->addCon(Con{ "s1", "1" });
    a.select("s7")->addCon(Con{ "s2", "1" });
    a.select("s8")->addCon(Con{ "s3", "1" });
    a.select("s9")->addCon(Con{ "s4", "1" });

    a.print();

    return 0;
}