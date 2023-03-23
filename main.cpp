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

    VendingMachine();

    void deliverSoda(int sodaCode);
    void makeChange(int sodaCode, int payment);
    void displayPrice(int sodaCode);
};
VendingMachine::VendingMachine()
{
    std::cout << "VendingMachine being constructed!" << std::endl;
}
void VendingMachine::deliverSoda( int sodaCode) 
{
    if (sodaCode == 1) {
        --numCokes;
            std::cout << "Delivering Coke" << std::endl;
        }
    else
    {
        --numMountainDews;    
     std::cout << "Delivering Mountain Dew" << std::endl;
        }
}

void VendingMachine::makeChange(int sodaCode, int payment)
{
    std::cout << "Sodacode:" << sodaCode << std::endl;
    std::cout << "Change:" << 1.5 - payment << std::endl;
}

void VendingMachine::displayPrice(int sodacode)
{
    std::cout << "Sodacode:" << sodacode << "Price: ";
    std::cout << 1.5  << std::endl;
}

struct BattleTank
{
    float fuelSupply = 0.833f;
    int bulletSupply = 3553;
    float turretAngle = 0.223f;
    int grenadeSupply = 23;
    int numOperators = 3;

    BattleTank();

    void aimTurret(float angle);
    bool fireBullets(int numBullets);
    bool launchGrenades(int numGrenades);
};

BattleTank::BattleTank()
{
    std::cout << "BattleTank being constructed!" << std::endl;  
}

void BattleTank::aimTurret( float angle )
{
    turretAngle = angle;
     std::cout << "Aiming Turret" << std::endl;
}
bool BattleTank::fireBullets( int numBullets )
{
    if (numBullets < bulletSupply)  
    {
        bulletSupply -= numBullets;
         std::cout << "Firing Bullets" << std::endl;
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

    DigitalCamera();

    struct MemoryCard
    { 
        bool isFull = false;
        bool isLocked = false;
        std::string cardname = "Untitled";
        int capacity = 1048576;
        int memoryAddress = 0;

        MemoryCard();

        bool storePicture(std::string Picture);
        void setLock(bool lock);
        std::string getPicture(int address);
        
    };
    void setZoom(float degree);
    void deletePicture(int pictNum, MemoryCard memCard);
};

DigitalCamera::DigitalCamera()
{
    std::cout << "Digital Camera being constructed!" << std::endl;
}

DigitalCamera::MemoryCard::MemoryCard()
{
    std::cout << "Digital Camera Memory Card being constructed!" << std::endl;
}

bool DigitalCamera::MemoryCard::storePicture(std::string Picture)
{
    if (Picture != "")
        {
         std::cout << "Storing picture" << std::endl;
        return true;
        }
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
     std::cout << "Deleting picture" << std::endl;
}
struct Submarine
{

    float depth = 203.33f;
    float heading = 0.67f;
    float waterPressure = 22.44f;
    int numShipmen = 44;
    int numTorpedos = 55;

    Submarine();

    struct Motor 
    { 
        std::string manufacturer = "RollsRoyce";
        std::string model = "Submaster 3000";
        int rpm = 0;
        bool isReady = true;
        int voltage = 220;

        Motor();

        void goOnline();
        void goOffline();
        bool setSpeed(int velocity);
    };

    void setDepth(float chosenDepth);
    void setDirection(float chosenHeading);
    bool fireTorpedo();
    void setVelocity(int velocity, Motor theMotor);
};

Submarine::Submarine()
{
    std::cout << "Submarine being constructed!" << std::endl;
}

Submarine::Motor::Motor()
{
    std::cout << "Submarine Motor being constructed!" << std::endl;
}
void Submarine::setDepth(float chosenDepth)
{
    depth = chosenDepth;
     std::cout << "Depth set" << std::endl;
}

void Submarine::setDirection(float chosenHeading)
{
    heading = chosenHeading;
     std::cout << "Direction set" << std::endl;
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

    ExecutiveBranch();

    void enactExecutiveOrder(int orderNumber, std::string orderText);
    void giveSpeech(std::string speechText);
    void initiateOps(std::string details);
};

ExecutiveBranch::ExecutiveBranch()
{
    std::cout << "Executive Branch being constructed!" << std::endl; 
}

void ExecutiveBranch::enactExecutiveOrder(int orderNumber, std::string orderText)
{

    std::cout << orderNumber << std::endl;
    std::cout << orderText << std::endl;
}

void ExecutiveBranch::giveSpeech(std::string speechText)
{
    std::cout << speechText << std::endl;
}

void ExecutiveBranch::initiateOps(std::string details)
{
    std::cout << details << std::endl;
}

struct LegislativeBranch
{
    int numLefties = 203;
    int numRighties = 202;
    int currentBill = 2245;
    int debateHoursRemaining = 4;
    bool inSession = true;

    LegislativeBranch();

    int voteOnBill(); 
    void debateBill();
    void tradeStocks();
};

LegislativeBranch::LegislativeBranch()
{
    std::cout << "Legislative Branch being constructed!" << std::endl; 
}
    
int LegislativeBranch::voteOnBill()
{
     std::cout << "Voting on bill" << std::endl;
    return currentBill;
}

void LegislativeBranch::debateBill()
{
     std::cout << "Debating bill" << std::endl;
   --debateHoursRemaining;
}

void LegislativeBranch::tradeStocks()
{
    std::cout << "WINNING" << std::endl;
}

struct JudicialBranch
{

    int numCases = 45;
    int daysRemainingInSession = 55;
    int currentCaseNumber = 45623;
    int nextCaseNumber = 45636;
    bool inSession = true;

    JudicialBranch();

    bool judgeCase(); 
    void remandCase();
    void listenToTestimony();
};

JudicialBranch::JudicialBranch()
{
    std::cout << "Judicial Branch being constructed!" << std::endl; 
}

bool JudicialBranch::judgeCase()
{
     std::cout << "Judging case" << std::endl;
    return true;
}

void JudicialBranch::remandCase()
{
     std::cout << "Remanding case" << std::endl;
    currentCaseNumber = nextCaseNumber;
}

void JudicialBranch::listenToTestimony()
{
    std::cout << "Listened to testimony" << std::endl;
}

struct Army
{
    int numOfficers = 4435;
    int numSoldiers = 434534;
    float soldierMorale = 0.8873f;
    int numTanks = 3345;
    int numBullets = 3453453;

    Army();

    void developPlans(std::string enemy);
    void invadeCountry(std::string country);
    void cleanBarracks();
};

Army::Army()
{
    std::cout << "Army being constructed!" << std::endl; 
}

void Army::developPlans(std::string enemy)
{
    std::cout << "plans developed against";
    std::cout << enemy << std::endl;
}

void Army::invadeCountry(std::string country)
{
    std::cout << "invading:";
    std::cout << country << std::endl;
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

    DeepState();

    void coerceLegislators();
    void designNarrative();
    void suppressInformation();
};

DeepState::DeepState()
{
    std::cout << "Deep State being constructed!" << std::endl; 
}

void DeepState::coerceLegislators()
{
    std::cout << "coerced legislators" << std::endl;
}

void DeepState::designNarrative()
{
    std::cout << "Narrative designed" << std::endl;
}

void DeepState::suppressInformation()
{
    std::cout << "Information suppressed" << std::endl;
}

struct Government

{
    ExecutiveBranch execBranch;
    LegislativeBranch legBranch;
    JudicialBranch judBranch;
    Army army;
    DeepState deepState;

    Government();

    void goToWar(std::string enemy);
    void levyTax(int amount);
    void propagandizeCitizens(std::string narrative);
};

Government::Government()
{
    std::cout << "Government being constructed!" << std::endl; 
}

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
    std::cout << amount << std::endl;
}

