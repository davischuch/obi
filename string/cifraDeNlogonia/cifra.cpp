#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string wordEntry;
	std::cin >> wordEntry;

	std::string alphabet = "abcdefghijklmnopqrstuvxz";
	std::string consonants = "bcdfghjklmnpqrstvwxz";
	std::string vowels = "aeiou";
	int vowelsNums[5] = { 0, 4, 8, 14, 20 };

	std::vector<char> cipher(0);

	for (int i = 0; i < wordEntry.size(); i++) {
		for (int j = 0; j < vowels.size(); j++) {
			if (vowels[j] == wordEntry[i]) {
				cipher.push_back(vowels[j]);
				break;
			}
		}
		for (int k = 0; k < consonants.size(); k++) {
			if (consonants[k] == wordEntry[i]) {
				cipher.push_back(consonants[k]);
				for (int l = 0; l < alphabet.size(); l++) {
					if (consonants[k] == alphabet[l]) {
						int closestVowel;
						int finalValue = 26;
						int m;

						for (m = 0; m < 5; m++) {
							int currentCalc = l - vowelsNums[m];
							if (currentCalc < 0) {
								currentCalc = currentCalc * -1;
							}
							if (currentCalc == finalValue) {
								if (closestVowel < vowelsNums[m]) {
									cipher.push_back(alphabet[closestVowel]);
									break;
								}
								if (closestVowel > vowelsNums[m]) {
									cipher.push_back(alphabet[vowelsNums[m]]);
									break;
								}

							}
							if (currentCalc < finalValue) {
								finalValue = currentCalc;
								closestVowel = vowelsNums[m];
							}
						}
						if (m >= 5) {
							cipher.push_back(alphabet[closestVowel]);
						}
					}
				}
				if (k == 19) {
					cipher.push_back(consonants[k]);
				} else {
					int y = k + 1;
					cipher.push_back(consonants[y]);
				}
				
			}
		}
	}
	for (int z = 0; z < cipher.size(); z++) {
		std::cout << cipher[z];
	}
}