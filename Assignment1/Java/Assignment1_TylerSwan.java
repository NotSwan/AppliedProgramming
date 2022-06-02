/*Citations
 * https://www.w3schools.com/java/java_constructors.asp
 * https://docs.oracle.com/javase/tutorial/java/javaOO/accesscontrol.html#:~:text=The%20private%20modifier%20specifies%20that,its%20class%20in%20another%20package.
 * https://www.w3schools.com/java/java_inheritance.asp
 * https://www.w3schools.com/java/java_try_catch.asp
 */
import java.util.Scanner;

public class Assignment1_TylerSwan{


    /*  main(String[] args)
     * 
     *  static main function that does simple movement between functions
     *  aswell as storing values input and objects created within 
     *  some of the functions
     */
    Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("\t---Welcome to the User Creation Tool---");
        int userInput = prompt_for_usertype();
        User[] users =  new User[5];
        create_user(userInput, users);
        while(userInput != 0){
            userInput = menu(users);
        }
    }
    /*  menu(User[] users)
     * 
     *  The function containing all logic for entering the needed commands
     *  Now for testing the menu relies on the debug function that calls all others
     *  but when greater functionality is added proper expansion of the commands will be done
     * 
     *  Primary function is handling and restricting of inputs both of commands and for 
     *  additional requirments within called commands
     */
    private static int menu(User[] users){
        System.out.println("\n------Main Menu------");
        System.out.println("4. Change credentials");
        System.out.println("5. Debug(calls all other commands)");
        System.out.println("0. Exit");
        int userInput;

        while(true){
            try {
                Scanner scan = new Scanner(System.in);
                System.out.print("Input command: ");
                userInput = scan.nextInt();
                if(userInput >= 0 && userInput < 6) {
                    break;
                }
                else
                    System.out.println("Incorrect Input!");
            }
            catch (Exception e){
                System.out.println("Incorrect Input!");
                
            }
        }
        if(userInput == 4){
            String a;
            String b;
            int c;
            while(true){
                try{
                    System.out.println("Syntax: first,last,id");
                    System.out.println("Input new credentials: ");
                    while(true){
                        try {
                            Scanner scan = new Scanner(System.in);
                            String temp = scan.nextLine();
                            
                            Scanner interpret = new Scanner(temp);
                            interpret.useDelimiter(",");
                            a = interpret.next();
                            b = interpret.next();
                            c = Integer.parseInt(interpret.next());
                            break;
                        } catch (Exception e) {
                            System.out.println("Incorrect Input!");
                        }
                    }
                    break;
                }
                catch (Exception e){
                    System.out.println("Incorrect input");
                }
            }
            users[0].set_first(a);
            users[0].set_last(b);
            users[0].set_id(c);
        }
        
        if(userInput == 5){
            users[0].debug();
        }
        return userInput;
    }


    /*  prompt_for_usertype()
     * 
     *  prompt and handles the selection of the user type
     * 
     */
    private static int prompt_for_usertype(){
        System.out.println("To begin what type of user would you like to create?");
        System.out.println("1. User");
        System.out.println("2. Student");
        System.out.println("3. Instructor");
        System.out.println("4. Admin");
        System.out.println("0. Exit");
        int userType;
        while(true){
            try {
                Scanner scan = new Scanner(System.in);
                System.out.print("Input usertype: ");
                userType = scan.nextInt();
                if(userType >= 0 && userType < 5) {
                    return userType;
                }
                else
                    throw new ArithmeticException("Int out of range");
            }
            catch (Exception e){
                System.out.println("Incorrect Input!");
                
            }
        }
    }

    /*  create_user()
     * 
     *  once usertype is selected the credentials must be selected 
     *  this is done using two scanners to interpret console input and
     *  to further interpret the string into 3 variables used in intialization
     *  of User and its subclasses
     * 
     */
    private static User[] create_user(int userType, User[] users){
        String a;
        String b;
        int c;

        if(userType != 0){

            System.out.println("\nYou selected: userType");
            System.out.println("Enter Credentials seperated by commas(,) as first,last,id");
            
            while(true){
                try {
                    Scanner scan = new Scanner(System.in);
                    String temp = scan.nextLine();
                    
                    Scanner interpret = new Scanner(temp);
                    interpret.useDelimiter(",");
                    a = interpret.next();
                    b = interpret.next();
                    c = Integer.parseInt(interpret.next());
                    break;
                } catch (Exception e) {
                    System.out.println("Incorrect Input!");
                }
            }
            
            if(userType == 1){
                users[0] = (new User(a,b,c));
            }
            if(userType == 2){
                users[0] = (new Student(a,b,c));
            }   
            if(userType == 3){
                users[0] = (new Instructor(a,b,c));
            }
            if(userType == 4){
                users[0] = (new Admin(a,b,c));
            }
            return users;
        }
        else    
            return users;
    }
}

class User {
    protected String firstName;
    protected String lastName;
    protected int id;

    //Default constructor used typically for quick testing 
    public User() {
        this.firstName = "testFirst";
        this.lastName = "testLast";
        id = 1234;
    }
    //Constructor that initializes with passed values
    public User(String firstName, String lastName, int id) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.id = id;
    }
    //Sets both first and last name in the same call
    public void set_name(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }
    //Sets first name because the variable is private
    public void set_first(String firstName) {
        this.firstName = firstName;
    }
    //Sets last name because the variable is private
    public void set_last(String lastName) {
        this.lastName = lastName;
    }
    //Sets id because the variable is private
    public void set_id(int id) {
        this.id = id;
    }
    //Prints a generalalized format of the objects credentials
    public void get_user() {
        System.out.println("\n" + lastName + ", " + firstName + "\nID: W00" + id);
    }

    public void debug(){
        get_user();
    }
}

class Student extends User {

    Student(){

    }

    Student(String firstName, String lastName, int id){

    }
    //debug function used to save lines when testing 
    public void debug() {
        get_user();
        search_courses();
        add_drop_courses();
        print_schedule();
    }
    //When implemented will
    public void search_courses() {
        System.out.println("This will search courses");
    }
    //When implemented will
    public void add_drop_courses() {
        System.out.println("This will add/drop courses");
    }
    //When implemented will
    public void print_schedule() {
        System.out.println("This will print student schedule");
    }
}

class Instructor extends User {
    Instructor(){

    }

    Instructor(String firstName, String lastName, int id){

    }

    public void debug() {
        get_user();
        search_courses();
        print_course_list();
        print_schedule();
    }
    //When implemented will
    public void search_courses() {
        System.out.println("This will search courses");
    }
    //When implemented will
    public void print_course_list() {
        System.out.println("This will print the instructor's course list");
    }
    //When implemented will
    public void print_schedule() {
        System.out.println("This will print instructor's schedule");
    }
}

class Admin extends User {
    //User type Admin contains ability to add/remove courses and users along with searching courses

    Admin(){

    }

    Admin(String firstName, String lastName, int id){

    }

    public void debug() {
        get_user();
        add_courses();
        remove_courses();
        add_remove_users();
        search_courses();
    }
    //When implemented will add courses
    public void add_courses() {
        System.out.println("This will add courses");
    }

    //When implemented will remove courses
    public void remove_courses() {
        System.out.println("This will remove courses");
    }

    //When implemented will add/remove users
    public void add_remove_users() {
        System.out.println("This will add/remove users");
    }

    //When implemented will print roster of searched class
    public void search_courses() {
        System.out.println("This will print roster of searched class");
    }
}