void Government::propagandizeCitizens(std::string narrative)
{
    std::cout << narrative << std::endl;
}

int main()
{
    Example::main();
    
    VendingMachine vm;
    vm.deliverSoda(1);
    vm.makeChange(1,4);
    vm.displayPrice(1);

    BattleTank bt;
    bt.aimTurret(1.05f);
    bt.fireBullets(33);
    bt.launchGrenades(3);

    DigitalCamera dc;
    DigitalCamera::MemoryCard mc;
    dc.setZoom(88.32f);
    dc.deletePicture(6, mc);

    Submarine sub;
    Submarine::Motor subMotor;
    sub.setDepth(99.4f);
    sub.setDirection(45.25);
    sub.fireTorpedo();
    sub.setVelocity(5, subMotor);

    ExecutiveBranch eb;
    eb.enactExecutiveOrder(56, "Release the hounds");
    eb.giveSpeech("Now is the time");
    eb.initiateOps("go spy now");

    LegislativeBranch lb;
    lb.voteOnBill();
    lb.debateBill();
    lb.tradeStocks();

    JudicialBranch jb;
    jb.judgeCase();
    jb.remandCase();
    jb.listenToTestimony();
    
    Army army;
    army.developPlans("antivaxers");
    army.invadeCountry("Vietnam");
    army.cleanBarracks();

    DeepState deepState;
    deepState.coerceLegislators();
    deepState.designNarrative();
    deepState.suppressInformation();

    Government government;
    government.goToWar("Portugal");
    government.levyTax(1000000000);
    government.propagandizeCitizens("Obey");
    
    
    std::cout << "Army bullet count:" << army.numBullets << std::endl;

      std::cout << "Battle tank bullet count:" << bt.bulletSupply << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
