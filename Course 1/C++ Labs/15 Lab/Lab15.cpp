#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class HashTable{
    private:
        static const int HashGroup = 10;
        list<pair<int,string>> table[HashGroup];

    public:
        bool isEmpty() const;
        int HashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        void printTable();
};

bool HashTable::isEmpty() const {
    int sum;
    for (int i = 0; i < HashGroup; i++)
    {
        sum += table[i].size();
    }
    
    if(!sum){
        return true;
    }
    return false;
}

int HashTable::HashFunction(int key){
    return key % HashGroup;
}
void HashTable::insertItem(int key, string value){
    int HashValue = HashFunction(key);
    auto& cell = table[HashValue];
    auto bItr = begin(cell);
    bool keyExist = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first==key)
        {
            keyExist = true;
            bItr->second = value;
            cout<<"[WARNING] Key exist. Value replaced."<<endl;
            break;
        }
        
    }
    if (!keyExist)
    {
        cell.emplace_back(key,value);
    }
    
    return;
}

void HashTable::removeItem(int key){
    int HashValue = HashFunction(key);
    auto& cell = table[HashValue];
    auto bItr = begin(cell);
    bool keyExist = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first==key)
        {
            keyExist = true;
            bItr = cell.erase(bItr);
            cout<<"[INFO] Item removed."<<endl;
            break;
        }
        
    }
    if (!keyExist)
    {
        cout<<"[WARNING] Key not foiund. Pair not removed"<<endl;
    }
    return;
}

void HashTable::printTable(){
    for (int i = 0; i < HashGroup; i++)
    {
        if (table[i].size()==0)
        {
            continue;
        }
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
        {
            cout<<"[INFO] Key: "<<bItr->first<<" Value: "<<bItr->second<<endl;
        }
        
    }
    
}

int main(){
    HashTable HT;

    if(HT.isEmpty()){
        cout<<"COrrect answer. Good job.";
    }
    else{
        cout<<"Oh. We need to check out code"<<endl;
    }
    HT.insertItem(905,"Minsk");
    HT.insertItem(225,"Brest");
    HT.insertItem(375,"Grodno");
    HT.insertItem(785,"Vitebsk");
    HT.insertItem(785,"Mogelev");

    HT.printTable();

    HT.removeItem(225);
    HT.removeItem(100);

    if(HT.isEmpty()){
    cout<<"Oh. We need to check out code";
    }
    else{
        cout<<"Correct"<<endl;
    }
    return 0;
}