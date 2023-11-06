// Logan Phillips
// CS230
// Gradebook header file
#ifndef STUDENT_T
#define STUDENT_T

#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<iomanip>

const int NUMBER_OF_CLASSES = 5;
const int MAX_TEST_GRADES = 5;
const int NUM_STUDENTS = 40;
const int MAX_HW_GRADES = 40;

struct GradeBookT {
    std::string className;
    int numTests;
    int numHw;
};

struct StudentT {
    std::string studentName{""};
    int gradeLevel{0};
    float testGrades[MAX_TEST_GRADES]{0};
    float hwGrades[MAX_HW_GRADES]{0};
    float finalGrade{0};
};

//int OpenInputFile(std:: ifstream & inputFile);

void GetClassInfo (std::ifstream & studentData, GradeBookT & c);
void GetStudentInfo(std::ifstream & studentData, StudentT & s, GradeBookT & c);

void PrintClassInfo(GradeBookT & c);
void PrintStudentInfo(StudentT & s, GradeBookT & c);

void Menu(StudentT & s, GradeBookT & c);

float Average(float scores[], int n );



#endif