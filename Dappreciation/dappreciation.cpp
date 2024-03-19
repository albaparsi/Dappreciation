#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
/*the car_has_primium_options finction's job is to ask a the user this question,"Does your car have premium options (yes/no)?"
* then the function gets the value which is yes or no and returns a boolean value. when the user says yes he value of the boolean is true
* and when the user says no the value of the boolean is false.
*/
bool car_has_premium_options() {
  std::string has_options_string{""}; //creating a string variable for when the user inputs yes or no
  std::cout << "Does your car have premium options (yes/no)? "; // promting the user for this question
  std::cin >> has_options_string; // using cin to get the answer from the user
  if (has_options_string == "yes") { // using an if statement to returning a boolean. if has_options_string is equal to yes it returns true and if it's not
    return true;                     //equal to yes then it returns false. 
  } else {
    return false;
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

/*
The purpose of this program is to prompt the user to get the year that the car was built and calculate the age of the car.
Prompts the user and get the number of accidents that the car has had. 
To ask the user if the car has premium option and to calculate the final resale value of the car based on the information that user gave.
The program is able to tell the user if the car is not eligible for reselling.
*/
/*The purpose of the main function is to first call the car model year function. 
Calculate the age of the car.
Call the car accidents function.
Call the car has premium options function.
Call the car msrp function.
Calculate the resale value if possible and display a message. 
The main function uses if statements.
*/
int main() {
    double total_percentage = 0;
    double baseline_resale_percentage = 0;
    int year = car_model_year();
    const int CURRENT_YEAR = 2023;
    int age = CURRENT_YEAR - year;
    bool eligibility = true;
    const  double TIER_ONE_BASELINE_RESALE_PERCENTAGE{ 85 };
    const double TIER_TWO_BASELINE_RESALE_PERCENTAGE{ 63 };
    const double TIER_THREE_BASELINE_RESALE_PERCENTAGE{ 45 };
    const  double TIER_ONE_WRECK_PENALTY_PERCENTAGE{ 0 };
    const  double TIER_TWO_WRECK_PENALTY_PERCENTAGE{ 2 };
    const  double TIER_THREE_WRECK_PENALTY_PERCENTAGE{ 10 };
    const  double TIER_FOUR_WRECK_PENALTY_PERCENTAGE{ 20 };
    const double TIER_ONE_PREMiUM_PERCENTAGE{ 5 };
    const double TIER_TWO_PREMiUM_PERCENTAGE{ 0 };


    if (age >= 0 && age <= 4) {
        baseline_resale_percentage = TIER_ONE_BASELINE_RESALE_PERCENTAGE;
    }
    else if (age >= 5 && age <= 8) {
        baseline_resale_percentage = TIER_TWO_BASELINE_RESALE_PERCENTAGE;
    }
    else if (age == 9 || age == 10) {
        baseline_resale_percentage = TIER_THREE_BASELINE_RESALE_PERCENTAGE;
    }
    else {
        eligibility = false;
    }

    int wrecks = 0;
    int wreck_penalty_percentage = 0;
    wrecks = car_accidents();
    if (wrecks == 0) {
        wreck_penalty_percentage = TIER_ONE_WRECK_PENALTY_PERCENTAGE;
    }
    else if (wrecks == 1) {
        wreck_penalty_percentage = TIER_TWO_WRECK_PENALTY_PERCENTAGE;
    }
    else if (wrecks == 2) {
        wreck_penalty_percentage = TIER_THREE_WRECK_PENALTY_PERCENTAGE;
    }
    else if (wrecks == 3) {
        wreck_penalty_percentage = TIER_FOUR_WRECK_PENALTY_PERCENTAGE;
    }
    else {
        eligibility = false;
    }

    bool premium_option;
    int premium_percentage = 0;
    premium_option = car_has_premium_options();
    if (premium_option == true) {
        premium_percentage = TIER_ONE_PREMiUM_PERCENTAGE;
    }
    else {
        premium_percentage = TIER_TWO_PREMiUM_PERCENTAGE;
    }

    double initial_car_price = 0;
    initial_car_price = car_msrp();

    double resale_value = 0;
    total_percentage = baseline_resale_percentage - wreck_penalty_percentage + premium_percentage;

    
    if (eligibility == true) {
        resale_value = initial_car_price * total_percentage / 100;
        print_eligible_message(resale_value);

    }
    else {
        print_ineligible_message();
    }
   

    return 0;
}
