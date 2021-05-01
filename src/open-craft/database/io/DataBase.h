#ifndef OPEN_CRAFT_DATABASE_H
#define OPEN_CRAFT_DATABASE_H


class DBReader;

class DBWriter;

class DataBase
{
public:
    virtual void write(DBWriter &) = 0;

    virtual void read(DBReader &) = 0;
};


#endif //OPEN_CRAFT_DATABASE_H
