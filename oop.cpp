#include <iostream>
#include <vector>
#include <string>

class Fish {
protected:
    std::string species;
    double size;
    double swimSpeed;

public:
    Fish(std::string species, double size, double swimSpeed) : species(species), size(size), swimSpeed(swimSpeed) {}
    virtual void swim() = 0;
};

class TropicalFish : public Fish {
private:
    double requiredWaterTemperature;

public:
    TropicalFish(std::string species, double size, double swimSpeed, double temp) : Fish(species, size, swimSpeed), requiredWaterTemperature(temp) {}
    void swim() override {
        std::cout << "Tropical fish swimming in warm water." << std::endl;
    }
};

class ColdWaterFish : public Fish {
private:
    std::string activityPeriod;

public:
    ColdWaterFish(std::string species, double size, double swimSpeed, std::string period) : Fish(species, size, swimSpeed), activityPeriod(period) {}
    void swim() override {
        std::cout << "Cold water fish swimming." << std::endl;
    }
};

class Plant {
private:
    std::string species;
    double height;
    double requiredLightLevel;

public:
    Plant(std::string species, double height, double lightLevel) : species(species), height(height), requiredLightLevel(lightLevel) {}

    void grow(double light, double nutrients) {
    if (light >= requiredLightLevel && nutrients > 0) {
        height += 0.1;
        std::cout << "Растение выросло" << std::endl;
    } else {
        std::cout << "Растение не может расти без света" << std::endl;
    }
}
};

class Filter {
private:
    std::string filterType;
    double power;

public:
    Filter(std::string type, double power) : filterType(type), power(power) {}
    void turnOn() {
        std::cout << "Фильтр включен" << std::endl;
    }

    void turnOff() {
        std::cout << "Фильтр выключен" << std::endl;
    }
};

class Lighting {
private:
    std::string lampType;
    double brightness;

public:
    Lighting(std::string type, double brightness) : lampType(type), brightness(brightness) {}
    void turnOn() {
        std::cout << "Свет включен" << std::endl;
    }

    void turnOff() {
        std::cout << "Свет выключен" << std::endl;
    }

    void changeBrightness(double brightness) {
        this->brightness = brightness;
        std::cout << "Яркость установлена на " << brightness << "." << std::endl;
    }
};

class Decoration {
private:
    std::string type;
    std::string material;

public:
    Decoration(std::string type, std::string material) : type(type), material(material) {}
    void clean() {
        std::cout << "Декорации очищены" << std::endl;
    }

    void changePosition(std::string position) {
        std::cout << "Положение декорации изменено на " << position << "." << std::endl;
    }
};

class Aquarium {
private:
    struct Size {
        double length;
        double width;
        double height;
    } size;
    std::string waterType;
    double waterTemperature;
    std::vector<Fish*> fishes;
    std::vector<Plant> plants;
    Filter* filter;
    Lighting* lighting;
    std::vector<Decoration> decorations;

public:
    Aquarium(double length, double width, double height, std::string waterType) : waterType(waterType) {
        size.length = length;
        size.width = width;
        size.height = height;
    }
    void addFish(Fish* fish) {
        fishes.push_back(fish);
    }
    void addPlant(Plant plant) {
        plants.push_back(plant);
    }
    void changeTemperature(double temperature) {
        waterTemperature = temperature;
    }
};

int main() {
    Aquarium myAquarium(100, 50, 50, "Freshwater");
    TropicalFish* clownFish = new TropicalFish("Clownfish", 10, 5, 26);
    ColdWaterFish* goldfish = new ColdWaterFish("Goldfish", 15, 3, "Day");

    myAquarium.addFish(clownFish);
    myAquarium.addFish(goldfish);

    delete clownFish;
    delete goldfish;

    return 0;
}
