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
    //Private variables 
    std::string firstName;
    std::string lastName;
    int id;

public:
    //Constructors
    User() {
        firstName = "tempFirst";
        lastName = "tempLast";
        id = 1234;
    }
    User(std::string firstName, std::string lastName, int id) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = id;
    }
    //set functions
    void set_first(std::string firstName) {
        this->firstName = firstName;
    }

    void set_last(std::string lastName) {
        this->lastName = lastName;
    }
    void set_id(int id) {
        this->id = id;
    }

    void set_user(std::string firstName, std::string lastName) {
        this->firstName = firstName;
        this->lastName = lastName;
    }

    //get functions
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
    //Constructors
    Student() : User() {

    }
    Student(std::string firstNameIn, std::string lastNameIn, int idIn) : User(firstNameIn, lastNameIn, idIn) {

    }

    //Functions
    std::string search_classes() {
        return "This will search classes";
    }
    std::string add_drop_classes() {
        return "This will add/drop classes";
    }
    std::string print_schedule() {
        return "This will print the schedule";
    }
};

class Instructor : public User {
private:
    bool fillVariableForSchedule = 1;
    bool fillVariableForClassList = 0;
public:
    //Constructors
    Instructor() : User() {

    }
    Instructor(std::string firstNameIn, std::string lastNameIn, int idIn) : User(firstNameIn, lastNameIn, idIn) {

    }

    //Functions
    std::string print_class_list() {
        return "This will search classes";
    }
    std::string print_schedule() {
        return "This will print the schedule";
    }
    std::string search_classes() {
        return "This will add/drop classes";
    }

};

class Admin : public User {
private:
    bool fillVariableForSchedule = 1;
    bool fillVariableForClassList = 0;
public:
    //Constructor
    Admin() : User() {

    }
    Admin(std::string firstNameIn, std::string lastNameIn, int idIn) : User(firstNameIn, lastNameIn, idIn) {

    }

    //Function
    std::string add_course() {
        return "This will add a course";
    }
    std::string remove_course() {
        return "This will remove a course";
    }
    std::string add_remove_user() {
        return "This will add/remove classes";
    }
    std::string add_remove_student() {
        return "This will add/remove students from a course";
    }
    std::string search_rosters() {
        return "This will search rosters";
    }
    std::string search_courses() {
        return "This will search classes";
    }
};

int main(){
    User asdf = User();
    Student fdsa = Student("First Name", "Last Name", 123);
    Instructor sadf = Instructor();
    Admin dfas = Admin();
}
