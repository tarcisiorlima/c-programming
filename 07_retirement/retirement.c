
//program to calculate the retirement savings
#include <stdio.h>
#include <stdlib.h>

struct _retire_info
{
  int months; //number of months it is applicable to
  double contribution; // how many dollars are contributed or spent if negative, from the account per month
  double  rate_of_return; // rate of returns after inflation
};
typedef struct _retire_info  retire_info;

typedef struct
{
  int age_years;
  int age_months;
}complete_age;

complete_age age_month_conversion(int  total_months) //converts a month based age in its corresponde value in years and months
{
  complete_age conversion;
  conversion.age_years = total_months / 12;
  conversion.age_months = total_months - (conversion.age_years * 12);

     if (conversion.age_months == 12)
    {
 	conversion.age_months = 0;
  	conversion.age_years ++;
    }
  
  return conversion;
}
  
double  computation_retirement (retire_info situation, int startAge_aux, double initial_aux)
{
  double balance = initial_aux;
  complete_age convertedAge;
  
  for (int i = 0; i < situation.months; i++)
    {
      convertedAge = age_month_conversion (startAge_aux);
      printf ("Age %3d month %2d you have $%.2f\n", convertedAge.age_years, convertedAge.age_months, balance);
      balance = balance + balance * situation.rate_of_return + situation.contribution;
      startAge_aux ++;
    }
  return balance;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired)
{
  initial = computation_retirement (working, startAge, initial);
  startAge = 327 + working.months;
  initial  = computation_retirement (retired, startAge, initial);
}

int main (void)
{
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retire_info retire;
  retire.months = 384;
  retire.contribution = -4000;
  retire.rate_of_return = 0.01/12;

  //starting conditions
  int start_age = 327; //in months
  double savings = 21345; //initial savings

  retirement (start_age, savings, working, retire);
 
}
