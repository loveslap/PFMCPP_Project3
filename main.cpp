/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()




struct VendingMachine
{

    int numCokes;
    int numMountainDews = 14;
    int numQuarters = 44;
    int numDimes = 22;
    int numNickels = 3;

    VendingMachine();

    void deliverSoda(int sodaCode);
    void makeChange(int sodaCode, int payment);
    void displayPrice(int sodaCode);
    void loadCokes(int howMany);
};


VendingMachine::VendingMachine() : numCokes(42)
{
    std::cout << "VendingMachine being constructed!" << std::endl;
    std::cout << numCokes << " Cokes and " << numMountainDews << " Mountain Dews" << std::endl;
}

void VendingMachine::loadCokes(int howMany)
{
    for (int i=0; i<howMany; ++i)
    {
        std::cout << "now have " << ++numCokes << " cokes \n";
    }
}

void VendingMachine::deliverSoda( int sodaCode) 
{
    if (sodaCode == 1)
    {
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
    int bulletSupply;
    float turretAngle = 0.223f;
    int grenadeSupply = 23;
    int numOperators = 3;

    BattleTank();

    void aimTurret(float angle);
    bool fireBullets(int numBullets);
    bool launchGrenades(int numGrenades);
    void fireAllGrenades();
};

BattleTank::BattleTank() : bulletSupply(35)
{
    std::cout << "BattleTank being constructed!" << std::endl;
    std::cout << "Fuel Supply: " << fuelSupply << std::endl;
    std::cout << "Bullet Supply: " << bulletSupply << std::endl;
}

void BattleTank::fireAllGrenades()
{
    while (grenadeSupply > 0)
    {
        std::cout << --grenadeSupply << " grenades left\n";
    }
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
    int horizontalResolution;
    int verticalResolution;

    DigitalCamera();

    struct MemoryCard
    { 
        bool isFull = false;
        bool isLocked = false;
        std::string cardName;
        int capacity;
        int memoryAddress = 0;

        MemoryCard();

        bool storePicture(std::string Picture);
        void setLock(bool lock);
        std::string getPicture(int address);
        
    };
    void setZoom(float degree);
    void deletePicture(int pictNum, MemoryCard memCard);
    void gradualDezoom();
};

DigitalCamera::DigitalCamera() : horizontalResolution(1024), verticalResolution(768)
{
    std::cout << "Digital Camera being constructed!" << std::endl;
    std::cout << "Resolution :" << horizontalResolution << "x" << verticalResolution << std::endl;
}

void DigitalCamera::gradualDezoom()
{
    while (zoomDegree > 0.001f) 
    {
        zoomDegree*= .7f;
        std::cout << "zoom degree: " << zoomDegree << std::endl;
    }
}
DigitalCamera::MemoryCard::MemoryCard() : capacity(4340000)
{
    std::cout << "Digital Camera Memory Card being constructed!" << std::endl;
    std::cout << "Capacity :" << capacity << std::endl;
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
    float depth;
    float heading;
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
    void surface();
};

Submarine::Submarine() :depth(203.33f), heading(0.67f)
{
    std::cout << "Submarine being constructed!" << std::endl;
    std::cout << "Depth: " << depth << std::endl;
    std::cout << "Heading: " << heading << std::endl;
}

Submarine::Motor::Motor()
{
    std::cout << "Submarine Motor being constructed!" << std::endl;
}

void Submarine::surface()
{
    std::cout << "Surfacing...\n";
    while (depth > 0)
    {
        --depth;
        std::cout << "depth: " << depth << std::endl;
    }
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
    std::string nameOfPresident;
    int numSecretService = 23;
    std::string locationPresident = "White House";
    int nukeSuitcaseCode = 8675309;
    int daysRemainingInOffice = 245;

    ExecutiveBranch();

    void enactExecutiveOrder(int orderNumber, std::string orderText);
    void giveSpeech(std::string speechText);
    void initiateOps(std::string details);
    void countSecretService();
};

ExecutiveBranch::ExecutiveBranch() : nameOfPresident("Bob")
{
    std::cout << "Executive Branch being constructed!" << std::endl; 
    std::cout << "Name of president: " << nameOfPresident << std::endl;
    std::cout << "Location of president: " << locationPresident << std::endl;
}

void ExecutiveBranch::countSecretService()
{
    int i=0;
    while (i < numSecretService) 
        {
            ++i;
            std::cout << i << " Secret Service" 
                << std::endl;
        }
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
    int numLefties;
    int numRighties;
    int currentBill = 2245;
    int debateHoursRemaining = 4;
    bool inSession = true;

    LegislativeBranch();

    int voteOnBill(); 
    void debateBill();
    void tradeStocks();
    void finishDebate();
};

LegislativeBranch::LegislativeBranch() : numLefties(238), numRighties(237)
{
    std::cout << "Legislative Branch being constructed!" << std::endl;
    std::cout << "Number of lefties: " << numLefties << std::endl;
    std::cout << "Number of righties: " << numRighties << std::endl;
}

void LegislativeBranch::finishDebate()
{
    while (debateHoursRemaining > 0)
        {
            std::cout << debateHoursRemaining << " hours of debate remaining" << std::endl;
            --debateHoursRemaining;
            
        }
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

    int numCases;
    int daysRemainingInSession = 55;
    int currentCaseNumber = 45623;
    int nextCaseNumber = 45636;
    bool inSession = true;

    JudicialBranch();

    bool judgeCase(); 
    void remandCase();
    void listenToTestimony();
    void finishSession();
};

JudicialBranch::JudicialBranch() : numCases(45)
{
    std::cout << "Judicial Branch being constructed!" << std::endl; 
    std::cout << "Number of cases: " << numCases << std::endl;  
}

void JudicialBranch::finishSession()
{
    while (--daysRemainingInSession >0)
    {
        std::cout << daysRemainingInSession << " days remaining in session\n";
    }
    daysRemainingInSession = 0;
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
    int numSoldiers;
    float soldierMorale = 0.8873f;
    int numTanks = 3345;
    int numBullets = 3453453;

    Army();

    void developPlans(std::string enemy);
    void invadeCountry(std::string country);
    void cleanBarracks();
    void displayPersonel();
    void recruitSoldiers(int quota);
};

Army::Army() : numSoldiers(234520)
{
    std::cout << "Army being constructed!" << std::endl;
}

void Army::recruitSoldiers(int quota)
{
    for (int i=0; i<quota; ++i)
        {
            ++numSoldiers;
            std::cout << "We now have " << numSoldiers << " soldiers!\n";
        }
}

void Army::displayPersonel()
{
    std::cout << "Number of soldiers: " << numSoldiers << std::endl;
    std::cout << "Number of officers: " << numOfficers << std::endl;
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
    int sacredNumber;

    DeepState();

    void coerceLegislators();
    void designNarrative();
    void suppressInformation();
    void displaySacredNumber();
    void getMoreJournos(int howMany);
};

DeepState::DeepState() : sacredNumber(88)
{
    std::cout << "Deep State being constructed!" << std::endl; 
}

void DeepState::getMoreJournos(int howMany)
{
    for (int i=0; i<howMany; ++i)
    {
        ++numEmbeddedJournalists;
        std::cout << "Now have " << numEmbeddedJournalists << " embedded journalists\n";
    }
}
void DeepState::displaySacredNumber()
{
    std::cout << "Sacred Number: " << sacredNumber << std::endl;
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
    army.displayPersonel();

    DeepState deepState;
    deepState.coerceLegislators();
    deepState.designNarrative();
    deepState.suppressInformation();
    deepState.displaySacredNumber();

    Government government;
    government.goToWar("Portugal");
    government.levyTax(1000000000);
    government.propagandizeCitizens("Obey");
    
    
    std::cout << "Army bullet count:" << army.numBullets << std::endl;

    std::cout << "Battle tank bullet count:" << bt.bulletSupply << std::endl;
    
    std::cout << "good to go!" << std::endl;


    vm.loadCokes(5);
    bt.fireAllGrenades();
    dc.gradualDezoom();
    sub.surface();
    eb.countSecretService();
    lb.finishDebate();
    std::cout << lb.debateHoursRemaining << " hours of debate remaining\n";
    jb.finishSession();
    army.recruitSoldiers(56);
    deepState.getMoreJournos(54);
}

