#include <QCoreApplication>
#include "porta.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Porta p = Porta("delaporta"); //to fix!!!
    if (argc == 2 && a.arguments().at(1) == "--print-table")
    {
        p.print_table();
    }
    else if (argc == 3)
    {
        Porta p = Porta(a.arguments().at(2));
        std::cout << "Message: " << a.arguments().at(1).toStdString() << std::endl;
        std::cout << "Used password: " << a.arguments().at(2).toStdString() << std::endl;
        std::cout << "Encrypted message: " << p.encrypt(a.arguments().at(1)).toStdString() << std::endl;
    }
    else
    {
        std::cout << "Incorrect usage!" << std::endl;
        std::cout << "Usage: porta {<message> <password>|--print-table}" << std::endl;
    }

    QCoreApplication::exit(0);
    return 0;
}
