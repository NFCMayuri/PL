#ifndef _GETXYFROMARRAYS_H
#define _GETXYFROMARRAYS_H
// only for char/byte
#define GETX_CHAR(CoordinateOrigin, ElementCoordinate, Column)                 \
    ((ElementCoordinate) - (CoordinateOrigin)) / (Column)
#define GETY_CHAR(CoordinateOrigin, ElementCoordinate, Column)                 \
    ((ElementCoordinate) - (CoordinateOrigin)) % (Column)
#endif /* _GETXYFROMARRAYS_H */
