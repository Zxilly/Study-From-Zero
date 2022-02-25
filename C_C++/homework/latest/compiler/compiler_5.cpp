//
// Created by zxilly on 2021/12/13.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <sstream>

#define MAX 507
#define DEBUG
using namespace std;

class WF {
public:
    string left, right;
    int back;
    int id;

    WF(char s1[], char s2[], int x, int y) {
        left = s1;
        right = s2;
        back = x;
        id = y;
    }

    WF(const string &s1, const string &s2, int x, int y) {
        left = s1;
        right = s2;
        back = x;
        id = y;
    }

    bool operator<(const WF &a) const {
        if (left == a.left)
            return right < a.right;
        return left < a.left;
    }

    bool operator==(const WF &a) const {
        return (left == a.left) && (right == a.right);
    }

    void print() const {
        printf("%s->%s\n", left.c_str(), right.c_str());
    }
};

class Closure {
public:
    vector<WF> element;

    void print(const string &str) {
        printf("%-15s%-15s\n", "", str.c_str());
        for (auto &i: element)
            i.print();
    }

    bool operator==(const Closure &a) const {
        if (a.element.size() != element.size()) return false;
        for (int i = 0; i < a.element.size(); i++)
            if (element[i] == a.element[i]) continue;
            else return false;
        return true;
    }
};

struct Content {
    int type;
    int num{};
    string out;

    Content() { type = -1; }

    Content(int a, int b)
            : type(a), num(b) {}
};

vector<WF> wf;
map<string, vector<int> > dic;
map<string, vector<int> > VN_set;
map<string, bool> vis;
[[maybe_unused]] string start = "S";
vector<Closure> collection;
vector<WF> items;
char CH = '$';
int go[MAX][MAX];
int to[MAX];
vector<char> V;
bool used[MAX];
Content action[MAX][MAX];
int Goto[MAX][MAX];
map<string, set<char> > first;
map<string, set<char> > follow;

void make_item() {
    memset(to, -1, sizeof(-1));
    for (int i = 0; i < wf.size(); i++)
        VN_set[wf[i].left].push_back(i);
    for (int i = 0; i < wf.size(); i++)
        for (int j = 0; j <= wf[i].right.length(); j++) {
            string temp = wf[i].right;
            temp.insert(temp.begin() + j, CH);
            dic[wf[i].left].push_back(items.size());
            if (j)
                to[items.size() - 1] = items.size();
            items.emplace_back(wf[i].left, temp, i, items.size());
        }
#ifdef DEBUG
    puts("-------------------------项目表-------------------------");
    for (int i = 0; i < items.size(); i++)
        printf("%s->%s back:%d id:%d\n", items[i].left.c_str(), items[i].right.c_str(), items[i].back, items[i].id);
    puts("--------------------------------------------------------");
#endif
}

void dfs(const string &x) {
    if (vis[x]) return;
    vis[x] = 1;
    vector<int> &id = VN_set[x];
    for (int i = 0; i < id.size(); i++) {
        string &left = wf[id[i]].left;
        string &right = wf[id[i]].right;
        for (int j = 0; j < right.length(); j++)
            if (isupper(right[j])) {
                dfs(right.substr(j, 1));
                set<char> &temp = first[right.substr(j, 1)];
                auto it = temp.begin();
                bool flag = true;
                for (; it != temp.end(); it++) {
                    if (*it == '~') flag = false;
                    first[left].insert(*it);
                }
                if (flag) break;
            } else {
                first[left].insert(right[j]);
                break;
            }
    }
}

void make_first() {
    vis.clear();
    auto it2 = dic.begin();
    for (; it2 != dic.end(); it2++)
        if (vis[it2->first]) continue;
        else dfs(it2->first);
#ifdef DEBUG
    puts("****************FIRST集***************************");
    map<string, set<char> >::iterator it = first.begin();
    for (; it != first.end(); it++) {
        printf("FIRST(%s)={", it->first.c_str());
        set<char> &temp = it->second;
        set<char>::iterator it1 = temp.begin();
        bool flag = false;
        for (; it1 != temp.end(); it1++) {
            if (flag) printf(",");
            printf("%c", *it1);
            flag = true;
        }
        puts("}");
    }
#endif
}

void append(const string &str1, const string &str2) {
    set<char> &from = follow[str1];
    set<char> &in_to = follow[str2];
    auto it = from.begin();
    for (; it != from.end(); it++)
        in_to.insert(*it);
}

