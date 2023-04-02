// ConsoleMapManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#include <iostream>
#include <cctype>

#include <CImg.h>
#include <MapManager.h>
#include <Utils.h>

using namespace TheWorld_MapManager;

void to_lower(std::string& s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void test(size_t test)
{
    if (test == 0)
        test = 4;
    
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


void printUsage(void)
{
    std::cout << std::endl;
    std::cout << "Usage:\n" << std::endl;
    std::cout << "Test <test_number>" << std::endl;
    std::cout << "GenerateGroundImage <output file dir> <ground type name> <output image size> <flipY 'Y/N' > <Albedo/Color/Diffuse image file path> <Bump/Height/Displ image file path> <Normal image file path> <Roughness image file path>" << std::endl;
}

bool generateGroundImage(std::string outdir, std::string groundTypeName, size_t imageSize, bool flipY, std::string colorFile, std::string bumpFile, std::string normalFile, std::string roughFile)
{
    TheWorld_Utils::MemoryBuffer colorImageBuffer;
    TheWorld_Utils::MemoryBuffer bumpImageBuffer;
    TheWorld_Utils::MemoryBuffer normalImageBuffer;
    TheWorld_Utils::MemoryBuffer roughImageBuffer;
    
    cimg_library::CImg<unsigned char> colorImage(colorFile.c_str());
    int width = colorImage.width();
    int height = colorImage.height();
    int depth = colorImage.depth();
    int spectrum = colorImage.spectrum();
    colorImage.resize((int)imageSize, (int)imageSize, -100, -100, 5);   // Cubic interpolation
    width = colorImage.width();
    height = colorImage.height();
    depth = colorImage.depth();
    spectrum = colorImage.spectrum();
    if (spectrum < 3)
    {
        std::cout << "Error: image " << colorImage << " must have at least 3 channels (" << spectrum << ")" << std::endl;
        return false;
    }
    size_t bufferSize = sizeof(struct TheWorld_Utils::_RGB) * (height * width);
    colorImageBuffer.reserve(bufferSize);
    struct TheWorld_Utils::_RGB* rgb = (struct TheWorld_Utils::_RGB*)colorImageBuffer.ptr();
    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
        {
            rgb->r = colorImage(col, row, 0, 0);
            rgb->g = colorImage(col, row, 0, 1);
            rgb->b = colorImage(col, row, 0, 2);
            //std::cout << "(" << row << "," << col << ") =" << " R" << (int)rgb->r << " G" << (int)rgb->g << " B" << (int)rgb->b << endl;
            rgb++;
        }
    colorImageBuffer.adjustSize(bufferSize);

    if (bumpFile.size() > 0)
    {
        cimg_library::CImg<unsigned char> bumpImage(bumpFile.c_str());
        width = bumpImage.width();
        height = bumpImage.height();
        depth = bumpImage.depth();
        spectrum = bumpImage.spectrum();
        bumpImage.resize((int)imageSize, (int)imageSize, -100, -100, 5);   // Cubic interpolation
        width = bumpImage.width();
        height = bumpImage.height();
        depth = bumpImage.depth();
        spectrum = bumpImage.spectrum();
        if (spectrum < 1)
        {
            std::cout << "Error: image " << bumpImage << " must have at least 1 channel (" << spectrum << ")" << std::endl;
            return false;
        }
        bufferSize = sizeof(BYTE) * (height * width);
        bumpImageBuffer.reserve(bufferSize);
        BYTE* red = bumpImageBuffer.ptr();
        for (int row = 0; row < height; row++)
            for (int col = 0; col < width; col++)
            {
                *red = bumpImage(col, row, 0, 0);
                //std::cout << "(" << row << "," << col << ") =" << " R" << (int)*red << endl;
                red++;
            }
        bumpImageBuffer.adjustSize(bufferSize);
    }

    if (normalFile.size() > 0)
    {
        cimg_library::CImg<unsigned char> normalImage(normalFile.c_str());
        int width = normalImage.width();
        int height = normalImage.height();
        int depth = normalImage.depth();
        int spectrum = normalImage.spectrum();
        normalImage.resize((int)imageSize, (int)imageSize, -100, -100, 5);   // Cubic interpolation
        width = normalImage.width();
        height = normalImage.height();
        depth = normalImage.depth();
        spectrum = normalImage.spectrum();
        if (spectrum < 3)
        {
            std::cout << "Error: image " << normalImage << " must have at least 3 channels (" << spectrum << ")" << std::endl;
            return false;
        }
        bufferSize = sizeof(struct TheWorld_Utils::_RGB) * (height * width);
        normalImageBuffer.reserve(bufferSize);
        struct TheWorld_Utils::_RGB* rgb = (struct TheWorld_Utils::_RGB*)normalImageBuffer.ptr();
        for (int row = 0; row < height; row++)
            for (int col = 0; col < width; col++)
            {
                rgb->r = normalImage(col, row, 0, 0);
                rgb->g = normalImage(col, row, 0, 1);
                rgb->b = normalImage(col, row, 0, 2);
                //std::cout << "(" << row << "," << col << ") =" << " R" << (int)rgb->r << " G" << (int)rgb->g << " B" << (int)rgb->b << endl;
                rgb++;
            }
        normalImageBuffer.adjustSize(bufferSize);
    }
    
    if (roughFile.size() > 0)
    {
        cimg_library::CImg<unsigned char> roughImage(roughFile.c_str());
        width = roughImage.width();
        height = roughImage.height();
        depth = roughImage.depth();
        spectrum = roughImage.spectrum();
        roughImage.resize((int)imageSize, (int)imageSize, -100, -100, 5);   // Cubic interpolation
        width = roughImage.width();
        height = roughImage.height();
        depth = roughImage.depth();
        spectrum = roughImage.spectrum();
        if (spectrum < 1)
        {
            std::cout << "Error: image " << roughImage << " must have at least 1 channel (" << spectrum << ")" << std::endl;
            return false;
        }
        bufferSize = sizeof(BYTE) * (height * width);
        roughImageBuffer.reserve(bufferSize);
        BYTE* red = roughImageBuffer.ptr();
        for (int row = 0; row < height; row++)
            for (int col = 0; col < width; col++)
            {
                *red = roughImage(col, row, 0, 0);
                //std::cout << "(" << row << "," << col << ") =" << " R" << (int)*red << endl;
                red++;
            }
        roughImageBuffer.adjustSize(bufferSize);
    }


    bool ret = true;
    try
    {
        TheWorld_Utils::TerrainEdit::generateGroundImage(outdir, groundTypeName, imageSize, flipY, colorImageBuffer, bumpImageBuffer, normalImageBuffer, roughImageBuffer);
    }
    catch (std::exception& e)
    {
        std::cout << "std::exception caught" << std::endl;
        std::cout << e.what() << std::endl;
        ret = false;
    }
    catch (...)
    {
        std::cout << "Generic exception caught" << std::endl;
        ret = false;
    }

    return ret;
}

int main(int argc, char* argv[])
{
    consoleDebugUtil debugUtil(true);
    TimerMs clock(true, true); // Timer<milliseconds, steady_clock>
    clock.tick();

    std::cout << "ConsoleMapManager ..." << std::endl;

    if (!(argc > 1))
    {
        std::cout << "Error: function not specified ..." << std::endl;
        printUsage();
        exit(1);
    }

    std::string cmd = argv[1];
    to_lower(cmd);
    
    if (cmd == "test")
    {
        if (argc != 3)
        {
            std::cout << "Error: wrong parameters ..." << std::endl;
            printUsage();
            exit(1);
        }

        size_t testNum = size_t(argv[2]);
        test(testNum);
    }
    else if (cmd == "generategroundimage")
    {
        if (argc != 10)
        {
            std::cout << "Error: wrong parameters ..." << std::endl;
            printUsage();
            exit(1);
        }

        std::string outDir = argv[2];
        std::string groundTypeName = argv[3];
        size_t imageSize = size_t(atol(argv[4]));
        std::string flipYStr = argv[5];
        to_lower(flipYStr);
        std::string colorFile = argv[6];
        if (colorFile == "-")
            colorFile = "";
        std::string bumpFile = argv[7];
        if (bumpFile == "-")
            bumpFile = "";
        std::string normalFile = argv[8];
        if (normalFile == "-")
            normalFile = "";
        std::string roughFile = argv[9];
        if (roughFile == "-")
            roughFile = "";
        
        if (outDir == "" || colorFile == "")
        {
            std::cout << "Error: output file or color/albedo image file are not specified ..." << std::endl;
            printUsage();
            exit(1);
        }

        bool ok = generateGroundImage(outDir, groundTypeName, imageSize, flipYStr == "y" ? true : false, colorFile, bumpFile, normalFile, roughFile);
        if (!ok)
            exit(1);
    }
    else
    {
        std::cout << "Error: function " << argv[0] << " unkwon ..." << std::endl;
        printUsage();
        exit(1);
    }

    clock.printDuration((std::string(__FUNCTION__) + " - ").c_str());

    std::cout << "Operation completed!" << std::endl;
    exit(0);
}
