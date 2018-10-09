namespace IO {
    const int MT = 5e7;
    char buf[MT]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MT, stdin);
    }
    template<class T>
    inline bool read(T &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}