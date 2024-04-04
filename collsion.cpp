#include<iostream>
#include<vector>
using namespace std;
const int TABLE_SIZE = 10;
class HashTable
{
        private:
        vector <int> table;
        vector <bool> isOccupied;

        //Hash Function to calculate the index
        int hashFunction(int key)
        {
            return key % TABLE_SIZE;
        }

        //Probe function for linear probing 
        int linearProbe(int index)
        {
            return (index+1)% TABLE_SIZE;
        }
        public:
        HashTable()
        {
            table.resize(TABLE_SIZE,-1);
            isOccupied.resize(TABLE_SIZE,false);
        }
        void insert(int key)
        {
            int index = hashFunction(key);
            while(isOccupied[index])
            {
                index = linearProbe(index);
            }
            table[index] = key;
            isOccupied[index] = true;
        }
        bool search(int key)
        {
            int index = hashFunction(key);
            int originalIndex = index;
            while(isOccupied[index])
            {
                if(table[index] == key)
                return true;
                index = linearProbe(index);
                if(index == originalIndex)
                break;
            }
            return false;
        }
        void display()
        {
            for(int i = 0; i <TABLE_SIZE;i++)
            {
                if(isOccupied[i])
                cout<<i<<":"<<table[i]<<endl;
            }
        }
};
int main()
{
    HashTable ht;
    ht.insert(12);
    ht.insert(25);
    ht.insert(35);
    ht.insert(44);
    ht.insert(78);

    cout<<"Hash Table:"<<endl;
    ht.display();

    int searchKey = 35;
    if(ht.search(searchKey))
    cout<<"Element"<<"found in the hash table"<<endl;
    else
    cout<<"Element"<<searchKey<<"not found in the hash table"<<endl;
    return 0 ;
}          