#ifndef ADMISSION_H
#define ADMISSION_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <limits>

class Student {
private:
    std::string name;
    int age;  // Changed to int
    double logicalReasoningMarks;
    double numericalReasoningMarks;
    double verbalAnalysisMarks;
    double essayWritingMarks;
    double entranceScore;
    double tenthGradeMarks;
    double twelfthGradeMarks;
    bool hasExtraCurricular;
    std::string extraCurricular;
    int essayScore;  // Changed to int
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

    // Rest of the class remains the same
};

bool isNumeric(const std::string& str);
bool getValidBoolInput(const std::string& prompt);
int getValidIntInput(const std::string& prompt, int min, int max);
double getValidDoubleInput(const std::string& prompt, double min, double max);
std::string getValidStringInput(const std::string& prompt);

#endif

