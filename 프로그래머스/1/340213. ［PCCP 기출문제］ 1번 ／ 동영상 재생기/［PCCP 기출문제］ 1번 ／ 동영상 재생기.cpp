#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> split(const string& str, char delimiter = ':')
{
    vector<string> tokens;
    string token;
    stringstream ss(str);

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int convert2Seconds(const string& mstr, const string& sstr)
{
    int m = stoi(mstr);
    int s = stoi(sstr);

    return m * 60 + s;
}

string seconds2string(int seconds)
{
    int m = seconds / 60;
    int s = seconds % 60;

    ostringstream oss;
    oss << setw(2) << setfill('0') << m << ':' << setw(2) << setfill('0') << s;

    return oss.str();
}

int next(int pos, int video_len)
{
    int result = pos + 10;
    if (result > video_len)
        result = video_len;
    return result;
}

int prev(int pos)
{
    int result = pos - 10;
    if (result < 0)
        result = 0;
    return result;
}

int skip_op(int pos, int op_start, int op_end)
{
    int result = pos;
    if (op_start <= pos && pos <= op_end)
    {
        result = op_end;
    }

    return result;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";

    vector<string> video_len_split = split(video_len);
    vector<string> pos_split = split(pos);
    vector<string> op_start_split = split(op_start);
    vector<string> op_end_split = split(op_end);

    int video_len_s = convert2Seconds(video_len_split[0], video_len_split[1]);
    int pos_s = convert2Seconds(pos_split[0], pos_split[1]);
    int op_start_s = convert2Seconds(op_start_split[0], op_start_split[1]);
    int op_end_s = convert2Seconds(op_end_split[0], op_end_split[1]);

    for (auto& command : commands)
    {
        pos_s = skip_op(pos_s, op_start_s, op_end_s);
        
        if (command == "next")
        {
            pos_s = next(pos_s, video_len_s);
        }
        else if (command == "prev")
        {
            pos_s = prev(pos_s);
        }
        
        pos_s = skip_op(pos_s, op_start_s, op_end_s);
    }

    answer = seconds2string(pos_s);

    return answer;
}
