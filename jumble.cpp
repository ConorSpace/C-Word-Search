#include <string>
#include <random>
#include <iostream>
#include "jumble.h"

//BadJumbleException 
BadJumbleException::BadJumbleException(const string& message): message(message) {};

string BadJumbleException::what() const{
     return message; 
     }


JumblePuzzle::JumblePuzzle(string word, string diff){
    //checking if word is approate length
    if(word.length() < 3 || word.length() > 10){
        throw BadJumbleException("Invaled Input for hidden word, must be longer \nthen 3 letters and less the 10"); 
    }

    //initlizing random char varable
    char rc;

    //getting random chars for puzzle ready
    random_device rd;  // Obtain a random seed from hardware if available
    mt19937 gen(rd()); // Seed the generator
    uniform_int_distribution<> distr('a', 'z');
    
    //Generate and output the random number
    //cout << distr(gen) << std::endl;
    
    //getting size of 2D array based on input 
    if(diff == "easy"){
        this->size = word.length() * 2;
    }else if(diff == "medium"){
        this->size = word.length() * 3;
    }else if(diff == "hard"){
        this->size = word.length() * 4;
    }else{
        throw BadJumbleException("Invaled Input for Puzzle Diffcultly");
    }

    //making sure the grid is different everytime
    srand(static_cast<unsigned int>(time(0)));

    //Creating puzzle with random letters
    this->jumbleArr = new char*[size];

    for(int i = 0; i < size; i++){
        this->jumbleArr[i] = new char[size];
    }

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            rc = static_cast<char>(distr(gen));
            this->jumbleArr[i][j] = rc;
        }
    }

    //inputting the hidden word
    string directions = "nsew";
    bool placed = false;

    
     do {
        int startRow = rand() % size;
        int startCol = rand() % size;
        char direction = directions[rand() % 4];

        
        int dRow = 0, dCol = 0;
        switch (direction) {
            case 'n': dRow = -1; break;
            case 'e': dCol = 1; break;
            case 's': dRow = 1; break;
            case 'w': dCol = -1; break;
        }
        int endRow = startRow + dRow * (word.length() - 1);
        int endCol = startCol + dCol * (word.length() - 1);
        if (endRow >= 0 && endRow < size && endCol >= 0 && endCol < size) {
            for (int i = 0; i < word.length(); ++i) {
                jumbleArr[startRow + i * dRow][startCol + i * dCol] = word[i];
            }
            this->rp = startRow;
            this->cp = startCol;
            this->direction = direction;
            placed = true;
        }
    } while (!placed);
    
};

JumblePuzzle::JumblePuzzle(const JumblePuzzle& obj) {
    this->size = obj.size;
    this->rp = obj.rp;
    this->cp = obj.cp;
    this->direction = obj.direction;

    jumbleArr = new charArrayPtr[size];
    for (int i = 0; i < size; i++) {
        jumbleArr[i] = new char[size];
        for (int j = 0; j < size; j++) {
            jumbleArr[i][j] = 'a' + rand() % 26;
        }
    }
}

JumblePuzzle::~JumblePuzzle(){
    for (int j = 0; j < size; j++) {
        delete[] jumbleArr[j];
    }
    delete[] jumbleArr;
}


charArrayPtr* JumblePuzzle::getJumble() const {
    return this->jumbleArr;
} 

int JumblePuzzle::getSize() const{
    return this->size;
}

char JumblePuzzle::getDirection() const {
    return this->direction;
}

int JumblePuzzle::getRowPos() const{
    return this->rp;
}

int JumblePuzzle::getColPos() const{
    return this->cp;
}