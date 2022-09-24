// Sources of logic assistance:  
// https://java2blog.com/round-to-2-decimal-places-cpp

#include <iostream> // To use cin/cout
#include <iomanip> // To access setw for output width
using namespace std;

// Monthly pricing for each plan
const double PAYMENT_A = 39.99; 
const double PAYMENT_B = 59.99;
const double PAYMENT_C = 69.99;

// Minute allowance per plan (C is unlimited)
const int ALLOW_A = 450;
const int ALLOW_B = 900;

// Calculate base rate per min
const double BASE_A = PAYMENT_A/ALLOW_A;
const double BASE_B = PAYMENT_B / ALLOW_B;

const double ADDITIONAL_A = 0.45;
const double ADDITIONAL_B = 0.40;

int main()
{
	// Dynamic variables
	int cellMin;
	double price, payment, baseRate, allowance, additionalRate;
	string planInput;

	cout << "Mobile Service Provider Plan Calculator" << endl
		<< "By Forrest Moulin" << endl << endl;

	cout << "Please enter a plan letter (A, B, or C)" << endl
		<< "followed by a space and the number of minutes" << endl
		<< "you spent on mobile calls this month." << endl << endl;

	cin >> planInput >> cellMin; // Get user input

	cout << endl << "You entered: " << endl
		<< left << setw(10) << "Plan" << planInput << endl
		<< left << setw(10) << "Minutes" << cellMin << endl << endl;

	// PLAN DETAILS AND FORMULAS
	// A - paymentA = $39.99/month, allowanceA = 450 min 
	//     baseRateA = $0.08886/min). additionalRateA = $0.45/min 
	//     If minA <= allowanceA, priceA = paymentA
	//     Else priceA = paymentA + additionalRateA(minA - allowanceA)
	// 
	// B - paymentB = $59.99/month, allowanceB = 900 min 
	//     (baseRateB = $0.06666/min). additionalRateB = $0.40/min 
	//     If minB <= allowanceB, priceB = paymentB
	//     Else priceB = paymentB + additionalRateB(minB - allowanceB)
	// 
	// C - $69.99/month, unlimited minutes 
	//     priceC = paymentC
	// 
	// baseB-baseA = $20. $20/($0.45/min) = 44.4 min, 
	// so after 494 min, plan B is more cost effective than A. 
	// 
	// baseC-baseA = $10. $10/($0.40/min) = 25 min, 
	// so after 925 min, plan C is more cost effective than B.

	cout << fixed << setprecision(2);
	if (planInput == "A")
	{
		cout << "Your plan cost for this month was $";
		if (cellMin < ALLOW_A)
		{
			price = PAYMENT_A;
			cout << price << "." << endl;
		}
		else
		{
			price = PAYMENT_A + ADDITIONAL_A * (cellMin - ALLOW_A);
			cout << price << "." << endl;
		}
	}
	else if (planInput == "B")
	{
		cout << "Your plan cost for this month was $";
		if (cellMin < ALLOW_B)
		{
			price = PAYMENT_B;
			cout << price << "." << endl;
		}
		else
		{
			price = PAYMENT_B + ADDITIONAL_B * (cellMin - ALLOW_B);
			cout << price << "." << endl;
		}
	}
	else if (planInput == "C")
	{
		cout << "Your plan cost for this month was $";
		price = PAYMENT_C;
		cout << price << "." << endl;
	}
	else
	{
		cout << "Unable to calculate your plan cost." << endl
			<< "Please enter a valid package letter such as A, B, or C."
			<< endl << "Example: A 400" << endl << endl;
	}

	// Check for cost effectivess based on minutes used
	cout << "Checking plan cost effectiveness based on "
		<< "minutes entered..." << endl << endl;
	if (cellMin > 925)
	{
		cout << "Since you entered more than 925 minutes," << endl
			<< "Plan C is the most cost effective option." << endl;
	}
	else if (cellMin > 494)
	{
		cout << "Since you entered more than 494 minutes" << endl
			<< "but less than or equal to 925 minutes," << endl
			<< "Plan B is the most cost effective option." << endl;
	}
	else
	{
		cout << "Since you entered less than 495 minutes," << endl
			<< "Plan A is the most cost effective option." << endl;
	}
}
/*
* CONSOLE OUTPUT
* Mobile Service Provider Plan Calculator
* By Forrest Moulin
*
* Please enter a plan letter (A, B, or C)
* followed by a space and the number of minutes
* you spent on mobile calls this month.
*
* B 3000
*
* You entered:
* Plan      B
* Minutes   3000
*
* Your plan cost for this month was $899.99.
* Checking plan cost effectiveness based on minutes entered...
*
* Since you entered more than 925 minutes,
* Plan C is the most cost effective option.
*/
