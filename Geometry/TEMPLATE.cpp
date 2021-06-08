#define ld long double

struct point{
    ld x,y;
    point(){};
    point(ld xx, ld yy){x=xx; y=yy;};

    point operator+ (point p){return point(x+p.x,y+p.y);};
    point operator- (point p){return point(x-p.x,y-p.y);};
    point operator* (ld p){return point(x*p,y*p);};
    point operator/ (ld p){return point(x/p,y/p);};
};

point p[3];

long double DistanceOf2points(point a, point b){

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

ll TriangleArea(point a, point b, point c){

    return (a.x*b.y-b.x*a.y)+(b.x*c.y-b.y*c.x)+(c.x*a.y-a.x*c.y);

}
