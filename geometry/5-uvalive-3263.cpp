
#include <cassert>
#include <numeric>
#include <functional>
#include <iostream>
#include <bitset>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <deque>
#include <sstream>
#include <queue>
#include <tuple>
#include <climits>
#include <complex>
using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define INF 0x3f3f3f3f
#define F first
#define S second
#define speedup ios_base::sync_with_stdio(0);cin.tie(0)
#define in_d(a) scanf("%Lf", &a)
#define in_d2(a,b) scanf("%Lf%Lf", &a, &b)
#define in_d3(a,b,c) scanf("%Lf%Lf%Lf", &a, &b, &c)
#define in_d4(a,b,c,d) scanf("%Lf%Lf%Lf%Lf", &a, &b, &c, &d)
#define in_l(a) scanf("%lld", &a)
#define in_l2(a,b) scanf("%lld%lld", &a, &b)
#define in_l3(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
#define in_l4(a,b,c,d) scanf("%lld%lld%lld%lld", &a, &b, &c, &d)
#define in_i(a) scanf("%d", &a)
#define in_i2(a,b) scanf("%d%d", &a, &b)
#define in_i3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define in_i4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define in_s(a) scanf("%s", a)
#define all(c) c.begin(), c.end()
#define rep(i, j, k) for (int i = (j); i < (int)(k); i++)
#define rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i < (int)(t1); i++) for (int j = (f2); j < (int)(t2); j++)
#define Rep(i, j, k) for (int i = (j); i <= (int)(k); i++)
#define Rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i <= (int)(t1); i++) for (int j = (f2); j <= (int)(t2); j++)
#define per(i, j, k) for (int i = (j); i >= (int)(k); i--)
#define out_i(a) printf("%d\n", a);
#define out_i2(a,b) printf("%d %d\n", a, b);
#define out_i3(a,b,c) printf("%d %d %d\n", a, b, c);
#define out_i4(a,b,c,d) printf("%d %d %d %d\n", a, b, c, d);
#define out_l(a) printf("%lld\n", a);
#define out_l2(a,b) printf("%lld %lld\n", a, b);
#define out_l3(a,b,c) printf("%lld %lld %lld\n", a, b, c);
#define out_l4(a,b,c,d) printf("%lld %lld %lld %lld\n", a, b, c, d);
#define out_d(a) printf("%.10Lf\n", a);
#define out_d2(a,b) printf("%.10Lf %.10Lf\n", a, b);
#define out_d3(a,b,c) printf("%.10Lf %.10Lf %.10Lf\n", a, b, c);
#define out_d4(a,b,c,d) printf("%.10Lf %.10Lf %.10Lf %.10Lf\n", a, b, c, d);
#define out_s(s) printf("%s\n", s);
#define out_ci(c) if (!c.empty()) printf("%d", c[0]); rep(i, 1, c.size()) printf(" %d", c[i]); puts("")
#define out_cd(c) if (!c.empty()) printf("%.10Lf", c[0]); rep(i, 1, c.size()) printf(" %.10Lf", c[i]); puts("")
#define out_cl(c) if (!c.empty()) printf("%lld", c[0]); rep(i, 1, c.size()) printf(" %lld", c[i]); puts("")
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef vector<LD> VD;
typedef vector<PDD> VDD;
typedef vector< vector<PDD> > VVD;
typedef vector<LL> VL;
typedef vector<PLL> VLL;
typedef vector< vector<PLL> > VVL;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<vector<PII> > VVI;
#define N 103000

typedef long double LD;
const LD EPS = 1e-8;
const LD PI = 3.1415926535897;


// class defination
// 向量
class Vec {
public:
    LD x, y;
    Vec() {}
    Vec(LD _x, LD _y) : x(_x), y(_y) {}

    bool operator == (const Vec o) const;  // 向量相等
    Vec  operator - (const Vec o) const;   // 向量减
    Vec  operator + (const Vec o) const;   // 向量加
    LD   operator * (const Vec o) const;   // 向量点乘
    Vec  operator * (const int o) const;   // 向量数乘
    LD  operator ^ (const Vec o) const;    // 向量叉乘
    Vec operator - () const;               // 向量反向

    Vec rotate(LD alpha);                  // 向量逆时针旋转alpha(弧度)
    LD len() const;                        // 向量长度
    LD ang() const;                        // 向量极角(弧度)(0,2*pi)

