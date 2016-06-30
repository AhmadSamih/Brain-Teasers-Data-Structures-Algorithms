class Vector2D {
public:

    std::vector<int>::iterator yitr;
    std::vector<vector<int>>::iterator xitr;
    std::vector<vector<int>>::iterator eitr;
    
    Vector2D(vector<vector<int>>& _vec2d) {
        xitr = _vec2d.begin();
        if(xitr!=_vec2d.end())
            yitr = xitr->begin();
        eitr = _vec2d.end();
    }

    int next() {
        return *yitr++;
    }

    bool hasNext() {
        while(xitr!=eitr && yitr==xitr->end()) xitr++, yitr=xitr->begin();
        return !(xitr==eitr);
    }
};
