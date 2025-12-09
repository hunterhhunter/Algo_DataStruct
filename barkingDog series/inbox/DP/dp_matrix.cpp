#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // LLONG_MAX 사용

using namespace std;

// 무한대 값 (long long 최대값 사용)
const long long INF = numeric_limits<long long>::max(); 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; 
    // 실제 실행 시 N=5와 뒤이은 차원 쌍을 입력해야 합니다.
    cout << "행렬 개수 N을 입력하세요 (예: 5): ";
    cin >> N;
    
    // N+1 크기의 차원 배열 P (P[0] ~ P[N])
    vector<long long> P(N + 1); 
    
    // DP 테이블: T[i][j] = 행렬 i부터 j까지 최소 곱셈 횟수 (1-인덱스 사용)
    vector<vector<long long>> table(N + 1, vector<long long>(N + 1, 0));

    // --- 1. 입력 및 P 배열 구축 ---
    cout << "N개의 행렬 차원 (R C) 쌍을 입력하세요:\n";
    for (int i = 1; i <= N; i++) {
        long long R, C;
        cin >> R >> C;
        
        if (i == 1) {
            P[i - 1] = R; // P[0] = R1
        }
        P[i] = C; // Pi = Ci
    }
    
    cout << "\n--- 차원 배열 P: [ ";
    for (int i=0; i<=N; ++i) cout << P[i] << " ";
    cout << "] ---\n";


    // --- 2. DP 루프 (추적) ---
    
    // L: Chain Length (부분 문제의 길이), 2부터 N까지
    for (int L = 2; L <= N; L++) { 
        cout << "\n\n============================================\n";
        cout << "STEP " << L - 1 << ": 길이 L=" << L << "인 행렬 체인 계산\n";
        cout << "============================================\n";

        // i: Start index (시작 행렬의 번호), 1부터 N-L+1까지
        for (int i = 1; i <= N - L + 1; i++) {
            int j = i + L - 1; // End index
            table[i][j] = INF; // 초기 최소값 설정
            
            cout << "  [처리 대상 셀: T[" << i << "][" << j << "] (M" << i << " ~ M" << j << ")]\n";
            
            // k: Split point (분할 지점), i부터 j-1까지
            for (int k = i; k < j; k++) {
                
                long long prev_left_cost = table[i][k];
                long long prev_right_cost = table[k + 1][j];
                
                // M(i..k) (P[i-1] x P[k]) 와 M(k+1..j) (P[k] x P[j])를 합치는 비용
                long long merge_cost = P[i - 1] * P[k] * P[j];
                
                long long total_cost = prev_left_cost + prev_right_cost + merge_cost;
                
                // T[1][4] 계산 시 k=2 트레이스
                if (i == 1 && j == 4 && k == 2) {
                    cout << "    |-- 🌟🌟🌟 핵심 분할 지점 k=2 트레이스 🌟🌟🌟\n";
                }
                
                cout << "    |-- Testing k=" << k << " (Split: M" << i << "~M" << k << " | M" << (k+1) << "~M" << j << ")\n";
                cout << "    |    ㄴ Left Cost (T[" << i << "][" << k << "]): " << prev_left_cost << "\n";
                cout << "    |    ㄴ Right Cost (T[" << (k+1) << "][" << j << "]): " << prev_right_cost << "\n";
                cout << "    |    ㄴ Merge Cost (" << P[i - 1] << "x" << P[k] << "x" << P[j] << "): " << merge_cost << "\n";
                cout << "    |    ㄴ Total Cost: " << total_cost << "\n";
                
                table[i][j] = min(table[i][j], total_cost);
            }
            cout << "  [T[" << i << "][" << j << "] 최종 최소값: " << table[i][j] << "]\n";
        }
    }
    
    // --- 3. 최종 출력 ---
    cout << "\n\n============================================\n";
    cout << "최종 최소 곱셈 횟수: " << table[1][N] << "\n";
    cout << "============================================\n";

    return 0;
}