    LD angto(Vec &o);                      // 当前向量到向量o旋转度数(弧度)(-pi,pi)，逆时针为正
};

// 点
class Pt {
public:
    LD x,y;
    Pt(LD _x, LD _y) : x(_x), y(_y) {}
    Pt() { Pt(0,0); }

    bool operator == (const Pt o) const;          // 判断点重合
    bool operator != (const Pt o) const;          // 判断点不重合

    Pt operator + (const Vec v) const;            // 点在向量下变换
    Pt operator - (const Vec v) const;            // 点在向量下变换
    Vec operator - (const Pt p) const;            // 两点生成向量

    LD dist(Pt &o);                               // 两点距离
    LD dist(vector<Pt> &pset,Pt &q);              // 计算点到折线集的最近距离,并返回最近点.
    Pt rotate_by(Pt &o, LD alpha);                // 返回*this绕点o逆时针旋转alpha(弧度)后的点
    LD angle(Pt s,Pt e);                          // 返回顶角在o点(*this)，起始边为os，终止边为oe的夹角(单位：弧度)

};

// 直线
class Line {
public:
    LD a, b, c;
    Line() {}
    Line(LD _a, LD _b, LD _c) : a(_a), b(_b), c(_c) {}
    Line(Pt p1, Pt p2);

    void nornalize();                     // 使a > 0

    LD slope();                           // 返回斜率
    LD alpha();                           // 返回直线的倾斜角 alpha ( 0 - pi)

    Pt symmetry(Pt p);                    // 求点p关于直线l的对称点
    bool same_side(Pt p1, Pt p2);         // 点在直线同侧返回true
    bool intersect(Line l,Pt &p);         // 两直线相交返回true并返回交点p,平行则返回false
    int relation(Line l);                 // 两直线关系
    LD p2l_dist(Pt p, Pt &np);            // 求点p到直线l所在直线的距离, np保存垂足
};

// 线段
class Seg {
public:
    Pt s, e;
    Seg() {}
    Seg(Pt _s, Pt _e) : s(_s), e(_e) {}
    Seg(Line l);

    bool has_p(Pt p);                       // 判断点在线段上(包括端点)
    bool has_p_ex(Pt p);                    // 判断点在线段上(不包括端点)
    LD relation(Pt p);                      // 点与线段的关系, (r=0, p=s),(r=1, p=e),(r<0, p在反向延长线),(r>1, p在延长线),(0<r<1, p在线段上)
    LD p2s_dist(Pt p,Pt &np);               // 求点p到线段l的最短距离,并返回线段上距该点最近的点np

    bool intersect(Seg l, Pt &p);           // 如果线段l1和l2相交，返回true且交点由(p)返回，否则返回false
    bool intersect(Seg l);                  // 如果线段u和v相交(包括相交在端点处)时,返回true
    bool intersect_ex(Seg l);               // 如果线段u和v相交(不包括相交在端点处)时,返回true
    bool intersect_l(Seg l);                // 线段v所在直线与线段u相交时返回true

    explicit operator Vec const () {return s-e;}   // 线段转换为向量
    explicit operator Line const () {return Line(s,e);} // 线段转换为直线
};

class Circle {
public:
    Pt o; LD r;
    Circle() {}
    Circle(Pt _o, LD _r) : o(_o), r(_r) {}

    int relation(Circle c);                        // 两圆位置关系
    int intersect(Line l, Pt &rp1, Pt &rp2);       // 圆和直线(ax+by+c=0,a>=0)关系
    bool intersect(Circle c, Pt &rp1,Pt &rp2);     // 两个圆(相交或相切返回true)的交点rp1,rp2
    bool intersect(Pt sp,Pt &rp1,Pt &rp2);         // 过圆外一点的直线与圆的两个切点(p为圆心,r为圆半径,点sp为圆外一点)
    LD intersect(Circle c);                        // 两相交圆公共面积

    bool has_p(Pt p);                              // 返回值:点p在圆内(包括边界)时,返回true

};

// misc functions
int sign(LD x);                                      // 返回精度允许下的符号
LD xmult(Pt p1,Pt p2,Pt p0);                         // 计算cross product (P1-P0)x(P2-P0)
LD dmult(Pt p1, Pt p2, Pt p0);                       // 计算dot product (P1-P0).(P2-P0)
LD dist(Pt &p1, Pt &p2);                             // 两点距离
Pt pmid(Pt p1, Pt p2);                               // 两点的中点

