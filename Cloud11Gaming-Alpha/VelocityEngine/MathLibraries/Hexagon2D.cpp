#include "Hexagon2D.h"

/** this namespace provides methods to calculate from map functions in a composite hexagon
 * map containing vertexes edges and faces
 *
 */
namespace hex2dvef0d{
/**
 * @brief v0vx vertex goes to 0 degree finds neighboring vertex and gets its x based
 * on x of vertex you are starting from
 * @param x
 * @return
 */
int v0vx(int x){return x + 1;}
/**
 * @brief v0vy vertex goes to degree and finds neighbor y
 * @param y
 * @return
 */
int v0vy(int y){return y - 2;}
/**
 * @brief v0vz vertex goes to degree and finds neighbor z
 * @return
 */
int v0vz(){return 1;}

/**
 * @brief v120vx vertex goes to degree and finds neighbor x
 * @param x
 * @return
 */
int v120vx(int x){return x + 1;}

/**
 * @brief v120vy vertex goes to degree and finds neighbor y
 * @param y
 * @return
 */
int v120vy(int y){return y - 1;}

/**
 * @brief v120vz vertex goes to degree and finds neighbor z
 * @return
 */
int v120vz(){return 1;}

/**
 * @brief v240vx vertex goes to degree and finds neighbor x
 * @param x
 * @return
 */
int v240vx(int x){return x;}

/**
 * @brief v240vy vertex goes to degree and finds neighbor y
 * @param y
 * @return
 */
int v240vy(int y){return y - 1;}

/**
 * @brief v240vz vertex goes to degree and finds neighbor z
 * @return
 */
int v240vz(){return 1;}

/**
 * @brief v60vx vertex goes to degree and finds neighbor x
 * @param x
 * @return
 */
int v60vx(int x){return x;}

/**
 * @brief v60vy vertex goes to degree and finds neighbor y
 * @param y
 * @return
 */
int v60vy(int y){return y + 1;}

/**
 * @brief v60vz vertex goes to degree and finds neighbor z
 * @return
 */
int v60vz(){return 0;}

/**
 * @brief v180vx vertex goes to degree and finds neighbor x
 * @param x
 * @return
 */
int v180vx(int x){return x - 1;}

/**
 * @brief v180vy vertex goes to degree and finds neighbor y
 * @param y
 * @return
 */
int v180vy(int y){return y + 2;}

/**
 * @brief v180vz  vertex goes to degree and finds neighbor z
 * @return
 */
int v180vz(){return 0;}

/**
 * @brief v300vx vertex goes to degree and finds neighbor x
 * @param x
 * @return
 */
int v300vx(int x){return x - 1;}

/**
 * @brief v300vy vertex goes to degree and finds neighbor y
 * @param y
 * @return
 */
int v300vy(int y){return y + 1;}

/**
 * @brief v300vz vertex goes to degree and finds neighbor z
 * @return
 */
int v300vz(){return 0;}

/**
 * @brief e0vx edge goes to degree and finds neighbor x
 * @param x
 * @return
 */
int e0vx(int x){return x + 1;}

/**
 * @brief e0vy edge goes to degree and finds neighbor y
 * @param y
 * @return
 */
int e0vy(int y){return y - 1;}

/**
 * @brief e0vz edge goes to degree and finds neighbor z
 * @return
 */
int e0vz(){return 1;}

/**
 * @brief e180vx edge goes to degree and finds neighbor x
 * @param x
 * @return
 */
int e180vx(int x){return x;}

/**
 * @brief e180vy edge goes to degree and finds neighbor y
 * @param y
 * @return
 */
int e180vy(int y){return y + 1;}

/**
 * @brief e180vz edge goes to degree and finds neighbor z
 * @return
 */
int e180vz(){return 0;}

/**
 * @brief e60vx edge goes to degree and finds neighbor x
 * @param x
 * @return
 */
int e60vx(int x){return x;}

/**
 * @brief e60vy edge goes to degree and finds neighbor y
 * @param y
 * @return
 */
int e60vy(int y){return y;}

/**
 * @brief e60vz edge goes to degree and finds neighbor z
 * @return
 */
int e60vz(){return 0;}

/**
 * @brief e240vx edge goes to degree and finds neighbor x
 * @param x
 * @return
 */
int e240vx(int x){return x;}

/**
 * @brief e240vy edge goes to degree and finds neighbor y
 * @param y
 * @return
 */
int e240vy(int y){return y - 1;}

/**
 * @brief e240vz edge goes to degree and finds neighbor z
 * @return
 */
int e240vz(){return 1;}

/**
 * @brief e120vx edge goes to degree and finds neighbor x
 * @param x
 * @return
 */
int e120vx(int x){return x;}

/**
 * @brief e120vy edge goes to degree and finds neighbor y
 * @param y
 * @return
 */
int e120vy(int y){return y;}

/**
 * @brief e120vz edge goes to degree and finds neighbor z
 * @return
 */
int e120vz(){return 1;}

/**
 * @brief e300vx edge goes to degree and finds neighbor x
 * @param x
 * @return
 */
int e300vx(int x){return x - 1;}

/**
 * @brief e300vy edge goes to degree and finds neighbor y
 * @param y
 * @return
 */
int e300vy(int y){return y + 1;}

/**
 * @brief e300vz edge goes to degree and finds neighbor z
 * @return
 */
int e300vz(){return 0;}

/**
 * @brief f0vx face goes to degree and finds neighbor x
 * @param x
 * @return
 */
int f0vx(int x){return x;}

/**
 * @brief f0vy face goes to degree and finds neighbor y
 * @param y
 * @return
 */
int f0vy(int y){return y;}

/**
 * @brief f0vz face goes to degree and finds neighbor z
 * @return
 */
int f0vz(){return 0;}

/**
 * @brief f60vx faceedge goes to degree and finds neighbor x
 * @param x
 * @return
 */
int f60vx(int x){return x + 1;}

/**
 * @brief f60vy face goes to degree and finds neighbor y
 * @param y
 * @return
 */
int f60vy(int y){return y - 1;}

/**
 * @brief f60vz face goes to degree and finds neighbor z
 * @return
 */
int f60vz(){return 1;}

/**
 * @brief f120vx face goes to degree and finds neighbor x
 * @param x
 * @return
 */
int f120vx(int x){return x;}

/**
 * @brief f120vy face goes to degree and finds neighbor y
 * @param y
 * @return
 */
int f120vy(int y){return y + 1;}

/**
 * @brief f120vz face goes to degree and finds neighbor z
 * @return
 */
int f120vz(){return 0;}

/**
 * @brief f180vx face goes to degree and finds neighbor x
 * @param x
 * @return
 */
int f180vx(int x){return x;}

/**
 * @brief f180vy face goes to degree and finds neighbor y
 * @param y
 * @return
 */
int f180vy(int y){return y;}

/**
 * @brief f180vz face goes to degree and finds neighbor z
 * @return
 */
int f180vz(){return 1;}

/**
 * @brief f240vx face goes to degree and finds neighbor x
 * @param x
 * @return
 */
int f240vx(int x){return x - 1;}

/**
 * @brief f240vy face goes to degree and finds neighbor y
 * @param y
 * @return
 */
int f240vy(int y){return y + 1;}

/**
 * @brief f240vz face goes to degree and finds neighbor z
 * @return
 */
int f240vz(){return 0;}

/**
 * @brief f300vx face goes to degree and finds neighbor x
 * @param x
 * @return
 */
int f300vx(int x){return x;}

/**
 * @brief f300vy face goes to degree and finds neighbor y
 * @param y
 * @return
 */
int f300vy(int y){return y - 1;}

/**
 * @brief f300vz face goes to degree and finds neighbor z
 * @return
 */
int f300vz(){return 1;}

int v0fx(int x){return x;}
int v0fy(int y){return y;}
int v0fz(){return 0;}

int v120fx(int x){return x;}
int v120fy(int y){return y + 1;}
int v120fz(){return 0;}

int v240fx(int x){return x - 1;}
int v240fy(int y){return y + 1;}
int v240fz(){return 0;}

int v60fx(int x){return x + 1;}
int v60fy(int y){return y - 1;}
int v60fz(){return 0;}

int v180fx(int x){return x;}
int v180fy(int y){return y;}
int v180fz(){return 0;}

int v300fx(int x){return x;}
int v300fy(int y){return y - 1;}
int v300fz(){return 0;}

}

