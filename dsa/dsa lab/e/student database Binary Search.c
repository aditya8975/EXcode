#include <stdio.h>

// Structure to represent a student
struct Student {
    int roll_no;
    char name[50];
    float percentage;
};

// Function to perform binary search on the student array
int binary_search(struct Student student_list[], int size, int target_roll_no) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int mid_roll_no = student_list[mid].roll_no;

        if (mid_roll_no == target_roll_no) {
            return mid;
        } else if (mid_roll_no < target_roll_no) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Not found
}

int main() {
    // Creating a sample student database
    struct Student students[] = {
        {101, "Alice", 85.5},
        {102, "Bob", 92.3},
        {103, "Charlie", 78.9},
        {104, "David", 91.2},
        {105, "Eva", 88.7},
    };

    // Calculating the size of the student array
    int size = sizeof(students) / sizeof(students[0]);

    // Sorting the student list based on roll numbers (if not already sorted)
    // (Note: This step may be unnecessary if the data is initially sorted)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                // Swap the students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Taking input for the roll number to search
    int target_roll_no;
    printf("Enter the roll number to search: ");
    scanf("%d", &target_roll_no);

    // Performing binary search
    int index = binary_search(students, size, target_roll_no);

    // Displaying the result
    if (index != -1) {
        printf("Student found - Roll No: %d, Name: %s, Percentage: %.2f\n", students[index].roll_no, students[index].name, students[index].percentage);
    } else {
        printf("Student with Roll No %d not found.\n", target_roll_no);
    }

    return 0;
}
