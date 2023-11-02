#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
#include <vector>
#include <limits>
#include <random>
#include <chrono>
#include <map>
#include <sstream>
#include <ctime>

using std::time;
using std::stof;
using std::stoi;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::copy;
using std::sort;
using std::fixed;
using std::vector;
using std::swap;
using std::runtime_error;
using std::map;
using std::mt19937;


using hrClock = std::chrono::high_resolution_clock; 
typedef std::uniform_int_distribution<int>  int_distribution;

class user{
    private:
    int balance;
    string name, public_key;
    public:
    user() : balance{0}, public_key{"none"}, name{"undefined user"} {}
    user(string vardas, string key, int balance) : balance{balance}, public_key{key}, name{vardas} {}
    inline string get_public_key() const { return public_key; }
    inline int get_balance() const { return balance; }
    ~user() {}
};

class transaction{
    private: 
    int ID, amount;
    string sender_key, getter_key;
    public:
    transaction() : ID(0), amount(0), sender_key("none"), getter_key("none") {}
    transaction(int amount, string pub1, string pub2) : amount(amount), sender_key(pub1), getter_key(pub2) {
        //hash is created:)
    }
    inline int get_ID() const { return ID; }
    inline string get_sender() const { return sender_key; }
    inline string get_getter() const { return getter_key; }
    inline int get_amount() const { return amount; }
    friend std::ostream& operator<<(std::ostream& out, const transaction& v);
    ~transaction() {}
};

class block {
    private: 
    vector<transaction> TX;
    string version;
    long int nonce;
    time_t timestamp;
    string prev_block;
    string merkle;
    string difficultyTarget;
    public:
    block() {
    version = "0100000";
    timestamp = time(nullptr);
    difficultyTarget = "0000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
    }
    void headerHash(){
        string input = version + prev_block + merkle + difficultyTarget + std::to_string(timestamp);
        hash(input);
    }
    inline string get_time() const { return std::to_string(timestamp); }
    inline string get_version() const { return version; }
    inline string get_previous() const { return prev_block; }
    inline string get_merkle_hash() const { return merkle; }
    inline int get_amount() const { return amount; }
    inline int get_amount() const { return amount; }
    ~block() {}
};
string generateRandomHashKey(int);
void gen_user(vector<user>&);
void gen_trans(vector<user>&, vector<transaction>&);
void processBlock(const string&, int, int, string&);
void hash(string);
