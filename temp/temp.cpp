#define maxn 224737
template <typename T>
class Hash
{
private:
    int hashsize, count;
    vector<T> elem;
    vector<bool> flag;
    unsigned int BKDRHash(string str)
    {
        unsigned int seed = 1313; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it)
            hash = hash * seed + *it;
        return (hash & 0x7FFFFFFF);
    }
    unsigned int getHash(string x){return BKDRHash(x) % hashsize;}
    unsigned int getHash(int x){return ((x & 0x7FFFFFFF) % hashsize);}
    unsigned int getHash(pair<string, string> x){return BKDRHash(x.first + ", " + x.second) % hashsize;}
    void collision_1(int &pos){pos = (pos + 1) % hashsize;}
    int findHash(T x, int &pos)
    {
        int c = 0;
        pos = getHash(x);
        while(flag[pos] && elem[pos] != x)
        {
            collision_1(pos);
            c++;
            if (c >= hashsize) return -2;
        }
        if (!flag[pos]) return 0;
        else return 1;
    }
public:
    Hash()
    {
        hashsize = maxn;
        elem.resize(hashsize);
        flag.resize(hashsize);
        count = 0;
    }
    int findHash(T x)
    {
        int pos = getHash(x), c = 0;
        while(flag[pos] && elem[pos] != x)
        {
            collision_1(pos);
            c++;
            if (c >= hashsize) return -2;
        }
        if (!flag[pos]) return -1;
        return pos;
    }
    int insert(T x)
    {
        int pos;
        if (findHash(x, pos) == 1) return pos;
        elem[pos] = x;
        flag[pos] = 1;
        count++;
        return pos;
    }
    void clear()
    {
        elem.clear();
        flag.clear();
        elem.resize(hashsize);
        flag.resize(hashsize);
        count = 0;
    }
    int size(){return count;}
};
