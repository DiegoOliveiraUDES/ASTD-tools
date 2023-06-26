#include <iostream>
#include <cmath>

void blinkLightsOn(float&  blinkLeft, float& blinkRight, float& lowBeamLeft, float& lowBeamRight, float& tailLampLeft, float& tailLampRight, std::string pitmanArmUD, bool hazardSwitch, int voltage, int marketCode){
    if(hazardSwitch){
        if(marketCode == 1 || marketCode == 2){
            if(voltage > 145){
                blinkLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                blinkRight = 100 + (100 - (voltage - 145) * 20) / 100;
                tailLampRight = 100 + (100 - (voltage - 145) * 20) / 100;
                tailLampLeft = 100 + (100 - (voltage - 145) * 20) / 100;
            }
            else{
                blinkRight = 100;
                blinkLeft = 100;
                tailLampRight = 100;
                tailLampLeft = 100;
            }
            if(lowBeamRight > 0){
                if(voltage > 145){
                    lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                }
                else{
                    lowBeamRight = 50;
                }
            }
            if(lowBeamLeft > 0){
                if(voltage > 145){ 
                    lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                }
                else{
                    lowBeamLeft = 50;
                }
            }
        }
        else{
            if(voltage > 145){
                blinkLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                blinkRight = 100 + (100 - (voltage - 145) * 20) / 100;
            }
            else{
                blinkRight = 100;
                blinkLeft = 100;
            }
        }
    }
    else{
        if(pitmanArmUD == "Upward5" || pitmanArmUD == "Upward7"){
            if((marketCode == 1 || marketCode == 2)){
                if(pitmanArmUD == "Upward7"){
                    if(voltage > 145){
                        blinkRight = 100 + (100 - (voltage - 145) * 20) / 100;
                        lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                        blinkLeft = 0;
                        tailLampRight = 100 + (100 - (voltage - 145) * 20) / 100;
                        tailLampLeft = 0;
                    }
                    else{
                        blinkRight = 100;
                        lowBeamRight = 100 * 0.5;
                        blinkLeft = 0;
                        tailLampRight = 0;
                        tailLampLeft = 0;
                    }
                }
                else{
                    //Upward5 -> Tip blinking -> no direction blinking
                    if(voltage > 145){
                        blinkRight = 100 + (100 - (voltage - 145) * 20) / 100;
                        lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                        blinkLeft = 0;
                        tailLampRight = 100 + (100 - (voltage - 145) * 20) / 100;
                        tailLampLeft = 0;
                    }
                    else{
                        blinkRight = 100;
                        lowBeamRight = 100 * 0.5;
                        blinkLeft = 0;
                        tailLampRight = 100;
                        tailLampLeft = 0;
                    }
                }
            }
            else{
                if(voltage > 145){
                    blinkRight = 100 + (100 - (voltage - 145) * 20) / 100;
                    blinkLeft = 0;
                }
                else{
                    blinkRight = 100;
                    blinkLeft = 0;
                }
            }
        }
        if(pitmanArmUD == "Downward5" || pitmanArmUD == "Downward7"){
            if((marketCode == 1 || marketCode == 2)){
                if(pitmanArmUD == "Downward7"){
                    if(voltage > 145){
                        blinkRight = 0;
                        blinkLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                        lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                        tailLampRight = 0;
                        tailLampLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                    }
                    else{
                        blinkRight = 0;
                        blinkLeft = 100;
                        lowBeamLeft = 100 * 0.5;
                        tailLampRight = 0;
                        tailLampLeft = 0;
                    }
                }
                else{
                    //Downward5 -> Tip blinking -> no direction blinking
                    if(voltage > 145){
                        blinkRight = 0;
                        blinkLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                        lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                        tailLampRight = 0;
                        tailLampLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                    }
                    else{
                        blinkRight = 0;
                        blinkLeft = 100;
                        lowBeamLeft = 100 * 0.5;
                        tailLampRight = 0;
                        tailLampLeft = 100;
                    }
                }
            }
            else{
                if(voltage > 145){
                    blinkRight = 0;
                    blinkLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                }
                else{
                    blinkRight = 0;
                    blinkLeft = 100;
                }
            }
        }
    }
}

