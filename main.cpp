 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct VendingMachine
{
// 5 properties:
//     1)  number of cokes (int)
    int numCokes = 33;
//     2)  number of mountain dews (int)
    int numMountainDews = 14;
//     3)  number of quarters (int)
    int numQuarters = 44;
//     4)  number of dimes (int)
    int numDimes = 22;
//     5)  number of nickels (int)
    int numNickels = 3;
// 3 things it can do:
//     1)  deliver soda
    void deliverSode(int sodaCode);
//     2)  make change
    void makeChange(int sodaCode, int payment);
//     3)   display price
    void displayPrice(int sodaCode);
};

struct BattleTank
{
//     1) fuel supply  (float)
    float fuelSupply = 0.833f;
//     2) bullet supply (int)
    int bulletSupply = 3553;
//     3) turret angle (float)
    float turretAngle = 0.223f;
//     4)  grenade supply (int)
    int grenadeSupply = 23;
//     5)  number of operators (int)
    int numOperators = 3;
// 3 things it can do:
//     1)  aim turret
    void aimTurret(float angle);
//     2)  fire bullets
    bool firebullets(int numBullets);
// returns false if not enough bullets
//     3)  launch grenades
    bool launchGrenades(int numGrenades);
// returns false if not enough grenades
};

struct DigitalCamera
{
// 5 properties:
//     1)   light level (float)
    float lightLevel = 2.455f;
//     2)   available storage (int)
    int availableStorage = 234235;
//     3)   zoom degree (float)
    float zoomDegree = 2.5334f;
//     4)   horizontal resolution (int)
    int horizontalResolution = 1024;
//     5)   vertical resolution (int)
    int verticalResolution = 768;
// here is the nested UDT
    struct MemoryCard
    { 
        bool isFull = false;
        bool isLocked = false;
        std::string cardname = "Untitled";
        int capacity = 1048576;
        int memoryAddress = 0;

        void storePicture(std::string Picture);
        void setLock(bool lock);
        std::string getPicture(int address);
        
    };
// 3 things it can do:
//     1)   set zoom
    void setZoom(float degree);
//     2)   take picture
    int takePicture(MemoryCard memCard); // returns picture number
//     3)   delete picture
    void deletePicture(int pictNum, MemoryCard memCard);
};

struct Submarine
{
// 5 properties:
//     1)  depth (float)
    float depth = 203.33f;
//     2)  heading (float)
    float heading = 0.67f;
//     3)  water pressure (float)
    float waterPressure = 22.44f;
//     4)  number of shipmen (int)
    int numShipmen = 44;
//     5)  number of torpedos (int)
    int numTorpedos = 55;

    struct Motor 
    { 
        std::string manufacturer = "RollsRoyce";
        std::string model = "Submaster 3000";
        int rpm = 0;
        bool isReady = true;
        int voltage = 220;

        // 3 things it can do
        void goOnline();
        void goOffline();
        bool setSpeed(int velocity);
    };
// 3 things it can do:
//     1)  set depth
    void setDepth(float chosenDepth);
//     2)  set direction
    void setDirection(float chosenHeading);
//     3)  fire torpedo
    bool fireTorpedo();
// set velocity of submarine
    void setVelocity(int velocity, Motor theMotor);
// returns false if no torpedo present
};

struct ExecutiveBranch 
{
// 5 properties:
//     1)  Name of President (std::string)
    std::string nameOfPresident = "Bob";
//     2)  Number of secret service (int)
    int numSecretService = 23;
//     3)  Location of President (std::string)
    std::string locationPresident = "White House";
//     4)  Nuclear Suitcase code (int)
    int nukeSuitcaseCode = 8675309;
//     5)  Days remaining in office. (int)
    int daysRemainingInOffice = 245;
// 3 things it can do:
//     1)  Enact excecutive order
    void enactExecutiveOrder(int orderNumber, std::string orderText);
//     2)  Give a speech
    void giveSpeech(std::string speechText);
//     3)  Initiate covert ops
    void initiateOps(std::string  details);
};

struct LegislativeBranch
{
// 5 properties:
//     1) Number of Lefties (int)
    int numLefties = 203;
//     2) Number of righties (int)
    int numRighties = 202;
//     3) Current bill under consideration (int)
    int currentBill = 2245;
//     4) Hours remaining for debate (int)
    int debateHoursRemaining = 4;
//     5) Currently in session (bool)
    bool inSession = true;
// 3 things it can do:
//     1) Vote on bill.
    int voteOnBill(); // returns number of yeses
//     2) Debate bill. 
    void debateBill();
//     3) Trade stocks.
    void tradeStocks();
};

struct JudicialBranch
{
// 5 properties:
//     1) Number of cases on docket (int)
    int numCases = 45;
//     2) Days remaining in current session (int)
    int daysRemainingInSession = 55;
//     3) Current case number (int)
    int currentCaseNumber = 45623;
//     4) Next Case number (int)
    int nextCaseNumber = 45636;
//     5) Currently in session (bool)
    bool inSession = true;
// 3 things it can do:
//     1)  Judge case
    bool judgeCase(); // true with judge sides with plantiff
//     2)  Remand case to lower court
    void remandCase();
//     3)  Listen to testimony
    void listenToTestimony();
};

struct Army
{
// 5 properties:
//     1)  Number of officers (int)
    int numOfficers = 4435;
//     2)  Number of soldiers (int)
    int numSoldiers = 434534;
//     3)  Soldier morale rating (float)
    float soldierMorale = 0.8873f;
//     4)  Number of tanks (int)
    int numTanks = 3345;
//     5)  Number of bullets (int)
    int numBullets = 3453453;
// 3 things it can do:
//     1)  Develop attack plans
    void developPlans();
//     2)  Invade country
    void invadeCountry(std::string country);
//     3)  Clean Barracks
    void cleanBarracks();
};

struct DeepState
{
// 5 properties:
//     1)  Numnber of embedded bureacrats (int)
    int numEmbeddedBureaucrats = 25455;
//     2)  Number of embedded journalists (int)
    int numEmbeddedJournalists = 245;
//  `  3)  Percentage of comprimised politicians (float)
    float percentageComprimisedPoliticians = 33.65f;
//     4)  Secret codeword (std::string)
    std::string secretCodeword = "Smurf";
//     5)  Sacred Number (int)
    int sacredNumber = 88;
// 3 things it can do:
//     1)  Coerce legislators
    void coerceLegislators();
//     2)  Engineer narrative
    void designNarrative();
//     3)  Supress information
    void suppressInformation();
};

struct Government

{
// 5 properties:
//     1) Executive Branch
    ExecutiveBranch execBranch;
//     2) Legislative Branch
    LegislativeBranch legBranch;
//     3) Judicial Branch
    JudicialBranch judBranch;
//     4) Army 
    Army army;
//     5) Deep State
    DeepState deepState;
// 3 things it can do:
//     1)  Go to war
    void goToWar(std::string enemy);
//     2)  Levy Tax
    void levyTax(int amount);
//     3)  Propagandize Citizens
    void propagandizeCitizens(std::string narrative);
};



int main()
{
    std::cout << "good to go!" << std::endl;
}
