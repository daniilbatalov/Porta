#ifndef PORTA_H
#define PORTA_H

#include <QString>
#include <QVector>

class Porta
{
public:
private:
    QString key;
    QString expand_key(int size);
    QVector<QVector<int>> table{{14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26},
                                {15, 17, 21, 22, 23, 25, 20, 19, 14, 16, 18, 26, 24},
                                {18, 23, 24, 16, 20, 21, 25, 22, 26, 14, 17, 15, 19},
                                {24, 26, 14, 15, 18, 23, 16, 19, 21, 25, 20, 17, 22},
                                {15, 16, 22, 20, 23, 17, 19, 21, 18, 14, 25, 24, 26},
                                {20, 18, 17, 19, 24, 26, 16, 22, 25, 15, 21, 14, 23},
                                {22, 16, 18, 25, 19, 26, 14, 17, 15, 21, 20, 24, 23},
                                {23, 14, 26, 20, 21, 15, 22, 19, 25, 24, 16, 18, 17},
                                {17, 21, 16, 24, 14, 15, 18, 26, 20, 22, 19, 23, 25},
                                {17, 20, 26, 21, 14, 18, 25, 22, 16, 19, 24, 23, 15},
                                {26, 18, 16, 14, 17, 23, 22, 25, 19, 20, 15, 21, 24},
                                {25, 18, 22, 17, 21, 15, 20, 14, 19, 26, 23, 16, 24},
                                {18, 17, 21, 16, 23, 20, 26, 22, 19, 15, 24, 14, 25}
                               };
    QString alphabet = "abcdefghijklmnopqrstuvwxyz";
    QString table_line_to_string(int line);
public:
    Porta(QString key_value);
    void print_table();
    QString encrypt(QString message);
};

#endif // PORTA_H
