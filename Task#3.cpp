#include <iostream>
#include <string>
using namespace std;

class Member {
private:
    string name;
    int membershipId;

public:
    Member(string n, int id) : name(n), membershipId(id) {}

    string getName() const {
        return name;
    }

    int getMembershipId() const {
        return membershipId;
    }
};

class Trainer {
private:
    string name;

public:
    Trainer(string n) : name(n) {}

    void train(Member& member) {
        cout << "Trainer " << name << " is training " << member.getName() << endl;
    }
};

int main() {
    Trainer trainer("John");

    Member member1("Alice", 101);
    Member member2("Bob", 102);
    Member member3("Charlie", 103);

    trainer.train(member1);
    trainer.train(member2);
    trainer.train(member3);

    return 0;
}