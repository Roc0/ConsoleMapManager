// ConsoleMapManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#include <iostream>

#include <MapManager.h>

using namespace TheWorld_MapManager;

int main()
{
    std::cout << "ConsoleMapManager ...\n\n";

    try
    {
        MapManager mapManager;
        mapManager.instrument(true);
        mapManager.debugMode(true);
        
        WorldDefiner WD1(2, 3, WDType::elevator, (float)0.5, (float)50);
        mapManager.addWD(WD1);
        
        WorldDefiner WD2(3, 4, WDType::elevator, (float)0.7, (float)50);
        mapManager.addWD(WD2);

        mapManager.UpdateValues();
        
        mapManager.finalizeDB();
    }
    catch (MapManagerException& e)
    {
        std::cout << e.exceptionName() << " caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "std::exception caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Generic exception caught" << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
