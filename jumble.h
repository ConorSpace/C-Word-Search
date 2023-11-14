
using namespace std;
#include <string>

#include <vector>
typedef char* charArrayPtr;

class BadJumbleException{
    public:
        BadJumbleException(const string& message);
        string what() const;
    private:
        string message;
};

class JumblePuzzle{
    public:
        JumblePuzzle(string word, string diff);
        JumblePuzzle(const JumblePuzzle &obj);
        ~JumblePuzzle();
        charArrayPtr* getJumble() const;
        int getSize() const;
        char getDirection() const;
        int getRowPos() const;
        int getColPos() const;
        charArrayPtr* jumbleArr;
        string diff;
        string word;
    private:
        int size;
        char direction;
        int rp;
        int cp;
};
