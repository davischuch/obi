#include <iostream>
#include <string>
#include <numeric>

int main() {
	int numOfEvents;
	std::cin >> numOfEvents;

	int matriz[100][6] = {0};
	char lastEvent = 0;

	for (int i = 0; i <= numOfEvents; i++) {
		std::string currentEvent;
		std::getline(std::cin, currentEvent);

		int typeOfEvent = currentEvent[0];
		int eventValue = 0;

		if (currentEvent[0] != 0) {
			currentEvent.erase(currentEvent.begin());
			currentEvent.erase(currentEvent.begin());

			eventValue = std::stoi(currentEvent);
		}

		switch (typeOfEvent) {
			case 82: //R
				if (lastEvent != '\0' && lastEvent != 'T') {
					for (int j = 0; j < 100; j++) {
						if (matriz[j][1] != matriz[j][2]) {
							matriz[j][3] = matriz[j][3] + 1;
						}
					}
				}

				matriz[eventValue][0] = eventValue;
				matriz[eventValue][1] = matriz[eventValue][1] + 1;
				matriz[eventValue][5] = 0;
				
				break;
			case 69: //E
				if (lastEvent != '\0' && lastEvent != 'T') {
					for (int j = 0; j < 100; j++) {
						if (matriz[j][1] != matriz[j][2]) {
							matriz[j][3] = matriz[j][3] + 1;
						}
					}
				}

				matriz[eventValue][2] = matriz[eventValue][2] + 1;
				matriz[eventValue][5] = 1;

				if (matriz[eventValue][1] == matriz[eventValue][2]) {
					matriz[eventValue][4] = matriz[eventValue][3];
				}
				
				break;
			case 84: //T
				for (int j = 0; j < 100; j++) {
					if (matriz[j][1] != matriz[j][2]) {
						matriz[j][3] = matriz[j][3] + eventValue;
					}
				}
				break;
			default:
				break;
		}
		lastEvent = typeOfEvent;
	}

	for (int i = 0; i < 100; i++) {
		if (matriz[i][0] != 0) {
			std::string saida;
			saida = std::to_string(i) + " " + std::to_string(matriz[i][4]);

			if (matriz[i][5] == 0) {
				saida = std::to_string(i) + " " + "-1";
				std::cout << saida << std::endl;
			}
			else {
				saida = std::to_string(i) + " " + std::to_string(matriz[i][4]);
				std::cout << saida << std::endl;
			}
		}
	}
}