Vec operator * (const int o, const Vec v);           // 向量数乘

Circle cocircle(Pt p1,Pt p2,Pt p3);                  // 三点确定一个圆,不能构成圆返回半径为负
Circle incircle(Pt p1,Pt p2,Pt p3);                  // 三角形内切圆
void done_sq(Pt a, Pt c, Pt& b, Pt &d);              // 已知正方形对角线上两顶点(a和c),求另两点(b和d);
bool p3_inline(Pt p1, Pt p2, Pt p3);                 // 判断三点共线
Line bisector(Pt& a, Pt& b);                         //求两点的平分线


// implementation of class methods;
// 判断点重合
bool Pt::operator == (const Pt o) const {
    return abs(x-o.x) < EPS && abs(y-o.y) < EPS;
}

// 判断点不重合
bool Pt::operator != (const Pt o) const {
    return !(*this == o);
}

// 点在向量下变换
Pt Pt::operator + (const Vec v) const {
    return Pt(x+v.x, y+v.y);
}

// 点在向量下变换
Pt Pt::operator - (const Vec v) const {
    return Pt(x-v.x, y-v.y);
}

// 两点生成向量
Vec Pt::operator - (const Pt p) const {
    return Vec(x-p.x, y-p.y);
}

// 两点距离
LD Pt::dist(Pt & o) {
    Pt &a = *this, &b = o;
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

// 返回*this绕点o逆时针旋转alpha(弧度)后的点
Pt Pt::rotate_by(Pt &o, LD alpha) {
    Pt tp;
    LD cx = x, cy = y;
    cx-=o.x;
    cy-=o.y;
    tp.x=cx*cos(alpha)-cy*sin(alpha)+o.x;
    tp.y=cy*cos(alpha)+cx*sin(alpha)+o.y;
    return tp;
}

/******************************************************************************
       返回顶角在o点，起始边为os，终止边为oe的夹角(单位：弧度)
    角度小于pi，返回正值
    角度大于pi，返回负值
    可以用于求线段之间的夹角
    原理：
    r = dotmultiply(s,e,o) / (dist(o,s)*dist(o,e))
    r'= multiply(s,e,o)
    r >= 1 angle = 0;
    r <= -1 angle = -PI
    -1<r<1 && r'>0 angle = arccos(r)
    -1<r<1 && r'<=0 angle = -arccos(r)
********************************************************************************/
LD Pt::angle(Pt s,Pt e) {
    Pt o = *this;
    LD cosfi,fi,norm;
    LD dsx = s.x - o.x;
    LD dsy = s.y - o.y;
    LD dex = e.x - o.x;
    LD dey = e.y - o.y;
    cosfi=dsx*dex+dsy*dey;
    norm=(dsx*dsx+dsy*dsy)*(dex*dex+dey*dey);
    cosfi /= sqrt( norm );
    if (cosfi >=  1.0 ) return 0;
    if (cosfi <= -1.0 ) return -3.1415926;
    fi=acos(cosfi);
    if (dsx*dey-dsy*dex>0) return fi;      // 说明矢量os 在矢量 oe的顺时针方向
    return -fi;
}

/******************************************************************************
     计算点到折线集的最近距离,并返回最近点.
    注意：调用的是ptolineseg()函数
*******************************************************************************/
LD Pt::dist(vector<Pt> &pset,Pt &q)
{
    Pt &p = *this;
    LD cd=LD(1e200),td;
    Seg l;
    Pt tq,cq;
    for(int i=0; i<(int)pset.size()-1; i++) {
        l.s=pset[i];
        l.e=pset[i+1];
        td=l.p2s_dist(p,tq);
        if(td<cd) {
            cd=td;
            cq=tq;
        }
    }
    q=cq;
    return cd;
}

// 向量极角
LD Vec::ang() const {
    LD ret = atan2(y,x);
    // if (ret < 0) ret += 2*PI;
    return ret;
}

// 当前向量到向量o旋转度数(弧度)(-pi,pi)，逆时针为正
LD Vec::angto(Vec &o) {
    LD ans = o.ang()-ang();
    if (ans > PI)
        ans = 2*PI - ans;
    else if (ans < -PI)
        ans = 2*PI + ans;
    return ans;
}

bool Vec::operator == (const Vec o) const {
    return abs(x-o.x) < EPS && abs(y-o.y) < EPS;
}

// 向量减
Vec Vec::operator - (const Vec o) const {
    return Vec(x-o.x, y-o.y);
}

// 向量加
Vec Vec::operator + (const Vec o) const {
    return Vec(x+o.x, y+o.y);
}

// 向量点乘
LD Vec::operator * (const Vec o) const {
    return x*o.x + y*o.y;
}

// 向量数乘
Vec Vec::operator * (const int o) const {
    return Vec(x*o, y*o);
}
Vec operator * (const int o, const Vec v) {
    return v*o;
}

// 向量叉乘
LD Vec::operator ^ (const Vec o) const {
    return x*o.y - y*o.x;
}

// 向量反向
Vec Vec::operator - () const {
    return Vec(-x, -y);
}

// 向量逆时针旋转alpha(弧度)
Vec Vec::rotate(LD alpha) {
    return Vec(x*cos(alpha) - y*sin(alpha), x*sin(alpha) + y*cos(alpha));
}

// 向量长度
LD Vec::len() const {
    return sqrt(x*x+y*y);
}


// seg from line
Seg::Seg(Line l) {
    if (abs(l.b) < EPS) {
        s = Pt(-l.c/l.a, 0);
        e = Pt(-l.c/l.a,10);
    }
    else if (abs(l.a) < EPS) {
        s = Pt(0, -l.c/l.b);
        e = Pt(10, -l.c/l.b);
    }
    else {
        s = Pt(0, -l.c/l.b);
        e = Pt(-l.c/l.a, 0);
    }
}

/******************************************************************************
    判断点p是否在线段l上(包括端点)
    条件：(p在线段l所在的直线上) && (点p在以线段l为对角线的矩形内)
*******************************************************************************/
bool Seg::has_p(Pt p) {
    return !sign(xmult(e,s,p)) && sign(dmult(e,s,p)) <= 0;
    // return( (xmult(e,p,s) < EPS) &&( ( (p.x-s.x)*(p.x-e.x)<=EPS )&&( (p.y-s.y)*(p.y-e.y)<=EPS ) ) );
}

/******************************************************************************
    判断点在线段上(不包括端点)
    条件：(p在线段l所在的直线上) && (点p在以线段l为对角线的矩形内)
*******************************************************************************/
bool Seg::has_p_ex(Pt p) {
    return !sign(xmult(e,s,p)) && sign(dmult(e,s,p)) < 0;
    // return has_p(p) && (p != s && p != e);
}

// 如果线段l1和l2相交，返回true且交点由(p)返回，否则返回false
bool Seg::intersect(Seg l2, Pt &p) {
    Seg &l1 = *this;
    Line ll1=Line(l1.s,l1.e);
    Line ll2=Line(l2.s,l2.e);
    if(l1.intersect(l2)) {
        ll1.intersect(ll2, p);
        return true;
    }
    else return false;
}

/******************************************************************************
    如果线段u和v相交(包括相交在端点处)时,返回true
    判断P1P2跨立Q1Q2的依据是: ( P1 - Q1 ) x ( Q2 - Q1 ) x ( Q2 - Q1 ) x ( P2 - Q1 ) >= 0
    判断Q1Q2跨立P1P2的依据是: ( Q1 - P1 ) x ( P2 -  P1 ) x ( P2 - P1 ) x ( Q2 - P1 ) >= 0
*******************************************************************************/
bool Seg::intersect(Seg v) {
    Seg &u = *this;
    return((max(u.s.x,u.e.x)>=min(v.s.x,v.e.x))&&                     //排斥实验
           (max(v.s.x,v.e.x)>=min(u.s.x,u.e.x))&&
           (max(u.s.y,u.e.y)>=min(v.s.y,v.e.y))&&
           (max(v.s.y,v.e.y)>=min(u.s.y,u.e.y))&&
           (xmult(v.s,u.e,u.s)*xmult(u.e,v.e,u.s)>=0)&&         //跨立实验
           (xmult(u.s,v.e,v.s)*xmult(v.e,u.e,v.s)>=0));
}

// (线段u和v相交)&&(交点不是端点)时返回true
bool Seg::intersect_ex(Seg v) {
    Seg &u = *this;
    return ((u.intersect(v))&&
            (!u.has_p(v.s))&&
            (!u.has_p(v.e))&&
            (!v.has_p(u.e))&&
            (!v.has_p(u.s)));
}

/******************************************************************************
    线段v所在直线与线段u相交时返回true;方法;判断线段u是否跨立线段v
*******************************************************************************/
bool Seg::intersect_l(Seg v) {
    Seg &u = *this;
    return xmult(u.s,v.e,v.s)*xmult(v.e,u.e,v.s)>=0;
}


/******************************************************************************
    判断点与线段的关系,用途很广泛
    本函数是根据下面的公式写的，P是点C到线段AB所在直线的垂足


            AC dot AB
    r =     ---------
             ||AB||^2
         (Cx-Ax)(Bx-Ax) + (Cy-Ay)(By-Ay)
      = -------------------------------
                      L^2
    r has the following meaning:
    r=0      P = A
    r=1      P = B
    r<0   P is on the backward extension of AB
    r>1      P is on the forward extension of AB
    0<r<1  P is interior to AB
********************************************************************************/
LD Seg::relation(Pt p) {
    Seg tl, &l = *this;
    tl.s=l.s;
    tl.e=p;
    return dmult(tl.e,l.e,l.s)/(dist(l.s,l.e)*dist(l.s,l.e));
}


/******************************************************************************
       求点p到线段l的最短距离,并返回线段上距该点最近的点np
    注意：np是线段l上到点p最近的点，不一定是垂足
*******************************************************************************/
LD Seg::p2s_dist(Pt p,Pt &np) {
    Seg &l = *this;
    LD r=l.relation(p);
    if(r<EPS) {
        np=l.s;
        return dist(p,l.s);
    }
    if(r>1+EPS) {
        np=l.e;
        return dist(p,l.e);
    }
    Line tmp = (Line) l;
    tmp.p2l_dist(p, np);
    return dist(p,np);
}

// 使a > 0
void Line::nornalize() {
    if (a < -EPS) {
        a *= -1; b *= -1; c *= -1;
    }
}

// 两直线相交返回true并返回交点p,不相交则返回false
bool Line::intersect(Line l2,Pt &p) {
    Line &l1 = *this;
    LD d=l1.a*l2.b-l2.a*l1.b;
    if(abs(d)<EPS) // 不相交
        return false;
    p.x = (l2.c*l1.b-l1.c*l2.b)/d;
    p.y = (l2.a*l1.c-l1.a*l2.c)/d;
    return true;
}

// 两直线关系
//////////////////////////
// 返回值:              //
//       平行: 1        //
//       垂直: 2        //
//       相交: 3        //
//////////////////////////
int Line::relation(Line l) {
    if (abs(a) < EPS && abs(l.a) < EPS) return 1;
    if (abs(b/a - l.b/l.a) < EPS) return 1;
    if (abs(a/b * l.a/l.b - (-1)) < EPS) return 2;
    return 3;
}

// 求点p到直线l所在直线的距离,tp保存垂足
LD Line::p2l_dist(Pt p, Pt &tp) {
    Seg l = Seg(*this);

    LD r=l.relation(p);
    tp.x=l.s.x+r*(l.e.x-l.s.x);
    tp.y=l.s.y+r*(l.e.y-l.s.y);
    return tp.dist(p);
}



// 求点p关于直线l的对称点
Pt Line::symmetry(Pt p) {
    Line &l = *this;
    Pt tp;
    tp.x=((l.b*l.b-l.a*l.a)*p.x-2*l.a*l.b*p.y-2*l.a*l.c)/(l.a*l.a+l.b*l.b);
    tp.y=((l.a*l.a-l.b*l.b)*p.y-2*l.a*l.b*p.x-2*l.b*l.c)/(l.a*l.a+l.b*l.b);
    return tp;
}

// 点在直线同侧返回true
bool Line::same_side(Pt p1, Pt p2) {
    Line &line = *this;
    return (line.a * p1.x + line.b * p1.y + line.c) *
        (line.a * p2.x + line.b * p2.y + line.c) > EPS;
}

// 返回直线的倾斜角 alpha ( 0 - pi)
LD Line::alpha() {
    if(abs(a)< EPS)
        return 0;
    if(abs(b)< EPS)
        return PI/2;
    LD k=slope();
    if(k>0) return atan(k);
    else return PI+atan(k);
}

// 返回斜率
LD Line::slope() {
    if(abs(a) < EPS*1e-3)
        return 0;
    if(abs(b) < EPS*1e-3)
        return 1e200;
    return -(a/b);
}

Line::Line(Pt p1, Pt p2) {
    LD dx = p2.x-p1.x;
    LD dy = p2.y-p1.y;
    if (abs(dx) < EPS) {
        b = 0; a = 1; c = -p1.x;
    }
    else {
        LD k = dy/dx;
        a = k, b = -1, c = p1.y-k*p1.x;
    }
}

/******************************************************************************
    参数o为圆心,r为半径,p为判断的点
    返回值:点p在圆内(包括边界)时,返回true
*******************************************************************************/
bool Circle::has_p(Pt p) {
    return dist(p, o) < r+EPS;
}

/******************************************************************************
    判断两圆位置关系
    相离:return 1
    外切:return 2
    相交:return 3
    内切:return 4
    内含:return 5
*******************************************************************************/
int Circle::relation(Circle c2) {
    Circle &c1 = *this;
    Pt &p1 = c1.o, &p2 = c2.o;
    LD &r1 = c1.r, &r2 = c2.r;
    LD d = sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) );
    if( abs(d-r1-r2) < EPS ) // 必须保证前两个if先被判定！
        return 2;
    if( abs(d-abs(r1-r2)) < EPS )
        return 4;
    if( d > r1+r2 )
        return 1;
    if( d < abs(r1-r2) )
        return 5;
    if( abs(r1-r2) < d && d < r1+r2 )
        return 3;
    return 0; // indicate an error!未知错误
}

