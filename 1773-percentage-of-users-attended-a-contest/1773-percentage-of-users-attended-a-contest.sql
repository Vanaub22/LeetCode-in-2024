# Write your MySQL query statement below
select r.contest_id, round(count(r.user_id)*100.0/(select count(*) from users as u),2) as percentage
from register as r
group by contest_id
order by percentage desc, contest_id asc;