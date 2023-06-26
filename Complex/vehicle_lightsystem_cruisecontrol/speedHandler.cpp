#include <iostream>
#include <cmath>
#include <chrono>
#include <ctime>

void setStartDesiredSpeed(float& desiredSpeed, float newDesiredSpeed, float& lastDesiredOver120){
    if(desiredSpeed == 0){
        desiredSpeed = newDesiredSpeed;
    }
    if(desiredSpeed > 120){
        lastDesiredOver120 = desiredSpeed;
    }
}

void changeDesiredSpeed(float& desiredSpeed, std::string SCSLever, float& lastDesiredOver120){
    if(SCSLever == "Upward5"){
        desiredSpeed++;
    }
    if(SCSLever == "Upward7"){
        int ten = desiredSpeed / 10;
        desiredSpeed = ten * 10 + 10;
    }
    if(SCSLever == "Downward5"){
        desiredSpeed--;
    }
    if(SCSLever == "Downward7"){
        int ten = desiredSpeed / 10;
        desiredSpeed = ten * 10 - 10;
        if(desiredSpeed < 0){
            desiredSpeed = 0;
        }
    }
    if(desiredSpeed > 120){
        lastDesiredOver120 = desiredSpeed;
    }
}

bool emergencyBrakeStage1(float currentSpeed, float rangeRadarSensor){
    if(rangeRadarSensor == 0){
        return false;
    }
    float standStill = currentSpeed / (3.6 * 6);
    float impact = rangeRadarSensor / currentSpeed * 3.6;
    if(impact <= standStill + 3 && impact > standStill + 1.5){
        return true;
    }
    return false;
}

bool emergencyBrakeStage2(float currentSpeed, float rangeRadarSensor){
    if(rangeRadarSensor == 0){
        return false;
    }
    float standStill = currentSpeed / (3.6 * 6);
    float impact = rangeRadarSensor / currentSpeed * 3.6;
    if(impact <= standStill + 1.5 && impact > standStill){
        return true;
    }
    return false;
}

bool emergencyBrakeStage3(float currentSpeed, float rangeRadarSensor){
    if(rangeRadarSensor == 0){
        return false;
    }
    float standStill = currentSpeed / (3.6 * 6);
    float impact = rangeRadarSensor / currentSpeed * 3.6;
    if(impact <= standStill){
        return true;
    }
    return false;
}

float calculateNewSpeed(float currentSpeed, int speedMode, int emergencyBrake, float gasPedal, float brakePedal, bool reverseGear, std::time_t deltaT, float setVehicleSpeed, bool speedLimit){
    float a = 0;
    float newSpeed;
    if(!reverseGear){
        if(emergencyBrake == 1){
            a = -3.0;
        }
        else if(emergencyBrake == 2){
            a = -3.6;
        }
        else if(emergencyBrake == 3){
            a = -6.0;
        }
        else{
            if(speedMode == 2){
                a = gasPedal * 3.0 / 45.0;
            }
            else if(speedMode == 1){
                a = 1.0;
            }
            else if(speedMode == -1){
                a = -3.0;
            }
            else if (speedMode == -2){
                a = - brakePedal * 6.0 / 45.0;
            }
            else if(speedMode == 0){
                return currentSpeed;
            }
        }
        newSpeed = (1.0/1000.0 * a * deltaT * 1.0/1000000000.0 * 3600.0) + currentSpeed;
        if(newSpeed <= 250 && newSpeed >= 0){
            if(speedLimit && newSpeed > setVehicleSpeed && (speedMode == 1 || speedMode == 2)){
                return setVehicleSpeed;
            }
            return newSpeed;
        }
        if(newSpeed < 0){
            return 0;
        }
        return 250;
    }
    else{
        if(speedMode == 2){
            a = gasPedal * 3.0 / 45.0;
        }
        if(speedMode == 1){
            a = 1.0;
        }
        if(speedMode == -1){
            a = -3.0;
        }
        if (speedMode == -2){
            a = - brakePedal * 6.0 / 45.0;
        }
        else if(speedMode == 0){
            return currentSpeed;
        }
        newSpeed = (1.0/1000.0 * a * deltaT * 1.0/1000000000.0 * 3600.0) + currentSpeed;
        if(newSpeed < 20 && newSpeed >= 0){
            return newSpeed;
        }
        if(newSpeed < 0){
            return 0;
        }
        return 20;
    }
}

void modifyWithSign(std::string val, float& desiredSpeed, float lastDesiredOver120){
    bool digit = true;

    for(int i = 0; i < val.size(); i++){
        if(!isdigit(val[i])) digit = false;
    }

    if (digit){
        desiredSpeed = std::stoi(val);   
    }
    else if(val == "Unlimited"){
        if(lastDesiredOver120 >= 120){
            desiredSpeed = lastDesiredOver120;
        }
        if(desiredSpeed < 120){
            desiredSpeed = 120;
        }
    }
}