/******************************************************************************
    圆和直线(ax+by+c=0,a>=0)关系
    相离 return 0
    相切 return 1
    相交 return 2
*******************************************************************************/
int Circle::intersect(Line l, Pt &rp1, Pt &rp2) {
    Circle &cir = *this;
    LD &a = l.a, &b = l.b, &c = l.c;
    Pt &p = cir.o;
    LD &r = cir.r;
    int res=0;
    c=c+a*p.x+b*p.y;
    LD tmp;
    if(abs(a)<EPS&&abs(b)>EPS) {
        tmp=-c/b;
        if(r*r<tmp*tmp) res=0;
        else if(r*r==tmp*tmp) {
            res=1;
            rp1.y=tmp;
            rp1.x=0;
        }
        else {
            res=2;
            rp1.y=rp2.y=tmp;
            rp1.x=sqrt(r*r-tmp*tmp);
            rp2.x=-rp1.x;
        }
    }
    else if(abs(a)>EPS&&abs(b)<EPS) {
        tmp=-c/a;
        if(r*r<tmp*tmp) res=0;
        else if(r*r==tmp*tmp) {
            res=1;
            rp1.x=tmp;
            rp1.y=0;
        }
        else {
            res=2;
            rp1.x=rp2.x=tmp;
            rp1.y=sqrt(r*r-tmp*tmp);
            rp2.y=-rp1.y;
        }
    }
    else if(abs(a)>EPS&&abs(b)>EPS) {
        LD delta;
        delta=b*b*c*c-(a*a+b*b)*(c*c-a*a*r*r);
        if(delta<0) res=0;
        else if(delta==0) {
            res=1;
            rp1.y=-b*c/(a*a+b*b);
            rp1.x=(-c-b*rp1.y)/a;
        }
        else {
            res=2;
            rp1.y=(-b*c+sqrt(delta))/(a*a+b*b);
            rp2.y=(-b*c-sqrt(delta))/(a*a+b*b);
            rp1.x=(-c-b*rp1.y)/a;
            rp2.x=(-c-b*rp2.y)/a;
        }
    }
    rp1.x+=p.x;
    rp1.y+=p.y;
    rp2.x+=p.x;
    rp2.y+=p.y;
    return res;
}