bool check(const vector<int> &id, const string &str) {
    for (int x: id) {
        if (wf[x].right == str) return true;
    }
    return false;
}

void make_follow() {
    while (true) {
        bool goon = false;
        auto it2 = VN_set.begin();
        for (; it2 != VN_set.end(); it2++) {
            vector<int> &id = it2->second;
            for (int i = 0; i < id.size(); i++) {
                bool flag = true;
                WF &tt = wf[id[i]];
                string &left = tt.left;
                const string &right = tt.right;
                for (int j = right.length() - 1; j >= 0; j--)
                    if (isupper(right[j])) {
                        if (flag) {
                            int tx = follow[right.substr(j, 1)].size();
                            append(left, right.substr(j, 1));
                            int tx1 = follow[right.substr(j, 1)].size();
                            if (tx1 > tx) goon = true;
                            if (check(id, "~"))
                                flag = false;
                        }
                        for (int k = j + 1; k < right.length(); k++)
                            if (isupper(right[k])) {
                                string idd = right.substr(k, 1);
                                set<char> &from = first[idd];
                                set<char> &in_to = follow[right.substr(j, 1)];
                                auto it1 = from.begin();
                                int tx = follow[right.substr(j, 1)].size();
                                for (; it1 != from.end(); it1++)
                                    if (*it1 != '~')
                                        in_to.insert(*it1);
                                int tx1 = follow[right.substr(j, 1)].size();
                                if (tx1 > tx) goon = true;
                                if (check(id, "~"))
                                    break;
                            } else {
                                int tx = follow[right.substr(j, 1)].size();
                                follow[right.substr(j, 1)].insert(right[k]);
                                int tx1 = follow[right.substr(j, 1)].size();
                                if (tx1 > tx) goon = true;
                                break;
                            }
                    } else flag = false;
            }
        }
        if (!goon) break;
    }
#ifdef DEBUG
    puts("***************FOLLOW集*******************");
    map<string, set<char> >::iterator it = follow.begin();
    for (; it != follow.end(); it++) {
        printf("FOLLOW(%s)={", it->first.c_str());
        set<char> &temp = it->second;
        //if ( it->first[0] == 'S' )
        temp.insert('#');
        set<char>::iterator it1 = temp.begin();
        bool flag = false;
        for (; it1 != temp.end(); it1++) {
            if (flag) printf(",");
            printf("%c", *it1);
            flag = true;
        }
        puts("}");
    }
#endif
}

void make_set() {
    bool has[MAX];
    for (int i = 0; i < items.size(); i++)
        if (items[i].left[0] == 'S' && items[i].right[0] == CH) {
            Closure temp;
            string &str = items[i].right;
            vector<WF> &element = temp.element;
            element.push_back(items[i]);
            int x = 0;
            for (x = 0; x < str.length(); x++)
                if (str[x] == CH)
                    break;
            /*if ( x != str.length()-1 )
            {
                string tt = str.substr(x+1,1);
                vector<int>& id = dic[tt];
                for ( int j = 0 ; j < id.size() ; j++ )
                {
                    int tx = id[j];
                    //items[tx].print();
                    if ( items[tx].right[0] == CH )
                        element.push_back ( items[tx] );
                }
            }*/
            memset(has, 0, sizeof(has));
            has[i] = 1;
            if (x != str.length() - 1) {
                queue<string> q;
                q.push(str.substr(x + 1, 1));
                while (!q.empty()) {
                    string u = q.front();
                    q.pop();
                    vector<int> &id = dic[u];
                    for (int tx: id) {
                        if (items[tx].right[0] == CH) {
                            if (has[tx]) continue;
                            has[tx] = 1;
                            if (isupper(items[tx].right[1]))
                                q.push(items[tx].right.substr(1, 1));
                            element.push_back(items[tx]);
                        }
                    }
                }
            }
            collection.push_back(temp);
        }
    for (int i = 0; i < collection.size(); i++) {
        map<int, Closure> temp;
        for (auto &j: collection[i].element) {
            string str = j.right;
            int x = 0;
            for (; x < str.length(); x++)
                if (str[x] == CH) break;
            if (x == str.length() - 1)
                continue;
            int y = str[x + 1];
            int ii;
            str.erase(str.begin() + x);
            str.insert(str.begin() + x + 1, CH);
            WF cmp = WF(j.left, str, -1, -1);
            for (int k = 0;; k++)
                if (items[k] == cmp) {
                    ii = k;
                    break;
                }
            //string& str1 = items[ii].right;
            memset(has, 0, sizeof(has));
            vector<WF> &element = temp[y].element;
            element.push_back(items[ii]);
            has[ii] = true;
            x++;
            if (x != str.length() - 1) {
                queue<string> q;
                q.push(str.substr(x + 1, 1));
                while (!q.empty()) {
                    string u = q.front();
                    q.pop();
                    vector<int> &id = dic[u];
                    for (int tx: id) {
                        if (items[tx].right[0] == CH) {
                            if (has[tx]) continue;
                            has[tx] = true;
                            if (isupper(items[tx].right[1]))
                                q.push(items[tx].right.substr(1, 1));
                            element.push_back(items[tx]);
                        }
                    }
                }
            }
        }
        auto it = temp.begin();
        for (; it != temp.end(); it++)
            collection.push_back(it->second);
        for (auto &k: collection)
            sort(k.element.begin(), k.element.end());
        for (int k = 0; k < collection.size(); k++)
            for (int j = k + 1; j < collection.size(); j++)
                if (collection[k] == collection[j])
                    collection.erase(collection.begin() + j);
    }
#ifdef DEBUG
    puts("-------------CLOSURE---------------------");
    stringstream sin;
    for (int i = 0; i < collection.size(); i++) {
        sin.clear();
        string out;
        sin << "closure-I" << i;
        sin >> out;
        collection[i].print(out);
    }
    puts("");
#endif
}

