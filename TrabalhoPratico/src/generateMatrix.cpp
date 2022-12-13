#include <iostream>
#include <SDL2/SDL.h>
#include <random>

#include "segregation.h"

std::vector<SDL_Rect> RectMatrix(SDL_Rect (*rectFactory)(int, int, int, int), int xStart, int yStart, int squareSize, SDL_Renderer *renderer, int matrixSize, std::vector<std::vector<Agent>> segregationMatrix)
{
    std::vector<SDL_Rect> rects;

    std::vector<SDL_Rect> yellowRects;
    std::vector<SDL_Rect> blueRects;
    std::vector<SDL_Rect> redRects;

    for (long int i = 0; i < matrixSize; i++)
    {
        for (long int j = 0; j < matrixSize; j++)
        {
            SDL_Rect rect = (*rectFactory)(xStart + squareSize * i, yStart + squareSize * j, squareSize, squareSize);
            if (segregationMatrix.at(i).at(j).type == 1)
            {
                blueRects.push_back(rect);
            }

            if (segregationMatrix.at(i).at(j).type == 0)
            {
                redRects.push_back(rect);
            }

            if (segregationMatrix.at(i).at(j).type == 3)
            {
                yellowRects.push_back(rect);
            }

            rects.push_back(rect);
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect blue[blueRects.size()];
    std::copy(blueRects.begin(), blueRects.end(), blue);
    SDL_RenderFillRects(renderer, blue, blueRects.size());

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect yellow[yellowRects.size()];
    std::copy(yellowRects.begin(), yellowRects.end(), yellow);
    SDL_RenderFillRects(renderer, yellow, yellowRects.size());

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect red[redRects.size()];
    std::copy(redRects.begin(), redRects.end(), red);
    SDL_RenderFillRects(renderer, red, redRects.size());

    return rects;
}

SDL_Rect rectFactory(int x, int y, int width, int height)
{
    SDL_Rect rect = {.x = x, .y = y, .w = width, .h = height};

    return rect;
}

void generateMatrix(std::vector<std::vector<Agent>> segregationMatrix, float tolerance)
{

    int squareSize = 10;
    int matrixSize = segregationMatrix.size();

    int matrixWidth = squareSize * matrixSize;

    int windowWidth = matrixWidth + 150;
    int windowHeight = matrixWidth + 50;

    int windowXStartAt = (windowWidth - matrixWidth) / 2;
    int windowsYStartAt = (windowHeight - matrixWidth) / 2;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool appIsRunning = true;

    int numMillisToThrottle = 6;
    Uint64 lastDrawTime = SDL_GetTicks64();

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL não pode ser inicializado: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "Sistema de video inicializado" << std::endl;
    }

    window = SDL_CreateWindow(
        "Modelo de Segregação Social de Schelling", // window title
        SDL_WINDOWPOS_UNDEFINED,                    // initial x position
        SDL_WINDOWPOS_UNDEFINED,                    // initial y position
        windowWidth,                                // width, in pixels
        windowHeight,                               // height, in pixels
        SDL_WINDOW_SHOWN                            // flags - see below
    );

    if (window == NULL)
    {
        printf("Não foi possivel criar a janela: %s\n", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL)
    {
        printf("Não foi possivel criar o renderizador: %s\n", SDL_GetError());
        return;
    }

    int rounds = 0;
    int displayNumberRounds = 0;

    while (appIsRunning)
    {
        // slowing things down a little, you can delete this if you like
        while (SDL_GetTicks64() - lastDrawTime < numMillisToThrottle)
        {
        }

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Handle each specific event
            if (event.type == SDL_QUIT)
            {
                appIsRunning = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        std::vector<SDL_Rect> rectsVector = RectMatrix(rectFactory, windowXStartAt, windowsYStartAt, squareSize, renderer, matrixSize, segregationMatrix);
        SDL_Rect rects[rectsVector.size()];
        std::copy(rectsVector.begin(), rectsVector.end(), rects);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        int success = SDL_RenderDrawRects(renderer, rects, rectsVector.size());
        if (success < 0)
        {
            std::cout << SDL_GetError() << std::endl;

            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            appIsRunning = false;
        }

        SDL_RenderPresent(renderer);

        SegregationStats stats = segregate(segregationMatrix, tolerance);
        segregationMatrix = stats.society;

        bool hasSegregation = stats.hasSegregation;

        if (hasSegregation)
        {
            rounds += 1;
        }
        else
        {
            if(displayNumberRounds < 1) {
                std::cout << "Rodadas: " << rounds << std::endl;
                displayNumberRounds += 1;
            }
        }

        lastDrawTime = SDL_GetTicks64();
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout << "exiting..." << std::endl;
    SDL_Quit();
    return;
}