// 两个圆(相交或相切返回true)的交点rp1,rp2
bool Circle::intersect(Circle c2,Pt &rp1,Pt &rp2) {
    Circle &c1 = *this;
    int rela = c1.relation(c2);
    if (rela == 5 || rela == 1) return 0;
    Pt &p1 = c1.o, &p2 = c2.o;
    LD &r1 = c1.r, &r2 = c2.r;
    LD a,b,r;
    a=p2.x-p1.x;
    b=p2.y-p1.y;
    r=(a*a+b*b+r1*r1-r2*r2)/2;
    if(abs(a)<EPS&&abs(b)>EPS) {
        rp1.y=rp2.y=r/b;
        rp1.x=sqrt(r1*r1-rp1.y*rp1.y);
        rp2.x=-rp1.x;
    }
    else if(abs(a)>EPS&&abs(b)<EPS) {
        rp1.x=rp2.x=r/a;
        rp1.y=sqrt(r1*r1-rp1.x*rp2.x);
        rp2.y=-rp1.y;
    }
    else if(abs(a)>EPS&&abs(b)>EPS) {
        LD delta;
        delta=b*b*r*r-(a*a+b*b)*(r*r-r1*r1*a*a);
        rp1.y=(b*r+sqrt(delta))/(a*a+b*b);
        rp2.y=(b*r-sqrt(delta))/(a*a+b*b);
        rp1.x=(r-b*rp1.y)/a;
        rp2.x=(r-b*rp2.y)/a;
    }
    rp1.x+=p1.x;
    rp1.y+=p1.y;
    rp2.x+=p1.x;
    rp2.y+=p1.y;

    return 1;
}