void make_V() {
    memset(used, 0, sizeof(used));
    for (auto &i: wf) {
        string &str = i.left;
        for (char &j: str) {
            if (used[j]) continue;
            used[j] = true;
            V.push_back(j);
        }
        string &str1 = i.right;
        for (char &j: str1) {
            if (used[j]) continue;
            used[j] = true;
            V.push_back(j);
        }
    }
    sort(V.begin(), V.end());
    V.push_back('#');
}

void make_cmp(vector<WF> &cmp1, int i, char ch) {
    for (auto &j: collection[i].element) {
        string str = j.right;
        int k;
        for (k = 0; k < str.length(); k++)
            if (str[k] == CH)
                break;
        if (k != str.length() - 1 && str[k + 1] == ch) {
            str.erase(str.begin() + k);
            str.insert(str.begin() + k + 1, CH);
            cmp1.emplace_back(j.left, str, -1, -1);
        }
    }
    sort(cmp1.begin(), cmp1.end());
}

void make_go() {
    memset(go, -1, sizeof(go));
    int m = collection.size();
    for (char ch: V) {
        for (int i = 0; i < m; i++) {
            vector<WF> cmp1;
            make_cmp(cmp1, i, ch);
            cout << cmp1.size() << endl;
            if (cmp1.empty()) continue;
            for (int j = 0; j < m; j++) {
                vector<WF> cmp2;
                for (auto &k: collection[j].element) {
                    string &str = k.right;
                    int x;
                    for (x = 0; x < str.length(); x++)
                        if (str[x] == CH)
                            break;
                    if (x && str[x - 1] == ch)
                        cmp2.emplace_back(k.left, str, -1, -1);
                }
                sort(cmp2.begin(), cmp2.end());
                //cout << cmp2.size() << endl;
                bool flag = true;
                if (cmp2.size() != cmp1.size()) continue;
                //cout << cmp1.size() << endl;
                for (int k = 0; k < cmp1.size(); k++)
                    if (cmp1[k] == cmp2[k]) continue;
                    else flag = false;
                //cout << "out " << endl;
                if (flag)
                    go[i][ch] = j;
            }
        }

    }
#ifdef DEBUG
    puts("---------------EDGE----------------------");
    stringstream sin;
    string out;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < MAX; k++)
                if (go[i][k] == j) {
                    sin.clear();
                    sin << "I" << i << "--" << (char) (k) << "--I" << j;
                    sin >> out;
                    printf("%s\n", out.c_str());
                }
#endif
}

