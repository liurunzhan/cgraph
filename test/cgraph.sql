create databese chemistry;
create table elements (
  autom_number int, 
  name varchar(255), 
  xa float,
  xar float,
  xcl float,
  xn float,
  xp float,
  xs float,
  xy float
);

load data infile "./elements.csv" into table elements fields termianted by "," lines terminated by "\r\n";