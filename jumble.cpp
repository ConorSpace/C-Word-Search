#include <string>
#include <random>
#include <iostream>
#include "jumble.h"

BadJumbleException::BadJumbleException(const string& message): message(message) {} ;

JumblePuzzle::JumblePuzzle(vector<string> word, string diff){
    //checking if word is approate lengeth
    if(word.size() < 3 || word.size() > 10){
        throw BadJumbleException("Invaled Input for hidden word, must be longer \nthen 3 letters and less the 10"); 
    }

    //initlizing random char varable
    char rc;

    //getting random chars for puzzle ready
    random_device rd;  // Obtain a random seed from hardware if available
    mt19937 gen(rd()); // Seed the generator
    uniform_int_distribution<> distr('a', 'z');


    //choosing random direction for diffen word
    string chars = "nesw";
    uniform_int_distribution<> distr(0, chars.size() - 1);
    this->direction = chars[distr(gen)];
    

    //Generate and output the random number
    cout << distr(gen) << std::endl;
    
    //getting size of 2D array based on input 
    if(diff == "easy"){
        this->size = word.size() * 2;
    }else if(diff == "medium"){
        this->size = word.size() * 3;
    }else if(diff == "hard"){
        this->size = word.size() * 4;
    }else{
        throw BadJumbleException("Invaled Input for Puzzle Diffcultly");
    }

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
    
};

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
    return this->size;
}

int JumblePuzzle::getRowCol() const{
    return this->size;
}