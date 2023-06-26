#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>
#include <getopt.h>

/*
 * @brief Regex expresssion used to parse
 *            event labels and parameters 
 */
#define LABEL_REGEX std::string("([a-z_A-z]+[0-9]*)")
#define PARAMS_REGEX std::string(LABEL_REGEX + "\\((.*)\\)")
/*
 * @brief Safely executes events by catching exceptions
 *     
 */
#define ERROR_1 std::cout << "Event is not recognized" << "\n"
#define ERROR_2 std::cout << "Event is not executable" << "\n"

/*
 * @brief An object used to serialize types and get the appropriated values as of
 *        primitive types or complex types.
 */
class Types {
    
 public:
    
    static std::string get_str(const std::string s) { return s; }
    static int get_int(const std::string s) { return std::stoi(s); }
    static float get_float(const std::string s) { return std::stof(s); }
    static double get_double(const std::string s) { return std::stod(s); }
    static bool get_bool(const std::string s) { 
        if(s == "0" || s == "false"){
            return false;
        }
        return true;
    }
};

/*
 * @brief channel to read events
 */
static std::ifstream channel;
static std::string filename;

/*
 * @brief The event data structure containing its label and its parameters
 *
 */
struct Event 
{
    std::string label;
    std::vector<std::string> params;
};

bool daytimeRunningLight;
bool armoredVehicle;
bool ambientLight;
int marketCode;
const std::vector<int> Dom_marketCode = {1,2,3};
int voltageBattery;
const std::vector<int> Dom_voltageBattery = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450};

class IO
{
public:
    /*
     * @brief parses event parameters and sets the event object with these params
     * @param The event object to be set
     * @param The event string to be parsed 
     * @param The input regex to be used for parsing
     * @return 
     */
    static void get_event_params(Event& e, const std::string in, const std::regex regex) 
    {
        std::smatch matches;
        if(regex_search(in, matches, regex)) 
        {
            std::stringstream ss(matches.str(2));
	    while(ss.good()) 
	    { 
	        std::string it; 
	        getline(ss, it, ',');
	        e.params.push_back(it); 
	    }
        }
  
        return;   
    }

    /*
     * @brief parses event label and returns its value
     * @param The event string to be parsed
     * @return The event label
     */
    static std::string get_event_label(const std::string in) 
    {
        std::smatch matches;
        if(regex_search(in, matches, std::regex(LABEL_REGEX)))
	    return matches.str(1);

        return ""; 
    }

    /*
     * @brief Reads event from the Input stream
     * @param The cmdline arguments 
     * @return The event object
     */

    static void configInputStream(int argc, char** argv) 
    {
        const char* const short_opts = "i:1:2:3:4:5:h";

        const option long_opts[] = {
            {"daytimeRunningLight", required_argument, nullptr, '1'},
            {"armoredVehicle", required_argument, nullptr, '2'},
            {"ambientLight", required_argument, nullptr, '3'},
            {"marketCode", required_argument, nullptr, '4'},
            {"voltageBattery", required_argument, nullptr, '5'},
        };

        while (true)
        {
             const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);
             if (-1 == opt)
                break;

             switch(opt)
             {
                    
             case 'i':
             {
                filename = std::string(optarg); 
                channel = std::ifstream(filename);
                if(!channel)
                    std::cout << "Error opening event file !!!";
                break;
             }
             
             case '1': 
                 daytimeRunningLight = Types::get_bool(optarg); 
                 break;
             case '2': 
                 armoredVehicle = Types::get_bool(optarg); 
                 break;
             case '3': 
                 ambientLight = Types::get_bool(optarg); 
                 break;
             case '4': 
                 if(std::find(Dom_marketCode.begin(), Dom_marketCode.end(), Types::get_int(optarg)) !=Dom_marketCode.end()) 
                 marketCode = Types::get_int(optarg); 
                break;
             case '5': 
                 if(std::find(Dom_voltageBattery.begin(), Dom_voltageBattery.end(), Types::get_int(optarg)) !=Dom_voltageBattery.end()) 
                 voltageBattery = Types::get_int(optarg); 
                break;
             case 'h':
             { 
                 std::cout << "This program has been compiled by cASTD." << "\n";
                 std::cout << "./my_program [-i <event file>] [-daytimeRunningLight <value>] [-armoredVehicle <value>] [-ambientLight <value>] [-marketCode <value>] [-voltageBattery <value>]  [-h]" << "\n";
                 std::cout << "[OPTIONS]     								     " << "\n";
                 std::cout << "   -i <event  file>  Read an event file in Shorthand format." << "\n";
                 std::cout << "                     If an event file is not given, it runs in interactive" << "\n";
                 std::cout << "                     mode from command line" << "\n";
                    std::cout << "   -daytimeRunningLight <value> Parameter of the ASTD" << std::endl;
                    std::cout << "   -armoredVehicle <value> Parameter of the ASTD" << std::endl;
                    std::cout << "   -ambientLight <value> Parameter of the ASTD" << std::endl;
                    std::cout << "   -marketCode <value> Parameter of the ASTD" << std::endl;
                    std::cout << "   -voltageBattery <value> Parameter of the ASTD" << std::endl;
                 
                 
                 
                 std::cout << "   -h                Show this help" << "\n";
                 exit(0);
                 break;
             }
             
         }   
     }
 }


    static Event read_event(int argc) 
    {
        Event e;
        std::string input;

        if(argc > 1) 
        {
            if(!filename.empty()) 
	        std::getline(channel, input); 
	    else 
	        std::getline(std::cin, input); 

	    e.label = get_event_label(input);
	    get_event_params(e, input, std::regex(PARAMS_REGEX));  
        }
        else 
        {
            getline(std::cin, input);
            e.label = get_event_label(input);
            get_event_params(e, input, std::regex(PARAMS_REGEX));
        }
     
        return e;
    }
};
/*
* @brief Manages clock variables.
*
*/
class Timer {
private:
        std::time_t time_stamp;

public:
    //constructor definition
    Timer(){
        time_stamp = std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count();
    }

    bool expired(double duration){
        return (std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count() >= time_stamp + duration);
    }

    std::time_t getPassedTime(){
        return (std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count() - time_stamp);
    }

    std::time_t getTimeStamp(){
        return time_stamp;
    }

    void reset_clock(){
        time_stamp = std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count();
    }

    void reset_clock(Timer ts){
        time_stamp = ts.getTimeStamp();
    }

    void setTimeStamp(){

    }
};