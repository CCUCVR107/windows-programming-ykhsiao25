#include <string>
#include <sstream>
#include <vector>
<<<<<<< HEAD
=======
#include <algorithm>
>>>>>>> finish HW2
#include <gtest\gtest.h>

using namespace std;


// getAscendingStr Function requirement
//
// Take space seperated digit string (ex. "1 2 3 5 4") and 
//   modify input string to ascending order ("1 2 3 4 5").
//
// return 0 if success, (empty string)
//       -1 if exception occur (ex. string containing non-digit character)
int getAscendingStr(string& inputStr)
<<<<<<< HEAD
{
=======
{	
>>>>>>> finish HW2
	for (char c : inputStr) {
		if (!isdigit(c) && c != ' ')
			if (c != '-')
				return -1;
	}
	//字串一一讀取，若有非數字直接回傳-1


	if (inputStr == "") {
		cout << "空字串";
		return 0;
	}
	else {
		int inputStr_index;
		stringstream ss(inputStr);
		vector<int> v;
		while (ss >> inputStr_index) {
			v.push_back(inputStr_index);
		}
		sort(v.begin(), v.end());
<<<<<<< HEAD
		stringstream result;
		std::copy(v.begin(), v.end(), std::ostream_iterator<float>(result, " "));
		result.str().erase(result.str().find_last_not_of(" ") + 1);
		std::cout << result.str().erase(result.str().find_last_not_of(" ") + 1) << endl;
		inputStr = result.str().erase(result.str().find_last_not_of(" ") + 1);

		//inputStr
		
		cout << inputStr << endl;
=======
		for (auto inputStr : v) {
			cout << inputStr << endl;
		}
>>>>>>> finish HW2
		return 0;
	}
}

// solveQ Function requirement
// 
// solve quadratic function ax^2 + bx + c = 0
//
// return 1 if equation has two different real number root 
//          (return vector size should be 2 containing 2 solution.  
//          Greater value should put into smaller vector index)
//        0 there is only one possible solution to the quadratic equation 
//          (return vector size should be 1)
//       -1 complex roots 
//          (return vector size should be 0)
int solveQ(vector<double> &x, double a, double b, double c)
{
<<<<<<< HEAD
	double d = (b * b) - (4 * a * c);
	if (d > 0) {
		x.push_back((-b + sqrt(b*b - 4 * a * c)) / (2 * a));
		x.push_back((-b - sqrt(b*b - 4 * a * c)) / (2 * a));
		cout << x[0] << endl;
		cout << x[1] << endl;
		return 1;
	}
	if (d == 0) {
		x.push_back((-b) / 2 * a);
		cout << x[0] << endl;
		return 0;
	}
	if (d < 0) {
		cout << "-1" << endl;
		return -1;
	}
=======
		double d = (b * b) - (4 * a * c);
		if (d > 0){
			x[0] = (-b + sqrt(4 * a * c)) / (2 * a);
			x[1] = (-b - sqrt(4 * a * c)) / (2 * a);
			cout << x[0] << endl;
			cout << x[1] << endl;
			return 1;
		}
		if (d == 0) {
			x[0] = (-b) / 2 * a;
			cout << x[0] << endl;
			return 0;
		}
		if (d < 0) {
			cout << "-1" << endl;
			return - 1;
		}
>>>>>>> finish HW2
}

int main(int argc, char*argv[]) {
	
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}


TEST(getAscendingStr, SimpleAscending)
{//Simple ascending test case

	string inputStr = "1 -3 2195 4 50";
	string tmpStr = inputStr;
	int err = getAscendingStr(tmpStr);
	EXPECT_EQ(tmpStr, "-3 1 4 50 2195");
	EXPECT_EQ(err, 0);
}

TEST(getAscendingStr, handleNonDigit)
{//getAscendingStr function should handle non digit case
	string tmpStr = "1 3 2 4 a 7f415";
	int err = getAscendingStr(tmpStr);
	EXPECT_EQ(err, -1);
}

TEST(solveQ, twoSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 2, -3);
	EXPECT_EQ(iSol, 1);
	EXPECT_EQ(sol.size(), 2);
	EXPECT_EQ(sol.at(0), 1);
	EXPECT_EQ(sol.at(1), -3);
}

TEST(solveQ, oneSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, -8, 16);
	EXPECT_EQ(iSol, 0);
	EXPECT_EQ(sol.size(), 1);
	EXPECT_EQ(sol.at(0), 4);
}

TEST(solveQ, noSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 1, 16);
	EXPECT_EQ(iSol, -1);
	EXPECT_EQ(sol.size(), 0);
}
