/*Citations
 *https://www.w3schools.com/java/java_constructors.asp
 *https://docs.oracle.com/javase/tutorial/java/javaOO/accesscontrol.html#:~:text=The%20private%20modifier%20specifies%20that,its%20class%20in%20another%20package.
 *https://www.w3schools.com/java/java_inheritance.asp
 */
public class Assignment1_TylerSwan{
    public static void main(String[] args) {
        User x = new User();
        System.out.println(x.get_user());

        Student y = new Student();
        System.out.println(y.get_user());
    }
}

class User {
    protected String firstName;
    protected String lastName;
    protected int id;

    public User() {
        this.firstName = "testFirst";
        this.lastName = "testLast";
        id = 1234;
    }
    
    public User(String firstName, String lastName, int id) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.id = id;
    }

    public void set_name(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public void set_first_name(String firstName) {
        this.firstName = firstName;
    }

    public void set_last_name(String lastName) {
        this.lastName = lastName;
    }

    public void set_id(int id) {
        this.id = id;
    }

    public String get_user() {
        return (lastName + ", " + firstName + "\nID: W00" + id);
    }
}

class Student extends User {

    public void search_courses() {
        System.out.println("This will search courses");
    }
    public void add_drop_courses() {
        System.out.println("This will add/drop courses");
    }
    public void print_schedule() {
        System.out.println("This will print student schedule");
    }
}

class Instructor extends User {

    public void search_courses() {
        System.out.println("This will search courses");
    }
    public void print_course_list() {
        System.out.println("This will print the instructor's course list");
    }
    public void print_schedule() {
        System.out.println("This will print instructor's schedule");
    }
}

class Admin extends User {

    public void add_courses() {
        System.out.println("This will add courses");
    }

    public void remove_courses() {
        System.out.println("This will remove courses");
    }

    public void add_remove_users() {
        System.out.println("This will add/remove users");
    }

    public void search_courses() {
        System.out.println("This will print roster of searched class");
    }
}