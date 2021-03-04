//Design a class that holds the following personal data: name, address, age, and phone number.
//Write appropriate accessor and mutator functions. Demonstrate the class by writing a program that creates three instances of it. One instance should hold your information, and the other two should hold your friends' or family members' information.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class PersonalInfo {
private:
    string name, address, phoneNum;
    int age;

public:
    void setName(string n) { name = n; }
    void setAddress(string add) { address = add; }
    void setPhoneNum(string num) { phoneNum = num; }
    void setAge(int a) { age = a; }

    string getName()const { return name; }
    string getAddress()const { return address; }
    string getPhoneNum()const { return phoneNum; }
    int getAge()const { return age; }

    void getData() {
        cout << "Name? ";
        cin >> name;
        getline(cin, name);
        cout << "Age? ";
        cin >> age;
        cin.ignore();
        cout << "Address? ";
        cin >> address;
        getline(cin, address);
        cout << "Phone number? ";
        getline(cin, phoneNum);


    }

    void dispData()
    {
        cout << "Name is " << name << endl;
        cout << "Age is " << age << endl;
        cout << "Address is " << address << endl;
        cout << "Phone number is " << phoneNum << endl;
    }
};

int main()
{
    PersonalInfo myInfo;
    PersonalInfo InfoPerson2;
    PersonalInfo InfoPerson3;

    cout << "Enter your info" << endl;
    myInfo.getData();

    cout << "\nEnter Person2 info" << endl;
    InfoPerson2.getData();

    cout << "\nEnter Person3 info" << endl;
    InfoPerson3.getData();

    cout << "\nYour info " << endl;
    myInfo.dispData();

    cout << "\nPerson 2 info " << endl;
    InfoPerson2.dispData();

    cout << "\nPerson 3 info " << endl;
    InfoPerson3.dispData();

    cout << "\n";

    return 0;

}

