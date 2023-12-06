#include <stdio.h>

// Structure to represent a student
struct Student {
    int roll_no;
    char name[50];
    float percentage;
};

// Function to perform bubble sort on the student array based on percentage
void bubble_sort(struct Student student_list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (student_list[j].percentage < student_list[j + 1].percentage) {
                // Swap the students
                struct Student temp = student_list[j];
                student_list[j] = student_list[j + 1];
                student_list[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Creating a sample student database
    struct Student students[] = {
        {101, "Alice", 85.5},
        {102, "Bob", 92.3},
        {103, "Charlie", 78.9},
        {104, "David", 91.2},
        {105, "Eva", 88.7},
        // Add more students as needed
    };

    // Calculating the size of the student array
    int size = sizeof(students) / sizeof(students[0]);

    // Performing bubble sort based on percentage in descending order
    bubble_sort(students, size);

    // Displaying the details of the top ten students
    printf("Top Ten Students:\n");
    for (int i = 0; i < 10 && i < size; i++) {
        printf("Roll No: %d, Name: %s, Percentage: %.2f\n", students[i].roll_no, students[i].name, students[i].percentage);
    }

    return 0;
}
