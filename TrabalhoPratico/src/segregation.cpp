#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cmath>

#include "segregation.h"
#include "generateMatrix.h"

bool verifyUnhappyCitizen(int x, int y, std::vector<std::vector<Agent>> matrix, float tolerance)
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

    if (cont >= std::round(contRadius * tolerance))
    {
        return true;
    }

    return false;
}

bool isEmptyPosition(std::vector<std::vector<Agent>> matrix, int x, int y)
{
    return matrix[x][y].type == 2 ? true : false;
}

Coordinates searchBlankSpace(std::vector<std::vector<Agent>> matrix)
{
    std::vector<Coordinates> blankSpaces;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j].type == 2)
            {
                blankSpaces.push_back({.i = i, .j = j});
            }
        }
    }

    std::random_device rd;
    std::uniform_int_distribution<int> randomCoordinates(0, blankSpaces.size() - 1);

    int i = randomCoordinates(rd);

    Coordinates coordinate = {.i = blankSpaces[i].i, .j = blankSpaces[i].j};

    return coordinate;
}

SegregationStats segregate(std::vector<std::vector<Agent>> matrix, float tolerance)
{
    bool unhappyStats = false;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j].type != 2)
            {
                bool unhappy = verifyUnhappyCitizen(j, i, matrix, tolerance);

                if (unhappy)
                {
                    Coordinates blankSpace = searchBlankSpace(matrix);
                    std::swap(matrix[i][j], matrix[blankSpace.i][blankSpace.j]);

                    if (!unhappyStats)
                    {
                        unhappyStats = true;
                    }
                }
            }
        }
    }

    return {.society = matrix, .hasSegregation = unhappyStats};
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

    int maxBlank = matrixTotalSize * 0.25;

    if (maxBlank == 0)
    {
        maxBlank = 1;
    }

    int yellowCitizenMaxQuantity = (matrixTotalSize - maxBlank) * 0.01;

    int maxCitizenType = (matrixTotalSize - (maxBlank + yellowCitizenMaxQuantity)) / 2;

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

    // std::cout << maxCitizenType << std::endl;

    int redCitizenCounter = plotCitizens(segregationVector, 0, maxCitizenType, coordinates, matrixSize);
    int blueCitizenCounter = plotCitizens(segregationVector, 1, maxCitizenType, coordinates, matrixSize);
    int yellowCitizenCounter = plotCitizens(segregationVector, 3, yellowCitizenMaxQuantity, coordinates, matrixSize);
    blank = plotCitizens(segregationVector, 2, maxBlank, coordinates, matrixSize);

    std::cout
        << "METADE: " << maxCitizenType << " RED: " << redCitizenCounter << " BLUE: " << blueCitizenCounter << " YELLOW: " << yellowCitizenCounter << " WHITE: " << blank << std::endl;

    return segregationVector;
}

int main()
{
    int matrixSize;
    float tolerance;

    std::cout << "Insira o tamanha da matrix: ";
    std::cin >> matrixSize;

    std::cout << "Insira o grau de tolerancia: ";
    std::cin >> tolerance;

    std::cout << "Gerando Modelo de Segregação Social de Schelling..." << std::endl;

    std::vector<std::vector<Agent>> matrix = generateSociety(matrixSize);

    generateMatrix(matrix, tolerance);
}