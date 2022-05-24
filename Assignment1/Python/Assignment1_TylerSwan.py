###############
#Citations
#https://www.w3schools.com/python/python_inheritance.asp
#https://stackoverflow.com/questions/23326099/how-can-i-limit-the-user-input-to-only-integers-in-python
#
###############
class User:
   
    def __init__(self, firstName = "testFirst", lastName = "testLast", id = 1234):
        self.firstName = firstName
        self.lastName = lastName
        self.id = id

    def set_first(self, firstName):
        self.firstName = firstName
    
    def set_last(self, lastName):
        self.lastName = lastName

    def set_name(self, firstName, lastName):
        self.firstName = firstName
        self.lastName = lastName
    
    def set_id(self, id):
        self.id = id
    
    def get_user(self):
        print (self.lastName + ", " + self.firstName + "\nWIT ID: W00" + str(self.id))

class Student(User):
    def __init__(self, firstName = "studentFirst", lastName = "studentLast", id = 1235):
        User.__init__(self, firstName, lastName, id)

    def debug(self):
        self.get_user()
        self.search_classes()
        self.add_drop_class()
        self.print_schedule()

    def search_classes(self):
        print ("This will search classes")

    def add_drop_class(self):
        print ("This will add/drop sepcified class")

    def print_schedule(self):
        print ("This will print the schedule")

class Instructor(User):
    def __init__(self, firstName = "instructorFirst", lastName = "instructorLast", id = 1236):
        User.__init__(self, firstName, lastName, id)

    def debug(self):
        self.get_user()
        self.print_course_list()
        self.print_schedule()
        self.search_classes()

    def print_schedule(self):
        print ("This will print the schedule")

    def print_course_list(self):
        print ("This will print the course list")

    def search_classes(self):
        print ("This will search classes") 

class Admin(User):
    def __init__(self, firstName = "adminFirst", lastName = "adminLast", id = 1237):
        User.__init__(self, firstName, lastName, id)

    def debug(self):
        self.get_user()
        self.add_course()
        self.remove_course()
        self.add_remove_student()
        self.search_classes()

    def add_course(self, course):
        print ("This will add specified class")

    def remove_course(self, course):
        print ("This will remove specified class")
    
    def add_remove_student(self, student):
        print ("This will add/remove students")

    def search_course(self):
        print ("This will search courses and print their roster")



def prompt_for_usertype():
    print("To begin what type of user would you like to create?")
    print("1. User")
    print("2. Student")
    print("3. Instructor")
    print("4. Admin")
    print("0. Exit")

    while True:
        try:
            userType = int(input("Input num: "))
            if(userType >= 0 and userType < 5):
                return userType
            else:
                raise Exception("IntegerOutOfRange")
        except:
            print("Invalid input!")

def create_user(userType, users):
    if(userType != 0):
        print(f"\nYou selected: {userTypeDict.get(userType)}")
        print("Enter Credentials seperated by commas(,) as first,last,id")
        
        while True:
            try:
                a,b,c = input("Input:").split(",")
                int(c)
                break
            except:
                print("Invalid input")
        if(userType == 1):
            users.append(User(a,b,c))
        if(userType == 2):
            users.append(Student(a,b,c))
        if(userType == 3):
            users.append(Instructor(a,b,c))
        if(userType == 4):
            users.append(Admin(a,b,c))

def menu():
    print("Main Menu")
    print("5. Debug(calls all other commands)")
    print("0. Exit")

    while True:
        try:
            userType = int(input("Input num: "))
            if(userType >= 0 and userType < 6):
                break
            else:
                raise Exception("IntegerOutOfRange")
        except:
            print("Invalid input!")

    users[0].debug()
    return userType


if __name__ == '__main__':
    global userTypeDict 
    userTypeDict= {
        1: "User",
        2: "Student",
        3: "Instructor",
        4: "Admin"
    }

    print("\t---Welcome to the User Creation Tool---")
    userInput = prompt_for_usertype()
    users = list()
    create_user(userInput, users)
    
    while userInput != 0:
        userInput = menu()
        
    print("Exiting...")