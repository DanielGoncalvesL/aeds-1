#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <array>
#include <string>

#include "segregation.h"
#include "generateMatrix.h"

bool verifyUnhappyCitizen(int x, int y, std::vector<std::vector<Agent>> matrix)
{
    int cont = 0;

    for (int i = y - 1; i <= y + 1; i++)
    {
        for (int j = x - 1; j <= x + 1; j++)
        {
            if (i == y && j == x)
            {
                continue;
            }
            else
            {
                if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix.size())
                {
                    if (matrix[y][x].type != matrix[i][j].type && matrix[i][j].type != 2)
                    {
                        cont += 1;
                    }
                }
            }
        }
    }

    if (cont >= 5)
    {
        return true;
    }

    return false;
}

Coordinates searchBlankSpace(std::vector<std::vector<Agent>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j].type == 2)
            {
                return {.i = i, .j = j};
            }
        }
    }

    return {};
}

SegregationStats segregate(std::vector<std::vector<Agent>> matrix)
{
    int contador = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j].type == 0 || matrix[i][j].type == 1)
            {
                bool unhappy = verifyUnhappyCitizen(j, i, matrix);

                if (unhappy)
                {
                    Coordinates blankSpace = searchBlankSpace(matrix);
                    std::swap(matrix[i][j], matrix[blankSpace.i][blankSpace.j]);
                }
            }
        }
    }

    return {.society = matrix};
}

int plotCitizens(std::vector<std::vector<Agent>> &segregationVector, int citizen, int maxCitizens, std::vector<std::string> &coordinates, int matrixSize)
{
    int plotCounter = 0;

    std::random_device rd;
    std::uniform_int_distribution randomCoordinates(0, matrixSize - 1);

    while (plotCounter < maxCitizens)
    {
        int x = randomCoordinates(rd);
        int y = randomCoordinates(rd);
        std::string coordinate = std::to_string(x) + "-" + std::to_string(y);

        auto coordinateExists = std::find(coordinates.begin(), coordinates.end(), coordinate);

        while (coordinateExists != coordinates.end())
        {
            x = randomCoordinates(rd);
            y = randomCoordinates(rd);
            coordinate = std::to_string(x) + "-" + std::to_string(y);

            coordinateExists = std::find(coordinates.begin(), coordinates.end(), coordinate);
        }
        segregationVector.at(x).at(y).type = citizen;
        coordinates.push_back(coordinate);

        plotCounter += 1;
    }

    return plotCounter;
}

std::vector<std::vector<Agent>> generateSociety(int matrixSize)
{
    std::random_device rd;
    std::uniform_int_distribution randomCitizen(0, 2);

    std::vector<std::vector<Agent>> segregationVector;

    std::vector<std::string> coordinates;

    int matrixTotalSize = matrixSize * matrixSize;

    int maxBlank = matrixTotalSize * 0.1;

    if (maxBlank == 0)
    {
        maxBlank = 1;
    }

    int maxCitizenType = (matrixTotalSize - maxBlank) / 2;

    for (int i = 0; i < matrixSize; i++)
    {
        std::vector<Agent> line;
        for (int j = 0; j < matrixSize; j++)
        {
            line.push_back({j});
        }
        segregationVector.push_back(line);
    }

    int positions = 0;
    int blank = 0;

    std::cout << maxCitizenType << std::endl;

    int redCitizenCounter = plotCitizens(segregationVector, 0, maxCitizenType, coordinates, matrixSize);
    int blueCitizenCounter = plotCitizens(segregationVector, 1, maxCitizenType, coordinates, matrixSize);
    blank = plotCitizens(segregationVector, 2, maxBlank, coordinates, matrixSize);

    // while (positions < matrixTotalSize)
    // {
    //     int x = randomCoordinates(rd);
    //     int y = randomCoordinates(rd);
    //     std::string coord = std::to_string(x) + "-" + std::to_string(y);

    //     auto coordinateExists = std::find(coordinates.begin(), coordinates.end(), coord);

    //     while (coordinateExists != coordinates.end())
    //     {
    //         x = randomCoordinates(rd);
    //         y = randomCoordinates(rd);
    //         coord = std::to_string(x) + "-" + std::to_string(y);

    //         coordinateExists = std::find(coordinates.begin(), coordinates.end(), coord);
    //     }

    //     int citizen = randomCitizen(rd);

    //     switch (citizen)
    //     {
    //     case 0:
    //         if(redCitizenCounter <= maxCitizenType){
    //             redCitizenCounter += 1;
    //         }else {
    //             citizen = randomCitizen(rd);
    //             while (citizen == 0)
    //             {
    //                 citizen = randomCitizen(rd);
    //             }
    //         }
    //         break;
    //     case 1:
    //         if(blueCitizenCounter <= maxCitizenType){
    //             blueCitizenCounter += 1;
    //         }else {
    //             citizen = randomCitizen(rd);
    //             while (citizen == 1)
    //             {
    //                 citizen = randomCitizen(rd);
    //             }
    //         }
    //         break;
    //     case 2:
    //         if(blank <= maxBlank){
    //             blank += 1;
    //         }else {
    //             citizen = randomCitizen(rd);
    //             while (citizen == 2)
    //             {
    //                 citizen = randomCitizen(rd);
    //             }
    //         }
    //         break;
    //     default:
    //         break;
    //     }

    //     segregationVector.at(x).at(y).type = citizen;
    //     coordinates.push_back(coord);

    //     positions += 1;
    //     std::cout << redCitizenCounter << " " << blueCitizenCounter << std::endl;
    // }

    std::cout
        << "METADE: " << maxCitizenType << " RED: " << redCitizenCounter << " BLUE: " << blueCitizenCounter << " WHITE: " << blank << std::endl;

    return segregationVector;
}

int main()
{
    int matrixSize;
    std::cout << "Insira o tamanha da matrix: ";
    std::cin >> matrixSize;

    std::cout << "Gerando Modelo de Segregação Social de Schelling..." << std::endl;

    std::vector<std::vector<Agent>> matrix = generateSociety(matrixSize);

    generateMatrix(matrix);
}