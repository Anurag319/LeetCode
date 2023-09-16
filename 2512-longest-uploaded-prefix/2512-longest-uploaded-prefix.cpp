class LUPrefix {
public:
    int pointer = 0;
    vector<int> prefix;
    LUPrefix(int n) {
        prefix.resize(n+2,0);
    }
    
    void upload(int video) {
        prefix[video] = 1;
        while(prefix[pointer+1]==1){
            pointer++;
        }
    }
    
    int longest() {
        return pointer;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */