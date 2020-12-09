#ifndef ROBOTS_MANAGEMENT
#define ROBOTS_MANAGEMENT

#include "RobotFunctions.hpp"
#include "Task.hpp"
#include "VillageStats.hpp"
#include <vector>
#include <map> 
#include <ctime>


class RobotsManagement{

    private:
        int totRobots;
        int freeRobots;
        int efficiency;
        int prodCost;
        VillageStats *villageStats;
        std::vector<std::map<int,Task>> *tasks;

    public:
        RobotsManagement();
        void initializeStats();
        ~RobotsManagement();

        int getTotRobots() const;
        int getFreeRobots() const;
        int getEfficiency() const;
        int getProdCost() const;

        void setTotRobots(int newTotRobots);
        void setFreeRobots(int newFreeRobots);
        void setEfficiency(int newEfficiency);
        void setProdCost(int newProdCost);
        void setVillageStats(VillageStats *newVillageStats);
        void setTasks(std::vector<std::map<int, Task>> *newTasks);

        bool createRobot();
        bool destroyRobot();
        void createTask(RobotFunctions::RobotFunction funct);
        bool moveRobot(Task choosenTask,int robotNo);
};
#endif