#ifndef OPEN_CRAFT_KEY_HANDLER_H
#define OPEN_CRAFT_KEY_HANDLER_H

class OpenCraftGame;
class KeyHandler
{
private:
    OpenCraftGame& game;
public:
    enum class Key : int
    {
        EXIT, LEFT_SHIFT, SPACE, RIGHT_SHIFT, LEFT_CTRL, RIGHT_CTRL, ENTER, TAB, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5,
        KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, W, A, S, D, Q, E, Z, X, C, V, F, R, T, G, B, N, H, Y, U, J, M, K, I, O, L, P
    };
    enum class Event : int {
        PRESSED
    };
    explicit KeyHandler(OpenCraftGame& game);

    void onKeyEvent(Key, Event);
};


#endif //OPEN_CRAFT_KEY_HANDLER_H
