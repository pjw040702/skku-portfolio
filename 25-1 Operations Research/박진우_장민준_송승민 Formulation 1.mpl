TITLE DietOptimization ;

INDEX
  i := 1..17;

DATA
  carb[i] := (0.4, 9, 8, 70, 4, 7, 5, 11.4, 45, 8, 14, 58, 5, 22, 120, 73.6, 5);
  protein[i] := (6.3, 6, 25, 6, 1, 10, 10, 10.8, 20.5, 16, 22, 25, 25, 20, 4, 11.5, 18);
  fat[i] := (5, 7, 25, 1, 0, 6, 4, 10.7, 25, 2, 9, 25, 1.25, 15, 45, 4.2, 18);
  kcal[i] := (71.8, 123, 405, 313, 20, 122, 80, 185.1, 485, 114, 225, 533, 133.5, 186, 1045, 378.2, 254);
  

VARIABLES
  x[i];


MODEL

MIN Totalkcalenergy = SUM(i: kcal[i] * x[i]);

SUBJECT TO

  Calorie_Lower: SUM(i: kcal[i] * x[i]) >= 2000;
  
  Carb_ratio_Lower: SUM(i: carb[i] * 4 * (x[i])) >= SUM(i: kcal[i] * 0.55 * (x[i]));
  Carb_ratio_Upper: SUM(i: carb[i] * 4 * (x[i])) <= SUM(i: kcal[i] * 0.65 * (x[i]));

  Protein_ratio_Lower: SUM(i: protein[i] * 4 * (x[i])) >= SUM(i: kcal[i] * 0.07 * (x[i]));
  Protein_ratio_Upper: SUM(i: protein[i] * 4 * (x[i])) <= SUM(i: kcal[i] * 0.2 * (x[i]));

  Fat_ratio_Lower: SUM(i: fat[i] * 9 * (x[i])) >= SUM(i: kcal[i] * 0.15 * (x[i]));
  Fat_ratio_Upper: SUM(i: fat[i] * 9 * (x[i])) <= SUM(i: kcal[i] * 0.3 * (x[i]));

  

END
