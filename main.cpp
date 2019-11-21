/* 
Student: Vibhavi Jayasinghe
Course Name: Programming Fundermental 2
Teacher: Dr_T
Unit 5 Assignment: Inheritance
Date: 11-12-2019
*/
 
#include <iostream>
#include <string>

using namespace std;

class Semester{
  private:
    double costPerCreditHour;
    double bookCostPerClass;
    double roomAndBoardCosts;
    double foodCostPerMonth;
    double travelCostPerMonth;        
    int hoursTheStudentTakes;
    int hoursInTheDegree;
    string schoolName;
    static const int hoursPerClass = 3;
    static const int monthsInSemester = 4;
    static const int semstersInYear = 3;
    
  public:
    Semester(){ //default constructor
      hoursTheStudentTakes = 12;
      hoursInTheDegree = 60;
      schoolName = "TCC";
      costPerCreditHour = 59.00;
      bookCostPerClass = 100.00;
      roomAndBoardCosts = 400.00;
      foodCostPerMonth = 150.00;
      travelCostPerMonth = 90.00;
    }

    Semester(double cPCH, double bCPC, double rABC, double fCPM, double tCPM, int hTST, int hITD, string sN) : costPerCreditHour(cPCH), bookCostPerClass(bCPC), roomAndBoardCosts(rABC), foodCostPerMonth(fCPM), travelCostPerMonth(tCPM), hoursTheStudentTakes(hTST), hoursInTheDegree(hITD), schoolName(sN){}
    void setHoursAStudentTakes(int h) {hoursTheStudentTakes = h;}
    int getHoursAStudentTakes() const {return hoursTheStudentTakes;}
    void setHoursInTheDegree(int hd) {hoursInTheDegree = hd;}
    int getHoursInTheDegree() const {return hoursInTheDegree;}
    void setSchoolName(string n) {schoolName = n;}
    string getSchoolName() const {return schoolName;}
    void setCostPerCreditHour(double cch) {costPerCreditHour = cch;}
    double getCostPerCreditHour() const {return costPerCreditHour;}
    void setBookCostPerHour(double bcpc) {bookCostPerClass = bcpc;}
    double getBookCostPerClass() const {return bookCostPerClass;}
    void setRoomAndBoardCost(double rabc) {roomAndBoardCosts = rabc;}
    double getRoomAndBoardCost() const {return roomAndBoardCosts;}
    void setFoodCostPerMonth(double fcpm) {foodCostPerMonth = fcpm;}
    double getFoodCostPerMonth() const {return foodCostPerMonth;}
    void setTavelCostPerMonth(double tcpm) {travelCostPerMonth = tcpm;}
    double getTravelCostPerMonth() const {return travelCostPerMonth;}

    double calculateTuitionCostPerSemester(){
      return (costPerCreditHour * hoursTheStudentTakes);
    }

    double calculateRoomAndBoardCostPerSemester(){
      return (roomAndBoardCosts * monthsInSemester);
    }

    double calculateBookCostPerSemester(){
      return (bookCostPerClass * hoursTheStudentTakes / hoursPerClass);
    }

    double calculateFoodCostPerSemester(){
      return (foodCostPerMonth * monthsInSemester);
    }

    double calculateTravelPerSemester(){
      return (travelCostPerMonth * monthsInSemester);
    }

    double calculateTotalCostPerSemester(){
      return (calculateTuitionCostPerSemester()+calculateRoomAndBoardCostPerSemester()+calculateBookCostPerSemester()+calculateFoodCostPerSemester()+calculateTravelPerSemester());
    }

    int calculateTimeForFTStudent(){
      return (hoursTheStudentTakes / hoursInTheDegree);
    }
    double calculateTotalCostForTwoYears(){
      return (calculateTotalCostPerSemester() * 6);
    }

    
  
