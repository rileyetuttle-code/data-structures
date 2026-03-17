#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// Define a struct
struct Student {
    string name;
    int score;
};

// Function to generate random scores
int generateScore() {
    static mt19937 rng(time(0));
    uniform_int_distribution<int> dist(50, 100);
    return dist(rng);
}

// Function to print students
void printStudents(const vector<Student>& students) {
    cout << "\n--- Student Scores ---\n";
    for (const auto& s : students) {
        cout << s.name << " -> " << s.score << endl;
    }
}

// Function to calculate average
double calculateAverage(const vector<Student>& students) {
    int sum = 0;
    for (const auto& s : students) {
        sum += s.score;
    }
    return static_cast<double>(sum) / students.size();
}

int main() {
    int n;

    cout << "How many students? ";
    cin >> n;

    vector<Student> students;

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "Enter name for student " << i + 1 << ": ";
        cin >> s.name;
        s.score = generateScore();
        students.push_back(s);
    }

    // Sort students by score (descending)
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });

    printStudents(students);

    cout << "\nClass average: " << calculateAverage(students) << endl;

    cout << "\nTop student: " 
         << students.front().name 
         << " with score " 
         << students.front().score 
         << endl;

    return 0;
}
