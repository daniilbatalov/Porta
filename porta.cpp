#include "porta.h"
#include <iostream>

Porta::Porta(QString key_value)
{
    key = key_value.toLower();
}

QString Porta::expand_key(int size)
{
    QString temp_key = key;
    int fullstring_c = (size / key.size()) - 1;
    int remstring_c = size % key.size();
    for(int i = 0; i < fullstring_c; i++)
    {
        temp_key.append(key);
    }
    temp_key.append(key.left(remstring_c));
    return temp_key;

}

QString Porta::encrypt(QString message)
{
    QString temp_key = expand_key(message.size());
    QString result;
    for(int i = 0; i < temp_key.size(); i++)
    {
        int line = alphabet.indexOf(temp_key.at(i)) / 2;
        int code = message.at(i).unicode() - 'a';
        if (code >= 0 && code <= 12)
        {
            result.append(QChar(table.at(line).at(code) + 96));
        }
        else
        {
            int new_code = table.at(line).indexOf(code + 1) + 97;
            result.append(QChar(new_code));
        }
    }
    return result;
}

QString Porta::table_line_to_string(int line)
{
    QString result;
    for(int i = 0; i < table.at(line).size(); i++)
    {
        int code = table.at(line).at(i) + 96;
        result.append(QChar(code) + ' ');
    }
    return result;
}
void Porta::print_table()
{
    std::cout << "Used table: " << std::endl;
    for(int i = 0; i < table.size() * 2; i++)
    {

        if (i % 2 == 1)
        {
            std::cout << QString(alphabet.toUpper().at(i + 1 / 2)).toStdString() << " | " << table_line_to_string(i / 2).toStdString() << std::endl;
            std::cout << "------------------------------" << std::endl;
        }
        else
        {
            std::cout << QString(alphabet.toUpper().at(i)).toStdString() << " | a b c d e f g h i j k l m" << std::endl;
        }
    }
}
