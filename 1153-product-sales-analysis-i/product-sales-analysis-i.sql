# Write your MySQL query statement below
SELECT product_name,year,price FROM Product P RIGHT JOIN Sales S ON P.product_id=S.prodUct_id;