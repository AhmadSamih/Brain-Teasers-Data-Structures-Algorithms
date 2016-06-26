class Vector2D {
public:

    int x,y;
    int X,Y;
    vector<vector<int>> vec2d;
    Vector2D(vector<vector<int>>& _vec2d) {
        vec2d = _vec2d;
        x=0; y=0;
        X = vec2d.size();
    }

    int next() {
        return vec2d[x][y++];
    }

    bool hasNext() {
        while(x<X && y>=vec2d[x].size()){x++;y=0;}
        if(x<X && y<vec2d[x].size()) return true;
        else return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */