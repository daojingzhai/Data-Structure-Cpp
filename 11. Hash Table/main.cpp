//
//  main.cpp
//  Hash Table
//
//  Created by Daojing Zhai on 2018/5/22.
//  Copyright © 2018 Daojing Zhai. All rights reserved.
//

#include <iostream>
using namespace std;
class HashingMachine {
public:
    HashingMachine(int d, int m) {
        this->div = d;
        this->maxAddr = m;
        this->numBins = m + 1;
        
        this->hashTable = new int[this->numBins]();
        this->isOccupied = new bool[this->numBins]();
    }
    
    virtual ~HashingMachine() {
        delete[](this->hashTable);
        delete[](this->isOccupied);
    }
    
    int insert(int newElement) {
        int hashedValue = newElement % this->div;
        for (int i = 0; i < this->numBins; i++) {
            int probedLoc = (hashedValue + i) % this->numBins;
            if (this->isOccupied[probedLoc] == false) {
                this->isOccupied[probedLoc] = true;
                this->hashTable[probedLoc] = newElement;
                return probedLoc;
            } else if (this->hashTable[probedLoc] == newElement) {
                return probedLoc;
            }
        }
        return -1;
    }
    
private:
    int div;
    int maxAddr;
    int numBins;
    int* hashTable;
    bool* isOccupied;
};

int main() {
    int alIn, canIn;
    while(cin >> alIn){
        HashingMachine dummy = HashingMachine(17, 20);
        for (int i = 0; i < alIn; i++) {
            cin >> canIn;
            dummy.insert(canIn);
        }
        cin >> canIn;
        cout << dummy.insert(canIn);
        cout << endl;
        
    }
    return 0;
}