// 过圆外一点的直线与圆的两个切点(p为圆心,r为圆半径,点sp为圆外一点)
bool Circle::intersect(Pt sp,Pt &rp1,Pt &rp2) {
    Circle &c = *this;
    Pt p2;
    Pt &p = c.o;
    // LD &r = c.r;
    p2.x=(p.x+sp.x)/2;
    p2.y=(p.y+sp.y)/2;
    LD dx2,dy2,r2;
    dx2=p2.x-p.x;
    dy2=p2.y-p.y;
    r2=sqrt(dx2*dx2+dy2*dy2);
    c.intersect(Circle(p2,r2), rp1, rp2);
    return 1;
}
// 两相交圆公共面积 
LD Circle::intersect(Circle c2) {
    Circle &c1 = *this;
    Pt &p1 = c1.o, &p2 = c2.o;
    LD &r1 = c1.r, &r2 = c2.r;
    LD TEMP;
    Pt rp1,rp2,rp;
    c1.intersect(c2, rp1, rp2);
    //保证r2>r1
    if(r1>r2) {
        rp=p1; p1=p2; p2=rp;
        TEMP=r1; r1=r2; r2=TEMP;
    }
    LD a,b,rr;
    a=p1.x-p2.x;
    b=p1.y-p2.y;
    rr=sqrt(a*a+b*b);
    LD dx1,dy1,dx2,dy2;
    LD sita1,sita2;
    dx1=rp1.x-p1.x;
    dy1=rp1.y-p1.y;
    dx2=rp2.x-p1.x;
    dy2=rp2.y-p1.y;
    sita1=acos((dx1*dx2+dy1*dy2)/r1/r1);
    dx1=rp1.x-p2.x;
    dy1=rp1.y-p2.y;
    dx2=rp2.x-p2.x;
    dy2=rp2.y-p2.y;
    sita2=acos((dx1*dx2+dy1*dy2)/r2/r2);
    LD s=0;
    if(rr<r2)//相交弧为优弧
        s=r1*r1*(PI-sita1/2+sin(sita1)/2)+r2*r2*(sita2-sin(sita2))/2;
    else//相交弧为劣弧
        s=(r1*r1*(sita1-sin(sita1))+r2*r2*(sita2-sin(sita2)))/2;


    return s;
}


