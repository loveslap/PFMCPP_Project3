/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





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
    std::cout << speechText;
}

void initiateOps(std::string details)
{
    std::cout << details;
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
    void developPlans(std::string enemy);
    void invadeCountry(std::string country);
    void cleanBarracks();
};

void Army::developPlans(std::string enemy)
{
    std::cout << "plans developed against";
    std::cout << enemy;
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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
