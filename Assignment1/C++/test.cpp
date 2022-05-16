//Included packages 
#include <iostream>
#include <string>

/* Citations
*https://www.w3schools.com/cpp/cpp_classes.asp
*https://www.w3schools.com/cpp/cpp_class_methods.asp
*https://www.w3schools.com/cpp/cpp_constructors.asp
*https://www.w3schools.com/cpp/cpp_inheritance.asp
*
*
*/
class User {
private:
    std::string firstName;
    std::string lastName;
    int id;

public:
    User() {
        firstName = "tempFirst";
        lastName = "tempLast";
        id = 1234;
    }
    User(std::string firstNameIn, std::string lastNameIn, int idIn) {
        firstName = firstNameIn;
        lastName = lastNameIn;
        id = idIn;
    }

    std::string user_name() {
        return lastName + ", " + firstName;
    }

    std::string getID() {
        return "ID: W00" + std::to_string(id);
    }

};

class Student : public User {
private:
    bool fillVariableForSchedule = 1;
public:
    Student() : User() {

    }
    Student(std::string firstNameIn, std::string lastNameIn, int idIn) : User(firstNameIn, lastNameIn, idIn) {

    }

    std::string search_classes() {
        return "This will search classes";
    }
};

int main(){
    User asdf = User();
    Student fdsa = Student("First Name", "Last Name", 123);

    std::cout << asdf.user_name() << " & " << asdf.getID() << std::endl;

    std::cout << fdsa.getID() << " & " << fdsa.search_classes() << " & " << fdsa.user_name();
}

