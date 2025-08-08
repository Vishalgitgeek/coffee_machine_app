#include <map>
#include <vector>
#include <string>

using namespace std;

class Coffee{
    private:
        string name;
        map<string, int> recipe;

    public:
        Coffee(string name, map<string, int> recipe);
        const string& getName() const;
        const map<string, int>& getRecipe() const;

};