###############
#Citations
#https://www.w3schools.com/python/python_inheritance.asp
#
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
        print (self.lastName + ", " + self.firstName + "\nWIT IT: W00" + str(self.id))

class Student(User):
    def __init__(self, firstName = "studentFirst", lastName = "studentLast", id = 1235):
        User.__init__(self, firstName, lastName, id)

    def search_classes(self):
        print ("This will search classes")

    def add_drop_class(self, course):
        print ("This will add/drop sepcified class")

    def print_schedule(self):
        print ("This will print the schedule")

class Instructor(User):
    def __init__(self, firstName = "instructorFirst", lastName = "instructorLast", id = 1236):
        User.__init__(self, firstName, lastName, id)

    def print_schedule(self):
        print ("This will print the schedule")

    def print_course_list(self):
        print ("This will print the course list")

    def search_classes(self):
        print ("This will search classes") 

class Admin(User):
    def __init__(self, firstName = "adminFirst", lastName = "adminLast", id = 1237):
        User.__init__(self, firstName, lastName, id)

    def add_course(self, course):
        print ("This will add/drop sepcified class")

    def remove_course(self, course):
        print ("This will add/drop sepcified class")
    
    def add_remove_student(self, student):
        print ("This will add/remove students")

    def search_course(self):
        print ("This will search courses and print their roster")


def __main__():
    user = User("Fortnite", "Battlepass", 42069)
    user.get_user()
    print()
    student = Student(id=124)
    student.get_user()
    student.print_schedule()
    student.search_classes()
    print()
    instructor = Instructor("Me", "Kill", 666)
    instructor.get_user()
    print()
    admin = Admin()
    admin.get_user()

__main__()