    void printSemester(){
      cout << "\nTuition Cost for a Semester: $ " << calculateTuitionCostPerSemester();
      cout << "\nBook cost for a semester: $ " << calculateBookCostPerSemester();
      cout << "\nRoom cost for a semester: $ " << calculateRoomAndBoardCostPerSemester();
      cout << "\nFood cost for a semester: $ " << calculateFoodCostPerSemester();
      cout << "\nTravel cost for a semester: $ " << calculateTravelPerSemester();
      cout << "\nTotal cost for a semester: $ " << calculateTotalCostPerSemester();
      cout << "\nTotal cost for Two Years: $ " << calculateTotalCostForTwoYears();
    
    }
};  

int main() {
  string userSchoolName;
  double userCostPerCreditHour;

  const int hoursAFullTimeStudent = 12;
  const int hoursAPartTimeStudent = 9;
  const int hoursAHalfTimeStudent = 6;

  Semester ftTCC;
  Semester ptTCC;
  Semester htTCC;

  ftTCC.setHoursAStudentTakes(hoursAFullTimeStudent);
  ptTCC.setHoursAStudentTakes(hoursAPartTimeStudent);
  htTCC.setHoursAStudentTakes(hoursAHalfTimeStudent);

  Semester ftCollege(1712.00, 100.00, 1000.00, 150.00, 90.00, hoursAFullTimeStudent, 120, "UNT");
  Semester ptCollege(1712.00, 100.00, 1000.00, 150.00, 90.00, hoursAPartTimeStudent, 120, "UNT");
  Semester htCollege(1712.00, 100.00, 1000.00, 150.00, 90.00, hoursAHalfTimeStudent, 120, "UNT");


  cout << "\n**** Welcome to the Student Cost Calculator ****" << endl;
  string selection = "";
  cout << "\nA: Cost for a student at TCC\nB: Cost for a student at UNT\nC: I want to add my own details\nE: Exit";
  cout << "\n\nPlease choose a selection: ";
  cin >> selection;

  do{
    if(selection == "a" || selection == "A"){
      cout << "\n\nCost Per Semester for a Full Time Student at TCC";
      ftTCC.printSemester();
      cout << "\n\nCost Per Semester for a Part Time Student at TCC";
      ptTCC.printSemester();
      cout << "\n\nCost Per Semester for a Half Time Student at TCC";
      htTCC.printSemester();
      return 0;
    }

    else if(selection == "b" | selection == "B"){
      cout << "\n\nCost Per Semester for a Full Time Student at UNT";
    ftCollege.printSemester();
    cout << "\n\nCost Per Semester for a Part Time Student at UNT";
    ptCollege.printSemester();
    cout << "\n\nCost Per Semester for a Half Time Student at UNT";
    htCollege.printSemester();
    return 0;
    }

    else if(selection == "c" || selection == "C"){
      cout << "\nPlease enter your School name: ";
      cin >> userSchoolName;
      cout << "Please enter cost per credit hour: $ ";
      cin >> userCostPerCreditHour;
      Semester(userCostPerCreditHour, 100.00, 1000.00, 150.00, 90.00, hoursAFullTimeStudent, 120, userSchoolName);
      cout << "\n\nCost Per Semester for a Full Time Student at " << userSchoolName;
      ftCollege.printSemester(); 
      Semester(userCostPerCreditHour, 100.00, 1000.00, 150.00, 90.00, hoursAPartTimeStudent, 120, userSchoolName);
      cout << "\n\nCost Per Semester for a Part Time Student at " << userSchoolName;
      ptCollege.printSemester();
      Semester(userCostPerCreditHour, 100.00, 1000.00, 150.00, 90.00, hoursAHalfTimeStudent, 120, userSchoolName);
      cout << "\n\nCost Per Semester for a Half Time Student at " << userSchoolName;
      htCollege.printSemester();
      return 0;
    }

    else if(selection == "e" || selection == "E"){
      cout << "\nGood Bye!";
    }

    else{
      cout << "Invalid Input. Please choose a correct option: ";
      cin >> selection;
      
    }
  }while(selection != "e" && selection != "E");
  cout << "\nThank you for using Student Cost Calculator!";
   
} 
