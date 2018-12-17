#ifndef DEF_H_
#define DEF_H_

#define width 640
#define height 480
#define cellwidth (width/3)
#define cellheight (height/3)


enum player { X, O, N };
typedef enum player player;

enum state{RUNNING, XWIN, OWIN, DRAW, QUIT};
typedef enum state state;

#endif
