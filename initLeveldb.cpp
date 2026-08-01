#include <iostream>
#include <leveldb/db.h>

using namespace std;

int main()
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;

    /*Open connection to db*/

    leveldb::Status status = leveldb::DB::Open(options,"elroyDb",&db);

    if(!status.ok()) 
    {
        cout << status.ToString() << endl;
        return 1;    
    } 

    cout << "OPEN STATUS:" << status.ToString() << endl;

    /*Insert value to DB */

    leveldb::WriteOptions writeOptions;
    leveldb::Status writeStatus = db->Put(writeOptions, "name", "elroy");

        if(!writeStatus.ok()) 
    {
        cout << "WRITE STATUS:" << writeStatus.ToString() << endl;
        return 1;    
    } 

    cout << "Write status:" << writeStatus.ToString() << endl;

    /*get value from DB */

    std::string str;
    leveldb::ReadOptions readOptions;
    leveldb::Status readStatus = db->Get(readOptions, "name", &str);

        if(!readStatus.ok()) 
    {
        cout << "READ STATUS:" << readStatus.ToString() << endl;
        return 1;    
    } 

    cout << "READ STATUS:" << readStatus.ToString() << endl;

    cout << "READ Value:" << str << endl;


    /*delete value from DB*/

    leveldb::Status delStatus = db->Delete(writeOptions, "name");

        if(!delStatus.ok()) 
    {
        cout << "DEL STATUS:" << readStatus.ToString() << endl;
        return 1;    
    } 

    cout << "del STATUS:" << readStatus.ToString() << endl;

    /*read if value is present after delete*/

    readStatus = db->Get(readOptions, "name", &str);

    if(!readStatus.ok()) 
    {
        cout << "READ STATUS:" << readStatus.ToString() << endl;
        return 1;    
    } 

    cout << "READ STATUS:" << readStatus.ToString() << endl;

    return 0;
}

