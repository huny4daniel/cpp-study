#include <algorithm>
#include "SortStrategy.h"
using namespace std;

// 전략 1. 최신순 정렬(default) : 삽입 순서의 역순(가장 최근 작성이 먼저)
void LatestSort::sortReviews(vector<Review>& reviews) {
    reverse(reviews.begin(), reviews.end());
}

// 전략 2. 평점 높은순 정렬 (내림차순)
void HighScoreSort::sortReviews(vector<Review>& reviews) {
    stable_sort(reviews.begin(), reviews.end(),
        [](Review a, Review b) { return a.getScore() > b.getScore(); });
}

// 전략 3. 평점 낮은순 정렬 (오름차순)
void LowScoreSort::sortReviews(vector<Review>& reviews) {
    stable_sort(reviews.begin(), reviews.end(),
        [](Review a, Review b) { return a.getScore() < b.getScore(); });
}
