#include < stdio.h > #include < stdlib.h > #include < math.h >
   int num;
struct Task {
   int id;
   int period;
   int exe;
   int priority;
   int finish;

}
tasks[200];

void sort() {
   int i, j, a, b, c, d;
   for (i = 0; i < ((num - 1) / 4); ++i)

   {

      for (j = i + 1; j < ((num - 1) / 4); ++j)

      {

         if (tasks[i].priority > tasks[j].priority)

         {
            a = tasks[i].priority;
            tasks[i].priority = tasks[j].priority;
            tasks[j].priority = a;

            b = tasks[i].period;
            tasks[i].period = tasks[j].period;
            tasks[j].period = b;

            c = tasks[i].exe;
            tasks[i].exe = tasks[j].exe;
            tasks[j].exe = c;

            d = tasks[i].id;
            tasks[i].id = tasks[j].id;
            tasks[j].id = d;

         }

      }

   }


}

void TDA() {
   int i = 1, j, counter = 0;
   float t1, sigma = 0;
   float w1 = 0;
   float w2 = 0;
   tasks[0].finish = tasks[0].exe;
   if (tasks[0].finish > tasks[0].period) {
      printf("no:%d\n", tasks[0].id);
      exit(0);
   }


   while (i < (num - 1) / 4)

   {
      if (counter == 0) {
         t1 = (float) tasks[i].exe;
         w1 = t1;
         w2 = 0;
         sigma = 0;
      } else {
         t1 = w2;
         w1 = w2;
         w2 = 0;
         sigma = 0;
      }
      for (j = 1; j <= i; j++) {

         sigma += ((ceil((t1 / tasks[i - j].period))) * tasks[i - j].exe);
      }
      w2 = sigma + (float) tasks[i].exe;

      if (w2 == w1 && (int) w2 < tasks[i].period) {
         tasks[i].finish = (int) w2;
         i++;
         sigma = 0;
         counter = 0;
         w1 = 0;
         w2 = 0;

         continue;
      } else if (w2 > tasks[i].period) {
         printf("no:%d\n", tasks[i].id);
         exit(0);
      } else {
         counter++;
      }

   }

   int jj;
   printf("yes:%d %d", tasks[0].id, tasks[0].finish);
   for (jj = 1; jj < (num - 1) / 4; jj++) {
      printf(" %d %d", tasks[jj].id, tasks[jj].finish);
   }
   printf("\n");
   exit(0);

}

int main(int argc, char * argv[])

{
   int j = 1;
   int i = 1;

   for (;;) {
      num = argc;
      if (argc < 5 || (((argc - 1) % 4) != 0)) {
         exit(0);

      } else {
         for (i = 1; i <= ((argc - 1) / 4); i++)

         {
            tasks[i - 1].id = atoi(argv[j]);
            j++;
            tasks[i - 1].period = atoi(argv[j]);
            j++;
            tasks[i - 1].exe = atoi(argv[j]);
            j++;
            tasks[i - 1].priority = atoi(argv[j]);
            j++;

         }

      }
      sort();

      TDA();
   }

   return 0;
}
