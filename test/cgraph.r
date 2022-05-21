#!/usr/bin/Rscript

library(igraph)

file <- "elements.csv"
if file.exists(file) {
	data <- read.csv(file, sep=",", header=TRUE, row.names=1, na.strings=c("NA"))
	print(data)
}
