#include <iostream>
#include <cstdio>


struct Clockofthelongnow {

	bool set_year(int year) {
		if (year < 2019) return false;
		this->year = year;
		return true;
	}
	int get_year() const {
		return year;
	}
	int year = 2020;
};


void add_year(Clockofthelongnow& clock) {
	clock.set_year(clock.get_year() + 1);
}

bool is_leap_year(const Clockofthelongnow& clock) {
	if (clock.get_year() % 4 > 0)return false;
	if (clock.get_year() % 100 > 0)return true;
	if (clock.get_year() % 400 > 0) return false;
	return true;
}

int main() {
	Clockofthelongnow clock;
	printf("The year is %d.\n", clock.get_year());
	add_year(clock);
	printf("The year is %d.\n", clock.get_year());
}
