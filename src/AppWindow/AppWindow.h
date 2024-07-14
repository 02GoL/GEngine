#include"../Window/Window.h"
#include"../CoreEngine/CoreEngine.h"
#include"../InputHandler/InputListener.h"
#include"../InputHandler/InputHandler.h"

class AppWindow: public Window{
    private:
        InputHandler inputHandler;
        int xResolution;
        int yResolution;
        bool displayFPS;
        bool dataLoaded;
    public:
        AppWindow(int xResolution, int yResolution);
        ~AppWindow(){};
        void eventHandler();
        void onCreate() override;
        void onDestroy() override;
};