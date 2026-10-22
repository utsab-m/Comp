#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // this is for teams, not seeds
    vector<ld> a(8), b(8);
    for (int i=0; i<8; ++i) cin >> a[i] >> b[i];

    vector<int> perm(8);
    for (int i=0; i<8; ++i) perm[i] = i+1;

    ld maxProb = 0;

    do {
        vector<double> round1(8), round2(8);
        int teamOneSeed;
        for (int i=0; i<4; i++) {
            // index is seed
            int firstTeam = perm[2*i], secondTeam = perm[2*i+1];
            double strengthA = a[firstTeam-1], strengthB = b[secondTeam-1];
            round1[2*i] = strengthA / (strengthA + strengthB);
            round1[2*i+1] = strengthB / (strengthA + strengthB);

            if (perm[2*i] == 1) teamOneSeed = 2*i;
            else if (perm[2*i+1] == 1) teamOneSeed = 2*i+1;
        }
        // choosing a pair to both win round 1 then see how likely it is that each win their respective bracket
        for (int i=0; i<4; ++i) {
            for (int j=i+1; j<4; ++j) {
                if (i / 2 == j / 2) continue; // can't be in the same round 1 bracket
                int firstTeam = perm[i], secondTeam = perm[j], thirdTeam = perm[i+4], fourthTeam = perm[j+4];
                // first we calculate the probability of both firstTeam and secondTeam winning round 1
                double fsWin1 = round1[i] * round1[j], tfWin1 = round1[i+4] * round1[j+4];
                // then we calculate the chance first beats second and second beats first and add to respective round 2 probabilities
                // since i < j, the seed of i is always gonna mean we take a for team i
                round2[i] += fsWin1 * a[firstTeam-1] / (a[firstTeam-1] + b[secondTeam-1]); // case team at seed i wins
                round2[j] += fsWin1 * b[secondTeam-1] / (a[firstTeam-1] + b[secondTeam-1]); // case team at seed j wins
                round2[i+4] += tfWin1 * a[thirdTeam-1] / (a[thirdTeam-1] + b[fourthTeam-1]);
                round2[j+4] += tfWin1 * b[fourthTeam-1] / (a[thirdTeam-1] + b[fourthTeam-1]);
            }
        }
        // now we just have to find out how TEAM 1 can win each round basically. this means it must win round 2 and then beat other team
        ld prob = 0;
        for (int i=0; i<8; ++i) {
            int part1 = min(teamOneSeed, i), part2 = max(teamOneSeed, i);
            int team1 = perm[part1], team2 = perm[part2];
            if (part1 / 4 == part2 / 4) continue;

            ld win2 = round2[part1] * round2[part2];
            
            if (team1 == 1) {
                prob += win2 * a[team1-1] / (a[team1-1] + b[team2-1]);
            } else {
                prob += win2 * b[team2-1] / (a[team1-1] + b[team2-1]);
            }
        }
        maxProb = max(maxProb, prob);

    } while (next_permutation(perm.begin(), perm.end()));

    cout << fixed << setprecision(9) << maxProb << '\n';
}