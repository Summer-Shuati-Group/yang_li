# Write your MySQL query statement below
SELECT wt2.Id From Weather wt1, Weather wt2
# create object so different attributes of these objects can be compared 
WHERE wt2.Temperature > wt1.Temperature AND 
TO_DAYS(wt2.RecordDate) - TO_DAYS(wt1.RecordDate) = 1;
