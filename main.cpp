#include <iostream>
#include "admission.h"

int main() {
    std::string name;
    std::string ageStr;  // Change to directly ask for age as a string
    int age;  // Declare 'age' variable here
    double logicalReasoningMarks;
    double numericalReasoningMarks;
    double verbalAnalysisMarks;
    double essayWritingMarks;
    double entranceScore;
    double tenthGradeMarks;
    double twelfthGradeMarks;
    bool hasExtraCurricular;
    std::string extraCurricular;
    int essayScore;
    std::string tenthGradeSchool;
    std::string twelfthGradeSchool;
    bool teacherRecommendation;

    std::cout << "Enter student's name: ";
    std::getline(std::cin, name);

    // Prompt for age directly
    std::cout << "Enter student's age: ";
    std::getline(std::cin, ageStr);

    age = std::stoi(ageStr);

    logicalReasoningMarks = getValidDoubleInput("Enter student's logical reasoning marks (0-100): ", 0.0, 100.0);
    numericalReasoningMarks = getValidDoubleInput("Enter student's numerical reasoning marks (0-100): ", 0.0, 100.0);
    verbalAnalysisMarks = getValidDoubleInput("Enter student's verbal analysis marks (0-100): ", 0.0, 100.0);
    essayWritingMarks = getValidDoubleInput("Enter student's essay writing marks (0-100): ", 0.0, 100.0);

    entranceScore = (logicalReasoningMarks + numericalReasoningMarks + verbalAnalysisMarks + essayWritingMarks) / 4.0;

    tenthGradeMarks = getValidDoubleInput("Enter student's 10th grade marks (0-100): ", 0.0, 100.0);
    twelfthGradeMarks = getValidDoubleInput("Enter student's 12th grade marks (0-100): ", 0.0, 100.0);

    hasExtraCurricular = getValidBoolInput("Does the student have any extra-curricular activities? (true/false): ");

    if (hasExtraCurricular) {
        std::cout << "Enter the type of extra-curricular activities (social service/internship/sports-music): ";
        std::cin >> extraCurricular;
    } else {
        extraCurricular = "None";
    }

    essayScore = getValidIntInput("Enter student's essay score (0-100): ", 0, 100);

    std::cin.ignore(); // Clear the newline character from the previous input

    std::cout << "Enter the name of the 10th grade school: ";
    std::getline(std::cin, tenthGradeSchool);

    std::cout << "Enter the name of the 12th grade school: ";
    std::getline(std::cin, twelfthGradeSchool);

    teacherRecommendation = getValidBoolInput("Did the student receive positive teacher recommendations? (true/false): ");

    // Create a Student object
    Student student(name, age, logicalReasoningMarks,
        numericalReasoningMarks, verbalAnalysisMarks, essayWritingMarks,
        entranceScore, tenthGradeMarks, twelfthGradeMarks,
        hasExtraCurricular, extraCurricular, essayScore,
        tenthGradeSchool, twelfthGradeSchool, teacherRecommendation);

    // Display admission status
    std::cout << "\nAdmission Status for " << student.getName() << ":\n";
    std::cout << "Age: " << student.getAge() << " years" << std::endl;
    std::cout << "Logical Reasoning Marks: " << student.getLogicalReasoningMarks() << std::endl;
    std::cout << "Numerical Reasoning Marks: " << student.getNumericalReasoningMarks() << std::endl;
    std::cout << "Verbal Analysis Marks: " << student.getVerbalAnalysisMarks() << std::endl;
    std::cout << "Essay Writing Marks: " << student.getEssayWritingMarks() << std::endl;

    if (student.isEligible()) {
        std::cout << "Eligibility: Eligible for acceptance into the next stage." << std::endl;
    } else {
        std::cout << "Eligibility: Not eligible for acceptance into the next stage." << std::endl;
        std::cout << "Sorry, you are not admitted to the university." << std::endl;
        return 0; // Exit the program
    }

    // Check admission status
    if (student.isAdmitted()) {
        std::cout << "Admission Status: Congratulations! You are admitted to the university." << std::endl;
    } else {
        std::cout << "Admission Status: Sorry, you are not admitted to the university." << std::endl;
    }

    return 0;
}

