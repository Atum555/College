#ifndef __POINT_P__
#define __POINT_P__

class Point {
  public:
    Point();
    Point(int x, int y);

    int getX() const;
    int getY() const;

    void show() const;

  private:
    int x_, y_;
};

#endif
