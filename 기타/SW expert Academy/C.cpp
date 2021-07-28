#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

typedef struct {
    int id;
    int dur;
    int cap;
    int wait;
    int last;
}Att;

int Num;
Att att[101];
map<int, int> mp;
priority_queue<pii> attQ[101];

struct cmp {
    bool operator()(pii a, pii b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

void init(int N, int mId[], int mDuration[], int mCapacity[]) {
    Num = N;
    for (int i = 0; i < N; i++) {
        mp[mId[i]] = i;
        att[i].id = mId[i];
        att[i].dur = mDuration[i];
        att[i].cap = mCapacity[i];
        att[i].wait = 0;
        att[i].last = 0;
        attQ[i] = priority_queue<pii>();
    }
    return;
}

void process(int idx, int tStamp) {
    while (att[idx].last <= tStamp && attQ[idx].size() > 0) {
        int sum = att[idx].cap;
        while (sum > 0 && attQ[idx].size() > 0) {
            int p = attQ[idx].top().first;
            int now = attQ[idx].top().second;
            attQ[idx].pop();
            if (sum < now) {
                now -= sum;
                att[idx].wait -= sum;
                attQ[idx].push({ p, now });
                break;
            }
            sum -= now;
            att[idx].wait -= now;
        }
        att[idx].last += att[idx].dur;
    }
}

int add(int tStamp, int mId, int mNum, int mPriority) {
    mId = mp[mId];
    process(mId, tStamp - 1);
    if (att[mId].last < tStamp) {
        att[mId].last = tStamp;
    }
    attQ[mId].push({ mPriority, mNum });
    att[mId].wait += mNum;
    process(mId, tStamp);
    if (attQ[mId].empty())    return 0;
    return attQ[mId].top().first;
}

void search(int tStamp, int mCount, int mId[], int mWait[]) {
    for (int i = 0; i < Num; i++) {
        process(i, tStamp);
    }
    priority_queue<pii, vector<pii>, cmp> pq;
    for (int i = 0; i < Num; i++) {
        pq.push({ att[i].wait, att[i].id });
    }
    for (int i = 0; i < mCount; i++) {
        mId[i] = pq.top().second;
        mWait[i] = pq.top().first;
        pq.pop();
    }
    return;
}
