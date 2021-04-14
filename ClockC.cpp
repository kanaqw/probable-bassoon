struct Clockofthelongnow {
	
	bool set_year(int year) {
		if (year < 2019) return false;
		this->year = year;
		return true;
	}
	int get_year() {
		return year;
	}
	int year=2020;
};


void add_year(Clockofthelongnow& clock) {
	clock.set_year(clock.get_year() + 1);
	}


int main() {
	Clockofthelongnow clock;
	printf("The year is %d.\n", clock.get_year());
	add_year(clock);
	printf("The year is %d.\n", clock.get_year());
}
