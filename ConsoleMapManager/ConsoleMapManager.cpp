// ConsoleMapManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#include <iostream>

#include <MapManager.h>

using namespace TheWorld_MapManager;

int main()
{
    bool test = true;

    if (test)
    {
        std::cout << "ConsoleMapManager: Test ...\n\n";

        try
        {
            MapManager mapManager;
            mapManager.instrument(true);
            mapManager.debugMode(true);

            mapManager.LoadGISMap("D:\\TheWorld\\Prove\\untitled2.shp", true);
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
    else
    {
        std::cout << "ConsoleMapManager ...\n\n";

        try
        {
            MapManager mapManager;
            mapManager.instrument(true);
            mapManager.debugMode(true);

            mapManager.LoadGISMap("D:\\TheWorld\\Prove\\untitled2.shp", true);

            WorldDefiner WD1(2, 3, WDType::elevator, WDFunctionType::cosin, (float)0.5, (float)50);
            WorldDefiner WD2(3, 4, WDType::elevator, WDFunctionType::cosin, (float)0.7, (float)50);

            mapManager.eraseWD(WD1);
            //mapManager.UpdateValues();
            mapManager.eraseWD(WD2);
            //mapManager.UpdateValues();

            __int64 rowid = mapManager.addWD(WD1);
            rowid = mapManager.addWD(WD2);
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
}

void provaProj()
{
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
