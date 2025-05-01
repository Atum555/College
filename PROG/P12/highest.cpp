#include <list>
#include <map>
#include <string>

using namespace std;

string student_highest_avg(map<string, list<int>> m) {
    double maxGrade = 0;
    string maxStudent;

    for (auto student : m) {
        auto   grades = student.second;
        double sum    = 0;

        for (auto grade : grades) sum += grade;

        double grade = sum / grades.size();

        if (grade > maxGrade) {
            maxGrade   = grade;
            maxStudent = student.first;
        }
    }
    return maxStudent;
}
