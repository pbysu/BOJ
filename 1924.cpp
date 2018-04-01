#include <iostream>

using namespace std;

int main() {
	int x, y, rem;
	cin >> x >> y;
	rem = y % 7;

	switch (x) {

	case 1:
		switch (rem) {

		case 0:
			cout << "SUN";
			break;
		case 1:
			cout << "MON";
			break;
		case 2:
			cout << "TUE";
			break;
		case 3:
			cout << "WED";
			break;
		case 4:
			cout << "THU";
			break;
		case 5:
			cout << "FRI";
			break;
		case 6:
			cout << "SAT";
			break;
		}

		break;

	case 2:
		switch (rem) {

		case 0:
			cout << "WED";
			break;
		case 1:
			cout << "THU";
			break;
		case 2:
			cout << "FRI";
			break;
		case 3:
			cout << "SAT";
			break;
		case 4:
			cout << "SUN";
			break;
		case 5:
			cout << "MON";
			break;
		case 6:
			cout << "TUE";
			break;
		}

		break;

	case 3:
		switch (rem) {

		case  0:
			cout << "WED";
			break;
		case  1:
			cout << "THU";
			break;
		case 2:
			cout << "FRI";
			break;
		case 3:
			cout << "SAT";
			break;
		case 4:
			cout << "SUN";
			break;
		case 5:
			cout << "MON";
			break;
		case 6:
			cout << "TUE";
			break;
		}

		break;

	case 4:
		switch (rem) {

		case 1:
			cout << "SUN";
			break;
		case 2:
			cout << "MON";
			break;
		case 3:
			cout << "TUE";
			break;
		case 4:
			cout << "WED";
			break;
		case 5:
			cout << "THU";
			break;
		case 6:
			cout << "FRI";
			break;
		case 0:
			cout << "SAT";
			break;
		}
		break;

	case 5:
		switch (rem) {

		case 6:
			cout << "SUN";
			break;
		case 0:
			cout << "MON";
			break;
		case  1:
			cout << "TUE";
			break;
		case  2:
			cout << "WED";
			break;
		case  3:
			cout << "THU";
			break;
		case 4:
			cout << "FRI";
			break;
		case 5:
			cout << "SAT";
			break;
		}
		break;

	case 6:
		switch (rem) {

		case  3:
			cout << "SUN";
			break;
		case  4:
			cout << "MON";
			break;
		case 5:
			cout << "TUE";
			break;
		case 6:
			cout << "WED";
			break;
		case 0:
			cout << "THU";
			break;
		case 1:
			cout << "FRI";
			break;
		case 2:
			cout << "SAT";
			break;
		}
		break;

	case 7:
		switch (rem) {

		case 1:
			cout << "SUN";
			break;
		case 2:
			cout << "MON";
			break;
		case 3:
			cout << "TUE";
			break;
		case 4:
			cout << "WED";
			break;
		case 5:
			cout << "THU";
			break;
		case 6:
			cout << "FRI";
			break;
		case 0:
			cout << "SAT";
			break;
		}
		break;

	case 8:
		switch (rem) {

		case 5:
			cout << "SUN";
			break;
		case 6:
			cout << "MON";
			break;
		case 0:
			cout << "TUE";
			break;
		case 1:
			cout << "WED";
			break;
		case 2:
			cout << "THU";
			break;
		case 3:
			cout << "FRI";
			break;
		case 4:
			cout << "SAT";
			break;
		}
		break;

	case 9:
		switch (rem) {

		case 2:
			cout << "SUN";
			break;
		case 3:
			cout << "MON";
			break;
		case 4:
			cout << "TUE";
			break;
		case 5:
			cout << "WED";
			break;
		case 6:
			cout << "THU";
			break;
		case 0:
			cout << "FRI";
			break;
		case 1:
			cout << "SAT";
			break;
		}
		break;

	case 10:
		switch (rem) {

		case 0:
			cout << "SUN";
			break;
		case 1:
			cout << "MON";
			break;
		case 2:
			cout << "TUE";
			break;
		case 3:
			cout << "WED";
			break;
		case 4:
			cout << "THU";
			break;
		case 5:
			cout << "FRI";
			break;
		case 6:
			cout << "SAT";
			break;
		}
		break;

	case 11:
		switch (rem) {

		case 0:
			cout << "WED";
			break;
		case 1:
			cout << "THU";
			break;
		case 2:
			cout << "FRI";
			break;
		case 3:
			cout << "SAT";
			break;
		case 4:
			cout << "SUN";
			break;
		case 5:
			cout << "MON";
			break;
		case 6:
			cout << "TUE";
			break;
		}

		break;
	case 12:
		switch (rem) {

		case 2:
			cout << "SUN";
			break;
		case 3:
			cout << "MON";
			break;
		case 4:
			cout << "TUE";
			break;
		case 5:
			cout << "WED";
			break;
		case 6:
			cout << "THU";
			break;
		case 0:
			cout << "FRI";
			break;
		case 1:
			cout << "SAT";
			break;
		}
		break;
	}
	cout << endl;
}