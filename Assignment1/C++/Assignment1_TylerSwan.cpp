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
    void get_user() {
        std::cout << (lastName + ", " + firstName + "ID: W00" + std::to_string(id)) << std::endl;
    }

    void debug() {
        get_user();
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
    void search_classes() {
        std::cout << "This will search classes" << std::endl;
    }
    void add_drop_classes() {
        std::cout << "This will add/drop classes" << std::endl;
    }
    void print_schedule() {
        std::cout << "This will print the schedule" << std::endl;
    }
    void debug() {
        get_user();
        search_classes();
        add_drop_classes();
        print_schedule();
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
    void print_class_list() {
        std::cout << "This will search classes" << std::endl;
    }
    void print_schedule() {
        std::cout << "This will print the schedule" << std::endl;
    }
    void search_classes() {
        std::cout << "This will add/drop classes" << std::endl;
    }
    
    void debug() {
        get_user();
        search_classes();
        print_class_list();
        print_schedule();
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
    void add_course() {
        std::cout << "This will add a course" << std::endl;
    }
    void remove_course() {
        std::cout << "This will remove a course" << std::endl;
    }
    void add_remove_class() {
        std::cout << "This will add/remove classes" << std::endl;
    }
    void add_remove_student() {
        std::cout << "This will add/remove students from a course" << std::endl;
    }
    void search_rosters() {
        std::cout << "This will search rosters" << std::endl;
    }
    void search_courses() {
        std::cout << "This will search classes" << std::endl;
    }

    void  debug() {
        get_user();
        add_course();
        remove_course();
        add_remove_class();
        search_rosters();
        search_courses();
    }
};

int prompt_for_usertype();
void create_user(int userInput, User* users);
int menu(User* users);

int main(){
    std::cout << ("\t---Welcome to the User Creation Tool---") << std::endl;
    int userInput = prompt_for_usertype();
    User* users = new User[5];
    create_user(userInput, users);
    while (userInput != 0) {
        userInput = menu(users);
    }
}


int prompt_for_usertype() {
    std::cout << ("To begin what type of user would you like to create?") << std::endl;
    std::cout << ("1. User") << std::endl;
    std::cout << ("2. Student") << std::endl;
    std::cout << ("3. Instructor") << std::endl;
    std::cout << ("4. Admin") << std::endl;
    std::cout << ("0. Exit") << std::endl;
    int userType;
    while (true) {
        try {
            std::cout << ("Input usertype: ");
            std::cin >> userType;
            if (userType >= 0 && userType < 5) {
                return userType;
            }
            else
                throw ("Int out of range");
        }
        catch (...) {
            std::cout << ("Incorrect Input!") << std::endl;
        }
    }
}

void create_user(int userInput, User* users) {
    std::string a;
    std::string b;
    int c;

    if (userInput != 0) {

        std::cout << ("\nYou selected: userType") << std::endl;
        std::cout << ("Enter Credentials seperated by spaces( ) as first last id") << std::endl;

        while (true) {
            try {
                std::cin >> a >> b >> c;
                break;
            }
            catch (...) {
                std::cout << ("Incorrect Input!") << std::endl;
            }
        }

        if (userInput == 1) {
            users[0] = (User(a, b, c));
        }
        if (userInput == 2) {
            users[0] = (Student(a, b, c));
        }
        if (userInput == 3) {
            users[0] = (Instructor(a, b, c));
        }
        if (userInput == 4) {
            users[0] = (Admin(a, b, c));
        }
    }
}

int menu(User* users) {
    std::cout << ("\n------Main Menu------") << std::endl;
    std::cout << ("4. Change credentials") << std::endl;
    std::cout << ("5. Debug(calls all other commands)") << std::endl;
    std::cout << ("0. Exit") << std::endl;
    int userInput;

    while (true) {
        try {
            std::cout << ("Input command: ");
            std::cin >> userInput;
            if (userInput >= 0 && userInput < 6) {
                break;
            }
            else
                throw "Incorrect Input!";
        }
        catch (...) {
            std::cout << ("Incorrect Input!") << std::endl;

        }
    }
    if (userInput == 4) {
        std::string a;
        std::string b;
        int c;
        while (true) {
            try {
                std::cout << ("Syntax: first last id") << std::endl;
                std::cout << ("Input new credentials: ") << std::endl;
                while (true) {
                    try {
                        std::cin >> a >> b >> c;
                        break;
                    }
                    catch (...) {
                        std::cout << ("Incorrect Input!") << std::endl;
                    }
                }
                break;
            }
            catch (...) {
                std::cout <<  ("Incorrect input") << std::endl;
            }
        }
        users[0].set_first(a);
        users[0].set_last(b);
        users[0].set_id(c);
    }

    if (userInput == 5) {
        users[0].debug();
    }
    return userInput;
}