void make_table() {
    memset(Goto, -1, sizeof(Goto));
    //write s to the table
    for (int i = 0; i < collection.size(); i++)
        for (char ch: V) {
            int x = go[i][ch];
            if (x == -1) continue;
            if (!isupper(ch))
                action[i][ch] = Content(0, x);
            else
                Goto[i][ch] = x;
        }
    //write r and acc to the table
    for (int i = 0; i < collection.size(); i++)
        for (int j = 0; j < collection[i].element.size(); j++) {
            WF &tt = collection[i].element[j];
            if (tt.right[tt.right.length() - 1] == CH) {
                if (tt.left[0] == 'S')
                    action[i]['#'] = Content(2, -1);
                else
                    for (char &k: V) {
                        int y = k;
                        if (!follow[tt.left].count(k)) continue;
                        action[i][y] = Content(1, tt.back);
                    }
            }
        }
#ifdef DEBUG
    puts("------------------------------------------LR(0)分析表--------------------------------------------------------");
    printf("%10s%5c%5s", "|", V[0], "|");
    for (int i = 1; i < V.size(); i++)
        printf("%5c%5s", V[i], "|");
    puts("");
    for (int i = 0; i < (V.size() + 1) * 10; i++)
        printf("-");
    puts("");
    stringstream sin;
    for (int i = 0; i < collection.size(); i++) {
        printf("%5d%5s", i, "|");
        for (int j = 0; j < V.size(); j++) {
            char ch = V[j];
            if (isupper(ch)) {
                if (Goto[i][ch] == -1)
                    printf("%10s", "|");
                else
                    printf("%5d%5s", Goto[i][ch], "|");
            } else {
                sin.clear();
                if (action[i][ch].type == -1)
                    printf("%10s", "|");
                else {
                    Content &temp = action[i][ch];
                    if (temp.type == 0)
                        sin << "S";
                    if (temp.type == 1)
                        sin << "R";
                    if (temp.type == 2)
                        sin << "acc";
                    if (temp.num != -1)
                        sin << temp.num;
                    sin >> temp.out;
                    printf("%7s%3s", temp.out.c_str(), "|");
                }
            }
        }
        puts("");
    }
    for (int i = 0; i < (V.size() + 1) * 10; i++)
        printf("-");
    puts("");
#endif
}

void print(const string &s1, const string &s2, const string &s3, const string &s4, const string &s5, const string &s6,
           const string &s7) {
    printf("%-15s|%-15s%-15s%-20s|%-15s%-15s%-15s\n", s1.c_str(), s2.c_str(), s3.c_str(), s4.c_str(), s5.c_str(),
           s6.c_str(), s7.c_str());
}

string get_steps(int x) {
    stringstream sin;
    sin << x;
    string ret;
    sin >> ret;
    return ret;
}

template<class T>
string get_stk(vector<T> stk) {
    stringstream sin;
    for (int i = 0; i < stk.size(); i++)
        sin << stk[i];
    string ret;
    sin >> ret;
    return ret;
}

string get_shift(WF &temp) {
    stringstream sin;
    sin << "reduce(" << temp.left << "->" << temp.right << ")";
    string out;
    sin >> out;
    return out;
}

void analyse(string src) {
    print("steps", "op-stack", "input", "operation", "state-stack", "ACTION", "GOTO");
    vector<char> op_stack;
    vector<int> st_stack;
    src += "#";
    op_stack.push_back('#');
    st_stack.push_back(0);
    int steps = 1;
    for (int i = 0; i < src.length(); i++) {
        char u = src[i];
        int top = st_stack[st_stack.size() - 1];
        Content &act = action[top][u];
        if (act.type == 0) {
            print(get_steps(steps++), get_stk(op_stack), src.substr(i), "shift", get_stk(st_stack), act.out, "");
            op_stack.push_back(u);
            st_stack.push_back(act.num);
        } else if (act.type == 1) {
            WF &tt = wf[act.num];
            int y = st_stack[st_stack.size() - tt.right.length() - 1];
            int x = Goto[y][tt.left[0]];
            print(get_steps(steps++), get_stk(op_stack), src.substr(i), get_shift(tt), get_stk(st_stack), act.out,
                  get_steps(x));
            for (int j = 0; j < tt.right.length(); j++) {
                st_stack.pop_back();
                op_stack.pop_back();
            }
            op_stack.push_back(tt.left[0]);
            st_stack.push_back(x);
            i--;
        } else if (act.type == 2) {
            print(get_steps(steps++), get_stk(op_stack), src.substr(i), "Accept", get_stk(st_stack), act.out, "");
        } else continue;
    }
}

int main() {
    int n;
    char s[MAX];
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s), j;
            for (j = 0; j < len; j++)
                if (s[j] == '-') break;
            s[j] = 0;
            wf.emplace_back(s, s + j + 2, -1, -1);
#ifdef DEBUG
            wf[wf.size() - 1].print();
#endif
        }
        make_item();
        make_first();
        make_follow();
        make_set();
        make_V();
        make_go();
        make_table();
        analyse("(i*i)+i");
    }
}