typedef struct point {
    int x;
    int y;
} point;

int abs(int a) {
    return (a>=0) ? a : -a;

}

int vec_prod(point *a, point *b) {
    return a->x * b->y - b->x * a->y;
}

int double_square(point *a, point *b, point *c) {
    point vb  = {b->x - a->x, b->y - a->y};
    point vc  = {c->x - a->x, c->y - a->y};
    return abs(vec_prod(&vb, &vc));
}
