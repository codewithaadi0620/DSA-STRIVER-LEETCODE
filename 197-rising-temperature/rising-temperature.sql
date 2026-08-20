# Write your MySQL query statement below

SELECT w1.ID 
FROM WEATHER w1
JOIN WEATHER w2
 ON DATEDIFF(W1.recordDate,w2.recordDate)=1 
WHERE w1.TEMPERATURE >W2.TEMPERATURE;