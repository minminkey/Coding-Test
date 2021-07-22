#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

#define CMD_INIT	100
#define CMD_ADD		200
#define CMD_BUY		300
#define CMD_RENT	400
#define CMD_RETURN	500

#define MAXN		100
#define MAXL		8
#define pii			pair<int, int>

typedef struct {
	int time;
	int playTime;
	int rentTime;
	string name;
	bool rented;
}Customer;

map<string, Customer> customers;
priority_queue <pii, vector<pii>, greater<pii>> shop[110];
priority_queue<int, vector<int>, greater<int>> shopGo[110];
int deliveryShop[MAXN];
int DTime;

void init(int N, int durableTime, int deliveryTimes[MAXN])
{
	DTime = durableTime;
	for (int i = 0; i < N; i++) {
		deliveryShop[i] = deliveryTimes[i];
		shop[i] = priority_queue <pii, vector<pii>, greater<pii>>();
		shopGo[i] = priority_queue<int, vector<int>, greater<int>>();
	}
	customers.clear();
}

void addBicycle(int cTimestamp, int pID, int bicycleNum)
{
	int now = cTimestamp;
	for (int i = 0; i < bicycleNum; ++i) {
		shop[pID].push({ 0, now });
	}
}

void buyTicket(int cTimestamp, char uName[MAXL], int validTime)
{
	string name = uName;
	if (customers.find(name) == customers.end()) {
		customers[name].name = name;
		customers[name].time = cTimestamp + validTime - 1;
	}
	else {
		if (customers[name].time < cTimestamp) {
			customers[name].time = cTimestamp + validTime - 1;
		}
		else {
			customers[name].time += validTime;
		}
	}
}

int rentBicycle(int cTimestamp, char uName[MAXL], int pID)
{
	while (!shopGo[pID].empty()) {
		int reached = shopGo[pID].top();
		if (reached <= cTimestamp) {
			shop[pID].push({ 0, 0 });
			shopGo[pID].pop();
		}
		else
			break;
	}
	string name = uName;
	if (customers.find(name) == customers.end())	return -1;
	if (shop[pID].empty())							return -1;
	if (customers[name].time < cTimestamp)			return -1;
	//cout << "limit : " << customers[name].time << endl;
	if (customers[name].rented)						return -1;
	int playTime = shop[pID].top().first;
	int rentTime = cTimestamp;
	//cout << shop[pID].size() << endl;
	shop[pID].pop();
	customers[name].rented = true;
	customers[name].playTime = playTime;
	customers[name].rentTime = rentTime;
	//cout << "playTime : " << playTime << endl;
	return playTime;
}

int returnBicycle(int cTimestamp, char uName[MAXL], int pID)
{
	string name = uName;
	if (customers.find(name) == customers.end())	return -1;
	if (!customers[name].rented)					return -1;
	customers[name].rented = false;
	int nowPlayTime = cTimestamp - customers[name].rentTime;
	int playTime = customers[name].playTime + nowPlayTime;
	//cout << playTime << ' ' << DTime << ' ' << customers[name].time <<endl;
	if (playTime > DTime) {
		shopGo[pID].push(cTimestamp + deliveryShop[pID]);
	}
	else {
		shop[pID].push({ playTime, 0 });
	}
	if (customers[name].time > cTimestamp)			return 0;
	else											return cTimestamp - customers[name].time;
}