void blinkLightsOff(float&  blinkLeft, float& blinkRight, float& lowBeamLeft, float& lowBeamRight, float& tailLampLeft, float& tailLampRight, int marketCode, int voltage, bool blinking, std::string pitmanArmUD){
    if((marketCode == 1) || marketCode == 2){
        tailLampLeft = 0;
        tailLampRight = 0;
        if(lowBeamLeft > 0){
            if(blinking && (pitmanArmUD == "Downward5" || pitmanArmUD == "Downward7" || pitmanArmUD == "Hazard")){
                if(voltage > 145){ 
                    lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                }
                else{
                    lowBeamLeft = 50;
                }
            }
            else{
                if(voltage > 145){ 
                    lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100);
                }
                else{
                    lowBeamLeft = 100;
                }
            }
        }
        if(lowBeamRight > 0){
            if(blinking && (pitmanArmUD == "Upward5" || pitmanArmUD == "Upward7" || pitmanArmUD == "Hazard")){
                if(voltage > 145){
                    lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                }
                else{
                    lowBeamRight = 50;
                }
            }
            else{
                if(voltage > 145){
                    lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100);
                }
                else{
                    lowBeamRight = 100;
                }   
            }
        }
    }
    blinkRight = 0;
    blinkLeft = 0;
}


void lowBeamsOn(float& lowBeamLeft, float& lowBeamRight, float& tailLampLeft, float& tailLampRight, int voltage, bool blinking, bool hazardSwitch, int marketCode, std::string pitmanArmUD){
    if(blinking && (marketCode == 1 || marketCode == 2) && (hazardSwitch || (pitmanArmUD == "Upward7" || pitmanArmUD == "Downward7"))){
        if(hazardSwitch){
            if(voltage > 145){
                lowBeamLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                lowBeamRight = 100 + (100 - (voltage - 145) * 20) / 100;
            }
            else{
                lowBeamRight = 100;
                lowBeamLeft = 100;
            }
        }
        else if(pitmanArmUD == "Upward7"){
            if(voltage > 145){
                lowBeamLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
            }
            else{
                lowBeamRight = 100 * 0.5;
                lowBeamLeft = 100;
            }
        }
        else{ //pitmanArmUD == "Downward7"
            if(voltage > 145){
                lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                lowBeamRight = 100 + (100 - (voltage - 145) * 20) / 100;
            }
            else{
                lowBeamRight = 100;
                lowBeamLeft = 100 * 0.5;
            }
        }    
    }
    else{
        if((marketCode == 1 || marketCode == 2)){
            if(voltage > 145){
                lowBeamLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                lowBeamRight = 100 + (100 - (voltage - 145) * 20) / 100;
                tailLampLeft = 0;
                tailLampRight = 0;
            }
            else{
                lowBeamRight = 100;
                lowBeamLeft = 100;
                tailLampLeft = 0;
                tailLampRight = 0;
            }
        }
        else{
            if(voltage > 145){
                lowBeamLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                lowBeamRight = 100 + (100 - (voltage - 145) * 20) / 100;
                tailLampLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                tailLampRight = 100 + (100 - (voltage - 145) * 20) / 100;
            }
            else{
                lowBeamRight = 100;
                lowBeamLeft = 100;
                tailLampLeft = 100;
                tailLampRight = 100;
            }
        }
    }
}

void lowBeamsHalf(float& lowBeamLeft, float& lowBeamRight, float& tailLampLeft, float& tailLampRight, int voltage, bool blinking, bool hazardSwitch, int marketCode, std::string pitmanArmUD){
    if(blinking && (marketCode == 1 || marketCode == 2) && (hazardSwitch || (pitmanArmUD == "Upward7" || pitmanArmUD == "Downward7"))){
        if(hazardSwitch){
            if(voltage > 145){
                lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
            }
            else{
                lowBeamRight = 100*0.5;
                lowBeamLeft = 100*0.5;
            }
        }
        else if(pitmanArmUD == "Upward7"){
            if(voltage > 145){
                lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5 * 0.5;
            }
            else{
                lowBeamRight = 100 * 0.5;
                lowBeamLeft = 100;
            }
        }
        else{ //pitmanArmUD == "Downward7"
            if(voltage > 145){
                lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
            }
            else{
                lowBeamRight = 100 * 0.5;
                lowBeamLeft = 100 * 0.5 * 0.5;
            }
        }    
    }
    else{
        if((marketCode == 1 || marketCode == 2)){
            if(voltage > 145){
                lowBeamLeft = 100 + (100 - (voltage - 145) * 20) / 100;
                lowBeamRight = 100 + (100 - (voltage - 145) * 20) / 100;
                tailLampLeft = 0;
                tailLampRight = 0;
            }
            else{
                lowBeamRight = 100;
                lowBeamLeft = 100;
                tailLampLeft = 0;
                tailLampRight = 0;
            }
        }
        else{
            if(voltage > 145){
                lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100)  * 0.5;
                tailLampLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
                tailLampRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.5;
            }
            else{
                lowBeamRight = 100 * 0.5;
                lowBeamLeft = 100 * 0.5;
                tailLampLeft = 100 * 0.5;
                tailLampRight = 100 * 0.5;
            }
        }   
    }
}

