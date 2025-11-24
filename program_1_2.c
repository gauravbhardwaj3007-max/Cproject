#include <stdio.h>

// Define a structure to hold employee data
struct Employee {
    char name[50];
    float basic_pay;
    float da;
    float gross_salary;
};

int main() {
    // Declare an array of 100 employee structures
    struct Employee employees[100];
    int i;

    printf("--- Monthly Pay Calculation for 100 Employees ---\n");

    // Loop to get details and calculate for each employee
    for (i = 0; i < 100; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);

        // Get employee name
        printf("Enter name: ");
        scanf("%s", employees[i].name);

        // Get basic pay
        printf("Enter basic pay: ");
        scanf("%f", &employees[i].basic_pay);

        // Calculate DA (52% of basic pay)
        employees[i].da = 0.52 * employees[i].basic_pay;

        // Calculate gross salary (basic pay + DA)
        employees[i].gross_salary = employees[i].basic_pay + employees[i].da;

        // Print name and gross salary for the current employee
        printf("Employee Name: %s\n", employees[i].name);
        printf("Gross Salary: %.2f\n\n", employees[i].gross_salary);
    }

    printf("--- Calculation complete ---\n");

    return 0;
}

