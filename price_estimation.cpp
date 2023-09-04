#include <iostream>
#include <string>

int mileage_check(int *mileage) {
    
    std::string string_mileage;
    std::cout << "Please give me a mileage: ";
    std::cin >> string_mileage ;

    for (int i = 0; string_mileage[i]; i++) {
        if (string_mileage[i]< '0' || string_mileage[i] > '9') {
            std::cout << "Only numbers are allowed" << std::endl;
            return (1);
        }
    }
    *mileage = stoi(string_mileage);
    return (0);
}


int main(int ac, char **av) {
    
    int theta0 = 0;
    int theta1 = 0;
    int mileage = -1;
    while (mileage_check(&mileage));
    std::cout << "The estimated price for a car with " << mileage << " mileage is: " << theta0 + (theta1 * mileage) << std::endl;
}
