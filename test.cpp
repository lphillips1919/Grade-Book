// Logan Phillips
// CS230
// Gradebook Test

#include "Gradebook.h"

using namespace std;

int main()
{
    GradeBookT c[NUMBER_OF_CLASSES];
    StudentT s[NUM_STUDENTS];
    ifstream studentData;
    string fileName;
    //OpenInputFile(studentData);

    cout << "Name of file with grade data: "; 
    cin >> fileName;
    studentData.open(fileName);
    if (not studentData) {
        cout << "Unable to open file " << fileName << ".";
        return 0;
    }

    GetClassInfo(studentData, c[0]);
    GetStudentInfo(studentData, s[0], c[0]);

    /*PrintClassInfo(c[0]);
    cout << endl;
    PrintStudentInfo(s[0], c[0]);*/

    Menu(s[0], c[0]);

    studentData.close();

    return 0;
}