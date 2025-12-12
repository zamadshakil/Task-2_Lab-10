#include <iostream>
#include <string>

class Patient {
public:
	std::string name;
	int age;

	Patient(const std::string& patientName, int patientAge) : name(patientName), age(patientAge) {}
};

class Hospital {
public:
	void admit(const Patient* patient) const {
		std::cout << "Hospital admits " << patient->name << ", age " << patient->age << std::endl;
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
