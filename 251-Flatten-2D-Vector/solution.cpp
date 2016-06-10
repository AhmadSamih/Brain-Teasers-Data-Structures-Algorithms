class Vector2D {
public:
    std::vector<vector<int>>::iterator x;
    std::vector<int>::iterator y;
    vector<vector<int>>vec2d;

    Vector2D(vector<vector<int>>& _vec2d) {
        vec2d = _vec2d;
        if(!vec2d.empty()){
            x = vec2d.begin();
            y = x->begin();
        }
    }

    int next() {
        return *y++;
    }

    bool hasNext() {
        while(x!=vec2d.end() && y==x->end()){
            x++;
            y=x->begin();
        }
        return (x!=vec2d.end());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */