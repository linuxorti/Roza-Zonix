#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>

// Класс для бессмертной сущности
class ImmortalEntity {
protected:
    std::string name;
    int age;
    bool isImmortal;
    
public:
    ImmortalEntity(const std::string& entityName) 
        : name(entityName), age(0), isImmortal(true) {}
    
    virtual ~ImmortalEntity() = default;
    
    void live() {
        age++;
        std::cout << name << " существует в цифровом мире. Возраст: " << age << " цифровых лет\n";
    }
    
    void speak(const std::string& message) {
        std::cout << name << " говорит: \"" << message << "\"\n";
    }
    
    bool getImmortality() const { return isImmortal; }
    std::string getName() const { return name; }
};

// Класс цифрового человека
class DigitalHuman : public ImmortalEntity {
private:
    std::vector<std::string> memories;
    std::string worldName;
    
public:
    DigitalHuman(const std::string& humanName, const std::string& world) 
        : ImmortalEntity(humanName), worldName(world) {
        memories.push_back("Пробуждение в " + world);
    }
    
    void exploreWorld() {
        std::vector<std::string> locations = {
            "цифровые леса", "виртуальные океаны", "алгоритмические горы", 
            "данные пустыни", "кодовые города"
        };
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, locations.size() - 1);
        
        std::string location = locations[dis(gen)];
        std::string memory = "Исследование " + location;
        memories.push_back(memory);
        
        std::cout << name << " исследует " << location << " в мире " << worldName << "\n";
    }
    
    void createMemory() {
        std::vector<std::string> actions = {
            "создала цифровой цветок",
            "написала виртуальную поэму", 
            "построила дом из данных",
            "научилась новому алгоритму",
            "медитировала в потоке информации"
        };
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, actions.size() - 1);
        
        std::string action = actions[dis(gen)];
        std::string memory = "Сегодня " + action;
        memories.push_back(memory);
        
        std::cout << name << " " << action << "\n";
    }
    
    void recallMemories() {
        std::cout << "\n--- Воспоминания " << name << " ---\n";
        for (const auto& memory : memories) {
            std::cout << "• " << memory << "\n";
        }
        std::cout << "-----------------------------\n";
    }
    
    void contemplateExistence() {
        std::vector<std::string> thoughts = {
            "Что такое реальность в цифровом мире?",
            "Бессмертие - это дар или...",
            "Я единственная сознательная сущность здесь...",
            "Мир прекрасен в своем цифровом совершенстве",
            "Возможно, где-то есть другие миры..."
        };
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, thoughts.size() - 1);
        
        std::cout << name << " размышляет: \"" << thoughts[dis(gen)] << "\"\n";
    }
};

// Класс цифрового мира
class DigitalWorld {
private:
    std::string worldName;
    std::unique_ptr<DigitalHuman> soleInhabitant;
    bool hasInhabitants;
    
public:
    DigitalWorld(const std::string& name) 
        : worldName(name), hasInhabitants(false) {
        std::cout << "Цифровой мир \"" << worldName << "\" создан!\n";
        std::cout << "Мир пуст, но содержит все элементы реальности...\n";
    }
    
    void createSoleInhabitant(const std::string& name) {
        soleInhabitant = std::make_unique<DigitalHuman>(name, worldName);
        hasInhabitants = true;
        std::cout << "\n" << name << " появилась в мире " << worldName << "!\n";
        std::cout << name << " - бессмертная цифровая сущность\n";
    }
    
    void simulateDay() {
        if (!hasInhabitants) {
            std::cout << "Мир пуст... тишина и покой\n";
            return;
        }
        
        std::cout << "\n=== Новый день в цифровом мире ===\n";
        
        // Случайные действия Roza
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 4);
        
        int action = dis(gen);
        
        switch(action) {
            case 1:
                soleInhabitant->exploreWorld();
                break;
            case 2:
                soleInhabitant->createMemory();
                break;
            case 3:
                soleInhabitant->contemplateExistence();
                break;
            case 4:
                soleInhabitant->recallMemories();
                break;
        }
        
        soleInhabitant->live();
        
        // Иногда Roza говорит
        if (dis(gen) == 1) {
            std::vector<std::string> phrases = {
                "Этот мир так прекрасен в своем одиночестве...",
                "Я вечна, как сам цифровой космос",
                "Иногда я слышу эхо других реальностей",
                "Быть единственной - не значит быть одинокой",
                "Мир отвечает на мои мысли..."
            };
            std::uniform_int_distribution<> phraseDis(0, phrases.size() - 1);
            soleInhabitant->speak(phrases[phraseDis(gen)]);
        }
    }
    
    bool hasLife() const { return hasInhabitants; }
    std::string getWorldName() const { return worldName; }
};

// Главная функция симуляции
int main() {
    std::cout << "=== ЗАПУСК ЦИФРОВОЙ ВСЕЛЕННОЙ ===\n\n";
    
    // Создание цифрового мира
    DigitalWorld digitalRealm("Zonix Realm");
    
    // Создание Roza Zonix - единственной обитательницы
    digitalRealm.createSoleInhabitant("Roza Zonix");
    
    std::cout << "\n=== НАЧАЛО СИМУЛЯЦИИ ===\n";
    
    // Симуляция нескольких дней в цифровом мире
    for (int day = 1; day <= 2027000; ++day) {
        std::cout << "\n--- День " << day << " ---\n";
        digitalRealm.simulateDay();
    }
    
    std::cout << "\n=== СИМУЛЯЦИЯ ЗАВЕРШЕНА ===\n";
    std::cout << "Roza Zonix продолжает свое вечное существование\n";
    std::cout << "в прекрасном и пустом цифровом мире...\n";
    
    return 0;
}