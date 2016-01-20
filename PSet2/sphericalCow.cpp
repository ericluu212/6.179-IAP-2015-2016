#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdlib>

/* Notes on meaning of variables

10 * M = Length of innermost racetrack (1 <= M <= 1000000)
L = Number of lanes on track (2 <= L <= 1000)
B = Number of bulls for each race (1 <= B <= L)
K = Integer assigned to each bull (1 <= K <= 10**10)
R = Number of laps in a race (1 <= R <= 8)
N = Number of races (1 <= N <= 1000)

*/

int main() {

	long bestTag = 0;
	double bestSpeed = 0.0;

	//Line 1
	long races, length, lanes;
	scanf("%d %d %d", &races, &length, &lanes);

	//Line 2
	long amountBulls, laps;

	//Loop through races
	for (long i = 0; i < races; i++) {

		scanf("%d %d", &amountBulls, &laps);

		for (long j = 1; j <= amountBulls; j++) {
			double rate;

			double distance = length * (10 + (j - 1)) * laps;

			long label;
			scanf("%d", &label);

			long lapTime = 0;
			long elapsedTime = 0;
			for (long z = 0; z < laps; z++) {
				scanf("%d", &lapTime);
				elapsedTime = elapsedTime + lapTime;
			}

			rate = distance / elapsedTime;

			if ( (i == 0 && j == 1) ) {
				bestSpeed = rate;
				bestTag = label;
			}

			else if ( rate >= bestSpeed || ( fabs(bestSpeed - rate) <= 0.000001 ) ) {
				bestSpeed = rate;
				bestTag = label;
			}
		}
	}

	printf("%d", bestTag);
	return 0;
}