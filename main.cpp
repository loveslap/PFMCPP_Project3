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

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run( int howFast, bool startWithLeftFoot);
};

struct Foot
{
    int size;

    bool stepForward();
    int stepSize();

};

bool Foot::stepForward()
{
    return true;
}

int Foot::stepSize()
{
    return size;
}
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

    int numCokes = 33;
    int numMountainDews = 14;
    int numQuarters = 44;
    int numDimes = 22;
    int numNickels = 3;

    void deliverSoda(int sodaCode);
    void makeChange(int sodaCode, int payment);
    void displayPrice(int sodaCode);
};

void VendingMachine::deliverSoda( int sodaCode) 
{
    if (sodaCode == 1) 
        --numCokes;
    else
        --numMountainDews;    
}


struct BattleTank
{
    float fuelSupply = 0.833f;
    int bulletSupply = 3553;
    float turretAngle = 0.223f;
    int grenadeSupply = 23;
    int numOperators = 3;

    void aimTurret(float angle);
    bool firebullets(int numBullets);
    bool launchGrenades(int numGrenades);
};

void BattleTank::aimTurret( float angle )
{
    turretAngle = angle;
}
bool BattleTank::firebullets( int numBullets )
{
    if (numBullets < bulletSupply)  
    {
        bulletSupply -= numBullets;
        return true;
    }
    return false;
}   
bool BattleTank::launchGrenades( int numGrenades )
{
    if (numGrenades < grenadeSupply)  
      {
        grenadeSupply -= numGrenades;
        return true;
      } 
    return false;
} 

struct DigitalCamera
{

    float lightLevel = 2.455f;
    int availableStorage = 234235;
    float zoomDegree = 2.5334f;
    int horizontalResolution = 1024;
    int verticalResolution = 768;

    struct MemoryCard
    { 
        bool isFull = false;
        bool isLocked = false;
        std::string cardname = "Untitled";
        int capacity = 1048576;
        int memoryAddress = 0;

        bool storePicture(std::string Picture);
        void setLock(bool lock);
        std::string getPicture(int address);
        
    };
    void setZoom(float degree);
    void deletePicture(int pictNum, MemoryCard memCard);
};
bool DigitalCamera::MemoryCard::storePicture(std::string Picture)
{
    if (Picture != "")
        return true;
    
    return false;
}
void DigitalCamera::setZoom( float degree )
{
    zoomDegree = degree;
}

void DigitalCamera::deletePicture(int pictNum, MemoryCard memCard)
{
    memCard.memoryAddress = pictNum * 1024;
    memCard.storePicture("BLANK");
}
struct Submarine
{

    float depth = 203.33f;
    float heading = 0.67f;
    float waterPressure = 22.44f;
    int numShipmen = 44;
    int numTorpedos = 55;

    struct Motor 
    { 
        std::string manufacturer = "RollsRoyce";
        std::string model = "Submaster 3000";
        int rpm = 0;
        bool isReady = true;
        int voltage = 220;

        void goOnline();
        void goOffline();
        bool setSpeed(int velocity);
    };

    void setDepth(float chosenDepth);
    void setDirection(float chosenHeading);
    bool fireTorpedo();
    void setVelocity(int velocity, Motor theMotor);
};

void Submarine::setDepth(float chosenDepth)
{
    depth = chosenDepth;
}

void Submarine::setDirection(float chosenHeading)
{
    heading = chosenHeading;
}

bool Submarine::fireTorpedo()
{
    if (numTorpedos > 0)
    {       
        --numTorpedos;
        return true;
    }
    return false;
}

bool Submarine::Motor::setSpeed(int velocity)
{
    if (isReady && velocity>0)
    {
        return true;
    }
    return false;
}
void Submarine::setVelocity(int velocity, Motor theMotor)
{
    theMotor.setSpeed(velocity);
}

#include <iostream>


struct ExecutiveBranch 
{
    std::string nameOfPresident = "Bob";
    int numSecretService = 23;
    std::string locationPresident = "White House";
    int nukeSuitcaseCode = 8675309;
    int daysRemainingInOffice = 245;
    void enactExecutiveOrder(int orderNumber, std::string orderText);
    void giveSpeech(std::string speechText);
    void initiateOps(std::string  details);
};

void ExecutiveBranch::enactExecutiveOrder(int orderNumber, std::string orderText)
{

    std::cout << orderNumber;
    std::cout << orderText;
}

void ExecutiveBranch::giveSpeech(std::string speechText)
{
    std::cout<<speechText;
}

void initiateOps(std::string details)
{
    std::cout<<details;
}

struct LegislativeBranch
{
    int numLefties = 203;
    int numRighties = 202;
    int currentBill = 2245;
    int debateHoursRemaining = 4;
    bool inSession = true;
    int voteOnBill(); 
    void debateBill();
    void tradeStocks();
};

int LegislativeBranch::voteOnBill()
{
    return currentBill;
}

void LegislativeBranch::debateBill()
{
   --debateHoursRemaining;
}

void tradeStocks()
{
    std::cout << "WINNING";
}

struct JudicialBranch
{

    int numCases = 45;
    int daysRemainingInSession = 55;
    int currentCaseNumber = 45623;
    int nextCaseNumber = 45636;
    bool inSession = true;
    bool judgeCase(); 
    void remandCase();
    void listenToTestimony();
};

bool JudicialBranch::judgeCase()
{
    return true;
}

void JudicialBranch::remandCase()
{
    currentCaseNumber = nextCaseNumber;
}

void JudicialBranch::listenToTestimony()
{
    std::cout << "Listened to testimony";
}

struct Army
{
    int numOfficers = 4435;
    int numSoldiers = 434534;
    float soldierMorale = 0.8873f;
    int numTanks = 3345;
    int numBullets = 3453453;
    void developPlans();
    void invadeCountry(std::string country);
    void cleanBarracks();
};

void Army::developPlans(std::string enemy)
{
    std::cout << "plans developed.";
}

void Army::invadeCountry(std::string country)
{
    std::cout << "invading:";
    std::cout << country;
}

void Army::cleanBarracks()
{
    std::cout << "Barracks cleaned";
    soldierMorale *= .7f;
}
struct DeepState
{
    int numEmbeddedBureaucrats = 25455;
    int numEmbeddedJournalists = 245;
    float percentageComprimisedPoliticians = 33.65f;
    std::string secretCodeword = "Smurf";
    int sacredNumber = 88;
    void coerceLegislators();
    void designNarrative();
    void suppressInformation();
};

void DeepState::coerceLegislators()
{
    std::cout << "coerced legislators";
}

void DeepState::designNarrative()
{
    std::cout << "Narrative designed";
}

void DeepState::suppressInformation()
{
    std::cout << "Information suppressed";
}

struct Government

{
    ExecutiveBranch execBranch;
    LegislativeBranch legBranch;
    JudicialBranch judBranch;
    Army army;
    DeepState deepState;
    void goToWar(std::string enemy);
    void levyTax(int amount);
    void propagandizeCitizens(std::string narrative);
};

void Government::goToWar(std::string enemy)
{
    army.developPlans(enemy);
    std::cout << "going to war against ";
    std::cout << enemy;
}

void Government::levyTax(int amount)
{
    deepState.designNarrative();
    std::cout << "Tax levied: ";
    std::cout << amount;
}

void Government::propagandizeCitizens(std::string narrative)
{
    std::cout << narrative;
}

int main()
{
    std::cout << "good to go!" << std::endl;
}
