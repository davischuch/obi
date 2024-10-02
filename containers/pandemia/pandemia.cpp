#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
	int totalFriends, totalMeetings, infectedFriend, firstInfectedMeeting;
	std::vector<int> friendsAtTheMeeting;
	std::vector<int>::iterator it;
	std::set<int> friends;

	std::cin >> totalFriends >> totalMeetings >> infectedFriend >> firstInfectedMeeting;
	friends.insert(infectedFriend);

	for (int i = 1; i <= totalMeetings; i++) {
		int friendsPresent;
		std::cin >> friendsPresent;

		for (int j = 0; j < friendsPresent; j++) {
			int currentFriend;
			std::cin >> currentFriend;
			friendsAtTheMeeting.push_back(currentFriend);
			it = std::find_first_of(friendsAtTheMeeting.begin(), friendsAtTheMeeting.end(), friends.begin(), friends.end());
		}

		if (it != friendsAtTheMeeting.end()) {
			if (i >= firstInfectedMeeting && *it != 0) {
				for (int k = 0; k < friendsAtTheMeeting.size(); k++) {
					friends.insert(friendsAtTheMeeting[k]);
				}
			}
		}
		friendsAtTheMeeting.clear();
	}
	std::cout << friends.size();
}