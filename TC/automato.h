#ifndef __automato_h__
#define __automato_h__

#include <iostream>
#include <string>
#include <vector>

class Con;
class Node;
class Automato;

class Con {
    std::string node;
    std::string str;

  public:
    Con(const Con &con) {
        node = con.node;
        str  = con.str;
    }

    Con(const std::string &n, const std::string &s) {
        node = n;
        str  = s;
    }

    bool operator==(const Con &con) const {
        return con.node == node && con.str == str;
    }

    std::string getNode() const { return std::string(node); }

    std::string getStr() const { return std::string(str); }

    void setStr(std::string &a) { str = a; }

    void print(std::string prefix = "To") {
        std::cout << prefix << ": " << node << " Str: " << str << std::endl;
    }
};

class Node {
    Automato        *ownerAutomato;
    std::string      name;
    std::vector<Con> inCon;
    std::vector<Con> outCon;

  public:
    Node(Automato *a) { ownerAutomato = a; }

    Node(const std::string &str, Automato *a) {
        ownerAutomato = a;
        name          = str;
    }

    Node(const Node &node) {
        name          = node.name;
        inCon         = node.inCon;
        outCon        = node.outCon;
        ownerAutomato = node.ownerAutomato;
    }

    std::string getName() const { return std::string(name); }

    void print(bool printIn);
    void setName(const std::string &str);
    void addCon(const Con &con);
    void delCon(const Con &con);
    void addInCon(const Con &con);
    void delInCon(const Con &con);
    int  inConCount();
};

class Automato {
    std::vector<Node>        nodes;
    std::string              start;
    std::vector<std::string> accepting;

  public:
    void print();
    void addNode(Node &node);
    void addNode(const std::string &name);
    bool addCon(
        const std::string &from, const std::string &to, const std::string &str
    );
    void  setStart(const std::string &name);
    bool  addAccepting(const std::string &name);
    bool  removeAccepting(const std::string &name);
    Node *select(const std::string &name);
    void  normalize();
    void  toRegex();
};

//
// Node Functions
//


void Node::print(bool printIn = false) {
    std::cout << "Node: " << name << std::endl;
    if (printIn) {
        std::cout << "    InCon: " << std::endl;
        for (size_t i = 0; i < inCon.size(); ++i) {
            inCon[i].print("    From");
        }
    }
    std::cout << "    OutCon: " << std::endl;
    for (size_t i = 0; i < outCon.size(); ++i) { outCon[i].print("    To"); }
}

void Node::setName(const std::string &str) { name = str; }

void Node::addCon(const Con &con) {
    outCon.push_back(con);
    ownerAutomato->select(con.getNode())
        ->addInCon(Con(this->getName(), con.getStr()));
}

void Node::delCon(const Con &con) {
    Node *out = ownerAutomato->select(con.getNode());
    if (out) { out->delInCon(con); }
    for (size_t i = 0; i < outCon.size(); ++i) {
        if (outCon[i] == con) {
            outCon.erase(outCon.begin() + i);
            break;
        }
    }
}

void Node::addInCon(const Con &con) { inCon.push_back(con); }

void Node::delInCon(const Con &con) {
    for (size_t i = 0; i < inCon.size(); ++i) {
        if (inCon[i] == con) {
            inCon.erase(inCon.begin() + i);
            break;
        }
    }
}

int Node ::inConCount() { return inCon.size(); }

//
// Automato Functions
//
void Automato::print() {
    std::cout << "Start: " << start << std::endl;
    std::cout << "Accepting: ";
    for (size_t i = 0; i < accepting.size(); ++i) { std::cout << accepting[i]; }
    std::cout << std::endl;
    for (size_t i = 0; i < nodes.size(); ++i) { nodes[i].print(); }
}

void Automato::addNode(Node &node) { nodes.push_back(node); }

void Automato::addNode(const std::string &name) {
    nodes.push_back(Node(name, this));
}

bool Automato::addCon(
    const std::string &from, const std::string &to, const std::string &str
) {
    Node *selected = this->select(from);
    if (selected) {
        selected->addCon(Con(to, str));
        return true;
    };
    return false;
}

void Automato::setStart(const std::string &name) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i].getName() == name) {
            start = name;
            break;
        };
    }
}

bool Automato::addAccepting(const std::string &name) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i].getName() == name) {
            accepting.push_back(name);
            return true;
        };
    }
    return false;
}

bool Automato::removeAccepting(const std::string &name) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i].getName() == name) {
            accepting.erase(accepting.begin() + i);
            return true;
        };
    }
    return false;
}

Node *Automato::select(const std::string &name) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i].getName() == name) { return &nodes[i]; };
    }
    return nullptr;
}

#endif