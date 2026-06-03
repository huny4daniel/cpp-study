#include <iostream>
#include "Review.h"
using namespace std;

Review::Review(string author, string content, int score) {
    strAuthor = author;
    strContent = content;
    nScore = score;
}

void Review::showReview() {
    cout << "[" << strAuthor << "] 평점: " << nScore << ", 후기: " << strContent << endl;
}
