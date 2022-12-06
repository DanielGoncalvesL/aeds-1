#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cmath>

#include "segregation.h"
#include "generateMatrix.h"

bool verifyUnhappyCitizen(int x, int y, std::vector<std::vector<Agent>> matrix)
{
    int cont = 0;
    int contRadius = 0;

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
                    contRadius += 1;
                    if (matrix[y][x].type != matrix[i][j].type && matrix[i][j].type != 2)
                    {
                        cont += 1;
                    }
                }
            }
        }
    }

    if (cont >= std::round(contRadius * 0.3))
    {
        return true;
    }

    return false;
}

bool isEmptyPosition(std::vector<std::vector<Agent>> matrix, int x, int y){
    return matrix[x][y].type == 2 ? true : false;
}

Coordinates searchBlankSpace(std::vector<std::vector<Agent>> matrix)
{
    std::random_device rd;
    std::uniform_int_distribution randomCoordinates(0, (int) matrix.size() - 1);

    int x = (int) randomCoordinates(rd);
    int y = (int) randomCoordinates(rd);

    while (matrix[x][y].type != 2)
    {
        x = (int) randomCoordinates(rd);
        y = (int) randomCoordinates(rd);
    }

    return {.i = x, .j = y};
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