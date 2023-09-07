#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <limits>

class Student {
private:
    std::string name;
    int age;
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

public:
    // Constructor
    Student(const std::string& n, int a,
        double lrMarks, double nrMarks, double vaMarks, double essayMarks,
        double entrance, double tenth, double twelfth, bool extraCurriculars,
        const std::string& ec, int es, const std::string& tgs, const std::string& tgs12, bool rec)
        : name(n), age(a), logicalReasoningMarks(lrMarks),
        numericalReasoningMarks(nrMarks), verbalAnalysisMarks(vaMarks),
        essayWritingMarks(essayMarks), entranceScore(entrance), tenthGradeMarks(tenth),
        twelfthGradeMarks(twelfth), hasExtraCurricular(extraCurriculars),
        extraCurricular(ec), essayScore(es), tenthGradeSchool(tgs), twelfthGradeSchool(tgs12),
        teacherRecommendation(rec) {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getLogicalReasoningMarks() const {
        return logicalReasoningMarks;
    }

    double getNumericalReasoningMarks() const {
        return numericalReasoningMarks;
    }

    double getVerbalAnalysisMarks() const {
        return verbalAnalysisMarks;
    }

    double getEssayWritingMarks() const {
        return essayWritingMarks;
    }

    double getEntranceScore() const {
        return entranceScore;
    }

    double getTenthGradeMarks() const {
        return tenthGradeMarks;
    }

    double getTwelfthGradeMarks() const {
        return twelfthGradeMarks;
    }

    bool isEligible() const {
        return logicalReasoningMarks >= 70.0 && numericalReasoningMarks >= 70.0 &&
            verbalAnalysisMarks >= 70.0 && age >= 18 && age <= 21;
    }

    bool isAdmitted() const {
        return entranceScore >= 80.0 && tenthGradeMarks >= 70.0 &&
            twelfthGradeMarks >= 75.0 && hasExtraCurricular;
    }

    bool hasPositiveTeacherRecommendation() const {
        return teacherRecommendation;
    }
};

bool isNumeric(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

bool getValidBoolInput(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::cin >> input;
        if (input == "true" || input == "false") {
            return input == "true";
        } else {
            std::cout << "Invalid input. Enter 'true' or 'false'." << std::endl;
        }
    }
}

int getValidIntInput(const std::string& prompt, int min, int max) {
    while (true) {
        std::cout << prompt;
        int value;
        std::cin >> value;

        if (std::cin.fail()) {
            // Handle invalid input (non-integer)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        } else if (value >= min && value <= max) {
            return value;
        } else {
            std::cout << "Invalid input. Enter an integer between " << min << " and " << max << "." << std::endl;
        }
    }
}

double getValidDoubleInput(const std::string& prompt, double min, double max) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::cin >> input;

        if (isNumeric(input)) {
            double value = std::stod(input);
            if (value >= min && value <= max) {
                return value;
            }
        }

        std::cout << "Invalid input. Enter a number between " << min << " and " << max << "." << std::endl;
    }
}

std::string getValidStringInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::cin.ignore();
        std::getline(std::cin, input);
        if (!input.empty()) {
            return input;
        } else {
            std::cout << "Invalid input. Please enter a non-empty string." << std::endl;
        }
    }
}

int main() {
    std::string name;
    int age;
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
    std::cin >> age;

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

