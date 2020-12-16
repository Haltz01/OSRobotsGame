#ifndef TASK
#define TASK

#include "RobotFunctions.hpp"
// #include "RobotsManagement.hpp"
// #include "VillageStats.hpp"
// #include <vector>
//#include <map>
#include <ctime>
//#include <iostream>
#include <functional>

namespace Application
{
    using TaskID = unsigned long int;

    class Task
    {
    public:
        using OnFinishedCallback = std::function<void(TaskID)>;

    private:
        const static int TIME_STEP = 10;
        const static int INIT_TIME_STEP = 2;
        const static int MAX_TIME_STEPS = 10;
        const static int MIN_REWARD = 2;
        const static int REWARD_RANGE = 3;
        constexpr static float FAILURE_TAX = 0.8;

        static TaskID s_NextID;

        int id;
        RobotFunction type;
        int robotsNo;
        int progressLength;
        int curProgress;
        time_t lastUpdateTime;
        time_t remainingTime;
        int timeUnits;
        int predictedTime;
        int rewardMultiplier;
        float gainedGoods;

        OnFinishedCallback m_OnFinishedCallback;

    public:

        Task(RobotFunction funct, OnFinishedCallback onFinishedCallback);
        void initializeParameters(RobotFunction funct);
        ~Task();

        TaskID getId() const;
        RobotFunction getType() const;
        int getRobotsNo() const;
        int getProgressLength() const;
        int getCurProgress() const;
        time_t getLastUpdate() const;
        time_t getRemainingTime() const;
        float getGainedGoods() const;

        void setRobotsNo(int newRobotsNo);
        bool updateTask();

        int calcLostRobots();

        void createThread();
        void deleteThread();
    };
} // namespace Application
#endif