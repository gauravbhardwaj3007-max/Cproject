#include <stdio.h>
#include <string.h>

// Define a constant for string buffer size
#define MAX_ADDR_LEN 100

// Define the union for address components
union AddressDetails {
    char name[MAX_ADDR_LEN];
    char home_address[MAX_ADDR_LEN];
    char hostel_address[MAX_ADDR_LEN];
    char city[MAX_ADDR_LEN];
    char state[MAX_ADDR_LEN];
    char zip[MAX_ADDR_LEN];
};

int main() {
    union AddressDetails currentAddress;

    // Example 1: Displaying home address
    printf("--- Displaying Home Address ---\n");
    strcpy(currentAddress.name, "John Doe"); // This will overwrite previous data
    strcpy(currentAddress.home_address, "123 Main St");
    strcpy(currentAddress.city, "Anytown"); // This will overwrite previous data
    strcpy(currentAddress.state, "CA");
    strcpy(currentAddress.zip, "90210");

    // Only the last assigned member (zip in this case) and potentially home_address might be valid.
    // To display the full address, assign and print each part consecutively.
    printf("Name: %s\n", currentAddress.name); // This might show corrupted data due to union
    printf("Home Address: %s\n", currentAddress.home_address); // This might show corrupted data due to union
    printf("City: %s\n", currentAddress.city); // This might show corrupted data due to union
    printf("State: %s\n", currentAddress.state); // This might show corrupted data due to union
    printf("Zip: %s\n", currentAddress.zip); // This might show corrupted data due to union

    printf("\n--- Displaying Hostel Address ---\n");
    // To correctly display an address, each component needs to be assigned and then printed.
    // Since a union shares memory, assigning to one member invalidates others.
    // Therefore, to print a complete address, we would typically use a struct.
    // However, adhering to the union requirement:
    strcpy(currentAddress.name, "Jane Smith");
    strcpy(currentAddress.hostel_address, "Room 404, University Dorms");
    strcpy(currentAddress.city, "Collegeville");
    strcpy(currentAddress.state, "NY");
    strcpy(currentAddress.zip, "10001");

    // Again, due to union's shared memory, only the last assigned member is guaranteed valid.
    printf("Name: %s\n", currentAddress.name);
    printf("Hostel Address: %s\n", currentAddress.hostel_address);
    printf("City: %s\n", currentAddress.city);
    printf("State: %s\n", currentAddress.state);
    printf("Zip: %s\n", currentAddress.zip);

    return 0;
}