/******************************************************************************
    用 途 :求不共线的三点确定一个圆
    输 入 :三个点p1,p2,p3
    返回值 :如果三点共线，返回半径为负；反之，返回确定的圆。
*******************************************************************************/
Circle cocircle(Pt p1,Pt p2,Pt p3) {
    Circle ret;
    Pt &q = ret.o;
    LD &r = ret.r;
    LD x12=p2.x-p1.x;
    LD y12=p2.y-p1.y;
    LD x13=p3.x-p1.x;
    LD y13=p3.y-p1.y;
    LD z2=x12*(p1.x+p2.x)+y12*(p1.y+p2.y);
    LD z3=x13*(p1.x+p3.x)+y13*(p1.y+p3.y);
    LD d=2.0*(x12*(p3.y-p2.y)-y12*(p3.x-p2.x));
    if(abs(d)<EPS) //共线，圆不存在
        return Circle({0,0}, -1);
    q.x=(y13*z2-y12*z3)/d;
    q.y=(x12*z3-x13*z2)/d;
    r=dist(p1,q);

    return ret;
}

// 三角形内切圆
Circle incircle(Pt p1,Pt p2,Pt p3) {
    LD dx31,dy31,dx21,dy21,d31,d21,a1,b1,c1;
    Pt rp; LD r;
    dx31=p3.x-p1.x;
    dy31=p3.y-p1.y;
    dx21=p2.x-p1.x;
    dy21=p2.y-p1.y;
    d31=sqrt(dx31*dx31+dy31*dy31);
    d21=sqrt(dx21*dx21+dy21*dy21);
    a1=dx31*d21-dx21*d31;
    b1=dy31*d21-dy21*d31;
    c1=a1*p1.x+b1*p1.y;
    LD dx32,dy32,dx12,dy12,d32,d12,a2,b2,c2;
    dx32=p3.x-p2.x;
    dy32=p3.y-p2.y;
    dx12=-dx21;
    dy12=-dy21;
    d32=sqrt(dx32*dx32+dy32*dy32);
    d12=d21;
    a2=dx12*d32-dx32*d12;
    b2=dy12*d32-dy32*d12;
    c2=a2*p2.x+b2*p2.y;
    rp.x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
    rp.y=(c2*a1-c1*a2)/(a1*b2-a2*b1);
    r=abs(dy21*rp.x-dx21*rp.y+dx21*p1.y-dy21*p1.x)/d21;
    return Circle(rp, r);
}

