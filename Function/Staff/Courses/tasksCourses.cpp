#include "../staff.h"

void tasksCourses(string &existSemester, string &year, string &year_semester, string &semester) {
    createTitle("COURSES");
    cout << "\n1. Courses and Edit";
    cout << "\n2. Back";
    cout << "\nYour choice is : ";
    int choose;
    cin >> choose;
    if (choose == 1) courseAndEdit(existSemester, year, year_semester, semester);
    else semesterAndEdit(existSemester, year);
}

void courseAndEdit(string &existSemester, string &year, string &year_semester, string &semester) {
    string existCourse = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/existCourse.txt";

    //open file named "existCourse.txt"
    ifstream in;
    in.open(existCourse);

    //get number of courses in this file
    int numberOfCourse = 0;
    string s, t;
    while (getline(in, s)) ++numberOfCourse;
    in.close();

    cout << "\n";

    string* arr = new string[numberOfCourse];
    string* tmp = new string[numberOfCourse];
    in.open(existCourse);
    int i = 0;
    while (!in.eof()) {
        // take the courses ID
        in >> s;
        arr[i] = s;
        ++i;
        getline(in, s);
    }
    in.close();

    in.open(existCourse);
    int n = 0;
    while (!in.eof()) {
        // print out all courses
        getline(in, t);
        tmp[n] = t;
        ++n;
    }
    in.close();

    //print out to terminal
    cout << " * Choose course and view its details :\n";
    for (i = 0; i < numberOfCourse; ++i) cout << i + 1 << ". " << tmp[i] << "\n";

    cout << "\n * Tasks :";
    cout << "\n" << ++i << ". Edit";
    cout << "\n" << ++i << ". Back";
    cout << "\nYour choice is : ";
    
    int choose;
    cin >> choose;
    if (choose == numberOfCourse + 1) {
        delete[] tmp;
        delete[] arr;
        editCourse(existSemester, year, year_semester, semester); // go to edit function
    }
    else if (choose == numberOfCourse + 2) {
        delete[] tmp;
        delete[] arr;
        tasksCourses(existSemester, year, year_semester, semester); // back to tasks function of Course
    }
    else if (choose <= numberOfCourse && choose >= 1) {
        string course = arr[choose - 1];
        delete[] tmp;
        delete[] arr;
        int order = choose;
        courseDetails(existSemester, year, year_semester, course, order, semester);
    }
}

void courseDetails(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester) {
    createTitle(course);
    cout << "\n1. Information";
    cout << "\n2. Students";
    cout << "\n3. Back";
    cout << "\nYour choice is : ";
    int choice;
    cin >> choice;
    if (choice == 1) informationCourse(existSemester, year, year_semester, course, order, semester);
    //else if (choice == 2)
    else courseAndEdit(existSemester, year, year_semester, semester);
}

void informationCourse(string &existSemester, string &year, string &year_semester, string &course, int &order, string &semester) {
    ifstream in;
    string courseInfo = "DataSet/SchoolYear/" + year + "/" + semester + "/" + year_semester + "/courseInfo.txt";
    in.open(courseInfo);

    string choice = to_string(order);
    string nextChoice = to_string(order + 1);
    string s;

    while (!in.eof()) {
        getline(in, s);
        if (s == choice) {
            createTitle("INFORMATION");
            cout << '\n';
            while (getline(in, s)) {
                if (s == nextChoice) break;
                cout << s << '\n';
            }
            break;
        }
    }

    cout << "* Tasks : ";
    cout << "\n1. Edit";
    cout << "\n2. Back";
    cout << "\nYour choice is: ";
    int ans;
    cin >> ans;
    if (ans == 1) editCourse(existSemester, year, year_semester, semester);
    else courseDetails(existSemester, year, year_semester, course, order, semester);
}