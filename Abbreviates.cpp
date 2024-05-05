#include <iostream>
#include <string>
using namespace std;

string abbreviateCode(const string& code) {
    string abbreviation;

    size_t startPos = code.find(" as ") + 4;
    size_t endPos = code.find(", ", startPos);
    string major = code.substr(startPos, endPos - startPos);

    startPos = code.find(", ", endPos + 2) + 2;
    endPos = code.find(", ", startPos);
    string year = code.substr(startPos, endPos - startPos);

    startPos = code.find(", ", endPos + 2) + 2;
    endPos = code.find(", ", startPos);
    string semester = code.substr(startPos, endPos - startPos);

    startPos = code.find(", ", endPos + 2) + 2;
    string course = code.substr(startPos);

    abbreviation += major.substr(0, 3);
    abbreviation += "-" + year.substr(0, 1);
    abbreviation += semester.substr(0, 1);
    abbreviation += " " + course.substr(0, 3);

    return abbreviation;
}

int main() {
    string code = "CSE-3141 as Computer Science & Engineering, 3rd year, 1st semester, compiler design, theory";
    string abbreviation = abbreviateCode(code);

    cout << "Abbreviation: " << abbreviation << endl;

    return 0;
}