// 已知正方形对角线上两顶点(a和c),求另两点(b和d);
void done_sq(Pt a, Pt c,Pt& b,Pt &d) {
    LD x,y,mx,my;
    mx = (a.x+c.x)/2.0;
    my = (a.y+c.y)/2.0;
    x = a.x - mx;
    y = a.y - my;
    b.x = -y + mx;
    b.y = x + my;
    x = c.x - mx;
    y = c.y - my;
    d.x = - y + mx;
    d.y = x + my;
}

// 判断三点共线
bool p3_inline(Pt p1, Pt p2, Pt p3) {
    return abs(xmult(p1,p2,p3)) < EPS;
}

//求两点的平分线
Line bisector(Pt& a, Pt& b) {
    Line ab, ans;  ab = Line(Seg(a, b));
    LD midx = (a.x + b.x)/2.0, midy = (a.y + b.y)/2.0;
    ans.a = -ab.b, ans.b = -ab.a, ans.c = -ab.b * midx + ab.a * midy;
    return ans;
}

// 返回精度允许下的符号
int sign(LD x) {
    if (abs(x) < EPS) return 0;
    if (x < 0) return -1;
    return 1;
}

// 计算cross product (P1-P0)x(P2-P0)
LD xmult(Pt p1,Pt p2,Pt p0) {
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

// 计算dot product (P1-P0).(P2-P0)
LD dmult(Pt p1, Pt p2, Pt p0) {
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}

// 两点距离
LD dist(Pt &p1, Pt &p2) {
    LD dx = p1.x-p2.x;
    LD dy = p1.y-p2.y;
    return sqrt(dx*dx+dy*dy);
}

// 两点的中点
Pt pmid(Pt p1, Pt p2) {
    return Pt((p1.x+p2.x)/2, (p1.y+p2.y)/2);
}

bool operator < (const Pt p1, const Pt p2) {
    return sign(p1.x-p2.x) < 0 || (!sign(p1.x-p2.x) && (sign(p1.y-p2.y) < 0));
}

int main() {
    freopen("3263.in", "r", stdin);
    int kase = 1;
    while (1) {
        int n; in_i(n);
        if (!n) break;
        vector<Pt> p;
        rep(i,0,n) {
            LD x,y; in_d2(x,y);
            p.pb({x,y});
        }
        vector<Seg> s;
        rep(i,0,n-1) {
            s.pb({p[i],p[i+1]});
        }
        vector<Pt> np = p;
        rep2(i,j, 0,n-1, i+1,n-1) {
            Pt npt;
            if (s[i].intersect(s[j], npt)) {
                np.pb(npt);
            }
        }
        sort(all(np));
        np.erase(unique(all(np)), np.end());
        int v = np.size(), e = n-1;
        for (auto pnt : np) {
            for (auto sg : s) {
                if (sg.has_p_ex(pnt)) {
                    // printf("Seg:(%Lf,%Lf)-(%Lf,%Lf)\n", sg.s.x, sg.s.y, sg.e.x, sg.e.y);
                    // printf("Pt: (%Lf,%Lf)\n", pnt.x, pnt.y);
                    e += 1;
                }
            }
        }
        printf("Case %d: There are %d pieces.\n", kase++, e-v+2);

    }
    return 0;
}
