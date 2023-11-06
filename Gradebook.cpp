// Logan Phillips
// CS230
// Gradebook Project implementation file

#include "Gradebook.h"

using namespace std;

/*int OpenInputFile(ifstream & inputFile) {
    string fileName;
    cout << "Name of file with grade data: "; 
    cin >> fileName;
    inputFile.open(fileName);
    if (not inputFile) {
        cout << "Unable to open file " << fileName << ".";
        return 0;
    }
}
*/

void GetClassInfo(ifstream & studentData, GradeBookT & c) {

    getline(studentData, c.className);
    studentData >> c.numTests;
    studentData >> c.numHw;

    studentData.ignore(256, '\n');
}

void GetStudentInfo(ifstream & studentData, StudentT & s, GradeBookT & c) {

    getline(studentData, s.studentName);
    studentData >> s.gradeLevel;

    for (int i = 0; i < c.numTests; i++) {
        studentData >> s.testGrades[i];
    }

    for (int i = 0; i < c.numHw; i++) {
        studentData >> s.hwGrades[i];
    }
    studentData.ignore(256, '\n');
}

void PrintClassInfo(GradeBookT & c) {

    cout << c.className << endl;
    cout << c.numTests << endl;
    cout << c.numHw << endl;
}

void PrintStudentInfo(StudentT & s, GradeBookT & c) {

    cout << s.studentName << endl;
    cout << s.gradeLevel << endl;

    for (int i = 0; i < c.numTests; i++) {
        if (i != c.numTests - 1) {
            cout << s.testGrades[i] << " ";
        } else {
            cout << s.testGrades[i] << endl;
        }
    }
    for (int i = 0; i < c.numHw; i++) {
        if (i != c.numHw - 1) {
            cout << s.hwGrades[i] << " ";
        } else {
            cout << s.hwGrades[i] << endl;
        }
    }
    /*while (i != c.numTests -1){
        cout << s.testGrades[i] << " ";
        i++;
    }
    cout << s.testGrades[i] << endl; 
    i = 0;
    //while (i != c.numHw -1){
        cout << s.hwGrades[i] << " ";
        i++;
    }*/
}

void Menu(StudentT & s, GradeBookT & c) {
    int num{0};
    float temp{0};
    cout << "Menu: (Enter 1-4)" << endl;
    cout << endl;
    cout << "1: Show class statistics" << endl;
    cout << "2: List students" << endl;
    cout << "3: List passing students" << endl;
    cout << "4: Exit" << endl;
    cout << endl;
    cout << "Please enter your selection:" << endl;
    cin >> num;

    if (num == 1) {
        temp = Average(s.testGrades, c.numTests);
        cout << temp;
        cout << endl;
        temp = sqrt(temp);
        cout << temp;
        cout << endl;

    } else if (num == 2) {
        cout << endl;
        cout << s.studentName << c.numHw << endl;

    } else if (num == 3) {
    
    } else if (num == 4) {
    
    } else {
        cout << "Please enter 1-4" << endl;
        cin >> num;
    }
} 

float Average(float scores[], int n ) {
    float avg{0};
    for (int i = 0; i < n; i++) {
        avg = avg + scores[i];
    }
    avg = avg / static_cast<float>(n);

    return avg;
}
