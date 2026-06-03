#ifndef REVIEW_H
#define REVIEW_H

#include <string>
using namespace std;

class Review {
private:
    string strAuthor;
    string strContent;
    int nScore;
public:
    Review(string author, string content, int score);
    void showReview();
    int getScore() { return nScore; }
};

#endif
