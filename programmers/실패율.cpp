#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> temp;
    double user=stages.size();//stage길이가 너무 클수 있으므로
    
     for(int i=1;i<=N;i++){
        double cnt=0;
         
       for(double j=0;j<stages.size();j++){
            if(i==stages[j])
                cnt++;
        }
         if(cnt==0)
             temp.push_back(0);
         else
             temp.push_back(cnt/user);
         user-=cnt;
    }
    
    //실패율을 내림차순으로 나열했을때 스테이지 번호를 answer에 넣어주는 방법
    //max_element()함수는 반복자를 리턴해주므로 itr은 결국 iterator형이 된다.
    //rate.begin()부터 rate.end()까지 가장 큰 값을 가지는 곳의 반복자를 리턴해준다..!
    //그렇다면 answer에는 itr - rate.begin() + 1을 하여 스테이지의 번호를 넣어주면 된다..!
    //+1을 하는 이유는 인덱스는 0부터 시작하기 때문이다..!
    //그리고 *itr = -111을 하여 해당 스테이지의 실패율을 가장 낮게 만들어준다..!
    
    for(int i = 0; i < N; i++)
    {
        auto itr = max_element(temp.begin(), temp.end());
        answer.push_back(itr - temp.begin() + 1);
        *itr = -111;
    }
    
    return answer;
}