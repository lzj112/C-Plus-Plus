#include <string>
#include <vector>
using namespace std;
class infint 
{
private:
    string number;
public:
    infint() {}
    infint(int tmp) { number = tmp; }
    infint(string tmp) { number = tmp; }
    ~infint() {}
    string BigInegerAdd(string s1, string s2); //相加
    string BigInegerMinus(string s1, string s2, bool negative); //相减
    string BigIneger(string s1, string s2);//判断
    string BigMutiple(string s1, string s2);//相乘
    string operator+(infint& b);
    string operator-(infint& b);
    string operator++();
    string operator+=(infint& b);
    string operator-=(infint& b);
    string operator*(infint& b);
    string operator*=(infint& b);
    string operator=(infint& b);
    friend ostream& operator<<(ostream& out, infint& b); 
};
string infint::BigInegerAdd(string s1, string s2) // s1+s2;
{
	int len = s1.size()>s2.size()?
    s1.size()+1:s2.size()+1;
	string res(len, '0');
	int i = s1.size() - 1, j = s2.size() - 1, k = len - 1;
	int borrow = 0;
	while(i >=0 && j >= 0)
	{
		int sum = s1[i] - '0' + s2[j] - '0' + borrow;
		if (sum >= 10)
		{
			borrow = 1;
			sum -= 10;
			res[k--] = sum + '0';
		}
		else {res[k--] = sum + '0'; borrow = 0;}
		i--;j--;
	}
	while(i >= 0)
	{
		int sum = s1[i] - '0' + borrow;
		if (sum >= 10)
		{
			borrow = 1;
			sum -= 10;
			res[k--] = sum + '0';
		}
		else {res[k--] = sum + '0'; borrow = 0;}
		i--;
	}
	while(j >= 0)
	{
		int sum = s2[j] - '0' + borrow;
		if (sum >= 10)
		{
			borrow = 1;
			sum -= 10;
			res[k--] = sum + '0';
		}
		else {res[k--] = sum + '0'; borrow = 0;}
		j--;
	}
	if (borrow == 1)
	{
		res[k] = '1';
	}
	else res[k] = '0';
	if (res[0] == '0')//ignore the prefix '0's
	{
		return res.substr(1, res.size()-1);
	}
	else return res;

}

//negative == true means s1 < s2
string infint::BigInegerMinus(string s1, string s2, bool negative) // s1-s2; 
{

	if (s1.size() < s2.size())
	{
		return BigInegerMinus(s2, s1, true);
	}
	if (s1.size() == s2.size())
	{
		int i = 0;
		while(i < s1.size() && s1[i] == s2[i])
			i++;
		if (s1[i] < s2[i])
		{
			return BigInegerMinus(s2, s1, true);
		}
	}
	string res(s1.size(), '0');
	int i = s1.size() -1, j = s2.size() - 1;
	int k = i;
	int borrow = 0;
	while(i >= 0 && j >= 0)
	{
		int sum = s1[i] - '0' - borrow - (s2[j] - '0');
		//cout<<sum<<endl;
		if (sum < 0)
		{
			borrow = 1;
			sum += 10;
			res[k--] = sum + '0';
		}
		else{
			borrow = 0;
			res[k--] = sum + '0';
		}
		i--;j--;
	}
	while(i >= 0)
	{
		int sum = s1[i--] - '0' - borrow;
		if (sum < 0)
		{
			borrow = 1;
			sum += 10;
			res[k--] = sum + '0';
		}
		else{
			borrow = 0;
			res[k--] = sum + '0';
		}
	}
	if (res[0] == '0')
	{
		//ignore the prefix '0's
		int index = 1;
		while(index < res.size() && res[index] == '0')
			index++;
		if (negative)
		{
			return "-" + res.substr(index, res.size() - index);
		}
		else return res.substr(index, res.size() - index);
	}
	else {
		if (negative)
		{
			return "-" + res;
		}
		else return res;
	}
}

string infint::BigIneger(string s1, string s2)
{
	if (s1 == "")
	{
		return s2;
	}
	if (s2 == "")
	{
		return s1;
	}

	char sign1 = '+', sign2 = '+';
	if (s1[0] == '-')
	{ 
		sign1 = '-';
	}
	if (s2[0] == '-')
	{
		sign2 = '-';
	}
	if (sign1 == '+' && sign2 == '+')
	{
		return BigInegerAdd(s1, s2);
	}
	else if (sign1 == '+' && sign2 == '-')
	{
		return BigInegerMinus(s1, s2.substr(1, s2.size()-1),false);
	}
	else if (sign1 == '-' && sign2 == '+')
	{
		return BigInegerMinus(s2, s1.substr(1, s1.size()-1), false);
	}
	else {
		string tmp = BigInegerAdd(s1.substr(1, s1.size()-1), s2.substr(1, s2.size()-1));
		if (tmp[0] == '0')
		{
			tmp = tmp.substr(1, tmp.size()- 1);
		}
		string res = "-" + tmp;
		return res;
	}
}

string infint::BigMutiple(string s1, string s2)
{

    string res="";
    //两个数的位数
    int m = s1.size(), n = s2.size();

    //一个i位数乘以一个j位数，结果至少是i+j-1位数
    vector<long long> tmp(m + n - 1);

    //每一位进行笛卡尔乘法
    for (int i = 0; i < m; i++){
         int a = s1[i] - '0';
        for (int j = 0; j < n; j++){
            int b = s2[j] - '0';
            tmp[i + j] += a*b;
        }
    }
    //进行进位处理，注意左侧是大右侧是小
    int carry = 0;
    for (int i = tmp.size() - 1; i >= 0; i--){
        int t = tmp[i] + carry;
        tmp[i] = t % 10;
        carry = t / 10;
    }
    //若遍历完仍然有进位
    while (carry != 0){
        int t = carry % 10;
        carry /= 10;
        tmp.insert(tmp.begin(), t);
    }
    //将结果存入到返回值中
    for (auto a : tmp){
        res = res + to_string(a);
    }
    if(res.size()>0&&res[0]=='0')return "0";
    return res;

}
string infint::operator+(infint& b) 
{
    return BigIneger(number, b.number);
}

string infint::operator-(infint& b) 
{
    return BigIneger(number, b.number);
}
string infint::operator++() 
{
    return BigIneger(number, number);
}

string infint::operator+=(infint& b) 
{
    return BigIneger(number, b.number);
}

string infint::operator-=(infint& b) 
{
    return BigIneger(number, b.number);
}

string infint::operator*(infint& b) 
{
    return BigMutiple(number, b.number);
}

string infint::operator*=(infint& b) 
{
    return BigMutiple(number, b.number);
}

string infint::operator=(infint& b) 
{
    if (&b == this) 
    {
        return this->number;
    }
    number = b.number;
    return this->number;
}

ostream& operator<<(ostream& out, infint& b) 
{
    out << b.number;
    return out;
}

