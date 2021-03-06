
#include <iostream>
#include <SDL.h>

using namespace std;

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Tiny Game!";

struct Box
{
    int x;
    int y;
    int size = 10;
    void render(SDL_Renderer* renderer)
    {
        SDL_Rect filled_rect;
        filled_rect.x=x;
        filled_rect.y=y;
        filled_rect.w=size;
        filled_rect.h=size;
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &filled_rect);
    }

    void move(){
        x+=5;
        y+=5;
    }
    void moveLeft()
    {
        x-=5;
    }
    void moveRight()
    {
        x+=5;
    }
    void moveDown()
    {
        y+=5;
    }
    void moveUp()
    {
        y-=5;
    }
    bool inside(int minx, int miny, int maxx, int maxy)
    {
        return (minx<=x && miny<=y && maxx>=x+size && maxy>=y+size);
    }
};
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void waitUntilKeyPressed();

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    // Your drawing code here
    // use SDL_RenderPresent(renderer) to show it
    SDL_Event e;
    Box box;
    box.x=10;
    box.y=10;
    while(box.inside(0,0,SCREEN_WIDTH,SCREEN_HEIGHT)){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        box.render(renderer);
        SDL_RenderPresent(renderer);
        if ( SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break;
        		case SDLK_LEFT: box.moveLeft();
        			break;
            	case SDLK_RIGHT: box.moveRight();
            		break;
            	case SDLK_DOWN: box.moveDown();
                    break;
            	case SDLK_UP: box.moveUp();
            		break;
        		default: break;
			}
        }
    }
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
