#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

#include <vector>
#include "Review.h"
using namespace std;

class SortStrategy {
public:
    virtual ~SortStrategy() {}
    virtual void sortReviews(vector<Review>& reviews) = 0;
};

// 전략 1. 최신순 정렬(default)
class LatestSort : public SortStrategy {
public:
    void sortReviews(vector<Review>& reviews);
};

// 전략 2. 평점 높은순 정렬
class HighScoreSort : public SortStrategy {
public:
    void sortReviews(vector<Review>& reviews);
};

// 전략 3. 평점 낮은순 정렬
class LowScoreSort : public SortStrategy {
public:
    void sortReviews(vector<Review>& reviews);
};

#endif
