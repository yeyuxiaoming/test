//给定一个表示分数加减运算表达式的字符串，你需要返回一个字符串形式的计算结果。?这个结果应该是不可约分的分数，即最简分数。?如果最终结果是一个整数，例如?2，你需要将它转换成分数形式，其分母为?1。所以在上述例子中, 2?应该被转换为?2/1。
class Solution {
public:
    struct Fraction{
        int up;
        int down;
        Fraction(){}
        Fraction(int Up, int Down):up(Up), down(Down){}
    };
    int gcd(int x, int y){
        return y==0?x:gcd(y, x%y);
    }
    Fraction reduction(Fraction fraction){
        if(fraction.down<0){
            fraction.up=-fraction.up;
            fraction.down=-fraction.down;
        }
        if(fraction.up==0) fraction.down=1;
        else{
            int gd=gcd(abs(fraction.up), abs(fraction.down)); //取正数的最大公因子
            fraction.up/=gd;
            fraction.down/=gd;
        }
        return fraction;
    }
    Fraction add(Fraction a, Fraction b){
        Fraction fraction;
        fraction.up=a.up*b.down+b.up*a.down;
        fraction.down=a.down*b.down;
        return reduction(fraction);
    }
    Fraction sub(Fraction a, Fraction b){
        Fraction fraction;
        fraction.up=a.up*b.down-b.up*a.down;
        fraction.down=a.down*b.down;
        return reduction(fraction);
    }
    int sToi(string str){
        int ans=0;
        for(int i=0;i<str.length();i++){
            ans=ans*10+str[i]-'0';
        }
        return ans;
    }
    Fraction handleStr(string str){
        Fraction fraction;
        int flag=1;
        if(str[0]=='-') {flag=-1;str=str.substr(1);}
        int idx=str.find('/');
        fraction.up=flag*sToi(str.substr(0, idx));
        fraction.down=sToi(str.substr(idx+1));
        return reduction(fraction);
    }
    string fractionAddition(string expression) {
        queue<Fraction> q;
        int start=0;
        for(int i=0;i<expression.length();i++){
            if(i!=0){
                if(expression[i]=='+'||expression[i]=='-'){
                    string s=expression.substr(start, i-start);
                    q.push(handleStr(s));
                    start=i;
                    if(expression[i]=='+') start++;
                }
            }
        }
        q.push(handleStr(expression.substr(start))); //最后一个分数
        while(q.size()>1){
            Fraction a=q.front();q.pop();
            Fraction b=q.front();q.pop();
            q.push(add(a, b));
        }
        Fraction res=q.front();q.pop();
        string result="";
        result+=to_string(res.up);
        result+='/';
        result+=to_string(res.down);
        return result;
    }
};
