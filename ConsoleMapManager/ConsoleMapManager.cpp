// ConsoleMapManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#include <iostream>

#include <MapManager.h>

using namespace TheWorld_MapManager;

int main()
{
    int test = 4;

    consoleDebugUtil debugUtil(true);
    TimerMs clock(true, true); // Timer<milliseconds, steady_clock>
    clock.tick();

    std::cout << "ConsoleMapManager ...\n\n";

    if (test == 1)
    {
        try
        {
            MapManager::staticInit(nullptr, plog::debug, plog::get(), true);
			
			MapManager mapManager(NULL);
            mapManager.instrument(true);
            mapManager.consoleDebugMode(true);

            mapManager.LoadGISMap("D:\\TheWorld\\Prove\\untitled2.shp", true);
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
    else if (test == 2)
    {
        try
        {
            MapManager::staticInit(nullptr, plog::debug, plog::get(), true);

            MapManager mapManager(NULL);
            mapManager.instrument(true);
            mapManager.consoleDebugMode(true);

            mapManager.LoadGISMap("D:\\TheWorld\\Prove\\untitled2.shp", true);

            WorldDefiner WD1(2, 3, WDType::elevator, WDFunctionType::MaxEffectOnWD, (float)0.5, (float)50);
            WorldDefiner WD2(3, 4, WDType::elevator, WDFunctionType::MaxEffectOnWD, (float)0.7, (float)50);

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
    else if (test == 3)
    {
        try
        {
            MapManager::staticInit(nullptr, plog::debug, plog::get(), true);

            MapManager mapManager(NULL);
            mapManager.instrument(true);
            mapManager.consoleDebugMode(true);

            int numPointX = 0, numPointZ = 0, numPatchX = 0, numPatchZ = 0;
            float gridStepInWU = 0.0f;
            vector<SQLInterface::GridVertex> mesh;
            vector<MapManager::GridPatch> patches;

            mapManager.getVertices(0, 0, MapManager::anchorType::center, 100, mesh, numPointX, numPointZ, gridStepInWU);
            mapManager.getPatches(0, 0, MapManager::anchorType::center, 100, patches, numPatchX, numPatchZ, gridStepInWU);

            mapManager.getVertices(1197615, 5467999, MapManager::anchorType::center, 100, mesh, numPointX, numPointZ, gridStepInWU);
            mapManager.getPatches(1197615, 5467999, MapManager::anchorType::center, 100, patches, numPatchX, numPatchZ, gridStepInWU);

            mapManager.getVertices(1197615, 5467999, MapManager::anchorType::center, 5000, mesh, numPointX, numPointZ, gridStepInWU);
            mapManager.getPatches(1197615, 5467999, MapManager::anchorType::center, 5000, patches, numPatchX, numPatchZ, gridStepInWU);

            mapManager.getVertices(1195425, 5465512, MapManager::anchorType::center, 5000, mesh, numPointX, numPointZ, gridStepInWU);
            mapManager.getPatches(1195425, 5465512, MapManager::anchorType::center, 5000, patches, numPatchX, numPatchZ, gridStepInWU);

            mapManager.getVertices(1195425, 5465512, MapManager::anchorType::center, 10000, mesh, numPointX, numPointZ, gridStepInWU);
            mapManager.getPatches(1195425, 5465512, MapManager::anchorType::center, 10000, patches, numPatchX, numPatchZ, gridStepInWU);

            mapManager.getVertices(1195425, 5465512, MapManager::anchorType::center, 20000, mesh, numPointX, numPointZ, gridStepInWU);
            mapManager.getPatches(1195425, 5465512, MapManager::anchorType::center, 20000, patches, numPatchX, numPatchZ, gridStepInWU);

            mapManager.getVertices(1195425, 5465512, MapManager::anchorType::center, 25000, mesh, numPointX, numPointZ, gridStepInWU);
            mapManager.getPatches(1195425, 5465512, MapManager::anchorType::center, 25000, patches, numPatchX, numPatchZ, gridStepInWU);
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
    else if (test == 4)
    {
        try
        {
            MapManager::staticInit(nullptr, plog::debug, plog::get(), true);

            MapManager mapManager(NULL);
            mapManager.instrument(true);
            mapManager.consoleDebugMode(true);

            WorldDefiner WD1(2, 3, WDType::elevator, WDFunctionType::MaxEffectOnWD, (float)10, (float)50);
            WorldDefiner WD2(10, 10, WDType::elevator, WDFunctionType::MaxEffectOnWD, (float)70, (float)50);
            WorldDefiner WD3(20, 20, WDType::depressor, WDFunctionType::MaxEffectOnWD, (float)50, (float)20);
            WorldDefiner WD4(25, 25, WDType::flattener, WDFunctionType::MaxEffectOnWD, (float)0.8, (float)5);

            bool deleted = mapManager.eraseWD(WD1);
            deleted = mapManager.eraseWD(WD2);
            deleted = mapManager.eraseWD(WD3);
            deleted = mapManager.eraseWD(WD4);

            __int64 rowid = mapManager.addWD(WD1);
            rowid = mapManager.addWD(WD2);
            rowid = mapManager.addWD(WD3);
            rowid = mapManager.addWD(WD4);
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

    clock.printDuration((string(__FUNCTION__) + " - ").c_str()); 
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
