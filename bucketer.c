#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
    for(int i = 0; i < nBatteries; i++)
    {
      //Calculation of SoH of Batteries
       float SoH = (((float)presentCapacities[i])/120.0)*100;

      //Classification of Batteries based on SoH and count in each classification
       if(SoH < 0.0 || SoH > 100.0)
       { 
          continue;
       }
       else if(SoH > 80.0)
       {
          counts.healthy++;
       }
       else if(SoH >= 62.0)
       {
          counts.exchange++;
       }
       else
       {
          counts.failed++;
       }
    }
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