void lowBeamsParkingLight(float& lowBeamLeft, float& lowBeamRight, float& tailLampLeft, float& tailLampRight, int voltage, bool blinking, bool hazardSwitch, int marketCode, std::string pitmanArmUD){
    if((marketCode == 1 || marketCode == 2) && blinking && hazardSwitch){
        if(pitmanArmUD == "Upward7"){
            if(voltage > 145){
                lowBeamLeft = 0 * 0.1;
                lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100)  * 0.1;
            }
            else{
                lowBeamRight = 100 * 0.1;
                lowBeamLeft = 0 * 0.1;
            }
        }
        else{ //Downward7
            if(voltage > 145){
                lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.1;
                lowBeamRight = 0  * 0.1;
            }
            else{
                lowBeamRight = 0 * 0.1;
                lowBeamLeft = 100 * 0.1;
            }
        }
    }
    else{
        if(pitmanArmUD == "Upward7"){
            if((marketCode == 1 || marketCode == 2)){
                if(voltage > 145){
                    lowBeamLeft = 0 * 0.1;
                    lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100)  * 0.1;
                    tailLampLeft = 0 * 0.1;
                    tailLampRight = 0;
                }
                else{
                    lowBeamRight = 100 * 0.1;
                    lowBeamLeft = 0 * 0.1;
                    tailLampLeft = 0 * 0.1;
                    tailLampRight = 0;
                }
            }
            else{      
                if(voltage > 145){
                    lowBeamLeft = 0 * 0.1;
                    lowBeamRight = (100 + (100 - (voltage - 145) * 20) / 100)  * 0.1;
                    tailLampLeft = 0 * 0.1;
                    tailLampRight = (100 + (100 - (voltage - 145) * 20) / 100) * 0.1;
                }
                else{
                    lowBeamRight = 100 * 0.1;
                    lowBeamLeft = 0 * 0.1;
                    tailLampLeft = 0 * 0.1;
                    tailLampRight = 100 * 0.1;
                }
            }
        }
        else{ //Downward7
            if((marketCode == 1 || marketCode == 2)){
                if(voltage > 145){
                    lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.1;
                    lowBeamRight = 0  * 0.1;
                    tailLampLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0;
                    tailLampRight = 0 * 0.1;
                }
                else{
                    lowBeamRight = 0 * 0.1;
                    lowBeamLeft = 100 * 0.1;
                    tailLampLeft = 0 * 0.1;
                    tailLampRight = 0 * 0.1;
                }
            }
            else{
                if(voltage > 145){
                    lowBeamLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.1;
                    lowBeamRight = 0  * 0.1;
                    tailLampLeft = (100 + (100 - (voltage - 145) * 20) / 100) * 0.1;
                    tailLampRight = 0 * 0.1;
                }
                else{
                    lowBeamRight = 0 * 0.1;
                    lowBeamLeft = 100 * 0.1;
                    tailLampLeft = 100 * 0.1;
                    tailLampRight = 0 * 0.1;
                }
            }
        }
    }
}

void lowBeamsOff(float& lowBeamLeft, float& lowBeamRight, float& tailLampLeft, float& tailLampRight, bool blinking, bool hazardSwitch, int marketCode, std::string pitmanArmUD){
    if(!(blinking && (marketCode == 1 || marketCode == 2) && (hazardSwitch || (pitmanArmUD == "Upward7" || pitmanArmUD == "Downward7")))){
        tailLampRight = 0;
        tailLampLeft = 0;
    }
    lowBeamLeft = 0;
    lowBeamRight = 0;
}

