#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
	string name;
	int age;

	Patient(const string& patientName, int patientAge) : name(patientName), age(patientAge) {}
};

class Hospital {
public:
	void admit(const Patient* patient) const {
		cout << "Hospital admits " << patient->name << ", age " << patient->age << endl;
	}
};

int main() {
	Patient patient1("Alice", 30);
	Patient patient2("Bob", 45);

	Hospital hospital;
	hospital.admit(&patient1);
	hospital.admit(&patient2);

	return 0;
}
