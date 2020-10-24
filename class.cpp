#include <iostream>
#include <string>
#include <regex>

class  house {
public:
	house() {};
	~house() {};
	house(int _w, int _d, int _h) {
		w = _w;
		d = _d;
		h = _h;
	}
	void printHouse() {
		std::cout << "Width: " << w << " m\n";
		std::cout << "Depth: " << d << " m\n";
		std::cout << "Height: " << h << " m\n";
	}
protected:
	int w;
	int d;
	int h;
};

class blockOfFlats :virtual public  house {
public:
	~blockOfFlats() {};
	blockOfFlats(int _residents, int _w, int _d, int _h) :house(_w, _d, _h) {
		residents = _residents;
	}
	void printBlockOfFlats() {
		std::cout << "Count of residents: " << residents << "\n";
	}
protected:
	int residents;
};

class flat :public blockOfFlats {
public:
	~flat(){};
	flat(int _sqare, int _residents, int _w, int _d, int _h) :blockOfFlats(_residents, _w, _d, _h) {
		sqare = _sqare;
	}
	void printFlat() {
		std::cout << "Sqare: " << sqare << " m^2\n";
	}
protected:
	int sqare;
};

class semiDetached :virtual public house {
public:
	~semiDetached() {}
	semiDetached(std::string _adress, int _w, int _d, int _h) :house(_w, _d, _h) {
		adress = _adress;
	}
	void printSemiDetached() {
		std::cout << "Adress: \"" << adress << "\"\n";
	}
protected:
	std::string adress;
};

class  block :public semiDetached {
public:
	~block() {}
	block(int _windows, std::string _adress, int _w, int _d, int _h) :semiDetached(_adress, _w, _d, _h) {
		windows = _windows;
	}
	void printBlock() {
		std::cout << "Count of windows: " << windows << "\n";
	}
protected:
	int windows;
};

class room : public block, public flat {
public:
	~room(){}
	room(std::string _roomName, int _sqare, int _residents, int _windows, std::string _adress, int _w, int _d, int _h):block(_windows, _adress, _w, _d, _h), flat(_sqare, _residents, _w, _d, _h),house(_w, _d, _h) {
		roomName = _roomName;
	}
	void printRoom() {
		std::cout << "Room name: " << roomName << "\n";
	}
private:
	std::string roomName;
};

int main() {
	int S,R,W,w,d,h;
	std::string A, N;

	std::cout << "Room name: ";
	rewind(stdin);
	std::getline(std::cin, A);

	std::cout << "Sqare: ";
	std::cin >> S;
	if (!std::cin){std::cout << "bad"; return 0;}

	std::cout << "Count of residents: ";
	std::cin >> R;
	if (!std::cin) { std::cout << "bad"; return 0;}

	std::cout << "Count of windows: ";
	std::cin >> W;
	if (!std::cin) { std::cout << "bad"; return 0; }

	std::cout << "Width: ";
	std::cin >> w;
	if (!std::cin) { std::cout << "bad"; return 0; }
	
	std::cout << "Depth: ";
	std::cin >> d;
	if (!std::cin) { std::cout << "bad"; return 0; }
	
	std::cout << "Height: ";
	std::cin >> h;
	if (!std::cin) { std::cout << "bad"; return 0; }
	
	std::cout << "Address: ";
	rewind(stdin);
	std::getline(std::cin, A);
	if (!std::regex_search(A, std::regex("([a-zA-Z] ){1,5}[0-90]{1,3}/[0-9]{1,3}"))) {
		std::cout << "bad"; return 0;
	}

	room a1409(N, S, R, W, A, w, d, h);
	
	a1409.printHouse();
	a1409.printSemiDetached();
	a1409.printBlock();
	a1409.printBlockOfFlats();
	a1409.printFlat();
	a1409.printRoom();
}