//void lowBeamsCheck(float& lowBeamLeft, float& lowBeamRight, float& tailLampLeft, float& tailLampRight, int voltage, bool blinking, bool hazardSwitch, int marketCode, std::string pitmanArmUD, int brightnessSensor){
//    if(brightnessSensor >= 250){
//        lowBeamsOff(lowBeamLeft, lowBeamRight, tailLampLeft, tailLampRight, blinking, hazardSwitch, marketCode, pitmanArmUD);
//    }
//    else{
//        lowBeamsOn(lowBeamLeft, lowBeamRight, tailLampLeft, tailLampRight, voltage, blinking, hazardSwitch, marketCode, pitmanArmUD);
//    }
//}

void corneringLightOn(float& corneringLightLeft, float& corneringLightRight, int voltage, bool left, bool right){
    if(left && right){
        if(voltage > 145){
            corneringLightLeft = 100 + (100 - (voltage - 145) * 20) / 100;
            corneringLightRight = 100 + (100 - (voltage - 145) * 20) / 100;
        }
        else{
            corneringLightRight = 100;
            corneringLightLeft = 100;
        }
    }
    else if(left){
        if(voltage > 145){
            corneringLightLeft = 100 + (100 - (voltage - 145) * 20) / 100;
            corneringLightRight = 0;
        }
        else{
            corneringLightLeft = 100;
            corneringLightRight = 0;
        }
    }
    else if(right){
        if(voltage > 145){
            corneringLightLeft = 0;
            corneringLightRight = 100 + (100 - (voltage - 145) * 20) / 100;
        }
        else{
            corneringLightLeft = 0;
            corneringLightRight = 100;
        }
    }
}

void corneringLightFadeOut(float& corneringLightLeft, float& corneringLightRight, float fadeValue){
    if(corneringLightLeft > 10){
        corneringLightLeft = corneringLightLeft - fadeValue;
    }
    else{
        corneringLightLeft = 0;
    }
    if(corneringLightRight > 10){
        corneringLightRight = corneringLightRight - fadeValue;
    }
    else{
        corneringLightRight = 0;
    }
}

void highBeamOnFixed(int& fixedIlluminationArea, int& highBeamMotor, int voltage){
    // if(voltage > 145){
    //     highBeamLights = fixedIlluminationArea + (100 - (voltage - 145) * 20) / 100;
    // }
    // else{
    //     highBeamLights = ;
    fixedIlluminationArea = 220;
    highBeamMotor = 7;
}

void highBeamAuto(int& highBeamMotor, int& fixedIlluminationArea, float speed, int voltage, float desiredSpeed, bool cruiseOn, int cruiseControlMode){
    // if(voltage > 145){
        // highBeamLights = (7 * speed + 60) / 90 + (100 - (voltage - 145) * 20) / 100;
    //     fixedIlluminationArea = 220;
    // }
    // else{
        // highBeamLights =;
    if(speed <= 171){
        if(cruiseOn && cruiseControlMode == 2){
            fixedIlluminationArea = double (std::pow(desiredSpeed, 2.2)) * 0.0025 + 95;
            if(fixedIlluminationArea < 100){
                fixedIlluminationArea = 100;
            }
        }
        else{
            fixedIlluminationArea = double (std::pow(speed, 2.2)) * 0.0025 + 95;
            if(fixedIlluminationArea < 100){
                fixedIlluminationArea = 100;
            }
        }
        if(fixedIlluminationArea >= 100 && fixedIlluminationArea < 120){
            highBeamMotor = 1;
        }
        else{
            highBeamMotor = (fixedIlluminationArea - 120) / 30 + 2;
        }
    }
    else{
        fixedIlluminationArea = 300;
        highBeamMotor = 12;
    }
}

void highBeamCar(int& highBeamMotor, int& fixedIlluminationArea, int voltage){
    // if(voltage > 145){
    //     fixedIlluminationArea = 30 + (100 - (voltage - 145) * 20) / 100;
    // }
    // else{    
    // }
    fixedIlluminationArea = 65;
    highBeamMotor = 0;
}

void reverseLightOn(float& reverseLight, int voltage){
    if(voltage > 145){
        reverseLight = 100 + (100 - (voltage - 145) * 20) / 100;
    }
    else{
        reverseLight = 100;
    }
}

void brakeLightOn(float& brakeLight, int voltage){
    if(voltage > 145){
        brakeLight = 100 + (100 - (voltage - 145) * 20) / 100;
    }
    else{
        brakeLight = 100;
    }
}