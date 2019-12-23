#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <string>
#include<iostream>
using namespace std;
//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;
//Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
        SDL_Texture* loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}
bool loadMedia(Block block)
{
    //Loading success flag
    bool success = true;

    //Load PNG texture
    switch(block.lop)
    {
    case 0:
        switch(block.mode)
        {
        case 0:
            switch(block.which)
            {
            case redred:
                gTexture = loadTexture(images/REDRED.png);
                break;
            case door:
                gTexture = loadTexture(images/DOOR.png);
                break;
            case flag:
                gTexture = loadTexture(images/FLAG.png);
                break;
            case wall:
                gTexture = loadTexture(images/WALL.png);
                break;
            case key:
                gTexture = loadTexture(images/KEY.png);
                break;
            case redred:
                gTexture = loadTexture(images/REDRED.png);
                break;
            case rock:
                gTexture = loadTexture(images/ROCK.png);
                break;
            case redred:
                gTexture = loadTexture(images/REDRED.png);
                break;
            case water:
                gTexture = loadTexture(images/WATER.png);
                break;
            case lava:
                gTexture = loadTexture(images/LAVA.png);
                break;
            case grass:
                gTexture = loadTexture(images/GRASS.png);
                break;
            }break;
        case 1:
            switch(block.which)
            {
            case you:
                gTexture = loadTexture(images/YOU.png);
                break;
            case sink:
                gTexture = loadTexture(images/SINK.png);
                break;
            case stop:
                gTexture = loadTexture(images/STOP.png);
                break;
            case push:
                gTexture = loadTexture(images/PUSH.png);
                break;
            case wa:
                gTexture = loadTexture(images/WA.png);
                break;
            case ac:
                gTexture = loadTexture(images/AC.png);
                break;
            case open:
                gTexture = loadTexture(images/OPEN.png);
                break;
            case hot:
                gTexture = loadTexture(images/HOT.png);
                break;
            case melt:
                gTexture = loadTexture(images/MELT.png);
                break;
            case shut:
                gTexture = loadTexture(images/SHUT.png);
                break;
            }break;
            case 2:
                 gTexture = loadTexture(images/IS.png);
                 break;
        }break;
    case 1:
        switch(block.mode)
        {
        case 0:
            switch(block.which)
            {
            case redred:
                gTexture = loadTexture(images/REDRED.png);
                break;
            case door:
                gTexture = loadTexture(images/DOOR.png);
                break;
            case flag:
                gTexture = loadTexture(images/FLAG.png);
                break;
            case wall:
                gTexture = loadTexture(images/WALL.png);
                break;
            case key:
                gTexture = loadTexture(images/KEY.png);
                break;
            case redred:
                gTexture = loadTexture(images/REDRED.png);
                break;
            case rock:
                gTexture = loadTexture(images/ROCK.png);
                break;
            case redred:
                gTexture = loadTexture(images/REDRED.png);
                break;
            case water:
                gTexture = loadTexture(images/WATER.png);
                break;
            case lava:
                gTexture = loadTexture(images/LAVA.png);
                break;
            case grass:
                gTexture = loadTexture(images/GRASS.png);
                break;
            }break;
        case 1:
            switch(block.which)
            {
            case you:
                gTexture = loadTexture(images/YOU.png);
                break;
            case sink:
                gTexture = loadTexture(images/SINK.png);
                break;
            case stop:
                gTexture = loadTexture(images/STOP.png);
                break;
            case push:
                gTexture = loadTexture(images/PUSH.png);
                break;
            case wa:
                gTexture = loadTexture(images/WA.png);
                break;
            case ac:
                gTexture = loadTexture(images/AC.png);
                break;
            case open:
                gTexture = loadTexture(images/OPEN.png);
                break;
            case hot:
                gTexture = loadTexture(images/HOT.png);
                break;
            case melt:
                gTexture = loadTexture(images/MELT.png);
                break;
            case shut:
                gTexture = loadTexture(images/SHUT.png);
                break;
            }break;
            case 2:
                 gTexture = loadTexture(images/IS.png);
                 break;
        }break;

    }

    if( gTexture == NULL )
    {
        printf( "Failed to load texture image!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
int main()
{
                    while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    motion(e);
                }


                //Clear screen
                SDL_RenderClear( gRenderer );

                //Render texture to screen
                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

                //Update screen
                SDL_RenderPresent( gRenderer );
            }
}
