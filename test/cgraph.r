library(igraph)

file <- ""
data <- read.csv(file, header=False, sep=",")
graph <- graph_from_data_frame(data, directed=TRUE)