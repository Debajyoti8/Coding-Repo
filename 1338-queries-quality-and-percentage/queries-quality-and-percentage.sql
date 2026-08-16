# Write your MySQL query statement below
select q.query_name, 
round(avg(q.rating/q.position),2) as quality , 
round(avg(IF(q.rating<3,1,0))*100,2) as poor_query_percentage
from Queries as q
group by q.query_name