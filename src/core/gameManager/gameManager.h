#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class GameManager{
private:
    json data; 

public:

    GameManager();
    auto* getvariable( const std::string& variable_name );

};
