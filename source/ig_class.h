#include <vector>
#include <string>

using namespace::std;

class Critter{
    friend void Peek(const Critter& crita);
    friend ostream& operator<< (ostream& os, const Critter& crita);
    public:
        void setHunger(int hunger);
        int getHunger(void);
        string name;
        static int getTotal(void); // static function call be called by class
        void greed();
        Critter(int mHunger = 99, const string &name = "asd");
        ~Critter();
        Critter(const Critter& c);
        Critter& operator= (const Critter& c ); // overload

    private:
        static int totalCount;
        int mHunger;
        string* pName;  
};

class Farm{
    public:
        Farm(int spaces = 1);
        void Add(const Critter &crit);
        void RollCall() const; // get function
    private:
        vector<Critter> mCritters;
};

class Enemy{
    public:
        Enemy();
        void attack();
        void virtual speak(); // made them virtual for overwriting
    private:
        int live;
    protected:
        int damage;
};

class Boss : public Enemy{
    public:
        int power;
        Boss();
        void specialAttack();
        void virtual speak();
    private:
        int backup;
};

void classRunner();
void Peek(const Critter& crita);
ostream& operator<< (ostream& os, const Critter& crita);