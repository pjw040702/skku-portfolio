TITLE DietOptimization ;

INDEX
  i := 1..17;

DATA
  carb[i] := (0.4, 9, 8, 70, 4, 7, 5, 11.4, 45, 8, 14, 58, 5, 22, 120, 73.6, 5);
  protein[i] := (6.3, 6, 25, 6, 1, 10, 10, 10.8, 20.5, 16, 22, 25, 25, 20, 4, 11.5, 18);
  fat[i] := (5, 7, 25, 1, 0, 6, 4, 10.7, 25, 2, 9, 25, 1.25, 15, 45, 4.2, 18);
  kcal[i] := (71.8, 123, 405, 313, 20, 122, 80, 185.1, 485, 114, 225, 533, 133.5, 186, 1045, 378.2, 254);
  cost[i] := (300,1400,2700,1000,1200,750,1000,1480,4500,1200,7500,4000,2280,1000,9000,3500,2500);
  

VARIABLES
  a[i];
  b[i];
  c[i];


MODEL

MIN Totalkcalenergy = SUM(i: kcal[i] * (a[i]+b[i]+c[i]));

SUBJECT TO

  Calorie_Lower: SUM(i: kcal[i] * (a[i]+b[i]+c[i])) >= 2000;
  

  Carb_ratio_Lower: SUM(i: carb[i] * 4 * (a[i]+b[i]+c[i])) >= SUM(i: kcal[i] * 0.55 * (a[i]+b[i]+c[i]));
  Carb_ratio_Upper: SUM(i: carb[i] * 4 * (a[i]+b[i]+c[i])) <= SUM(i: kcal[i] * 0.65 * (a[i]+b[i]+c[i]));

  Protein_ratio_Lower: SUM(i: protein[i] * 4 * (a[i]+b[i]+c[i])) >= SUM(i: kcal[i] * 0.07 * (a[i]+b[i]+c[i]));
  Protein_ratio_Upper: SUM(i: protein[i] * 4 * (a[i]+b[i]+c[i])) <= SUM(i: kcal[i] * 0.2 * (a[i]+b[i]+c[i]));

  Fat_ratio_Lower: SUM(i: fat[i] * 9 * (a[i]+b[i]+c[i])) >= SUM(i: kcal[i] * 0.15 * (a[i]+b[i]+c[i]));
  Fat_ratio_Upper: SUM(i: fat[i] * 9 * (a[i]+b[i]+c[i])) <= SUM(i: kcal[i] * 0.3 * (a[i]+b[i]+c[i]));

  Cost_Upper: SUM(i: cost[i] * (a[i]+b[i]+c[i])) <= 8500;

  morning_energy_lower: SUM(i: kcal[i] * a[i]) >= 400;
  morning_energy_upper: SUM(i: kcal[i] * a[i]) <= 500;
  
  lunch_energy_lower: SUM(i: kcal[i] * b[i]) >= 600;
  lunch_energy_upper: SUM(i: kcal[i] * b[i]) <= 800;

  dinner_energy_lower: SUM(i: kcal[i] * c[i]) >= 500;
  dinner_energy_upper: SUM(i: kcal[i] * c[i]) <= 700;

END